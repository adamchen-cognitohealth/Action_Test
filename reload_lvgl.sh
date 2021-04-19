#!/bin/sh

make

cp liblvgl.so /usr/local/lib/
ldconfig

python3 build.py
python3 try_cffi.py
