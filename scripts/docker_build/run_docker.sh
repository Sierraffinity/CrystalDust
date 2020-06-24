#!/bin/bash

docker build -t crystal-dust-build . || {
    echo "Failed to build container, see console for details."
    exit -1
}

pushd ../../
    docker run -it --rm -v $(pwd):/source crystal-dust-build
popd