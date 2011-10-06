#TwitCrusader++
###TwitCrusader++ is Twitter Client For Linux Desktop

##Required

* g++ or c++
* pkg-config
* gtkmm-2.4 >= 2.24.0
* libcurl >= 7.21.7
* oauth >= 0.9.4
* libxml++-2.6 >= 2.10.0
* libnotify >= 0.7.3

## Archlinux - required
    
### Dependencies:
    $ su
    # pacman -Syu
    # pacman -S gtkmm3 liboauth libxml++ libnotify pkg-config


##  Ubuntu - required
	$ sudo apt-get install libtool libgtkmm-2.4-dev liboauth-dev libxml++2.6-dev \
						   libnotify-dev libcurl4-gnutls-dev

### Compile - Makefile
    $ ./autogen.sh
    $ ./configure
    $ make
    $ su
    # make install

#### Unistalling - Makefile
    $ su
    # make uninstall

###Support

Source: https://github.com/RoxShannon/

