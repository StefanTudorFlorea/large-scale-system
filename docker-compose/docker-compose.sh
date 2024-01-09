#!/bin/bash
docker-compose \
    -f config.yml \
    -f backend.yml \
    -f frontend.yml \
    -f observability.yml \
    up --build