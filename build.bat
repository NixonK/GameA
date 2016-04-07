rd /s /q build
mkdir build || exit /b 1
cd build || exit /b 1

cmake -G "Visual Studio 14 2015" .. || exit /b 1
cmake --build . --config Release || exit /b 1

copy ..\GameAClean\sprite.png .\Release\ || exit /b 1
copy ..\SDL\lib\win32\SDL2.dll .\Release\ || exit /b 1
copy ..\SDL2_image-2.0.0\lib\x86\SDL2_image.dll .\Release\ || exit /b 1
copy ..\SDL2_image-2.0.0\lib\x86\libpng16-16.dll .\Release\ || exit /b 1
copy ..\SDL2_image-2.0.0\lib\x86\zlib1.dll .\Release\ || exit /b 1

cd Release && start GameAExecutable.exe || exit /b 1
