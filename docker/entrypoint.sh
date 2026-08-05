#!/bin/bash
set -euo pipefail

ETC=/app/etc

gen_conf() {
  local src="$1" dst="$2"
  if [ ! -f "$dst" ]; then
    echo ">>> generating $(basename "$dst") from $(basename "$src")"
    sed -e 's/127\.0\.0\.1;3306;root;root;/db;3306;pandaria;pandaria;/g' "$src" > "$dst"
  else
    echo ">>> keeping existing $(basename "$dst")"
  fi
}

gen_conf "$ETC/authserver.conf.dist"  "$ETC/authserver.conf"
gen_conf "$ETC/worldserver.conf.dist" "$ETC/worldserver.conf"

exec "$@"
