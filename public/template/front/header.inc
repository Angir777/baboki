<?php

    /**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

    // here load app process in future
    $number_order = 0;
    if (!empty($_SESSION['cart'])) {
      $array = $_SESSION['cart'];
      foreach ($array as $item) {
        $number_order += $item['4'];
      }
    }
?>
<!DOCTYPE html>
<html lang="<?= $lang ?>">
  <head>
    <meta charset="utf-8">
    <title><?= $l['page_title'] ?> - Baboki.com‎</title>
    <?php if ($_SESSION['pageSite']!='creator') {echo '<meta name="viewport" content="width=device-width, initial-scale=1.0">';} ?>
    <meta name="description" content="<?= $l['meta_description'] ?>">
    <meta name="keywords" content="<?= $l['meta_keywords'] ?>">
    <meta name="theme-color" content="#8383ff">
    <meta name="google-site-verification" content="l1nb1tSU9OcIBJnNL1fHspGbRzAc7k9aIqe8CmI2UjM">
<?php /* if ($_SESSION['pageSite']=='cpanel') {
      echo '
        <meta name="robots" content="noindex, nofollow">
        <meta name="googlebot" content="noindex, nofollow">
      ';
    } else {
      echo '
        <meta name="robots" content="index, follow">
        <meta name="googlebot" content="index, follow">
      ';
    }
*/ ?>
    <!-- favicons -->
    <link rel="shortcut icon" href="<?= URL ?>template/<?= VIEW ?>/images/favicon.ico" type="image/x-icon">
    <!-- bootstrap -->
    <link rel="stylesheet" href="<?= URL ?>vendor/twbs/bootstrap/dist/css/bootstrap.min.css">
    <!-- fontawesome -->
    <link rel="stylesheet" href="<?= URL ?>vendor/fortawesome/font-awesome/css/all.min.css">
    <!-- main style -->
    <link rel="stylesheet" href="<?= URL ?>template/<?= VIEW ?>/css/style.min.css">
    <link rel="stylesheet" href="<?= URL ?>template/<?= VIEW ?>/css/shop.min.css">
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
    <!-- Google Analytics -->
    <script async src="https://www.googletagmanager.com/gtag/js?id=UA-123087981-1"></script>
    <script>
      window.dataLayer = window.dataLayer || [];
      function gtag(){dataLayer.push(arguments);}
      gtag('js', new Date());
      gtag('config', 'UA-123087981-1');
    </script>
    <script src="https://www.google.com/recaptcha/api.js"></script>
<?php
  if ($_SESSION['user']['logged'] == true) {
    echo '<link rel="stylesheet" href="'.URL.'template/'.VIEW.'/css/control.min.css">';
    if ( DEV == true ) {
      echo '<link rel="stylesheet" href="'.URL.'template/'.VIEW.'/css/dev.min.css">';
    }
  }
