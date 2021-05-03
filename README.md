#SetupTest
This repo is just to illustrate an issue I'm having as a newcomer to platformio.

####my end-goal:

I'm trying to set up my project with a library in the `Project/lib` foler which is intendend to provide an io wrapper for the particular framework that I'm using. I have a couple of development boards that I want to play around with and I'd like to be able to just call a generic `ledWrite` function for example, which would pick the correct implementation depending on the framework I'm using. Once I have this working, I'd like to set up the dir of my library within the `lib` dir as a sumbodule in git so that I can have it as a separate repo and use it in any project. 

####the issue:

Since I have so far two possible implementation files (.cpp) of my library, I'm trying to filter out the one that doesn't contain the correct implementation for the framework. I've been trying to use the `src_filter` for this in the environment definitions in the `platformio.ini` file but I'm having the problem that the compiler is still trying to compile it, so it seems the .cpp file is not really getting ignored. I'm aware that the path indicated for `src_filter` is relative to the `src_dir`, but this doesn't work so I've also tried tweaking the path there in many different ways. I am constantly getting the following error when it attempts to compile the wrong implementation since it can't find the header I'm importing there, which is intended only to be used when the other platform implementation is selected:

```
> Executing task in folder SetupTest: platformio run <

Processing teensy41 (platform: teensy; board: teensy41; framework: arduino)
-------------------------------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/teensy/teensy41.html
PLATFORM: Teensy (4.12.0) > Teensy 4.1
HARDWARE: IMXRT1062 600MHz, 512KB RAM, 7.75MB Flash
DEBUG: Current (jlink) External (jlink)
PACKAGES: 
 - framework-arduinoteensy 1.153.0 (1.53) 
 - toolchain-gccarmnoneeabi 1.50401.190816 (5.4.1)
LDF: Library Dependency Finder -> http://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 90 compatible libraries
Scanning dependencies...
Dependency Graph
|-- <io> 0.0.1
Building in release mode
Compiling .pio/build/teensy41/lib/io/src/fw-arduino-io.cpp.o
Compiling .pio/build/teensy41/src/main.cpp.o
Compiling .pio/build/teensy41/libdaa/io/fw-arduino-io.cpp.o
Compiling .pio/build/teensy41/libdaa/io/fw-stm32cube-io.cpp.o
lib/io/src/fw-stm32cube-io.cpp:2:27: fatal error: stm32f4xx_hal.h: No such file or directory

***********************************************************************
* Looking for stm32f4xx_hal.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:stm32f4xx_hal.h"
* Web  > https://platformio.org/lib/search?query=header:stm32f4xx_hal.h
*
***********************************************************************

compilation terminated.
*** [.pio/build/teensy41/libdaa/io/fw-stm32cube-io.cpp.o] Error 1
======================================================= [FAILED] Took 1.99 seconds =======================================================

Environment    Status    Duration
-------------  --------  ------------
teensy41       FAILED    00:00:01.994
================================================== 1 failed, 0 succeeded in 00:00:01.994 ==================================================
The terminal process "platformio 'run'" terminated with exit code: 1.

Terminal will be reused by tasks, press any key to close it.

```