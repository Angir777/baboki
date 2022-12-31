<?php

	/**
	* This file is part of BABOKI.COM
	*
	* @author       Błażej Skrzypniak <hi@skrzypniak.pl>
	* @link         https://baboki.com
	*/

	class Content {
		
		protected $lang;
		protected $l;

		public function getMenuLight () {

			$requestURI = explode('/', strtolower(substr($_SERVER['REQUEST_URI'], 1)));

			$param = '';
			for ($i=0; $i < count($requestURI); $i++) {$param .= '/' . $requestURI[$i];}

			// PAGE/SUBPAGE
			$getSubPage = $requestURI[1];

			// ACTIONS
			$action = (string) $requestURI[3];

			// PAGE/PARAMETERS
			$getParam1 = (string) $requestURI[1];
			$getParam2 = (int) $requestURI[2];
			$getParam3 = (int) $requestURI[3];

			$rules = [
				["/","pl"],
				["/o-babokach","pl"],
			    ["/about-baboki","en"],
			    ["/wlasny-pluszak","pl"],
			    ["/creator","en"],
			    ["/sklep","pl"],
			    ["/shop","en"],
			    	["/sklep/$getParam1/$getParam2/$getParam3","pl"],
			    	["/shop/$getParam1/$getParam2/$getParam3","en"],
					["/sklep/strona/$getParam2","pl"],
					["/shop/page/$getParam2","en"],
					["/sklep/produkt/$getParam2","pl"],
					["/shop/product/$getParam2","en"],
			    ["/kontakt","pl"],
			    ["/contact","en"],
			    ["/koszyk","pl"],
			    ["/cart","en"],
			    	["/dostawa-i-platnosc","pl"],
			   	 	["/delivery-and-payment","en"],
			   	 	["/potwierdzenie","pl"],
			   	 	["/confirmation","en"],
				["/zwroty-i-reklamacje","pl"],
				["/returns-and-complaints","en"],
				["/polityka-prywatnosci","pl"],
				["/privacy-policy","en"],
				["/regulamin","pl"],
				["/regulations","en"],
				["/sposoby-dostawy","pl"],
				["/delivery-methods","en"],
				["/formy-platnosci","pl"],
				["/forms-of-payment","en"],
				["/czeste-pytania","pl"],
				["/faq","en"],
				["/wspolpraca","pl"],
				["/cooperation","en"],
				["/status-zamowienia","pl"],
				["/status-of-the-order","en"],
				["/biuletyn","pl"],
				["/biuletyn/","pl"],
				["/biuletyn/$getSubPage","pl"],
				["/biuletyn/$getSubPage/","pl"],
				["/newsletter","en"],
				["/newsletter/","en"],
				["/newsletter/$getSubPage","en"],
				["/newsletter/$getSubPage/","en"],
				["/cpanel","pl"],
				["/cpanel/","pl"],
				["/cpanel/$getParam1","pl"],
				["/cpanel/$getParam1/$getParam2","pl"],
				["/cpanel/$getParam1/$getParam2/$action","pl"],
				["/cpanel/$getParam1/strona/$getParam3","pl"],
			];

			$found = false;

			foreach ($rules as $url => $info) {
				if ($param == $info[0]) {
					if ($param == '/' or $param == '') {

						$_SESSION['pageSite'] = 'home';

					} elseif ($param == '/o-babokach' or $param == '/about-baboki') {	
						
						$_SESSION['pageSite'] = 'about';

					} elseif ($param == '/wlasny-pluszak' or $param == '/creator') {	
						
						$_SESSION['pageSite'] = 'creator';

					} elseif ($param == '/sklep' or $param == '/shop' or $param == '/sklep/' or $param == '/shop/') {

						$_SESSION['pageSite'] = 'shop';

					} elseif ($param == '/sklep/'.$getParam1.'/'.$getParam2.'/'.$getParam3 or $param == '/shop/'.$getParam1.'/'.$getParam2.'/'.$getParam3) {
						
						$_SESSION['pageSite'] = 'shop';

					} elseif ($param == '/sklep/strona/'.$getParam2 or $param == '/shop/page/'.$getParam2) {	
						
						$_SESSION['pageSite'] = 'shop';

					} elseif ($param == '/sklep/produkt/'.$getParam2 or $param == '/shop/product/'.$getParam2) {	
						
						$_SESSION['pageSite'] = 'shop-product';

					} elseif ($param == '/kontakt' or $param == '/contact') {	
						
						$_SESSION['pageSite'] = 'contact';

					} elseif ($param == '/koszyk' or $param == '/cart') {	
						
						$_SESSION['pageSite'] = 'cart';

					} elseif ($param == '/dostawa-i-platnosc' or $param == '/delivery-and-payment') {	
						
						$_SESSION['pageSite'] = 'delivery-and-payment';

					} elseif ($param == '/potwierdzenie' or $param == '/confirmation') {	
						
						$_SESSION['pageSite'] = 'confirmation';

					} elseif ($param == '/zwroty-i-reklamacje' or $param == '/returns-and-complaints') {	
						
						$_SESSION['pageSite'] = 'returns-and-complaints';

					} elseif ($param == '/polityka-prywatnosci' or $param == '/privacy-policy') {	
						
						$_SESSION['pageSite'] = 'privacy-policy';

					} elseif ($param == '/regulamin' or $param == '/regulations') {	
						
						$_SESSION['pageSite'] = 'regulations';

					} elseif ($param == '/sposoby-dostawy' or $param == '/delivery-methods') {	
						
						$_SESSION['pageSite'] = 'delivery-methods';

					} elseif ($param == '/formy-platnosci' or $param == '/forms-of-payment') {	
						
						$_SESSION['pageSite'] = 'forms-of-payment';

					} elseif ($param == '/czeste-pytania' or $param == '/faq') {	
						
						$_SESSION['pageSite'] = 'faq';

					} elseif ($param == '/wspolpraca' or $param == '/cooperation') {	
						
						$_SESSION['pageSite'] = 'cooperation';

					} elseif ($param == '/status-zamowienia' or $param == '/status-of-the-order') {	
						
						$_SESSION['pageSite'] = 'status-order';

					} elseif ($param == '/biuletyn' or $param == '/biuletyn/' or $param == '/newsletter' or $param == '/newsletter/') {	
						
						$_SESSION['pageSite'] = 'newsletter';

					} elseif ($param == '/biuletyn/'.$getSubPage or $param == '/biuletyn/'.$getSubPage.'/' or $param == '/newsletter/'.$getSubPage or $param == '/newsletter/'.$getSubPage.'/') {	
						
						$_SESSION['pageSite'] = 'newsletter';
						$_SESSION['subpageSite'] = $getSubPage;

					} elseif ($param == '/cpanel' or $param == '/cpanel/') {	
						
						$_SESSION['pageSite'] = 'cpanel';

					} elseif ($param == '/cpanel/'.$getParam1 or $param == '/cpanel/'.$getParam1.'/'.$getParam2 or $param == '/cpanel/'.$getParam1.'/'.$getParam2.'/'.$action 
						or $param == '/cpanel/'.$getParam1.'/strona/'.$getParam3) {	
						
						$_SESSION['pageSite'] = 'cpanel';

						if ($getParam1=='do-oplacenia' || $getParam1=='w-trakcie' || $getParam1=='wyslane' || $getParam1=='zakonczone' || $getParam1=='anulowane' || $getParam1=='zamowienia') {
							$_SESSION['subpageSite'] = 'zamowienia';
						} else {
							$_SESSION['subpageSite'] = $getParam1;
						}

					}
			        $found = true;
			        break;
			    }
			}

			if (!$found) {$_SESSION['pageSite'] = '';}
			
			return;
			
		}

		public function getPage ($lang, $l) {

			$requestURI = explode('/', strtolower(substr($_SERVER['REQUEST_URI'], 1)));

			$param = '';
			for ($i=0; $i < count($requestURI); $i++) {$param .= '/' . $requestURI[$i];}

			// PAGE/SUBPAGE
			$getSubPage = $requestURI[1];

			// ACTIONS
			$action = (string) $requestURI[3];

			// PAGE/PARAMETERS
			$getParam1 = (string) $requestURI[1];
			$getParam2 = (int) $requestURI[2];
			$getParam3 = (int) $requestURI[3];

			$rules = [
				["/","pl"],
				["/o-babokach","pl"],
			    ["/about-baboki","en"],
			    ["/wlasny-pluszak","pl"],
			    ["/creator","en"],
			    ["/sklep","pl"],
			    ["/shop","en"],
			    	["/sklep/$getParam1/$getParam2/$getParam3","pl"],
			    	["/shop/$getParam1/$getParam2/$getParam3","en"],
					["/sklep/strona/$getParam2","pl"],
					["/shop/page/$getParam2","en"],
					["/sklep/produkt/$getParam2","pl"],
					["/shop/product/$getParam2","en"],
			    ["/kontakt","pl"],
			    ["/contact","en"],
			    ["/koszyk","pl"],
			    ["/cart","en"],
			    	["/dostawa-i-platnosc","pl"],
			   	 	["/delivery-and-payment","en"],
			   	 	["/potwierdzenie","pl"],
			   	 	["/confirmation","en"],
				["/zwroty-i-reklamacje","pl"],
				["/returns-and-complaints","en"],
				["/polityka-prywatnosci","pl"],
				["/privacy-policy","en"],
				["/regulamin","pl"],
				["/regulations","en"],
				["/sposoby-dostawy","pl"],
				["/delivery-methods","en"],
				["/formy-platnosci","pl"],
				["/forms-of-payment","en"],
				["/czeste-pytania","pl"],
				["/faq","en"],
				["/wspolpraca","pl"],
				["/cooperation","en"],
				["/status-zamowienia","pl"],
				["/status-of-the-order","en"],
				["/biuletyn","pl"],
				["/biuletyn/","pl"],
				["/biuletyn/$getSubPage","pl"],
				["/biuletyn/$getSubPage/","pl"],
				["/newsletter","en"],
				["/newsletter/","en"],
				["/newsletter/$getSubPage","en"],
				["/newsletter/$getSubPage/","en"],
				["/cpanel","pl"],
				["/cpanel/","pl"],
				["/cpanel/$getParam1","pl"],
				["/cpanel/$getParam1/$getParam2","pl"],
				["/cpanel/$getParam1/$getParam2/$action","pl"],
				["/cpanel/$getParam1/strona/$getParam3","pl"],
				["/cpanel/logout","pl"],
				["/cpanel/logout/","pl"],
			];

			$found = false;

			foreach ($rules as $url => $info) {
				if ($param == $info[0]) {

					$getLang = new Language();

					if ($param == '/' or $param == '') {

						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}
						
						$lang = $_SESSION['lang'];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/o-babokach' or $param == '/about-baboki') {	

						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/wlasny-pluszak' or $param == '/creator') {
					
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sklep' or $param == '/shop' or $param == '/sklep/' or $param == '/shop/') {
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sklep/'.$getSubPage or $param == '/shop/'.$getSubPage) {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sklep/'.$getParam1.'/'.$getParam2.'/'.$getParam3 or $param == '/shop/'.$getParam1.'/'.$getParam2.'/'.$getParam3) {
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sklep/strona/'.$getParam2 or $param == '/shop/page/'.$getParam2) {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sklep/produkt/'.$getParam2 or $param == '/shop/product/'.$getParam2) {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/kontakt' or $param == '/contact') {	

						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/koszyk' or $param == '/cart') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');	

					} elseif ($param == '/dostawa-i-platnosc' or $param == '/delivery-and-payment') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/potwierdzenie' or $param == '/confirmation') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/zwroty-i-reklamacje' or $param == '/returns-and-complaints') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/polityka-prywatnosci' or $param == '/privacy-policy') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/regulamin' or $param == '/regulations') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/sposoby-dostawy' or $param == '/delivery-methods') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/formy-platnosci' or $param == '/forms-of-payment') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/czeste-pytania' or $param == '/faq') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/wspolpraca' or $param == '/cooperation') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/status-zamowienia' or $param == '/status-of-the-order') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/biuletyn' or $param == '/biuletyn/' or $param == '/biuletyn/'.$getSubPage or $param == '/biuletyn/'.$getSubPage.'/' or $param == '/newsletter' or $param == '/newsletter/' or $param == '/newsletter/'.$getSubPage or $param == '/newsletter/'.$getSubPage.'/') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');
					
					} elseif ($param == '/cpanel' or $param == '/cpanel/') {	
						
						$model = '../app/model/' . $_SESSION['pageSite'] . '.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						include('../app/views/' . $_SESSION['pageSite'] . '/index.php');

					} elseif ($param == '/cpanel/logout' or $param == '/cpanel/logout/') {	
						
						$_SESSION = array();
						session_destroy();
						session_start();
						$_SESSION['lang'] = $lang;
						header('Location: '.URL.'cpanel');

					} elseif ($param == '/cpanel/'.$getParam1 or $param == '/cpanel/'.$getParam1.'/'.$getParam2 or $param == '/cpanel/'.$getParam1.'/'.$getParam2.'/'.$action or $param == '/cpanel/'.$getParam1.'/strona/'.$getParam3) {
						
						$model = '../app/model/cpanel.inc';
						if (file_exists($model)) {include ('../app/model/' . $_SESSION['pageSite'] . '.inc');}

						$_SESSION['lang'] = $info[1];
						$lang = $info[1];
						$l = $getLang->lang($lang);

						if ($getParam1=='do-oplacenia' || $getParam1=='w-trakcie' || $getParam1=='wyslane' || $getParam1=='zakonczone' || $getParam1=='anulowane' || $getParam1=='zamowienia') {
							include('../app/views/cpanel/zamowienia.php');
						} else {
							include('../app/views/cpanel/' . $getParam1 . '.php');
						}

					}
			        $found = true;
			        break;
			    }
			}

			if (!$found) {
				header("HTTP/1.0 404 Not Found");
				$getLang = new Language();
				$lang = $_SESSION['lang'];
				$l = $getLang->lang($lang);
			    include('../app/views/404/index.php');
			}
			
			return;
			
		}

	}