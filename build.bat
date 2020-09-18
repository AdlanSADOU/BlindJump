@echo off
:: MVSC++ Compiler options list: https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=vs-2019
:: VS : set the path to your Visual Studio installation. needed to setup environment varibles to be able to compile with mvsc++

REM SET VS=C:\Program Files (x86)\Microsoft Visual Studio\2017
REM CALL "%VS%\Community\VC\Auxiliary\Build\vcvars64.bat"

REM /Qpar	Enables automatic parallelization of loops.
REM /RTC	Enables run-time error checking.

:: Set release or debug mode
SET COMPILE_MODE=debug

SET SRC=..\src\*.c ..\src\init\*.c ..\src\pathfinding\*.c ..\src\utils\*.c

SET INC=/I..\include /I..\vendor\CSFML\x64\include

SET LIBPATH=/LIBPATH:"..\vendor\CSFML\x64\lib\msvc\"
SET LIBS=csfml-window.lib csfml-graphics.lib csfml-audio.lib csfml-system.lib

IF "%COMPILE_MODE%"=="release" (
    SET CFLAGS= /MT /FC /MP /TC /nologo
    SET NAME=/Fe"release\BlindJump.exe"
)

IF "%COMPILE_MODE%"=="debug" (
    SET CFLAGS= /Zi /MTd /FC /MP /TC /nologo
    SET NAME=/Fe"debug\BlindJump.exe"
)

SET LINK_OPTS= /link %LIBPATH% /SUBSYSTEM:CONSOLE

mkdir build
pushd build

cl.exe %NAME% %CFLAGS% %INC% %SRC% %LINK_OPTS% %LIBS%

popd build