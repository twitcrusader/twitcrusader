bin_PROGRAMS = twc
twc_SOURCES = main.c gui/windows.main.c gui/windows.credits.c gui/windows.updates.c tools/debugger.c 
twc_LDADD = @gtk_LIBS@ @oauth_LIBS@ @libxml2_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@
