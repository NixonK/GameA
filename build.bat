:: Clear old build files and setup new build directory.
rd /s /q %~dp0\build
mkdir %~dp0\build || exit /b 1
cd %~dp0\build || exit /b 1

set "SDL2_LIB="
for /d /r "%~dp0" %%i in (SDL2-*) do (
	set "SDL2_LIB=%%~i"
)
if [%SDL2_LIB%] == [] (
	echo Missing SDL2 library.
	exit /b 1
)

set "SDL2image_LIB="
for /d /r "%~dp0" %%i in (SDL2_image-*) do (
	set "SDL2image_LIB=%%~i"
)
if [%SDL2image_LIB%] == [] (
	echo Missing SDL2image library.
	exit /b 1
)

cmake -G "Visual Studio 14 2015 Win64" %~dp0 -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="%SDL2_LIB%;%SDL2image_LIB%" || exit /b 1
cmake --build %~dp0\build --config Release || exit /b 1

cd %~dp0\build\Release && start GameAExecutable.exe || exit /b 1
