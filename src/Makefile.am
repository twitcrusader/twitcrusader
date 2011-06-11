bin_PROGRAMS = twc
twc_SOURCES = main.c gui/windows.c gui/gtkfunctions.c core/twitter.c core/config.c core/timeline.c core/functions.c core/gethttp.c
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@

progdir = $(datadir)/@PACKAGE@

prog_DATA= \
	AUTHORS \
	GPL3

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
