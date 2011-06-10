bin_PROGRAMS = twc
twc_SOURCES = twc main.c core/config.c core/functions.c core/gethttp.c core/timeline.c core/twitter.c gui/gtkMain.c gui/windows.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
