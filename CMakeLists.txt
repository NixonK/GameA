cmake_minimum_required( VERSION 3.2 FATAL_ERROR )

project( GameA )

# prohibit in-source builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
	message(FATAL_ERROR "In-source builds are not allowed, use a separate build directory.")
endif()

set( GAMEA_SRC
	 src/game.cpp
	 src/key_handler.cpp
	 src/main.cpp
	 src/player.cpp
	 src/user_interface.cpp )

set( GAMEA_HEADERS
	 src/game.h
	 src/includes.h
	 src/key_handler.h
	 src/player.h
	 src/user_interface.h )

add_library( GameA ${GAMEA_SRC} ${GAMEA_HEADERS} )

target_include_directories( GameA PUBLIC ./src/ )
target_include_directories( GameA PUBLIC ./SDL/include/
										 ./SDL2_image-2.0.1/include/ )

add_executable( GameAExecutable ${GAMEA_SRC} )
target_link_libraries( GameAExecutable GameA
					   ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x64/SDL2.lib
					   ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x64/SDL2main.lib
					   ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image-2.0.1/lib/x64/SDL2_image.lib )

set( POST_BUILD_FILES
	 res/sprite.png
	 SDL/lib/x64/SDL2.dll
	 SDL2_image-2.0.1/lib/x64/SDL2_image.dll
	 SDL2_image-2.0.1/lib/x64/libpng16-16.dll
	 SDL2_image-2.0.1/lib/x64/zlib1.dll )

foreach( res ${POST_BUILD_FILES} )
	ADD_CUSTOM_COMMAND( TARGET GameA POST_BUILD
						COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_CURRENT_SOURCE_DIR}/${res}
						${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE} )
endforeach()
