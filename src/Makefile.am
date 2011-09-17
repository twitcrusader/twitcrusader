bin_PROGRAMS = twc
twc_SOURCES = \
gui/inc/windows.main.h \
gui/inc/icons.h \
gui/inc/windows.updates.h \
gui/inc/windows.credits.h \
gui/windows.main.c \
gui/windows.updates.c \
gui/windows.credits.c \
core/inc/notify.h \
core/inc/functions.h \
core/inc/twitter.h \
core/inc/gethttp.h \
core/inc/config.h \
core/inc/lang.h \
core/inc/timeline.h \
core/notify.c \
core/functions.c \
core/twitter.c \
core/gethttp.c \
core/config.c \
core/timeline.c \
tools/inc/debugger.h \
tools/debugger.c \
main.c

twc_LDADD = @libcurl_LIBS@ @gtk2_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtk2_CFLAGS@ \
	@libcurl_CFLAGS@\
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
