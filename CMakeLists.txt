cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

project( GameA )

# prohibit in-source builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
	message(FATAL_ERROR "In-source builds are not allowed, use a separate build directory.")
endif()

set( GAMEA_SRC
	 GameAClean/game.cpp
	 GameAClean/key_handler.cpp
	 GameAClean/main.cpp
	 GameAClean/player.cpp
	 GameAClean/user_interface.cpp )

set( GAMEA_HEADERS
	 GameAClean/game.h
	 GameAClean/includes.h
	 GameAClean/key_handler.h
	 GameAClean/player.h
	 GameAClean/user_interface.h )

add_library( GameA ${GAMEA_SRC} ${GAMEA_HEADERS} )

target_include_directories( GameA PUBLIC ./GameAClean/ )
target_include_directories( GameA PUBLIC ./SDL/include/
										 ./SDL2_image-2.0.0/include/ )

add_executable( GameAExecutable ${GAMEA_SRC} )
target_link_libraries( GameAExecutable GameA
									   ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/win32/SDL2.lib
									   ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/win32/SDL2main.lib
									   ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image-2.0.0/lib/x86/SDL2_image.lib )

