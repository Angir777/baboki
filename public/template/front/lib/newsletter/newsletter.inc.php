<?php

	/**
    * This file is part of BABOKI.COM
    * Module: newsletter
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

    require_once ('../../../../../app/core/db.inc');
	require_once ('../../../../../app/core/defines.inc');

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		
		$lang 	= !empty($_POST['lang'])?$_POST['lang']:'pl';
		$ip 	= !empty($_POST['addr'])?$_POST['addr']:'';
		$email 	= filter_var(trim($_POST["email"]), FILTER_SANITIZE_EMAIL);
		
		$n = [];
		if ($lang == 'pl') {
			$n['page_name'] = 'biuletyn';
			$n['info_1'] = 'Proszę, odśwież stronę i zaznacz pole reCAPTCHA.';
			$n['info_2'] = 'Podany adres e-mail jest już zapisany!';
			$n['info_3'] = 'Błąd! Spróbuj ponownie później.';
			$n['info_4'] = 'Dziękujemy za zapisanie się do naszego newsletter-a!';

			$n['newsletter_h1'] = 'Ręcznie szyte<br/>maskotki';
			$n['newsletter_about_b'] = 'Kim są Baboki?';
			$n['newsletter_about_p'] = 'Baboki to mała manufaktura ręcznie szytych, projektowanych od serca pluszaków. Wszystkie maskotki szyte są tutaj z uwagą i pasją ręcznie, dlatego każda jest inna i niepowtarzalna. Baboki są przyjazne dla dzieci, nie mają żadnych twardych, plastikowych czy metalowych elementów. Wszystkie baboki powstają w środowisku wolnym od dymu papierosowego. Wytwarzane są w Polsce a do ich produkcji używane są tylko polskie materiały.';
			$n['newsletter_advantages_b'] = 'Dlaczego Baboki?';
			$n['newsletter_advantages_p'] = '
				<li>Baboczek może być pierwszym przyjacielem Twojego dziecka;</li>
				<li>Możesz wyrazić swoje uczucia za pomocą danej maskotki;</li>
				<li>Są idealne do zabawy zarówno w domu, jak i w podróży;</li>
				<li>Wykorzystujemy tylko najwyższej jakości materiały pochodzące z polski;</li>
				<li>Nasze pluszaki nie mają żadnych twardych, plastikowych czy metalowych elementów;</li>
				<li>Wykorzystujemy antyalergiczne wypełnienie posiadające certyfikat Oeko-Tex®Standard100;</li>
				<li>Maskotki powstają w środowisku wolnym od dymu papierosowego;</li>
				<li>Baboki tworzone są z pasją i miłością do zabawek;</li>
				<li>Każdy produkt jest unikalny i niepowtarzalny;</li>
				<li>Dbamy o design i pozytywny odbiór naszych produktów;</li>
				<li>Baboki to w 100% polskie rękodzieło.</li>
			';
			$n['newsletter_create_b'] = 'Pluszaki na zamówienie';
			$n['newsletter_create_p'] = 'Możesz zaprojektować własną maskotkę dla siebie lub Twoich bliskich! Skorzystaj z całej gamy elementów dzięki którym możesz odwzorować swoją ulubioną postać z gry, filmu bądź książki. Masz bujną wyobraźnię? Super! Stwórz całkiem nową postać i zaskocz swoich znajomych!';
			$n['newsletter_code_b'] = 'Twój 5% kod rabatowy na pierwszy zakup:';
			$n['newsletter_code_p'] = 'HELLO';
			$n['newsletter_text_start'] = 'Jeśli nie chcesz otrzymywać newslettera ';
			$n['newsletter_text_end'] = 'wypisz się';
			$n['newsletter_reserved'] = 'Wszelkie prawa zastrzeżone.';
		} else {
			$n['page_name'] = 'newsletter';
			$n['info_1'] = 'Please, refresh the page and check the box reCAPTCHA.';
			$n['info_2'] = 'Your e-mail address is already saved!';
			$n['info_3'] = 'Error! Try again later.';
			$n['info_4'] = 'Thank you for signing up to our newsletter!';

			$n['newsletter_h1'] = 'Hand sewn<br/>mascots';
			$n['newsletter_about_b'] = 'Who are Baboki?';
			$n['newsletter_about_p'] = 'Baboki is a small manufacture of hand-sewn, heart-shaped stuffed mascots. All mascots are sewn here with attention and passion by hand, so each is different and unique. Baboki are child-friendly, they do not have any hard, plastic or metal elements. All babokas are created in a smoke-free environment. They are made in Poland and only Polish materials are used in their production.';
			$n['newsletter_advantages_b'] = 'Why Baboki?';
			$n['newsletter_advantages_p'] = '
				<li> Baboczek may be your child\'s first friend; </li>
				<li> You can express your feelings with a mascot; </li>
				<li> They are perfect for fun both at home and while traveling; </li>
				<li> We only use the highest quality materials from Poland; </li>
				<li> Our stuffed animals do not have any hard, plastic or metal elements; </li>
				<li> We use antiallergic filling certified by Oeko-Tex®Standard100; </li>
				<li> Mascots are created in a smoke-free environment; </li>
				<li> Baboki are created with passion and love for toys; </li>
				<li> Each product is unique and unique; </li>
				<li> We care about the design and positive reception of our products; </li>
				<li> Baboki is 100% Polish handicraft. </li>
			';
			$n['newsletter_create_b'] = 'Custom stuffed mascots';
			$n['newsletter_create_p'] = 'You can design your own mascot for yourself or your loved ones! Use the whole range of elements thanks to which you can reproduce your favorite character from a game, movie or book. You have luxuriant imagination? Cool! Create a whole new character and surprise your friends!';
			$n['newsletter_code_b'] = 'Your 5% rebate code on your first purchase:';
			$n['newsletter_code_p'] = 'HELLO';
			$n['newsletter_text_start'] = 'If you do not want to receive the newsletter ';
			$n['newsletter_text_end'] = 'sign off';
			$n['newsletter_reserved'] = 'All rights reserved.';
		}

		if (isset($_POST['g-recaptcha-response']) && !empty($_POST['g-recaptcha-response'])) {

			$secret = '6LcsSn4UAAAAAMMDyhS_vHR_P28_D59u6_PuqMwG'; // Secret key
			$verifyResponse = file_get_contents('https://www.google.com/recaptcha/api/siteverify?secret='.$secret.'&response='.$_POST['g-recaptcha-response']);
			$responseData = json_decode($verifyResponse);

			if ($responseData->success) {

				define('URL', 'https://baboki.com/');
				define('DB_PREFIX', 'mycms');

			    class Newsletter extends db {

					public function checkNewsletter($email, $lang, $ip, $n) {

						// Set the recipient email address.
						$recipient = $email;
						// Set the email subject.
						$subject = $n['info_4'];
						// Build the email headers.
						$email_company 	 = EMAIL_COMPANY;
						$email_headers   = array();
						$email_headers[] = "MIME-Version: 1.0";
						$email_headers[] = "Content-Transfer-Encoding: 8bit";
						$email_headers[] = "Content-type: text/html; charset=utf-8";
						$email_headers[] = "From: BABOKI.COM - NEWSLETTER <$email_company>";
						$headers[] 		 = "X-Mailer: PHP/".phpversion();

						// Select form DB
						$sql = "SELECT * FROM ".DB_PREFIX."_newsletter where email='$email'";
					    $statement = $this->connectToNewsletter()->prepare($sql);
					    $statement->execute();
					    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

						if (empty($answer)) {	// Nowe email
							
							// Build the email content.
							$email_content = "
							    <html><head><title>BABOKI.COM</title><style>body,div,p,ul{font-family:Arial,Sans;font-size:15px;color:#333;line-height:150%}a{color:#333;text-decoration:none}a:hover,a:focus{color:#7c7cff;text-decoration:none}.tlo {background-position: center top;background-repeat: no-repeat;height: 160px;background-color: #8383ff;color:#fff;}.tlo a:hover,a:focus{color:#7c7cff;text-decoration:none}.btn{-webkit-border-radius:0;-moz-border-radius:0;border-radius:0;font-family:Arial;color:#3d3d63;font-size:20px;background:#fff;padding:10px 20px 10px 20px;text-decoration:none;float:right;margin-right:30px}.btn:hover{color:#3d3d63;background:#fff;text-decoration:none}ul{list-style:none;padding:0;margin:0}li{padding-left:1em;text-indent:-.7em}li::before{content:'✔ ';color:#7c7cff}</style></head>
							        <body style='background-color: #F9F9F9;'>
							        	<table style='width:615px;'>
							                <tbody>
							                    <tr>
							                        <td>
							                            <table>
							                                <tbody>
							                                    <tr>
							                                        <td>
							                                            <table style='width:100%;min-height:350px'>
							                                                <tbody>
							                                                    <tr class='tlo'>
							                                                        <td align='center'>
							                                                            <h1 style='font-size:52px;color:#fff;line-height:1.1;margin:0px 30px 0 0;text-align:right;'>
							                                                                ".$n['newsletter_h1']."
							                                                            </h1>
							                                                            <br/>
							                                                            <a class='btn' href='https://baboki.com/' rel='nofollow' target='_blank' title='BABOKI.COM'>www.baboki.com</a>
							                                                        </td>
							                                                    </tr>
							                                                </tbody>
							                                            </table>
							                                        </td><td>
							                                    </td></tr>
							                                    <tr>
							                                        <td>
							                                            <table>
							                                                <tbody style='background-color: #FFFFFF;'>
							                                                    <tr>
							                                                        <td>
							                                                            <table border='0' cellpadding='20' cellspacing='0'>
							                                                                <tbody>
							                                                                    <tr>
							                                                                        <td>
							                                                                            <table border='0' cellpadding='0' cellspacing='0'>
							                                                                                <tbody>
							                                                                                    <tr>
							                                                                                        <td>
							                                                                                            <span style='font-size:15px;'>
							                                                                                                <b>".$n['newsletter_about_b']."</b>
							                                                                                                <p>".$n['newsletter_about_p']."</p>
							                                                                                            </span>
							                                                                                        </td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td height='30' style='height: 30px;'>&nbsp;</td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td>
							                                                                                            <span style='font-size:15px;'>
							                                                                                                <b>".$n['newsletter_advantages_b']."</b><br /><br />
							                                                                                                <ul>
							                                                                                                    ".$n['newsletter_advantages_p']."
							                                                                                                </ul>
							                                                                                            </span>
							                                                                                        </td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td height='30'>&nbsp;</td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td>
							                                                                                            <span style='font-size:15px;'>
							                                                                                                <b>".$n['newsletter_create_b']."</b>
							                                                                                                <p>".$n['newsletter_create_p']."</p>
							                                                                                            </span>
							                                                                                        </td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td height='30'>&nbsp;</td>
							                                                                                    </tr>
							                                                                                    <tr>
							                                                                                        <td style='font-size:15px;border:1px dotted #7c7cff;text-align:center;padding:10px;'>
							                                                                                            <span>
							                                                                                                ".$n['newsletter_code_b']."<br /><b style='font-size:25px;'>".$n['newsletter_code_p']."</b>
							                                                                                            </span>
							                                                                                        </td>
							                                                                                    </tr>
							                                                                                </tbody>
							                                                                            </table>
							                                                                        </td>
							                                                                    </tr>
							                                                                </tbody>
							                                                            </table>
							                                                        </td>
							                                                    </tr>
							                                                </tbody>
							                                            </table>
							                                        </td>
							                                    </tr>
							                                    <tr style='color: rgb(143, 143, 143);'>
							                                        <td>
							                                            <small>
							                                                <small>
							                                                    <span>
							                                                        ".$n['newsletter_text_start']." 
							                                                        <a href='".URL.$n['page_name']."/".$email."' rel='nofollow' target='_blank' title=''>".$n['newsletter_text_end']."</a>.
							                                                    </span>
							                                                </small>
							                                            </small>
							                                        </td>
							                                    </tr>
							                                    <tr style='color: rgb(143, 143, 143);'>
							                                        <td>
							                                            <small>
							                                                <small>
							                                                    <span>
							                                                        © ".date("Y")." <a href='https://baboki.com' rel='nofollow' target='_blank' title='BABOKI'>www.baboki.com</a>, ".$n['newsletter_reserved']."
							                                                    </span>
							                                                </small>
							                                            </small>
							                                        </td>
							                                    </tr>
							                                </tbody>
							                            </table>
							                        </td>
							                    </tr>
							                </tbody>
							            </table>
							        </body>
							    </html>
							";

							// Send the email.
							if (mail($recipient, $subject, $email_content, implode("\r\n", $email_headers))) {

								// Info
								echo $n['info_4'];

								// Add to DB
								$deleted = 0;
								$hidden = 0;
								$date_addition = date("Y-m-d");
								$sql = "INSERT INTO ".DB_PREFIX."_newsletter (email, lang, deleted, date_addition, ip, hidden) VALUES (:email, :lang, :deleted, :date_addition, :ip, :hidden)";
								$statement = $this->connectToNewsletter()->prepare($sql);
								$statement->bindParam(":email", $email, PDO::PARAM_STR);
								$statement->bindParam(":lang", $lang, PDO::PARAM_STR);
								$statement->bindParam(":deleted", $deleted, PDO::PARAM_INT);
								$statement->bindParam(":date_addition", $date_addition, PDO::PARAM_STR);
								$statement->bindParam(":ip", $ip, PDO::PARAM_STR);
								$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			    				$statement->execute();

							} else { echo $n['info_3']; }

						} else {	// If email is in the database

							foreach ($answer as $data) {
								
								$hidden = $data['hidden'];

								if ($hidden==1) {

									// Build the email content.
									$email_content = "
									    <html><head><title>BABOKI.COM</title><style>body,div,p,ul{font-family:Arial,Sans;font-size:15px;color:#333;line-height:150%}a{color:#333;text-decoration:none}a:hover,a:focus{color:#7c7cff;text-decoration:none}.tlo {background-position: center top;background-repeat: no-repeat;height: 160px;background-color: #8383ff;color:#fff;}.tlo a:hover,a:focus{color:#7c7cff;text-decoration:none}.btn{-webkit-border-radius:0;-moz-border-radius:0;border-radius:0;font-family:Arial;color:#3d3d63;font-size:20px;background:#fff;padding:10px 20px 10px 20px;text-decoration:none;float:right;margin-right:30px}.btn:hover{color:#3d3d63;background:#fff;text-decoration:none}ul{list-style:none;padding:0;margin:0}li{padding-left:1em;text-indent:-.7em}li::before{content:'✔ ';color:#7c7cff}</style></head>
									        <body style='background-color: #F9F9F9;'>
									        	<table style='width:615px;'>
									                <tbody>
									                    <tr>
									                        <td>
									                            <table>
									                                <tbody>
									                                    <tr>
									                                        <td>
									                                            <table style='width:100%;min-height:350px'>
									                                                <tbody>
									                                                    <tr class='tlo'>
									                                                        <td align='center'>
									                                                            <h1 style='font-size:52px;color:#fff;line-height:1.1;margin:0px 30px 0 0;text-align:right;'>
									                                                                ".$n['newsletter_h1']."
									                                                            </h1>
									                                                            <br/>
									                                                            <a class='btn' href='https://baboki.com/' rel='nofollow' target='_blank' title='BABOKI.COM'>www.baboki.com</a>
									                                                        </td>
									                                                    </tr>
									                                                </tbody>
									                                            </table>
									                                        </td><td>
									                                    </td></tr>
									                                    <tr>
									                                        <td>
									                                            <table>
									                                                <tbody style='background-color: #FFFFFF;'>
									                                                    <tr>
									                                                        <td>
									                                                            <table border='0' cellpadding='20' cellspacing='0'>
									                                                                <tbody>
									                                                                    <tr>
									                                                                        <td>
									                                                                            <table border='0' cellpadding='0' cellspacing='0'>
									                                                                                <tbody>
									                                                                                    <tr>
									                                                                                        <td>
									                                                                                            <span style='font-size:15px;'>
									                                                                                                <b>".$n['newsletter_about_b']."</b>
									                                                                                                <p>".$n['newsletter_about_p']."</p>
									                                                                                            </span>
									                                                                                        </td>
									                                                                                    </tr>
									                                                                                    <tr>
									                                                                                        <td height='30' style='height: 30px;'>&nbsp;</td>
									                                                                                    </tr>
									                                                                                    <tr>
									                                                                                        <td>
									                                                                                            <span style='font-size:15px;'>
									                                                                                                <b>".$n['newsletter_advantages_b']."</b><br /><br />
									                                                                                                <ul>
									                                                                                                    ".$n['newsletter_advantages_p']."
									                                                                                                </ul>
									                                                                                            </span>
									                                                                                        </td>
									                                                                                    </tr>
									                                                                                    <tr>
									                                                                                        <td height='30'>&nbsp;</td>
									                                                                                    </tr>
									                                                                                    <tr>
									                                                                                        <td>
									                                                                                            <span style='font-size:15px;'>
									                                                                                                <b>".$n['newsletter_create_b']."</b>
									                                                                                                <p>".$n['newsletter_create_p']."</p>
									                                                                                            </span>
									                                                                                        </td>
									                                                                                    </tr>
									                                                                                </tbody>
									                                                                            </table>
									                                                                        </td>
									                                                                    </tr>
									                                                                </tbody>
									                                                            </table>
									                                                        </td>
									                                                    </tr>
									                                                </tbody>
									                                            </table>
									                                        </td>
									                                    </tr>
									                                    <tr style='color: rgb(143, 143, 143);'>
									                                        <td>
									                                            <small>
									                                                <small>
									                                                    <span>
									                                                        ".$n['newsletter_text_start']." 
									                                                        <a href='".URL.$n['page_name']."/".$email."' rel='nofollow' target='_blank' title=''>".$n['newsletter_text_end']."</a>.
									                                                    </span>
									                                                </small>
									                                            </small>
									                                        </td>
									                                    </tr>
									                                    <tr style='color: rgb(143, 143, 143);'>
									                                        <td>
									                                            <small>
									                                                <small>
									                                                    <span>
									                                                        © ".date("Y")." <a href='https://baboki.com' rel='nofollow' target='_blank' title='BABOKI'>www.baboki.com</a>, ".$n['newsletter_reserved']."
									                                                    </span>
									                                                </small>
									                                            </small>
									                                        </td>
									                                    </tr>
									                                </tbody>
									                            </table>
									                        </td>
									                    </tr>
									                </tbody>
									            </table>
									        </body>
									    </html>
									";

									// Send the email.
									if (mail($recipient, $subject, $email_content, implode("\r\n", $email_headers))) {
										
										// Info
										echo $n['info_4'];
										
										// Update in DB
										$hidden = 0;
										$date_addition = date("Y/m/d");
										$sql = "UPDATE ".DB_PREFIX."_newsletter SET hidden = :hidden, lang = :lang, date_addition = :date_addition, ip = :ip WHERE email = :email";
										$statement = $this->connectToNewsletter()->prepare($sql);
										$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
										$statement->bindParam(":lang", $lang, PDO::PARAM_STR);
										$statement->bindParam(":date_addition", $date_addition, PDO::PARAM_STR);
										$statement->bindParam(":ip", $ip, PDO::PARAM_STR);
										$statement->bindParam(":email", $email, PDO::PARAM_STR);
					    				$statement->execute();

									} else { echo $n['info_3']; }

								} else { echo $n['info_2']; }

							}
						}
					}
				}

				$getNewsletter = new Newsletter();
				$getNewsletter->checkNewsletter($email, $lang, $ip, $n);

			} else { echo $n['info_3']; }
		} else { echo $n['info_1']; }
	} else { header('Location: https://'.$_SERVER['HTTP_HOST']); }