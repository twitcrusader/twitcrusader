bin_PROGRAMS = twc
twc_SOURCES = main.c core/twitter.c gui/windows.c gui/gtkfunctions.c core/timeline.c core/functions.c core/gethttp.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
