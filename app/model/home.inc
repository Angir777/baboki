<?php

class Home extends db {

	public function getSlider($lang, $l) {
    	
		$result = '';

    	$sql = "SELECT * FROM ".DB_PREFIX."_slider WHERE hidden=0 ORDER BY position ASC";
	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
	    
		if ( !empty($answer) ) {
			foreach ($answer as $data) {
				// data
				if ($lang == 'pl') {
					$file_name = $data['file_name_pl'];
					$url = $data['url_pl'];
				} else {
					$file_name = $data['file_name_en'];
					$url = $data['url_en'];
				}
				$slider_position = $data['position'];
				
				$btn_style = '';
				$link_url = '';
				$file_link = URL.'tmp/gallery/slider/'.$file_name;
				
				if ($slider_position==1) {
					/*$btn_style = 'white';
					if (!empty($url)) {
						$link_url = '<a href="'.$url.'" class="btn btn-'.$btn_style.' btn-lg hidden-sm hidden-xs" title="'.$l['slider_button_create'].'">'.$l['slider_button_create'].'</a>';
					}*/
					$btn_style = 'white';
					if (!empty($url)) {
						$link_url = '<a href="'.$url.'" class="btn btn-'.$btn_style.' btn-lg hidden-sm hidden-xs" title="'.$l['slider_button_view'].'">'.$l['slider_button_view'].'</a>';
					}
				} else {
					$btn_style = 'white';
					if (!empty($url)) {
						$link_url = '<a href="'.$url.'" class="btn btn-'.$btn_style.' btn-lg hidden-sm hidden-xs" title="'.$l['slider_button_view'].'">'.$l['slider_button_view'].'</a>';
					}
				}
				
				$result .= '
					<div class="item">
						<div class="slider-img">
							<img src="'.$file_link.'" alt="'.$file_name.'">
						</div>
						<div class="container">
							<div class="row">
								<div class="col-lg-7 col-md-7 col-sm-12  col-xs-12"></div>
								<div class="col-lg-5 col-md-5 col-sm-12 col-xs-12">
									<div class="slider-captions">
										'.$link_url.'
									</div>
								</div>
							</div>
						</div>
					</div>
				';
			}
		}

	    return $result;

	}

	public function getMiniSlider($lang) {

		if ($lang == 'pl') {
			$n = [
				"Babok",
				"Uśmiechnięty Babok Harry",
				"Babok Rokowy na specjalne zamówienie",
				"Babok Wąsacz z książką",
				"Babok Olaf nad morzem",
				"Babok Indianin przy wielkim drzewie",
				"Babok Nerwusek w samochodzie",
				"Słodki Babok Panda",
				"Babok Lisek",
				"Babok Indianin na kanapie",
				"Baboki planują",
				"Babokowa paczka",
				"Kapitan Babok",
				"Babpool",
				"Babok Zając na kanapie"
			];
		} else {
			$n = [
				"Babok",
				"Smiling Babok Harry",
				"Babok Rock for special order",
				"Babok Mustache with a book",
				"Babok Olaf by the sea",
				"Babok Indian at a large tree",
				"Babok Angry in the car",
				"Słodki Babok Panda",
				"Babok Fox",
				"Babok Indian on the couch",
				"Baboki plan",
				"Babok package",
				"Captain Babok",
				"Babpool",
				"Babok Hare on the couch"
			];
		}

		$result = '';

		$cout = 1;
		$coutImg = 14;
		while ($cout <= $coutImg) {
			$result .= '<div class="item"><div class="slider-img"><img src="'.URL.'template/'.VIEW.'/images/gallery-pic-'.$cout.'.jpg" alt="'.$n[$cout].'"></div></div>';
			$cout++;
		}

		return $result;

	}

}
