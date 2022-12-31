<?php

    /**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

?>
        <!-- footer start -->
        <div class="footer">
            <div class="container">
                <div class="row">
                    <div class="col-lg-4 col-md-4 col-sm-6 col-xs-12 ">
                        <div class="footer-widget">
                            <h3 class="footer-title">BABOKI.COM</h3>
                            <div class="">
                                <ul>
                                    <li>
                                        <i class="fas fa-paper-plane"></i>
                                        <?= EMAIL_COMPANY ?>
                                    </li>
                                    <li>
                                        <i class="fas fa-map-marker-alt"></i>
                                        <?= ADDRESS_COMPANY ?>, <?= $l['footer_1'] ?>
                                    </li>
                                    <li class="instafooter">
                                        <i class="fab fa-instagram"></i>
                                        <?= $l['footer_2'] ?><a href="https://www.instagram.com/baboki_com/" rel="nofollow" target="_blank" title="@baboki_com"><?= $l['footer_3'] ?></a>
                                    </li>
                                    <li>
                                        <i class="fas fa-paragraph"></i>
                                        <?= $l['footer_4'] ?> 
                                        <select id="langSelect" onchange="changeLang();">
                                            <option value="pl" <?php if($_SESSION['lang']=='pl'){echo'selected="selected"';} else{} ?> >polski</option>
                                            <option value="en" <?php if($_SESSION['lang']=='en'){echo'selected="selected"';} else{} ?> >english</option>
                                        </select>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                    <div class="col-lg-4 col-md-4 col-sm-6 col-xs-12">
                        <div class="footer-widget">
                            <h3 class="footer-title"><?= $l['footer_5'] ?></h3>
                            <ul class="angle angle-right">
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_returns_and_complaints']) ?>" title="<?= $l['menu_returns_and_complaints'] ?>"><?= $l['menu_returns_and_complaints'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_privacy_policy']) ?>" title="<?= $l['menu_privacy_policy'] ?>"><?= $l['menu_privacy_policy'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_regulations']) ?>" title="<?= $l['menu_regulations'] ?>"><?= $l['menu_regulations'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_delivery_methods']) ?>" title="<?= $l['menu_delivery_methods'] ?>"><?= $l['menu_delivery_methods'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_forms_of_payment']) ?>" title="<?= $l['menu_forms_of_payment'] ?>"><?= $l['menu_forms_of_payment'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_faq']) ?>" title="<?= $l['menu_faq'] ?>"><?= $l['menu_faq'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_cooperation']) ?>" title="<?= $l['menu_cooperation'] ?>"><?= $l['menu_cooperation'] ?></a>
                                </li>
                                <li>
                                    <a href="<?= URL . friendly_url($l['menu_status_order']) ?>" title="<?= $l['menu_status_order'] ?>"><?= $l['menu_status_order'] ?></a>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <div class="col-lg-4 col-md-4 col-sm-6 col-xs-12">
                        <div class="footer-widget">
                            <h3 class="footer-title"><?= $l['footer_6'] ?></h3>
                            <ul>
                                <?php 
                                if (DELIVERY_PERSONAL == true) {
                                    echo '
                                        <li>
                                            <i class="fas fa-handshake"></i>
                                            '.$l['delivery_personal_name'].'
                                        </li>
                                    ';
                                }
                                if (DELIVERY_INPOST == true) {
                                    echo '
                                        <li>
                                            <i class="fas fa-city"></i>
                                            '.$l['delivery_inpost_name'].'
                                        </li>
                                    ';
                                }
                                if (DELIVERY_DPD == true || DELIVERY_DPD_WORLD == true) {
                                    echo '
                                        <li>
                                            <i class="fas fa-truck"></i>
                                            '.$l['delivery_dpd_name'].'
                                        </li>
                                    ';
                                }
                                ?>
                            </ul>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="tiny-footer">
                            <?= $l['footer_10'] ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!-- jquery -->
        <script src="<?= URL ?>template/<?= VIEW ?>/js/jquery.min.js"></script>
        <!-- navigation -->
        <script async src="<?= URL ?>template/<?= VIEW ?>/js/sticky-header.min.js"></script>
        <script async src="<?= URL ?>template/<?= VIEW ?>/js/navigation.min.js"></script>
        <script async src="<?= URL ?>template/<?= VIEW ?>/js/menumaker.min.js"></script>
        <!-- modules -->
        <?php
        // Module: preloader
        if ($_SESSION['pageSite']!='delivery-and-payment') {include ('lib/preloader/loader.inc');}
        // Module: back-to-top
        include ('lib/back-to-top/loader.inc');
        // Module: hover
        include ('lib/hover/loader.inc');
        // Module: cookies
        include ('lib/cookies/loader.inc');
        // Module: lang_switch
        include ('lib/lang_switch/loader.inc');
        // Module: slider
        if ($_SESSION['pageSite']=='' || $_SESSION['pageSite']=='home' || $_SESSION['pageSite']=='about') {include ('lib/slider/loader.inc');}
        // Module: lightbox
        if ($_SESSION['pageSite']=='blog') {include ('lib/lightbox/loader.inc');}
        // Module: newsletter [SHOP]
        if ($_SESSION['pageSite']!='contact') {include ('lib/newsletter/loader.inc');}
        // Module: mailer [SHOP]
        if ($_SESSION['pageSite']=='contact') {include ('lib/mailer/loader.inc');}
        // Module: price-scroller [SHOP]
        if ($_SESSION['pageSite']=='shop') {include ('lib/price-scroller/loader.inc');}
        // Module: products-gallery [SHOP]
        if ($_SESSION['pageSite']=='shop-product') {include ('lib/products-gallery/loader.inc');}
        // Module: creator [SHOP]
        if ($_SESSION['pageSite']=='creator') {include ('lib/creator/loader.inc');}
        // Module: control [CONTROL]
        if ($_SESSION['user']['logged'] == true) {include ('lib/control/loader.inc');}
        ?>
        <!-- /modules -->
        <!-- bootstrap -->
        <script src="<?= URL ?>vendor/twbs/bootstrap/dist/js/bootstrap.min.js"></script>
    </body>
</html>