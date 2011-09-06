AC_INIT([TwitCrusaderpp], [1.0], [BUG: orazio.1985@hotmail.com])

AC_PREREQ(2.59)

AC_CANONICAL_SYSTEM


AM_INIT_AUTOMAKE([-Wall ])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX([c++ g++])

AC_CONFIG_HEADERS([config.h])

PKG_CHECK_MODULES(libcurl, [libcurl >= 7.21.7], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libcurl >= 7.21.7
])])

AC_SUBST(libcurl_CFLAGS)
AC_SUBST(libcurl_LIBS)

PKG_CHECK_MODULES(gtkmm, [gtkmm-2.4 >= 2.24.0], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtkmm-2.4 >= 2.24.0
])])

AC_SUBST(gtkmm_CFLAGS)
AC_SUBST(gtkmm_LIBS)

PKG_CHECK_MODULES(oauth, [oauth >= 0.9.4], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have oauth >= 0.9.4
])])

AC_SUBST(oauth_CFLAGS)
AC_SUBST(oauth_LIBS)

PKG_CHECK_MODULES(libxmlpp, [libxml++-2.6 >= 2.10.0], ,[
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libxml++-2.6 >= 2.10.0
])])
    
AC_SUBST(libxmlpp_CFLAGS)
AC_SUBST(libxmlpp_LIBS)

PKG_CHECK_MODULES(libnotify, [libnotify >= 0.7.2], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libnotify >= 0.7.3
])])

AC_SUBST(libnotify_CFLAGS)
AC_SUBST(libnotify_LIBS)

AC_CONFIG_FILES([
Makefile
src/Makefile
src/share/icons/Makefile
src/share/applications/Makefile
])
AC_OUTPUT
