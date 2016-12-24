# Find SDL2image
#
# This sets the following variables:
# SDL2image_FOUND - True if SDL2image (includes and library) is found.
# SDL2image_INCLUDE_DIR  - Directories containing the SDL2image include files.
# SDL2image_INCLUDE_DIRS
# SDL2image_LIBRARY      - Directories containing the SDL2image library.
# SDL2image_LIBRARIES

find_path(SDL2image_INCLUDE_DIR SDL_image.h)
message("SDL2image_INCLUDE_DIR is ${SDL2image_INCLUDE_DIR}")

find_library(SDL2image_LIBRARY NAMES SDL2_image
             PATH_SUFFIXES "${ARCHITECTURE}")
message("SDL2image_LIBRARY is ${SDL2image_LIBRARY}")

set(SDL2image_INCLUDE_DIRS ${SDL2image_INCLUDE_DIR})
set(SDL2image_LIBRARIES ${SDL2image_LIBRARY})



# Required DLL's:
set(SDL2image_DLL_FILE "SDL2_image.dll")
find_path(SDL2image_DLL ${SDL2image_DLL_FILE}
          PATH_SUFFIXES "lib/${ARCHITECTURE}")
message("SDL2image_DLL is ${SDL2image_DLL}")

set(PNG_DLL_FILE "libpng16-16.dll")
find_path(PNG_DLL ${PNG_DLL_FILE}
          PATH_SUFFIXES "lib/${ARCHITECTURE}")
message("PNG_DLL is ${PNG_DLL}")

set(ZLIB_DLL_FILE "zlib1.dll")
find_path(ZLIB_DLL ${ZLIB_DLL_FILE}
          PATH_SUFFIXES "lib/${ARCHITECTURE}")
message("ZLIB_DLL is ${ZLIB_DLL}")

set(SDL2image_DLLS ${SDL2image_DLL}/${SDL2image_DLL_FILE} ${PNG_DLL}/${PNG_DLL_FILE} ${ZLIB_DLL}/zlib1.dll )



include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2image DEFAULT_MSG SDL2image_LIBRARY SDL2image_INCLUDE_DIR
                                  SDL2image_DLL PNG_DLL ZLIB_DLL)

mark_as_advanced(SDL2image_LIBRARIES SDL2image_INCLUDE_DIRS SDL2image_DLLS)
