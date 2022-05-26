@ECHO OFF
REM Variables relevant to the compilation of the program.
SET CXX=g++
SET CPPOBJS=src/main.cpp src/spill.cpp
SET EDCXXFLAGS=-I ./ -I ./include/ -Wall -std=gnu++17
SET EDLDFLAGS=-lstdc++fs -static-libgcc -static-libstdc++
SET TARGET=spill.exe

REM This runs a command-prompt command to compile using G++.
ECHO ON
CMD /c "%CXX% %EDCXXFLAGS% %CPPOBJS% -o %TARGET% %EDLDFLAGS%"
@ECHO OFF

REM This will run the executable automatically.
@REM START %TARGET%