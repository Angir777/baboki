<?php

    /**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

  // global varables
  global $lang;                   // Global language varable
  global $l;                      // Global language array
  // initiating the model
  $getcPanel = new cPanel();
  // initiating additives
  // thumbs generator
  require_once('../public/template/'.VIEW.'/lib/control/phpthumb/ThumbLib.inc.php');
  // urls
  $requestURI = explode('/', strtolower(substr($_SERVER['REQUEST_URI'], 1)));
  $page_name = (string) $requestURI[1];
  $id_slider = (int) $requestURI[2];
  $action = $requestURI[3];
  if (!empty($id_slider)) {$page = (string) $requestURI[1];} else {$page = '';}
  if ($requestURI[2]=='strona'){$pagination = (int) $requestURI[3];}
  if ($_SESSION['user']['logged'] == true) {
?>
<div class="single_services text-left mt30 mb20">
  <div class="container">
    <div class="row">
      <div id="cpanel" class="col-md-12">
        <div class="card step-one">
          <div class="row card-body mb20">
            <div class="col-md-3"><a href="<?= URL ?>cpanel/<?= $page ?>" class="btn btn-grey"><i class="fas fa-long-arrow-alt-left"></i> Powrót</a></div>
            <div class="col-md-6 mt10 text-center"><h4>Slidery</h4></div>
            <div class="col-md-3 text-right"><button class="btn btn-grey" onclick="AddSlider();"><i class="far fa-plus-square"></i> Dodaj nowy</button></div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div id="cpanel" class="col-md-12">
<?php 
  if (isset($action) && $action == 'edytuj') {
    echo $getcPanel->getSlider($id_slider);
  } else {
    echo $getcPanel->getSliders($pagination, $page_name);
  }
?>
      </div>
    </div> 
  </div>
</div>
<?php 
  } else {header('Location: '.URL.'cpanel');}
?>