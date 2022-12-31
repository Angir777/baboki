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
  $id_order = (int) $requestURI[2];
  $action = $requestURI[3];
  if (!empty($id_order)) {$page = (string) $requestURI[1];} else {$page = '';}
  if ($requestURI[2]=='strona'){$pagination = (int) $requestURI[3];}
  if ($_SESSION['user']['logged'] == true) {
    if ($page_name == 'do-oplacenia') {
      $title_page = 'Zamówienia do opłacenia';
    } elseif ($page_name == 'w-trakcie') {
      $title_page = 'Zamówienia w trakcie realizacji';
    } elseif ($page_name == 'wyslane') {
      $title_page = 'Zamówienia wysłane';
    } elseif ($page_name == 'zakonczone') {
      $title_page = 'Zamówienia zakończone';
    } elseif ($page_name == 'anulowane') {
      $title_page = 'Zamówienia anulowane';
    } elseif ($page_name == 'zamowienia') {
      $title_page = 'Wszystkie zamówienia';
    }
?>
<div class="single_services text-left mt30 mb20">
  <div class="container">
    <div class="row">
      <div id="cpanel" class="col-md-12">
        <div class="card step-one">
          <div class="row card-body mb20">
            <div class="col-md-3"><a href="<?= URL ?>cpanel/<?= $page ?>" class="btn btn-grey"><i class="fas fa-long-arrow-alt-left"></i> Powrót</a></div>
            <div class="col-md-6 mt10 text-center"><h4><?= $title_page ?></h4></div>
            <div class="col-md-3 text-right"></div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div id="cpanel" class="col-md-12">
<?php 
  if (isset($action) && $action == 'edytuj') {
    echo $getcPanel->getOrder($id_order, $page_name, $l);
  } else {
    echo $getcPanel->getOrders($pagination, $page_name);
  }
?>
      </div>
    </div> 
  </div>
</div>
<?php 
  } else {header('Location: '.URL.'cpanel');}
?>