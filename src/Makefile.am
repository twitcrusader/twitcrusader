bin_PROGRAMS = twc
twc_SOURCES = include/function.h include/twitcrusader.h include/gtkwindows.h function.c twitcrusader.c gtkwindows.c 
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@
AM_CPPFLAGS = \
	@gtk_CFLAGS@ \
	@oauth_CFLAGS@ \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\"
