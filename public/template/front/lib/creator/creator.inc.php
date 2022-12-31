<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */
 	
	require_once ('../../../../../app/core/db.inc');
	require_once ('../../../../../app/core/defines.inc');
	
	class CreatorController extends db {

		private function add($id_product, $name_product, $ref_product, $price, $b_color, $b_eyes, $b_mimicry, $b_ears, $b_face, $b_nose, $b_handle, $b_accessories) {
			array_push($_SESSION['cart'], array($id_product, $name_product, $ref_product, $price, 1));
			array_push($_SESSION['cart_info'], array($b_color, $b_eyes, $b_mimicry, $b_ears, $b_face, $b_nose, $b_handle, $b_accessories));
		}

		public function getProduct($id_product, $b_color, $b_eyes, $b_mimicry, $b_ears, $b_face, $b_nose, $b_handle, $b_accessories) {
			$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE id_product='$id_product'";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answer) ) {
				foreach ($answer as $data) {
					// Data
					$id_product = $data['id_product'];
					$name_product = $data['name_product'];
					$ref_product = $data['ref_product'];
					$price = $data['price'];
					$promo_product = $data['promo_product'];
					$hidden = $data['hidden'];
					// Checks if there is a promotion for a given product
					if ($promo_product > 0) {$price = $promo_product;}
					$this->add($id_product, $name_product, $ref_product, $price, $b_color, $b_eyes, $b_mimicry, $b_ears, $b_face, $b_nose, $b_handle, $b_accessories);
				}
			}
		}

	}

	session_start();

	if (empty($_SESSION['cart'])) {$_SESSION['cart'] = array();}
	if (empty($_SESSION['cart_info'])) {$_SESSION['cart_info'] = array();}

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		
		$id_product = $_POST['product'];
		$lang = $_POST['lang'];

		/* 1 b_color */
		$b_color = '';
		if (isset($_POST['form_check_color_1'])) {$b_color = $_POST['form_check_color_1'];}
		/* 2 b_eyes */
		$b_eyes = '';
		if (isset($_POST['form_check_eyes_1'])) {$b_eyes = $_POST['form_check_eyes_1'] ;}
		/* 3 b_mimicry */
		$b_mimicry = '';
		if (isset($_POST['form_check_mimicry_1'])) {$b_mimicry = $_POST['form_check_mimicry_1'];}
		/* 4 b_ears */
		$b_ears = '';
		if (isset($_POST['form_check_ears_1'])) {$b_ears = $_POST['form_check_ears_1'];}
		/* 5 b_face */
		$b_face = '';
		if (isset($_POST['form_check_face_1'])) {$b_face = $_POST['form_check_face_1'];}
		/* 6 b_nose */
		$b_nose = '';
		if (isset($_POST['form_check_nose_1'])) {$b_nose = $_POST['form_check_nose_1'];}
		/* 7 b_handle */
		$b_handle = '';
		if (isset($_POST['form_check_handle_1'])) {$b_handle = $_POST['form_check_handle_1'];}
		/* 8 b_accessories */
		$b_accessories = '';
		@$form_check_accessories = $_POST['form_check_accessories'];
		if (empty($form_check_accessories)) {$b_accessories = '';} else {
			$N = count($form_check_accessories);
			for ($i=0; $i < $N; $i++) {$b_accessories .= $form_check_accessories[$i].'|';}
		}
		
		$getCreatorController = new CreatorController();
		$getCreatorController->getProduct($id_product, $b_color, $b_eyes, $b_mimicry, $b_ears, $b_face, $b_nose, $b_handle, $b_accessories);

		if ($lang == 'pl') {header('Location: '. URL . 'koszyk'); exit;} else {header('Location: '. URL . 'cart'); exit;}
		
	}