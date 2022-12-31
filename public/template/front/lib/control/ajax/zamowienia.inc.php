<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	require_once ('../../../../../../app/core/db.inc');
	require_once ('../../../../../../app/core/defines.inc');

	class OrderController extends db {

		public function deleteOrder($id_order, $page_name) {
			
			$sql = "DELETE FROM ".DB_PREFIX."_products_orders WHERE id_order = '".$id_order."'";
			$statement = $this->connect()->prepare($sql);
	   		$statement->execute();

	   		return $page_name;
			
		}

	}

	$getOrderController = new OrderController();
	$pass = (int)$_GET['pass'];
	if (	$pass == 1) {
		$id_order = (int)$_GET['id_order'];
		$page_name = (string)$_GET['page_name'];
		echo $getOrderController->deleteOrder($id_order, $page_name);
	}