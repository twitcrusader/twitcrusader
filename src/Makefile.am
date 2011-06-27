## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(datadir)/twitcrusader/ui
ui_DATA = twitcrusader.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(TWITCRUSADER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = twitcrusader

twitcrusader_SOURCES = \
	main.c

twitcrusader_LDFLAGS = \
	-Wl,--export-dynamic

twitcrusader_LDADD = $(TWITCRUSADER_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/twitcrusader
