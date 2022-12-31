<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	// global varables
	global $lang;										// Global language varable
	global $l; 											// Global language array
	// initiating the model
	$getConfirmation = new Confirmation();
	// data
	if (!empty($_SESSION['cart'])) {

		/////////////////////////////////
		// Tworzenie numeru zamówienia //
		/////////////////////////////////

		$showOrderNumber = $getConfirmation->getOrderNumber();
		$order_number = $showOrderNumber;

		////////////////////////////////////////////
		// Odejmowanie kupionych produktów z bazy //
		////////////////////////////////////////////

		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {

			$actual_price = $_SESSION['cart'][$i][3]*$_SESSION['cart'][$i][4];
			$total_price += $actual_price;
			$ref_product = $_SESSION['cart'][$i][2];
			$quantityCart = $_SESSION['cart'][$i][4];
			
			$getConfirmation->updateWarehouse($ref_product, $quantityCart);
			
		}

		///////////////////////
		// Dane              //
		///////////////////////

		
		// Language
		$lang = $_SESSION['lang'];
		
		/*
		// Form
		$_SESSION['confirmation_form']['k24_nazwa'];
		$_SESSION['confirmation_form']['k24_email'];
		$_SESSION['confirmation_form']['k24_tel'];
		
		$_SESSION['confirmation_form']['k24_dostawa'];
		
		$_SESSION['confirmation_form']['k24_kraj'];
		$_SESSION['confirmation_form']['k24_kod'];
		$_SESSION['confirmation_form']['k24_miasto'];
		$_SESSION['confirmation_form']['k24_ulica'];
		$_SESSION['confirmation_form']['k24_numer_dom'];

		$_SESSION['confirmation_form']['k24_kraj2'];
		$_SESSION['confirmation_form']['k24_kod2'];
		$_SESSION['confirmation_form']['k24_miasto2'];
		$_SESSION['confirmation_form']['k24_ulica2'];
		$_SESSION['confirmation_form']['k24_numer_dom2'];

	    $_SESSION['confirmation_form']['k24_platnosc'];
	    $_SESSION['confirmation_form']['k24_notes'];
	    
	    $_SESSION['confirmation_form']['k24_invoice'];
	    $_SESSION['confirmation_form']['k24_invoice-company-name'];
	    $_SESSION['confirmation_form']['k24_invoice-company-nip'];
	    $_SESSION['confirmation_form']['k24_regulamin'];

	    $_SESSION['confirmation_form']['k24_kwota'];

	    // Discount
	    $_SESSION['client_rabat']['code'];
	    $_SESSION['client_rabat']['check'];
	    $_SESSION['client_rabat']['price'];
	    $_SESSION['client_rabat']['type'];

	    // Cart
	    $_SESSION['cart'];
	    $_SESSION['cart_info'];
		*/

	    ////////////////////////////////////////////////////////////////////////
		// Przygotowanie zmiennych do szablonu wiadomości email i bazy danych //											
		////////////////////////////////////////////////////////////////////////

	    if ($_SESSION['client_rabat']['check'] == 'yes') {
			$total_rabat = $_SESSION['client_rabat']['price'];
			$create_percent = $total_rabat / 100;
			$convert_percent = $total_price * $create_percent;
			$total_price = $total_price - $convert_percent;
		}
		$total_price = number_format($total_price,2, '.', '');

		// Delivery
		if (		$_SESSION['confirmation_form']['k24_dostawa']==1 ) {
			
			$shipping_name 		= $l['delivery_personal_name'];
			$delivery_price 	= number_format($l['delivery_personal_cash'],2, '.', '');
			$delivery_method 	= 1;

		} elseif (	$_SESSION['confirmation_form']['k24_dostawa']==2 ) {

			if ($total_price >= $l['delivery_free_cash']) {
				$shipping_name 	= $l['delivery_inpost_name'] .' - '. $l['c_37'];
				$delivery_price	= 0.00;
			} else {
				$shipping_name 	= $l['delivery_inpost_name'];
				$delivery_price	= number_format($l['delivery_inpost_cash'],2, '.', '');
			}
			$delivery_method 	= 2;

		} elseif (	$_SESSION['confirmation_form']['k24_dostawa']==3 ) {
			
			if ($total_price >= $l['delivery_free_cash']) {
				$shipping_name 	= $l['delivery_dpd_name'] .' - '. $l['c_37'];
				$delivery_price	= 0.00;
			} else {
				$shipping_name 	= $l['delivery_dpd_name'];
				$delivery_price	= number_format($l['delivery_dpd_cash'],2, '.', '');
			}
			$delivery_method 	= 3;

		} elseif (	$_SESSION['confirmation_form']['k24_dostawa']==4 ) {

			$shipping_name 		= $l['delivery_dpd_world_name'];
			$delivery_price 	= number_format($l['delivery_dpd_world_cash'],2, '.', '');
			$delivery_method 	= 4;

		}

		// Payment
		if (		$_SESSION['confirmation_form']['k24_platnosc']==1 ) {
			$payment_name = $l['c_44'];
			$payment_method = 1;
		} elseif (	$_SESSION['confirmation_form']['k24_platnosc']==2 ) {
			$payment_name = $l['c_45'];
			$payment_method = 2;
		} elseif (	$_SESSION['confirmation_form']['k24_platnosc']==3 ) {
			$payment_name = $l['c_46'];
			$payment_method = 3;
		}

		// Comment
		$comment = '';
		if (empty($comment)) {$comment = $_SESSION['confirmation_form']['k24_notes'];}

		// Creator
		$create_toy = '';
		for ($j = 0; $j < sizeof($_SESSION['cart']); $j++) {
			if ($_SESSION['cart'][$j][2]=='001') {
				$create_toy .= $_SESSION['cart_info'][$j][0].','.$_SESSION['cart_info'][$j][1].','.$_SESSION['cart_info'][$j][2].','.$_SESSION['cart_info'][$j][3].','.$_SESSION['cart_info'][$j][4].','.$_SESSION['cart_info'][$j][5].','.$_SESSION['cart_info'][$j][6].','.$_SESSION['cart_info'][$j][7].'.';
			} else {
				$create_toy .= 'none.';
			}
		}

		// Info buyer
		$info_buyer = 
		'Imię i nazwisko: '.$_SESSION['confirmation_form']['k24_nazwa'].
		'|Email: '.$_SESSION['confirmation_form']['k24_email'].
		'|Tel: '.$_SESSION['confirmation_form']['k24_tel'].
		'|Kraj: '.$_SESSION['confirmation_form']['k24_kraj'].$_SESSION['confirmation_form']['k24_kraj2'].
		'|Kod: '.$_SESSION['confirmation_form']['k24_kod'].$_SESSION['confirmation_form']['k24_kod2'].
		'|Miasto: '.$_SESSION['confirmation_form']['k24_miasto'].$_SESSION['confirmation_form']['k24_miasto2'].
		'|Ulica: '.$_SESSION['confirmation_form']['k24_ulica'].$_SESSION['confirmation_form']['k24_ulica2'].
		'|Nr domu: '.$_SESSION['confirmation_form']['k24_numer_dom'].$_SESSION['confirmation_form']['k24_numer_dom2'].
		'|Nazwa firmy: '.$_SESSION['confirmation_form']['k24_invoice-company-name'].
		'|NIP: '.$_SESSION['confirmation_form']['k24_invoice-company-nip'];

		// Email buyer
		$email_buyer = $_SESSION['confirmation_form']['k24_email'];

		// Info product
		$info_product = '';
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {
			$info_product .= $_SESSION['cart'][$i][1].','.$_SESSION['cart'][$i][2].','.$_SESSION['cart'][$i][3].','.$_SESSION['cart'][$i][4].'/';
		}

		// Product price
		$product_price = 0;
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {
			$product_price += $_SESSION['cart'][$i][4] * $_SESSION['cart'][$i][3];
		}

		// Discount
		$discount = 0;
		if ($_SESSION['client_rabat']['check'] == 'yes') {
			$discount = $_SESSION['client_rabat']['price'];
		}

		// Cena końcowa
		$total_price = $total_price + $shipping;
		$total_price = number_format($total_price,2, '.', '');
		if (empty($_SESSION['courier'])) {
			if (number_format($_SESSION['confirmation_form']['k24_kwota'],2, '.', '') == $total_price) {
				$_SESSION['courier'] = $total_price;
			}
		}

		///////////////////////////////////////
		// Zaznaczanie wykorzystanego rabatu //											
		/////////////////////////////////////// 

		if ($_SESSION['client_rabat']['type'] == 1) {$getConfirmation->updatePersonalDiscount($_SESSION['client_rabat']['code']);}
		$getConfirmation->updateDisposableDiscount($_SESSION['confirmation_form']['k24_email']);
		
		//////////////////////////////////////
		// Wiadomość o zamówieniu do sklepu //
		//////////////////////////////////////

		$recipient = EMAIL_COMPANY;
		// Set the email subject.
		$subject = 'Zamówienie numer '.$order_number;
		// Build the email content.
		$email_content = "<html><head><title>BABOKI.COM</title><style>body,div,p,ul{font-family:Arial,Sans;font-size:15px;color:#333;line-height:150%}a{color:#333;text-decoration:none}a:hover,a:focus{color:#7c7cff;text-decoration:none}.tlo {background-position: center top;background-repeat: no-repeat;height: 160px;background-color: #8383ff;color:#fff;}</style></head><body style='background-color: #F9F9F9;'><table><tbody><tr><td><table style='width:100%;text-align:left;margin-left:auto;margin-right:auto;'><tbody><tr><td><table width='100%'><tbody><tr class='tlo'><td align='center'><h1 style='font-size:23px;line-height:1.1;margin:20px 0 0 0'>Potwierdzenie zamówienia</h1><br></td></tr></tbody></table></td><td></td></tr><tr><td><table  width='100%' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td style='vertical-align:top;' bgcolor='#fff'><table width='100%' style='text-align:left;width:100%;' border='0' cellpadding='20' cellspacing='0'><tbody><tr><td><table style='font-size:13px;width: 100%;'><tbody><tr><td><span style='font-size:13px;'><b>Zamówienie numer</b>: ".$order_number."<br /><b>Sposób dostawy</b>: ".$shipping_name."<br /><b>Sposób płatności</b>: ".$payment_name."<br />";
		if (!empty($comment)) {$email_content .= "<br /><b>Komentarz do zamówienia</b>:<br /><br /><i>".$comment."</i>";}
		for ($j = 0; $j < sizeof($_SESSION['cart']); $j++) {
			if($_SESSION['cart'][$j][2]=='001'){
				$email_content .= "<br /><b>Własny pluszak</b>:<br /><br />";
				$email_content .= '
				Kolor: '.$_SESSION['cart_info'][$j][0].'<br>
				Oczy: '.$_SESSION['cart_info'][$j][1].'<br>
				Mina: '.$_SESSION['cart_info'][$j][2].'<br>
				Uszy: '.$_SESSION['cart_info'][$j][3].'<br>
				Nosek: '.$_SESSION['cart_info'][$j][5].'<br>
				Twarz: '.$_SESSION['cart_info'][$j][4].'<br>
				Łapki: '.$_SESSION['cart_info'][$j][6].'<br>
				Dodatki: '.$_SESSION['cart_info'][$j][7].'<br><br>';
			}
		}
		$email_content .= "</span></td></tr><tr><td style='height:30px;'><hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><table style='text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td><span style='font-size:13px;font-weight: bold;'>Szczegóły zamówienia:</span></td></tr><tr><td style='height: 15px;'></td></tr><tr><td><small><span style='line-height:120%;'>Dane zamawiającego:</span><br /><br /></small></td></tr><tr><td><table style='text-align:left;width:100%;' border='0' cellpadding='0' cellspacing='4'><tbody><tr><td></td><td><small style='color:rgb(68, 68, 68);font-family Arial;font-size:14px;'>Imię i nazwisko: ".$_SESSION['confirmation_form']['k24_nazwa']."<br />E-mail: ".$_SESSION['confirmation_form']['k24_email']."<br />Tel: ".$_SESSION['confirmation_form']['k24_tel']."<br />Kraj: ".$_SESSION['confirmation_form']['k24_kraj'].$_SESSION['confirmation_form']['k24_kraj2']."<br />Kod: ".$_SESSION['confirmation_form']['k24_kod'].$_SESSION['confirmation_form']['k24_kod2']."<br />Miasto: ".$_SESSION['confirmation_form']['k24_miasto'].$_SESSION['confirmation_form']['k24_miasto2']."<br />Ulica: ".$_SESSION['confirmation_form']['k24_ulica'].$_SESSION['confirmation_form']['k24_ulica2']."<br />Nr domu/mieszkania: ".$_SESSION['confirmation_form']['k24_numer_dom'].$_SESSION['confirmation_form']['k24_numer_dom2']."
			<br />Język: ".$_SESSION['lang']
		;
		if (!empty($_SESSION['confirmation_form']['k24_invoice-company-name'])) {$email_content .= "<br />Nazwa firmy: ".$_SESSION['confirmation_form']['k24_invoice-company-name'];}
		if (!empty($_SESSION['confirmation_form']['k24_invoice-company-nip'])) {$email_content .= "<br />NIP: ".$_SESSION['confirmation_form']['k24_invoice-company-nip'];}
		$email_content .= "</small></td></tr></tbody></table></td></tr><tr><td height='10' style='height:10px;'>&nbsp;</td></tr><tr><td><small><span style='line-height:120%;'>Zakupione produkty:</span><br /><br /></small></td></tr><tr><td><table style='text-align:left;width:100%;' border='0' cellpadding='0' cellspacing='4'><tbody>";
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {
			$email_content .= "<tr><td></td><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial; font-size: 14px;'>".$_SESSION['cart'][$i][1]."</span><br /><span style='font-family: Arial; font-size: 11px;'>REF ".$_SESSION['cart'][$i][2]."</span></small></td>
			<td style='text-align: right;'><small style='color: rgb(68, 68, 68);'>
			<span style='font-family: Arial; font-size: 14px;'>".$_SESSION['cart'][$i][4]." x ".number_format($_SESSION['cart'][$i][3],2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr><tr></tr>";}
		$email_content .= "</tbody></table></td></tr><tr><td style='height:30px;'><hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><table style='width:100%;text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td style='width: 50%; vertical-align: top;'><span style='font-size:13px;font-weight:bold;color: rgb(68, 68, 68);'>Zakupy razem:</span></td><td style='width: 50%;'><table style='text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td><small style='color: rgb(68, 68, 68);'><span>Produkty razem:</span></small></td><td style='text-align: right;'><small><span style='font-family: Arial;'>";
		$products_prince = 0;
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {$products_prince += $_SESSION['cart'][$i][4] * $_SESSION['cart'][$i][3];}
		$email_content .= number_format($products_prince,2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr>";
		if ($_SESSION['client_rabat']['check'] == 'yes') {$email_content .= "<tr><td><small style='color: rgb(68, 68, 68);'><span>Rabat:</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span>".$_SESSION['client_rabat']['price']."%</span></small></td></tr>";}
		$email_content .= "<tr><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial;'>Wysyłka:</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span>".$delivery_price." ".$l['delivery_cash']."</span></small></td></tr><tr><td colspan='2' rowspan='1'>
		<hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial;'>Razem:</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial; font-size: 15px; font-weight: bold;'>".number_format($_SESSION['courier'],2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr></tbody></table></td></tr></tbody></table></td></tr></tbody></table></td></tr></tbody></table><span style='font-family: Arial; color: rgb(51, 51, 51); line-height: 150%;'><br></span><span style='font-family: Arial; color: rgb(51, 51, 51);'>&nbsp;</span></td></tr></tbody></table></td></tr><tr><td><table style='text-align: left; width: 615px; height: 6px;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td width='6' style='width: 6px;'></td><td width='100%' style='width: 100%;'></td><td width='6' style='width: 6px;'></td></tr></tbody></table></td></tr></tbody></table></td></tr><tr style='color: rgb(143, 143, 143);'><td><small><small><span style='font-family: Arial;'>© BABOKI | 2018 - "; $email_content .= date("Y"); $email_content .= " | <a href='".URL."' rel='nofollow' target='_blank' title='BABOKI.COM'>www.baboki.com</a> | Wszelkie prawa zastrzeżone.</span></small></small></td></tr></tbody></table></td></tr></tbody></table></body></html>";
		// Build the email headers.
		$email_headers   = array();
		$email_headers[] = "MIME-Version: 1.0";
		$email_headers[] = "Content-Transfer-Encoding: 8bit";
		$email_headers[] = "Content-type: text/html; charset=utf-8";
		$email_headers[] = "From: ".$_SESSION['confirmation_form']['k24_email'];
		$headers[] = "X-Mailer: PHP/".phpversion();
		// Send the email.
		mail($recipient, $subject, $email_content, implode("\r\n", $email_headers));

		///////////////////////////////////////
		// Wiadomość o zamówieniu do klienta //
		///////////////////////////////////////

		$recipient = $_SESSION['confirmation_form']['k24_email'];
		// Set the email subject.
		$subject = $l['c_26'];
		// Build the email content.
		$email_content2 = "<html><head><title>BABOKI.COM</title><style>body,div,p,ul{font-family:Arial,Sans;font-size:15px;color:#333;line-height:150%}a{color:#333;text-decoration:none}a:hover,a:focus{color:#7c7cff;text-decoration:none}.tlo {background-position: center top;background-repeat: no-repeat;height: 160px;background-color: #8383ff;color:#fff;}</style></head><body style='background-color: #F9F9F9;'><table><tbody><tr><td><table style='width:100%;text-align:left;margin-left:auto;margin-right:auto;'><tbody><tr><td><table width='100%'><tbody><tr class='tlo'><td align='center'><h1 style='font-size:23px;line-height:1.1;margin:20px 0 0 0'>".$l['c_5']."</h1><br></td></tr></tbody></table></td><td></td></tr><tr><td><table  width='100%' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td style='vertical-align:top;' bgcolor='#fff'><table width='100%' style='text-align:left;width:100%;' border='0' cellpadding='20' cellspacing='0'><tbody><tr><td><table style='font-size:13px;width: 100%;'><tbody><tr><td><span style='font-size:13px;'>".$l['c_8']."<b>".$order_number."</b>.<br /><br />".$l['c_15']."<br /><br /><b>".$l['c_11']."</b>: ".$shipping_name."<br /><b>".$l['c_12']."</b>: ".$payment_name."<br />";
		if (!empty($comment)) {$email_content2 .= "<br /><b>".$l['c_6']."</b>:<br /><i>".$comment."</i>";}
		$email_content2 .= "</span></td></tr><tr><td style='height:30px;'><hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><table style='text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td><span style='font-size:13px;font-weight: bold;'>".$l['c_48'].":</span></td></tr><tr><td style='height: 15px;'></td></tr><tr><td><small><span style='line-height:120%;'>".$l['c_19'].":</span><br /><br /></small></td></tr><tr><td><table style='text-align:left;width:100%;' border='0' cellpadding='0' cellspacing='4'><tbody><tr><td></td><td><small style='color:rgb(68, 68, 68);font-family Arial;font-size:14px;'>".$l['c_49'].": ".$_SESSION['confirmation_form']['k24_nazwa']."<br />".$l['c_50'].": ".$_SESSION['confirmation_form']['k24_email']."<br />".$l['c_51'].": ".$_SESSION['confirmation_form']['k24_tel']."<br />".$l['c_52'].": ".$_SESSION['confirmation_form']['k24_kraj'].$_SESSION['confirmation_form']['k24_kraj2']."<br />".$l['c_53'].": ".$_SESSION['confirmation_form']['k24_kod'].$_SESSION['confirmation_form']['k24_kod2']."<br />".$l['c_54'].": ".$_SESSION['confirmation_form']['k24_miasto'].$_SESSION['confirmation_form']['k24_miasto2']."<br />".$l['c_55'].": ".$_SESSION['confirmation_form']['k24_ulica'].$_SESSION['confirmation_form']['k24_ulica2']."<br />".$l['c_56'].": ".$_SESSION['confirmation_form']['k24_numer_dom'].$_SESSION['confirmation_form']['k24_numer_dom2'];
		if (!empty($_SESSION['confirmation_form']['k24_invoice-company-name'])) {$email_content2 .= "<br />".$l['c_57'].": ".$_SESSION['confirmation_form']['k24_invoice-company-name'];}
		if (!empty($_SESSION['confirmation_form']['k24_invoice-company-nip'])) {$email_content2 .= "<br />".$l['c_58'].": ".$_SESSION['confirmation_form']['k24_invoice-company-nip'];}
		$email_content2 .= "</small></td></tr></tbody></table></td></tr><tr><td height='10' style='height:10px;'>&nbsp;</td></tr><tr><td><small><span style='line-height:120%;'>".$l['c_59'].":</span><br /><br /></small></td></tr><tr><td><table style='text-align:left;width:100%;' border='0' cellpadding='0' cellspacing='4'><tbody>";
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {$email_content2 .= "<tr><td></td><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial; font-size: 14px;'>".$_SESSION['cart'][$i][1]."</span><br /><span style='font-family: Arial; font-size: 11px;'>REF ".$_SESSION['cart'][$i][2]."</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial; font-size: 14px;'>".$_SESSION['cart'][$i][4]." x ".number_format($_SESSION['cart'][$i][3],2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr><tr></tr>";}
		$email_content2 .= "</tbody></table></td></tr><tr><td style='height:30px;'><hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><table style='width:100%;text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td style='width: 50%; vertical-align: top;'><span style='font-size:13px;font-weight:bold;color: rgb(68, 68, 68);'>".$l['c_60'].":</span></td><td style='width: 50%;'><table style='text-align: left; width: 100%;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td><small style='color: rgb(68, 68, 68);'><span>".$l['c_22'].":</span></small></td><td style='text-align: right;'><small><span style='font-family: Arial;'>";
		$products_prince = 0;
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {$products_prince += $_SESSION['cart'][$i][4] * $_SESSION['cart'][$i][3];}
		$email_content2 .= number_format($products_prince,2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr>";
		if ($_SESSION['client_rabat']['check'] == 'yes') {$email_content2 .= "<tr><td><small 
		style='color:rgb(68, 68, 68);'><span>".$l['c_39'].":</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span>".$_SESSION['client_rabat']['price']."%</span></small></td></tr>";}
		$email_content2 .= "<tr><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial;'>".$l['c_23'].":</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span>".$delivery_price." ".$l['delivery_cash']."</span></small></td></tr><tr><td colspan='2' rowspan='1'>
		<hr style='height:1px;width:100%;' color='#e0e0e0'></td></tr><tr><td><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial;'>".$l['c_24'].":</span></small></td><td style='text-align: right;'><small style='color: rgb(68, 68, 68);'><span style='font-family: Arial; font-size: 15px; font-weight: bold;'>".number_format($_SESSION['courier'],2, '.', '')." ".$l['delivery_cash']."</span></small></td></tr></tbody></table></td></tr></tbody></table></td></tr></tbody></table></td></tr></tbody></table><span style='font-family: Arial; color: rgb(51, 51, 51); line-height: 150%;'><br></span><span style='font-family: Arial; color: rgb(51, 51, 51);'>&nbsp;</span></td></tr></tbody></table></td></tr><tr><td><table style='text-align: left; width: 615px; height: 6px;' border='0' cellpadding='0' cellspacing='0'><tbody><tr><td width='6' style='width: 6px;'></td><td width='100%' style='width: 100%;'></td><td width='6' style='width: 6px;'></td></tr></tbody></table></td></tr></tbody></table></td></tr><tr style='color: rgb(143, 143, 143);'><td><small><small><span style='font-family: Arial;'>© BABOKI | 2018 - "; $email_content2 .= date("Y"); $email_content2 .= " | <a href='".URL."' rel='nofollow' target='_blank' title='BABOKI.COM'>www.baboki.com</a> | ".$l['c_40'].".</span></small></small></td></tr></tbody></table></td></tr></tbody></table></body></html>";
		// Build the email headers.
		$email_headers   = array();
		$email_headers[] = "MIME-Version: 1.0";
		$email_headers[] = "Content-Transfer-Encoding: 8bit";
		$email_headers[] = "Content-type: text/html; charset=utf-8";
		if ($_SESSION['lang'] == 'pl') {$email_headers[] = "From: SKLEP BABOKI.COM <".EMAIL_COMPANY.">";} else {$email_headers[] = "From: SHOP BABOKI.COM <".EMAIL_COMPANY.">";}
		$headers[] = "X-Mailer: PHP/".phpversion();
		// Send the email.
		mail($recipient, $subject, $email_content2, implode("\r\n", $email_headers));

		/////////////////////////////////////////////////////
		// Wysłanie kopii zamówienia do bazy danych sklepu //
		/////////////////////////////////////////////////////

		$getConfirmation->addNewOrder($order_number, $delivery_method, $delivery_price, $payment_method, $comment, $create_toy, $info_buyer, $email_buyer, $info_product, $product_price, $discount, $_SESSION['courier']);

		////////////////////////////////////////
		// Wyświetlanie informacji na stronie //
		////////////////////////////////////////
?>
<div class="space-medium bg-light">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="section-title">
					<h1><?= $l['c_1'] ?></h1>
					<div class="divider"></div>
				</div>
			</div>
		</div>
		<div class="row bs-wizard" style="border-bottom:0;">
			<div class="col-xs-4 bs-wizard-step complete">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_2'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
			<div class="col-xs-4 bs-wizard-step complete">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_3'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
			<div class="col-xs-4 bs-wizard-step complete">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_4'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
		</div>
	</div>
</div>
<div class="container single_services text-left">
	<div class="row mt40">
		<div class="col-md-12">
			<div class="row">
				<div class="col-md-12">
					<h2><?= $l['c_5'] ?></h2>
					<div class="divider additional"></div>
				</div>
			</div>
			<div class="container single_services text-left">
				<div class="row info-cart-style1 mt30 mb50">
					<div class="col-md-12 text-center">
						<h4><?= $l['c_26'] ?></h4>
						<p>
							<?= $l['c_27'] ?><br>
							<b><?= $order_number ?></b><br>
							<?= $l['c_28'] ?> (<?= $_SESSION['confirmation_form']['k24_email'] ?>)
							<?= $l['c_29'] ?>
							<small><?= $l['c_30'] ?></small>
						</p>
						<p><?= $l['c_31'] ?></p>
					</div>
					<div class="col-md-12 text-center">
						<a href="<?= URL.friendly_url($l['menu_shop']) ?>" class="btn btn-white mt20 hvr-buzz-out" title="<?= $l['c_34'] ?>"><?= $l['c_34'] ?></a>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>
<?php
		////////////////////
		// Usuwanie sesji //
		////////////////////
		
		$_SESSION = array();
		session_destroy();
		session_start();
		$_SESSION['lang'] = $lang;

	} else {
		header('Location: '.URL.friendly_url($l['menu_cart']));
	}
?>