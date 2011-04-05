AC_INIT([TwitCrusader], [1.0], [BUG: ptkdev@gmail.com, orazio.1985@hotmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_CPP
AC_CANONICAL_HOST
AC_CONFIG_HEADERS([config.h])
PKG_CHECK_MODULES(gtk, [gtk+-2.0 >= 2.10.0], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtk+ >= 2.10.0
])])

AC_SUBST(gtk_CFLAGS)
AC_SUBST(gtk_LIBS)

PKG_CHECK_MODULES(oauth, [oauth >= 0.9.4], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have oauth >= 0.9.4
])])

AC_SUBST(oauth_CFLAGS)
AC_SUBST(oauth_LIBS)

AC_CONFIG_FILES([
Makefile
src/Makefile
img/Makefile
])
AC_OUTPUT
