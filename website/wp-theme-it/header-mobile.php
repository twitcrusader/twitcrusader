<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.2//EN" "http://www.openmobilealliance.org/tech/DTD/xhtml-mobile12.dtd">
<html>
<head>
	<meta charset="<?php bloginfo( 'charset' ); ?>" />
	<title><?php wp_title(''); ?> <?php if(wp_title(' ', false)) { echo '&laquo;'; } ?> <?php bloginfo('name'); ?></title>
	<meta name="generator" content="Geany IDE" />
	<meta name="author" content="Patryk Rzucidlo" />
	<meta name="copyright" content="Creative Commons IT" />
	<meta name="distribution" content="global" />
	<meta name="author-mail" content="ptkdev[at]gmail[dot]com" />
	<meta name="author-msn" content="ptkdev[at]gmail[dot]com" />
	<meta name="author-skype" content="ptkdev" />
	<meta name="author-gadu_gadu" content="2825253" />
	<meta name="author-phone_wind" content="+39 3281759093" />
	<meta name="robots" content="index,follow" />
	<meta name="revisit-after" content="3 days" />
	<meta name="rating" content="general" />
	<meta name="language" content="it" />
	<link rel="alternate" type="application/rss+xml" title="<?php bloginfo('name'); ?> - Feed RSS" href="http://feeds.feedburner.com/twitcrusader" />
	<link rel="shortcut icon" href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/favicon.ico" />
	<link rel="icon" href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/favicon.png" type="image/png" />
	<link rel="icon" href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/favicon.ico" type="image/ico" />
	<link rel="profile" href="http://gmpg.org/xfn/11" />
	<link rel="stylesheet" type="text/css" href="<?php bloginfo('template_url'); ?>/css/mobile/layout.css" />
	<link rel="stylesheet" type="text/css" href="<?php bloginfo('template_url'); ?>/css/mobile/header.css" />
	<link rel="stylesheet" type="text/css" href="<?php bloginfo('template_url'); ?>/css/mobile/body.css" />
	<link rel="stylesheet" type="text/css" href="<?php bloginfo('template_url'); ?>/css/mobile/footer.css" />
	<link rel="stylesheet" type="text/css" href="<?php bloginfo('template_url'); ?>/css/mobile/link.css" />
	<link rel="pingback" href="<?php bloginfo( 'pingback_url' ); ?>" />
	<?php
		wp_head();
	?>
</head>

<body>
	<div id="title"><a href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/">TwitCrusader</a></div>		
