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
	$id_product = $requestURI[2];
	// initiating the model
	$getShopProduct = new ShopProduct();
	$showProductShop = $getShopProduct->getProduct($lang, $l, $id_product);
?>
<div class="space-medium">
	<div class="container">
		<?= $showProductShop ?>
	</div>
</div>
<script>
	function add_to_cart_single(id_product, lang){
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				document.getElementById('product_single_'+id_product).className = "add_single_shopping_cart";
				setTimeout(function(){document.getElementById('product_single_'+id_product).className = "add_single_shopping_cart_hidden";}, 500);
				console.log(xhttp.responseText);
				// Change number in the basket
				document.getElementById('shopping_number').innerHTML = parseInt(document.getElementById('shopping_number').innerHTML) + 1;
				document.getElementById('shopping_number_small').innerHTML = parseInt(document.getElementById('shopping_number_small').innerHTML) + 1; // Mobile
			}
		}
		xhttp.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/shop/shop.inc.php?pass=1&id_products="+id_product+"&lang="+lang, true);
		xhttp.send();
	}
</script>