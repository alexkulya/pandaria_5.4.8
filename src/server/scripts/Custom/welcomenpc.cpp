#include "ScriptPCH.h"
#include "Chat.h"
 
enum bags_id
{
        bag_24 = 51809, // Unused
        bag_36 = 23162, // Used
 
        Number_of_Bags = 4 // 1-2-3-4 Default
};
 
enum Spell_Talent // Need More Attention (Unlearn Somes Bad Spells)
{
        //Priest
        Priest_Spell_Penance = 47540,
        Priest_Spell_Chastise = 88625,
        Priest_Spell_MindFlay = 15407,
        //Mage
        Mage_Spell_Arcane_Barrage = 44425,  
        Mage_Spell_Pyroblast = 11366,
        Mage_Spell_Water_Elemental = 31687,
        Mage_Spell_Freeze = 33395,
        Mage_Spell_Waterbolt = 31707,
        Mage_Spell_AM = 7268,
        //Shaman
        Shaman_Spell_Thunderstorm = 51490,
        Shaman_Spell_LavaLash = 60103,
        Shaman_Spell_EarthShield = 974,
        //Hunter
        Hunter_Spell_Intimidation = 19577,
        Hunter_Spell_Aimed_Shot = 19434,
        Hunter_Spell_Explosive_Shot = 53301,
        //DK
        DK_Spell_Heart_Strike = 55050,  
        DK_Spell_Frost_Strike = 49143,
        DK_Spell_Scourge_Strike = 55090,
        //Rogue
        Rogue_Spell_Mutilate = 1329,
        Rogue_Spell_Blade_Flurry = 13877,
        Rogue_Spell_ShadowStep = 36554,
        //Druid
        Druid_Spell_Starsurge = 78674,
        Druid_Spell_Mangle = 33917,
        Druid_Spell_Swiftmend = 18562,
        //Warlock
        Warlock_Spell_Unstable_Afflication = 30108,
        Warlock_Spell_Summon_Felguard = 30146,
        Warlock_Spell_Conflagrate = 17962,
        //Warrior
        Warrior_Spell_Mortal_Strike = 12294,
        Warrior_Spell_Bloodthirst = 23881,
        Warrior_Spell_Shield_Slam = 23922,
        //Paladin
        Paladin_Spell_Holy_Shock = 20473,
        Paladin_Spell_Avenger_shield = 31935,
        Paladin_Spell_Templar_Verdict = 85256,
};
 
enum Specialisazion
{
        Spell_Dual_Wield = 674,
        Spell_Spec_War_Plate = 87509, // War Only
        Spell_Spec_Pal_Plate = 87511, // Pal Only
        Spell_Spec_DK_Plate = 87510, // Dk Only
        Spell_Spec_Druid_Leather = 87505, // Druid
        Spell_Spec_Rogue_Leather = 87504, // rogue
        Spell_Spec_Hunt_Mail = 87506, // Hunter ()
        Spell_Spec_Shaman_Mail = 87507, //Shaman
        Spell_netherMancy = 86091, //Warlock
        Spell_Wizardry = 89744, //Mage
        Spell_Mysticism = 89745, //Priest
        Spell_Equip_plate = 750, // Pala-War-DK
        Spell_Equip_Mail = 8737, // Hunt-Shaman
        Spell_Equip_Leather = 9077 // Druid-Rogue
};
 
enum spell_mastery
{
        spell_mastery_warrior = 87500,
        spell_mastery_mage = 86467,
        spell_mastery_druid = 87491,
        spell_mastery_dk = 87492,
        spell_mastery_hunter = 87493,
        spell_mastery_paladin = 87494,
        spell_mastery_priest = 87495,
        spell_mastery_rogue = 87496,
        spell_mastery_shaman = 87497,
        spell_mastery_warlock = 87498
};
 
