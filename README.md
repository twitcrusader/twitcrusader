#TwitCrusader - Linux Packages

Archlinux (pkgbuild), Debian/Ubuntu (deb), Fedora (rpm) and other packages


##Folders

First folder have name of a linux distro
	/debian
Second folder refers to a family of instruction set architectures (x86 = 32bit / x64 = 64bit)
	/debian/x86
Third folder is type of this twc-release (stable/nightly/beta/etc) 
	/debian/x86/nightly

##Release
* [stable] Stable version
* [beta] Beta version
* [nightly] Version released on a daily (unstable)


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
