/*
	Reinicio de Arenas
		ID logros       ID Criterio     Nombres                             Descripción
		397             306             Entra en la arena                   Gana 1 encuentro de arena puntuado
		398             307             Despiadadamente entregado           Gana 100 encuentros de arena
        399             329             Entre tu yo: 1550                   Indice personal en 2 vs 2
		400             332				Entre tu yo: 1750				    Indice personal en 2 vs 2
		401             335				Entre tu yo: 2000				    Indice personal en 2 vs 2
        402             330             Tres son multitud: 1550             Indice personal en 3 vs 3
		403             333             Tres son multitud: 1750             Indice personal en 3 vs 3
		405             336             Tres son multitud: 2000             Indice personal en 3 vs 3
        404             337             Choca esos cinco: 2000              Indice personal en 5 vs 5
        406             331             Choca esos cinco: 1550              Indice personal en 5 vs 5
		407             334             Choca esos cinco: 1750              Indice personal en 5 vs 5
        409             2408            Una buena racha                     Gana 10 encuentros en la arena sin perder
        409             3822            El último hombre en pie             Sé el único superviviente en 5c5.
		699             608             Ganador mundial                     Gana un encuentro de arena puntuado en todas las arenas
		699             609		        Ganador mundial
		699             610             Ganador mundial
		699             5809            Ganador mundial
		699             5810            Ganador mundial
		875             1829            Vengativamente entregado            Gana 200 encuentros de arena
		876             1830            Brutalmente entregado               Gana 200 encuentros de arena
        1159            3381            Entre tú y yo: 2200                 Indice personal en  2 vs 2	
        1160            3382            Tres son multitud: 2200             Indice personal en  3 vs 3
		1161            3383            Choca esos cinco: 2200              Indice personal en  5 vs 5
        1162            3384            Una racha mejor                     Gana diez encuentros puntuados seguidos con un índice personal superior a 1800.
        1174            3488            El maestro de la arena              Completa los logros de arena listados a continuación.
        1174            3489            El maestro de la arena
        1174            3490            El maestro de la arena
        1174            3491            El maestro de la arena
        1174            3492            El maestro de la arena
        1174            3493            El maestro de la arena
        1174            3494            El maestro de la arena
        1174            3496            El maestro de la arena
        1490            5533            Golpes de gracia en la arena        Golpes de gracia en la arena
        1490            5534            Golpes de gracia en la arena
        1490            5535            Golpes de gracia en la arena
        1490            9165            Golpes de gracia en la arena
        1490            9166            Golpes de gracia en la arena
        1492            5541            Golpes de gracia en la arena 2c2    Golpes de gracia en la arena 2c2
        1493            5542            Golpes de gracia en la arena 3c3    Golpes de gracia en la arena 3c3
        1494            5543            Golpes de gracia en la arena 5c5    Golpes de gracia en la arena 5c5
        5266            15001           Tres son multitud: 2400             Indice personal en 3 vs 3
        5267            15002           Tres son multitud: 2700             Indice personal en 3 vs 3
        5542            16309           1000 puntos de conquista            Gana 1000 puntos de conquista
		5541            16310           5000 puntos de conquista            Gana 5000 puntos de conquista
		5540            16311           25000 puntos de conquista           Gana 25000 puntos de conquista
		5539            16312           50000 puntos de conquista           Gana 50000 puntos de conquista
*/

-- remover logros de todos los personajes
DELETE FROM character_achievement WHERE achievement IN (397, 398, 399, 400, 401, 402, 403, 405, 404, 406, 407, 409, 699, 875, 876, 1159, 1160, 1161, 1162, 1174, 1490, 1492, 1493, 1494, 5266, 5267, 5542, 5541, 5540, 5539);

