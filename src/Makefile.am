bin_PROGRAMS = twc
twc_SOURCES =./gui/main_window.cc main.cc core/tweet.cc core/functions.cc core/local_user.cc core/getHTTP.cc core/user.cc core/twitter.cc core/config.cc core/timeline.cc
twc_LDADD = @gtkmm_LIBS@ @oauth_LIBS@ @libxml2_LIBS@ @libnotify_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/@PACKAGE@/icons/"\" \
	-DPROG_DIR=\""$(prefix)/share/@PACKAGE@"\" \
	@gtkmm_CFLAGS@ \
	-pthread \
	@oauth_CFLAGS@ \
	@libxml2_CFLAGS@ \
	@libnotify_CFLAGS@
