<?php

class About extends db {

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