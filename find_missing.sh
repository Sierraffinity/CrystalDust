#!/bin/bash

find_missing(){
    for fl in $(tools/scaninc/scaninc -I include -I "" $1); do
        if ! [ -f $fl ]; then echo $fl; else find_missing $fl; fi
    done
}

find_missing data/event_scripts.s
