bin_PROGRAMS = twc
twc_SOURCES = function.c gtkwindows.c twitcrusader.c twitter.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@

