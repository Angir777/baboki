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
  // urls
  $requestURI = explode('/', strtolower(substr($_SERVER['REQUEST_URI'], 1)));
  $page_name = (string) $requestURI[1];
  $id_newsletter = (int) $requestURI[2];
  $action = $requestURI[3];
  if (!empty($id_newsletter)) {$page = (string) $requestURI[1];} else {$page = '';}
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
            <div class="col-md-6 mt10 text-center"><h4>Biuletyn</h4></div>
            <div class="col-md-3 text-right"><button class="btn btn-grey" onclick="AddNewsletter();"><i class="far fa-plus-square"></i> Dodaj nowy</button></div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div id="cpanel" class="col-md-12">
<?php 
  if (isset($action) && $action == 'edytuj') {
    echo $getcPanel->getNewsletter($id_newsletter);
  } else {
    echo $getcPanel->getNewsletters($pagination, $page_name);
  }
?>
      </div>
    </div> 
  </div>
</div>
<?php 
  } else {header('Location: '.URL.'cpanel');}
?>