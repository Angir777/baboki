<?php

	/**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

	// global varables
	global $lang;										// Global language varable
	global $l; 											// Global language array
	// initiating the model
	$getHome = new Home();
	$showSliderHome = $getHome->getSlider($lang, $l);
	$showMiniSliderHome = $getHome->getMiniSlider($lang);
?>
<div class="slider">
	<div class="owl-carousel slider">
		<?= $showSliderHome ?>
	</div>
</div>
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
		<div class="row">
			<div class="col-lg-6 col-md-6 col-sm-12 col-xs-12">
				<div class="about-section">
					<h2><?= $l['c_3'] ?></h2>
					<div class="divider additional"></div>
					<p><?= $l['c_4'] ?></p>
					<p><?= $l['c_5'] ?></p>
					<div class="row">
						<div class="col-lg-6 col-md-6 col-sm-6 col-xs-12 mt20">
							<h3><?= $l['c_6'] ?></h3>
							<p><?= $l['c_7'] ?></p>
							<a href="<?= URL.friendly_url($l['menu_shop']) ?>" class="btn btn-default" title="<?= $l['menu_shop'] ?>"><?= $l['menu_shop'] ?></a>
						</div>
						<div class="col-lg-6 col-md-6 col-sm-6 col-xs-12 mt20">
							<h3><?= $l['c_8'] ?></h3>
							<p><?= $l['c_9'] ?></p>
							<a href="<?= URL.friendly_url($l['menu_own_plush_toy']) ?>" class="btn btn-primary hvr-buzz-out" title="<?= $l['menu_own_plush_toy'] ?>"><?= $l['c_10'] ?></a>
						</div>
					</div>
				</div>
			</div>
			<div class="col-lg-offset-1 col-lg-5 col-md-5 col-md-offset-1 col-sm-12 col-xs-12">
				<div class="">
					<img src="<?= URL ?>template/<?= VIEW ?>/images/about-pic.jpg" alt="Babox Indianin przy wielkim drzewie" class="img-responsive">
				</div>
			</div>
		</div>
	</div>
</div>
<div class="container-fluid bg-gradient">
	<div class="row">
		<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
			<div class="section-title mt30">
				<h2><?= $l['c_11'] ?></h2>
				<div class="divider"></div>
				<a href="https://www.instagram.com/baboki_com/" rel="nofollow" target="_blank" title="@baboki_com" class="btn btn-primary bnt_pulse mt30">baboki_com</a>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="gallery-slider-carousel">
			<div class="owl-carousel slider minislider">
				<?= $showMiniSliderHome ?>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
			<div class="section-title mt60">
				<h2><?= $l['c_19'] ?></h2>
				<p><?= $l['c_20'] ?></p>
				<div class="divider"></div>
				<button type="button" class="btn btn-primary mt30 bnt_newsletter" data-toggle="modal" data-target="#single-dialog"><?= $l['c_21'] ?></button>
			</div>
		</div>
	</div>
</div>
<div class="space-medium">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="section-title">
					<h2><?= $l['c_12'] ?></h2>
					<div class="divider"></div>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-lg-3 col-md-3 col-sm-6 col-xs-12">
				<div class="post-block">
					<div class="post-img">
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/4" class="imghover" title="">
							<img src="<?= URL.'template/'.VIEW ?>/images/post-img-small-2.jpg" alt="Babok Wiedźminek" class="img-responsive">
						</a>
					</div>
					<div class="post-content">
						<div class="meta">
							<span class="meta-categories">Babok</span>
							<span class="meta-date"></span>
						</div>
						<h3><a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/4" class="title" title="Babok Wiedźminek">Wiedźminek</a></h3>
						<p><?= substr($l['c_14'], 0, 100) ?> [...]</p>
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/4" class="btn-link" title="<?= $l['c_22'] ?>">Babok Wiedźminek <i class="fas fa-long-arrow-alt-right"></i></a>
					</div>
				</div>
			</div>
			<div class="col-lg-3 col-md-3 col-sm-6 col-xs-12">
				<div class="post-block">
					<div class="post-img">
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/11" class="imghover" title="">
							<img src="<?= URL.'template/'.VIEW ?>/images/post-img-small-3.jpg" alt="Babok Babpool" class="img-responsive">
						</a>
					</div>
					<div class="post-content">
						<div class="meta">
							<span class="meta-categories">Babok</span>
							<span class="meta-date"></span>
						</div>
						<h3><a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/11" class="title" title="Babok Babpool">Babpool</a></h3>
						<p><?= substr($l['c_15'], 0, 100) ?> [...]</p>
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/11" class="btn-link" title="<?= $l['c_22'] ?>">Babok Babpool <i class="fas fa-long-arrow-alt-right"></i></a>
					</div>
				</div>
			</div>
			<div class="col-lg-3 col-md-3 col-sm-6 col-xs-12">
				<div class="post-block">
					<div class="post-img">
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/12" class="imghover" title="">
							<img src="<?= URL.'template/'.VIEW ?>/images/post-img-small-1.jpg" alt="Kapitan Babok" class="img-responsive">
						</a>
					</div>
					<div class="post-content">
						<div class="meta">
							<span class="meta-categories">Babok</span>
							<span class="meta-date"></span>
						</div>
						<h3><a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/12" class="title" title="Kapitan Babok">Kapitan Babok</a></h3>
						<p><?= substr($l['c_13'], 0, 100) ?> [...]</p>
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/12" class="btn-link" title="<?= $l['c_22'] ?>">Kapitan Babok <i class="fas fa-long-arrow-alt-right"></i></a>
					</div>
				</div>
			</div>
			<div class="col-lg-3 col-md-3 col-sm-6 col-xs-12">
				<div class="post-block">
					<div class="post-img">
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/13" class="imghover" title="">
							<img src="<?= URL.'template/'.VIEW ?>/images/post-img-small-4.jpg" alt="Kicaj" class="img-responsive">
						</a>
					</div>
					<div class="post-content">
						<div class="meta">
							<span class="meta-categories">Babok</span>
							<span class="meta-date"></span>
						</div>
						<h3><a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/13" class="title" title="Kicaj">Kicaj</a></h3>
						<p><?= substr($l['c_23'], 0, 100) ?> [...]</p>
						<a href="<?= URL.friendly_url($l['menu_shop']).'/'.$l['shop_product'] ?>/13" class="btn-link" title="<?= $l['c_22'] ?>">Babok Kicaj <i class="fas fa-long-arrow-alt-right"></i></a>
					</div>
				</div>
			</div>
		</div>
		 <div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 text-center">
				<a href="<?= URL . friendly_url($l['menu_shop']) ?>" class="btn btn-primary btn-lg mb20" title="<?= $l['c_16'] ?>"><?= $l['c_16'] ?></a>
			</div>
		</div>
	</div>
</div>
<div class="space-medium bg-light">
	<div class="container">
		<div class="testimonial-carousel mb50">
			<div class="owl-carousel slider">
				<div class="item">
					<div class="col-lg-offset-3 col-lg-6 col-md-offset-3 col-md-6 col-sm-12 col-xs-12">
						<div class="">
							<div class="testimonial-content">
								<div class="testimonial-icon"><img src="<?= URL.'template/'.VIEW ?>/images/quote.png" alt="Pozytywna opinia"></div>
								<?php /*<div class="">
									<ul><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li></ul>
							 	</div> */ ?>
								<h5>"<?= $l['c_17'] ?>"</h5>
								<p class="testimonial-text"></p>
								<div class="testimonial-meta"><span>- Marta</span></div>
							</div>
						</div>
					</div>
				</div>
				<div class="item">
					<div class="col-lg-offset-3 col-lg-6 col-md-offset-3 col-md-6 col-sm-12 col-xs-12">
						<div class="">
							<div class="testimonial-content">
								<div class="testimonial-icon"><img src="<?= URL.'template/'.VIEW ?>/images/quote.png" alt="Pozytywna opinia"></div>
								<?php /*<div class="">
									<ul><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li><li><i class="fa fa-star"></i></li></ul>
							 	</div> */ ?>
								<h5>"<?= $l['c_18'] ?>"</h5>
								<p class="testimonial-text"></p>
								<div class="testimonial-meta"><span>- Zosia</span></div>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>