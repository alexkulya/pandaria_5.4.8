#!/bin/bash
set -euo pipefail

export MYSQL_PWD="${MYSQL_ROOT_PASSWORD}"

mysql -uroot <<'SQL'
CREATE USER IF NOT EXISTS 'pandaria'@'%' IDENTIFIED WITH mysql_native_password BY 'pandaria';
GRANT ALL PRIVILEGES ON auth.*      TO 'pandaria'@'%';
GRANT ALL PRIVILEGES ON characters.* TO 'pandaria'@'%';
GRANT ALL PRIVILEGES ON world.*      TO 'pandaria'@'%';
FLUSH PRIVILEGES;
SQL

echo ">>> [initdb] application user 'pandaria' created"
