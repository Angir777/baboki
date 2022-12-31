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
    $getContact = new Contact();
    $showFormContact = $getContact->getForm($lang, $l);
?>
<div class="space-medium bg-light">
  <div class="container">
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <h1><?= $l['c_1'] ?></h1>
          <div class="divider"></div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <p><?= $l['c_2'] ?></p>
        </div>
      </div>
    </div>
  </div>
</div>
<?= $showFormContact ?>
<div class="space-medium">
  <div class="container">
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <h3><?= $l['c_3'] ?></h3>
          <div class="divider"></div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
        <div class="section-title">
          <p><?= $l['c_4'] ?></p>
        </div>
      </div>
    </div>
  </div>
</div>