#!/bin/bash
docker-compose \
    -f docker/docker-compose/config.yml \
    -f docker/docker-compose/backend.yml \
    -f docker/docker-compose/frontend.yml \
    -f docker/docker-compose/observability.yml \
    $@