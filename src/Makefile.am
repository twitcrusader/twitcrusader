bin_PROGRAMS = twc
twc_SOURCES = \
gui/windows.error.c \
gui/windows.properties.c \
gui/windows.main.c \
gui/windows.register.c \
gui/windows.updates.c \
gui/windows.credits.c \
core/preference.c\
core/debug.c \
core/notify.c \
core/functions.c \
core/twitter.c \
core/gethttp.c \
core/config.c \
core/timeline.c \
main.c


twc_LDADD = @libcurl_LIBS@ @gtk2_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-pthread \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk2_CFLAGS@ \
	@libcurl_CFLAGS@\
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