?>
    <!-- social media -->
    <meta property="og:url" content="<?= URL ?>" />
    <meta property="og:type" content="website" />
    <meta property="og:title" content="<?= $l['social_1'] ?>" />
    <meta property="og:description" content="<?= $l['social_2'] ?>" />
    <meta property="og:image" content="<?= URL ?>template/<?= VIEW ?>/images/banner.jpg" />
    <meta property="og:image:alt" content="<?= $l['social_3'] ?>" />
  </head>
  <body>
    <?php 
      // Module: check_rabat [SHOP]
      include ('lib/check_rabat/loader.inc');
      // Cart number
      $number_order = 0;
      if (!empty($_SESSION['cart'])) {
        $array = $_SESSION['cart'];
        foreach ($array as $item) {
          $number_order += $item['4'];
          $_SESSION['number_order'] = $number_order;
        }
      }
      // Menu shop block in dev
      if ((DEV == true) && ($_SESSION['user']['logged'] != true)) {
        $disabledLink = 'class="disabled"';
        echo '
          <div id="promo-bar" style="display:block">
            <div class="container-fluid">
              <div class="row">
                <div class="col">
                  <div class="promo-bar-main"> 
                    <p class="promo-cta">
                      '.$l['technicalBreak'].'
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        ';
      } else {$disabledLink = '';}
    ?>
    <!-- header start -->
    <div class="header-wrapper">
      <div class="container">
        <div class="row">
          <div class="col-lg-2 col-md-2 col-sm-12 col-xs-12 text-center">
            <a href="<?= URL ?>">
              <img src="<?= URL ?>template/<?= VIEW ?>/images/logo.png" alt="BABOKI.COM">
            </a>
          </div>
          <div class="col-lg-8 col-md-10 col-sm-12 col-xs-12">
            <div class="navigation">
              <div id="navigation">
                <ul>
                  <li <?php if($_SESSION['pageSite']=='home'){echo'class="active"';} else{} ?>>
                    <a href="<?= URL ?>" title="<?= $l['menu_start'] ?>"><?= $l['menu_start'] ?></a>
                  </li>
                  <li <?php if($_SESSION['pageSite']=='about'){echo'class="active"';} else{} ?>>
                    <a href="<?= URL . friendly_url($l['menu_about_baboki']) ?>" title="<?= $l['menu_about_baboki'] ?>"><?= $l['menu_about_baboki'] ?></a>
                  </li>
                  <li <?php if($_SESSION['pageSite']=='creator'){echo'class="active"';} else{} ?>>
                    <a href="<?= URL . friendly_url($l['menu_own_plush_toy']) ?>" title="<?= $l['menu_own_plush_toy'] ?>"<?= $disabledLink ?>><?= $l['menu_own_plush_toy'] ?></a>
                  </li>
                  <li <?php if($_SESSION['pageSite']=='shop' || $_SESSION['pageSite']=='shop-product'){echo'class="active"';} else{} ?>>
                    <a href="<?= URL . friendly_url($l['menu_shop']) ?>" title="<?= $l['menu_shop'] ?>"<?= $disabledLink ?>><?= $l['menu_shop'] ?></a>
                  </li>
                  
                  <li <?php if($_SESSION['pageSite']=='contact'){echo'class="active"';} else{} ?>>
                    <a href="<?= URL . friendly_url($l['menu_contact']) ?>" title="<?= $l['menu_contact'] ?>"><?= $l['menu_contact'] ?></a>
                  </li>
                  <li class="hidden-lg shopping-cart">
                    <a href="<?= URL . friendly_url($l['menu_cart']) ?>" title="<?= $l['menu_cart'] ?>"><?= $l['menu_cart'] ?> [<span id="shopping_number_small"><?= $number_order ?></span>]</a>
                  </li>
                </ul>
              </div>
            </div>
          </div>
          <div class="col-lg-2 hidden-md hidden-sm hidden-xs">
            <div class="header-btn shopping-cart">
              <a href="<?= URL . friendly_url($l['menu_cart']) ?>" class="btn btn-default" title="<?= $l['menu_cart'] ?>"><?= $l['menu_cart'] ?></a>
              <span id="shopping_number"><?= $number_order ?></span>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php 
    /*
    $to = '';
    $subject = 'subject';
    $message = 'message';
    $type = 'plain'; // or HTML
    $charset = 'utf-8';

    $mail     = 'no-reply@'.str_replace('www.', '', $_SERVER['SERVER_NAME']);
    $uniqid   = md5(uniqid(time()));
    $headers  = 'From: '.$mail."\n";
    $headers .= 'Reply-to: '.$mail."\n";
    $headers .= 'Return-Path: '.$mail."\n";
    $headers .= 'Message-ID: <'.$uniqid.'@'.$_SERVER['SERVER_NAME'].">\n";
    $headers .= 'MIME-Version: 1.0'."\n";
    $headers .= 'Date: '.gmdate('D, d M Y H:i:s', time())."\n";
    $headers .= 'X-Priority: 3'."\n";
    $headers .= 'X-MSMail-Priority: Normal'."\n";
    $headers .= 'Content-Type: multipart/mixed;boundary="----------'.$uniqid.'"'."\n";
    $headers .= '------------'.$uniqid."\n";
    $headers .= 'Content-type: text/'.$type.';charset='.$charset.''."\n";
    $headers .= 'Content-transfer-encoding: 7bit';

    mail($to, $subject, $message, $headers);
    */
    ?>