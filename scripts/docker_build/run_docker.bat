@echo off

docker build -t crystal-dust-build .

IF %ERRORLEVEL% NEQ 0 (
    echo Failed to build container, see console for details.
    exit -1
)

pushd ..\..\
    docker run -it --rm -v %CD%\:/source crystal-dust-build
popd