# syntax=docker/dockerfile:1
#
# Pandaria 5.4.8 - build & runtime image (Linux)
# Ubuntu 20.04 provides the toolchain this codebase was written for:
#   cmake 3.16, gcc 9, OpenSSL 1.1.1, Boost 1.71, libace 6.4.5, MySQL client 8.0.19

FROM ubuntu:20.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential cmake \
        libace-dev libssl-dev libmysqlclient-dev \
        libreadline-dev libncurses-dev \
        zlib1g-dev libbz2-dev \
        libboost-system-dev libboost-locale-dev libboost-filesystem-dev \
        libboost-thread-dev libboost-regex-dev libboost-serialization-dev \
        libboost-date-time-dev \
    && rm -rf /var/lib/apt/lists/*

COPY . /src

ARG BUILD_JOBS=8

# The /build directory is a BuildKit cache mount: it persists between builds so
# that iterating on a source fix only recompiles the affected targets instead of
# the whole tree (~70 min). Drop stale MySQL cache entries left over from previous
# configure runs so find_package(MySQL) resolves the real library path.
RUN --mount=type=cache,target=/build \
    sed -i '/^MYSQL_LIBRARY/d;/^MYSQL_INCLUDE_DIR/d;/^$/d' /build/CMakeCache.txt 2>/dev/null || true; \
    cmake -S /src -B /build \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/app \
        -DBUILD_DEPLOY=0 \
        -DSCRIPTS=1 \
        -DTOOLS=1 \
        -DNOJEM=1 \
        -DUSE_COREPCH=1 \
        -DUSE_SCRIPTPCH=1 \
    && cmake --build /build --target install --parallel ${BUILD_JOBS}

FROM ubuntu:20.04 AS runtime

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
        libace-6.4.5 libssl1.1 libmysqlclient21 \
        libreadline8 libncurses6 libbz2-1.0 zlib1g \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /app /app
COPY docker/entrypoint.sh /usr/local/bin/docker-entrypoint.sh
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

WORKDIR /app
ENTRYPOINT ["docker-entrypoint.sh"]
CMD ["bash", "-c", "bin/worldserver --help || true"]
