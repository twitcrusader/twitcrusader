# DOXYGEN SUPPORT
include $(top_srcdir)/aminclude.am

SUBDIRS = share/icons share/applications po libtwitc src

progdir = $(datadir)/@PACKAGE@

prog_DATA= \
	AUTHORS \
	COPYING \
	VERSION
	
INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	autogen.sh \
	$(DX_CONFIG) \
	$(INTLTOOL_FILES)

if DX_COND_doc

all: doxygen-doc

endif

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


MOSTLYCLEANFILES = $(DX_CLEANFILES)

uninstall-local:
	rm -rf $(prefix)/share/@PACKAGE@/icons
	rm -rf /usr/share/applications/TwitCrusader.desktop
