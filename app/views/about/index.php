<?php

    /**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

    // global varables
    global $lang;                                       // Global language varable
    global $l;                                          // Global language array
    // initiating the model
    $getAbout = new About();
    $showMiniSliderAbout = $getAbout->getMiniSlider($lang);
?>
<div class="space-medium bg-light">
  <div class="container">
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <h1><?= $l['c_1'] ?></h1>
          <div class="divider"></div>
          <p><?= $l['c_2'] ?></p>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="container-fluid">
  <div class="row">
    <div class="gallery-slider-carousel">
      <div class="owl-carousel slider minislider">
        <?= $showMiniSliderAbout ?>
      </div>
    </div>
  </div>
</div>
<div class="space-medium">
  <div class="container">
    <div class="row">
      <div class="col-lg-5 col-md-5 col-sm-12 col-xs-12">
        <div class="about-section">
          <div>
            <h1><?= $l['c_3'] ?></h1>
            <div class="divider additional"></div>
          </div>
          <div class="about-right">
            <ul>
              <?= $l['c_4'] ?>
            </ul>
          </div>
        </div>
      </div>
      <div class="col-lg-6 col-lg-offset-1 col-md-6 col-md-offset-1 col-sm-12 col-xs-12">
        <img src="<?= URL ?>template/<?= VIEW ?>/images/profile_<?= $lang ?>.jpg" alt="<?= $l['c_8'] ?>" class="img-responsive">
      </div>
    </div>
    <div class="row">
      <div class="col-lg-4 col-md-4 col-sm-12 col-xs-12">
        <div class="about-section">
          <div>
            <h1><?= $l['c_5'] ?></h1>
            <div class="divider additional"></div>
          </div>
          <div class="about-right">
            <ul>
              <?= $l['c_6'] ?>
            </ul>
            <a href="<?= URL . friendly_url($l['menu_own_plush_toy']) ?>" title="<?= $l['c_7'] ?>" class="btn btn-primary btn-sm mb20 mt30"><?= $l['c_7'] ?></a>
          </div>
        </div>
      </div>
      <div class="col-lg-7 col-lg-offset-1 col-md-6 col-md-offset-1 col-sm-12 col-xs-12">
        <img src="<?= URL ?>template/<?= VIEW ?>/images/creator_picture_<?= $lang ?>.gif" alt="<?= $l['c_7'] ?>" class="img-responsive">
      </div>
    </div>
  </div>
</div>