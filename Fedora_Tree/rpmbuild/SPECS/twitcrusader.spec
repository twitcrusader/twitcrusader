Name:		twitcrusader
Version:	1.0prebeta
Release:	1%{?dist}
Summary:	twitcrusader
Group:		Internet/Browser
License:	GPL
URL:		http://it.twitcrusader.org/
Source: 	%{name}-%{version}.tar.gz
Prefix:		/usr
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:	gettext
BuildRequires:	glib
BuildRequires:	automake
BuildRequires:	autoconf

BuildRequires:	libcurl-devel
BuildRequires:	gtk2-devel
BuildRequires:	liboauth-devel
BuildRequires:	libxml2-devel
Requires:	libnotify
Requires:	libcurl
Requires:	gtk2
Requires:	liboauth
Requires:	libxml2
Requires:	libnotify
%description
TwitCrusader is Twitter Client For Linux Desktop

%prep
%setup -q

%build
sh autogen.sh
%configure --prefix=/usr
make

%install
rm -rf %{buildroot}
make DESTDIR=%{buildroot} install

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%doc
/usr/share/locale/it/LC_MESSAGES/*
/usr/share/applications/*
/usr/share/icons/*
/usr/share/*
/usr/bin/twc





%changelog