DELETE FROM account_achievement WHERE achievement IN (397, 398, 399, 400, 401, 402, 403, 405, 404, 406, 407, 409, 699, 875, 876, 1159, 1160, 1161, 1162, 1174, 1490, 1492, 1493, 1494, 5266, 5267, 5542, 5541, 5540, 5539);
-- remover progresos de logros de arena de todos los personajes
DELETE FROM character_achievement_progress WHERE criteria IN (306, 307, 329, 332, 335, 330, 333, 336, 337, 331, 334, 2408, 3822, 608, 609, 610, 5809, 5810, 1829, 1830, 3381, 3382, 3383, 3384, 3488, 3489, 3490, 3491, 3492, 3493, 3494, 3496, 5533, 5534, 5535, 9165, 9166, 5541, 5542, 5543, 15001, 15002, 16309, 16310, 16311, 16312);
DELETE FROM account_achievement_progress WHERE criteria IN (306, 307, 329, 332, 335, 330, 333, 336, 337, 331, 334, 2408, 3822, 608, 609, 610, 5809, 5810, 1829, 1830, 3381, 3382, 3383, 3384, 3488, 3489, 3490, 3491, 3492, 3493, 3494, 3496, 5533, 5534, 5535, 9165, 9166, 5541, 5542, 5543, 15001, 15002, 16309, 16310, 16311, 16312);

/*
-- Reiniciando el registro de las arenas jugadas
-- DB_auth - realm = 1 , cambiar si se aplica a otro reino
UPDATE `arena_game_id` SET `game_id` = 1 WHERE `realm_id` = 1;
DELETE FROM `arena_games` WHERE `realmid` = 1;
*/

-- Reiniciando los índices de las arenas y los puntos de conquista
-- DB_characters
DELETE FROM `rated_pvp_info`;
DELETE FROM `character_currency` WHERE `currency` = 484;
DELETE FROM `character_currency` WHERE `currency` = 483;
DELETE FROM `character_currency` WHERE `currency` = 390;
-- UPDATE `character_currency` SET `season_count` = 55725, `total_count` = 0, `week_count` = 0, `flags` = 254 WHERE `currency` = 390;



/*
	Reinicio de RBGs
		ID logros       ID Criterio     Nombres                             Descripción
		5268			15005			Al servicio de la Alianza			Gana un campo de batalla puntuado
		5269			15006			Al servicio de la Horda				Gana un campo de batalla puntuado
		5322			15286			Al servicio de la Alianza			Gana 10 campos de batalla puntuados
		5323			15287			Al servicio de la Horda				Gana 10 campos de batalla puntuados
		5324			15288			Al servicio de la Horda				Gana 25 campos de batalla puntuados
		5325			15289			Veterano de la Horda				Gana 75 campos de batalla puntuados
		5326			15290			Batallador de la Horda				Gana 300 campos de batalla puntuados
		5327			15291			Al servicio de la Alianza			Gana 25 campos de batalla puntuados
		5328			15292			Veterano de la Alianza				Gana 75 campos de batalla puntuados
		5329			15293			Campeador veterano de la Alianza	Gana 300 campos de batalla puntuados
		5330			15294			Soldado								Consigue un índice de campo de batalla de 1100.
		5331			15295			Cabo								Consigue un índice de campo de batalla de 1200.
		5332			15296			Capataz								Consigue un índice de campo de batalla de 1300.
		5333			15297			Sargento primero					Consigue un índice de campo de batalla de 1400.
		5334			15298			Alférez								Consigue un índice de campo de batalla de 1500.
		5335			15299			Caballero							Consigue un índice de campo de batalla de 1600.
		5336			15300			Teniente caballero					Consigue un índice de campo de batalla de 1700.
		5337			15301			Capitán caballero					Consigue un índice de campo de batalla de 1800.
		5338			15302			Centurión							Consigue un índice de campo de batalla de 1900.
		5339			15303			Teniente coronel					Consigue un índice de campo de batalla de 2000.
		5340			15304			Comandante							Consigue un índice de campo de batalla de 2100.
		5341			15305			Mariscal							Consigue un índice de campo de batalla de 2200.
		5342			15306			Señor de la Guerra					Consigue un índice de campo de batalla de 2300.
		5343			15307			Gran mariscal						Consigue un índice de campo de batalla de 2400.
		5345			15309			Rastreador							Consigue un índice de campo de batalla de 1100.
		5346			15310			Bruto								Consigue un índice de campo de batalla de 1200.
		5347			15311			Capataz								Consigue un índice de campo de batalla de 1300.
		5348			15312			Capataz primero						Consigue un índice de campo de batalla de 1400.
		5349			15313			Gran capataz						Consigue un índice de campo de batalla de 1500.
		5350			15314			Guardia de piedra					Consigue un índice de campo de batalla de 1600.
		5351			15315			Guardia de sangre					Consigue un índice de campo de batalla de 1700.
		5352			15316			Legionario							Consigue un índice de campo de batalla de 1800.
		5353			15317			Campeón								Consigue un índice de campo de batalla de 2000.
		5354			15318			General								Consigue un índice de campo de batalla de 2100.
		5355			15319			Gran general						Consigue un índice de campo de batalla de 2200.
		5356			15320			Gran Señor de la Guerra				Consigue un índice de campo de batalla de 2400.
		5357			15321			Mariscal de campo					Consigue un índice de campo de batalla de 2300.
		5359			15323			Campeón caballero					Consigue un índice de campo de batalla de 1900.
		5823			17546			Veterano de la Alianza II			Gana 150 campos de batalla puntuados.
		5824			17547			Veterano de la Horda II				Gana 150 campos de batalla puntuados.
		8484							Combatiente severo					Gana 100 arenas (3c3) o 40 campos de batalla puntuados en la temporada 14.
		8485							Combatiente severo					Gana 100 arenas (3c3) o 40 campos de batalla puntuados en la temporada 14.
		8641							Combatiente orgulloso				Gana 100 arenas (3c3) o 40 campos de batalla puntuados en la temporada 15.
		8642							Combatiente orgulloso				Gana 100 arenas (3c3) o 40 campos de batalla puntuados en la temporada 15.		
*/

