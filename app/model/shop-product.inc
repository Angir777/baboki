<?php

class ShopProduct extends db {

	public function getProduct($lang, $l, $id_product) {
		$result = '';

		$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0 AND id_product=$id_product";
		$statement = $this->connect()->prepare($sql);
    	$statement->execute();
    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				//data
				$id_product = $data['id_product'];
				$name_product = $data['name_product'];
				$ref_product = $data['ref_product'];
				$price = $data['price'];
				$quantity = $data['quantity'];
				$promo_product = $data['promo_product'];
				$delivery_time =$data['delivery_time'];
				if ($lang == 'pl') {
					$description_product = $data['description_product_pl'];
					$technical_informations = $data['technical_informations_pl'];
				} else {
					$description_product = $data['description_product_en'];
					$technical_informations = $data['technical_informations_en'];
				}
				$product_description = $data['product_description'];
				$product_keywords = $data['product_keywords'];
				$hidden = $data['hidden'];
				// main picture
				$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE hidden=0 AND product_id=$id_product AND position=1";
				$statement = $this->connect()->prepare($sql);
		    	$statement->execute();
		    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
				if ( !empty($answer) ) {
					foreach ($answer as $data) {
						// data
						$description = $data['description'];
						$name = $data['name'];
						// explode name file
						$getenlargement = explode('.', $name);
						$namefile = $getenlargement[0];
						$enlargement = $getenlargement[1];
						$fileName = $namefile.'.'.$enlargement; 		// picture
						$fileNameThumb = $namefile.'_m.'.$enlargement; 	// thumbnail
						// img url
						$fileLink = URL.'tmp/gallery/product/'.$fileName;
						$fileLinkThumb = URL.'tmp/gallery/product/'.$fileNameThumb;
						$getImg = '<img src="'.$urlSite.$fileLink.'" alt="'.$name.'" />';
					}
				}
				$result .= '
					<div class="row" id="single_product">
						<div class="col-md-7 mb30">
							<div id="js-gallery" class="gallery">
								<div class="gallery__hero">
				';
				$result .= $getImg;
				$result .= '
								</div>
								<div class="gallery__thumbs">
				';
				// other pictures
				$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE hidden=0 AND product_id=$id_product ORDER BY position";
				$statement = $this->connect()->prepare($sql);
				$statement->execute();
				$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
				if ( !empty($answer) ) {
					foreach ($answer as $data) {
						$description = $data['description'];
						$name = $data['name'];
						// explode name file
						$getenlargement = explode('.', $name);
						$namefile = $getenlargement[0];
						$enlargement = $getenlargement[1];
						$fileName = $namefile.'.'.$enlargement; // Obraz
						$fileNameThumb = $namefile.'_m.'.$enlargement; // Miniaturka
						// img url
						$fileLink = URL.'tmp/gallery/product/'.$fileName;
						$fileLinkThumb = URL.'tmp/gallery/product/'.$fileNameThumb;
						$result .= '
							<a href="'.$fileLink.'" data-gallery="thumb" class="" title="">
								<img src="'.$fileLinkThumb.'" alt="'.$description.'">
							</a>
						';
					}
				}
				$result .= '

								</div>
							</div>
						</div>
						<div class="col-md-5">
							<header>
								<h1>'.$name_product.'</h1>
							</header>
							<div id="refNumber">
								<p>REF <span>'.$ref_product.'</span></p>
							</div>
							<div id="productActions">
				';
				if ($promo_product > 0) {
					$result .= '<div id="price" style="color:#46484a;padding-bottom:0px;font-size:15px;text-decoration:line-through;">'.number_format($price,2, '.', '').',-</div>';
					$result .= '<div id="price">'.number_format($promo_product,2, '.', '').',-</div>';
					$actual_product_price = $promo_product;
				} else {
					$result .= '<div id="price">'.number_format($price,2, '.', '').',-</div>';
					$actual_product_price = $price;
				}
				$result .= '
								<div id="quantityInfo">
				';
				if ($quantity <= 0) {
					$result .= '
									<p>'.$l['c_12'].' <span>0</span> '.$l['c_12a'].'</p>
									<p>'.$l['c_13'].' <span>10</span> '.$l['c_13a'].'</p>
					';
				} else {
					$result .= '
									<p>'.$l['c_12'].' <span>'.$quantity.'</span> '.$l['c_12a'].'</p>
									<p>'.$l['c_13'].' <span>'.$delivery_time.'</span> '.$l['c_13a'].'</p>
					';
				}
				$result .= '
								</div>
							</div>
							<div id="toCart">
				';
				if ($quantity <= 0) {
					$text_add_cart = $l['c_10'];
				} else {
					$text_add_cart = $l['c_11'];
				}
				$result .= '
								<div style="position: relative;">
									<div id="product_single_'.$id_product.'" class="add_shopping_cart_hidden fadeInUp"></div>
									<button onclick="add_to_cart_single('.$id_product.', \''.$lang.'\')" class="btn btn-primary mt20 hvr-buzz-out" style="width:50%;">'.$text_add_cart.'</button>
								</div>
							</div>				
							<div id="tabs">
								<!-- Nav tabs -->
								<ul class="nav nav-tabs product-tab" role="tablist">
									<li class="nav-item active">
										<a class="nav-link" data-toggle="tab" href="#description" role="tab">'.$l['c_14'].'</a>
									</li>
									<li class="nav-item">
										<a class="nav-link" data-toggle="tab" href="#tech" role="tab">'.$l['c_15'].'</a>
									</li>
									<li class="nav-item">
										<a class="nav-link" data-toggle="tab" href="#delivery" role="tab">'.$l['c_16'].'</a>
									</li>
								</ul>
								<!-- Tab panes -->
								<div class="tab-content tab_shop">
									<div class="tab-pane active" id="description" role="tabpanel">
										<br />
										<p>'.$description_product.'</p>
										<p>'.$l['c_21'].'</p>
									</div>
									<div class="tab-pane" id="tech" role="tabpanel">
										<br />
				';
				if ($id_product == 10) {
					$result .= '<p>'.$l['c_19_small'].'</p>';
				} else {
					$result .= '<p>'.$l['c_19'].'</p>';
				}
				$result .= '
										<p>'.$l['c_20'].'</p>
									</div>
									<div class="tab-pane" id="delivery" role="tabpanel">
										<br />
										<p>'.$l['c_17'].'</p>
										<p>'.$l['c_18'].'</p>
										<hr />
				';
				if (DELIVERY_PERSONAL == true) {
                    $result .= '<p>'.$l['delivery_personal_name'].': '.number_format($l['delivery_personal_cash'],2, '.', '').$l['delivery_cash'].'</p>';
                }
				if (DELIVERY_INPOST == true) {
					$result .= '<p>'.$l['delivery_inpost_name'].': '.number_format($l['delivery_inpost_cash'],2, '.', '').$l['delivery_cash'].'</p>';
				}
				if (DELIVERY_DPD == true) {
					$result .= '<p>'.$l['delivery_dpd_name'].': '.number_format($l['delivery_dpd_cash'],2, '.', '').$l['delivery_cash'].'</p>';
				}
				if (DELIVERY_DPD_WORLD == true) {
					$result .= '<p>'.$l['delivery_dpd_world_name'].': '.number_format($l['delivery_dpd_world_cash'],2, '.', '').$l['delivery_cash'].'</p>';
				}
				$result .= '
									</div>
								</div>
							</div>
				';								
				$result .= '
							<div class="product-share">
								<hr />
								<span>'.$l['c_22'].'</span>
								<ul>
									<li>
										<a href="https://www.facebook.com/sharer/sharer.php?u='.URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'].'/'.friendly_url($id_product).'&amp;p[images][0]='.$fileLink.'" rel="nofollow" target="_blank" title="facebook">
											<i class="fab fa-facebook-square"></i>
										</a>
									</li>
									<li>
										<a href="http://twitter.com/share?url='.URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'].'/'.friendly_url($id_product).'" rel="nofollow" target="_blank" title="twitter">
											<i class="fab fa-twitter-square"></i>
										</a>
									</li>
									<li>
										<a href="http://pinterest.com/pin/create/button/?url='.URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'].'/'.friendly_url($id_product).'" rel="nofollow" target="_blank" title="pinterest">
											<i class="fab fa-pinterest-square"></i>
										</a>
									</li>
								</ul>
							</div>
						</div>
					</div>
					<div class="row pinside20">
						<a href="javascript: history.go(-1)" title="'.$l['c_9'].'">
							<i class="fa fa-angle-left" style="font-weight:bold;"></i> '.$l['c_9'].'
						</a>
					</div>
				';
			}
		}

		return $result;

	}

}