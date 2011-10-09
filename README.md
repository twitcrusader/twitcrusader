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
* libnotify >= 0.7.3`


##ArchLinux - Install or Compile Package

### PKGBUILD
    $ su
    # makepkg --asroot
    # pacman -U twitcrusader-git-XXXXXXXXXXXXXX-1-i686.pkg.tar.xz

### AUR
    $ su
    # yaourt -S twitcrusader-git


##Debian/Ubuntu

### Make the deb package

1) uncompress the source file `twitcrusader-<version>.tar.gz` ( or `twitcrusader-<version>.tar.bz2` )

NOTE the source file may be writed with lower case and may have only one  "-". 

2) Install package:  devscripts dh-make make build-essential dpkg apt

    $ sudo apt-get install devscripts dh-make make build-essential dpkg apt

3) Install program dependences: libcurl-ocaml intltool intltool-debian libcurl-ocaml-dev 
   libgtk2.0-dev libnotify-dev liboauth-dev libxml2-dev

    $ sudo apt-get install libcurl-ocaml intltool intltool-debian libcurl-ocaml-dev \
    libgtk2.0-dev libnotify-dev liboauth-dev libxml2-dev libnss3-dev

4) From the source tree run:

    $ dh_make -s -e <email address> -n –copyright gpl

5) Run:

    $ debuild binary 

### Install from package

    $ sudo dpkg -i <package name>.deb


##Fedora

### Make the rpm package

To make a new "rpmbuild" into your home directory run:

    $ rpmdev-setuptree

1) Copy compressed source file into rpmbuild/SOURCE
	( The source may be call `twitcrusader-<version>.tar.gz` )

2) Copy the file "twitcrusader.spec" located into "Fedora_Tree" (or create a new copy) "into rpmbuild/SPECS"

3) From the folder "rpmbuild" run:

    $ rpmbuild -v -bb --clean SPECS/twitcrusader.spec

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

    $ sh autogen.sh

#### Unistalling from Source
    $ su
    # make uninstall
    
    
##Debug

After installation run:

    $ twc --debug

To have more details run:

    $ gdb twc

( make sure you have gdb installed )