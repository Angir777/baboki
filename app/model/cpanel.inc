<?php

class cPanel extends db {

	/* login */

  	public function getForm($l){

  		$result = '
			<form action="'.URL.'cpanel" method="POST" class="form-horizontal" autocomplete="off">
              	<div class="form-group">
                  	<label class="col-md-2 control-label" for="l_name">'.$l['c_2'].'*</label>
                  	<div id="name-group" class="col-md-10">
                    	<input type="password" class="form-control" name="l_name" placeholder="" required>
                  	</div>
              	</div>
              	<div class="form-group">
                  	<label class="col-md-2 control-label" for="l_password">'.$l['c_3'].'*</label>
                  	<div id="email-group" class="col-md-10">
                    	<input type="password" class="form-control" name="l_password" placeholder="" required>
                  	</div>
              	</div>
              	<div class="form-group">
                	<div class="col-md-12 text-right mt20">
                  	<button type="submit" class="btn btn-primary btn-md">'.$l['c_4'].'</button>
                	</div>
              	</div>
            </form>
		';

		return $result;
		
  	}

  	public function getLogin($login, $password) {

		// Select form DB
		$sql = "SELECT * FROM ".DB_PREFIX."_users WHERE user_login = '".$login."'";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    if (!empty($answer)) {

			foreach ($answer as $data) {
				
				$passwordDB = $data['user_password'];

				if (password_verify($password, $passwordDB)) {

				  	$_SESSION['user']['logged'] = true;
					$_SESSION['user']['permissions'] = $data['user_permissions'];
					$_SESSION['user']['signature'] = $data['signature'];

					return true;

				} else {

					return false;

			 	}
			}

		} else {

			return false;

		}

  	}

  	/* statistics */

