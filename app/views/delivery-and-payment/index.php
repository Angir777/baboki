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
	// menu shop block in dev
    if ((DEV == true) && ($_SESSION['user']['logged'] != true)) {header('Location: '.URL);}
	//form
	if (($_SERVER["REQUEST_METHOD"] == "POST") AND (!empty($_SESSION['cart']))) {
		// errors
		$errors = array();
		// language
		$c = [];
		if ($lang == 'pl') {
			$c['info_1'] = 'Podaj prawidłowy numer telefonu.';
			$c['info_2'] = 'Wiadomość jest za krótka.';
		} else {
			$c['info_1'] = 'Please enter a valid phone number.';
			$c['info_2'] = 'The message is too short.';
		}
		// k24_tel
		if (empty($_POST['k24_tel'])) { 	
		} else { 
			if(!filter_var($_POST['k24_tel'], FILTER_VALIDATE_INT) || strlen($_POST['k24_tel']) < 6) {
				$errors['k24_tel'] = $c['info_1']; 
			} else { 
				$k24_tel = check_inputs($_POST['k24_tel']); 
			} 
		}
		if (empty($_POST['k24_notes'])) {	
		} else { 
			if (strlen($_POST['k24_notes']) < 10) { 
				$errors['k24_notes'] = $c['info_2'];
			} else { 
				$k24_notes = check_inputs($_POST['k24_notes']); 
			} 
		}
		if (empty($errors)) {
			// data
			$_SESSION['confirmation_form']['k24_nazwa'] 				= check_inputs($_POST['k24_nazwa']);
 			$_SESSION['confirmation_form']['k24_email'] 				= check_inputs($_POST['k24_email']);
 			$_SESSION['confirmation_form']['k24_tel'] 					= check_inputs($_POST['k24_tel']);
			
			$_SESSION['confirmation_form']['k24_dostawa'] 				= check_inputs($_POST['k24_dostawa']);
			
			$_SESSION['confirmation_form']['k24_kraj'] 					= check_inputs($_POST['k24_kraj']);
			$_SESSION['confirmation_form']['k24_kod'] 					= check_inputs($_POST['k24_kod']);
			$_SESSION['confirmation_form']['k24_miasto'] 				= check_inputs($_POST['k24_miasto']);
			$_SESSION['confirmation_form']['k24_ulica'] 				= check_inputs($_POST['k24_ulica']);
 			$_SESSION['confirmation_form']['k24_numer_dom'] 			= check_inputs($_POST['k24_numer_dom']);

 			$_SESSION['confirmation_form']['k24_kraj2'] 				= check_inputs($_POST['k24_kraj2']);
			$_SESSION['confirmation_form']['k24_kod2'] 					= check_inputs($_POST['k24_kod2']);
			$_SESSION['confirmation_form']['k24_miasto2'] 				= check_inputs($_POST['k24_miasto2']);
			$_SESSION['confirmation_form']['k24_ulica2'] 				= check_inputs($_POST['k24_ulica2']);
 			$_SESSION['confirmation_form']['k24_numer_dom2'] 			= check_inputs($_POST['k24_numer_dom2']);

		    $_SESSION['confirmation_form']['k24_platnosc'] 				= check_inputs($_POST['k24_platnosc']);
		    $_SESSION['confirmation_form']['k24_notes'] 				= check_inputs($_POST['k24_notes']);
		    
		    $_SESSION['confirmation_form']['k24_invoice'] 				= check_inputs($_POST['invoice']);
		    $_SESSION['confirmation_form']['k24_invoice-company-name'] 	= check_inputs($_POST['invoice-company-name']);
		    $_SESSION['confirmation_form']['k24_invoice-company-nip'] 	= check_inputs($_POST['invoice-company-nip']);
		    $_SESSION['confirmation_form']['k24_regulamin'] 			= check_inputs($_POST['regulamin']);

		    $_SESSION['confirmation_form']['k24_kwota'] 				= check_inputs($_SESSION['courier']);

		    header('Location: '.URL.friendly_url($l['menu_confirmation']));
		}
	} 
	// data 
	if (count($_SESSION['cart']) == 0) {
		unset($_SESSION['courier']);
		header('Location: '.URL.friendly_url($l['menu_cart']));
	} else {
		// total_price
		$total_price = 0.00;
		for ($i = 0; $i < sizeof(@$_SESSION['cart']); $i++) {
			$actual_price = $_SESSION['cart'][$i][3]*$_SESSION['cart'][$i][4];
			$total_price += $actual_price;
		}
		// rabat
		$value_rabat = '0';
		$input_chceck = '';
		$need_email = '';
		if (@$_SESSION['client_rabat']['check'] == 'yes') {
			$input_chceck = 'style="border: 1px solid LimeGreen;"';
			$value_rabat = $_SESSION['client_rabat']['price'];
			$create_percent = $value_rabat / 100;
			$convert_percent = $total_price * $create_percent;
			$total_price = $total_price-$convert_percent;
		} elseif (@$_SESSION['client_rabat']['check'] == 'no') {
			$input_chceck = 'style="border: 1px solid Crimson;"';
			$value_rabat = '0';
		} elseif (@$_SESSION['client_rabat']['check'] == 'notcompletely') {
			$input_chceck = 'style="border: 1px solid Orange;"';
			$need_email = 'style="border: 1px solid Crimson;"';
			$value_rabat = '0';
		} else {
			$value_rabat = '0';
		}
		// total_price_format
		$total_price = number_format($total_price,2, '.', '');
		// delivery prices shipping
		$delivery_1 = number_format($l['delivery_personal_cash'],2, '.', ''); 		// Odbiór osobisty
		$delivery_2 = number_format($l['delivery_inpost_cash'],2, '.', ''); 		// Kurier (DPD Polska) - Wysyłka tylko na terenie Polski.
		$delivery_3 = number_format($l['delivery_dpd_cash'],2, '.', '');			// Poczta Polska - Wysyłka tylko na terenie Polski.
		$delivery_4 = number_format($l['delivery_dpd_world_cash'],2, '.', '');		// Poczta Polska - Wysyłka po za terytorium Polski.
		$delivery_5 = number_format($l['delivery_free_cash'],2, '.', '');			// Darmowa dostawa od 150 PLN
	}
	// initiating the model
	$getDeliveryAndPayment = new deliveryAndPayment();
	$showDeliveryAndPayment = $getDeliveryAndPayment->checkOrdersForMonth($lang, $l, $total_price);
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
			<div class="col-xs-4 bs-wizard-step disabled">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_4'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
		</div>
	</div>
