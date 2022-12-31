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
	$getCart = new Cart();
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
		<div class="row bs-wizard" style="border-bottom:0;">
			<div class="col-xs-4 bs-wizard-step complete">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_2'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
			<div class="col-xs-4 bs-wizard-step disabled">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_3'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
			<div class="col-xs-4 bs-wizard-step disabled">
				<div class="text-center bs-wizard-stepnum"><?= $l['c_4'] ?></div>
				<div class="progress"><div class="progress-bar"></div></div>
				<a href="#" class="bs-wizard-dot"></a>
				<div class="bs-wizard-info text-center"></div>
			</div>
		</div>
	</div>
</div>
<div class="container single_services text-left">
	<div class="row mt40">
		<div class="col-md-12">
			<h2><?= $l['c_5'] ?></h2>
			<div class="divider additional"></div>
		</div>
	</div>
<?php
	$total_price = 0;
	if (empty($_SESSION['cart'])) {
		unset($_SESSION['courier']);
		echo '
		<div class="row">
			<div class="col-md-12 text-center mb30">
				<p>'.$l['c_14'].'</p>
				<a href="'.URL.friendly_url($l['menu_shop']).'" title="'.$l['c_24'].'" class="btn btn-default btn-lg m30">'.$l['c_16'].'</a>
			</div>
		</div>
		';
	} else {
		echo '
		<div id="cartTableHead" class="row">
			<div class="col-lg-3 col-sm-3 hidden-xs">'.$l['c_6'].'</div>
			<div class="col-lg-2 col-sm-2 col-xs-3">'.$l['c_7'].'</div>
			<div class="col-lg-2 col-sm-2 col-xs-2">'.$l['c_8'].'</div>
			<div class="col-lg-2 col-sm-2 col-xs-2">'.$l['c_9'].'</div>
			<div class="col-lg-2 col-sm-2 col-xs-2">'.$l['c_10'].'</div>
			<div class="col-lg-1 col-sm-1 col-xs-3"></div>
		</div>
		';
		for ($i = 0; $i < sizeof($_SESSION['cart']); $i++) {
			$actual_price = $_SESSION['cart'][$i][3]*$_SESSION['cart'][$i][4];
			$total_price += $actual_price;
			echo '
			<div id="cartTableProduct_'.$i.'" class="row cartTableProduct">
				<div class="col-lg-3 col-sm-3 hidden-xs">
			';
			// show product image
			$id_product = $_SESSION['cart'][$i][0];
			echo $getCart->getImgProduct($lang, $l, $id_product, $i);
			echo '
				</div>
				<div class="col-lg-2 col-sm-2 col-xs-3">'.$_SESSION['cart'][$i][1].'</div>
				<div class="col-lg-2 col-sm-2 col-xs-2">REF '.$_SESSION['cart'][$i][2].'</div>
				<div class="col-lg-2 col-sm-2 col-xs-2">
					<input type="number" name="amount_products" value="'.$_SESSION['cart'][$i][4].'" onchange="amount_products('.$i.', '.$_SESSION['cart'][$i][3].', this.value);" min="1" />
				</div>
				<div id="order_price_'.$i.'" class="col-lg-2 col-sm-2 col-xs-2">'.number_format($actual_price,2, '.', '').'</div>
				<div class="col-lg-1 col-sm-1 col-xs-3">
					<span class="shopping_delete_product" onclick="delete_from_cart_single('.$i.')">
						<i class="far fa-minus-square" title="'.$l['c_15'].'"></i>
					</span>
				</div>
			</div>
			';
		}
		echo '
		<div class="row mt20">
			<div class="col-md-12 text-lg-right text-sm-right text-right">
				<p>'.$l['c_11'].'</p>
			</div>
		</div>
		<div class="row">
			<div class="col-md-12 text-lg-right text-sm-right text-right mb20">
				<b>'.$l['c_12'].' <span id="total_price">'.number_format($total_price,2, '.', '').'</span> '.$l['delivery_cash'].'</b>
				<br><br>
				<a href="'.URL.friendly_url($l['menu_delivery_and_payment']).'" title="'.$l['c_23'].'">'.$l['c_13'].' <i class="fa fa-angle-right" style="font-weight:bold;"></i></a>
			</div>
		</div>
		';
	}
?>
	<div class="row cart-bottom-boxes mb30">
		<div class="col-lg-4 col-md-4 col-xs-12">
			<div class="cart-bottom-box-inner">
				<div class="cart-bottom-col-left"><i class="far fa-hand-peace"></i></div>
				<div class="cart-bottom-col-right">
					<h3><?= $l['c_17'] ?></h3>
					<p><?= $l['c_18'] ?></p>
				</div>
			</div>
		</div>
		<div class="col-lg-4 col-md-4 col-xs-12">
			<div class="cart-bottom-box-inner">
				<div class="cart-bottom-col-left"><i class="fas fa-lock"></i></div>
				<div class="cart-bottom-col-right">
					<h3><?= $l['c_19'] ?></h3>
					<p><?= $l['c_20'] ?></p>
				</div>
			</div>
		</div>
		<div class="col-lg-4 col-md-4 col-xs-12">
			<div class="cart-bottom-box-inner">
				<div class="cart-bottom-col-left"><i class="fas fa-medal"></i></div>
				<div class="cart-bottom-col-right">
					<h3><?= $l['c_21'] ?></h3>
					<p><?= $l['c_22'] ?></p>
				</div>
			</div>
		</div>
	</div>
</div>
<script>
	// remove product from basket
	function delete_from_cart_single(id_product) {
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function(){
			if (this.readyState == 4 && this.status == 200) {
				document.getElementById('shopping_number').innerHTML = parseInt(document.getElementById('shopping_number').innerHTML) - 1;
				document.getElementById('shopping_number_small').innerHTML = parseInt(document.getElementById('shopping_number_small').innerHTML) - 1; // Mobile
				location.reload();
			}
		}
		xhttp.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/shop/shop.inc.php?pass=3&id_product="+id_product, true);
		xhttp.send();
	}
	// change of quantity and prices
	<?php echo 'var number_order = '.$_SESSION['number_order'].';'; ?>
	function calculate_total() {
		document.getElementById("total_price").innerHTML = 0;
		for (var i=0;i<number_order;i++) {
			var price_format = document.getElementById("order_price_"+i).innerHTML;
			var total_price = document.getElementById("total_price");
			var price = parseFloat(total_price.innerHTML) + parseFloat(price_format);
			var roundedPrice = price.toFixed(2); 
			total_price.innerHTML = roundedPrice;
		}
	}
	function single_products_info(amount_added, id_product_cart) {
		var xhttp = new XMLHttpRequest();
		xhttp.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/shop/shop.inc.php?pass=2&amount_added="+amount_added+"&id_product_cart="+id_product_cart, true);
		xhttp.send();
	}	
	function amount_products(id_product_cart, price_product_cart, amount_added) {
		single_products_info(amount_added, id_product_cart);
		var new_price = price_product_cart*amount_added;
		document.getElementById("order_price_"+id_product_cart).innerHTML = new_price.toFixed(2);
		calculate_total();
	}
</script>