rd /s /q %~dp0\build
mkdir %~dp0\build || exit /b 1
cd %~dp0\build || exit /b 1

cmake -G "Visual Studio 14 2015 Win64" %~dp0 -DCMAKE_BUILD_TYPE=Release || exit /b 1
cmake --build %~dp0\build --config Release || exit /b 1

cd %~dp0\build\Release && start GameAExecutable.exe || exit /b 1