</div>
<?php
echo $showDeliveryAndPayment;
if ($showDeliveryAndPayment == FALSE) {
	if (isset($_SESSION['cart_form']['s_k24_dostawa'])) {
		if 		 ($_SESSION['cart_form']['s_k24_dostawa'] == 1) {
			$class1_1 = 'selected-shipping';		$class1_2 = 'save-this-change click-collect-shipping';
			$class2_1 = 'no-selected-shipping';		$class2_2 = 'save-this-change';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$class4_1 = 'no-selected-shipping';		$class4_2 = 'save-this-change';
			$classChecked1 = 'checked';
			$classChecked2 = '';
			$classChecked3 = '';
			$classChecked4 = '';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 2) {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'selected-shipping';		$class2_2 = 'save-this-change click-collect-shipping';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$class4_1 = 'no-selected-shipping';		$class4_2 = 'save-this-change';
			$classChecked1 = '';
			$classChecked2 = 'checked';
			$classChecked3 = '';
			$classChecked4 = '';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 3) {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'no-selected-shipping';		$class2_2 = 'save-this-change';
			$class3_1 = 'selected-shipping';		$class3_2 = 'save-this-change click-collect-shipping';
			$class4_1 = 'no-selected-shipping';		$class4_2 = 'save-this-change';
			$classChecked1 = '';
			$classChecked2 = '';
			$classChecked3 = 'checked';
			$classChecked4 = '';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 4) {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'no-selected-shipping';		$class2_2 = 'save-this-change';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$class4_1 = 'selected-shipping';		$class4_2 = 'save-this-change click-collect-shipping';
			$classChecked1 = '';
			$classChecked2 = '';
			$classChecked3 = '';
			$classChecked4 = 'checked';
		}
	} else {
			$_SESSION['cart_form']['s_k24_dostawa'] = 2;
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'selected-shipping';		$class2_2 = 'save-this-change click-collect-shipping';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$class4_1 = 'no-selected-shipping';		$class4_2 = 'save-this-change';
			$classChecked1 = '';
			$classChecked2 = 'checked';
			$classChecked3 = '';
			$classChecked4 = '';
	}
	if (isset($_SESSION['cart_form']['s_k24_platnosc'])) {
		if 		 ($_SESSION['cart_form']['s_k24_platnosc'] == 1) {
			$class1_1 = 'selected-shipping';		$class1_2 = 'save-this-change click-collect-shipping';
			$class2_1 = 'no-selected-shipping';		$class2_2 = 'save-this-change';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$classChecked1 = 'checked';
			$classChecked2 = '';
			$classChecked3 = '';
		} elseif ($_SESSION['cart_form']['s_k24_platnosc'] == 2) {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'selected-shipping';		$class2_2 = 'save-this-change click-collect-shipping';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$classChecked1 = '';
			$classChecked2 = 'checked';
			$classChecked3 = '';
		} elseif ($_SESSION['cart_form']['s_k24_platnosc'] == 3) {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'no-selected-shipping';		$class2_2 = 'save-this-change';
			$class3_1 = 'selected-shipping';		$class3_2 = 'save-this-change click-collect-shipping';
			$classChecked1 = '';
			$classChecked2 = '';
			$classChecked3 = 'checked';
		}
	} else {
			$class1_1 = 'no-selected-shipping';		$class1_2 = 'save-this-change';
			$class2_1 = 'selected-shipping';		$class2_2 = 'save-this-change click-collect-shipping';
			$class3_1 = 'no-selected-shipping';		$class3_2 = 'save-this-change';
			$classChecked1 = '';
			$classChecked2 = 'checked';
			$classChecked3 = '';
	}
?>
		<div class="container single_services text-left">
			<div class="row mt20">
				<div class="col-md-4 col-md-push-8">
					<div id="secureCheckout" class="pdt20">
						<p><span><?= $l['c_5'] ?></span> <i class="fa fa-lock"></i></p>
					</div>
					<div id="clientRabatContent" class="pinside20">
						<div class="input">
							<label for="rabat"><?= $l['c_22'] ?>
								<a href="<?= URL.friendly_url($l['menu_faq']) ?>" target="_blank" class="active"><?= $l['c_23'] ?></a>
							</label>
							<input id="total_rabat" type="hidden" name="chceck_rabat" value="<?= $value_rabat ?>" />
							<input id="rabat" type="text" name="rabat" placeholder="<?= $l['c_26'] ?>" 
								value="<?= @$_SESSION['client_rabat']['code'] ?>" autocomplete="off" <?= @$input_chceck ?> />
							<div class="input-group-addon">
								<button type="submit" class="btn btn-primary" value="true" onclick="return chceck_rabat()"><?= $l['c_24'] ?></button>
							</div>
						</div>
					</div>
				</div>
				<div class="col-md-8 col-md-pull-4 pinside20">
					<div class="row">
						<div class="col-md-12">
							<h2><?= $l['c_3'] ?></h2>
							<div class="divider additional"></div>
							<div class="fieldset">
								<form id="myform" class="contact-shop-form" method="post" action="<?= URL.friendly_url($l['menu_delivery_and_payment']) ?>" name="deliveryform">
									<div id="clientNameWrapp" class="input">
										<label for="k24_nazwa"><?= $l['c_11'] ?>*</label>
										<input id="k24_nazwa" type="text" name="k24_nazwa" value="<?= @$_SESSION['cart_form']['s_k24_nazwa'] ?>" 
											onchange="save_fields(this)" required />
									</div>
									<div id="clientEmailWrapp" class="input">
										<label for="k24_email"><?= $l['c_6'] ?>*</label>
										<input id="k24_email" type="email" name="k24_email" value="<?= @$_SESSION['cart_form']['s_k24_email'] ?>" 
											onchange="multiFunction(this)" <?= @$need_email ?> required />
									</div>
									<div id="clientTelWrapp" class="input">
										<label for="k24_tel"><?= $l['c_7'] ?></label>
										<input id="k24_tel" type="phone" name="k24_tel" value="<?= @$_SESSION['cart_form']['s_k24_tel'] ?>" 
											onchange="save_fields(this)" />
										<?php if(!empty($errors['k24_tel'])){echo '<div class="error-block"><span></span> '.$errors['k24_tel'].'</div>';} ?>
									</div>
<?php 
		echo '
		<div id="shippingOptions" class="">
			<p class="set-title">'.$l['c_8'].'</p>
			<div class="radio-group">
		';

		if (DELIVERY_PERSONAL == true) {
			$type1 = 'radio';
			$dysplayRadio1 = '';
		} else {
			$type1 = 'hidden';
			$dysplayRadio1 = ' style="display:none"';
		}

    	echo '
        <div id="radio_1" class="radio active-shipping '.$class1_1.'"'.$dysplayRadio1.'>
			<input id="delivery_1" type="'.$type1.'" name="k24_dostawa" value="1" onclick="save_fields(this)" class="'.$class1_2.'" 
				onchange="radio_delivery(\''.$delivery_1.'\',1);" '.$classChecked1.' />
			<label for="delivery_1">
				<span>'.$l['delivery_personal_name'].'<br>'.$l['c_25'].'</span>
				<strong>
					<span>
						'.number_format($delivery_1,2, '.', '').$l['delivery_cash'].'
					</span>
				</strong>
				<p class="collect-wrapper">
					<i id="work_open_close" class="collect-indicator"></i>
					<span id="work_shop" class="collect-label"></span>
				</p>
			</label>
		</div>
        ';

		if (DELIVERY_INPOST == true) {
			$type2 = 'radio';
			$dysplayRadio2 = '';
		} else {
			$type2 = 'hidden';
			$dysplayRadio2 = ' style="display:none"';
		}

		echo '
		<div id="radio_2" class="radio active-shipping '.$class2_1.'"'.$dysplayRadio2.'>
			<input id="delivery_2" type="'.$type2.'" name="k24_dostawa" value="2" onclick="save_fields(this)" class="'.$class2_2.'" 
				onchange="radio_delivery(\''.$delivery_2.'\',2);" '.$classChecked2.' />
			<label for="delivery_2">
				<span>'.$l['delivery_inpost_name'].'<br>'.$l['c_9'].'</span>
				<strong>
					<span>
		';
						if($total_price >= $l['delivery_free_cash']){echo 'GRATIS!';}else{echo number_format($delivery_2,2, '.', '').$l['delivery_cash'];}
		echo '
					</span>
				</strong>
			</label>
		</div>
		';

		if (DELIVERY_DPD == true) {
			$type3 = 'radio';
			$dysplayRadio3 = '';
		} else {
			$type3 = 'hidden';
			$dysplayRadio3 = ' style="display:none"';
		}

		echo '
		<div id="radio_3" class="radio active-shipping '.$class3_1.'"'.$dysplayRadio3.'>
			<input id="delivery_3" type="'.$type3.'" name="k24_dostawa" value="3" onclick="save_fields(this)" class="'.$class3_2.'" 
				onchange="radio_delivery(\''.$delivery_3.'\',3);" '.$classChecked3.' />
			<label for="delivery_3">
				<span>'.$l['delivery_dpd_name'].'<br>'.$l['c_27'].'</span>
				<strong>
					<span>
		';
						if($total_price >= $l['delivery_free_cash']){echo 'GRATIS!';}else{echo number_format($delivery_3,2, '.', '').$l['delivery_cash'];}
		echo '
					</span>
				</strong>
			</label>
		</div>
		';
		
		if (DELIVERY_DPD_WORLD == true) {
			$type4 = 'radio';
			$dysplayRadio4 = '';
		} else {
			$type4 = 'hidden';
			$dysplayRadio4 = ' style="display:none"';
		}

		echo '
		<div id="radio_4" class="radio active-shipping '.$class4_1.'"'.$dysplayRadio4.'>
			<input id="delivery_4" type="'.$type4.'" name="k24_dostawa" value="4" onclick="save_fields(this)" class="'.$class4_2.'" 
				onchange="radio_delivery(\''.$delivery_4.'\',4);" '.$classChecked4.' />
			<label for="delivery_4">
				<span>'.$l['delivery_dpd_world_name'].'<br>'.$l['c_10'].'</span>
				<strong>
					<span>
						'.number_format($delivery_4,2, '.', '').$l['delivery_cash'].'
					</span>
				</strong>
			</label>
		</div>

		</div>
	</div>
	';
	//if ($lang == 'pl') {
		echo '
			<div id="deliveryForm1" style="display:none;">
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_kraj">'.$l['c_12'].'</label>
						<input id="k24_kraj" type="text" name="k24_kraj" value="Polska" placeholder="Polska" readonly />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_kod">'.$l['c_15'].'*</label>
						<input id="k24_kod" type="text" name="k24_kod" value="'.@$_SESSION['cart_form']['s_k24_kod'].'" onchange="save_fields(this)" pattern="^\d{2}-\d{3}$" placeholder="" required />
					</div>
				</div>
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_miasto">'.$l['c_35'].'*</label>
						<input id="k24_miasto" type="text" name="k24_miasto" value="'.@$_SESSION['cart_form']['s_k24_miasto'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_ulica">'.$l['c_36'].'</label>
						<input id="k24_ulica" type="text" name="k24_ulica" value="'.@$_SESSION['cart_form']['s_k24_ulica'].'" onchange="save_fields(this)" placeholder="" />
					</div>
				</div>
				<div class="input-group">
					<div id="group_two" class="input ">
						<label for="k24_numer_dom">'.$l['c_37'].'*</label>
						<input id="k24_numer_dom" type="text" name="k24_numer_dom" value="'.@$_SESSION['cart_form']['s_k24_numer_dom'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
				</div>
			</div>
			<div id="deliveryForm2" style="display:none;">
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_kraj2">'.$l['c_12'].'</label>
						<input id="k24_kraj2" type="text" name="k24_kraj2" value="'.@$_SESSION['cart_form']['s_k24_kraj2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_kod2">'.$l['c_15'].'*</label>
						<input id="k24_kod2" type="text" name="k24_kod2" value="'.@$_SESSION['cart_form']['s_k24_kod2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
				</div>
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_miasto2">'.$l['c_35'].'*</label>
						<input id="k24_miasto2" type="text" name="k24_miasto2" value="'.@$_SESSION['cart_form']['s_k24_miasto2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_ulica2">'.$l['c_36'].'</label>
						<input id="k24_ulica2" type="text" name="k24_ulica2" value="'.@$_SESSION['cart_form']['s_k24_ulica2'].'" onchange="save_fields(this)" placeholder="" />
					</div>
				</div>
				<div class="input-group">
					<div id="group_two" class="input ">
						<label for="k24_numer_dom2">'.$l['c_37'].'*</label>
						<input id="k24_numer_dom2" type="text" name="k24_numer_dom2" value="'.@$_SESSION['cart_form']['s_k24_numer_dom2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
				</div>
			</div>
		';
	/*} else {
		echo '
			<div id="deliveryForm2" style="display:block;">
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_kraj2">'.$l['c_12'].'</label>
						<input id="k24_kraj2" type="text" name="k24_kraj2" value="'.@$_SESSION['cart_form']['s_k24_kraj2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_kod2">'.$l['c_15'].'*</label>
						<input id="k24_kod2" type="text" name="k24_kod2" value="'.@$_SESSION['cart_form']['s_k24_kod2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
				</div>
				<div class="input-group">
					<div id="group_one" class="input ">
						<label for="k24_miasto2">'.$l['c_35'].'*</label>
						<input id="k24_miasto2" type="text" name="k24_miasto2" value="'.@$_SESSION['cart_form']['s_k24_miasto2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
					<div id="group_two" class="input ">
						<label for="k24_ulica2">'.$l['c_36'].'*</label>
						<input id="k24_ulica2" type="text" name="k24_ulica2" value="'.@$_SESSION['cart_form']['s_k24_ulica2'].'" onchange="save_fields(this)" placeholder="" />
					</div>
				</div>
				<div class="input-group">
					<div id="group_two" class="input ">
						<label for="k24_numer_dom2">'.$l['c_37'].'*</label>
						<input id="k24_numer_dom2" type="text" name="k24_numer_dom2" value="'.@$_SESSION['cart_form']['s_k24_numer_dom2'].'" onchange="save_fields(this)" placeholder="" required />
					</div>
				</div>
			</div>
		';
	}*/
?>
									<div id="paymentMethod" class="">
										<p class="set-title"><?= $l['c_38'] ?></p>
										<div class="radio-group">
<?php 
										if (PAYMENT_HAND == true && $lang == 'pl') {
											echo '
											<div id="radio_5" class="radio active-shipping '.$class1_1.'">
												<input id="payment_1" type="radio" name="k24_platnosc" value="1" onclick="save_fields(this)" class="'.$class1_2.'" onchange="radio_payment(this);" '.$classChecked1.' />
												<label for="payment_1">
													<span>'.$l['c_39'].'</span>
												</label>
											</div>
											';
										}
										if (PAYMENT_TRANSFER == true) {
											echo '
											<div id="radio_6" class="radio active-shipping '.$class2_1.'">
												<input id="payment_2" type="radio" name="k24_platnosc" value="2" onclick="save_fields(this)" class="'.$class2_2.'" 
													onchange="radio_payment(this);" '.$classChecked2.' />
												<label for="payment_2"><span>'.$l['c_40'].'</span></label>
											</div>
											';
										}
										if (PAYMENT_PRZELEWY24 == true) {
											echo '
											<div id="radio_7" class="radio active-shipping '.$class3_1.'">
												<input id="payment_3" type="radio" name="k24_platnosc" value="3" onclick="save_fields(this)" class="'.$class3_2.'" 
													onchange="radio_payment(this);" '.$classChecked3.' />
												<label for="payment_3"><span>'.$l['c_41'].'</span></label>
											</div>
											';
										}
?>	
										</div>
									</div>
									<div id="clientOrderMessage" class="input">
										<label for="k24_notes"><?= $l['c_17'] ?></label>
										<div class="notes2">
											<textarea id="k24_notes" name="k24_notes" cols="30" rows="1" 
												onchange="save_fields(this)"><?= @$_SESSION['cart_form']['s_k24_notes'] ?></textarea>
											<?php if(!empty($errors['k24_notes'])){echo '<div class="error-block"><span></span> '.$errors['k24_notes'].'</div>';} ?>
										</div>
									</div>
									<div class="group box">
										<label for="invoice">
											<input type="checkbox" id="invoice" name="invoice">
											<?= $l['c_30'] ?>
										</label>
									</div>
									<div id="invoice_field" style="display:none;">
										<div class="input group">
											<label><?= $l['c_31'] ?></label>
											<input id="invoice-company-name" name="invoice-company-name" type="text" value="<?= @$_SESSION['cart_form']['s_invoice-company-name'] ?>" 
												onchange="save_fields(this)" class="input" required="" disabled="">
										</div>
										<div class="input group">
											<label><?= $l['c_33'] ?></label>
											<input id="invoice-company-nip" name="invoice-company-nip" type="number" value="<?= @$_SESSION['cart_form']['s_invoice-company-nip'] ?>" 
												onchange="save_fields(this)" class="input" required="" disabled="">
										</div>
									</div>
									<div class="group box">
										<label for="regulamin">
											<input type="checkbox" id="regulamin" name="regulamin" required>
											<?= $l['c_28'] ?> <a href="<?= URL.friendly_url($l['menu_regulations']) ?>" target="_blank" title="<?= $l['menu_regulations'] ?>"> <?= $l['c_29'] ?></a>.
										</label>
									</div>
									<hr />
									<span id="total_price_basic" style="display:none;"><?= $total_price ?></span>
									<b><?= $l['c_19'] ?> <span id="total_price"><?= $total_price ?></span><?= $l['delivery_cash'] ?></b>
									<button class="btn btn-primary btn-lg mt20"><?= $l['c_18'] ?></button>
								</form>
							</div>
						</div>
					</div>
					<div class="row">
						<div class="col-md-12 text-lg-left text-sm-left text-left mb30">
							<hr />
							<a href="<?= URL.friendly_url($l['menu_cart']) ?>" title="<?= $l['c_20'] ?>">
								<i class="fa fa-angle-left" style="font-weight:bold;"></i> <?= $l['c_20'] ?>
							</a>
						</div>
					</div>
				</div>
			</div>
		</div>
<?php 
//if ($lang == 'pl') {
	// frist load page
	if (		$_SESSION['cart_form']['s_k24_dostawa'] == 1) {
		echo '
			<script>
				// display Form1 and Form2
				setTimeout(function(){
					document.getElementById("deliveryForm1").style.display = "block";
					document.getElementById("deliveryForm2").style.display = "none";
				}, 200);
				// price
				var price_courier = '.$delivery_1.';
				var total_price_basic = document.getElementById("total_price_basic");
				var total = parseFloat(total_price_basic.innerHTML);
				var total = total.toFixed(2); 
				var total_price = document.getElementById("total_price");
				total=eval(total);
				price_courier=eval(price_courier);
				// free delivery 150 PLN
				if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
					var price = total;
				} else {
					var price = total+price_courier;
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();
			</script>
		';
	} elseif (	$_SESSION['cart_form']['s_k24_dostawa'] == 2) {
		echo '
			<script>
				// display Form1 and Form2
				setTimeout(function(){
					document.getElementById("deliveryForm1").style.display = "block";
					document.getElementById("deliveryForm2").style.display = "none";
				}, 200);
				// price
				var price_courier = '.$delivery_2.';
				var total_price_basic = document.getElementById("total_price_basic");
				var total = parseFloat(total_price_basic.innerHTML);
				var total = total.toFixed(2); 
				var total_price = document.getElementById("total_price");
				total=eval(total);
				price_courier=eval(price_courier);
				// free delivery 150 PLN
				if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
					var price = total;
				} else {
					var price = total+price_courier;
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();
			</script>
		';
	} elseif (	$_SESSION['cart_form']['s_k24_dostawa'] == 3) {
		echo '
			<script>
				// display Form1 and Form2
				setTimeout(function(){
					document.getElementById("deliveryForm1").style.display = "block";
					document.getElementById("deliveryForm2").style.display = "none";
				}, 200);
				// price
				var price_courier = '.$delivery_3.';
				var total_price_basic = document.getElementById("total_price_basic");
				var total = parseFloat(total_price_basic.innerHTML);
				var total = total.toFixed(2); 
				var total_price = document.getElementById("total_price");
				total=eval(total);
				price_courier=eval(price_courier);
				// free delivery 150 PLN
				if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
					var price = total;
				} else {
					var price = total+price_courier;
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();
			</script>
		';
	} elseif (	$_SESSION['cart_form']['s_k24_dostawa'] == 4) {
		echo '
			<script>
				// display Form1 and Form2
				setTimeout(function(){
					document.getElementById("deliveryForm1").style.display = "none";
					document.getElementById("deliveryForm2").style.display = "block";
				}, 200);
				// price
				var price_courier = '.$delivery_4.';
				var total_price_basic = document.getElementById("total_price_basic");
				var total = parseFloat(total_price_basic.innerHTML);
				var total = total.toFixed(2); 
				var total_price = document.getElementById("total_price");
				total=eval(total);
				price_courier=eval(price_courier);
				// free delivery 150 PLN
				if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
					var price = total;
				} else {
					var price = total+price_courier;
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();
			</script>
		';
	}
	echo '
		<script>
			// Check rabat
			function chceck_rabat(input) {
				var text_rabat = document.getElementById("rabat").value;
				var email_rabat = document.getElementById("k24_email").value;
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/check_rabat/check_rabat.inc.php?pass=1&text_rabat="+text_rabat+"&email_rabat="+email_rabat, true);
				xhttp.send();
				setTimeout(function(){
					window.location.reload(true);
				}, 1000);
			}
			// Add FV
			document.getElementById("invoice").onchange = function() {
				document.getElementById("invoice_field").style.display = this.checked ? "block" : "none";
				if($(this).is(":checked")) {
					document.getElementById("invoice-company-name").required = true;
					document.getElementById("invoice-company-name").disabled = false;
					document.getElementById("invoice-company-nip").required = true;
					document.getElementById("invoice-company-nip").disabled = false;
				} else {
					document.getElementById("invoice-company-name").required = false;
					document.getElementById("invoice-company-name").disabled = true;
					document.getElementById("invoice-company-nip").required = false;
					document.getElementById("invoice-company-nip").disabled = true;
				}
			};
			// Sposób dostawy
			function radio_delivery(worth,mode){
				if (mode==1) {
	';
	if (DELIVERY_PERSONAL == true) {
		echo '
					// display Form1 and Form2
					setTimeout(function(){
						document.getElementById("deliveryForm1").style.display = "none";
						document.getElementById("deliveryForm2").style.display = "none";
					}, 200);
					// delivery
					document.getElementById("radio_1").className = "no-selected-shipping";
					document.getElementById("radio_2").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_3").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_4").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_1").className = "radio active-shipping selected-shipping";
					// files required
					document.getElementById("k24_kraj").required = false;
					document.getElementById("k24_kod").required = false;
					document.getElementById("k24_miasto").required = false;
					//document.getElementById("k24_ulica").required = false;
					document.getElementById("k24_numer_dom").required = false;
						document.getElementById("k24_kraj2").required = false;
						document.getElementById("k24_kod2").required = false;
						document.getElementById("k24_miasto2").required = false;
						//document.getElementById("k24_ulica2").required = false;
						document.getElementById("k24_numer_dom2").required = false;
					// files disabled
					document.getElementById("k24_kraj").disabled = true;
					document.getElementById("k24_kod").disabled = true;
					document.getElementById("k24_miasto").disabled = true;
					//document.getElementById("k24_ulica").disabled = true;
					document.getElementById("k24_numer_dom").disabled = true;
						document.getElementById("k24_kraj2").disabled = true;
						document.getElementById("k24_kod2").disabled = true;
						document.getElementById("k24_miasto2").disabled = true;
						//document.getElementById("k24_ulica2").disabled = true;
						document.getElementById("k24_numer_dom2").disabled = true;
					// price
					var total_price_basic = document.getElementById("total_price_basic");
					var total = parseFloat(total_price_basic.innerHTML);
					var total = total.toFixed(2); 
					total=eval(total);
					var total_price = document.getElementById("total_price");
					var price = total;
		';
	}
	echo '
				} else if (mode==2) {
					// display Form1 and Form2
					setTimeout(function(){
						document.getElementById("deliveryForm1").style.display = "block";
						document.getElementById("deliveryForm2").style.display = "none";
					}, 200);
					// delivery
					document.getElementById("radio_2").className = "no-selected-shipping";
	';
	if (DELIVERY_PERSONAL == true) {
		echo 'document.getElementById("radio_1").className = "radio active-shipping no-selected-shipping";';
	}
	echo '
					document.getElementById("radio_3").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_4").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_2").className = "radio active-shipping selected-shipping";
					// files required
					document.getElementById("k24_kraj").required = true;
					document.getElementById("k24_kod").required = true;
					document.getElementById("k24_miasto").required = true;
					//document.getElementById("k24_ulica").required = true;
					document.getElementById("k24_numer_dom").required = true;
						document.getElementById("k24_kraj2").required = false;
						document.getElementById("k24_kod2").required = false;
						document.getElementById("k24_miasto2").required = false;
						//document.getElementById("k24_ulica2").required = false;
						document.getElementById("k24_numer_dom2").required = false;
					// files disabled
					document.getElementById("k24_kraj").disabled = false;
					document.getElementById("k24_kod").disabled = false;
					document.getElementById("k24_miasto").disabled = false;
					//document.getElementById("k24_ulica").disabled = false;
					document.getElementById("k24_numer_dom").disabled = false;
						document.getElementById("k24_kraj2").disabled = true;
						document.getElementById("k24_kod2").disabled = true;
						document.getElementById("k24_miasto2").disabled = true;
						//document.getElementById("k24_ulica2").disabled = true;
						document.getElementById("k24_numer_dom2").disabled = true;
					// price
					var price_courier = worth;
					var total_price_basic = document.getElementById("total_price_basic");
					var total = parseFloat(total_price_basic.innerHTML);
					var total = total.toFixed(2); 
					var total_price = document.getElementById("total_price");
					total=eval(total);
					price_courier=eval(price_courier);				
					// free delivery 150 PLN
					if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
						var price = total;
					} else {
						var price = total+price_courier;
					}
				} else if (mode==3) {
					// display Form1 and Form2
					setTimeout(function(){
						document.getElementById("deliveryForm1").style.display = "block";
						document.getElementById("deliveryForm2").style.display = "none";
					}, 200);
					// delivery
					document.getElementById("radio_3").className = "no-selected-shipping";
	';
	if (DELIVERY_PERSONAL == true) {
		echo 'document.getElementById("radio_1").className = "radio active-shipping no-selected-shipping";';
	}
	echo '
					document.getElementById("radio_2").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_4").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_3").className = "radio active-shipping selected-shipping";
					// files required
					document.getElementById("k24_kraj").required = true;
					document.getElementById("k24_kod").required = true;
					document.getElementById("k24_miasto").required = true;
					//document.getElementById("k24_ulica").required = true;
					document.getElementById("k24_numer_dom").required = true;
						document.getElementById("k24_kraj2").required = false;
						document.getElementById("k24_kod2").required = false;
						document.getElementById("k24_miasto2").required = false;
						//document.getElementById("k24_ulica2").required = false;
						document.getElementById("k24_numer_dom2").required = false;
					// files disabled
					document.getElementById("k24_kraj").disabled = false;
					document.getElementById("k24_kod").disabled = false;
					document.getElementById("k24_miasto").disabled = false;
					//document.getElementById("k24_ulica").disabled = false;
					document.getElementById("k24_numer_dom").disabled = false;
						document.getElementById("k24_kraj2").disabled = true;
						document.getElementById("k24_kod2").disabled = true;
						document.getElementById("k24_miasto2").disabled = true;
						//document.getElementById("k24_ulica2").disabled = true;
						document.getElementById("k24_numer_dom2").disabled = true;
					// price
					var price_courier = worth;
					var total_price_basic = document.getElementById("total_price_basic");
					var total = parseFloat(total_price_basic.innerHTML);
					var total = total.toFixed(2); 
					var total_price = document.getElementById("total_price");
					total=eval(total);
					price_courier=eval(price_courier);
					// free delivery 150 PLN
					if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
						var price = total;
					} else {
						var price = total+price_courier;
					}
				} else if (mode==4) {
					// display Form1 and Form2
					setTimeout(function(){
						document.getElementById("deliveryForm1").style.display = "none";
						document.getElementById("deliveryForm2").style.display = "block";
					}, 200);
					// delivery
					document.getElementById("radio_4").className = "no-selected-shipping";
	';
	if (DELIVERY_PERSONAL == true) {
		echo 'document.getElementById("radio_1").className = "radio active-shipping no-selected-shipping";';
	}
	echo '
					document.getElementById("radio_2").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_3").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_4").className = "radio active-shipping selected-shipping";
					// files required
					document.getElementById("k24_kraj").required = false;
					document.getElementById("k24_kod").required = false;
					document.getElementById("k24_miasto").required = false;
					//document.getElementById("k24_ulica").required = false;
					document.getElementById("k24_numer_dom").required = false;
						document.getElementById("k24_kraj2").required = true;
						document.getElementById("k24_kod2").required = true;
						document.getElementById("k24_miasto2").required = true;
						//document.getElementById("k24_ulica2").required = true;
						document.getElementById("k24_numer_dom2").required = true;
					// files disabled
					document.getElementById("k24_kraj").disabled = true;
					document.getElementById("k24_kod").disabled = true;
					document.getElementById("k24_miasto").disabled = true;
					//document.getElementById("k24_ulica").disabled = true;
					document.getElementById("k24_numer_dom").disabled = true;
						document.getElementById("k24_kraj2").disabled = false;
						document.getElementById("k24_kod2").disabled = false;
						document.getElementById("k24_miasto2").disabled = false;
						//document.getElementById("k24_ulica2").disabled = false;
						document.getElementById("k24_numer_dom2").disabled = false;
					// price
					var price_courier = worth;
					var total_price_basic = document.getElementById("total_price_basic");
					var total = parseFloat(total_price_basic.innerHTML);
					var total = total.toFixed(2); 
					var total_price = document.getElementById("total_price");
					total=eval(total);
					price_courier=eval(price_courier);
					// free delivery 150 PLN
					if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
						var price = total+price_courier;
					} else {
						var price = total+price_courier;
					}
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();	
			}
			// Sposób płatności
			function radio_payment(sel){
				var mode = sel.value;
				if (mode==1) {
	';
					if (PAYMENT_HAND == true && $lang == 'pl') {
						echo '
							document.getElementById("radio_5").className = "radio active-shipping selected-shipping";
							document.getElementById("radio_6").className = "radio active-shipping no-selected-shipping";
							document.getElementById("radio_7").className = "radio active-shipping no-selected-shipping";
						';
					}
	echo '
				} else if (mode==2) {
	';
					if (PAYMENT_HAND == true && $lang == 'pl') {echo 'document.getElementById("radio_5").className = "radio active-shipping no-selected-shipping";';}
	echo '
					document.getElementById("radio_6").className = "radio active-shipping selected-shipping";
					document.getElementById("radio_7").className = "radio active-shipping no-selected-shipping";
				} else if (mode==3) {
	';
					if (PAYMENT_HAND == true && $lang == 'pl') {echo 'document.getElementById("radio_5").className = "radio active-shipping no-selected-shipping";';}
	echo '
					document.getElementById("radio_6").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_7").className = "radio active-shipping selected-shipping";
				}
			}
			// Otwarty / zamknięty sklep
			var czas = new Date;
			var dzien = czas.getDay();
			var godz = czas.getHours();
			if (dzien!=6 && dzien!=0 && godz>=9 && godz<17) {
				document.getElementById("work_shop").textContent = "Otwarte dziś [09:00-17:00]";
			} else {
				document.getElementById("work_shop").textContent = "Teraz zamknięte [09:00-17:00]";
				document.getElementById("work_open_close").className = "collect-indicator closed";
			}
			// Dostawa
			//radio_delivery(\'13.99\',2);
	';
	if (isset($_SESSION['cart_form']['s_k24_dostawa'])) {
		if 		 ($_SESSION['cart_form']['s_k24_dostawa'] == 1) {
			echo 'radio_delivery(\''.$delivery_1.'\',1);';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 2) {
			echo 'radio_delivery(\''.$delivery_2.'\',2);';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 3) {
			echo 'radio_delivery(\''.$delivery_3.'\',3);';
		} elseif ($_SESSION['cart_form']['s_k24_dostawa'] == 4) {
			echo 'radio_delivery(\''.$delivery_4.'\',4);';
		}
	} else {
			echo 'radio_delivery(\''.$delivery_2.'\',2);';
	}
	echo '
		</script>
	';
