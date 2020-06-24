#!/bin/bash

pushd scripts/docker_build
./run_docker_in_scripts.sh  /bin/bash ./build.sh
popd