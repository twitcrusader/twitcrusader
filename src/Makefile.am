bin_PROGRAMS = twc
twc_SOURCES = include/function.h function.c include/twitter.h twitter.c include/gtkwindows.h gtkwindows.c include/twitcrusader.h twitcrusader.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@\
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\"