  	private function getCard($card) {
		
		$todayPrice = 0;
  		$ordersCout = 0;

		$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE hidden=0 AND status!=4";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    if (!empty($answer)) {

			foreach ($answer as $data) {
				
				$todays_date = date("Y/m/d");
				$order_number = $data['order_number'];
				$final_price = $data['final_price'];

				$dlugosc_numeru_zam = strlen($order_number);

				while ($dlugosc_numeru_zam > 10) {
					$order_number = substr($order_number ,0,strlen($order_number )-1);
					$dlugosc_numeru_zam = strlen($order_number);
				}

				if ($order_number == $todays_date) {
					$ordersCout++;
					$todayPrice = $todayPrice + $final_price;
				}

			}

			if ($card == 1) {

				return $todayPrice;

			} elseif ($card == 2) {

				return $ordersCout;

			}

		} else {

			if ($card == 1) {

				return $todayPrice;

			} elseif ($card == 2) {

				return $ordersCout;

			}

		}

  	}

  	public function getCardSingle($card) {

		return $this->getCard($card);

  	}

  	public function getCardMagazine() {
		
  		$productsCout = 0;

		$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE hidden=0";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    if (!empty($answer)) {

			foreach ($answer as $data) {
				
				$quantity = $data['quantity'];
				if ($quantity >= 0) {
					$productsCout += $data['quantity'];
				}

			}

			return $productsCout;

		} else {

			return $productsCout;

		}

  	}

  	private function getCardStatus($statusOrder) {
		
  		$ordersCout = 0;

		$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE hidden=0 AND status='".$statusOrder."'";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $count = $statement->rowCount();

	   	return $ordersCout += $count;

  	}

  	public function getCardStatusSingle($statusOrder) {

  		return $this->getCardStatus($statusOrder);

  	}

  	/* pagination */

  	private function getPagination($page_name, $pagination, $productsOnPage) {

		$result = '';

		if (($page_name == 'do-oplacenia' || $page_name == 'w-trakcie' || $page_name == 'wyslane' || $page_name == 'zakonczone' || $page_name == 'anulowane' || $page_name == 'zamowienia')) {
			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders";
			$statement = $this->connect()->prepare($sql);
		} else if ($page_name=='slider') {
			$sql = "SELECT * FROM ".DB_PREFIX."_slider";
			$statement = $this->connect()->prepare($sql);
		} else if ($page_name=='biuletyn') {
			$sql = "SELECT * FROM ".DB_PREFIX."_newsletter";
			$statement = $this->connectToNewsletter()->prepare($sql);
		} else if ($page_name=='magazyn') {
			$sql = "SELECT * FROM ".DB_PREFIX."_products";
			$statement = $this->connect()->prepare($sql);
		}
		
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
							<a class="btn btn-default btn-style2 pill-btn" rel="" href="'.URL.'cpanel/'.$page_name.'/strona/'.($pagination-1).'">
								<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-left"></i></span>
							</a>
						</div>
					';
			}else{
				$result .= '
					<div>
						<span class="btn btn-default btn-style2 pill-btn disabled">
							<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-left"></i></span>
						</span>
					</div>
				';
			}
			if($pagination < $numberOfPages){
					$result .= '
						<div>
							<a class="btn btn-default btn-style2 pill-btn" rel="" href="'.URL.'cpanel/'.$page_name.'/strona/'.($pagination+1).'">
								<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-right"></i></span>
							</a>
						</div>
					';
			}else{
				$result .= '
					<div>
						<span class="btn btn-default btn-style2 pill-btn disabled">
							<span class="btn_pagination"><i class="pdl-pagination fas fa-long-arrow-alt-right"></i></span>
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

	/* product */

  	public function getProducts($pagination, $page_name) {

  		$result = '';

  		// pagination
		$productsOnPage = 10;
		if(empty($pagination)){ $pagination = 1; }
		$startAt = ($pagination-1) * $productsOnPage;

  		$sql = "SELECT * FROM ".DB_PREFIX."_products ORDER BY id_product DESC LIMIT $startAt, $productsOnPage";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 1;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_product = $data['id_product'];
				$name_product = $data['name_product'];

				$result .= '
					<div class="card step-one">
						<div class="row card-body mb20">
	      					<div class="col-md-8 col-xs-12">
	      						<h4>'.$name_product.'</h4>
	      					</div>
	      					<div class="col-md-2 col-xs-12">
	      						<a href="'.URL.'cpanel/magazyn/'.$id_product.'/edytuj" class="btn btn-green">Edytuj</a>
	      					</div>
	      					<div class="col-md-2 col-xs-12">
	      						<button type="button" onclick="DeleteProduct('.$id_product.', \''.$page_name.'\');" class="btn btn-red">Usuń</button>
	      					</div>
	      				</div>
					</div>
				';

				$i++;

			}

			$result .= $this->getPagination($page_name, $pagination, $productsOnPage);

			return $result;
		
		} else {

			$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-12 text-center">
      						Brak dodanych produktów.
      					</div>
      				</div>
				</div>
			';

			return $result;

		}

  	}
  	
	  	public function getProduct($id_product) {

	  		if (isset($_POST['save'])) {

	  			if (!empty($_FILES['picture_product'])) {
	  				
	  				for ($i=0; $i <= count($_FILES['picture_product']['name']); $i++) { 
	  					
	  					if (is_uploaded_file($_FILES['picture_product']['tmp_name'][$i])) {
	  				
			  				$file = $_FILES['picture_product'];

			  				$fileTmp = $file['tmp_name'][$i];
							$fileError = $file['error'][$i];
							$fileName =  $file['name'][$i];
			  				
			  				// chceck format
							$getenlargement = explode('.', $fileName);
							$fileName = $getenlargement[0];
							$fileEnlargement = $getenlargement[1];
							
							if (($fileEnlargement == 'jpg') || ($fileEnlargement == 'jpeg') || ($fileEnlargement == 'png')) {
							} else {
								$error = 'Nieprawidłowy format pliku!';
								return $error;
							}

							// select next id 
							$sql = "SELECT * FROM ".DB_PREFIX."_products_photo";
						    $statement = $this->connect()->prepare($sql);
						    $statement->execute();
						    $count = $statement->rowCount();
							$count++;

							// url tmp
							$uploadFile = '../public/tmp/gallery/product/'.$count.'_'.$id_product.'.'.$fileEnlargement;
							$uploadFileThumb = '../public/tmp/gallery/product/'.$count.'_'.$id_product.'_m.'.$fileEnlargement;

							// check size
							$size = getimagesize ($fileTmp);
							$img_width = $size[0];
							if (move_uploaded_file($fileTmp, $uploadFile)) { 
								// main image
								if ($img_width > 571) {
									$thumb = PhpThumbFactory::create($uploadFile);
									$thumb->resize(571, 538);
									$thumb->save($uploadFile);
								} else {
									$thumb = PhpThumbFactory::create($uploadFile);
									$thumb->save($uploadFile);
								}
								// thumb
								$thumb = PhpThumbFactory::create($uploadFile);
								$thumb->adaptiveResize(111, 111);
								$thumb->save($uploadFileThumb);
								// add to db
								$product_id = $id_product;
								$name = $count.'_'.$id_product.'.'.$fileEnlargement;
								$description_pl = $count.'_'.$id_product;
								$description_en = $count.'_'.$id_product;
								$position = $i;
								$hidden = 0;
								$sql = "INSERT INTO ".DB_PREFIX."_products_photo (product_id, name, description_pl, description_en, position, hidden) VALUES (?, ?, ?, ?, ?, ?)";
								$statement = $this->connect()->prepare($sql);
								$statement->bindParam(":product_id", $product_id, PDO::PARAM_INT);
								$statement->bindParam(":name", $name, PDO::PARAM_STR);
								$statement->bindParam(":description_pl", $description_pl, PDO::PARAM_STR);
								$statement->bindParam(":description_en", $description_en, PDO::PARAM_STR);
								$statement->bindParam(":position", $position, PDO::PARAM_INT);
								$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
								$statement->execute([$product_id, $name, $description_pl, $description_en, $position, $hidden]);
							} else {
								$error = 'Błąd podczas przesyłania pliku!';
								return $error;
							}

			  			}

	  				}

	  			}
	  			// photo position update
	  			foreach ($_POST['position'] as $key => $value) {
					$name = $key;
					$position = $value;
	  				$sql = "UPDATE ".DB_PREFIX."_products_photo SET position = :position WHERE name = :name";
					$statement = $this->connect()->prepare($sql);
					$statement->bindParam(":position", $position, PDO::PARAM_INT);
					$statement->bindParam(":name", $name, PDO::PARAM_STR);
					$statement->execute();
	  			}

				$id_product = $_POST['id_product'];
				$name_product = $_POST['name_product'];
				$ref_product = $_POST['ref_product'];
			    $price = $_POST['price'];
			    $quantity = $_POST['quantity'];
			    $delivery_time = $_POST['delivery_time'];
			    $promo_product = $_POST['promo_product'];
			    $description_product_pl = $_POST['description_product_pl'];
			    $description_product_en = $_POST['description_product_en'];
			    $technical_informations_pl = $_POST['technical_informations_pl'];
			    $technical_informations_en = $_POST['technical_informations_en'];
			    $hidden = $_POST['hidden'];

			    $sql = "UPDATE ".DB_PREFIX."_products SET name_product = :name_product, ref_product = :ref_product, price = :price, quantity = :quantity, delivery_time = :delivery_time, promo_product = :promo_product, description_product_pl = :description_product_pl, description_product_en = :description_product_en, technical_informations_pl = :technical_informations_pl, technical_informations_en = :technical_informations_en, hidden = :hidden WHERE id_product = :id_product";
				$statement = $this->connect()->prepare($sql);
				$statement->bindParam(":id_product", $id_product, PDO::PARAM_INT);
				$statement->bindParam(":name_product", $name_product, PDO::PARAM_STR);
				$statement->bindParam(":ref_product", $ref_product, PDO::PARAM_INT);
				$statement->bindParam(":price", $price, PDO::PARAM_INT);
				$statement->bindParam(":quantity", $quantity, PDO::PARAM_INT);
				$statement->bindParam(":delivery_time", $delivery_time, PDO::PARAM_INT);
				$statement->bindParam(":promo_product", $promo_product, PDO::PARAM_INT);
				$statement->bindParam(":description_product_pl", $description_product_pl, PDO::PARAM_STR);
				$statement->bindParam(":description_product_en", $description_product_en, PDO::PARAM_STR);
				$statement->bindParam(":technical_informations_pl", $technical_informations_pl, PDO::PARAM_STR);
				$statement->bindParam(":technical_informations_en", $technical_informations_en, PDO::PARAM_STR);
				$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
				$statement->execute();
			}
			if (isset($_POST['delete'])) {

				$sql = "SELECT name FROM ".DB_PREFIX."_products_photo WHERE product_id=$id_product";
			    $statement = $this->connect()->prepare($sql);
			    $statement->execute();
				$answer = $statement->fetchAll(PDO::FETCH_ASSOC);
			    if (!empty($answer)) {
					foreach ($answer as $data) {
						$name = $data['name'];
						$explodeFileName = explode('.', $name);

						$file = '../public/tmp/gallery/product/'.$name;
						$fileThumb = '../public/tmp/gallery/product/'.$explodeFileName[0].'_m.'.$explodeFileName[1];

						unlink($file);
						unlink($fileThumb);
					}
				}

				$sql = "DELETE FROM ".DB_PREFIX."_products_photo WHERE product_id = '".$id_product."'";
				$statement = $this->connect()->prepare($sql);
		   		$statement->execute();

				$sql = "DELETE FROM ".DB_PREFIX."_products WHERE id_product = '".$id_product."'";
				$statement = $this->connect()->prepare($sql);
		   		$statement->execute();

		   		header('Location: '.URL.'cpanel/magazyn');

			}

	  		$result = '';

	  		// cout number sliders
	  		$sql = "SELECT * FROM ".DB_PREFIX."_products";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $count = $statement->rowCount();

		    // main sql
	  		$sql = "SELECT * FROM ".DB_PREFIX."_products WHERE id_product = '".$id_product."'";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

		    $i = 0;
		    if (!empty($answer)) {

				foreach ($answer as $data) {

					$id_product = $data['id_product'];
					$name_product = $data['name_product'];
					$ref_product = $data['ref_product'];
					$price = $data['price'];
					$quantity = $data['quantity'];
					$delivery_time = $data['delivery_time'];
					$promo_product = $data['promo_product'];
					$description_product_pl = $data['description_product_pl'];
					$description_product_en = $data['description_product_en'];
					$technical_informations_pl = $data['technical_informations_pl'];
					$technical_informations_en = $data['technical_informations_en'];
					$hidden = $data['hidden'];

					$result .= '
						<form action="'.URL.'cpanel/magazyn/'.$id_product.'/edytuj" method="POST" ENCTYPE="multipart/form-data">
			               <div class="card step-two">
			                  <div class="row card-body"> 
			                  	<div class="col-md-12">
									<h3>Edycja</h3>
								</div>
			                    <div class="col-md-8">
			                      	<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Nazwa produktu</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="name_product" type="text" name="name_product" value="'.$name_product.'">
		                            		<input id="id_product" type="hidden" name="id_product" value="'.$id_product.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Numer REF</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="ref_product" type="text" name="ref_product" value="'.$ref_product.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Cena produktu</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="price" type="number" name="price" step="0.01" value="'.$price.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Ilość w magazynie</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="quantity" type="number" name="quantity" step="1" value="'.$quantity.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Czas dostawy</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="delivery_time" type="number" name="delivery_time" step="1" value="'.$delivery_time.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Rabat %</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<input id="promo_product" type="number" name="promo_product" step="1" value="'.$promo_product.'">
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Opis PL</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<textarea name="description_product_pl" rows="10" cols="50">'.$description_product_pl.'</textarea>
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Opis EN</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<textarea name="description_product_en" rows="10" cols="50">'.$description_product_en.'</textarea>
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Dane techniczne PL</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<textarea name="technical_informations_pl" rows="10" cols="50">'.$technical_informations_pl.'</textarea>
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Dane techniczne EN</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
		                            		<textarea name="technical_informations_en" rows="10" cols="50">'.$technical_informations_en.'</textarea>
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
			                        	<div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Obrazy</div>
				                          	</div>
			                        	</div>
			                        	<div class="panel-body">
				                        	<table class="table tab_order table-striped table-bordered">
												<tbody>
													<tr class="text-center">
					';
					// basic url
					$file_url_pl = 'tmp/gallery/product/';
					// sql
					$sql = "SELECT * FROM ".DB_PREFIX."_products_photo WHERE product_id = '".$id_product."' ORDER BY position ASC";
				    $statement = $this->connect()->prepare($sql);
				    $statement->execute();
				    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
				    $i = 0;
				    if (!empty($answer)) {
						foreach ($answer as $data) {
							
							$id_product_photo = $data['id_product_photo'];
							$name = $data['name'];
							$position = $data['position'];

							$result .= '
								<td width="33%">
							';
							if (file_exists('../public/'.$file_url_pl.'/'.$name)) {
								$result .= '
									<div>
					                  	<img src="'.URL.$file_url_pl.$name.'">
					                  	<input type="number" name="position['.$name.']" min="1" max="3" step="1" value="'.$position.'">
										<button type="button" onclick="DeleteProductPhoto(\''.$name.'\')" class="btn-cpanel btn-grey2">
											<i class="far fa-trash-alt"></i> Usuń obraz
										</button>
									</div>
				                ';
				            } else {
				            	$result .= '
				            		<input type="file" name="picture_product[]" class="filestyle" data-input="false">
				            	';
				            }
				            $result .= '
				            	</td>
				            ';

				            $i++;

						}
						if ($i == 1) {
							$result .= '
								<td width="33%">
			            			<input type="file" name="picture_product[]" class="filestyle" data-input="false">
			            		</td>
			            		<td width="33%">
			            			<input type="file" name="picture_product[]" class="filestyle" data-input="false">
			            		</td>
			            	';
						} else if ($i == 2) {
							$result .= '
								<td width="33%">
			            			<input type="file" name="picture_product[]" class="filestyle" data-input="false">
			            		</td>
			            	';
						}
					} else {
						$result .= '
							<td width="33%">
		            			<input id="picture_product_'.$id_product.'_1" type="file" name="picture_product[]" class="filestyle" data-input="false">
		            		</td>
		            		<td width="33%">
		            			<input id="picture_product_'.$id_product.'_2" type="file" name="picture_product[]" class="filestyle" data-input="false">
		            		</td>
		            		<td width="33%">
		            			<input id="picture_product_'.$id_product.'_3" type="file" name="picture_product[]" class="filestyle" data-input="false">
		            		</td>
		            	';
					}
					$result .= '
													</tr>
												</tbody>
											</table>
		                        		</div>
		                      		</div>
		                    	</div>
		                    	<div class="col-md-4">
		                      		<div class="panel panel-default">
				                        <div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Akcja</div>
				                          	</div>
				                        </div>
			                        	<div class="panel-body">
			                          		<button type="submit" name="save" value="save" class="btn-cpanel btn-green">Zapisz</button>
			                          		<button type="submit" name="delete" value="delete" class="btn-cpanel btn-red">Usuń</button>
			                        	</div>
		                      		</div>
		                      		<div class="panel panel-default">
		                        		<div class="panel-heading">
		                          			<div class="row">
		                            			<div class="col-md-12">Widoczność</div>
		                          			</div>
		                        		</div>
		                        		<div class="panel-body">
		                          			<div class="switch-field">
		            ';
		            $checked_visible = '';
					if ($hidden == 0)
						$checked_visible = 'checked="checked"';
					$checked_hidden = '';
					if ($hidden == 1)
						$checked_hidden = 'checked="checked"';
					$result .= '							
			                            			<input type="radio" id="radio-hidden-slider_'.$id_product.'-1" name="hidden" value="0" '.$checked_visible.'/>
			                            			<label for="radio-hidden-slider_'.$id_product.'-1"><i class="far fa-eye"></i></label>
			                            			<input type="radio" id="radio-hidden-slider_'.$id_product.'-2" name="hidden" value="1" '.$checked_hidden.'/>
			                            			<label for="radio-hidden-slider_'.$id_product.'-2"><i class="far fa-eye-slash"></i></label>
			                          			</div>
			                        		</div>
			                      		</div>
			                    	</div>
			                  	</div>
			                </div>
		        		</form>
	        	';

	        	$i++;

				}

				return $result;
			
			} else {

				return '<div class="alert alert-danger" role="alert">Brak takiego produktu.</div>';

			}

	  	}
	
  	/* sliders */

  	public function getSliders($pagination, $page_name) {

  		$result = '';

  		// pagination
		$productsOnPage = 10;
		if(empty($pagination)){ $pagination = 1; }
		$startAt = ($pagination-1) * $productsOnPage;

  		$sql = "SELECT * FROM ".DB_PREFIX."_slider ORDER BY position ASC LIMIT $startAt, $productsOnPage";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 1;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_slider = $data['id_slider'];
				$file_name_pl = $data['file_name_pl'];
				$file_name_en = $data['file_name_en'];
				$url_pl = $data['url_pl'];
				$url_en = $data['url_en'];
				$position = $data['position'];
				$hidden = $data['hidden'];

				$file_url_pl = 'tmp/gallery/slider/'.$file_name_pl;

				$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-8 col-xs-12">
      			';
      			if (file_exists('../public/'.$file_url_pl)) {
	                $result .= '<img src="'.URL.$file_url_pl.'" class="mb10" alt="slider_'.$id_slider.'_pl">';
	            } else {$result .= '<h3>Slider '.$i.'</h3>';}
	            $result .= '
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<a href="'.URL.'cpanel/slider/'.$id_slider.'/edytuj" class="btn btn-green">Edytuj</a>
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<button type="button" onclick="DeleteSlider('.$id_slider.');" class="btn btn-red">Usuń</button>
      					</div>
      				</div>
				</div>
				';

				$i++;

			}

			$result .= $this->getPagination($page_name, $pagination, $productsOnPage);

			return $result;
		
		} else {

			$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-12 text-center">
      						Brak dodanych sliderów.
      					</div>
      				</div>
				</div>
			';

			return $result;

		}

  	}

  	public function getSlider($id_slider) {

  		if (isset($_POST['save'])) {
			
  			if (is_uploaded_file($_FILES['picture_slider_pl']['tmp_name'][0])) {

  				$file = $_FILES['picture_slider_pl'];

  				$fileTmp = $file['tmp_name'][0];
				$fileError = $file['error'][0];

  				// chceck format
  				$fileName =  $_FILES['picture_slider_pl']['name'][0];
				$getenlargement = explode('.', $fileName);
				$fileName = $getenlargement[0];
				$fileEnlargement = $getenlargement[1];
				
				if (($fileEnlargement == 'jpg') || ($fileEnlargement == 'jpeg') || ($fileEnlargement == 'png')) {
				} else {
					$error = 'Nieprawidłowy format pliku!';
					return $error;
				}
				
				// url tmp
				$uploadFile = '../public/tmp/gallery/slider/'.$id_slider.'_slider_pl.'.$fileEnlargement;
				$uploadFileThumb = '../public/tmp/gallery/slider/'.$id_slider.'_slider_pl_m.'.$fileEnlargement;

				// check size
				$size = getimagesize ($fileTmp);
				$img_width = $size[0];
				if (move_uploaded_file($fileTmp, $uploadFile)) { 
					// main image
					if ($img_width > 1900) {
						$thumb = PhpThumbFactory::create($uploadFile);
						$thumb->resize(1900, 700);
						$thumb->save($uploadFile);
					} else {
						$thumb = PhpThumbFactory::create($uploadFile);
						$thumb->save($uploadFile);
					}
					// thumb
					$thumb = PhpThumbFactory::create($uploadFile);
					$thumb->adaptiveResize(400, 400);
					$thumb->save($uploadFileThumb);
				} else {
					$error = 'Błąd podczas przesyłania pliku!';
					return $error;
				}

				$file_name_pl = $id_slider.'_slider_pl.'.$fileEnlargement;

  			} else {
  				
  				$file_name_pl = $_POST['picture_slider_pl']['name'];

  			}

  			if (is_uploaded_file($_FILES['picture_slider_en']['tmp_name'][0])) {

  				$file = $_FILES['picture_slider_en'];

  				$fileTmp = $file['tmp_name'][0];
				$fileError = $file['error'][0];

  				// chceck format
  				$fileName =  $_FILES['picture_slider_en']['name'][0];
				$getenlargement = explode('.', $fileName);
				$fileName = $getenlargement[0];
				$fileEnlargement = $getenlargement[1];
				
				if (($fileEnlargement == 'jpg') || ($fileEnlargement == 'jpeg') || ($fileEnlargement == 'png')) {
				} else {
					$error = 'Nieprawidłowy format pliku!';
					return $error;
				}
				
				// url tmp
				$uploadFile = '../public/tmp/gallery/slider/'.$id_slider.'_slider_en.'.$fileEnlargement;
				$uploadFileThumb = '../public/tmp/gallery/slider/'.$id_slider.'_slider_en_m.'.$fileEnlargement;

				// check size
				$size = getimagesize ($fileTmp);
				$img_width = $size[0];
				if (move_uploaded_file($fileTmp, $uploadFile)) { 
					// main image
					if ($img_width > 1900) {
						$thumb = PhpThumbFactory::create($uploadFile);
						$thumb->resize(1900, 700);
						$thumb->save($uploadFile);
					} else {
						$thumb = PhpThumbFactory::create($uploadFile);
						$thumb->save($uploadFile);
					}
					// thumb
					$thumb = PhpThumbFactory::create($uploadFile);
					$thumb->adaptiveResize(400, 400);
					$thumb->save($uploadFileThumb);
				} else {
					$error = 'Błąd podczas przesyłania pliku!';
					return $error;
				}

				$file_name_en = $id_slider.'_slider_en.'.$fileEnlargement;

  			} else {
  				
  				$file_name_en = $_POST['picture_slider_en']['name'];

  			}

			$url_pl = $_POST['url_pl'];
			$url_en = $_POST['url_en'];
			$position = $_POST['position'];
			$hidden = $_POST['hidden'];

  			$sql = "UPDATE ".DB_PREFIX."_slider SET file_name_pl = :file_name_pl, file_name_en = :file_name_en, url_pl = :url_pl, url_en = :url_en, position = :position, hidden = :hidden WHERE id_slider = :id_slider";
			$statement = $this->connect()->prepare($sql);
			$statement->bindParam(":file_name_pl", $file_name_pl, PDO::PARAM_STR);
			$statement->bindParam(":file_name_en", $file_name_en, PDO::PARAM_STR);
			$statement->bindParam(":url_pl", $url_pl, PDO::PARAM_STR);
			$statement->bindParam(":url_en", $url_en, PDO::PARAM_STR);
			$statement->bindParam(":position", $position, PDO::PARAM_INT);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->bindParam(":id_slider", $id_slider, PDO::PARAM_INT);
			$statement->execute();

		}
		if (isset($_POST['delete'])) {
			
			$sql = "SELECT * FROM ".DB_PREFIX."_slider WHERE id_slider = '".$id_slider."'";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

		    if (!empty($answer)) {

				foreach ($answer as $data) {
					
					$file_name_pl = $data['file_name_pl'];
					$file_name_en = $data['file_name_en'];

				}

			}

	   		$getenlargement = explode('.', $file_name_pl);
			$fileName = $getenlargement[0];
			$fileEnlargement = $getenlargement[1];

	   		unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_pl.'.$fileEnlargement);
			unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_pl_m.'.$fileEnlargement);

			$getenlargement = explode('.', $file_name_en);
			$fileName = $getenlargement[0];
			$fileEnlargement = $getenlargement[1];

	   		unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_en.'.$fileEnlargement);
			unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_en_m.'.$fileEnlargement);

			$sql = "DELETE FROM ".DB_PREFIX."_slider WHERE id_slider = '".$id_slider."'";
			$statement = $this->connect()->prepare($sql);
	   		$statement->execute();

	   		header('Location: '.URL.'cpanel/slider');

		}

  		$result = '';

  		// cout number sliders
  		$sql = "SELECT * FROM ".DB_PREFIX."_slider";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $count = $statement->rowCount();

	    // main sql
  		$sql = "SELECT * FROM ".DB_PREFIX."_slider WHERE id_slider = '".$id_slider."'";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 0;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_slider = $data['id_slider'];
				$file_name_pl = $data['file_name_pl'];
				$file_name_en = $data['file_name_en'];
				$url_pl = $data['url_pl'];
				$url_en = $data['url_en'];
				$position = $data['position'];
				$hidden = $data['hidden'];

				$result .= '
					<form action="'.URL.'cpanel/slider/'.$id_slider.'/edytuj" method="POST" ENCTYPE="multipart/form-data">
		               <div class="card step-two">
		                  <div class="row card-body"> 
		                  	<div class="col-md-12">
								<h3>Edycja</h3>
							</div>
		                    <div class="col-md-8">
		                      	<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Obraz PL</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	            ';

	            $file_url_pl = 'tmp/gallery/slider/'.$file_name_pl;

	            if (file_exists('../public/'.$file_url_pl)) {
	                $result .= '
	                  <input type="hidden" name="picture_slider_pl[name]" value="'.$file_name_pl.'">
	                  <img src="'.URL.$file_url_pl.'" id="picture_slider_'.$id_slider.'_pl" alt="slider_'.$id_slider.'_pl">
	                  <button type="button" onclick="DeleteSliderPhoto('.$id_slider.', \'pl\');" class="btn-cpanel btn-grey2"><i class="far fa-trash-alt"></i> Usuń obraz</button>
	                ';
	            } else {
	            	$result .= '
	            		<input type="hidden" name="picture_slider_pl[name]" value="'.$file_name_pl.'">
	            		<input id="picture_slider_'.$id_slider.'_pl" type="file" name="picture_slider_pl[]" class="filestyle" data-input="false">
	            	';
	            }

            	$result .= '
	                            		<label for="url_slider_'.$id_slider.'_pl">URL</label>
	                            		<input id="url_slider_'.$id_slider.'_pl" type="text" name="url_pl" value="'.$url_pl.'">
	                        		</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                           	 			<div class="col-md-12">Obraz EN</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	            ';

	            $file_url_en = 'tmp/gallery/slider/'.$file_name_en;

	            if (file_exists('../public/'.$file_url_en)) {
	                $result .= '
	                  <input type="hidden" name="picture_slider_en[name]" value="'.$file_name_en.'">
	                  <img src="'.URL.$file_url_en.'" id="picture_slider_'.$id_slider.'_en" alt="slider_'.$id_slider.'_en">
	                  <button type="button" onclick="DeleteSliderPhoto('.$id_slider.', \'en\');" class="btn-cpanel btn-grey2"><i class="far fa-trash-alt"></i> Usuń obraz</button>
	                ';
	            } else {
	            	$result .= '
	            		<input type="hidden" name="picture_slider_en[name]" value="'.$file_name_en.'">
	            		<input id="picture_slider_'.$id_slider.'_en" type="file" name="picture_slider_en[]" class="filestyle" data-input="false">
	            	';
	            }

            	$result .= '
	                            		<label for="url_slider_'.$id_slider.'_en">URL</label>
	                            		<input id="url_slider_'.$id_slider.'_en" type="text" name="url_en" value="'.$url_en.'">
	                        		</div>
	                      		</div>
	                    	</div>
	                    	<div class="col-md-4">
	                      		<div class="panel panel-default">
			                        <div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Akcja</div>
			                          	</div>
			                        </div>
		                        	<div class="panel-body">
		                          		<button type="submit" name="save" value="save" class="btn-cpanel btn-green">Zapisz</button>
		                          		<button type="submit" name="delete" value="delete" class="btn-cpanel btn-red">Usuń</button>
		                        	</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Widoczność</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-field">
	            ';
	            $checked_visible = '';
				if ($hidden == 0)
					$checked_visible = 'checked="checked"';
				$checked_hidden = '';
				if ($hidden == 1)
					$checked_hidden = 'checked="checked"';
				$result .= '							
		                            			<input type="radio" id="radio-hidden-slider_'.$id_slider.'-1" name="hidden" value="0" '.$checked_visible.'/>
		                            			<label for="radio-hidden-slider_'.$id_slider.'-1"><i class="far fa-eye"></i></label>
		                            			<input type="radio" id="radio-hidden-slider_'.$id_slider.'-2" name="hidden" value="1" '.$checked_hidden.'/>
		                            			<label for="radio-hidden-slider_'.$id_slider.'-2"><i class="far fa-eye-slash"></i></label>
		                          			</div>
		                        		</div>
		                      		</div>
		                      		<div class="panel panel-default">
				                        <div class="panel-heading">
				                          	<div class="row">
				                            	<div class="col-md-12">Pozycja</div>
				                          	</div>
				                        </div>
		                        		<div class="panel-body">
		                           			<input type="number" name="position" min="1" max="'.$count.'" value="'.$position.'">
		                        		</div>
		                      		</div>
		                    	</div>
		                  	</div>
		                </div>
	        		</form>
        	';

        	$i++;

			}

			return $result;
		
		} else {

			return '<div class="alert alert-danger" role="alert">Brak takiego slidera.</div>';

		}

  	}

  	/* biuletyn */

  	public function getNewsletters($pagination, $page_name) {

  		$result = '';

  		// pagination
		$productsOnPage = 10;
		if(empty($pagination)){ $pagination = 1; }
		$startAt = ($pagination-1) * $productsOnPage;

  		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter ORDER BY id_newsletter DESC LIMIT $startAt, $productsOnPage";
	    $statement = $this->connectToNewsletter()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 1;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_newsletter = $data['id_newsletter'];
				$email = $data['email'];
				$lang = $data['lang'];
				$deleted = $data['deleted'];
				$date_addition = $data['date_addition'];
				$ip = $data['ip'];
				$hidden = $data['hidden'];

				$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-8 col-xs-12">
      			';
      			if ($hidden == 0) {
      				$showText = $email;
      				if ($deleted == 0) {
      					$newMail = ' <i class="fas fa-shopping-basket ico-green" title="Aktywny kod rabatowy"></i>';
	      			} else {
	      				$newMail = ' <i class="fas fa-shopping-basket ico-red" title="Wykorzystany kod rabatowy"></i>';
	      			}
      			} else {
      				$showText = '<span style="color:#e4e4e4;">'.$email.'</span>';
      				$newMail = ' <i class="fas fa-shopping-basket ico-grey" title="Nieaktywny kod rabatowy"></i>';
      			}

      			$result .= '<h4>'.$i.'] '.$showText.$newMail.'</h4>';		
      			$result .= '
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<a href="'.URL.'cpanel/biuletyn/'.$id_newsletter.'/edytuj" class="btn btn-green">Edytuj</a>
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<button type="button" onclick="DeleteNewsletter('.$id_newsletter.');" class="btn btn-red">Usuń</button>
      					</div>
      				</div>
				</div>
				';

				$i++;

			}

			$result .= $this->getPagination($page_name, $pagination, $productsOnPage);

			return $result;
		
		} else {

			$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-12 text-center">
      						Brak dodanych adresów email.
      					</div>
      				</div>
				</div>
			';

			return $result;

		}

  	}

  	public function getNewsletter($id_newsletter) {

  		if (isset($_POST['save'])) {
  			
			$email = $_POST['email'];
			$lang = $_POST['lang'];
			$deleted = $_POST['deleted'];
			$date_addition = $_POST['date_addition'];
			$ip = $_POST['ip'];
			$hidden = $_POST['hidden'];

  			$sql = "UPDATE ".DB_PREFIX."_newsletter SET email = :email, lang = :lang, deleted = :deleted, date_addition = :date_addition, ip = :ip, hidden = :hidden WHERE id_newsletter = :id_newsletter";
			$statement = $this->connectToNewsletter()->prepare($sql);
			$statement->bindParam(":id_newsletter", $id_newsletter, PDO::PARAM_INT);
			$statement->bindParam(":email", $email, PDO::PARAM_STR);
			$statement->bindParam(":lang", $lang, PDO::PARAM_STR);
			$statement->bindParam(":deleted", $deleted, PDO::PARAM_INT);
			$statement->bindParam(":date_addition", $date_addition, PDO::PARAM_STR);
			$statement->bindParam(":ip", $ip, PDO::PARAM_STR);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->execute();
			
		}
		if (isset($_POST['delete'])) {
			
			$sql = "DELETE FROM ".DB_PREFIX."_newsletter WHERE id_newsletter = '".$id_newsletter."'";
			$statement = $this->connectToNewsletter()->prepare($sql);
	   		$statement->execute();

	   		header('Location: '.URL.'cpanel/biuletyn');
			
		}

  		$result = '';

	    // main sql
  		$sql = "SELECT * FROM ".DB_PREFIX."_newsletter WHERE id_newsletter = '".$id_newsletter."'";
	    $statement = $this->connectToNewsletter()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 0;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_newsletter = $data['id_newsletter'];
				$email = $data['email'];
				$lang = $data['lang'];;
				$deleted = $data['deleted'];
				$date_addition = $data['date_addition'];
				$ip = $data['ip'];
				$hidden = $data['hidden'];

				$result .= '
					<form action="'.URL.'cpanel/biuletyn/'.$id_newsletter.'/edytuj" method="POST">
		               <div class="card step-two">
		                  <div class="row card-body"> 
		                  	<div class="col-md-12">
								<h3>Edycja</h3>
							</div>
		                    <div class="col-md-8">
		                      	<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Adres email</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<input id="email" type="text" name="email" value="'.$email.'">
	                        		</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                           	 			<div class="col-md-12">Data dodania</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                            		<input id="date_addition" type="date" name="date_addition" value="'.$date_addition.'">
	                        		</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                           	 			<div class="col-md-12">IP</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                            		<input id="ip" type="text" name="ip" value="'.$ip.'">
	                        		</div>
	                      		</div>
	                    	</div>
	                    	<div class="col-md-4">

	                      		<div class="panel panel-default">
			                        <div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Akcja</div>
			                          	</div>
			                        </div>
		                        	<div class="panel-body">
		                          		<button type="submit" name="save" value="save" class="btn-cpanel btn-green">Zapisz</button>
		                          		<button type="submit" name="delete" value="delete" class="btn-cpanel btn-red">Usuń</button>
		                        	</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Widoczność</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-field">
	            ';
	            $checked_visible = '';
				if ($hidden == 0)
					$checked_visible = 'checked="checked"';
				$checked_hidden = '';
				if ($hidden == 1)
					$checked_hidden = 'checked="checked"';
				$result .= '							
		                            			<input type="radio" id="radio-hidden-newsletter-1" name="hidden" value="0" '.$checked_visible.'/>
		                            			<label for="radio-hidden-newsletter-1"><i class="far fa-eye"></i></label>
		                            			<input type="radio" id="radio-hidden-newsletter-2" name="hidden" value="1" '.$checked_hidden.'/>
		                            			<label for="radio-hidden-newsletter-2"><i class="far fa-eye-slash"></i></label>
		                          			</div>
		                        		</div>
		                      		</div>
		                    		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Status</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-field">
	            ';
	            $deleted_off = '';
				if ($deleted == 0)
					$deleted_off = 'checked="checked"';
				$deleted_on = '';
				if ($deleted == 1)
					$deleted_on = 'checked="checked"';
				$result .= '							
		                            			<input type="radio" id="radio-deleted-newsletter-1" name="deleted" value="0" '.$deleted_off.'/>
		                            			<label for="radio-deleted-newsletter-1"><i class="fas fa-shopping-basket"></i></label>
		                            			<input type="radio" id="radio-deleted-newsletter-2" name="deleted" value="1" '.$deleted_on.'/>
		                            			<label for="radio-deleted-newsletter-2"><i class="fas fa-shopping-basket"></i></label>
		                          			</div>
		                        		</div>
		                      		</div>
		                    	</div>
		                    </div>
		                </div>
	        		</form>
        	';

        	$i++;

			}

			return $result;
		
		} else {

			return '<div class="alert alert-danger" role="alert">Brak takiego adresu email.</div>';

		}

  	}

  	/* zamowienia */

  	public function getOrders($pagination, $page_name) {

  		$result = '';

  		// pagination
		$productsOnPage = 10;
		if(empty($pagination)){ $pagination = 1; }
		$startAt = ($pagination-1) * $productsOnPage;

  		if ($page_name == 'do-oplacenia') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE status=0 ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		} elseif ($page_name == 'w-trakcie') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE status=1 ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		} elseif ($page_name == 'wyslane') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE status=2 ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		} elseif ($page_name == 'zakonczone') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE status=3 ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		} elseif ($page_name == 'anulowane') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE status=4 ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		} elseif ($page_name == 'zamowienia') {
  			$sql = "SELECT * FROM ".DB_PREFIX."_products_orders ORDER BY id_order DESC LIMIT $startAt, $productsOnPage";
  		}
  		
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 1;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_order = $data['id_order'];
				$order_number = $data['order_number'];
				$status = $data['status'];
				$hidden = $data['hidden'];

				$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-8 col-xs-12">
      						<h4>'.$order_number.'</h4>		
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<a href="'.URL.'cpanel/'.$page_name.'/'.$id_order.'/edytuj" class="btn btn-green">Edytuj</a>
      					</div>
      					<div class="col-md-2 col-xs-12">
      						<button type="button" onclick="DeleteOrder('.$id_order.', \''.$page_name.'\');" class="btn btn-red">Usuń</button>
      					</div>
      				</div>
				</div>
				';

				$i++;

			}

			$result .= $this->getPagination($page_name, $pagination, $productsOnPage);

			return $result;
		
		} else {

			$result .= '
				<div class="card step-one">
					<div class="row card-body mb20">
      					<div class="col-md-12 text-center">
      						Brak dodanych zamówień.	
      					</div>
      				</div>
				</div>
			';

			return $result;

		}

  	}

  	public function getOrder($id_order, $page_name, $l) {

  		if (isset($_POST['save'])) {
  			// ID
  			$id_order = $_POST['id_order'];
  			// Order number
  			$order_number = $_POST['order_number'];
  			// Forma dostawy + jej kwota
		    $delivery_method = $_POST['delivery_method'];
		    if (		$delivery_method == 1) {
				$delivery_price = $l['delivery_personal_cash'];
		    } else if (	$delivery_method == 2) {
				$delivery_price = $l['delivery_inpost_cash'];
		    } else if (	$delivery_method == 3) {
				$delivery_price = $l['delivery_dpd_cash'];
		    } else if (	$delivery_method == 4) {
				$delivery_price = $l['delivery_dpd_world_cash'];
		    }
		   	// Informacje
		    $payment_method = $_POST['payment_method'];
		    $comment = $_POST['comment'];
		    $create_toy = $_POST['create_toy'];
			$info_buyer = $_POST['info_buyer'];
			$email_buyer = $_POST['email_buyer'];
			// Wylicza kwotę za produkt/y
			$info_product = $_POST['info_product'];
		    $product_price = 0;
		    $products = $info_product;
			$group_products = explode("/", $products);
			foreach ($group_products as $value) {
			    $info_single_product = explode(",", $value);
			    $actual_price = $info_single_product[2] * $info_single_product[3];
			    $product_price += $actual_price;
			}
			// Sprawdza czy jest rabat
		    $discount = $_POST['discount'];
		    if ($discount > 0) {
		    	$total_price = $product_price;
				$total_rabat = $discount;
				$create_percent = $total_rabat / 100;
				$convert_percent = $total_price * $create_percent;
				$product_price = $total_price - $convert_percent;
			}
			$product_price = number_format($product_price,2, '.', '');
			// Sprawdza czy kwota zakupu podlega darmowej dostawie
			if ($product_price >= $l['delivery_free_cash']) {
				$delivery_price	= 0.00;
			}
		    // Cena końcowa
		    $final_price = $delivery_price + $product_price;
			$final_price = number_format($final_price,2, '.', '');
			// Status
		    $status = $_POST['status'];
		    $hidden = $_POST['hidden'];
		    
  			$sql = "UPDATE ".DB_PREFIX."_products_orders SET order_number = :order_number, delivery_method = :delivery_method, delivery_price = :delivery_price, payment_method = :payment_method, comment = :comment, create_toy = :create_toy, info_buyer = :info_buyer, email_buyer = :email_buyer, info_product = :info_product, product_price = :product_price, discount = :discount, final_price = :final_price, status = :status, hidden = :hidden WHERE id_order = :id_order";
			$statement = $this->connect()->prepare($sql);
			$statement->bindParam(":id_order", $id_order, PDO::PARAM_STR);
			$statement->bindParam(":order_number", $order_number, PDO::PARAM_STR);
			$statement->bindParam(":delivery_method", $delivery_method, PDO::PARAM_INT);
			$statement->bindParam(":delivery_price", $delivery_price, PDO::PARAM_INT);
			$statement->bindParam(":payment_method", $payment_method, PDO::PARAM_INT);
			$statement->bindParam(":comment", $comment, PDO::PARAM_STR);
			$statement->bindParam(":create_toy", $create_toy, PDO::PARAM_STR);
			$statement->bindParam(":info_buyer", $info_buyer, PDO::PARAM_STR);
			$statement->bindParam(":email_buyer", $email_buyer, PDO::PARAM_STR);
			$statement->bindParam(":info_product", $info_product, PDO::PARAM_STR);
			$statement->bindParam(":product_price", $product_price, PDO::PARAM_INT);
			$statement->bindParam(":discount", $discount, PDO::PARAM_INT);
			$statement->bindParam(":final_price", $final_price, PDO::PARAM_INT);
			$statement->bindParam(":status", $status, PDO::PARAM_INT);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->execute();
		}
		if (isset($_POST['delete'])) {
			
			$sql = "DELETE FROM ".DB_PREFIX."_products_orders WHERE id_order = '".$id_order."'";
			$statement = $this->connect()->prepare($sql);
	   		$statement->execute();

	   		header('Location: '.URL.'cpanel/'.$page_name);
			
		}

  		$result = '';

	    // main sql
  		$sql = "SELECT * FROM ".DB_PREFIX."_products_orders WHERE id_order = '".$id_order."'";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);

	    $i = 0;
	    if (!empty($answer)) {

			foreach ($answer as $data) {

				$id_order = $data['id_order'];
				$order_number = $data['order_number'];
				$delivery_method = $data['delivery_method'];
				$payment_method = $data['payment_method'];
				$comment = $data['comment'];
				$create_toy = $data['create_toy'];
				$info_buyer = $data['info_buyer']; $info_buyer = str_replace("|","\n",$info_buyer);
				$email_buyer = $data['email_buyer'];
				$info_product = $data['info_product'];
				$product_price = $data['product_price'];
				$discount = $data['discount'];
				$final_price = $data['final_price'];
				$status = $data['status'];
				$hidden = $data['hidden'];

				$result .= '
					<form action="'.URL.'cpanel/'.$page_name.'/'.$id_order.'/edytuj" method="POST">
		               <div class="card step-two">
		                  <div class="row card-body"> 
		                  	<div class="col-md-12">
								<h3>Edycja</h3>
							</div>
		                    <div class="col-md-8">

		                      	<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Numer zamówienia</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
		                        		<input id="id_order" type="hidden" name="id_order" value="'.$id_order.'">
	                            		<input id="order_number" type="text" name="order_number" value="'.$order_number.'" readonly>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Sposób dostawy</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-fields">
	            ';
	            $delivery_method_1_on = '';
				if ($delivery_method == 1)
					$delivery_method_1_on = 'checked="checked"';
				$delivery_method_2_on = '';
				if ($delivery_method == 2)
					$delivery_method_2_on = 'checked="checked"';
				$delivery_method_3_on = '';
				if ($delivery_method == 3)
					$delivery_method_3_on = 'checked="checked"';
				$delivery_method_4_on = '';
				if ($delivery_method == 4)
					$delivery_method_4_on = 'checked="checked"';
				$result .= '							
	                            			<input type="radio" id="radio-delivery_method-1" name="delivery_method" value="1" '.$delivery_method_1_on.'/>
	                            			<label for="radio-delivery_method-1">Odbiór osobisty <small>'.number_format($l['delivery_personal_cash'], 2, ',', ' ').' PLN</small></label>
	                            			<input type="radio" id="radio-delivery_method-2" name="delivery_method" value="2" '.$delivery_method_2_on.'/>
	                            			<label for="radio-delivery_method-2">InPost Polska <small>'.number_format($l['delivery_inpost_cash'], 2, ',', ' ').' PLN</small></label>
	                            			<input type="radio" id="radio-delivery_method-3" name="delivery_method" value="3" '.$delivery_method_3_on.'/>
	                            			<label for="radio-delivery_method-3">DPD Polska <small>'.number_format($l['delivery_dpd_cash'], 2, ',', ' ').' PLN</small></label>
	                            			<input type="radio" id="radio-delivery_method-4" name="delivery_method" value="4" '.$delivery_method_4_on.'/>
	                            			<label for="radio-delivery_method-4">DPD Świat <small>'.number_format($l['delivery_dpd_world_cash'], 2, ',', ' ').' PLN</small></label>
	                          			</div>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Sposób płatności</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-fields">
	            ';
	            $payment_method_1_on = '';
				if ($payment_method == 1)
					$payment_method_1_on = 'checked="checked"';
				$payment_method_2_on = '';
				if ($payment_method == 2)
					$payment_method_2_on = 'checked="checked"';
				$payment_method_3_on = '';
				if ($payment_method == 3)
					$payment_method_3_on = 'checked="checked"';
				$result .= '							
	                            			<input type="radio" id="radio-payment_method-1" name="payment_method" value="1" '.$payment_method_1_on.'/>
	                            			<label for="radio-payment_method-1">Zapłata na miejscu</label>
	                            			<input type="radio" id="radio-payment_method-2" name="payment_method" value="2" '.$payment_method_2_on.'/>
	                            			<label for="radio-payment_method-2">Przelew tradycyjny</label>
	                            			<input type="radio" id="radio-payment_method-3" name="payment_method" value="3" '.$payment_method_3_on.'/>
	                            			<label for="radio-payment_method-3">Przelewy24</small></label>
	                          			</div>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Dane do wysyłki</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<textarea name="info_buyer" rows="10" cols="50" required>'.@$info_buyer.'</textarea>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Email</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<input id="email_buyer" type="text" name="email_buyer" value="'.$email_buyer.'">
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Komentarz do zamówienia</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<textarea name="comment" rows="10" cols="50">'.@$comment.'</textarea>
	                        		</div>
	                      		</div>

								<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Zamówione produkty </div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body nopadding">
		                        		
		                            	<textarea name="info_product" rows="3" cols="50" required>'.@$info_product.'</textarea>
		                        		
	                            		<table class="table tab_order table-striped table-bordered">
											<thead>
												<tr class="active">
													<th scope="col" width="25%">Nazwa produktu</th>
													<th scope="col" width="25%">Nr REF</th>
													<th scope="col" width="25%">Cena za sztuke <small>(PLN)</small></th>
													<th scope="col" width="25%">Ilość <small>(szt.)</small></th>
												</tr>
											</thead>
											<tbody>
				';
				$products = $info_product;
				$group_products = explode("/", $products);
				$group_products_count = count($group_products)-1;
				for ($licz=0; $licz<$group_products_count; $licz++) {
					$single_product = explode(",", $group_products[$licz]);
					$name_product = $single_product[0];
					$ref_product = $single_product[1];
					$price_product = $single_product[2];
					$quantity_product = $single_product[3];
					$result .= '
							<tr class="text-center">
								<td>'.$name_product.'</td>
								<td>'.$ref_product.'</td>
								<td>'.$price_product.'</td>
								<td>'.$quantity_product.'</td>
							</tr>
					';
					if ($ref_product == '001') {
						// [1] - Rozbicie ciągu produktów do tablicy ogólnej
						$single_toy = explode(".", $create_toy);
						$data_toy = $single_toy[$licz];
						// [0 Kolor] [1 Oczy] [2 Mina] [3 Uszy] [4 Twarz] [5 Nos] [6 Łapki] [7 Dodatki] [8 Uwagi]
						$elements = explode(",", $data_toy);
						// Dodatki [0 - 8]
						$accesories = explode("|", $elements[7]);
						$accesories = str_replace(" ","",$accesories);
						$N = count($accesories); $N--;
						if ($data_toy!='none') {
							
							$imgURL = URL.'template/'.VIEW.'/lib/creator/';

							$result .= '
								<tr class="text-center">
									<td colspan="2" id="b_main" style="width:50%;">
							';

								// FRONT

								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_16') {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_11') {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_9') {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}
								$result .= '
									<img id="b_handle_front" src="'.$imgURL.'b_creator/b_visualisation/b_handle/'.$elements[6].'.png" />
									<img id="b_ears_front" 	src="'.$imgURL.'b_creator/b_visualisation/b_ears/'.$elements[3].'_front.png" />
									<img id="b_color_front" src="'.$imgURL.'b_creator/b_visualisation/b_color/'.$elements[0].'_front.png" />
									<img id="b_face" src="'.$imgURL.'b_creator/b_visualisation/b_face/'.$elements[4].'.png" />
									<img id="b_mimicry" src="'.$imgURL.'b_creator/b_visualisation/b_mimicry/'.$elements[2].'.png" />
								';
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_25' || $accesories[$i]=='b_accessories_26' || $accesories[$i]=='b_accessories_27') {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}
								$result .= '
									<img id="b_nose" src="'.$imgURL.'b_creator/b_visualisation/b_nose/'.$elements[5].'.png" />
								';
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_16' || $accesories[$i]=='b_accessories_11' || $accesories[$i]=='b_accessories_9' || $accesories[$i]=='b_accessories_25' || $accesories[$i]=='b_accessories_26' || $accesories[$i]=='b_accessories_27' || $accesories[$i]=='b_accessories_13' || $accesories[$i]=='b_accessories_10') {} else {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}
								$result .= '
									<img id="b_eyes" src="'.$imgURL.'b_creator/b_visualisation/b_eyes/'.$elements[1].'.png" />
								';
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_13' || $accesories[$i]=='b_accessories_10') {
										$result .= '
											<img id="'.$accesories[$i].'_front" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_front.png" />
										';
									}
								}

							$result .= '
								</td>
								<td colspan="2" id="b_main" style="width:50%;">
							';

								// BACK

								$result .= '
									<img id="b_handle_back" src="'.$imgURL.'b_creator/b_visualisation/b_handle/'.$elements[6].'.png" />
								';
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_1') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								$result .= '
									<img id="b_ears_back" src="'.$imgURL.'b_creator/b_visualisation/b_ears/'.$elements[3].'_back.png" />
									<img id="b_color_back" src="'.$imgURL.'b_creator/b_visualisation/b_color/'.$elements[0].'_back.png" />
								';
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_3' || $accesories[$i]=='b_accessories_4' || $accesories[$i]=='b_accessories_5' || $accesories[$i]=='b_accessories_6') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_14') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_3' || $accesories[$i]=='b_accessories_4' || $accesories[$i]=='b_accessories_5' || $accesories[$i]=='b_accessories_6' || $accesories[$i]=='b_accessories_14' || $accesories[$i]=='b_accessories_13' || $accesories[$i]=='b_accessories_15' || $accesories[$i]=='b_accessories_12' || $accesories[$i]=='b_accessories_10' || $accesories[$i]=='b_accessories_9' || $accesories[$i]=='b_accessories_2' || $accesories[$i]=='b_accessories_29' || $accesories[$i]=='b_accessories_11' || $accesories[$i]=='b_accessories_16') {} else {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_13') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_15') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_12') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_10') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_9') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_2') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_29') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_11') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}
								for ($i=0; $i < $N; $i++) {
									if ($accesories[$i]=='b_accessories_16') {
										$result .= '<img id="'.$accesories[$i].'_back" src="'.$imgURL.'b_creator/b_visualisation/b_accessories/'.$accesories[$i].'_back.png" />';
									}
								}

							$result .= '
								</td>
							';
						}
						$result .= '
							<tr class="text-center"></tr>
							<tr class="text-center"></tr>
						';
					} else {
						$result .= '
							<tr class="text-center"></tr>
						';
					}
				}
				$result .= '
											</tbody>
										</table>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Dodatki do własnego projektu</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<textarea name="create_toy" rows="10" cols="50">'.$create_toy.'</textarea>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Rabat (%)</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<input id="discount" type="text" name="discount" value="'.$discount.'" required>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
		                        	<div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Cena końcowa (PLN)</div>
			                          	</div>
		                        	</div>
		                        	<div class="panel-body">
	                            		<input id="final_price" type="text" name="final_price" value="'.$final_price.'" readonly>
	                        		</div>
	                      		</div>

	                    	</div>
	                    	<div class="col-md-4">
	                      		<div class="panel panel-default">
			                        <div class="panel-heading">
			                          	<div class="row">
			                            	<div class="col-md-12">Akcja</div>
			                          	</div>
			                        </div>
		                        	<div class="panel-body">
		                          		<button type="submit" name="save" value="save" class="btn-cpanel btn-green">Zapisz</button>
		                          		<button type="submit" name="delete" value="delete" class="btn-cpanel btn-red">Usuń</button>
		                        	</div>
	                      		</div>
	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Widoczność</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-field">
	            ';
	            $checked_visible = '';
				if ($hidden == 0)
					$checked_visible = 'checked="checked"';
				$checked_hidden = '';
				if ($hidden == 1)
					$checked_hidden = 'checked="checked"';
				$result .= '							
	                            			<input type="radio" id="radio-hidden-newsletter-1" name="hidden" value="0" '.$checked_visible.'/>
	                            			<label for="radio-hidden-newsletter-1"><i class="far fa-eye"></i></label>
	                            			<input type="radio" id="radio-hidden-newsletter-2" name="hidden" value="1" '.$checked_hidden.'/>
	                            			<label for="radio-hidden-newsletter-2"><i class="far fa-eye-slash"></i></label>
	                          			</div>
	                        		</div>
	                      		</div>

	                      		<div class="panel panel-default">
	                        		<div class="panel-heading">
	                          			<div class="row">
	                            			<div class="col-md-12">Status</div>
	                          			</div>
	                        		</div>
	                        		<div class="panel-body">
	                          			<div class="switch-field">
	            ';
	            $status_1_on = '';
				if ($status == 0)
					$status_1_on = 'checked="checked"';
				$status_2_on = '';
				if ($status == 1)
					$status_2_on = 'checked="checked"';
				$status_3_on = '';
				if ($status == 2)
					$status_3_on = 'checked="checked"';
				$status_4_on = '';
				if ($status == 3)
					$status_4_on = 'checked="checked"';
				$status_5_on = '';
				if ($status == 4)
					$status_5_on = 'checked="checked"';
				$result .= '							
	                            			<input type="radio" id="radio-status-1" name="status" value="0" '.$status_1_on.'/>
	                            			<label for="radio-status-1" title="do opłacenia"><i class="fas fa-battery-quarter"></i></label>
	                            			
	                            			<input type="radio" id="radio-status-2" name="status" value="1" '.$status_2_on.'/>
	                            			<label for="radio-status-2" title="w trakcie"><i class="fas fa-battery-half"></i></label>
	                            			
	                            			<input type="radio" id="radio-status-3" name="status" value="2" '.$status_3_on.'/>
	                            			<label for="radio-status-3" title="wysłane"><i class="fas fa-battery-three-quarters"></i></label>
	                            			
	                            			<input type="radio" id="radio-status-4" name="status" value="3" '.$status_4_on.'/>
	                            			<label for="radio-status-4" title="zakończone"><i class="fas fa-battery-full"></i></label>
	                            			
	                            			<input type="radio" id="radio-status-5" name="status" value="4" '.$status_5_on.'/>
	                            			<label for="radio-status-5" title="anulowane"><i class="far fa-trash-alt"></i></label>
	                          			</div>
	                        		</div>
	                      		</div>

	                    	</div>
	                    </div>
	                </div>
        		</form>
        		';

        		$i++;

			}

			return $result;
		
		} else {

			return '<div class="alert alert-danger" role="alert">Brak takiego zamówienia.</div>';

		}

  	}

}