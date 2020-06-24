#!/bin/bash

./init_dev_environment.sh
pushd ../
    make modern -j8
popd