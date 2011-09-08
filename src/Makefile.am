bin_PROGRAMS = twcpp
twcpp_SOURCES = gui/PropertiesDialog.cc \
gui/VersionDialog.cc \
gui/AboutDialog.cc \
gui/MainWindow.cc \
gui/RegDialog.cc \
core/GetHTTP.cc \
core/Tweet.cc \
core/User.cc \
core/Twitter.cc \
core/TimeLine.cc \
core/Config.cc \
core/Functions.cc \
core/LocalUser.cc \
Main.cc 
 
twcpp_LDADD = @gtkmm_LIBS@ @oauth_LIBS@ @libxmlpp_LIBS@ @libnotify_LIBS@ @libcurl_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtkmm_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxmlpp_CFLAGS@ \
	@libnotify_CFLAGS@ \
	@libcurl_CFLAGS@
