-- =====================================================================
-- Battle Pay: fill in the missing esES locale rows.
--
-- Coverage before this script (base rows vs esES rows):
--     battle_pay_entry     170 ->  34 esES   (136 missing)
--     battle_pay_product   169 ->  26 esES   (143 missing)
--     battle_pay_group      12 ->  12 esES   (complete, untouched)
--
-- Item names are NOT invented here: they are the official esES names taken
-- from `locales_item`. That table is partially double-encoded (about 13k of
-- its 68k esES rows store UTF-8 that was re-encoded as if it were latin1,
-- e.g. 'a' with acute stored as C383C2A1 instead of C3A1), so the affected
-- names were repaired with
--     CONVERT(BINARY(CONVERT(Name USING latin1)) USING utf8mb4)
-- before being written here. Everything below is plain, correct UTF-8, which
-- is what the core expects: it connects with `mysql_set_character_set(utf8)`
-- (MySQLConnection.cpp) and hands the bytes straight to the client.
--
-- The remaining strings (mount/pet type lines, currency and character
-- service texts) are translated from the English source rows.
--
-- Titles keep the formatting of their table: `battle_pay_entry` wraps the
-- name in its quality colour code (|cffXXXXXX...|r) and `battle_pay_product`
-- prefixes it with "Tienda:" plus a newline, matching the esES rows that
-- already existed.
--
-- NOTE: the 22 esES rows that were already present in these two tables are
-- themselves double-encoded and therefore render as mojibake in game. They
-- are deliberately left alone here - repairing them is a separate change.
-- =====================================================================

SET NAMES utf8mb4;

