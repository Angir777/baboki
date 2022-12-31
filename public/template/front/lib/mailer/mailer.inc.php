<?php

	/**
    * This file is part of BABOKI.COM
    * Module: mailer
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	$errors = array();  									// array to hold validation errors
	$data 	= array(); 										// array to pass back data
	$lang 	= !empty($_POST['lang'])?$_POST['lang']:'pl';	// language for email

	function check_inputs($data) {
	  	$data = trim($data);
	  	$data = stripslashes($data);
	  	$data = htmlspecialchars($data);
	  	return $data;
	}

	// Language
	$c = [];
	if ($lang == 'pl') {
		$c['info_1'] = 'Imię i nazwisko jest wymagane.';
		$c['info_2'] = 'E-mail jest wymagany.';
		$c['info_3'] = 'Podaj poprawny numer telefonu.';
		$c['info_4'] = 'Treść wiadomości jest wymagana.';
		$c['info_5'] = 'Treść wiadomości jest za krótka.';
		$c['info_6'] = 'Nieprawidłowy wynik.';
		$c['info_7'] = 'Wiadomość została wysłana!';
	} else {
		$c['info_1'] = 'Name is required.';
		$c['info_2'] = 'E-mail is required.';
		$c['info_3'] = 'Please enter a valid phone number.';
		$c['info_4'] = 'Message is required.';
		$c['info_5'] = 'The content of the message is too short.';
		$c['info_6'] = 'Invalid result.';
		$c['info_7'] = 'Message was sent!';
	}
	// Validate the variables ======================================================
	// if any of these variables don't exist, add an error to our $errors array
	if (empty($_POST['name']))
		$errors['name'] = $c['info_1'];
	else
		$form_name = check_inputs($_POST['name']);
	
	if (empty($_POST['email']) OR !filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
		$errors['email'] = $c['info_2'];
	else
		$form_email = check_inputs($_POST['email']);
	
	if (empty($_POST['phone'])) { 
		$form_phone = ''; 
	} else { 
		if(!filter_var($_POST['phone'], FILTER_VALIDATE_INT) || strlen($_POST['phone']) < 6) {
			$errors['phone'] = $c['info_3']; 
		} else { 
			$form_phone = check_inputs($_POST['phone']); 
		} 
	}
	
	if (empty($_POST['message'])) {
		$errors['message'] = $c['info_4'];
	} else { 
		if (strlen($_POST['message']) < 10) { 
			$errors['message'] = $c['info_5']; 
		} else { 
			$form_message = check_inputs($_POST['message']); 
		} 
	}
	
	if (empty($_POST['recaptcha']) OR ($_POST['check'] != $_POST['recaptcha']))
		$errors['recaptcha'] = $c['info_6'];

	// Return a response ===========================================================
	// if there are any errors in our errors array, return a success boolean of false
	if (!empty($errors)) {
		// if there are items in our errors array, return those errors
		$data['success'] = false;
		$data['errors']  = $errors;
	} else {
		// Set the recipient email address.
		$recipient = EMAIL_COMPANY;
		// Set the email subject.
		$subject = "Zapytanie od ".$form_name;
		// Build the email content.
		$email_content 	.= "Język: ".$lang."<br>";
		$email_content 	.= "Imię i nazwisko: ".$form_name."<br>";
		$email_content 	.= "Email: ".$form_email."<br>";
		$email_content 	.= "Tel: ".$form_phone."<br>";
		$email_content 	.= "Wiadomość: <br><br>".$form_message."<br><br>";
		// Build the email headers.
		$email_headers   = array();
		$email_headers[] = "MIME-Version: 1.0";
		$email_headers[] = "Content-Transfer-Encoding: 8bit";
		$email_headers[] = "Content-type: text/html; charset=utf-8";
		$email_headers[] = "From: ".$form_email;
		$headers[] 		 = "X-Mailer: PHP/".phpversion();
		// Send the email.
		mail($recipient, $subject, $email_content, implode("\r\n", $email_headers));
		
		// show a message of success and provide a true success variable
		$data['success'] = true;
		$data['message'] = $c['info_7'];
	}
	// return all our data to an AJAX call
	echo json_encode($data);