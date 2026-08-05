#!/bin/bash
set -euo pipefail

export MYSQL_PWD="${MYSQL_ROOT_PASSWORD}"

apply_dir() {
  local db="$1"
  local dir="$2"
  [ -d "$dir" ] || return 0
  find "$dir" -maxdepth 2 -name '*.sql' -print0 2>/dev/null | sort -z | while IFS= read -r -d '' f; do
    echo ">>> [initdb] ${db} < $(basename "$f")"
    mysql -uroot "$db" < "$f"
  done
}

apply_dir world      /sql/updates/world
apply_dir auth       /sql/updates/auth
apply_dir characters /sql/updates/characters

echo ">>> [initdb] updates applied"
