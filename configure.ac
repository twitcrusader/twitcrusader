AC_INIT([TwitCrusader], [1.0], [BUG: ptkdev@gmail.com])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

AC_PROG_CXX

dnl ***************************************************************************
dnl Internatinalization
dnl ***************************************************************************
GETTEXT_PACKAGE=twc
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
PACKAGE_LOCALE_DIR=[${datadir}/locale]
AC_SUBST(PACKAGE_LOCALE_DIR)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.35.0])


PKG_CHECK_MODULES(libcurl, [libcurl >= 7.21.0], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libcurl >= 7.21.0
])])

AC_SUBST(libcurl_CFLAGS)
AC_SUBST(libcurl_LIBS)

PKG_CHECK_MODULES(gtk2, [gtk+-2.0 >=  2.24], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have gtk+-2.0 >=  2.24.6
])])

AC_SUBST(gtk2_CFLAGS)
AC_SUBST(gtk2_LIBS)

PKG_CHECK_MODULES(oauth, [oauth >= 0.9.1], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have oauth >= 0.9.1
])])

AC_SUBST(oauth_CFLAGS)
AC_SUBST(oauth_LIBS)


PKG_CHECK_MODULES(libxml2, [libxml-2.0 >= 2.6.32], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libxml-2.0 >= 2.6.32
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
po/Makefile.in
share/icons/Makefile
share/applications/Makefile
])
AC_OUTPUT
