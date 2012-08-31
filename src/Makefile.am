bin_PROGRAMS = twc
twc_SOURCES = \
preference.c \
notify.c \
Property.c \
ErrorWidget.c \
Registration.c \
Credits.c \
Version.c \
MainWindow.c \
twc.c

twc_LDADD = \
	@liblogc_LIBS@	 \
	@libtwitc_LIBS@	 \
	@libnotify_LIBS@ \
	$(EXTERN_LIB_DEP_LIBS)
	
if DEBUG

AM_CFLAGS = -g3 -O0 \
	-DDEBUG \
	-D_GNU_SOURCE \
	-lpthread \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@/"\" \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)locale/"\" \
	$(EXTERN_LIB_DEP_CFLAGS) \
	@libnotify_CFLAGS@ \
	@liblogc_CFLAGS@ \
	@libtwitc_CFLAGS@ \
	@libtwcgui_CFLAGS@


AM_CXXFLAGS = -g3 -O0 \
	-DDEBUG \
	-D_GNU_SOURCE \
	-lpthread \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@/"\" \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)locale/"\" \
	$(EXTERN_LIB_DEP_CFLAGS) \
	@libnotify_CFLAGS@ \
	@liblogc_CFLAGS@ \
	@libtwitc_CFLAGS@ \
	@libtwcgui_CFLAGS@

else

AM_CFLAGS = -O2 \
	-D_GNU_SOURCE \
	-lpthread \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@/"\" \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)locale/"\" \
	$(EXTERN_LIB_DEP_CFLAGS) \
	@libnotify_CFLAGS@ \
	@liblogc_CFLAGS@ \
	@libtwitc_CFLAGS@ \
	@libtwcgui_CFLAGS@
	
AM_CXXFLAGS = -O2 \
	-D_GNU_SOURCE \
	-lpthread \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@/"\" \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)locale/"\" \
	$(EXTERN_LIB_DEP_CFLAGS) \
	@libnotify_CFLAGS@ \
	@liblogc_CFLAGS@ \
	@libtwitc_CFLAGS@ \
	@libtwcgui_CFLAGS@

endif