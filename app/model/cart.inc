<?php

class Cart extends db {

	public function getImgProduct($lang, $l, $id_product, $i) {
		
		$result = '';

		$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE hidden=0 AND product_id=$id_product AND position=1";
		$statement = $this->connect()->prepare($sql);
    	$statement->execute();
    	$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				// data
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
				// product url
				$url = URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'].'/'.$id_product;
				// show image
				if ($id_product==1) {
					$accesories = explode("|", $_SESSION['cart_info'][$i][7]);
					$accesories = str_replace(" ","",$accesories);
					$N = count($accesories); $N--;
					$result .= '
						<div id="create_toy_img">
					';
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_16') {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_11') {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_9') {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
					$result .= '
							<img id="b_handle_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_handle/'.$_SESSION['cart_info'][$i][6].'.png" />
							<img id="b_ears_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_ears/'.$_SESSION['cart_info'][$i][3].'_front.png" />
							<img id="b_color_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_color/'.$_SESSION['cart_info'][$i][0].'_front.png" />
							<img id="b_face" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_face/'.$_SESSION['cart_info'][$i][4].'.png" />
							<img id="b_mimicry" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_mimicry/'.$_SESSION['cart_info'][$i][2].'.png" />
					';
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_25' || $accesories[$j]=='b_accessories_26' || $accesories[$j]=='b_accessories_27') {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
					$result .= '
							<img id="b_nose" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_nose/'.$_SESSION['cart_info'][$i][5].'.png" />
					';
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_16' || $accesories[$j]=='b_accessories_11' || $accesories[$j]=='b_accessories_9' || $accesories[$j]=='b_accessories_25' || $accesories[$j]=='b_accessories_26' || $accesories[$j]=='b_accessories_27' || $accesories[$j]=='b_accessories_13' || $accesories[$j]=='b_accessories_10') {} else {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
					$result .= '
							<img id="b_eyes" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_eyes/'.$_SESSION['cart_info'][$i][1].'.png" />
					';
							for ($j=0; $j < $N; $j++) {
								if ($accesories[$j]=='b_accessories_13' || $accesories[$j]=='b_accessories_10') {
									$result .= '<img id="'.$accesories[$j].'_front" src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_visualisation/b_accessories/'.$accesories[$j].'_front.png" />'.PHP_EOL;
								}
							}
					$result .= '
						</div>
					';
				} else {
					$result .= '<a href="'.$url.'" title=""><img src="'.$fileLinkThumb.'" alt="'.$name.'" /></a>';
				}
			}
		} else {
			$result .= '<img src="'.URL.'tmp/gallery/simple.jpg" alt="simple.jpg" />';
		}

		return $result;

	}
	
}