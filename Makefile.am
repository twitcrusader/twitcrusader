SUBDIRS = src po share/icons share/applications

progdir = $(datadir)/@PACKAGE@

prog_DATA= \
	AUTHORS \
	COPYING \
	GPL

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


uninstall-local:
	rm -rf $(prefix)/share/@PACKAGE@/icons
