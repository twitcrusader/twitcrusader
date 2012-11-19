cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)

PROJECT(TwitCrusader)

SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CONFIGURATION_TYPES Release)

SET(BUILD_SHARED_LIBS "Set to ON to build shared libraries" OFF)

SET(FILEPATH ${CMAKE_CURRENT_SOURCE_DIR})
SET(PROJECT_FOLDER ${HOMEPATH}/TwitCrusader)
set (CMAKE_INSTALL_PREFIX ${PROJECT_FOLDER})

SET( ${PROJECT_NAME}_MAJOR_VERSION 1 )
SET( ${PROJECT_NAME}_MINOR_VERSION 0 )
SET( ${PROJECT_NAME}_PATCH_LEVEL 0 )

SET( CMAKE_VERBOSE_MAKEFILE ON )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/dep.cmake)

INCLUDE_DIRECTORIES (
  # Look in the cmake build directory (some generated headers could be there)
  ${CMAKE_CURRENT_BINARY_DIR} 
)

INCLUDE_DIRECTORIES(dependences)
add_subdirectory(dependences)
	
#Include the source and header files
SET(SRC 
	src/console.c
	src/Credits.c
	src/ErrorWidget.c
	src/MainWindow.c
	src/notify.c
	src/preference.c
	src/Property.c
	src/Registration.c
	src/twc.c
	src/Version.c
	)

SET(HDR 
	include/console.h
	include/Credits.h
	include/ErrorWidget.h
	include/icons.h
	include/MainWindow.h
	include/notify.h
	include/preference.h
	include/Property.h
	include/Registration.h
	include/twc.h
	include/Version.h
	)


#Generates the executable
add_executable(TwitCrusader  ${SRC} ${HDR} )


TARGET_LINK_LIBRARIES(TwitCrusader twitc)
TARGET_LINK_LIBRARIES(TwitCrusader ${GTHREAD_LIBRARIES} ${GTK3_LIBRARIES} ${LIBXML2_LIBRARIES} ${CURL_LIBRARIES} ${LIBNOTIFY_LIBRARIES} ${OAuth_LIBRARIES})


SET_TARGET_PROPERTIES(TwitCrusader
                      PROPERTIES
                      VERSION 1.0
                      SOVERSION 1)
					  
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/share/twitcrusader/icons/*.png")

INSTALL(FILES   ${CMAKE_CURRENT_SOURCE_DIR}/AUTHORS
				${CMAKE_CURRENT_SOURCE_DIR}/COPYING
				${CMAKE_CURRENT_SOURCE_DIR}/VERSION
				
		DESTINATION /usr/local/share/twitcrusader)
  
INSTALL(FILES ${files}
		DESTINATION /usr/local/share/twitcrusader/icons)

INSTALL(TARGETS TwitCrusader 
		RUNTIME DESTINATION /usr/local/bin
)


#~ include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/install.cmake)
