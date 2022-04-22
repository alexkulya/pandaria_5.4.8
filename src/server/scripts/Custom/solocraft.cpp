/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <map>
#include "Config.h"
#include "DatabaseEnv.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Pet.h"
#include "Map.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Chat.h"
#include "Log.h"
#include <math.h>
#include <unordered_map>

#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c

bool SoloCraftEnable = 1;
bool SoloCraftAnnounceModule = 1;
bool SoloCraftDebuffEnable = 1;
bool SolocraftXPBalancingEnabled = 1;
bool SolocraftXPEnabled = 1;
bool SolocraftNoXPFlag = 0;

float SoloCraftSpellMult = 1.0;
float SoloCraftStatsMult = 100.0;
float SoloCraftXPMod = 1.0;

uint32 SolocraftLevelDiff = 1;
uint32 SolocraftDungeonLevel = 1;

std::unordered_map<uint32, uint32> dungeons;
std::unordered_map<uint32, float> diff_Multiplier;
std::unordered_map<uint32, float> diff_Multiplier_Heroics;
std::unordered_map<uint8, uint32> classes;

float D5 = 1.0;
float D10 = 1.0;
float D25 = 1.0;
float D40 = 1.0;
float D649H10 = 1.0;
float D649H25 = 1.0;

class solocraft_system_config : public WorldScript
{
public:
    solocraft_system_config() : WorldScript("solocraft_system_config") { }

