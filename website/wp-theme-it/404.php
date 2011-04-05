<?php 
/*
if($_SERVER['REQUEST_URI'] == "/sitemap/"){ 
echo ":<a class='title_post' href='#'>SITEMAP</a><br />";
$filename = "/sitemap.xml";
$handle = fopen($filename, "r");
$var = fread($handle, filesize($filename));
preg_match_all("/(<loc>)(.*)(<\/loc>)/", $var, $matches);

for ($i=0; $i < count($matches[0]); $i++){
$array[$i] = $matches[2][$i];}
for( $i=0; $i < count($array); ++$i)
{
echo('<a href="');
echo($array[$i]);
echo('">'); 
$array[$i] = eregi_replace($_SERVER['SERVER_NAME'], "", $array[$i]);
$array[$i] = eregi_replace("http://", " ", $array[$i]);
$array[$i] = eregi_replace("cat/", " ", $array[$i]);
$array[$i] = eregi_replace("tag/", " ", $array[$i]);
$array[$i] = eregi_replace("/", " ", $array[$i]);
$array[$i] = eregi_replace("_", " ", $array[$i]);
$array[$i] = eregi_replace("-", " ", $array[$i]);
echo($array[$i]);
echo('</a><br /><br />');
} 
}else{ } */
?>
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN"> 
<html><head> 
<title>404 Not Found</title> 
</head><body> 
<h1>Not Found</h1> 
<p>The requested URL /assa was not found on this server.</p> 
</body></html> 
