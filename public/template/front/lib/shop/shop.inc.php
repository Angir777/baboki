<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	require_once ('../../../../../app/core/db.inc');
	require_once ('../../../../../app/core/defines.inc');

	class ShopController extends db {

		private function cartCheckProduct($array, $key, $val) {
			foreach ($array as $item)
				if (isset($item[$key]) && $item[$key] == $val)
					return true;
			return false;
		}

		private function searchForName($name, $array){
			foreach($array as $key => $val){
				if($val['1'] === $name)
					return $key;
			}
			return null;
		}

		private function add($id_product, $name_product, $ref_product, $price){			
			$chceckcart = $this->cartCheckProduct($_SESSION['cart'], 1, $name_product);
			if ($chceckcart == false) {
				array_push($_SESSION['cart'], array($id_product, $name_product, $ref_product, $price, 1));
				array_push($_SESSION['cart_info'], array(null, null, null, null, null, null, null, null));
			} else {
				$id = $this->searchForName($name_product, $_SESSION['cart']);
				$_SESSION['cart'][$id][4] = $_SESSION['cart'][$id][4] + 1;
			}
		}

		public function getProduct($lang, $id_product) {
			$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE id_product='$id_product'";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answer) ) {
				foreach ($answer as $data) {
					// data
					$id_product = $data['id_product'];
					$name_product = $data['name_product'];
					$ref_product = $data['ref_product'];
					$price = $data['price'];
					$promo_product = $data['promo_product'];
					$hidden = $data['hidden'];
					// Checks if there is a promotion for a given product
					if($promo_product > 0) {$price = $promo_product;}else{}
					$this->add($id_product, $name_product, $ref_product, $price);
				}
			}

		}

	}

	session_start();

	if (empty($_SESSION['cart'])) {$_SESSION['cart'] = array();}
	if (empty($_SESSION['cart_info'])) {$_SESSION['cart_info'] = array();}
	if (empty($_SESSION['cart_form'])) {$_SESSION['cart_form'] = array();}

	$pass = (int)$_GET['pass'];
	// Adding product to the basket
	if (	$pass == 1) {
		$lang = (string)$_GET['lang'];
		$id_product = (int)$_GET['id_products'];
		$getShopController = new ShopController();
		$getShopController->getProduct($lang, $id_product);
	// Change of quantity and prices
	} elseif($pass == 2) {
		$amount_added = $_GET['amount_added'];
		$id_product_cart = (int)$_GET['id_product_cart'];
		function add_info($id_product_cart, $amount_added) {$_SESSION['cart'][$id_product_cart][4] = $amount_added;}
		add_info($id_product_cart, $amount_added);
	// Remove product from basket
	} elseif($pass == 3) {
		$id_product = (int)$_GET['id_product'];
		array_splice($_SESSION['cart'], $id_product, 1);
		array_splice($_SESSION['cart_info'], $id_product, 1);
		$_SESSION['client_rabat']['code'] = '';
		$_SESSION['client_rabat']['check'] = '';
		$_SESSION['client_rabat']['price'] = '0.00';
		$_SESSION['client_rabat']['type'] = '';
	// The final price
	} elseif($pass == 4) {
		$totalprince = $_GET['totalprince'];
		$_SESSION['courier'] = $totalprince;
	// Field save
	} elseif($pass == 5) {
		$name_field = $_GET['name_field'];
		$value_field = $_GET['value_field'];
		function add_info($value_field, $name_field) {$_SESSION['cart_form']['s_'.$value_field] = $name_field;}
		add_info($name_field, $value_field);
	}