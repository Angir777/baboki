<?php

	/**
	* This file is part of BABOKI.COM
	*
	* @author       Błażej Skrzypniak <hi@skrzypniak.pl>
	* @link         https://baboki.com
	*/

	header('Content-Type:text/html;charset=utf-8');

	require_once ('../app/init.php');														// load functions app
	require_once ('vendor/autoload.php');													// load scripts composer
	
	ob_start();
	
	$showPage = new Content();																// create content
	$showPage->getMenuLight();	
	$lang = $_SESSION['lang'];																// load general language
	$l = $getLang->lang($lang);																// load content - menu light
	require_once ('template/' . VIEW . '/header.inc');										// load header page
	$showPage->getPage($lang, $l);															// load content - main page
	require_once ('template/' . VIEW . '/footer.inc');										// load footer page

	// init dev bar
	if ($_SESSION['user']['logged'] == true) {
		if ( DEV == true ) {
			echo '<pre><code><b>$_SESSION</b><br>';
			echo print_r($_SESSION);
			echo '</code></pre>';
			echo '<pre><code><b>$_COOKIES</b><br>';
			echo print_r($_COOKIE);
			echo '</code></pre>';
			echo '<pre><code><b>$_POST</b><br>';
			echo print_r($_POST);
			echo '</code></pre>';
			echo '<pre><code><b>$_FILES</b><br>';
			echo print_r($_FILES);
			echo '</code></pre>';
		}
	}

	ob_end_flush();