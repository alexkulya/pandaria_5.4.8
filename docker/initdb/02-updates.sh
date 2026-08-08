#!/bin/bash
set -euo pipefail

export MYSQL_PWD="${MYSQL_ROOT_PASSWORD}"

FAILED="$(mktemp)"
trap 'rm -f "$FAILED"' EXIT

apply_dir() {
  local db="$1"
  local dir="$2"
  [ -d "$dir" ] || return 0
  # No -maxdepth: the world updates nest three levels deep
  # (updates/world/localization/ruRU/*.sql) and were being silently skipped.
  find "$dir" -name '*.sql' -print0 2>/dev/null | sort -z | while IFS= read -r -d '' f; do
    echo ">>> [initdb] ${db} < ${f#/sql/updates/}"
    # A single stale file must not abort the whole import and leave the
    # database half-populated, but it must not pass unnoticed either: record
    # it and fail the script at the end.
    if ! mysql -uroot "$db" < "$f"; then
      echo "!!! [initdb] FAILED: ${f#/sql/updates/}"
      echo "${f#/sql/updates/}" >> "$FAILED"
    fi
  done
}

apply_dir world      /sql/updates/world
apply_dir auth       /sql/updates/auth
apply_dir characters /sql/updates/characters

if [ -s "$FAILED" ]; then
  echo ">>> [initdb] updates applied, but these files FAILED:"
  sed 's/^/      /' "$FAILED"
  exit 1
fi

echo ">>> [initdb] updates applied"