enum mount_spell
{
        mount_spell_Master_Riding = 90265,
        mount_spell_Journeyman_Riding = 33392,
        mount_spell_Cold_Weather_Flying = 54197,
        mount_spell_Flight_Master_License = 90267
};
#define TEXT_CUSTOM_RED1                      "|cff990033"
#define TEXT_CUSTOM_RED2                      "|cff000033"
#define TEXT_CUSTOM_RED3                      "|cff873600"
#define TEXT_CUSTOM_RED4                      "|cff873600"
#define TEXT_CUSTOM_ORANGE                      "|cff873600"
#define TEXT_CUSTOM_RED                         "|cffA40000"
#define TEXT_CUSTOM_BLUE                        "|cff00479E"
#define TEXT_CUSTOM_GREEN                       "|cff065600"
#define TEXT_CUSTOM_PURPLE                      "|cff5A005B"
#define TEXT_CUSTOM_GREY                        "|cff515151"
#define TEXT_CUSTOM_CYAN                        "|cff005853"
#define TEXT_CUSTOM_BROWN                       "|cff584200"
 
//////////////////////WELCOME MENU/////////////////////////////////
#define Class_Skills  "|TInterface/ICONS/Achievement_FeatsOfStrength_Gladiator_05:30:30:-15.3:0|t[LEARN MY CLASS SKILLS]"      
#define Glyph_Skills  "|TInterface/ICONS/Achievement_FeatsOfStrength_Gladiator_06:30:30:-15.1:0|t[LEARN MY GLYPH  SKILLS]"
#define Riding_Skills "|TInterface/ICONS/Achievement_FeatsOfStrength_Gladiator_07:30:30:-15.2:0|t[LEARN MY RIDING SKILLS]"
#define Reset_Talents "|TInterface/ICONS/Achievement_FeatsOfStrength_Gladiator_08:30:30:-15.5:0|t[RESET MY TALENTS]"                              
//////////////////////////////////////////////////////////////////
 
class npc_welcome : public CreatureScript
{
public:
        npc_welcome() : CreatureScript("npc_welcome") { }
 
