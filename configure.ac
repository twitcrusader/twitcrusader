AC_PREREQ(2.59)

AC_CANONICAL_SYSTEM

AC_INIT([TwitCrusader++], [1.0], [BUG: ptkdev@gmail.com, orazio.1985@hotmail.com])
AM_INIT_AUTOMAKE([-Wall ])

AC_PROG_CPP
AC_PROG_CXX([cc++ c++ g++])

AC_CONFIG_HEADERS([config.h])

PKG_CHECK_MODULES(gtkmm, [gtkmm-3.0 >= 3.0.1], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtkmm-3.0 >= 3.0.1
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


PKG_CHECK_MODULES(libxmlpp, [libxml++-2.6 >= 2.34.1], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libxml-2.0 >= 2.7.8
])])

AC_SUBST(libxml2_CFLAGS)
AC_SUBST(libxml2_LIBS)

PKG_CHECK_MODULES(libnotify, [libnotify >= 0.7.3], , [
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
