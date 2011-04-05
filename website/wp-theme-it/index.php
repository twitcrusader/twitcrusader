<?php
	get_sidebar("mobile_detect"); 
	$detect = new Mobile_Detect();
	$mobi = $detect->isMobile();
	if(!$mobi){
		get_header();
		get_sidebar(); 
		get_template_part( 'desktop', 'index' );	
		get_footer(); 
	}else{
		get_header("mobile"); 
		get_template_part( 'mobile', 'index' );	
		get_footer("mobile"); 
	}
?>