DELETE FROM `battle_pay_entry_locale` WHERE `Locale` = 'esES' AND `ID` IN (7,8,9,10,11,12,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,84,85,86,87,88,89,90,94,95,96,97,98,99,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167);
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES
(7, 'esES', '|cff1eff001.000 de oro|r', 'Te otorga 1.000 de oro.'),
(8, 'esES', '|cff1eff005.000 de oro|r', 'Te otorga 5.000 de oro.'),
(9, 'esES', '|cff0070dd10.000 de oro|r', 'Te otorga 10.000 de oro.'),
(10, 'esES', '|cff0070dd30.000 de oro|r', 'Te otorga 30.000 de oro.'),
(11, 'esES', '|cffa335ee80.000 de oro|r', 'Te otorga 80.000 de oro.'),
(12, 'esES', '|cffff8000150.000 de oro|r', 'Te otorga 150.000 de oro.'),
(31, 'esES', '|cffa335eeBrida de semental blanco|r', 'Montura terrestre'),
(32, 'esES', '|cffa335eeCarnero de escarcha|r', 'Montura terrestre'),
(33, 'esES', '|cffa335eeCarnero negro|r', 'Montura terrestre'),
(34, 'esES', '|cffa335eeCuerno del lobo ártico|r', 'Montura terrestre'),
(35, 'esES', '|cffa335eeCuerno del lobo rojo|r', 'Montura terrestre'),
(36, 'esES', '|cffa335eeKodo azulado|r', 'Montura terrestre'),
(37, 'esES', '|cffa335eeKodo verde|r', 'Montura terrestre'),
(38, 'esES', '|cffa335eeMecazancudo azul hielo modelo A|r', 'Montura terrestre'),
(39, 'esES', '|cffa335eeMecazancudo blanco modelo B|r', 'Montura terrestre'),
(40, 'esES', '|cffa335eeRiendas del sable de hielo anciano|r', 'Montura terrestre'),
(41, 'esES', '|cffa335eeRiendas del sable de la noche|r', 'Montura terrestre'),
(42, 'esES', '|cffa335eeSilbato del raptor marfil|r', 'Montura terrestre'),
(43, 'esES', '|cffa335eeSilbato del raptor rojo jaspeado|r', 'Montura terrestre'),
(44, 'esES', '|cffa335eeRiendas de protodraco herrumbroso|r', 'Montura voladora'),
(45, 'esES', '|cffa335eeRiendas de protodraco vinculahierro|r', 'Montura voladora'),
(46, 'esES', '|cffa335eeRiendas de vencedor Razaescarcha bañado en sangre|r', 'Montura voladora'),
(47, 'esES', '|cffa335eeRiendas del draco azul|r', 'Montura voladora'),
(48, 'esES', '|cffa335eeRiendas del vencedor Razaescarcha vinculado al hielo|r', 'Montura voladora'),
(49, 'esES', '|cffa335eeRiendas del draco de piedra volcánico|r', 'Montura voladora'),
(50, 'esES', '|cffa335eeRiendas del draco del Viento del Este|r', 'Montura voladora'),
(51, 'esES', '|cffa335eeRiendas del draco del Viento del Norte|r', 'Montura voladora'),
(52, 'esES', '|cffa335eeRiendas del draco de piedra fosforescente|r', 'Montura voladora'),
(53, 'esES', '|cffa335eeRiendas del draco de piedra vítreo|r', 'Montura voladora'),
(54, 'esES', '|cffa335eeRiendas del presagista Crepuscular|r', 'Montura voladora'),
(55, 'esES', '|cffa335eeHalcón zancudo blanco presto|r', 'Montura terrestre'),
(56, 'esES', '|cffa335eeRiendas del Lord Cuervo|r', 'Montura terrestre'),
(57, 'esES', '|cffa335eeRiendas del protodraco apestado|r', 'Montura voladora'),
(58, 'esES', '|cffa335eeRiendas del protodraco azul|r', 'Montura voladora'),
(59, 'esES', '|cffa335eeRiendas del protodraco negro|r', 'Montura voladora'),
(60, 'esES', '|cffa335eeRiendas del protodraco rojo|r', 'Montura voladora'),
(61, 'esES', '|cffa335eeHuevo de Millagazor corrupto|r', 'Montura voladora'),
(62, 'esES', '|cffa335eePantera Zulian presta|r', 'Montura terrestre'),
(63, 'esES', '|cffa335eeRaptor fosilizado|r', 'Montura terrestre'),
(64, 'esES', '|cffa335eeRaptor Razzashi acorazado|r', 'Montura terrestre'),
(65, 'esES', '|cffa335eeRiendas del draco Ala Abisal azur|r', 'Montura voladora'),
(66, 'esES', '|cffa335eeRiendas del draco Ala Abisal cobalto|r', 'Montura voladora'),
(67, 'esES', '|cffa335eeRiendas del draco Ala Abisal morado|r', 'Montura voladora'),
(68, 'esES', '|cffa335eeRiendas del draco Ala Abisal ónice|r', 'Montura voladora'),
(69, 'esES', '|cffa335eeRiendas del draco Ala Abisal veridiano|r', 'Montura voladora'),
(70, 'esES', '|cffa335eeRiendas del draco Ala Abisal violeta|r', 'Montura voladora'),
(71, 'esES', '|cffa335eeRiendas de destrero de la muerte|r', 'Montura terrestre'),
(72, 'esES', '|cffa335eeRiendas del talbuk de guerra oscuro|r', 'Montura terrestre'),
(73, 'esES', '|cffa335eeRiendas del talbuk de montar oscuro|r', 'Montura terrestre'),
(74, 'esES', '|cffa335eeOso de batalla Amani|r', 'Montura terrestre'),
(75, 'esES', '|cffa335eeRiendas del draco bronce|r', 'Montura voladora'),
(76, 'esES', '|cffa335eeRiendas del protodraco Tiempo Perdido|r', 'Montura voladora'),
(77, 'esES', '|cffa335eeRiendas del protodraco verde|r', 'Montura voladora'),
(78, 'esES', '|cffa335eeVial de las arenas|r', 'Montura voladora'),
(79, 'esES', '|cffa335eeChopper de mekigeniero|r', 'Montura terrestre'),
(80, 'esES', '|cffa335eeMeca-jarly|r', 'Montura terrestre'),
(81, 'esES', '|cffa335eeRiendas del oso polar blanco|r', 'Montura terrestre'),
(82, 'esES', '|cffa335eeSilbato del ravasaurio Pellejo Venenoso|r', 'Montura terrestre'),
(84, 'esES', '|cffa335eeBrida de Palomino|r', 'Montura terrestre'),
(85, 'esES', '|cffa335eeDragón hada encantado|r', 'Montura voladora'),
(86, 'esES', '|cffa335eeQuilen imperial|r', 'Montura voladora'),
(87, 'esES', '|cffa335eeCorcel del viento presto|r', 'Montura voladora'),
(88, 'esES', '|cffa335eeRaptor Razzashi presto|r', 'Montura terrestre'),
(89, 'esES', '|cffa335eeRinoceronte blanco lanudo|r', 'Montura terrestre'),
(90, 'esES', '|cffa335eeCohete de paseo X-53|r', 'Montura voladora'),
(94, 'esES', '|cffffd700Cambio de nombre|r', 'No tienes por qué llevar el mismo nombre toda la vida. Puede que te hayas cansado de que te persigan para pedirte autógrafos (o para partirte la cara), o puede que simplemente se te haya ocurrido algo mejor. En cualquier caso, ¡nombre nuevo, vida nueva!'),
(95, 'esES', '|cffffd700Cambio de facción|r', '«¡Traidor!...» Sí, es fácil soltar frases grandilocuentes. A tus aliados de facción no les hará gracia que hayas decidido marcharte. Pero, en realidad, ¿qué les debes? Quizá sea el momento de ver cómo les va a los demás. ¡A lo mejor ya tienes amigos allí! Quién sabe, igual resulta que, como suele decirse, los «épicos» son más morados donde no estamos... El cambio de facción incluye un cambio de raza, para que sea más fácil unirse a las filas de los nuevos aliados.'),
(96, 'esES', '|cffffd700Cambio de raza|r', 'La genética es cruel. Prueba a vivir siempre en verde. O en azul. O en morado. Y encima con la lengua afilada. A veces un cambio cosmético de imagen no basta y hacen falta medidas drásticas: ¡cambiar de raza por completo!'),
(97, 'esES', '|cffffd700Personalización|r', 'Todo fluye, todo cambia. Las personas, los peinados, los tipos de interés... Si estás harto del aspecto de tu personaje y no quieres ir por ahí con el yelmo y la visera bajada, este servicio te vendrá bien. ¡Ojalá fuera así en la vida real...! Puedes cambiar por completo el aspecto e incluso, si quieres, el sexo de tu personaje.'),
(98, 'esES', '|cffa335ee1000 puntos de honor|r', 'Te otorga 1000 puntos de honor'),
(99, 'esES', '|cffa335ee1000 puntos de justicia|r', 'Te otorga 1000 puntos de justicia'),
(103, 'esES', '|cff0070ddProle aterradora|r', 'Mascota promocional'),
(104, 'esES', '|cff0070ddSaco del goblin del tesoro|r', 'Mascota promocional'),
(105, 'esES', '|cff0070ddTalismán de plátano|r', 'Mascota promocional'),
(106, 'esES', '|cff0070ddHuevo de múrloc blanco|r', 'Mascota promocional'),
(107, 'esES', '|cff0070ddMoneda de la fortuna|r', 'Mascota promocional'),
(108, 'esES', '|cff0070ddCometa de dragón|r', 'Mascota promocional'),
(109, 'esES', '|cff0070ddHuevo múrloc naranja|r', 'Mascota promocional'),
(110, 'esES', '|cff0070ddPesteling|r', 'Mascota promocional'),
(111, 'esES', '|cff1eff00Huevo múrloc rosa|r', 'Mascota promocional'),
(112, 'esES', '|cff0070ddCachorro de jinete del viento|r', 'Mascota promocional'),
(113, 'esES', '|cffa335eeProle de hipogrifo|r', 'Mascota promocional'),
(114, 'esES', '|cff0070ddProle Cenarion|r', 'Mascota promocional'),
(115, 'esES', '|cff0070ddCachorro guardián|r', 'Mascota promocional'),
(116, 'esES', '|cff0070ddCachorro sable de la noche|r', 'Mascota promocional'),
(117, 'esES', '|cff0070ddCollera de panda|r', 'Mascota promocional'),
(118, 'esES', '|cffffffffVástago de Onyxia|r', 'Mascota promocional'),
(119, 'esES', '|cff0070ddMedallón de oro|r', 'Mascota promocional'),
(120, 'esES', '|cff0070ddRecuerdo de competidor|r', 'Mascota promocional'),
(121, 'esES', '|cff0070ddAlma de los Aspectos|r', 'Mascota promocional'),
(122, 'esES', '|cff0070ddCorrea Zergling|r', 'Mascota promocional'),
(123, 'esES', '|cff0070ddMoneda de cerdo de oro|r', 'Mascota promocional'),
(124, 'esES', '|cff0070ddMini thor|r', 'Mascota promocional'),
(125, 'esES', '|cffa335eeCometa colmillarr|r', 'Mascota promocional'),
(126, 'esES', '|cff0070ddPequeña Filacteria|r', 'Mascota promocional'),
(127, 'esES', '|cff0070ddCachorro de quilen de la suerte|r', 'Mascota promocional'),
(128, 'esES', '|cff0070ddPiedra de diablo|r', 'Mascota promocional'),
(129, 'esES', '|cff0070ddEmpuñadura de Tyrael|r', 'Mascota promocional'),
(130, 'esES', '|cff0070ddHuevo sin abrir de Birujillo|r', 'Mascota promocional'),
(131, 'esES', '|cff0070ddCollera de Carámbano|r', 'Mascota promocional'),
(132, 'esES', '|cff0070ddPequeña piedra de alma de Murky|r', 'Mascota promocional'),
(133, 'esES', '|cff0070ddMayal de Murkalot|r', 'Mascota promocional'),
(134, 'esES', '|cff0070ddMonje pandaren|r', 'Mascota promocional'),
(135, 'esES', '|cff0070ddGrimorio de ráfaga|r', 'Mascota promocional'),
(136, 'esES', '|cff0070ddHuevo de múrloc pesado|r', 'Mascota promocional'),
(137, 'esES', '|cff0070ddCachorro de tigre espectral|r', 'Mascota promocional'),
(138, 'esES', '|cff0070ddMini Ragnaros|r', 'Mascota promocional'),
(139, 'esES', '|cff0070ddMini XT|r', 'Mascota promocional'),
(140, 'esES', '|cff0070ddHuevo de múrloc humeante|r', 'Mascota promocional'),
(141, 'esES', '|cff0070ddMini Alamuerte|r', 'Mascota promocional'),
(142, 'esES', '|cff0070ddLanza de fetiche chamán|r', 'Mascota promocional'),
(143, 'esES', '|cff0070ddAnciano floreciente|r', 'Mascota promocional'),
(144, 'esES', '|cff0070ddTe enseña a invocar este compañero.|r', 'Mascota promocional'),
(145, 'esES', '|cff0070ddCachorro de can del Núcleo|r', 'Mascota promocional'),
(146, 'esES', '|cff0070ddBaliza de comerciante de almas|r', 'Mascota promocional'),
(147, 'esES', '|cffffffffCollera de oso polar|r', 'Mascota promocional'),
(148, 'esES', '|cff0070ddGallina cohete|r', 'Mascota promocional'),
(149, 'esES', '|cff0070ddMoneda de cerdo de plata|r', 'Mascota promocional'),
(150, 'esES', '|cff0070ddPez globo morado|r', 'Mascota promocional'),
(151, 'esES', '|cffa335eeHipogrifo esmeralda|r', 'Montura voladora'),
(152, 'esES', '|cffa335eeCorazón de alanoche|r', 'Montura voladora'),
(153, 'esES', '|cffa335eePegaso|r', 'Montura voladora'),
(154, 'esES', '|cffa335eeRiendas de cuervo aterrador|r', 'Montura voladora'),
(155, 'esES', '|cffa335eeDestrero de Tyrael|r', 'Montura voladora'),
(156, 'esES', '|cffa335eeAlasangre acorazado|r', 'Montura voladora'),
(157, 'esES', '|cffa335eeCorazón de los Aspectos|r', 'Montura voladora'),
(158, 'esES', '|cffa335eeAtracacielos férreo|r', 'Montura voladora'),
(159, 'esES', '|cffa335eeGuardián alado|r', 'Montura voladora'),
(160, 'esES', '|cffa335eeRiendas del tigre espectral presto|r', 'Montura terrestre'),
(161, 'esES', '|cffa335eeTormento de guerra|r', 'Montura voladora'),
(162, 'esES', '|cffa335eeHuevo de gallo mágico|r', 'Montura terrestre'),
(163, 'esES', '|cffa335eeZhebra presta OLD|r', 'Montura terrestre'),
(164, 'esES', '|cffa335eeRiendas del fénix oscuro|r', 'Montura voladora'),
(165, 'esES', '|cffa335eeAsaltante sonriente|r', 'Montura voladora'),
(166, 'esES', '|cffa335eeCuervo tormentoso|r', 'Montura voladora'),
(167, 'esES', '|cffa335eeCorcel celestial|r', 'Montura voladora');

