#!/bin/bash

if [ -z "$1" ]; then
    echo  "[ERROR]: Missing service id argument"
    exit -1
else
    if [ "$1" == "bash" ]; then
	exec "/bin/bash"
    fi

    SERVICE_ID=$1
    echo "Running service '${SERVICE_ID}'"
fi

# start requested service
cd $SERVICE_ID && ./$SERVICE_ID