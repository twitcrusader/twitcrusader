cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)

PROJECT(libraries)

SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CONFIGURATION_TYPES Release)

SET(BUILD_SHARED_LIBS "Set to ON to build shared libraries" OFF)

SET( CMAKE_VERBOSE_MAKEFILE ON )



SET(LOGC_HEADERS
	liblogc/logc.h
	)
	
SET(LOGC_SRC
	liblogc/impl/logc.c
	)

SET(HEADERS
	libtwitc/dm.h
	libtwitc/favorites.h
	libtwitc/functions.h
	libtwitc/http.h
	libtwitc/oauth.h
	libtwitc/status.h
	libtwitc/stdredef.h
	libtwitc/timeline.h
	libtwitc/twitc.h
	libtwitc/twitter.h
	libtwitc/user.h
	)
	
SET(SRC
	libtwitc/impl/dm.c
	libtwitc/impl/favorites.c
	libtwitc/impl/functions.c
	libtwitc/impl/http.c
	libtwitc/impl/oauth.c
	libtwitc/impl/status.c
	libtwitc/impl/timeline.c
	libtwitc/impl/twitter.c
	libtwitc/impl/user.c
	)


add_library( logc STATIC ${LOGC_HEADERS} ${LOGC_SRC})

add_library( twitc STATIC ${HEADERS} ${SRC} )

SET_TARGET_PROPERTIES(logc
                      PROPERTIES
                      VERSION 1.0.0
                      SOVERSION 1)

TARGET_LINK_LIBRARIES(twitc logc)

SET_TARGET_PROPERTIES(twitc
                      PROPERTIES
                      VERSION 1.0.0
                      SOVERSION 1)
     
INSTALL(TARGETS logc
		ARCHIVE DESTINATION /usr/local/lib
        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
                 
INSTALL(TARGETS twitc
        ARCHIVE DESTINATION /usr/local/lib
		PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
