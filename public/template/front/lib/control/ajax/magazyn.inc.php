<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	require_once ('../../../../../../app/core/db.inc');
	require_once ('../../../../../../app/core/defines.inc');

	class ProductController extends db {

		public function addProduct() {

			// cout number products
	  		$sql = "SELECT * FROM ".DB_PREFIX."_products";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $count = $statement->rowCount();
		    $count++;

			$name_product = 'Nowy produkt';
			$ref_product = '';
			$price = 55.00;
			$quantity = 1;
			$delivery_time = 7;
			$promo_product = 0;
			$description_product_pl = '';
			$description_product_en = '';
			$technical_informations_pl = '';
			$technical_informations_en = '';
			$hidden = 1;
			
			$sql = "INSERT INTO ".DB_PREFIX."_products (name_product, ref_product, price, quantity, delivery_time, promo_product, description_product_pl, description_product_en, technical_informations_pl, technical_informations_en, hidden) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
			$statement = $this->connect()->prepare($sql);
			$statement->bindParam(":name_product", $name_product, PDO::PARAM_STR);
			$statement->bindParam(":ref_product", $ref_product, PDO::PARAM_INT);
			$statement->bindParam(":price", $price, PDO::PARAM_INT);
			$statement->bindParam(":quantity", $quantity, PDO::PARAM_INT);
			$statement->bindParam(":delivery_time", $delivery_time, PDO::PARAM_INT);
			$statement->bindParam(":promo_product", $promo_product, PDO::PARAM_INT);
			$statement->bindParam(":description_product_pl", $description_product_pl, PDO::PARAM_STR);
			$statement->bindParam(":description_product_en", $description_product_en, PDO::PARAM_STR);
			$statement->bindParam(":technical_informations_pl", $technical_informations_pl, PDO::PARAM_STR);
			$statement->bindParam(":technical_informations_en", $technical_informations_en, PDO::PARAM_STR);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->execute([$name_product, $ref_product, $price, $quantity, $delivery_time, $promo_product, $description_product_pl, $description_product_en, $technical_informations_pl, $technical_informations_en, $hidden]);

	  		$sql = "SELECT * FROM ".DB_PREFIX."_products ORDER BY id_product DESC";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		    if (!empty($answer)) {
				foreach ($answer as $data) {
					$id_product = $data['id_product'];
					break;
				}
			}

			return $id_product;

		}

		public function deleteProduct($id_product, $page_name) {
			
			if ($id_product == 1) {	
			} else {
				$sql = "SELECT name FROM ".DB_PREFIX."_products_photo WHERE product_id=$id_product";
			    $statement = $this->connect()->prepare($sql);
			    $statement->execute();
				$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			    if (!empty($answer)) {
					foreach ($answer as $data) {
						$name = $data['name'];
						$explodeFileName = explode('.', $name);

						$file = '../public/tmp/gallery/product/'.$name;
						$fileThumb = '../public/tmp/gallery/product/'.$explodeFileName[0].'_m.'.$explodeFileName[1];

						unlink($file);
						unlink($fileThumb);
					}
				}

				$sql = "DELETE FROM ".DB_PREFIX."_products_photo WHERE product_id = '".$id_product."'";
				$statement = $this->connect()->prepare($sql);
		   		$statement->execute();

				$sql = "DELETE FROM ".DB_PREFIX."_products WHERE id_product = '".$id_product."'";
				$statement = $this->connect()->prepare($sql);
		   		$statement->execute();
			}

	   		return $page_name;
			
		}

		public function deleteProductSinglePhoto($name) {

			$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE name = '".$name."'";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		    if (!empty($answer)) {
				foreach ($answer as $data) {
					$id_product = $data['product_id'];
				}
			}

			$getenlargement = explode('.', $name);
			$fileName = $getenlargement[0];
			$fileEnlargement = $getenlargement[1];

	   		unlink('../public/tmp/gallery/product/'.$fileName.'.'.$fileEnlargement);
			unlink('../public/tmp/gallery/product/'.$fileName.'_m.'.$fileEnlargement);
			
			$sql = "DELETE FROM ".DB_PREFIX."_products_photo WHERE name = '".$name."'";
			$statement = $this->connect()->prepare($sql);
   			$statement->execute();

			return $id_product;

		}

	}

	$getProductController = new ProductController();
	$pass = (int)$_GET['pass'];
	if (		$pass == 1) {
		echo $getProductController->addProduct();
	} else if (	$pass == 2) {
		$id_product = (int)$_GET['id_product'];
		$page_name = (string)$_GET['page_name'];
		echo $getProductController->deleteProduct($id_product, $page_name);
	} elseif (	$pass == 3) {
		$name = (string)$_GET['name'];
		echo $getProductController->deleteProductSinglePhoto($name);
	}