/*} else {
	echo '
		<script>
			// Check rabat
			function chceck_rabat(input) {
				var text_rabat = document.getElementById("rabat").value;
				var email_rabat = document.getElementById("k24_email").value;
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/check_rabat/check_rabat.inc.php?pass=1&text_rabat="+text_rabat+"&email_rabat="+email_rabat, true);
				xhttp.send();
				setTimeout(function(){
					window.location.reload(true);
				}, 1000);
			}
			// Add FV
			document.getElementById("invoice").onchange = function() {
				document.getElementById("invoice_field").style.display = this.checked ? "block" : "none";
				if ($(this).is(":checked")) {
					document.getElementById("invoice-company-name").required = true;
					document.getElementById("invoice-company-name").disabled = false;
					document.getElementById("invoice-company-nip").required = false;
					document.getElementById("invoice-company-nip").disabled = false;
				} else {
					document.getElementById("invoice-company-name").required = false;
					document.getElementById("invoice-company-name").disabled = true;
					document.getElementById("invoice-company-nip").required = false;
					document.getElementById("invoice-company-nip").disabled = true;
				}
			};
			// Courier delivery
			function radio_delivery(worth,mode){
				if (mode==4) {
					document.getElementById("k24_kraj2").required = true;
					document.getElementById("k24_kod2").required = true;
					document.getElementById("k24_miasto2").required = true;
					document.getElementById("k24_ulica2").required = true;
					document.getElementById("k24_numer_dom2").required = true;					
					document.getElementById("k24_kraj2").disabled = false;
					document.getElementById("k24_kod2").disabled = false;
					document.getElementById("k24_miasto2").disabled = false;
					document.getElementById("k24_ulica2").disabled = false;
					document.getElementById("k24_numer_dom2").disabled = false;
					var price_courier = worth;
					var total_price_basic = document.getElementById("total_price_basic");
					var total = parseFloat(total_price_basic.innerHTML);
					var total = total.toFixed(2); 
					var total_price = document.getElementById("total_price");
					total=eval(total);
					price_courier=eval(price_courier);
					if (total >= '.number_format($l['delivery_free_cash'],2, '.', '').') {
						var price = total+price_courier;
					} else {
						var price = total+price_courier;
					}
				}
				var roundedPrice = price.toFixed(2); 
				total_price.innerHTML = roundedPrice;
				var total_p = price.toFixed(2);
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/shop/shop.inc.php?pass=4&totalprince="+total_p, true);
				xhttp.send();
			}
			// Sposób płatności
			function radio_payment(sel){
				var mode = sel.value;
				if (mode==1) {
					//document.getElementById("radio_5").className = "radio active-shipping selected-shipping";
					//document.getElementById("radio_6").className = "radio active-shipping no-selected-shipping";
					//document.getElementById("radio_7").className = "radio active-shipping no-selected-shipping";
				} else if (mode==2) {
					//document.getElementById("radio_5").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_6").className = "radio active-shipping selected-shipping";
					document.getElementById("radio_7").className = "radio active-shipping no-selected-shipping";
				} else if (mode==3) {
					//document.getElementById("radio_5").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_6").className = "radio active-shipping no-selected-shipping";
					document.getElementById("radio_7").className = "radio active-shipping selected-shipping";
				}
			}
			// Dostawa
			radio_delivery(\''.$delivery_4.'\',4);
		</script>
	';
}*/
?>
<script>
	// chceck rabat
	function multiFunction(name) {
		save_fields(name);
		return chceck_rabat();
	}
	// field save
	function save_fields(name) {
		var name_field = name.getAttribute('name');
		if (name_field == "k24_dostawa" || name_field == "k24_platnosc") {
			var value_field = name.getAttribute('value');
		} else {
			var value_field = document.getElementById(name_field).value;
		}
		var xhttp = new XMLHttpRequest();
		xhttp.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/shop/shop.inc.php?pass=5&value_field="+value_field+"&name_field="+name_field, true);
		xhttp.send();
	}
</script>
<?php } ?>