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
  $showcPanelForm = $getcPanel->getForm($l);
  // work
  $l_error = '';
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["l_name"]) OR empty($_POST["l_password"])) {
      $l_error = '<div class="alert alert-danger">'.$l['c_5'].'</div>';
    } else {
      $login_name = check_inputs($_POST["l_name"]);
      $login_password = check_inputs($_POST["l_password"]);
      if ($getcPanel->getLogin($login_name, $login_password) == FALSE) {
        $l_error = '<div class="alert alert-danger">'.$l['c_5'].'</div>';
      } else {
         header('Location: '.URL.'cpanel');
      }
    }
  }
?>
<div class="space-medium bg-light">
  <div class="container">
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <h1><?= $l['c_1'] ?></h1>
          <div class="divider"></div>
          <p></p>
        </div>
      </div>
    </div>
  </div>
</div>
<?php
  if ($_SESSION['user']['logged'] == true) {
?>
<div class="single_services text-left mt30 mb20">
  <div class="container">
    <div class="row">
      <div class="col-lg-6 col-md-6 col-sm-6 col-xs-12">
        <div class="card card-banner card-green">
          <div class="card-body">
            <i class="icon fas fa-coins fa-4x"></i>
            <div class="content">
              <div class="title">Dzisiejszy zarobek</div>
              <div class="value"><span class="sign">PLN</span><?= $getcPanel->getCardSingle(1); ?></div>
            </div>
          </div>
        </div>
      </div>
      <div class="col-lg-6 col-md-6 col-sm-6 col-xs-12">
        <div class="card card-banner card-blue">
          <div class="card-body">
            <i class="icon fas fa-cart-arrow-down fa-4x"></i>
            <div class="content">
              <div class="title">Zamówień dzisiaj</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardSingle(2); ?></div>
            </div>
          </div>
        </div>
      </div>
      <div class="col-lg-6 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/magazyn" class="card card-banner card-purple">
          <div class="card-body">
            <i class="icon fas fa-boxes fa-4x"></i>
            <div class="content">
              <div class="title">Produktów w magazynie</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardMagazine(); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-6 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/anulowane" class="card card-banner card-red">
          <div class="card-body">
            <i class="icon far fa-trash-alt fa-4x"></i>
            <div class="content">
              <div class="title">Anulowane</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardStatusSingle(4); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/do-oplacenia" class="card card-banner card-yellow">
          <div class="card-body">
            <i class="icon fas fa-battery-quarter fa-4x"></i>
            <div class="content">
              <div class="title">Do opłacenia</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardStatusSingle(0); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/w-trakcie" class="card card-banner card-yellow">
          <div class="card-body">
            <i class="icon fas fa-battery-half fa-4x"></i>
            <div class="content">
              <div class="title">W trakcie</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardStatusSingle(1); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/wyslane" class="card card-banner card-yellow">
          <div class="card-body">
            <i class="icon fas fa-battery-three-quarters fa-4x"></i>
            <div class="content">
              <div class="title">Wysłane</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardStatusSingle(2); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/zakonczone" class="card card-banner card-yellow">
          <div class="card-body">
            <i class="icon fas fa-battery-full fa-4x"></i>
            <div class="content">
              <div class="title">Zakończone</div>
              <div class="value"><span class="sign"></span><?= $getcPanel->getCardStatusSingle(3); ?></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/slider" class="card card-banner card-brown">
          <div class="card-body">
            <i class="icon far fa-images fa-4x"></i>
            <div class="content">
              <div class="title">Slider</div>
              <div class="value"><span class="sign"></span></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/zamowienia" class="card card-banner card-brown">
          <div class="card-body">
            <i class="icon fas fa-file-invoice-dollar fa-4x"></i>
            <div class="content">
              <div class="title">Zamówienia</div>
              <div class="value"><span class="sign"></span></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/biuletyn" class="card card-banner card-brown">
          <div class="card-body">
            <i class="icon fas fa-envelope-open-text fa-4x"></i>
            <div class="content">
              <div class="title">Biuletyn</div>
              <div class="value"><span class="sign"></span></div>
            </div>
          </div>
        </a>
      </div>
      <div class="col-lg-3 col-md-6 col-sm-6 col-xs-12">
        <a href="<?= URL ?>cpanel/logout" class="card card-banner card-grey">
          <div class="card-body">
            <i class="icon fas fa-sign-out-alt fa-4x"></i>
            <div class="content">
              <div class="title">Wyloguj</div>
              <div class="value"><span class="sign"></span></div>
            </div>
          </div>
        </a>
      </div>
    </div>
  </div>
</div>
<?php 
  } else {
?>
<div class="space-medium single_services text-left">
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-xs-12">
        <h4><?= $l['c_1'] ?></h4>
        <div class="divider additional"></div>
        <div class="header-text mt-5">
          <?php if (!empty($l_error)) {echo $l_error;} ?>
          <?= $showcPanelForm ?>
        </div>
      </div>
      <div class="col-md-6 col-xs-12 mt20">
        <div class="header-circle">
          <div class="header-circle-icon">
            <i class="fas fa-user-lock"></i>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<?php 
  }
?>