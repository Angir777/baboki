<?php

class StatusOrder extends db {

	public function getForm($l){
		
		$result = '
			<form class="row contact-form" method="post" action="'.friendly_url($l['menu_status_order']).'" autocomplete="off">
				<div class="input-group">
					<div class="col-md-6">
						<div class="input ">
							<label for="order_number">'.$l['c_3'].'</label>
							<input id="order_number" type="text" name="order_number" value="" pattern="[0-9]{4}/(0[1-9]|1[012])/(0[1-9]|1[0-9]|2[0-9]|3[01])/([0-9]+)" placeholder="" required />
						</div>
					</div>
					<div class="col-md-6">
						<div class="input ">
							<label for="order_email">'.$l['c_4'].'</label>
							<input id="order_email" type="email" name="order_email" value="" placeholder="" required />
						</div>
					</div>
					
				</div>
				<div class="col-md-12 text-lg-right text-sm-right text-center">
					<button class="btn btn-primary mb20 mt20">'.$l['c_5'].'</button>
				</div>
			</form>
		';

		return $result;
	}

	public function getStatus($lang, $f_order_number, $f_order_email) {

		$n = [];
		if ($lang == 'pl') {
			$n['info_1'] = 'Numer zamówienia';
			$n['info_2'] = 'Status';
			$n['info_3'] = 'Nieprawidłowy e-mail lub numer zamówienia.';
			$n['info_4_0'] = 'Zamówienie do opłacenia';
			$n['info_4_1'] = 'Zamówienie w trakcie realizacji';
			$n['info_4_2'] = 'Zamówienie wysłane';
			$n['info_4_3'] = 'Zamówienie zrealizowane';
			$n['info_4_4'] = 'Zamówienie anulowane';
		} else {
			$n['info_1'] = 'Order number';
			$n['info_2'] = 'Status';
			$n['info_3'] = 'Invalid e-mail or order number.';
			$n['info_4_0'] = 'Order to be paid';
			$n['info_4_1'] = 'Order in progress';
			$n['info_4_2'] = 'Order sent';
			$n['info_4_3'] = 'Order completed';
			$n['info_4_4'] = 'Order canceled';
		}

		// Select form DB
		$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE order_number='$f_order_number' AND email_buyer='$f_order_email' AND hidden=0";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    if (!empty($answer)) {
			foreach ($answer as $data) {
				$order_number = $data['order_number'];
				$status = $data['status'];
				
				if($status == "0"){$f_status=$n['info_4_0'];}
				if($status == "1"){$f_status=$n['info_4_1'];}
				if($status == "2"){$f_status=$n['info_4_2'];}
				if($status == "3"){$f_status=$n['info_4_3'];}
				if($status == "4"){$f_status=$n['info_4_4'];}
			
				$result = '
					<div class="row">
						<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
							<div class="divider additional"></div>
							<div class="header-text mb20">
								<p>'.$n['info_1'].': <b>'.$order_number.'</b></p>
								<p>'.$n['info_2'].': <b>'.$f_status.'</b></p>
							</div>
						</div>
					</div>
				';
			}
		} else {
			$result = '
				<div class="row p-4">
					<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
						<div class="divider additional"></div>
						<div class="header-text mb20">
							<p>'.$n['info_3'].'</p>
						</div>
					</div>
				</div>
			';
		}

		return $result;

	}

}