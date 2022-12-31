<?php

class Confirmation extends db {

	public function getOrderNumber() {

		$sql = "SELECT order_number FROM ".DB_PREFIX."_products_orders ORDER BY id_order DESC";
		$getSelectCnt = $select->num_rows;
		$statement = $this->connect()->prepare($sql);
    	$statement->execute();
    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);

		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				// Data
				$order_number = $data['order_number'];
				// Breaking down the order number
				$dane_numeru = explode("/", $order_number); 
				// Setting id and date
				$data_zam = $dane_numeru[0].'/'.$dane_numeru[1].'/'.$dane_numeru[2];
				$id_zam = $dane_numeru[3];
				// Today's date
				$data = date("Y/m/d"); 
				// If the date is the same then we add 1 to id and if not then id = 1
				if ($data==$data_zam) {
					
					$id_zam++;
					$nowe_zam = $data_zam.'/'.$id_zam;

					return $nowe_zam;

				} else {
					
					$id_zam = 1;
					$nowe_zam = $data.'/'.$id_zam;

					return $nowe_zam;

				}
			}
		}

	}

	public function updateWarehouse($ref_product, $quantityCart) {

		$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0 AND ref_product='$ref_product'";
		$getSelectCnt = $select->num_rows;
		$statement = $this->connect()->prepare($sql);
    	$statement->execute();
    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);

		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				$quantity = $data['quantity'];
				$quantity = $quantity - $quantityCart;

				$sql = "UPDATE ".DB_PREFIX."_products SET quantity = :quantity WHERE ref_product = :ref_product";
				$statement = $this->connect()->prepare($sql);
				$statement->bindParam(":quantity", $quantity, PDO::PARAM_INT);
				$statement->bindParam(":ref_product", $ref_product, PDO::PARAM_STR);
				$statement->execute();
			}
		}

	}

	public function updatePersonalDiscount($code) {

		$active = 1;

		$sql = "UPDATE ".DB_PREFIX."_discount SET active = :active WHERE code = :code";
		$statement = $this->connect()->prepare($sql);
		$statement->bindParam(":active", $active, PDO::PARAM_INT);
		$statement->bindParam(":code", $code, PDO::PARAM_STR);
		$statement->execute();

	}

	public function updateDisposableDiscount($email) {

		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter WHERE email='$email' AND deleted=0 AND hidden=0"; 
		$getSelectCnt = $select->num_rows;
		$statement = $this->connectToNewsletter()->prepare($sql);
    	$statement->execute();
    	$count = $statement->rowCount();
		if ($count!=0) {

			$deleted = 1;

			$sql = "UPDATE ".DB_PREFIX."_newsletter SET deleted = :deleted WHERE email = :email";
			$statement = $this->connectToNewsletter()->prepare($sql);
			$statement->bindParam(":deleted", $deleted, PDO::PARAM_INT);
			$statement->bindParam(":email", $email, PDO::PARAM_STR);
			$statement->execute();

		}

	}

	public function addNewOrder($order_number, $delivery_method, $delivery_price, $payment_method, $comment, $create_toy, $info_buyer, $email_buyer, $info_product, $product_price, $discount, $final_price) {
		
		$status = 0;
		$hidden = 0;

		$sql = "INSERT INTO ".DB_PREFIX."_products_orders 
		(order_number, delivery_method, delivery_price, payment_method, comment, create_toy, info_buyer, email_buyer, info_product, product_price, discount, final_price, status, hidden) VALUES 
		(:order_number, :delivery_method, :delivery_price, :payment_method, :comment, :create_toy, :info_buyer, :email_buyer, :info_product, :product_price, :discount, :final_price, :status, :hidden)";

		$statement = $this->connect()->prepare($sql);
		$statement->bindParam(":order_number", 		$order_number, 		PDO::PARAM_STR);
		$statement->bindParam(":delivery_method", 	$delivery_method,	PDO::PARAM_INT);
		$statement->bindParam(":delivery_price", 	$delivery_price, 	PDO::PARAM_INT);
		$statement->bindParam(":payment_method", 	$payment_method, 	PDO::PARAM_INT);
		$statement->bindParam(":comment", 			$comment, 			PDO::PARAM_STR);
		$statement->bindParam(":create_toy", 		$create_toy, 		PDO::PARAM_STR);
		$statement->bindParam(":info_buyer", 		$info_buyer, 		PDO::PARAM_STR);
		$statement->bindParam(":email_buyer", 		$email_buyer, 		PDO::PARAM_STR);
		$statement->bindParam(":info_product", 		$info_product, 		PDO::PARAM_STR);
		$statement->bindParam(":product_price", 	$product_price, 	PDO::PARAM_INT);
		$statement->bindParam(":discount", 			$discount, 			PDO::PARAM_INT);
		$statement->bindParam(":final_price", 		$final_price, 		PDO::PARAM_INT);
		$statement->bindParam(":status", 			$status, 			PDO::PARAM_INT);
		$statement->bindParam(":hidden", 			$hidden, 			PDO::PARAM_INT);
		$statement->execute();

	}

}