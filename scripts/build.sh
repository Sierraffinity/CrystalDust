#!/bin/bash

echo Initializing development environment...
./init_dev_environment.sh

pushd ../
    echo Building...
    make modern -j8
popd