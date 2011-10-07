#TwitCrusader - Linux Packages

Archlinux (pkgbuild), Debian/Ubuntu (deb), Fedora (rpm) and other packages

##Release
* [stable] Stable version
* [beta] Beta version
* [nightly] Version released on a daily (unstable)

##Required

* gcc or cc
* pkg-config
* intltool
* libcurl >= 7.22.0
* gtk+-2.4 >= 2.24.6
* oauth >= 0.9.1
* libxml-2.0 >= 2.6.32
* libnotify >= 0.7.3


##ArchLinux - Install or Compile Package

### PKGBUILD
    $ su
    # makepkg --asroot
    # pacman -U twitcrusader-git-XXXXXXXXXXXXXX-1-i686.pkg.tar.xz

### AUR
    $ su
    # yaourt -S twitcrusader-git


##Debian/Ubuntu - Install or Compile Package

	Coming Soon


##Fedora - Install or Compile Package

	Coming Soon

##Others

### Compile from Source
    $ ./configure
    $ make
    $ su
    # make install

if "configure" aren't present into the package try:

    $ ./autogen.sh

#### Unistalling from Source
    $ su
    # make uninstall
    
