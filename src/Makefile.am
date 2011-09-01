bin_PROGRAMS = twcpp
twcpp_SOURCES = gui/AccountDialog.cc gui/AboutWindow.cc gui/WindowVersion.cc gui/MainWindow.cc gui/RegWindow.cc core/GetHTTP.cc core/Tweet.cc core/User.cc core/Twitter.cc core/Timeline.cc core/Config.cc core/Functions.cc core/LocalUser.cc Main.cc 
twcpp_LDADD = @gtkmm_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtkmm_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
