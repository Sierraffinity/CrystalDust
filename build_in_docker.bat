@echo off

pushd scripts\docker_build
call run_docker_in_scripts.bat /bin/bash ./build.sh
popd