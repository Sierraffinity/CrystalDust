#!/bin/bash

docker build -t crystal-dust-build . || {
    echo "Failed to build container, see console for details."
    exit -1
}

pushd ../../
    echo docker run -it --rm -v $PWD:/source -w /source/scripts crystal-dust-build $@
popd