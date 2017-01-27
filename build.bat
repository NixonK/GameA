@echo on

REM SHOW_CONSOLE for executable option.
if ["%1"] == ["show_console"] (
	set "SHOW_CONSOLE=ON"
) else (
	set "SHOW_CONSOLE=OFF"
)

echo Option [show_console]: %SHOW_CONSOLE%

REM Clear old build files and setup new build directory.
if exist %~dp0\build rd /s /q %~dp0\build || exit /b 1
mkdir %~dp0\build || exit /b 1
cd %~dp0\build || exit /b 1

REM Check for SDL2 library directory.
set "SDL2_LIB="
for /d /r "%~dp0" %%i in (SDL2-*) do (
	set "SDL2_LIB=%%~i"
)
if [%SDL2_LIB%] == [] (
	echo Missing SDL2 library.
	exit /b 1
)
REM Check for SDL2image library directory.
set "SDL2image_LIB="
for /d /r "%~dp0" %%i in (SDL2_image-*) do (
	set "SDL2image_LIB=%%~i"
)
if [%SDL2image_LIB%] == [] (
	echo Missing SDL2image library.
	exit /b 1
)

REM Compile with CMake configuration.
cmake -G "Visual Studio 14 2015 Win64" ^
	-DCMAKE_BUILD_TYPE=Release ^
	-DCMAKE_CXX_FLAGS_RELEASE="%CMAKE_CXX_FLAGS_RELEASE% /MT" ^
	-DCMAKE_PREFIX_PATH="%SDL2_LIB%;%SDL2image_LIB%" ^
	-DSHOW_CONSOLE=%SHOW_CONSOLE% ^
	%~dp0 || exit /b 1
cmake --build %~dp0\build --config Release || exit /b 1

REM Run the resulting executable.
cd %~dp0\build\Release && start GameA.exe || exit /b 1
