bin_PROGRAMS = twc
twc_SOURCES = include/twitcrusader.h include/gtkwindows.h include/function.h include/twitter.h include/timeline.h include/gethttp.h twitcrusader.c twitter.c gtkwindows.c timeline.c function.c gethttp.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@

