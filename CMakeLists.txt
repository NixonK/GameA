cmake_minimum_required( VERSION 3.2 FATAL_ERROR )

project( GameA )

# prohibit in-source builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
	message(FATAL_ERROR "In-source builds are not allowed, use a separate build directory.")
endif()

# src/*.cpp
set( GAMEA_SRC
	 src/game.cpp
	 src/key_handler.cpp
	 src/main.cpp
	 src/player.cpp
	 src/user_interface.cpp )

# src/*.h
set( GAMEA_HEADERS
	 src/game.h
	 src/includes.h
	 src/key_handler.h
	 src/player.h
	 src/user_interface.h )

add_library( GameA ${GAMEA_SRC} ${GAMEA_HEADERS} )

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
  set(ARCHITECTURE "x64")
else()
  set(ARCHITECTURE "x86")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")
find_package(SDL2 REQUIRED)
find_package(SDL2image REQUIRED)

target_include_directories( GameA PUBLIC ./src/ )
target_include_directories( GameA PUBLIC ${SDL2_INCLUDE_DIRS}
										 ${SDL2image_INCLUDE_DIRS} )

add_executable( GameAExecutable ${GAMEA_SRC} )
target_link_libraries( GameAExecutable GameA
					   ${SDL2_LIBRARIES}
					   ${SDL2image_LIBRARIES} )

set( POST_BUILD_FILES
	 res/sprite.png
	 ${SDL2_DLLS}
	 ${SDL2image_DLLS} )

foreach( res ${POST_BUILD_FILES} )
	if(IS_ABSOLUTE ${res})
		set(COPY_PATH ${res})
	else()
		set(COPY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${res})
	endif()

	ADD_CUSTOM_COMMAND( TARGET GameA POST_BUILD
						COMMAND ${CMAKE_COMMAND} -E copy
						${COPY_PATH}
						${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE} )
endforeach()
