<?php

	/**
	* This file is part of BABOKI.COM
	*
	* @author       Błażej Skrzypniak <hi@skrzypniak.pl>
	* @link         https://baboki.com
	*/

	// language for app
	if (!isset($_SESSION['lang'])) {$_SESSION['lang'] = 'pl';}

	class Language {

		public function lang($lang) {
		    require_once('template/' . VIEW . '/lang/lang_' . $lang . '.inc');
		    return $l;
		}

	}
	
	$getLang = new Language();