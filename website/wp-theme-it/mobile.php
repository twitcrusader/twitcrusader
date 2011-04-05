	<div id="content">		
			<div id="spacecontent"></div>
			<div id="contentpost">
				<?php if ( have_posts() ) : while ( have_posts() ) : the_post(); ?>
					<div class="post-title"><a href="<?php the_permalink() ?>"><?php the_title(); ?></a></div>
					<div id="spacepost"></div>
					<div class="content-style"><?php the_content(); ?></div>
					<div id="spacepost"></div><div id="spacepost"></div>
				<?php endwhile; else: endif; ?>	
			</div>	
			<div id="spacecontent"></div>
			<div class="boxmenu"><a href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/features/">FEATURES</a></div>
			<div class="boxmenu"><a href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/changelog/">CHANGELOG</a></div>
			<div class="boxmenu"><a href="https://github.com/PTKDev/TwitCrusader/">GITHUB</a></div>
			<div class="boxmenu"><a href="http://<?php echo $_SERVER['SERVER_NAME']; ?>/download">DOWNLOAD</a></div>
		<table class="width">
			<tr>
				<td class="clear_center">
					<?php if(!is_single()) { ?>
						<div class="switch_page"><?php posts_nav_link(' | ','&laquo; Pagina Precedente','Pagina Successiva &raquo;'); ?> </div><br />
					<?php }?>
				</td>
			</tr>
		</table> 
	</div>
