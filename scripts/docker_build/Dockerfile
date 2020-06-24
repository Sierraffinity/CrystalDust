FROM gcc:9.3.0

RUN mkdir /temp

ENV DEVKITPRO /opt/devkitPro
ENV DEVKITARM $DEVKITPRO/devkitARM
RUN mkdir $DEVKITPRO

WORKDIR /opt/devkitPro
RUN wget https://github.com/devkitPro/buildscripts/releases/download/devkitARM_r52/devkitARM_r52-linux.tar.xz
RUN tar xJf devkitARM*.tar.xz

RUN wget https://github.com/devkitPro/devkitarm-rules/releases/download/v1.0.0/devkitarm-rules-1.0.0.tar.xz
RUN tar xJf devkitarm-rules-*.tar.xz -C $DEVKITARM

RUN git clone https://github.com/pret/agbcc.git --depth 1 /agbcc
WORKDIR /agbcc
RUN ./build.sh

RUN mkdir /source
WORKDIR /source