DELETE FROM `battle_pay_product_locale` WHERE `Locale` = 'esES' AND `ID` IN (7,8,9,10,11,12,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167);
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES
(7, 'esES', 'Tienda:
1.000 de oro', 'Te otorga 1.000 de oro.'),
(8, 'esES', 'Tienda:
5.000 de oro', 'Te otorga 5.000 de oro.'),
(9, 'esES', 'Tienda:
10.000 de oro', 'Te otorga 10.000 de oro.'),
(10, 'esES', 'Tienda:
30.000 de oro', 'Te otorga 30.000 de oro.'),
(11, 'esES', 'Tienda:
80.000 de oro', 'Te otorga 80.000 de oro.'),
(12, 'esES', 'Tienda:
150.000 de oro', 'Te otorga 150.000 de oro.'),
(31, 'esES', 'Tienda:
Brida de semental blanco', 'Montura terrestre'),
(32, 'esES', 'Tienda:
Carnero de escarcha', 'Montura terrestre'),
(33, 'esES', 'Tienda:
Carnero negro', 'Montura terrestre'),
(34, 'esES', 'Tienda:
Cuerno del lobo ártico', 'Montura terrestre'),
(35, 'esES', 'Tienda:
Cuerno del lobo rojo', 'Montura terrestre'),
(36, 'esES', 'Tienda:
Kodo azulado', 'Montura terrestre'),
(37, 'esES', 'Tienda:
Kodo verde', 'Montura terrestre'),
(38, 'esES', 'Tienda:
Mecazancudo azul hielo modelo A', 'Montura terrestre'),
(39, 'esES', 'Tienda:
Mecazancudo blanco modelo B', 'Montura terrestre'),
(40, 'esES', 'Tienda:
Riendas del sable de hielo anciano', 'Montura terrestre'),
(41, 'esES', 'Tienda:
Riendas del sable de la noche', 'Montura terrestre'),
(42, 'esES', 'Tienda:
Silbato del raptor marfil', 'Montura terrestre'),
(43, 'esES', 'Tienda:
Silbato del raptor rojo jaspeado', 'Montura terrestre'),
(44, 'esES', 'Tienda:
Riendas de protodraco herrumbroso', 'Montura voladora'),
(45, 'esES', 'Tienda:
Riendas de protodraco vinculahierro', 'Montura voladora'),
(46, 'esES', 'Tienda:
Riendas de vencedor Razaescarcha bañado en sangre', 'Montura voladora'),
(47, 'esES', 'Tienda:
Riendas del draco azul', 'Montura voladora'),
(48, 'esES', 'Tienda:
Riendas del vencedor Razaescarcha vinculado al hielo', 'Montura voladora'),
(49, 'esES', 'Tienda:
Riendas del draco de piedra volcánico', 'Montura voladora'),
(50, 'esES', 'Tienda:
Riendas del draco del Viento del Este', 'Montura voladora'),
(51, 'esES', 'Tienda:
Riendas del draco del Viento del Norte', 'Montura voladora'),
(52, 'esES', 'Tienda:
Riendas del draco de piedra fosforescente', 'Montura voladora'),
(53, 'esES', 'Tienda:
Riendas del draco de piedra vítreo', 'Montura voladora'),
(54, 'esES', 'Tienda:
Riendas del presagista Crepuscular', 'Montura voladora'),
(55, 'esES', 'Tienda:
Halcón zancudo blanco presto', 'Montura terrestre'),
(56, 'esES', 'Tienda:
Riendas del Lord Cuervo', 'Montura terrestre'),
(57, 'esES', 'Tienda:
Riendas del protodraco apestado', 'Montura voladora'),
(58, 'esES', 'Tienda:
Riendas del protodraco azul', 'Montura voladora'),
(59, 'esES', 'Tienda:
Riendas del protodraco negro', 'Montura voladora'),
(60, 'esES', 'Tienda:
Riendas del protodraco rojo', 'Montura voladora'),
(61, 'esES', 'Tienda:
Huevo de Millagazor corrupto', 'Montura voladora'),
(62, 'esES', 'Tienda:
Pantera Zulian presta', 'Montura terrestre'),
(63, 'esES', 'Tienda:
Raptor fosilizado', 'Montura terrestre'),
(64, 'esES', 'Tienda:
Raptor Razzashi acorazado', 'Montura terrestre'),
(65, 'esES', 'Tienda:
Riendas del draco Ala Abisal azur', 'Montura voladora'),
(66, 'esES', 'Tienda:
Riendas del draco Ala Abisal cobalto', 'Montura voladora'),
(67, 'esES', 'Tienda:
Riendas del draco Ala Abisal morado', 'Montura voladora'),
(68, 'esES', 'Tienda:
Riendas del draco Ala Abisal ónice', 'Montura voladora'),
(69, 'esES', 'Tienda:
Riendas del draco Ala Abisal veridiano', 'Montura voladora'),
(70, 'esES', 'Tienda:
Riendas del draco Ala Abisal violeta', 'Montura voladora'),
(71, 'esES', 'Tienda:
Riendas de destrero de la muerte', 'Montura terrestre'),
(72, 'esES', 'Tienda:
Riendas del talbuk de guerra oscuro', 'Montura terrestre'),
(73, 'esES', 'Tienda:
Riendas del talbuk de montar oscuro', 'Montura terrestre'),
(74, 'esES', 'Tienda:
Oso de batalla Amani', 'Montura terrestre'),
(75, 'esES', 'Tienda:
Riendas del draco bronce', 'Montura voladora'),
(76, 'esES', 'Tienda:
Riendas del protodraco Tiempo Perdido', 'Montura voladora'),
(77, 'esES', 'Tienda:
Riendas del protodraco verde', 'Montura voladora'),
(78, 'esES', 'Tienda:
Vial de las arenas', 'Montura voladora'),
(79, 'esES', 'Tienda:
Chopper de mekigeniero', 'Montura terrestre'),
(80, 'esES', 'Tienda:
Meca-jarly', 'Montura terrestre'),
(81, 'esES', 'Tienda:
Riendas del oso polar blanco', 'Montura terrestre'),
(82, 'esES', 'Tienda:
Silbato del ravasaurio Pellejo Venenoso', 'Montura terrestre'),
(83, 'esES', 'Martin Furia', 'Posibilidad de «promocionar» tu personaje.'),
(84, 'esES', 'Tienda:
Brida de Palomino', 'Montura terrestre'),
(85, 'esES', 'Tienda:
Dragón hada encantado', 'Montura voladora'),
(86, 'esES', 'Tienda:
Quilen imperial', 'Montura voladora'),
(87, 'esES', 'Tienda:
Corcel del viento presto', 'Montura voladora'),
(88, 'esES', 'Tienda:
Raptor Razzashi presto', 'Montura terrestre'),
(89, 'esES', 'Tienda:
Rinoceronte blanco lanudo', 'Montura terrestre'),
(90, 'esES', 'Tienda:
Cohete de paseo X-53', 'Montura voladora'),
(91, 'esES', 'Tienda:
Mejora de profesión', 'Permite subir cualquiera de tus profesiones hasta 600.'),
(92, 'esES', 'Tienda:
Mejora menor de profesión', 'Permite subir cualquiera de tus profesiones al máximo disponible (75, 150, 225, 300, 375, 450, 525 o 600 puntos).'),
(93, 'esES', 'Tienda:
Subida a nivel 90', 'Sube al personaje al nivel 90 de forma instantánea.'),
(94, 'esES', 'Tienda:
Cambio de nombre', 'Permite cambiar el nombre del personaje.'),
(95, 'esES', 'Tienda:
Cambio de facción', 'Permite cambiar la facción del personaje.'),
(96, 'esES', 'Tienda:
Cambio de raza', 'Permite cambiar la raza del personaje.'),
(97, 'esES', 'Tienda:
Personalización', 'Permite cambiar el aspecto del personaje.'),
(98, 'esES', 'Tienda:
1000 puntos de honor', 'Te otorga 1000 puntos de honor'),
(99, 'esES', 'Tienda:
1000 puntos de justicia', 'Te otorga 1000 puntos de justicia'),
(100, 'esES', 'Tienda:
1000 puntos de valor', 'Te otorga 1000 puntos de valor'),
(101, 'esES', 'Tienda:
1000 puntos de conquista', 'Te otorga 1000 puntos de conquista'),
(102, 'esES', 'Tienda:
Elixir de conocimiento antiguo', 'Se oye un leve susurro proveniente de la botella.'),
(103, 'esES', 'Tienda:
Prole aterradora', 'Mascota promocional'),
(104, 'esES', 'Tienda:
Saco del goblin del tesoro', 'Mascota promocional'),
(105, 'esES', 'Tienda:
Talismán de plátano', 'Mascota promocional'),
(106, 'esES', 'Tienda:
Huevo de múrloc blanco', 'Mascota promocional'),
(107, 'esES', 'Tienda:
Moneda de la fortuna', 'Mascota promocional'),
(108, 'esES', 'Tienda:
Cometa de dragón', 'Mascota promocional'),
(109, 'esES', 'Tienda:
Huevo múrloc naranja', 'Mascota promocional'),
(110, 'esES', 'Tienda:
Pesteling', 'Mascota promocional'),
(111, 'esES', 'Tienda:
Huevo múrloc rosa', 'Mascota promocional'),
(112, 'esES', 'Tienda:
Cachorro de jinete del viento', 'Mascota promocional'),
(113, 'esES', 'Tienda:
Prole de hipogrifo', 'Mascota promocional'),
(114, 'esES', 'Tienda:
Prole Cenarion', 'Mascota promocional'),
(115, 'esES', 'Tienda:
Cachorro guardián', 'Mascota promocional'),
(116, 'esES', 'Tienda:
Cachorro sable de la noche', 'Mascota promocional'),
(117, 'esES', 'Tienda:
Collera de panda', 'Mascota promocional'),
(118, 'esES', 'Tienda:
Vástago de Onyxia', 'Mascota promocional'),
(119, 'esES', 'Tienda:
Medallón de oro', 'Mascota promocional'),
(120, 'esES', 'Tienda:
Recuerdo de competidor', 'Mascota promocional'),
(121, 'esES', 'Tienda:
Alma de los Aspectos', 'Mascota promocional'),
(122, 'esES', 'Tienda:
Correa Zergling', 'Mascota promocional'),
(123, 'esES', 'Tienda:
Moneda de cerdo de oro', 'Mascota promocional'),
(124, 'esES', 'Tienda:
Mini thor', 'Mascota promocional'),
(125, 'esES', 'Tienda:
Cometa colmillarr', 'Mascota promocional'),
(126, 'esES', 'Tienda:
Pequeña Filacteria', 'Mascota promocional'),
(127, 'esES', 'Tienda:
Cachorro de quilen de la suerte', 'Mascota promocional'),
(128, 'esES', 'Tienda:
Piedra de diablo', 'Mascota promocional'),
(129, 'esES', 'Tienda:
Empuñadura de Tyrael', 'Mascota promocional'),
(130, 'esES', 'Tienda:
Huevo sin abrir de Birujillo', 'Mascota promocional'),
(131, 'esES', 'Tienda:
Collera de Carámbano', 'Mascota promocional'),
(132, 'esES', 'Tienda:
Pequeña piedra de alma de Murky', 'Mascota promocional'),
(133, 'esES', 'Tienda:
Mayal de Murkalot', 'Mascota promocional'),
(134, 'esES', 'Tienda:
Monje pandaren', 'Mascota promocional'),
(135, 'esES', 'Tienda:
Grimorio de ráfaga', 'Mascota promocional'),
(136, 'esES', 'Tienda:
Huevo de múrloc pesado', 'Mascota promocional'),
(137, 'esES', 'Tienda:
Cachorro de tigre espectral', 'Mascota promocional'),
(138, 'esES', 'Tienda:
Mini Ragnaros', 'Mascota promocional'),
(139, 'esES', 'Tienda:
Mini XT', 'Mascota promocional'),
(140, 'esES', 'Tienda:
Huevo de múrloc humeante', 'Mascota promocional'),
(141, 'esES', 'Tienda:
Mini Alamuerte', 'Mascota promocional'),
(142, 'esES', 'Tienda:
Lanza de fetiche chamán', 'Mascota promocional'),
(143, 'esES', 'Tienda:
Anciano floreciente', 'Mascota promocional'),
(144, 'esES', 'Tienda:
Te enseña a invocar este compañero.', 'Mascota promocional'),
(145, 'esES', 'Tienda:
Cachorro de can del Núcleo', 'Mascota promocional'),
(146, 'esES', 'Tienda:
Baliza de comerciante de almas', 'Mascota promocional'),
(147, 'esES', 'Tienda:
Collera de oso polar', 'Mascota promocional'),
(148, 'esES', 'Tienda:
Gallina cohete', 'Mascota promocional'),
(149, 'esES', 'Tienda:
Moneda de cerdo de plata', 'Mascota promocional'),
(150, 'esES', 'Tienda:
Pez globo morado', 'Mascota promocional'),
(151, 'esES', 'Tienda:
Hipogrifo esmeralda', 'Montura voladora'),
(152, 'esES', 'Tienda:
Corazón de alanoche', 'Montura voladora'),
(153, 'esES', 'Tienda:
Pegaso', 'Montura voladora'),
(154, 'esES', 'Tienda:
Riendas de cuervo aterrador', 'Montura voladora'),
(155, 'esES', 'Tienda:
Destrero de Tyrael', 'Montura voladora'),
(156, 'esES', 'Tienda:
Alasangre acorazado', 'Montura voladora'),
(157, 'esES', 'Tienda:
Corazón de los Aspectos', 'Montura voladora'),
(158, 'esES', 'Tienda:
Atracacielos férreo', 'Montura voladora'),
(159, 'esES', 'Tienda:
Guardián alado', 'Montura voladora'),
(160, 'esES', 'Tienda:
Riendas del tigre espectral presto', 'Montura terrestre'),
(161, 'esES', 'Tienda:
Tormento de guerra', 'Montura voladora'),
(162, 'esES', 'Tienda:
Huevo de gallo mágico', 'Montura terrestre'),
(163, 'esES', 'Tienda:
Zhebra presta OLD', 'Montura terrestre'),
(164, 'esES', 'Tienda:
Riendas del fénix oscuro', 'Montura voladora'),
(165, 'esES', 'Tienda:
Asaltante sonriente', 'Montura voladora'),
(166, 'esES', 'Tienda:
Cuervo tormentoso', 'Montura voladora'),
(167, 'esES', 'Tienda:
Corcel celestial', 'Montura voladora');
