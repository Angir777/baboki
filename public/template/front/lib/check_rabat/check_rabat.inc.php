<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */
 	
	// require
	require_once ('../../../../../app/core/config.inc');
	require_once ('../../../../../app/core/db.inc');
	require_once ('../../../../../app/core/defines.inc');
	// global varables
	global $lang;										// Global language varable
	global $l;
	// data
	$pass = (int)$_GET['pass'];
	if (!empty($_GET['text_rabat']))
		$text_rabat = check_inputs($_GET['text_rabat']);
	if (!empty($_GET['email_rabat']) OR filter_var($_GET['email_rabat'], FILTER_VALIDATE_EMAIL))
		$email_rabat = check_inputs($_GET['email_rabat']);
	// class
	class Newsletter extends db {

      	public function checkMail($email_rabat) {

      		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter WHERE email='$email_rabat' AND deleted=0 AND hidden=0"; 
			$getSelectCnt = $select->num_rows;
			$statement = $this->connectToNewsletter()->prepare($sql);
	    	$statement->execute();
	    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answer) ) {
				return TRUE;
			} else {
				return FALSE;
			}

      	}

    }
	class CheckRabatController extends db {

		public function getPersonalDiscount() {
			$single_rabat_codes = array();
			$sql = "SELECT * FROM ".DB_PREFIX."_discount WHERE active=0";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answer) ) {
				foreach ($answer as $data) {
					// data
					$code = $data['code'];
					// add to array
					array_push($single_rabat_codes, $code);
				}
			}

			return $single_rabat_codes;

		}

	}
	
	$getNewsletter = new Newsletter();
	$getCheckRabatController = new CheckRabatController();
	$single_rabat_codes = $getCheckRabatController->getPersonalDiscount();
	
	// Checking the discount from the delivery-and-payment site
	if ($pass == 1) {
		if (!empty($text_rabat)) {
			// Discount for one user through a unique code active once
			if (in_array ($text_rabat, $single_rabat_codes)) {
				if (empty($email_rabat)) {
					$_SESSION['client_rabat']['code'] = $text_rabat;
					$_SESSION['client_rabat']['check'] = 'notcompletely';
					$_SESSION['client_rabat']['price'] = '0.00';
					$_SESSION['client_rabat']['type'] = '';
				} else {
					$_SESSION['client_rabat']['code'] = $text_rabat;
					$_SESSION['client_rabat']['check'] = 'yes';
					$_SESSION['client_rabat']['price'] = '30';												// Discount 30%
					$_SESSION['client_rabat']['type'] = 1;
					exit;
				}
			// Discount for all users until the set date
			} elseif ($text_rabat == 'PANDA18' && $_SESSION['bannerRabatActive'] == TRUE) {
				if (empty($email_rabat)) {
					$_SESSION['client_rabat']['code'] = $text_rabat;
					$_SESSION['client_rabat']['check'] = 'notcompletely';
					$_SESSION['client_rabat']['price'] = '0.00';
					$_SESSION['client_rabat']['type'] = '';
				} else {
					$_SESSION['client_rabat']['code'] = $text_rabat;
					$_SESSION['client_rabat']['check'] = 'yes';
					$_SESSION['client_rabat']['price'] = '20';												// Discount 20%
					$_SESSION['client_rabat']['type'] = 2;
					exit;
				}
			// First purchase discount
			} elseif ($text_rabat == 'HELLO') {
				if (empty($email_rabat)) {
					$_SESSION['client_rabat']['code'] = $text_rabat;
					$_SESSION['client_rabat']['check'] = 'notcompletely';
					$_SESSION['client_rabat']['price'] = '0.00';
					$_SESSION['client_rabat']['type'] = '';
				} else {
					$checkMail = $getNewsletter->checkMail($email_rabat);
					if ($checkMail == TRUE) {
						$_SESSION['client_rabat']['code'] = $text_rabat;
						$_SESSION['client_rabat']['check'] = 'yes';
						$_SESSION['client_rabat']['price'] = '10';											// Discount 10%
						$_SESSION['client_rabat']['type'] = 3;
						exit;
					} else {
						$_SESSION['client_rabat']['code'] = $text_rabat;
						$_SESSION['client_rabat']['check'] = 'notcompletely';
						$_SESSION['client_rabat']['price'] = '0.00';
						$_SESSION['client_rabat']['type'] = '';
					}
				}
			} else {
				$_SESSION['client_rabat']['code'] = $text_rabat;
				$_SESSION['client_rabat']['check'] = 'no';
				$_SESSION['client_rabat']['price'] = '0.00';
				$_SESSION['client_rabat']['type'] = '';
			}
		} else {
			$_SESSION['client_rabat']['code'] = $text_rabat;
			$_SESSION['client_rabat']['check'] = 'none';
			$_SESSION['client_rabat']['price'] = '0.00';
			$_SESSION['client_rabat']['type'] = '';
		}
	// Disabling the display of a banner with a discount on the website
	} elseif ($pass == 3) {
		$_SESSION['bannerRabatShow'] = FALSE;
	}