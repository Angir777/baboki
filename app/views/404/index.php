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
?>
<div class="space-medium bg-light">
	<div class="container">
		<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="section-title">
					<h1>404</h1>
					<div class="divider"></div>
					<p><?= $l['e404_1'] ?></p>
				</div>
			</div>
		</div>
	</div>
</div>
<div class="space-medium single_services text-left">
	<div class="container">
		<div class="row">
			<div class="col-md-6 col-xs-12">
				<h4><?= $l['e404_2'] ?></h4>
				<div class="divider additional"></div>
				<div class="header-text mt-5">
					<ul>
						<?= $l['e404_3'] ?>
					</ul>
					<p><?= $l['e404_4'] ?><a href="<?= URL ?>" title="BABOKI.COM"><?= $l['e404_5'] ?></a>.</p>
				</div>
			</div>
			<div class="col-md-6 col-xs-12 mt20">
				<div class="header-circle">
					<div class="header-circle-icon">
						<i class="fas fa-map-signs"></i>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>