#!/bin/bash

if [ -z "$1" ]; then
    echo  "Building services"
    exit 0
else
    SERVICE_ID=$1
    echo "Running service '${SERVICE_ID}'"
fi

# start requested service
cd $SERVICE_ID && ./$SERVICE_ID