-- DB_characters
DELETE FROM `character_battleground_stats`;
DELETE FROM `character_currency` WHERE `currency` = 692;

DELETE FROM character_achievement WHERE achievement IN (5268, 5269, 5322, 5323, 5324, 5325, 5326, 5327, 5328, 5329, 5330, 5331, 5332, 5333, 5334, 5335, 5336, 5337, 5338, 5339, 5340, 5341, 5342, 5343, 5345, 5346, 5347, 5348, 5349, 5350, 5351, 5352, 5353, 5354, 5355, 5356, 5357, 5359, 5823, 5824, 8484, 8485, 8641, 8642);

DELETE FROM account_achievement WHERE achievement IN (5268, 5269, 5322, 5323, 5324, 5325, 5326, 5327, 5328, 5329, 5330, 5331, 5332, 5333, 5334, 5335, 5336, 5337, 5338, 5339, 5340, 5341, 5342, 5343, 5345, 5346, 5347, 5348, 5349, 5350, 5351, 5352, 5353, 5354, 5355, 5356, 5357, 5359, 5823, 5824, 8484, 8485, 8641, 8642);

DELETE FROM character_achievement_progress WHERE criteria IN (15005, 15006, 15286, 15287, 15288, 15289, 15290, 15291, 15292, 15293, 15294, 15295, 15296, 15297, 15298, 15299, 15300, 15301, 15302, 15303, 15304, 15305, 15306, 15307, 15309, 15310, 15311, 15312, 15313, 15314, 15315, 15316, 15317, 15318, 15319, 15320, 15321, 15323, 17546, 17547);

DELETE FROM account_achievement_progress WHERE criteria IN (15005, 15006, 15286, 15287, 15288, 15289, 15290, 15291, 15292, 15293, 15294, 15295, 15296, 15297, 15298, 15299, 15300, 15301, 15302, 15303, 15304, 15305, 15306, 15307, 15309, 15310, 15311, 15312, 15313, 15314, 15315, 15316, 15317, 15318, 15319, 15320, 15321, 15323, 17546, 17547);
