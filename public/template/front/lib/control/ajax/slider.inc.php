<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	require_once ('../../../../../../app/core/db.inc');
	require_once ('../../../../../../app/core/defines.inc');

	class SliderController extends db {

		public function addSlider() {

			// cout number sliders
	  		$sql = "SELECT * FROM ".DB_PREFIX."_slider";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $count = $statement->rowCount();
		    $count++;

			$file_name_pl = 'none.jpg';
			$file_name_en = 'none.jpg';
			$url_pl = '';
			$url_en = '';
			$position = $count;
			$hidden = 1;
			
			$sql = "INSERT INTO ".DB_PREFIX."_slider (file_name_pl, file_name_en, url_pl, url_en, position, hidden) VALUES (?, ?, ?, ?, ?, ?)";
			$statement = $this->connect()->prepare($sql);
			$statement->bindParam(":file_name_pl", $file_name_pl, PDO::PARAM_STR);
			$statement->bindParam(":file_name_en", $file_name_en, PDO::PARAM_STR);
			$statement->bindParam(":url_pl", $url_pl, PDO::PARAM_STR);
			$statement->bindParam(":url_en", $url_en, PDO::PARAM_STR);
			$statement->bindParam(":position", $position, PDO::PARAM_INT);
			$statement->bindParam(":hidden", $hidden, PDO::PARAM_INT);
			$statement->execute([$file_name_pl, $file_name_en, $url_pl, $url_en, $position, $hidden]);

	  		$sql = "SELECT * FROM ".DB_PREFIX."_slider ORDER BY id_slider DESC";
		    $statement = $this->connect()->prepare($sql);
		    $statement->execute();
		    $answer = $statement->fetchAll(PDO::FETCH_ASSOC);
		    if (!empty($answer)) {
				foreach ($answer as $data) {
					$id_slider = $data['id_slider'];
					break;
				}
			}

			return $id_slider;

		}

		public function deleteSlider($id_slider) {

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

		}

		public function deleteSliderSinglePhoto($id_slider, $lang) {

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

			if ($lang == 'pl') {
				$getenlargement = explode('.', $file_name_pl);
				$fileName = $getenlargement[0];
				$fileEnlargement = $getenlargement[1];

		   		unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_pl.'.$fileEnlargement);
				unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_pl_m.'.$fileEnlargement);
			} elseif ($lang == 'en') {
				$getenlargement = explode('.', $file_name_en);
				$fileName = $getenlargement[0];
				$fileEnlargement = $getenlargement[1];

		   		unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_en.'.$fileEnlargement);
				unlink('../public/tmp/gallery/slider/'.$id_slider.'_slider_en_m.'.$fileEnlargement);
			}

			return $id_slider;

		}

	}

	$getSliderController = new SliderController();
	$pass = (int)$_GET['pass'];
	if (		$pass == 1) {
		echo $getSliderController->addSlider();
	} elseif (	$pass == 2) {
		$id_slider = (int)$_GET['id_slider'];
		echo $getSliderController->deleteSlider($id_slider);
	} elseif (	$pass == 3) {
		$id_slider = (int)$_GET['id_slider'];
		$lang = (string)$_GET['lang'];
		echo $getSliderController->deleteSliderSinglePhoto($id_slider, $lang);
	}