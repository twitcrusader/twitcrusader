bin_PROGRAMS = twc
twc_SOURCES = main.cc  gui/main_window.cc  core/config.cc core/functions.cc core/getHTTP.cc core/local_user.cc core/timeline.cc core/tweet.cc core/twitter.cc core/user.cc
twc_LDADD = @gtkmm_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtkmm_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
