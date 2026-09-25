DELETE FROM `conditions`
WHERE `SourceTypeOrReferenceId` = 1
  AND `SourceGroup` = 73666
  AND `SourceEntry` IN (-777, -738);
