<?php

class Shop extends db {

	public function getCategory($lang, $l, $filter_category) {
    	
		$result = '';

    	$sql = "SELECT * FROM ".DB_PREFIX."_products_category_dict WHERE hidden=0 ORDER BY position ASC";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				// data
				$id_category = $data['id_category'];
				if ($lang == 'pl') {
					$name_category = $data['name_pl'];
				} else {
					$name_category = $data['name_en'];
				}
				$checked = '';

				if ($filter_category == friendly_url($name_category)) {$checked = ' checked';}
				
				$result .= '
					<li>
						<input type="radio" class="option-input checkbox" id="cat_'.$id_category.'" name="category" value="'.friendly_url($name_category).'" '.$checked.' />
						<label for="cat_'.$id_category.'">'.$name_category.'</label>
					</li>
				';
			}
		} else {
			$result = $l['c_2'];
		}

	    return $result;

	}

	public function getPagination($lang, $l, $pagination, $productsOnPage) {

		$result = '';

		$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0";
		$statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $count = $statement->rowCount();

		$numberOfPages = ceil($count/$productsOnPage);
		if(empty($pagination)){ $pagination = 1; }

		if($numberOfPages > 1){
			$result .= '
				<div class="row m10">
					<div class="col">
						<div class="blog_pagination shop_pagination">
			';
			if($pagination > 1){
					$result .= '
						<div>
							<a class="btn btn-default btn-style2 pill-btn" rel="" href="'.URL.friendly_url($l['menu_shop']).'/'.$l['pagination_page'].'/'.($pagination-1).'">
								<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-left"></i> '.$l['c_8'].'</span>
							</a>
						</div>
					';
			}else{
				$result .= '
					<div>
						<span class="btn btn-default btn-style2 pill-btn disabled">
							<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-left"></i> '.$l['c_8'].'</span>
						</span>
					</div>
				';
			}
			if($pagination < $numberOfPages){
					$result .= '
						<div>
							<a class="btn btn-default btn-style2 pill-btn" rel="" href="'.URL.friendly_url($l['menu_shop']).'/'.$l['pagination_page'].'/'.($pagination+1).'">
								<span class="btn_pagination">'.$l['c_7'].' <i class="pdl-pagination fas fa-long-arrow-alt-right"></i></span>
							</a>
						</div>
					';
			}else{
				$result .= '
					<div>
						<span class="btn btn-default btn-style2 pill-btn disabled">
							<span class="btn_pagination">'.$l['c_7'].' <i class="pdl-pagination fas fa-long-arrow-alt-right"></i></span>
						</span>
					</div>
				';
			}
			$result .= '
						</div>
					</div>
				</div>
			';
		}

		return $result;

	}

	public function getProduct($lang, $l, $pagination, $filter_category, $filter_price_from, $filter_price_to) {
		// pagination
		$productsOnPage = 9;
		if(empty($pagination)){ $pagination = 1; }
		$startAt = ($pagination-1) * $productsOnPage;
		// filter
		if ($filter_category != 'all'){
			$sqlCat = "SELECT id_category FROM ".DB_PREFIX."_products_category_dict WHERE hidden=0 AND url_pl='$filter_category' OR url_en='$filter_category'";		
			$statementCat = $this->connect()->prepare($sqlCat);
	    	$statementCat->execute();
	    	$answerCat = $statementCat->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answerCat) ) {
				foreach ($answerCat as $dataCat) {
					$id_category = $dataCat['id_category'];
				}
			}
			$sql = "
				SELECT *
				FROM ".DB_PREFIX."_products 
				INNER JOIN ".DB_PREFIX."_products_category 
				ON ".DB_PREFIX."_products.id_product = ".DB_PREFIX."_products_category.id_product
				WHERE ".DB_PREFIX."_products_category.id_category = $id_category
				AND (".DB_PREFIX."_products.hidden=0)
				AND (".DB_PREFIX."_products.price BETWEEN $filter_price_from AND $filter_price_to)
				ORDER BY ".DB_PREFIX."_products.id_product DESC
			";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$getCount = $statement->rowCount();
			$showPagination = FALSE;
		} elseif ($filter_category == 'all' && $filter_price_from == 0 && $filter_price_to == 100){
			$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0 ORDER BY id_product DESC LIMIT $startAt, $productsOnPage";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$getCount = $statement->rowCount();
	    	$showPagination = TRUE;
		} elseif ($filter_category == 'all' && ($filter_price_from != 0 || $filter_price_to != 100)){
			$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0 AND price BETWEEN $filter_price_from AND $filter_price_to ORDER BY id_product DESC";
			$statement = $this->connect()->prepare($sql);
	    	$statement->execute();
	    	$getCount = $statement->rowCount();
	    	$showPagination = FALSE;
		}
		// show product
		if ($getCount > 0) {
			$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			if ( !empty($answer) ) {
				$result .= '<div class="row">';
				foreach ($answer as $data) {
					// data
					$id_product = $data['id_product'];
					$name_product = $data['name_product'];
					$ref_product = $data['ref_product'];
					$price = $data['price'];
					$promo_product = $data['promo_product'];
					$hidden = $data['hidden'];
					// url
					$url = URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'].'/'.$id_product;
					// image
					$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE hidden=0 AND product_id=$id_product AND position=1";
					$statement = $this->connect()->prepare($sql);
	    			$statement->execute();
					$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
					if ( !empty($answer) ) {
						foreach ($answer as $data) {
							// data
							if ($lang == 'pl') {
								$description = $data['description_pl'];
							} else {
								$description = $data['description_en'];
							}
							$name = $data['name'];
							// explode name file
							$getenlargement = explode('.', $name);
							$namefile = $getenlargement[0];
							$enlargement = $getenlargement[1];
							$fileName = $namefile.'.'.$enlargement; 		// picture
							$fileNameThumb = $namefile.'_m.'.$enlargement;  // thumbnail
							// img url
							$fileLink = URL.'tmp/gallery/product/'.$fileName;
							$fileLinkThumb = URL.'tmp/gallery/product/'.$fileNameThumb;
							//if(file_exists($fileLink)){
								$getImg = '<img class="hero-grid-image effect-image" src="'.$fileLink.'" alt="'.$name.'" />';
							//}else{}
						}
					}
					// Wyświetlenie produktu
					$result .= '
						<div class="col-lg-4 col-md-6 col-sm-6 col-xs-12">
					        <div id="product-front">
					        	<div class="shadow"></div>
					            '.$getImg.'
					            <div class="image_overlay"></div>
					            <a href="'.$url.'"><div id="view_details"><i class="fas fa-search"></i></div></a>
					            <div class="stats">        	
					                <div class="stats-container">
					                    <span class="product_name">'.$name_product.'</span>
					                    <br>
					';
					if ($promo_product > 0) {
						$result .= '<span class="product_price"><small><s>'.number_format($price,2, '.', '').'</s></small></span>';
						$result .= '<span class="product_price promotion"> / '.number_format($promo_product,2, '.', '').',-</span>';
					} else {
						$result .= '<span class="product_price">'.number_format($price,2, '.', '').',-</span> ';
					}
					$result .= '
					                </div>                                               
					            </div>
					        </div>
						</div>
					';
				}
				$result .= '</div>';
				if ($showPagination == TRUE) {$result .= $this->getPagination($lang, $l, $pagination, $productsOnPage);}
			}
		} else {
			$result .= '
				<div class="row">
					<div class="col">
						<span class="text-center">'.$l['c_6'].'</span>
					</div>
				</div>
			';
		}

		return $result;

	}
}
