# Find SDL2
#
# This sets the following variables:
# SDL2_FOUND - True if SDL2 (includes and library) is found.
# SDL2_INCLUDE_DIR  - Directories containing the SDL2 include files.
# SDL2_INCLUDE_DIRS
# SDL2_LIBRARY      - Directories containing the SDL2 library.
# SDL2_LIBRARIES

find_path(SDL2_INCLUDE_DIR SDL.h)
message("SDL2_INCLUDE_DIR is ${SDL2_INCLUDE_DIR}")

find_library(SDL2_LIBRARY NAMES SDL2
             PATH_SUFFIXES "${ARCHITECTURE}")
message("SDL2_LIBRARY is ${SDL2_LIBRARY}")

find_library(SDL2main_LIBRARY NAMES SDL2main
             PATH_SUFFIXES "${ARCHITECTURE}")
message("SDL2main_LIBRARY is ${SDL2main_LIBRARY}")


set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
set(SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2main_LIBRARY})

set(SD2_DLL_FILE "SDL2.dll")
find_path(SDL2_DLL ${SD2_DLL_FILE}
          PATH_SUFFIXES "lib/${ARCHITECTURE}")
message("SDL2_DLL is ${SDL2_DLL}")
set(SDL2_DLLS ${SDL2_DLL}/${SD2_DLL_FILE})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 DEFAULT_MSG SDL2_LIBRARY SDL2main_LIBRARY SDL2_INCLUDE_DIR SDL2_DLL)

mark_as_advanced(SDL2_LIBRARIES SDL2_INCLUDE_DIRS SDL2_DLLS)
