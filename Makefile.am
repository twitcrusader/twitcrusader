SUBDIRS = src po share/icons share/applications

progdir = $(datadir)/@PACKAGE@

prog_DATA= \
	AUTHORS \
	COPYING \
	GPL \
	VERSION

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


#html doc
if HAVE_DOXYGEN

# doxdir & pkgdocdir are not always defined by automake
docdir=$(datadir)/doc
pkgdocdir=$(docdir)/$(PACKAGE)
doc_htmldir=$(pkgdocdir)/html

doc_html_DATA = $(top_builddir)/doc/html/html.tar

$(doc_html_DATA): $(top_builddir)/doc/html/index.html
	cd $(<D) && tar cf html.tar *

$(top_builddir)/doc/html/index.html: $(SOURCES) twc.doxygen Makefile.am
	rm -rf doc
	$(DOXYGEN) twc.doxygen

install-data-hook:
	cd $(DESTDIR)$(doc_htmldir) && tar xf html.tar && rm -f html.tar

uninstall-hook:
	cd $(DESTDIR)$(doc_htmldir) && rm -f *


endif


uninstall-local:
	rm -rf $(prefix)/share/@PACKAGE@/icons
