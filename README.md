#TwitCrusader

[![TwitCrusader](http://www.twitcrusader.org/logo.png)](http://www.twitcrusader.org/)

TwitCrusader is Twitter Client For Linux Desktop


## How to download this repository:

	$ git clone <project url>  --recursive

##Branchs

* [builds] TwitCrusader Linux-PackageBuild (deb, pkgbuild, rpm, and other) 

* [experimental] TwitCrusader unstable code, testing and other. PTKDev test only.
		
* [nightly] TwitCrusader unstable code, testing and other. Please commit here.
	
* [nightly-cpp]	TwitCrusader++ is fork of TwitCrusader, More information on github.com/KernelMonkey/TwitCrusaderpp

## Are You A Developer?

Development Guidelines (Italian): http://dev.it.twitcrusader.org/

Developers Of TwitCrusader (Italian): http://it.twitcrusader.org/about/

##Required

* C compiler
* pkg-config
* intltool
* gtk+-3.0
* gthreads
* libnotify >= 0.7.3

libtwitc Required:

* libcurl 
* oauth
* libxml-2.0
 

### Compile - Makefile

    $ ./autogen.sh
    $ ./configure
    $ make
    $ su
    # make install

#### Unistalling - Makefile

    $ su
    # make uninstall

##Debug

On compiling process run:

    $ ./configure --enable-debug

To have more details run:

    $ gdb twc

( make sure you have gdb installed )


## Support

You can find us on this web source:

WebSite: http://www.twitcrusader.org/

IRC: chat.freenode.net at #teamtwc

Twitter: @teamtwc
