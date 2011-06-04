bin_PROGRAMS = twc
twc_SOURCES = twitcrusader.c twitter.c gtkwindows.c timeline.c function.c gethttp.c test/thread/gtk-thread.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-pthread \ 
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
