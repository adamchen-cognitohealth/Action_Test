# Edge UI for Cognito 3.0

This program is a device UI for Cognito 3.0 box. It uses the following knowledge.

- C code
- LVGL (C liberary)
- Python
- python-cffi (Python liberary, a glue between C and Python)



## Prepare

1. Prepare a linux PC installed gcc and Python 3.7

2. Download this repository

3. Install python-cffi

   ```bash
   apt update
   apt install python3-dev libffi-dev
   pip3 install cffi
   ```

   

4. Run the start script, and it will show the display

   ```bash
   bash reload_lvgl.sh
   ```

## Development

### A. LVGL source code development

After modify LVGL code, run the following code.

1. Compile C code

   ```bash
   make clean
   make
   ```

   

2. Load LVGL

   ```bash
   cp liblvgl.so /usr/local/lib
   ldconfig
   ```

### B. LVGL application development

1. Modify cffi translation file  `build.py` 

2. Compile `build.py`

   ```bash
   python3 build.py
   ```

3. Modify application file `try_cffi.py`

4. Run application

   ```bash
   python3 try_cffi.py
   ```

### C. Hybrid development

1. Accroding to the file `./lvgl/src/my_lv.h`, finish it and `./lvgl/src/my_lv.c`.

2. Run the start script, and it will show the display

   ```bash
   bash reload_lvgl.sh
   ```

## 

## Troubleshoot

### A. While compile C code, error occurs:  `pyconfig.h: No such file or directory` .

- Analysis: The results is that the compiler cannot find the file.

- Solution:

  1. Find the path of `pyconfig.h`.

     ```bash
     find / -name pyconfig.h
     
     # /usr/include/python3.5m/pyconfig.h
     ```

  2. Modify `makefile`, and add this path to `include_path`.

     ```bash
     BINARY  := liblvgl
     OBJ_DIR := ./
     
     INCS := -I ./ -I/usr/include/python3.5m/   -I./lvgl/  -I./lvgl/src
     CFLAGS= -Wall -g  -std=c99
     ```

  3. Retry

     ```bash
     make clean
     make
     ```

     