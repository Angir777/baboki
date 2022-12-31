<?php

	/**
	* This file is part of BABOKI.COM
	*
	* @author       Błażej Skrzypniak <hi@skrzypniak.pl>
	* @link         https://baboki.com
	*/

	if (!version_compare(PHP_VERSION, '7.0.0', '>=')) {
		exit("Fixit requires at least <b>PHP 7.0</b>");
	}

	// URL files
	define('VIEW', 'front');

	// URL path
	$path = 'https://' . $_SERVER['HTTP_HOST'] . '/';
	define('URL', $path);

	// data base settings
	define('DB_PREFIX', 'mycms');

	// email base settings
	define('EMAIL_COMPANY', 'php-shop@example.com');

	// email base address
	define('ADDRESS_COMPANY', 'Lorem Ipsum');

	// bank number
	define('BANK_COMPANY', '00 0000 0000 0000 0000 0000 0000');

	// single dialog  settings
	define('SINGLE_DIALOG', false); // true or false

	// dev settings
	define('DEV', false); // true or false

	// delivery settings
	define('DELIVERY_PERSONAL', false); // true or false
	define('DELIVERY_INPOST', true); // true or false
	define('DELIVERY_DPD', true); // true or false
	define('DELIVERY_DPD_WORLD', true); // true or false

	// payment settings
	define('PAYMENT_HAND', false); // true or false
	define('PAYMENT_TRANSFER', true); // must only true
	define('PAYMENT_PRZELEWY24', false); // true or false