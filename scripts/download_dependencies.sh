#!/bin/bash
pushd ../
    if [ ! -f "tools/poryscript/poryscript" ]; then
        mkdir temp
        cd temp
        wget https://github.com/huderlem/poryscript/releases/download/2.8.1/poryscript-linux.zip
        unzip poryscript-linux.zip
        cp poryscript-linux/poryscript ../tools/poryscript/poryscript
        cd ../
        rm -rf temp
    fi
popd