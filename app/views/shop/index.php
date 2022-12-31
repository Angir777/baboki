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
	// generate filter url
	$requestURI = explode('/', strtolower(substr($_SERVER['REQUEST_URI'], 1)));
	$param = '';
	for ($i=0; $i < count($requestURI); $i++) {$param .= '/' . $requestURI[$i];}
	if ($requestURI[1]=='strona' || $requestURI[1]=='page'){
		$pagination = (int) $requestURI[2];
		$filter_category = 'all';
		$filter_price_from = 0;
		$filter_price_to = 100;
	} else {
		if ( empty($requestURI[1]) && empty($requestURI[2]) && empty($requestURI[3]) ) {
			$filter_category = 'all';
			$filter_price_from = 0;
			$filter_price_to = 100;
		} else {
			$filter_category = (string) $requestURI[1];
			$filter_price_from = (int) $requestURI[2];
			$filter_price_to = (int) $requestURI[3];
		}
	}
	// initiating the model
	$getShop = new Shop();
	$showCaregoryShop = $getShop->getCategory($lang, $l, $filter_category);
	$showProductShop = $getShop->getProduct($lang, $l, $pagination, $filter_category, $filter_price_from, $filter_price_to);
?>
<div class="space-medium">
	<div class="container">
		<div class="row">
			<div class="col-lg-9 col-md-8 col-sm-12 col-xs-12">		
				<?= $showProductShop ?>
			</div>
			<div class="col-lg-3 col-md-4 col-sm-12 col-xs-12">
				<div class="well">
					<div class="row">
						<div class="col-lg-12">
							<h4><?= $l['c_1'] ?></h4>
							<ul class="list-unstyled">
								<?= $showCaregoryShop ?>
							</ul>
						</div>
					</div>
				</div>
				<div class="well">
					<h4 class="pdb20"><?= $l['c_3'] ?></h4>
					<div id="nonlinear"></div>
					<br />
					<div id="price-range">
						<div class="row">
							<?php
							if(isset($filter_price_from)){$value_min = $filter_price_from;}else{$value_min = 0;}
							if(isset($filter_price_to)){$value_max = $filter_price_to;}else{$value_max = 100;}
							echo '
							<script>
								var WGR = WGR || {};
									WGR.filterPriceRangeMin = '.$value_min.';
									WGR.filterPriceRangeMax = '.$value_max.';
							</script>
							';
							?>
							<div class="col-md-12">
								<div class="row">
									<div class="col-md-6 col-xs-6">
										<input type="text" id="input-with-keypress-0" value="'.$value_min.'">
									</div>
									
									<div class="col-md-6 col-xs-6">
										<input type="text" id="input-with-keypress-1" value="'.$value_max.'">
									</div>
								</div>
							</div>
							<div class="col-md-12 text-center">
								<button id="subFilter" class="btn btn-default btn-sm mt20" type="submit"><?= $l['c_4'] ?></button>
								<p class="text-center"><a href="<?= URL . friendly_url($l['menu_shop']) ?>" title="Usuń wszystkie filtry"><?= $l['c_5'] ?></a></p>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>