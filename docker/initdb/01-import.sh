#!/bin/bash
set -euo pipefail

export MYSQL_PWD="${MYSQL_ROOT_PASSWORD}"

shopt -s nullglob
for f in /sql/base/*.sql; do
  echo ">>> [initdb] importing $(basename "$f")"
  mysql -uroot < "$f"
done

echo ">>> [initdb] base databases imported"
