bin_PROGRAMS = twc
twc_SOURCES = \
libs/oauth/twitter_oauth.c \
libs/curl/getfile.c \
libs/libxml/node.c \
gui/inc/windows.updates.h \
gui/windows.main.c \
gui/windows.credits.c \
gui/windows.updates.c \
main.c

twc_LDADD = @gtk3_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk3_CFLAGS@ \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
