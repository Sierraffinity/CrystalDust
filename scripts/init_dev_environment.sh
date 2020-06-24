#!/bin/bash

./download_dependencies.sh
pushd ../
    # Initialize agbcc if it doesn't exist
    if [ ! -d "../agbcc" ]; then
        echo "agbcc does not exist, initializing..."
        git clone https://github.com/pret/agbcc.git --depth 1 ../agbcc
        pushd ../agbcc
            ./build.sh || {
                echo Failed to build agbcc...
                cd ../
                rm -rf agbcc
                exit
            }
        popd
    fi

    # Install agbcc if it does not exist
    if [ ! -f "./tools/agbcc/bin/agbcc" ]; then
        echo Installing agbcc...
        cwd=$(pwd)
        pushd ../agbcc
            ./install.sh $cwd
        popd
    fi

    make tools
popd