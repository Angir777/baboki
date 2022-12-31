<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	session_start();

	// Set the selected language
	if ($_POST['langSwitch'] == TRUE) {
		// Modal box rabat
		setcookie("_br", "0", time()+7200, "/");
		// Banner rabat
		$_SESSION['bannerRabat'] 		= TRUE;
		// Resetting the basket
		$_SESSION['cart'] 				= array();
		$_SESSION['cart_info'] 			= array();
		// Resetting the active discount
		$_SESSION['client_rabat_code'] 	= '';
		$_SESSION['client_rabat_check'] = '';
		$_SESSION['client_rabat_price'] = '0.00';
		// Change the language
		$_SESSION['lang'] 				= $_POST['lang'];
	}