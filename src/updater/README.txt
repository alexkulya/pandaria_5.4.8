1. Собрать

Linux:
cmake ... -DUPDATER=1
make
make install

Копируем bin/updater etc/updater.conf.dist куда надо

cmake ... -DUPDATER=0

Windows:
cmake ... -DUPDATER=1 или выставляем в GUI
Solution explorer -> updater -> ПКМ -> Build

Копируем updater.exe updater.conf.dist ace.dll libmysql.dll куда надо

cmake ... -DUPDATER=0 или выставляем в GUI

2. Переименовать updater.conf.dist в updater.conf и настроить
3. Копировать таблицу sql_update вместе с данными с лайв сервера (структура так же есть в sql_update.sql) 
4. Есил realmid отличается от используемого локально - надо обновить его в локальной базе, так же можно дропнуть записи с ненужным realmid
5. PROFIT!!!
