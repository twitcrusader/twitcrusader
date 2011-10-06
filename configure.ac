AC_INIT(twitcrusaderpp, 0.3)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

AC_PROG_CXX




dnl ***************************************************************************
dnl Internatinalization
dnl ***************************************************************************
GETTEXT_PACKAGE=twitcrusaderpp
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
PACKAGE_LOCALE_DIR=[${datadir}/locale]
AC_SUBST(PACKAGE_LOCALE_DIR)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.35.0])


PKG_CHECK_MODULES(libcurl, [libcurl >= 7.21.3], , [
		AC_MSG_RESULT(no)
		AC_MSG_ERROR([

You must have libcurl >= 7.21.3
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





AC_OUTPUT([
Makefile
src/Makefile
src/share/icons/Makefile
src/share/applications/Makefile
po/Makefile.in
])