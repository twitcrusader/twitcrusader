#
# Regular cron jobs for the twitcrusader package
#
0 4	* * *	root	[ -x /usr/bin/twitcrusader_maintenance ] && /usr/bin/twitcrusader_maintenance