        bool OnGossipHello(Player* player, Creature* creature)
        {
                if (player->getLevel() >= 85)
                {
                        {
                                player->PrepareQuestMenu(creature->GetGUID());
                                player->SendPreparedQuest(creature->GetGUID());
                        }
                        ///////////////////////////////*   -- Colors --  */
                        player->ADD_GOSSIP_ITEM(0, /**/TEXT_CUSTOM_GREEN/**/ Class_Skills, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                        player->ADD_GOSSIP_ITEM(0, /**/TEXT_CUSTOM_ORANGE/**/Glyph_Skills, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                        player->ADD_GOSSIP_ITEM(0, /**/TEXT_CUSTOM_CYAN/**/ Riding_Skills, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                        player->ADD_GOSSIP_ITEM(0, /**/TEXT_CUSTOM_RED1/**/ Reset_Talents, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                }
                else
                {
                        player->PlayerTalkClass->SendCloseGossip();
                        return false;
                }
                return true;
        }
 
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
                uint32 mount_spells[4] =
                {
                        mount_spell_Flight_Master_License,mount_spell_Journeyman_Riding,mount_spell_Cold_Weather_Flying,mount_spell_Master_Riding
                };
 
                uint32 Remove_T_Spell[33] =
                {
                        Priest_Spell_Penance,Priest_Spell_Chastise,Priest_Spell_MindFlay,Mage_Spell_Arcane_Barrage,Mage_Spell_Pyroblast,Mage_Spell_Water_Elemental,Shaman_Spell_Thunderstorm,Shaman_Spell_LavaLash,Shaman_Spell_EarthShield,Hunter_Spell_Intimidation,Hunter_Spell_Aimed_Shot,Hunter_Spell_Explosive_Shot,DK_Spell_Heart_Strike,DK_Spell_Frost_Strike,DK_Spell_Scourge_Strike,Rogue_Spell_Mutilate,Rogue_Spell_Blade_Flurry,Rogue_Spell_ShadowStep,Druid_Spell_Starsurge,Druid_Spell_Mangle,Druid_Spell_Swiftmend,Warlock_Spell_Unstable_Afflication,Warlock_Spell_Summon_Felguard,Warlock_Spell_Conflagrate,Warrior_Spell_Mortal_Strike,Warrior_Spell_Bloodthirst,Warrior_Spell_Shield_Slam,Paladin_Spell_Holy_Shock,Paladin_Spell_Avenger_shield,Paladin_Spell_Templar_Verdict,
                        Mage_Spell_Freeze,Mage_Spell_Waterbolt,Mage_Spell_AM,
                };
 
                player->PlayerTalkClass->ClearMenus();
                {
                        switch(action)
                        {
                        case GOSSIP_ACTION_INFO_DEF+1:
                                {
                                        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(player->GetSession()->GetPlayer()->getClass());
                                        if (!classEntry)
                                                return true;
                                        uint32 family = classEntry->spellfamily;
                                        for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
                                        {
                                                SkillLineAbilityEntry const* entry = sSkillLineAbilityStore.LookupEntry(i);
                                                if (!entry)
                                                        continue;
                                                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(entry->spellId);
                                                if (!spellInfo)
                                                        continue;
                                                // skip server-side/triggered spells
                                                if (spellInfo->SpellLevel == 0)
                                                        continue;
                                                // skip wrong class/race skills
                                                if (!player->GetSession()->GetPlayer()->IsSpellFitByClassAndRace(spellInfo->Id))
                                                        continue;
                                                // skip other spell families
                                                if (spellInfo->SpellFamilyName != family)
                                                        continue;
                                                // skip spells with first rank learned as talent (and all talents then also)
                                                if (GetTalentSpellCost(spellInfo->GetFirstRankSpell()->Id) > 0)
                                                        continue;
                                                // skip broken spells
                                                if (!SpellMgr::IsSpellValid(spellInfo, player->GetSession()->GetPlayer(), false))
                                                        continue;
                                                player->GetSession()->GetPlayer()->learnSpell(spellInfo->Id, false);
                                        }
                                        /*-- Unlearn Talent Points Before (Prevention) --*/
                                        player->ResetTalents(true);
                                        //Client Update
                                        if(!player->GetSession()->PlayerLoading())
                                        {
                                                player->SendTalentsInfoData(false);
                                        }
                                        /*-- Removing Spells Learned by spending 11 Talents Points (Need More attention)--*/
                                        for(uint32 i = 0; i < sizeof(Remove_T_Spell)/sizeof(uint32); i++)
                                                player->removeSpell(Remove_T_Spell[i],false);
                                        // General Spells -- Mastery etc (Need Manually - Could not be added by function)
                                        if(player->getClass() == CLASS_WARRIOR)
                                        {
                                                player->learnSpell(spell_mastery_warrior,false);
                                                player->learnSpell(Spell_Spec_War_Plate,false);
                                                player->learnSpell(Spell_Equip_plate,false);
                                        }
                                        if(player->getClass() ==  CLASS_PALADIN)
                                        {
                                                player->learnSpell(spell_mastery_paladin,false);
                                                player->learnSpell(Spell_Spec_Pal_Plate,false);
                                                player->learnSpell(Spell_Equip_plate,false);
                                        }
                                        if(player->getClass() ==   CLASS_HUNTER)
                                        {
                                                player->learnSpell(spell_mastery_hunter,false);
                                                player->learnSpell(Spell_Spec_Hunt_Mail,false);
                                                player->learnSpell(Spell_Dual_Wield,false);
                                                player->learnSpell(Spell_Equip_Mail,false);
                                        }
                                        if(player->getClass() ==   CLASS_ROGUE)
                                        {
                                                player->learnSpell(spell_mastery_rogue,false);
                                                player->learnSpell(Spell_Spec_Rogue_Leather,false);
                                                player->learnSpell(Spell_Equip_Leather,false);
                                        }
                                        if(player->getClass() ==  CLASS_PRIEST)
                                        {
                                                player->learnSpell(spell_mastery_priest,false);
                                                player->learnSpell(Spell_Mysticism,false);
                                        }
                                        if(player->getClass() == CLASS_DEATH_KNIGHT)
                                        {
                                                player->learnSpell(spell_mastery_dk,false);
                                                player->learnSpell(Spell_Spec_DK_Plate,false);
                                                player->learnSpell(Spell_Equip_plate,false);
                                        }
                                        if(player->getClass() == CLASS_SHAMAN)
                                        {
                                                player->learnSpell(spell_mastery_shaman,false);
                                                player->learnSpell(Spell_Spec_Shaman_Mail,false);
                                                player->learnSpell(Spell_Equip_Mail,false);
                                        }
                                        if(player->getClass() == CLASS_MAGE)
                                        {
                                                player->learnSpell(spell_mastery_mage,false);
                                                player->learnSpell(Spell_Wizardry,false);
                                        }
                                        if(player->getClass() == CLASS_WARLOCK)
                                        {
                                                player->learnSpell(spell_mastery_warlock,false);
                                                player->learnSpell(Spell_netherMancy,false);
                                        }
                                        if(player->getClass() == CLASS_DRUID)
                                        {
                                                player->learnSpell(spell_mastery_druid,false);
                                                player->learnSpell(Spell_Equip_Leather,false);
                                                player->learnSpell(Spell_Spec_Druid_Leather,false);
                                        }
                                        /**DUAL SPEC*////////////////////////////////////////////////////////////
                                        /**/player->CastSpell(player,63680,true,NULL,NULL,player->GetGUID());///
                                        /**/player->CastSpell(player,63624,true,NULL,NULL,player->GetGUID());//
                                        /**///////////////////////////////////////////////////////////////////
 
                                        // Bags
                                        if(!player->HasItemCount(bag_36, 4,false))
                                        {
                                                player->AddItem(bag_36, Number_of_Bags);
                                        }
                                        player->SaveToDB();
                                        player->CLOSE_GOSSIP_MENU();
                                }
                                break;
 
        case GOSSIP_ACTION_INFO_DEF+2:
                // Checking Glyph Items & Extracting Origin Spells
                for(ItemTemplateContainer::const_iterator
                        itr = sObjectMgr->GetItemTemplateStore()->begin();
                        itr!=sObjectMgr->GetItemTemplateStore()->end();itr++){
                                if(ItemTemplate const* templ=&itr->second){
                                        for(int i=0;i<MAX_ITEM_PROTO_SPELLS;i++){
                                                if(SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(templ->Spells[i].SpellId)){    
                                                        {
                                                                // skip broken spells
                                                                if (!SpellMgr::IsSpellValid(spellInfo, player->GetSession()->GetPlayer(), false))
                                                                        continue;
                                                        }
                                                        // Final Step : Learning Glyphs
                                                        if(templ->Class==16&&templ->SubClass== player->getClass()){
                                                                player->learnSpell(templ->Spells[i].SpellId,false);}
                                                }}}}  
                // Few Problems Fix here
                player->removeSpell(58240,false);
                player->removeSpell(46831,false);
                player->removeSpell(60460,false);
                player->removeSpell(51220,false);
 
                player->CastSpell(player,95794);
                player->SaveToDB();
                player->CLOSE_GOSSIP_MENU();
                break;
 
        case GOSSIP_ACTION_INFO_DEF+3:
                {
                        for(uint32 i = 0; i < sizeof(mount_spells)/sizeof(uint32); i++)
                                player->learnSpell(mount_spells[i],false);
                        if (player->GetTeam() == HORDE)
                        {
                                player->AddItem(46749, 1);
                                player->AddItem(44690, 1);                                            
                        }
                        else
                        {
                                player->AddItem(44689, 1);
                                player->AddItem(45125, 1);
                        }
                        player->CLOSE_GOSSIP_MENU();
                }
                break;
 
        case GOSSIP_ACTION_INFO_DEF+4:
                player->ResetTalents(true);
                //Client Update
                if(!player->GetSession()->PlayerLoading())
                {
                        player->SendTalentsInfoData(false);
                }
                player->CastSpell(player,95794);
                player->SaveToDB();
                player->CLOSE_GOSSIP_MENU();
                break;
                        }
                }
                return true;
        }
 
};
 
void AddSC_npc_welcome()
{
        new npc_welcome();
}
