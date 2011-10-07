#TwitCrusader - Linux Packages

Archlinux (pkgbuild), Debian/Ubuntu (deb), Fedora (rpm) and other packages

##Required

* gcc or cc
* pkg-config
* intltool
* libcurl >= 7.21.0
* gtk+-2.4 >= 2.24.4
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


##Fedora

### Make the rpm package

To make a new "rpmbuild" into your home directory run:

	$ rpmdev-setuptree

Or move into your home directory the rpmbuild located into "Fedora_Tree" 

1) Copy compressed source file into rpmbuild/SOURCE
	( The source may be call "TwitCrusader-<version>.tar.gz" )

2) Create or modify the file "TwitCrusader.spec" into rpmbuild/SPECS

3) From the folder "rpmbuild" run:

	$ rpmbuild -v -bb --clean SPECS/TwitCrusader.spec

4) The rpm package are located into "rpmbuild/RPMS"


### Install from package

Download the right TwitCrusader package for your arch and run:

	$ rpm -i <package name>.rpm

##Others Linux System

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
    
