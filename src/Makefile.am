bin_PROGRAMS = twc
twc_SOURCES = inc/function.h inc/twitcrusader.h inc/gtkwindows.h function.c twitcrusader.c gtkwindows.c 
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@
AM_CPPFLAGS = \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@\
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\"
