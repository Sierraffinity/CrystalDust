#!/bin/bash

for file in $(tools/scaninc/scaninc -I include $1); do
  if ! [ -f "${file}" ]; then
    make "${file}" || echo ${file}
  fi
done
