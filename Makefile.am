# DOXYGEN SUPPORT
include $(top_srcdir)/aminclude.am

SUBDIRS = share/icons share/applications libtwitc src

progdir = $(datadir)/@PACKAGE@

prog_DATA= \
	AUTHORS \
	COPYING \
	VERSION

EXTRA_DIST = \
	autogen.sh \
	$(DX_CONFIG)

if DX_COND_doc

all: doxygen-doc

endif

MOSTLYCLEANFILES = $(DX_CLEANFILES)

uninstall-local:
	rm -rf $(prefix)/share/@PACKAGE@/icons
	rm -rf /usr/share/applications/TwitCrusader.desktop
