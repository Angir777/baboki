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
	</div>
</div>
<div class="space-medium">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<?php 
				if (DELIVERY_PERSONAL == true) {
					echo '
						<h4 class="mt40">'.$l['delivery_personal_name'].' '.number_format($l['delivery_personal_cash'],2, '.', '').$l['delivery_cash'].'</h4>
						<div class="divider additional"></div>
						<div class="text-justify mb10">
							<p>'.$l['c_3'].'</p>
						</div>
					';
				} else {
					echo '
						<h4>'.$l['c_2'].'</h4>
						<div class="divider additional"></div>
						<div class="text-justify mb10">
							<p></p>
						</div>
					';
				}
				if (DELIVERY_INPOST == true) {
					echo '
						<h4 class="mt40">'.$l['delivery_inpost_name'].' '.number_format($l['delivery_inpost_cash'],2, '.', '').$l['delivery_cash'].'</h4>
						<div class="divider additional"></div>
						<div class="text-justify mb10">
							<p>'.$l['c_4'].'</p>
						</div>
					';
				}
				if (DELIVERY_DPD == true) {
					echo '
						<h4 class="mt40">'.$l['delivery_dpd_name'].' '.number_format($l['delivery_dpd_cash'],2, '.', '').$l['delivery_cash'].'</h4>
						<div class="divider additional"></div>
						<div class="text-justify mb10">
							<p>'.$l['c_5'].'</p>
						</div>
					';
				}
				if (DELIVERY_DPD_WORLD == true) {
					echo '
						<h4 class="mt40">'.$l['delivery_dpd_world_name'].' '.number_format($l['delivery_dpd_world_cash'],2, '.', '').$l['delivery_cash'].'</h4>
						<div class="divider additional"></div>
						<div class="text-justify mb10">
							<p>'.$l['c_6'].'</p>
						</div>
					';
				}
				?>
				<h4 class="mt40"><?= $l['c_7'] ?></h4>
				<div class="divider additional"></div>
				<div class="text-justify mb10">
					<p><?= $l['c_8'] ?></p>
				</div>
				<h4 class="mt40"><?= $l['c_9'] ?></h4>
				<div class="divider additional"></div>
				<div class="text-justify mb10">
					<p><?= $l['c_10'] ?></p>
				</div>
			</div>
		</div>
	</div>
</div>