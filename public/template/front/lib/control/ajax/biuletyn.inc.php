<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	require_once ('../../../../../../app/core/db.inc');
	require_once ('../../../../../../app/core/defines.inc');

	class BiuletynController extends db {

		public function addNewsletter() {

			$email = '';
			$lang = 'pl';
			$deleted = 0;
			$date_addition = date("Y/m/d");
			$ip = $_SERVER['REMOTE_ADDR'];
			$hidden = 1;
			
			$sql = "INSERT INTO ".DB_PREFIX."_newsletter (email, lang, deleted, date_addition, ip, hidden) VALUES (?, ?, ?, ?, ?, ?)";
			$statement = $this->connectToNewsletter()->prepare($sql);
			$statement->bindParam(":email", $email, PDO::PARAM_STR);
			$statement->bindParam(":lang", $lang, PDO::PARAM_STR);
			$statement->bindParam(":deleted", $deleted, PDO::PARAM_INT);
			$statement->bindParam(":date_addition", $date_addition, PDO::PARAM_STR);
			$statement->bindParam(":ip", $ip, PDO::PARAM_STR);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->execute([$email, $lang, $deleted, $date_addition, $ip, $hidden]);

	  		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter ORDER BY id_newsletter DESC";
		    $statement = $this->connectToNewsletter()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		    if (!empty($answer)) {
				foreach ($answer as $data) {
					$id_newsletter = $data['id_newsletter'];
					break;
				}
			}

			return $id_newsletter;

		}

		public function deleteNewsletter($id_newsletter) {

			$sql = "DELETE FROM ".DB_PREFIX."_newsletter WHERE id_newsletter = '".$id_newsletter."'";
			$statement = $this->connectToNewsletter()->prepare($sql);
	   		$statement->execute();

		}

	}

	$getBiuletynController = new BiuletynController();
	$pass = (int)$_GET['pass'];
	if (		$pass == 1) {
		echo $getBiuletynController->addNewsletter();
	} elseif (	$pass == 2) {
		$id_newsletter = (int)$_GET['id_newsletter'];
		echo $getBiuletynController->deleteNewsletter($id_newsletter);
	}