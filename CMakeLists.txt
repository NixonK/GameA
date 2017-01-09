cmake_minimum_required( VERSION 3.6 FATAL_ERROR )

project( GameA )

option( SHOW_CONSOLE "Build executable to display console when running." ON )

# Prohibit in-source builds.
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
	message( FATAL_ERROR "In-source builds are not allowed, use a separate build directory." )
endif()


# Glob source files.
set( GAMEA_SRC_DIR "./src" )
file( GLOB_RECURSE GAMEA_SRC_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
	"${GAMEA_SRC_DIR}/*.cpp"
)
set( GAMEA_INCLUDE_DIR "./${PROJECT_NAME}" )
file( GLOB_RECURSE GAMEA_INCLUDE_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
	"${GAMEA_INCLUDE_DIR}/*.h"
)
set( SOURCE_FILES ${GAMEA_SRC_FILES} ${GAMEA_INCLUDE_FILES} )


# Create executable target.
if( WIN32 )
	if( SHOW_CONSOLE )
		add_executable( GameA ${SOURCE_FILES} GameA.rc )
	else()
		add_executable( GameA WIN32 ${SOURCE_FILES} GameA.rc )
	endif()
else()
	message( FATAL_ERROR "${CMAKE_SYSTEM} not supported for GameA." )
endif()
set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameA )


# Find and link import libraries.
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/" )
if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
	set( ARCHITECTURE "x64" )
else()
	set( ARCHITECTURE "x86" )
endif()
find_package( SDL2 REQUIRED )
find_package( SDL2image REQUIRED )
target_link_libraries( GameA ${SDL2_LIBRARIES} ${SDL2image_LIBRARIES} )
target_include_directories( GameA PUBLIC
	${GAMEA_INCLUDE_DIR}
	${SDL2_INCLUDE_DIRS}
	${SDL2image_INCLUDE_DIRS}
)


# Executable file dependencies.
set( POST_BUILD_FILES
	res/sprite.png
	${SDL2_DLLS}
	${SDL2image_DLLS}
)
# Add post-build commands to copy the dependencies to the executable directory.
foreach( res ${POST_BUILD_FILES} )
	if( IS_ABSOLUTE ${res} )
		set( COPY_PATH ${res} )
	else()
		set( COPY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${res} )
	endif()

	ADD_CUSTOM_COMMAND( TARGET GameA POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${COPY_PATH}
		${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}
	)
endforeach()
