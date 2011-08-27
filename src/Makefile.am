bin_PROGRAMS = twc
twc_SOURCES =gui/MainWindow.cc core/GetHTTP.cc core/Tweet.cc core/User.cc core/Twitter.cc core/Timeline.cc core/Config.cc core/Functions.cc core/LocalUser.cc Main.cc
twc_LDADD = @gtkmm_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtkmm_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
