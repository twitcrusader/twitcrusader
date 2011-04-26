AC_INIT([TwitCrusader], [1.0], [BUG: ptkdev@gmail.com, orazio.1985@hotmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_CPP
AC_CONFIG_HEADERS([config.h])

AC_CHECK_PROGS([WGET], [wget curl])

AC_MSG_CHECKING(if wget was wget)
if test "X$WGET" = "Xwget"; then
   AC_MSG_RESULT(yes)
   WGET="wget -q" 
else
   AC_MSG_RESULT(no)
fi

AC_MSG_CHECKING(if wget was nothing)
if test -z "$WGET"; then
   AC_MSG_RESULT(yes, but that may be fatal)
else
   AC_MSG_RESULT(no, which is good.)
fi

PKG_CHECK_MODULES(gtk, [gtk+-2.0 >= 2.10.0], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtk+ >= 2.10.0
])])

AC_SUBST(gtk_CFLAGS)
AC_SUBST(gtk_LIBS)

PKG_CHECK_MODULES(oauth, [oauth >= 0.9.1], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have oauth >= 0.9.4
])])

PKG_CHECK_MODULES(libxml2, [libxml-2.0 >= 2.6.32], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libxml-2.0 >= 2.6.32
])])

AC_SUBST(oauth_CFLAGS)
AC_SUBST(oauth_LIBS)

AC_CONFIG_FILES([
Makefile
src/Makefile
img/Makefile
])
AC_OUTPUT