    void OnConfigLoad(bool /*reload*/) override
    {
        SoloCraftEnable = sConfigMgr->GetBoolDefault("Solocraft.Enable", 1);
        SoloCraftAnnounceModule = sConfigMgr->GetBoolDefault("Solocraft.Announce", 1);
        SoloCraftDebuffEnable = sConfigMgr->GetBoolDefault("SoloCraft.Debuff.Enable", 1);
        SoloCraftSpellMult = sConfigMgr->GetFloatDefault("SoloCraft.Spellpower.Mult", 2.5);
        SoloCraftStatsMult = sConfigMgr->GetFloatDefault("SoloCraft.Stats.Mult", 100.0);

        classes =
        {
            {1, sConfigMgr->GetIntDefault("SoloCraft.Warrior", 100) },
            {2, sConfigMgr->GetIntDefault("SoloCraft.Paladin", 100) },
            {3, sConfigMgr->GetIntDefault("SoloCraft.Hunter", 100) },
            {4, sConfigMgr->GetIntDefault("SoloCraft.Rogue", 100) },
            {5, sConfigMgr->GetIntDefault("SoloCraft.Priest", 100) },
            {6, sConfigMgr->GetIntDefault("SoloCraft.Death.Knight", 100) },
            {7, sConfigMgr->GetIntDefault("SoloCraft.Shaman", 100) },
            {8, sConfigMgr->GetIntDefault("SoloCraft.Mage", 100) },
            {9, sConfigMgr->GetIntDefault("SoloCraft.Warlock", 100) },
            {10, sConfigMgr->GetIntDefault("SoloCraft.Monk", 100) },
            {11, sConfigMgr->GetIntDefault("SoloCraft.Druid", 100) },
        };

        SolocraftXPEnabled = sConfigMgr->GetBoolDefault("Solocraft.XP.Enabled", 1);
        SolocraftXPBalancingEnabled = sConfigMgr->GetBoolDefault("Solocraft.XP.Balancing.Enabled", 1);
        SolocraftLevelDiff = sConfigMgr->GetIntDefault("Solocraft.Max.Level.Diff", 10);
        SolocraftDungeonLevel = sConfigMgr->GetIntDefault("Solocraft.Dungeon.Level", 90);
        // Уровни
        dungeons =
        {
            /// VANILLA
            {34, sConfigMgr->GetIntDefault("Solocraft.Stockades.Level", 22) },
            {43, sConfigMgr->GetIntDefault("Solocraft.WailingCaverns.Level", 17) },
            {47, sConfigMgr->GetIntDefault("Solocraft.RazorfenKraul.Level", 30) },
            {48, sConfigMgr->GetIntDefault("Solocraft.BlackfathomDeeps.Level", 20) },
            {70, sConfigMgr->GetIntDefault("Solocraft.Uldaman.Level", 40) },
            {90, sConfigMgr->GetIntDefault("Solocraft.Gnomeregan.Level", 24) },
            {109, sConfigMgr->GetIntDefault("Solocraft.SunkenTemple.Level", 50) },
            {129, sConfigMgr->GetIntDefault("Solocraft.RazorfenDowns.Level", 40) },
            {209, sConfigMgr->GetIntDefault("Solocraft.ZulFarrak.Level", 44) },
            {229, sConfigMgr->GetIntDefault("Solocraft.BlackRockSpire.Level", 55) },
            {230, sConfigMgr->GetIntDefault("Solocraft.BlackrockDepths.Level", 50) },
            {249, sConfigMgr->GetIntDefault("Solocraft.OnyxiaLair.Level", 60) },
            {329, sConfigMgr->GetIntDefault("Solocraft.Stratholme.Level", 55) },
            {349, sConfigMgr->GetIntDefault("Solocraft.Mauradon.Level", 48) },
            {389, sConfigMgr->GetIntDefault("Solocraft.RagefireChasm.Level", 15) },
            {409, sConfigMgr->GetIntDefault("Solocraft.MoltenCore.Level", 60) },
            {429, sConfigMgr->GetIntDefault("Solocraft.DireMaul.Level", 48) },
            {469, sConfigMgr->GetIntDefault("Solocraft.BlackwingLair.Level", 40) },
            {509, sConfigMgr->GetIntDefault("Solocraft.RuinsOfAhnQiraj.Level", 60) },
            {531, sConfigMgr->GetIntDefault("Solocraft.TempleOfAhnQiraj.Level", 60) },
            /// BURNING CRUSADE
            {269, sConfigMgr->GetIntDefault("Solocraft.TheBlackMorass.Level", 68) },
            {532, sConfigMgr->GetIntDefault("Solocraft.Karazahn.Level", 68) },
            {534, sConfigMgr->GetIntDefault("Solocraft.TheBattleForMountHyjal.Level", 70) },
            {540, sConfigMgr->GetIntDefault("Solocraft.TheShatteredHalls.Level", 68) },
            {542, sConfigMgr->GetIntDefault("Solocraft.TheBloodFurnace.Level", 68) },
            {543, sConfigMgr->GetIntDefault("Solocraft.HellfireRampart.Level", 68) },
            {544, sConfigMgr->GetIntDefault("Solocraft.MagtheridonsLair.Level", 68) },
            {545, sConfigMgr->GetIntDefault("Solocraft.TheSteamVault.Level", 68) },
            {546, sConfigMgr->GetIntDefault("Solocraft.TheUnderbog.Level", 68) },
            {547, sConfigMgr->GetIntDefault("Solocraft.TheSlavePens.Level", 68) },
            {548, sConfigMgr->GetIntDefault("Solocraft.SerpentshrineCavern.Level", 70) },
            {550, sConfigMgr->GetIntDefault("Solocraft.TheEye.Level", 70) },
            {552, sConfigMgr->GetIntDefault("Solocraft.TheArcatraz.Level", 68) },
            {553, sConfigMgr->GetIntDefault("Solocraft.TheBotanica.Level", 68) },
            {554, sConfigMgr->GetIntDefault("Solocraft.TheMechanar.Level", 68) },
            {555, sConfigMgr->GetIntDefault("Solocraft.ShadowLabyrinth.Level", 68) },
            {556, sConfigMgr->GetIntDefault("Solocraft.SethekkHalls.Level", 68) },
            {557, sConfigMgr->GetIntDefault("Solocraft.ManaTombs.Level", 68) },
            {558, sConfigMgr->GetIntDefault("Solocraft.AuchenaiCrypts.Level", 68) },
            {560, sConfigMgr->GetIntDefault("Solocraft.OldHillsbradFoothills.Level", 68) },
            {564, sConfigMgr->GetIntDefault("Solocraft.BlackTemple.Level", 70) },
            {565, sConfigMgr->GetIntDefault("Solocraft.GruulsLair.Level", 70) },
            {580, sConfigMgr->GetIntDefault("Solocraft.SunwellPlateau.Level", 70) },
            {585, sConfigMgr->GetIntDefault("Solocraft.MagistersTerrace.Level", 68) },
            /// WRATH OF THE LICH KING
            {533, sConfigMgr->GetIntDefault("Solocraft.Naxxramas.Level", 78) },
            {574, sConfigMgr->GetIntDefault("Solocraft.UtgardeKeep", 78) },
            {575, sConfigMgr->GetIntDefault("Solocraft.UtgardePinnacle.Level", 78) },
            {578, sConfigMgr->GetIntDefault("Solocraft.Oculus.Level", 78) },
            {595, sConfigMgr->GetIntDefault("Solocraft.TheCullingOfStratholme.Level", 78) },
            {599, sConfigMgr->GetIntDefault("Solocraft.HallsOfStone.Level", 78) },
            {600, sConfigMgr->GetIntDefault("Solocraft.DrakTharonKeep.Level", 78) },
            {601, sConfigMgr->GetIntDefault("Solocraft.AzjolNerub.Level", 78) },
            {602, sConfigMgr->GetIntDefault("Solocraft.HallsOfLighting.Level", 78) },
            {603, sConfigMgr->GetIntDefault("Solocraft.Ulduar.Level", 80) },
            {604, sConfigMgr->GetIntDefault("Solocraft.GunDrak.Level", 78) },
            {608, sConfigMgr->GetIntDefault("Solocraft.VioletHold.Level", 78) },
            {615, sConfigMgr->GetIntDefault("Solocraft.TheObsidianSanctum.Level", 80) },
            {616, sConfigMgr->GetIntDefault("Solocraft.TheEyeOfEternity.Level", 80) },
            {619, sConfigMgr->GetIntDefault("Solocraft.AhnkahetTheOldKingdom.Level", 78) },
            {631, sConfigMgr->GetIntDefault("Solocraft.IcecrownCitadel.Level", 80) },
            {632, sConfigMgr->GetIntDefault("Solocraft.TheForgeOfSouls.Level", 78) },
            {649, sConfigMgr->GetIntDefault("Solocraft.TrialOfTheCrusader.Level", 80) },
            {650, sConfigMgr->GetIntDefault("Solocraft.TrialOfTheChampion.Level", 80) },
            {658, sConfigMgr->GetIntDefault("Solocraft.PitOfSaron.Level", 78) },
            {668, sConfigMgr->GetIntDefault("Solocraft.HallsOfReflection.Level", 78) },
            {724, sConfigMgr->GetIntDefault("Solocraft.TheRubySanctum.Level", 80) },
            /// CATACLYSM
            {33, sConfigMgr->GetIntDefault("Solocraft.ShadowfangKeep.Level", 85) }, // Крепость Темного Клыка
            {36, sConfigMgr->GetIntDefault("Solocraft.DeadMines.Level", 85) }, // Мертвые Копи
            {645, sConfigMgr->GetIntDefault("Solocraft.BlackrockCaverns.Level", 85) }, // Пещеры Черной горы
            {643, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheTides.Level", 85) }, // Трон Приливов
            {657, sConfigMgr->GetIntDefault("Solocraft.TheVortexPinnacle.Level", 85) }, // Вершина Смерча
            {725, sConfigMgr->GetIntDefault("Solocraft.TheStonecore.Level", 85) }, // Каменные Недра
            {755, sConfigMgr->GetIntDefault("Solocraft.LostCityOfTheTol'vir.Level", 85) }, // Затерянный город Тол'вир
            {644, sConfigMgr->GetIntDefault("Solocraft.HallsOfOrigination.Level", 85) }, // Чертоги Созидания
            {670, sConfigMgr->GetIntDefault("Solocraft.GrimBatol.Level", 85) }, // Грим Батол
            {669, sConfigMgr->GetIntDefault("Solocraft.BlackwingDescent.Level", 85) }, // Твердыня Крыла Тьмы
            {671, sConfigMgr->GetIntDefault("Solocraft.TheBastionOfTwilight.Level", 85) }, // Сумеречный бастион
            {754, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheFourWinds.Level", 85) }, // Трон Четырех Ветров
            {757, sConfigMgr->GetIntDefault("Solocraft.BaradinHold.Level", 85) }, // Крепость Барадин
            {720, sConfigMgr->GetIntDefault("Solocraft.Firelands.Level", 85) }, // Огненные Просторы
            {967, sConfigMgr->GetIntDefault("Solocraft.DragonSoul.Level", 85) }, // Душа Дракона
            {938, sConfigMgr->GetIntDefault("Solocraft.EndTime.Level", 85) }, // Конец Времен
            {939, sConfigMgr->GetIntDefault("Solocraft.WellOfEternity.Level", 85) }, // Источник Вечности
            {940, sConfigMgr->GetIntDefault("Solocraft.HourOfTwilight.Level", 85) }, // Время Сумерек
            {859, sConfigMgr->GetIntDefault("Solocraft.Zul'gurub.Level", 85) }, // Зул'Гуруб
            {568, sConfigMgr->GetIntDefault("Solocraft.ZulAman.Level", 85) }, // Зул'Аман
            {576, sConfigMgr->GetIntDefault("Solocraft.Nexus.Level", 85) }, // Нексус
            /// MISTS OF PANDARIA
            {959, sConfigMgr->GetIntDefault("Solocraft.ShadoPanMonastery.Level", 90) }, // Монастырь Шадо-Пан
            {1007, sConfigMgr->GetIntDefault("Solocraft.Scholomance.Level", 90) }, // Некроситет
            {1004, sConfigMgr->GetIntDefault("Solocraft.ScarletMonastery.Level", 90) }, // Монастырь Алого ордена
            {994, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanPalace.Level", 90) }, // Дворец Могу'шан
            {1008, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanVaults.Level", 90) }, // Подземелья Могу'шан
            {1136, sConfigMgr->GetIntDefault("Solocraft.SiegeOfOrgrimmar.Level", 90) }, // Осада Оргриммара
            {1098, sConfigMgr->GetIntDefault("Solocraft.ThroneOfThunder.Level", 90) }, // Престол Гроз
            {1009, sConfigMgr->GetIntDefault("Solocraft.HeartOfFear.Level", 90) }, // Сердце Страха
            {996, sConfigMgr->GetIntDefault("Solocraft.TerraceOfEndlessSpring.Level", 90) }, // Терраса Вечной Весны
            {1001, sConfigMgr->GetIntDefault("Solocraft.ScarletHalls.Level", 90) }, // Залы Алого ордена
            {962, sConfigMgr->GetIntDefault("Solocraft.GateOfTheSettingSun.Level", 90) }, // Врата Заходящего Солнца
            {1011, sConfigMgr->GetIntDefault("Solocraft.SiegeOfNiuzaoTemple.Level", 90) }, // Осада храма Нюцзао
            {960, sConfigMgr->GetIntDefault("Solocraft.TempleOfTheJadeSerpent.Level", 90) }, // Храм Нефритовой Змеи
            {961, sConfigMgr->GetIntDefault("Solocraft.StormstoutBrewery.Level", 90) }, // Хмелеварня Буйных Портеров
        };
        // Сложность
        D5 = sConfigMgr->GetFloatDefault("Solocraft.Dungeon", 5.0);
        D10 = sConfigMgr->GetFloatDefault("Solocraft.Heroic", 10.0);
        D25 = sConfigMgr->GetFloatDefault("Solocraft.Raid25", 25.0);
        D40 = sConfigMgr->GetFloatDefault("Solocraft.Raid40", 40.0);
        // Множитель (обычный)
        diff_Multiplier =
        {
            /// VANILLA
            {34, sConfigMgr->GetFloatDefault("Solocraft.Stockades", 5.0) },
            {43, sConfigMgr->GetFloatDefault("Solocraft.WailingCaverns", 5.0) },
            {47, sConfigMgr->GetFloatDefault("Solocraft.RazorfenKraul", 5.0) },
            {48, sConfigMgr->GetFloatDefault("Solocraft.BlackfathomDeeps", 5.0) },
            {70, sConfigMgr->GetFloatDefault("Solocraft.Uldaman", 5.0) },
            {90, sConfigMgr->GetFloatDefault("Solocraft.Gnomeregan", 5.0) },
            {109, sConfigMgr->GetFloatDefault("Solocraft.SunkenTemple", 5.0) },
            {129, sConfigMgr->GetFloatDefault("Solocraft.RazorfenDowns", 5.0) },
            {209, sConfigMgr->GetFloatDefault("Solocraft.ZulFarrak", 5.0) },
            {229, sConfigMgr->GetFloatDefault("Solocraft.BlackRockSpire", 10.0) },
            {230, sConfigMgr->GetFloatDefault("Solocraft.BlackrockDepths", 5.0) },
            {249, sConfigMgr->GetFloatDefault("Solocraft.OnyxiaLair", 40.0) },
            {329, sConfigMgr->GetFloatDefault("Solocraft.Stratholme", 5.0) },
            {349, sConfigMgr->GetFloatDefault("Solocraft.Mauradon", 5.0) },
            {389, sConfigMgr->GetFloatDefault("Solocraft.RagefireChasm", 5.0) },
            {409, sConfigMgr->GetFloatDefault("Solocraft.MoltenCore", 40.0) },
            {429, sConfigMgr->GetFloatDefault("Solocraft.DireMaul", 5.0) },
            {469, sConfigMgr->GetFloatDefault("Solocraft.BlackwingLair", 40.0) },
            {509, sConfigMgr->GetFloatDefault("Solocraft.RuinsOfAhnQiraj", 20.0) },
            {531, sConfigMgr->GetFloatDefault("Solocraft.TempleOfAhnQiraj", 40.0) },
            /// BURNING CRUSADE
            {269, sConfigMgr->GetFloatDefault("Solocraft.TheBlackMorass", 5.0) },
            {532, sConfigMgr->GetFloatDefault("Solocraft.Karazahn", 10.0) },
            {534, sConfigMgr->GetFloatDefault("Solocraft.TheBattleForMountHyjal", 25.0) },
            {540, sConfigMgr->GetFloatDefault("Solocraft.TheShatteredHalls", 5.0) },
            {542, sConfigMgr->GetFloatDefault("Solocraft.TheBloodFurnace", 5.0) },
            {543, sConfigMgr->GetFloatDefault("Solocraft.HellfireRampart", 5.0) },
            {544, sConfigMgr->GetFloatDefault("Solocraft.MagtheridonsLair", 25.0) },
            {545, sConfigMgr->GetFloatDefault("Solocraft.TheSteamVault", 5.0) },
            {546, sConfigMgr->GetFloatDefault("Solocraft.TheUnderbog", 5.0) },
            {547, sConfigMgr->GetFloatDefault("Solocraft.TheSlavePens", 5.0) },
            {548, sConfigMgr->GetFloatDefault("Solocraft.SerpentshrineCavern", 25.0) },
            {550, sConfigMgr->GetFloatDefault("Solocraft.TheEye", 25.0) },
            {552, sConfigMgr->GetFloatDefault("Solocraft.TheArcatraz", 5.0) },
            {553, sConfigMgr->GetFloatDefault("Solocraft.TheBotanica", 5.0) },
            {554, sConfigMgr->GetFloatDefault("Solocraft.TheMechanar", 5.0) },
            {555, sConfigMgr->GetFloatDefault("Solocraft.ShadowLabyrinth", 5.0) },
            {556, sConfigMgr->GetFloatDefault("Solocraft.SethekkHalls", 5.0) },
            {557, sConfigMgr->GetFloatDefault("Solocraft.ManaTombs", 5.0) },
            {558, sConfigMgr->GetFloatDefault("Solocraft.AuchenaiCrypts", 5.0) },
            {560, sConfigMgr->GetFloatDefault("Solocraft.OldHillsbradFoothills", 5.0) },
            {564, sConfigMgr->GetFloatDefault("Solocraft.BlackTemple", 25.0) },
            {565, sConfigMgr->GetFloatDefault("Solocraft.GruulsLair", 25.0) },
            {580, sConfigMgr->GetFloatDefault("Solocraft.SunwellPlateau", 25.0) },
            {585, sConfigMgr->GetFloatDefault("Solocraft.MagistersTerrace", 5.0) },
            /// WRATH OF THE LICH KING
            {533, sConfigMgr->GetFloatDefault("Solocraft.Naxxramas", 10.0) },
            {574, sConfigMgr->GetFloatDefault("Solocraft.UtgardeKeep", 5.0) },
            {575, sConfigMgr->GetFloatDefault("Solocraft.UtgardePinnacle", 5.0) },
            {578, sConfigMgr->GetFloatDefault("Solocraft.Oculus", 5.0) },
            {595, sConfigMgr->GetFloatDefault("Solocraft.TheCullingOfStratholme", 5.0) },
            {599, sConfigMgr->GetFloatDefault("Solocraft.HallsOfStone", 5.0) },
            {600, sConfigMgr->GetFloatDefault("Solocraft.DrakTharonKeep", 5.0) },
            {601, sConfigMgr->GetFloatDefault("Solocraft.AzjolNerub", 5.0) },
            {602, sConfigMgr->GetFloatDefault("Solocraft.HallsOfLighting", 5.0) },
            {603, sConfigMgr->GetFloatDefault("Solocraft.Ulduar", 10.0) },
            {604, sConfigMgr->GetFloatDefault("Solocraft.GunDrak", 5.0) },
            {608, sConfigMgr->GetFloatDefault("Solocraft.VioletHold", 5.0) },
            {615, sConfigMgr->GetFloatDefault("Solocraft.TheObsidianSanctum", 10.0) },
            {616, sConfigMgr->GetFloatDefault("Solocraft.TheEyeOfEternity", 10.0) },
            {619, sConfigMgr->GetFloatDefault("Solocraft.AhnkahetTheOldKingdom", 5.0) },
            {631, sConfigMgr->GetFloatDefault("Solocraft.IcecrownCitadel", 10.0) },
            {632, sConfigMgr->GetFloatDefault("Solocraft.TheForgeOfSouls", 5.0) },
            {649, sConfigMgr->GetFloatDefault("Solocraft.TrialOfTheCrusader", 10.0) },
            {650, sConfigMgr->GetFloatDefault("Solocraft.TrialOfTheChampion", 5.0) },
            {658, sConfigMgr->GetFloatDefault("Solocraft.PitOfSaron", 5.0) },
            {668, sConfigMgr->GetFloatDefault("Solocraft.HallsOfReflection", 5.0) },
            {724, sConfigMgr->GetFloatDefault("Solocraft.TheRubySanctum", 10.0) },
            /// CATACLYSM
            {33, sConfigMgr->GetIntDefault("Solocraft.ShadowfangKeep", 5.0) }, // Крепость Темного Клыка
            {36, sConfigMgr->GetIntDefault("Solocraft.DeadMines", 5.0) }, // Мертвые Копи
            {645, sConfigMgr->GetIntDefault("Solocraft.BlackrockCaverns", 5.0) }, // Пещеры Черной горы
            {643, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheTides", 5.0) }, // Трон Приливов
            {657, sConfigMgr->GetIntDefault("Solocraft.TheVortexPinnacle", 5.0) }, // Вершина Смерча
            {725, sConfigMgr->GetIntDefault("Solocraft.TheStonecore", 5.0) }, // Каменные Недра
            {755, sConfigMgr->GetIntDefault("Solocraft.LostCityOfTheTol'vir", 5.0) }, // Затерянный город Тол'вир
            {644, sConfigMgr->GetIntDefault("Solocraft.HallsOfOrigination", 5.0) }, // Чертоги Созидания
            {670, sConfigMgr->GetIntDefault("Solocraft.GrimBatol", 5.0) }, // Грим Батол
            {669, sConfigMgr->GetIntDefault("Solocraft.BlackwingDescent", 10.0) }, // Твердыня Крыла Тьмы
            {671, sConfigMgr->GetIntDefault("Solocraft.TheBastionOfTwilight", 10.0) }, // Сумеречный бастион
            {754, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheFourWinds", 10.0) }, // Трон Четырех Ветров
            {757, sConfigMgr->GetIntDefault("Solocraft.BaradinHold", 10.0) }, // Крепость Барадин
            {720, sConfigMgr->GetIntDefault("Solocraft.Firelands", 10.0) }, // Огненные Просторы
            {967, sConfigMgr->GetIntDefault("Solocraft.DragonSoul", 10.0) }, // Душа Дракона
            {859, sConfigMgr->GetIntDefault("Solocraft.Zul'gurub", 5.0) }, // Зул'Гуруб
            {568, sConfigMgr->GetIntDefault("Solocraft.ZulAman", 5.0) }, // Зул'Аман
            {576, sConfigMgr->GetIntDefault("Solocraft.Nexus", 5.0) }, // Нексус
            /// MISTS OF PANDARIA
            {959, sConfigMgr->GetIntDefault("Solocraft.ShadoPanMonastery", 5.0) }, // Монастырь Шадо-Пан
            {1007, sConfigMgr->GetIntDefault("Solocraft.Scholomance", 5.0) }, // Некроситет
            {1004, sConfigMgr->GetIntDefault("Solocraft.ScarletMonastery", 5.0) }, // Монастырь Алого ордена
            {994, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanPalace", 5.0) }, // Дворец Могу'шан
            {1008, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanVaults", 10.0) }, // Подземелья Могу'шан
            {1136, sConfigMgr->GetIntDefault("Solocraft.SiegeOfOrgrimmar", 10.0) }, // Осада Оргриммара
            {1098, sConfigMgr->GetIntDefault("Solocraft.ThroneOfThunder", 10.0) }, // Престол Гроз
            {1009, sConfigMgr->GetIntDefault("Solocraft.HeartOfFear", 10.0) }, // Сердце Страха
            {996, sConfigMgr->GetIntDefault("Solocraft.TerraceOfEndlessSpring", 10.0) }, // Терраса Вечной Весны
            {1001, sConfigMgr->GetIntDefault("Solocraft.ScarletHalls", 5.0) }, // Залы Алого ордена
            {962, sConfigMgr->GetIntDefault("Solocraft.GateOfTheSettingSun", 5.0) }, // Врата Заходящего Солнца
            {1011, sConfigMgr->GetIntDefault("Solocraft.SiegeOfNiuzaoTemple", 5.0) }, // Осада храма Нюцзао
            {960, sConfigMgr->GetIntDefault("Solocraft.TempleOfTheJadeSerpent", 5.0) }, // Храм Нефритовой Змеи
            {961, sConfigMgr->GetIntDefault("Solocraft.StormstoutBrewery", 5.0) }, // Хмелеварня Буйных Портеров
        };
        // Множитель (героический)
        diff_Multiplier_Heroics =
        {
            /// BURNING CRUSADE
            {269, sConfigMgr->GetFloatDefault("Solocraft.TheBlackMorassH", 5.0) },
            {540, sConfigMgr->GetFloatDefault("Solocraft.TheShatteredHallsH", 5.0) },
            {542, sConfigMgr->GetFloatDefault("Solocraft.TheBloodFurnaceH", 5.0) },
            {543, sConfigMgr->GetFloatDefault("Solocraft.HellfireRampartH", 5.0) },
            {545, sConfigMgr->GetFloatDefault("Solocraft.TheSteamVaultH", 5.0) },
            {546, sConfigMgr->GetFloatDefault("Solocraft.TheUnderbogH", 5.0) },
            {547, sConfigMgr->GetFloatDefault("Solocraft.TheSlavePensH", 5.0) },
            {552, sConfigMgr->GetFloatDefault("Solocraft.TheArcatrazH", 5.0) },
            {553, sConfigMgr->GetFloatDefault("Solocraft.TheBotanicaH", 5.0) },
            {554, sConfigMgr->GetFloatDefault("Solocraft.TheMechanarH", 5.0) },
            {555, sConfigMgr->GetFloatDefault("Solocraft.ShadowLabyrinthH", 5.0) },
            {556, sConfigMgr->GetFloatDefault("Solocraft.SethekkHallsH", 5.0) },
            {557, sConfigMgr->GetFloatDefault("Solocraft.ManaTombsH", 5.0) },
            {558, sConfigMgr->GetFloatDefault("Solocraft.AuchenaiCryptsH", 5.0) },
            {560, sConfigMgr->GetFloatDefault("Solocraft.OldHillsbradFoothillsH", 5.0) },
            {585, sConfigMgr->GetFloatDefault("Solocraft.MagistersTerraceH", 5.0) },
            /// WRATH OF THE LICH KING
            {533, sConfigMgr->GetFloatDefault("Solocraft.NaxxramasH", 25.0) },
            {574, sConfigMgr->GetFloatDefault("Solocraft.UtgardeKeepH", 5.0) },
            {575, sConfigMgr->GetFloatDefault("Solocraft.UtgardePinnacleH", 5.0) },
            {578, sConfigMgr->GetFloatDefault("Solocraft.OculusH", 5.0) },
            {595, sConfigMgr->GetFloatDefault("Solocraft.TheCullingOfStratholmeH", 5.0) },
            {599, sConfigMgr->GetFloatDefault("Solocraft.HallsOfStoneH", 5.0) },
            {600, sConfigMgr->GetFloatDefault("Solocraft.DrakTharonKeepH", 5.0) },
            {601, sConfigMgr->GetFloatDefault("Solocraft.AzjolNerubH", 5.0) },
            {602, sConfigMgr->GetFloatDefault("Solocraft.HallsOfLightingH", 5.0) },
            {603, sConfigMgr->GetFloatDefault("Solocraft.UlduarH", 25.0) },
            {604, sConfigMgr->GetFloatDefault("Solocraft.GunDrakH", 5.0) },
            {608, sConfigMgr->GetFloatDefault("Solocraft.VioletHoldH", 5.0) },
            {615, sConfigMgr->GetFloatDefault("Solocraft.TheObsidianSanctumH", 25.0) },
            {616, sConfigMgr->GetFloatDefault("Solocraft.TheEyeOfEternityH", 25.0) },
            {619, sConfigMgr->GetFloatDefault("Solocraft.AhnkahetTheOldKingdomH", 5.0) },
            {631, sConfigMgr->GetFloatDefault("Solocraft.IcecrownCitadelH", 25.0) },
            {632, sConfigMgr->GetFloatDefault("Solocraft.TheForgeOfSoulsH", 5.0) },
            {649, sConfigMgr->GetFloatDefault("Solocraft.TrialOfTheCrusaderH", 25.0) },
            {650, sConfigMgr->GetFloatDefault("Solocraft.TrialOfTheChampionH", 5.0) },
            {658, sConfigMgr->GetFloatDefault("Solocraft.PitOfSaronH", 5.0) },
            {668, sConfigMgr->GetFloatDefault("Solocraft.HallsOfReflectionH", 5.0) },
            {724, sConfigMgr->GetFloatDefault("Solocraft.TheRubySanctumH", 25.0) },
            /// CATACLYSM
            {33, sConfigMgr->GetFloatDefault("Solocraft.ShadowfangKeepH", 5.0) }, // Крепость Темного Клыка
            {36, sConfigMgr->GetFloatDefault("Solocraft.DeadMinesH", 5.0) }, // Мертвые Копи
            {645, sConfigMgr->GetIntDefault("Solocraft.BlackrockCavernsH", 5.0) }, // Пещеры Черной горы
            {643, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheTidesH", 5.0) }, // Трон Приливов
            {657, sConfigMgr->GetIntDefault("Solocraft.TheVortexPinnacleH", 5.0) }, // Вершина Смерча
            {725, sConfigMgr->GetIntDefault("Solocraft.TheStonecoreH", 5.0) }, // Каменные Недра
            {755, sConfigMgr->GetIntDefault("Solocraft.LostCityOfTheTol'virH", 5.0) }, // Затерянный город Тол'вир
            {644, sConfigMgr->GetIntDefault("Solocraft.HallsOfOriginationH", 5.0) }, // Чертоги Созидания
            {670, sConfigMgr->GetIntDefault("Solocraft.GrimBatolH", 5.0) }, // Грим Батол
            {669, sConfigMgr->GetIntDefault("Solocraft.BlackwingDescentH", 25.0) }, // Твердыня Крыла Тьмы
            {671, sConfigMgr->GetIntDefault("Solocraft.TheBastionOfTwilightH", 25.0) }, // Сумеречный бастион
            {754, sConfigMgr->GetIntDefault("Solocraft.ThroneOfTheFourWindsH", 25.0) }, // Трон Четырех Ветров
            {757, sConfigMgr->GetIntDefault("Solocraft.BaradinHoldH", 25.0) }, // Крепость Барадин
            {720, sConfigMgr->GetIntDefault("Solocraft.FirelandsH", 25.0) }, // Огненные Просторы
            {967, sConfigMgr->GetIntDefault("Solocraft.DragonSoulH", 25.0) }, // Душа Дракона
            {938, sConfigMgr->GetIntDefault("Solocraft.EndTimeH", 5.0) }, // Конец Времен
            {939, sConfigMgr->GetIntDefault("Solocraft.WellOfEternityH", 5.0) }, // Источник Вечности
            {940, sConfigMgr->GetIntDefault("Solocraft.HourOfTwilightH", 5.0) }, // Время Сумерек
            {859, sConfigMgr->GetIntDefault("Solocraft.Zul'gurubH", 5.0) }, // Зул'Гуруб
            {568, sConfigMgr->GetIntDefault("Solocraft.ZulAmanH", 5.0) }, // Зул'Аман
            {576, sConfigMgr->GetIntDefault("Solocraft.NexusH", 5.0) }, // Нексус
            /// MISTS OF PANDARIA
            {959, sConfigMgr->GetIntDefault("Solocraft.ShadoPanMonasteryH", 5.0) }, // Монастырь Шадо-Пан
            {1007, sConfigMgr->GetIntDefault("Solocraft.ScholomanceH", 5.0) }, // Некроситет
            {1004, sConfigMgr->GetIntDefault("Solocraft.ScarletMonasteryH", 5.0) }, // Монастырь Алого ордена
            {994, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanPalaceH", 5.0) }, // Дворец Могу'шан
            {1008, sConfigMgr->GetIntDefault("Solocraft.Mogu'shanVaultsH", 25.0) }, // Подземелья Могу'шан
            {1136, sConfigMgr->GetIntDefault("Solocraft.SiegeOfOrgrimmarH", 25.0) }, // Осада Оргриммара
            {1098, sConfigMgr->GetIntDefault("Solocraft.ThroneOfThunderH", 25.0) }, // Престол Гроз
            {1009, sConfigMgr->GetIntDefault("Solocraft.HeartOfFearH", 25.0) }, // Сердце Страха
            {996, sConfigMgr->GetIntDefault("Solocraft.TerraceOfEndlessSpringH", 25.0) }, // Терраса Вечной Весны
            {1001, sConfigMgr->GetIntDefault("Solocraft.ScarletHallsH", 5.0) }, // Залы Алого ордена
            {962, sConfigMgr->GetIntDefault("Solocraft.GateOfTheSettingSunH", 5.0) }, // Врата Заходящего Солнца
            {1011, sConfigMgr->GetIntDefault("Solocraft.SiegeOfNiuzaoTempleH", 5.0) }, // Осада храма Нюцзао
            {960, sConfigMgr->GetIntDefault("Solocraft.TempleOfTheJadeSerpentH", 5.0) }, // Храм Нефритовой Змеи
            {961, sConfigMgr->GetIntDefault("Solocraft.StormstoutBreweryH", 5.0) }, // Хмелеварня Буйных Портеров
        };

        D649H10 = sConfigMgr->GetFloatDefault("Solocraft.ArgentTournamentRaidH10", 10.0);  // Trial of the Crusader 10 Heroic
        D649H25 = sConfigMgr->GetFloatDefault("Solocraft.ArgentTournamentRaidH25", 25.0);  // Trial of the Crusader 25 Heroic
    }
};

class solocraft_system_announce : public PlayerScript
{
public:
    solocraft_system_announce() : PlayerScript("solocraft_system_announce") { }

    void OnLogin(Player* player) override
    {
        if (SoloCraftEnable)
        {
            if (SoloCraftAnnounceModule)
            {
                ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "|cff4CFF00СолоКрафт система|r активирована.", "|cff4CFF00SoloCraft system|r active."));
            }
        }
    }

    void OnLogout(Player* player) override
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT `GUID` FROM `custom_solocraft_character_stats` WHERE GUID = %u", player->GetGUID());

        if (result)
        {
            CharacterDatabase.PExecute("DELETE FROM custom_solocraft_character_stats WHERE GUID = %u", player->GetGUID());
        }
    }

    void OnGiveXP(Player* /*player*/, uint32& amount, Unit* /*victim*/) override
    {
        if (SolocraftXPBalancingEnabled) 
        {
            amount = uint32(amount * SoloCraftXPMod);
        }
    }
};

class solocraft_system_player_instance_handler : public PlayerScript
{
public:
    solocraft_system_player_instance_handler() : PlayerScript("solocraft_system_player_instance_handler") { }

    void OnMapChanged(Player* player) override
    {
        if (sConfigMgr->GetBoolDefault("Solocraft.Enable", true))
        {
            Map* map = player->GetMap();
            float difficulty = CalculateDifficulty(map, player);
            int dunLevel = CalculateDungeonLevel(map, player);
            int numInGroup = GetNumInGroup(player);
            uint32 classBalance = GetClassBalance(player);
            ApplyBuffs(player, map, difficulty, dunLevel, numInGroup, classBalance);
        }
    }

private:
    std::map<uint32, float> _unitDifficulty;

    int CalculateDifficulty(Map* map, Player* /*player*/)
    {
        if (map)
        {
            if (map->Is25ManRaid())
            {
                if (map->IsHeroic() && map->GetId() == 649)
                {
                    return D649H25;
                }
                else if (diff_Multiplier_Heroics.find(map->GetId()) == diff_Multiplier_Heroics.end())
                {
                    return D25;
                }
                else
                    return diff_Multiplier_Heroics[map->GetId()];
            }

            if (map->IsHeroic())
            {
                if (map->GetId() == 649)
                {
                    return D649H10;
                }
                else if (diff_Multiplier_Heroics.find(map->GetId()) == diff_Multiplier_Heroics.end())
                {
                    return D10;
                }
                else
                    return diff_Multiplier_Heroics[map->GetId()];
            }

            if (diff_Multiplier.find(map->GetId()) == diff_Multiplier.end())
            {
                if (map->IsDungeon())
                {
                    return D5;
                }
                else if (map->IsRaid())
                {
                    return D40;
                }
            }
            else
                return diff_Multiplier[map->GetId()];
        }
        return 0;
    }

    int CalculateDungeonLevel(Map* map, Player* /*player*/)
    {
        if (dungeons.find(map->GetId()) == dungeons.end())
        {
            return SolocraftDungeonLevel;
        }
        else
            return dungeons[map->GetId()];
    }

    int GetNumInGroup(Player* player)
    {
        int numInGroup = 1;
        Group* group = player->GetGroup();

        if (group)
        {
            Group::MemberSlotList const& groupMembers = group->GetMemberSlots();
            numInGroup = groupMembers.size();
        }
        return numInGroup;
    }

    uint32 GetClassBalance(Player* player)
    {
        uint32 classBalance = 100;

        if (classes.find(player->getClass()) == classes.end())
        {
            return classBalance;
        }
        else if (classes[player->getClass()] <= 100)
        {
            return classes[player->getClass()];
        }
        else
            return classBalance;
    }

    void ApplyBuffs(Player* player, Map* map, float difficulty, int dunLevel, int numInGroup, int classBalance)
    {
        if (difficulty != 0)
        {
            std::ostringstream msg_ru, msg_en;

            int SpellPowerBonus = 0;

            if (player->HasFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN))
            {
                SolocraftNoXPFlag = 1;
            }

            if (player->getLevel() <= dunLevel + SolocraftLevelDiff)
            {
                float GroupDifficulty = GetGroupDifficulty(player);

                if (GroupDifficulty >= difficulty && SoloCraftDebuffEnable == 1)
                {
                    difficulty = (-abs(difficulty)) + ((((float)classBalance / 100) * difficulty) / numInGroup);
                    difficulty = roundf(difficulty * 100) / 100;

                    if (!player->HasFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN) && SolocraftXPBalancingEnabled)
                    {
                        player->SetFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
                    }
                }
                else
                {
                    difficulty = (((float)classBalance / 100) * difficulty) / numInGroup;;
                    difficulty = roundf(difficulty * 100) / 100;

                    SoloCraftXPMod = (1.04 / difficulty) - 0.02;
                    SoloCraftXPMod = roundf(SoloCraftXPMod * 100) / 100;

                    if (SoloCraftXPMod < 0)
                    {
                        SoloCraftXPMod = 0;

                        if (!player->HasFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN) && SolocraftXPBalancingEnabled)
                        {
                            player->SetFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
                        }
                    }

                    if (SoloCraftXPMod > 1)
                    {
                        SoloCraftXPMod = 1.0;
                    }
                }

                QueryResult result = CharacterDatabase.PQuery("SELECT `GUID`, `Difficulty`, `GroupSize`, `SpellPower`, `Stats` FROM `custom_solocraft_character_stats` WHERE GUID = %u", player->GetGUID());

                for (int32 i = STAT_STRENGTH; i < MAX_STATS; ++i)
                {
                    if (result)
                    {
                        player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_VALUE, (*result)[1].GetFloat() * (*result)[4].GetFloat(), false);
                    }

                    player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_VALUE, difficulty * SoloCraftStatsMult, true);
                }

                player->SetFullHealth();
                player->CastSpell(player, 6962, true);

                if (player->GetPowerType() == POWER_MANA || player->getClass() == 11)
                {
                    player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));

                    if (result)
                    {
                        player->ApplySpellPowerBonus((*result)[3].GetUInt32() * (*result)[4].GetFloat(), false);
                    }

                    if (difficulty > 0)
                    {
                        SpellPowerBonus = static_cast<int>((player->getLevel() * SoloCraftSpellMult) * difficulty);
                        player->ApplySpellPowerBonus(SpellPowerBonus, true);
                    }
                }

                if (!SolocraftXPEnabled)
                {
                    SoloCraftXPMod = 0;

                    if (!player->HasFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN))
                    {
                        player->SetFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
                    }
                }

                if (difficulty > 0)
                {
                    if (!SolocraftXPEnabled)
                    {
                        msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - Изменение сложности: %0.2f. Бонус к силе заклинаний: %i. Балансировочное значение класса: %i. Получение опыта: |cffFF0000Отключено";
                        msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - Difficulty Offset: %0.2f. Spellpower Bonus: %i. Class Balance Weight: %i. XP Gain: |cffFF0000Disabled";
                        ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, SpellPowerBonus, classBalance);
                    }
                    else
                    {
                        if (!SolocraftXPBalancingEnabled)
                        {
                            msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - Изменение сложности: %0.2f. Бонус к силе заклинаний: %i. Балансировочное значение класса: %i. Баланс опыта: |cffFF0000Отключен";
                            msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - Difficulty Offset: %0.2f. Spellpower Bonus: %i. Class Balance Weight: %i. XP Balancing: |cffFF0000Disabled";
                            ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, SpellPowerBonus, classBalance);
                        }
                        else
                        {
                            msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - Изменение сложности: %0.2f. Бонус к силе заклинаний: %i. Балансировочное значение класса: %i. Баланс опыта: |cff4CFF00Включен";
                            msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - Difficulty Offset: %0.2f. Spellpower Bonus: %i. Class Balance Weight: %i. XP Balancing: |cff4CFF00Enabled";
                            ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, SpellPowerBonus, classBalance);
                        }
                    }
                }
                else
                {
                    if (!SolocraftXPBalancingEnabled && SolocraftXPEnabled)
                    {
                        msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - |cffFF0000ПОМНИТЕ - Вы не получили дебафф по изменению сложности: %0.2f с балансировочным значением класса: %i. |cffFF8000Член группы, уже находящийся внутри подземелья, получил бафф по изменению сложности. Для заклинателей не применен бонус к силе заклинаний. ВСЕ члены группы должны выйти из подземелья и войти снова, чтобы получить изменение баланса.";
                        msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - |cffFF0000BE ADVISED - You have been debuffed by offset: %0.2f with a Class Balance Weight: %i. |cffFF8000A group member already inside has the dungeon's full buff offset. No Spellpower buff will be applied to spell casters. ALL group members must exit the dungeon and re-enter to receive a balanced offset.";
                        ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, classBalance);
                    }
                    else
                    {
                        msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - |cffFF0000ПОМНИТЕ - Вы не получили дебафф по изменению сложности: %0.2f с балансировочным значением класса: %i и не будете получать опыт. |cffFF8000Член группы, уже находящийся внутри подземелья, получил бафф по изменению сложности. Для заклинателей не применен бонус к силе заклинаний. ВСЕ члены группы должны выйти из подземелья и войти снова, чтобы получить изменение баланса.";
                        msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - |cffFF0000BE ADVISED - You have been debuffed by offset: %0.2f with a Class Balance Weight: %i and no XP will be awarded. |cffFF8000A group member already inside has the dungeon's full buff offset. No Spellpower buff will be applied to spell casters. ALL group members must exit the dungeon and re-enter to receive a balanced offset.";
                        ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, classBalance);
                    }
                }

                CharacterDatabase.PExecute("REPLACE INTO custom_solocraft_character_stats (GUID, Difficulty, GroupSize, SpellPower, Stats) VALUES (%u, %f, %u, %i, %f)", player->GetGUID(), difficulty, numInGroup, SpellPowerBonus, SoloCraftStatsMult);
            }
            else
            {
                msg_ru << "|cffFF0000[СолоКрафт] |cffFF8000Игрок " << player->GetName() << " вошел в %s - |cffFF0000Вы не получили бафф.|r |cffFF8000Ваш уровень выше максимального уровня, (%i) порог этого подземелья.";
                msg_en << "|cffFF0000[SoloCraft] |cffFF8000Player " << player->GetName() << " entered %s - |cffFF0000You have not been buffed.|r |cffFF8000Your level is higher than the max level (%i) threshold for this dungeon.";
                ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), dunLevel + SolocraftLevelDiff);
                ClearBuffs(player, map);
            }
        }
        else
        {
            ClearBuffs(player, map);
        }
    }

    float GetGroupDifficulty(Player* player)
    {
        float GroupDifficulty = 0.0;
        Group* group = player->GetGroup();

        if (group)
        {
            Group::MemberSlotList const& groupMembers = group->GetMemberSlots();

            for (Group::member_citerator itr = groupMembers.begin(); itr != groupMembers.end(); ++itr)
            {
                if (itr->guid != player->GetGUID())
                {
                    QueryResult result = CharacterDatabase.PQuery("SELECT `GUID`, `Difficulty`, `GroupSize` FROM `custom_solocraft_character_stats` WHERE GUID = %u", itr->guid);

                    if (result)
                    {
                        if ((*result)[1].GetFloat() > 0)
                        {
                            GroupDifficulty = GroupDifficulty + (*result)[1].GetFloat();
                        }
                    }
                }
            }
        }

        return GroupDifficulty;
    }

    void ClearBuffs(Player* player, Map* map)
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT `GUID`, `Difficulty`, `GroupSize`, `SpellPower`, `Stats` FROM `custom_solocraft_character_stats` WHERE GUID = %u", player->GetGUID());

        if (result)
        {
            float difficulty = (*result)[1].GetFloat();
            int SpellPowerBonus = (*result)[3].GetUInt32();
            float StatsMultPct = (*result)[4].GetFloat();
            SoloCraftXPMod = 1.0;

            std::ostringstream msg_ru, msg_en;
            msg_ru << "|cffFF0000[СолоКрафт]|r |cffFF8000" << player->GetName() << " покинул %s - Возврат изменения сложности: %0.2f. Бонус к силе заклинаний удален: %i";
            msg_en << "|cffFF0000[SoloCraft]|r |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f. Spellpower Bonus Removed: %i";
            ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, msg_ru.str().c_str(), msg_en.str().c_str()), map->GetMapName(), difficulty, SpellPowerBonus);

            for (int32 i = STAT_STRENGTH; i < MAX_STATS; ++i)
            {
                player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_VALUE, difficulty * StatsMultPct, false);
            }

            if (player->GetPowerType() == POWER_MANA && difficulty > 0)
            {
                player->ApplySpellPowerBonus(SpellPowerBonus, false);
            }

            if (player->HasFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN) && !SolocraftNoXPFlag)
            {
                player->RemoveFlag(PLAYER_FIELD_PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
            }

            SolocraftNoXPFlag = 0;

            CharacterDatabase.PExecute("DELETE FROM custom_solocraft_character_stats WHERE GUID = %u", player->GetGUID());
        }
    }
};

void AddSC_solocraft_system()
{
    new solocraft_system_config();
    new solocraft_system_announce();
    new solocraft_system_player_instance_handler();
}
