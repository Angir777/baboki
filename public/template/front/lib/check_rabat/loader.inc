<?php

    /**
    * This file is part of BABOKI.COM
    * Module: check_rabat
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

    // End date banner
	$data 		= '2019-09-16'; 									
	$end 		= explode('-', $data);
	$data_start = mktime (0, 0, 0, date("m"), date("d"), date("Y"));
	$data_end 	= mktime(0, 0, 0, $end[1], $end[2], $end[0]);
	$jsDay 		= $end[2];
	$jsMonth 	= $end[1] - 1;
	$jsYear 	= $end[0];

	if ($data_start < $data_end) {

		if (!isset($_SESSION['bannerRabatActive']) && !isset($_SESSION['bannerRabatShow'])) {
			$_SESSION['bannerRabatActive'] = TRUE;
			$_SESSION['bannerRabatShow'] = TRUE;
		}

		if ($_SESSION['bannerRabatShow'] == TRUE) {
		  echo '
		    <div id="promo-bar" style="display:block">
		      <div class="container-fluid">
		        <div class="row">
		          <div class="col">
		            <div class="promo-bar-main"> 
		              '.$l['rabat_banner_title'].' | 
		              <div id="countdown"></div>
		              <p class="promo-cta"><a class="promo-bar-btn promo-bar-btn-iphone" href="'.URL.friendly_url($l['menu_shop']).'" title="'.$l['rabat_banner_button'].'">'.$l['rabat_banner_button'].' <i class="fa fa-angle-double-right"></i></a></p>
		            </div>
		            <div class="promo-close" onclick="close_banner_rabat()"><i class="fa fa-times"></i></div>
		          </div>
		        </div>
		      </div>
		    </div>
		    <script>
		      // Check baner rabat
		      function close_banner_rabat() {
		        var xhttp = new XMLHttpRequest();
		        xhttp.open("GET", "'.URL.'template/'.VIEW.'/lib/check_rabat/check_rabat.inc.php?pass=3", true);
		        xhttp.send();
		        setTimeout(function(){document.getElementById("promo-bar").style.display = "none";}, 500);
		      }
		      // Counting down
		      k=+new Date('.$jsYear.','.$jsMonth.','.$jsDay.',00,00,00);
		      (function(){
		        sec=(k-new Date())/1000;
		        document.getElementById("countdown").innerHTML=~~(sec/(3600*24))+" '.$l['rabat_banner_day'].' "+~~(sec/3600)%24+" '.$l['rabat_banner_hour'].' "+~~(sec/60)%60+" '.$l['rabat_banner_minute'].' "+~~sec%60+" '.$l['rabat_banner_second'].'";
		        if(sec>0)setTimeout(arguments.callee,1000)
		      })()
		    </script>
		  ';
		}

	} else {
		$_SESSION['bannerRabatActive'] = FALSE;
	}