<?php

class deliveryAndPayment extends db {

	private function strContains($haystack, $needle) {

		return (strpos($haystack,$needle)!==false);

	}

	public function checkOrdersForMonth($lang, $l, $total_price) {

		$month_price = 0;

		$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE hidden=0 AND status!=4 ORDER BY id_order DESC";
		$statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				$product_price =  $data['product_price'];
				$order_number =  $data['order_number'];
				$todays_date = date("Y/m/");
				if ($this->strContains($order_number, $todays_date)) {
					$count++;
					$month_price = $month_price + $product_price;
				}
			}
		}

		$month_price = $month_price + $total_price;
		
		if ($month_price > 1050) {
			$limit = $month_price - 1050;
			$result = '
				<div class="container single_services text-left">
					<div class="row info-cart-style1 mt30">
						<div class="col-md-12 text-center">
							<p>'.$l['c_42'].number_format($limit,2, '.', '').' '.$l['delivery_cash'].'.<br>'.$l['c_43'].'</p>
						</div>
					</div>
					<div class="row pinside20 mb100">
						<div class="col text-lg-left text-sm-left text-left">
							<a href="koszyk" title="'.$l['c_20'].'">
								<i class="fa fa-angle-left" style="font-weight:bold;"></i> '.$l['c_20'].'
							</a>
						</div>
					</div>
				</div>
			';
		} else {
			$result = FALSE;
		}

		return $result;

	}

}