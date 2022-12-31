<?php

    /**
	* This file is part of BABOKI.COM
	*
	* @author       Błażej Skrzypniak <hi@skrzypniak.pl>
	* @link         https://baboki.com
	*/
    
	// start session
	session_start();

	// frendly URL
	function exchangeCharacters($variable) {
		$aReplacePL = array('ą' => 'a', 'ę' => 'e', 'ś' => 's', 'ć' => 'c', 'ó' => 'o', 'ń' => 'n', 'ż' => 'z', 'ź' => 'z', 'ł' => 'l', 'Ą' => 'A', 'Ę' => 'E', 'Ś' => 'S', 'Ć' => 'C', 'Ó' => 'O', 'Ń' => 'N', 'Ż' => 'Z', 'Ź' => 'Z', 'Ł' => 'L');
		return str_replace(array_keys($aReplacePL), array_values($aReplacePL), $variable);
	}

	function friendly_url($variable) {
		$variable = exchangeCharacters($variable);
		$variable = strtolower($variable);
		$variable = str_replace(' ', '-', $variable);
		$variable = preg_replace('/[^0-9a-z\-]+/', '', $variable);
		$variable = preg_replace('/[\-]+/', '-', $variable);
		$variable = trim($variable, '-');
		return $variable;  
	}

	// chceck inputs
	function check_inputs($data) {
	  $data = trim($data);
	  $data = stripslashes($data);
	  $data = htmlspecialchars($data);
	  return $data;
	}

	// pageSite
	if (!isset($_SESSION['pageSite'])){$_SESSION['pageSite'] = 'home';}