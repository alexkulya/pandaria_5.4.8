DELETE FROM `conditions`
WHERE `SourceTypeOrReferenceId` = 13
  AND `SourceGroup` = 1
  AND `SourceEntry` IN (77782, 77925, 77932, 77937, 86911, 87517, 92831, 96931, 119841, 139848);
