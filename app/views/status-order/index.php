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
	$getStatusOrder = new StatusOrder();
	$showStatusForm = $getStatusOrder->getForm($l);
?>
<div class="space-medium bg-light">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="section-title">
					<h1><?= $l['c_1'] ?></h1>
					<div class="divider"></div>
					<p><?= $l['c_2'] ?></p>
				</div>
			</div>
		</div>
	</div>
</div>
<div class="space-medium">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="header-text text-justify">
					<?= $showStatusForm ?>
				</div>
			</div>
		</div>
		<?php
			if ($_SERVER["REQUEST_METHOD"] == "POST") {
				if (empty($_POST['order_email']) OR !filter_var($_POST['order_email'], FILTER_VALIDATE_EMAIL)) {
					echo '<div class="alert alert-danger" role="alert">'.$l['c_6'].'</div>';
				} else {
					$f_order_number = check_inputs($_POST["order_number"]);
					$f_order_email = check_inputs($_POST['order_email']);
					echo $getStatusOrder->getStatus($lang, $f_order_number, $f_order_email);
				}
			}
		?>
	</div>
</div>