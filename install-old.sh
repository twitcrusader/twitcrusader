#!/bin/bash

liboauth="liboauth-0.9.4.tar.gz"
link="http://downloads.sourceforge.net/project/liboauth/liboauth-0.9.4.tar.gz"
mkdir -p opensource
cd opensource
wget $link
tar xvvf $liboauth
cd liboauth-0.9.4
./configure
make
make install
cd ../../src
gcc -Wall -lssl -loauth -o twc twc.c oauth.c credits.c update_status.c other.c setting.c statusbar.c `pkg-config --cflags --libs gtk+-2.0`
