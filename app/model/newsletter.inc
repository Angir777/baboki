<?php

class Newsletter extends db {

	public function checkNewsletter($email) {
		
		// Select form DB
		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter where email='$email' AND hidden=0";
	    $statement = $this->connectToNewsletter()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

		if (!empty($answer)) {

			// Update in DB
			$hidden = 1;
			$deleted = 1;
			$sql = "UPDATE ".DB_PREFIX."_newsletter SET hidden = :hidden, deleted = :deleted WHERE email = :email";
			$statement = $this->connectToNewsletter()->prepare($sql);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->bindParam(":deleted", $deleted, PDO::PARAM_INT);
			$statement->bindParam(":email", $email, PDO::PARAM_STR);
			$statement->execute();

			return TRUE;

		} else {

			return FALSE;
			
		}

	}

}