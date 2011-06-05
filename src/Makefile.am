bin_PROGRAMS = twc
twc_SOURCES = main.c src/core/twitter.c gui/window.c gui/gtkfunction.h src/core/timeline.c src/core/function.c src/core/gethttp.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
