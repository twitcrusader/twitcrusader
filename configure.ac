AC_INIT([TwitCrusader], [1.0], [BUG: ptkdev@gmail.com])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE([-Wall -pthread], AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

AC_PROG_CC

AC_PROG_CXX

dnl ***************************************************************************
dnl Internatinalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=twc
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])

AM_GLIB_GNU_GETTEXT

PACKAGE_LOCALE_DIR=[${datadir}/locale]
AC_SUBST(PACKAGE_LOCALE_DIR)


PKG_CHECK_MODULES(GTK_FOOBAR, [libcurl libxml-2.0 oauth gtk+-2.0])

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
po/Makefile.in
share/icons/Makefile
share/applications/Makefile
])
AC_OUTPUT
