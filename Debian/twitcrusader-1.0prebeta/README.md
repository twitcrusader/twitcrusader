#TwitCrusader

TwitCrusader is Twitter Client For Linux Desktop

## Are You A Developer?

Development Guidelines (Italian): http://dev.it.twitcrusader.org/

Developers Of TwitCrusader (Italian): http://it.twitcrusader.org/about/

##Required

* gcc or cc
* pkg-config
* intltool
* libcurl >= 7.22.0
* gtk+-2.4 >= 2.24.6
* oauth >= 0.9.1
* libxml-2.0 >= 2.6.32
* libnotify >= 0.7.3

### Compile - Makefile
    $ ./configure
    $ make
    $ su
    # make install

if "configure" aren't present into the package try:

    $ ./autogen.sh

#### Unistalling - Makefile
    $ su
    # make uninstall
    
##Branchs
* [builds] TwitCrusader Linux-PackageBuild (deb, pkgbuild, rpm, and other) 

* [experimental] TwitCrusader unstable code, testing and other. PTKDev test only.
		
* [nightly] TwitCrusader unstable code, testing and other. Please commit here.
	
* [nightly-cpp]	TwitCrusader++ is fork of TwitCrusader, More information on github.com/RoxShannon/TwitCrusaderpp

## Support

You can find us on this web source:

WebSite: http://www.twitcrusader.org/

IRC: chat.freenode.net at #teamtwc

Twitter: @teamtwc
