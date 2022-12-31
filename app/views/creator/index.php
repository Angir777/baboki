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
	// menu shop block in dev
    if ((DEV == true) && ($_SESSION['user']['logged'] != true)) {header('Location: '.URL);}
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
<div class="space-medium">
	<div class="container">
		<div class="row">
			<div class="col-lg-6 col-md-6 col-sm-12 col-xs-12">
				<div class="about-section">
					<h1><?= $l['c_3'] ?></h1>
					<div class="divider additional"></div>
					<?= $l['c_4'] ?><br><br><?= $l['c_5']; ?>
				</div>
			</div>
			<div class="col-lg-6 col-md-6 col-sm-12 col-xs-12">
				<img src="<?= URL ?>template/<?= VIEW ?>/images/creator_picture2.jpg" alt="Babok Rockowy" class="img-responsive">
			</div>
		</div>
		
		<div class="row mt30">
			<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
				<div class="section-title">
					<h1><?= $l['c_6'] ?></h1>
					<div class="divider"></div>
					<p><?= $l['c_7'] ?></p>
				</div>
			</div>
		</div>
	</div>
</div>
<div class="container-fluid">
	<form action="<?= URL ?>template/<?= VIEW ?>/lib/creator/creator.inc.php" method="POST">	
		<div class="row mb20" style="border:1px solid #dddddd;background:#eee;">
			<div class="col-md-4 col-sm-12 bg-light nopadding" style="border-right:1px solid #dddddd;">
				<div id="tabs">
					<ul class="nav nav-tabs text-center" role="tablist">
						<li class="nav-item active" style="width:50%;">
							<a class="nav-link" data-toggle="tab" href="#frontend" role="tab_preview" aria-expanded="true"><?= $l['c_19'] ?></a>
						</li>
						<li class="nav-item" style="width:50%;">
							<a class="nav-link" data-toggle="tab" href="#backend" role="tab_preview" aria-expanded="false"><?= $l['c_20'] ?></a>
						</li>
					</ul>
					<div class="tab-content">
						<!-- FRONT -->
						<div class="tab-pane active" id="frontend" role="tab_preview" aria-expanded="true">
							<div id="b_main">
								
								<img id="b_accessories_16_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_11_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_9_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								
								<img id="b_handle_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_handle/b_handle_0.png">
								<img id="b_ears_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_ears/b_ears_0_front.png">
								<img id="b_color_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_color/b_color_1_front.png">
								<img id="b_face" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_face/b_face_0.png">
								<img id="b_mimicry" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_mimicry/b_mimicry_0.png">
								
								<img id="b_accessories_25_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_26_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_27_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">

								<img id="b_nose" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_nose/b_nose_0.png">
								
								<img id="b_accessories_1_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_3_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_4_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_5_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_6_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_7_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_8_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_15_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_12_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_14_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_17_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_18_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_19_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_20_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_21_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_22_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_23_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_24_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_28_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_2_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_29_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								
								<img id="b_eyes" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_eyes/b_eyes_0.png">
								
								<img id="b_accessories_13_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
								<img id="b_accessories_10_front" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png">
							</div>
						</div>
						<!-- BACK -->
						<div class="tab-pane" id="backend" role="tab_preview">
							<div id="b_main">
								<img id="b_handle_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_handle/b_handle_0.png">
								<img id="b_accessories_1_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_ears_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_ears/b_ears_0_back.png">
								<img id="b_color_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_color/b_color_1_back.png">
								
								<img id="b_accessories_3_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_4_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_5_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_6_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_14_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								
								<img id="b_accessories_17_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_18_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_19_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_20_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_21_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_22_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_23_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_24_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_25_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_26_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								
								<img id="b_accessories_13_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_15_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_12_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_10_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_9_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_2_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_29_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_11_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
								<img id="b_accessories_16_back" src="<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png">
							</div>
						</div>
					</div>
				</div>
			</div>
			<div class="col-md-6 col-sm-9 bg-light nopadding">		
				<?php 
				/*
					Brak produktu: <div class="col-lg-4 col-md-6 col-sm-6"> + .none-product, input + disabled
				*/
				?>
				<input type="hidden" name="product" value="1">
				<input type="hidden" name="lang" value="<?= $lang ?>">
				<div class="tab-content pinside20 scroll">
			      	<!-- color -->
			      	<div class="tab-pane active" id="color-tab" role="tab_edit" aria-expanded="true">
			      		<h2><i class="fas fa-fill-drip"></i> <?= $l['c_8'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">			
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_color/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"));} else {$quantity = 0;}
										// description
										if ($lang == 'pl') {
											$arrayColor = ['None', 'Czerwony', 'Błękitny', 'Czarny', 'Biały', 'Niebieski', 'Pomarańczowy', 'Jasnoszary', 'Zielony', 'Ciemnoszary', 'Brązowy', 'Foletowy'];
										} else {
											$arrayColor = ['None', 'Red', 'Sky Blue', 'Black', 'White', 'Blue', 'Orange', 'Light Gray', 'Green', 'Dark Gray', 'Brown', 'Purple'];
										}
										// show
										for ($i=1; $i <= $quantity; $i++) { 
											$text=$l['c_17'].' '.$i;
											if ($i == 1) {$checked = 'checked';} else {$checked = '';}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q1_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_color_1" value="b_color_'.$i.'" onclick="changeColor(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q1_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_color/b_color_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'<br /><small>('.$arrayColor[$i].')</small></span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
								</div>
							</div>
						</div>
			      	</div>
			      	<!-- eye -->
			      	<div class="tab-pane" id="eye-tab" role="tab_edit">
			      		<h2><i class="fas fa-eye"></i> <?= $l['c_9'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_eyes/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text = $l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q2_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_eyes_1" value="b_eyes_'.$i.'" onclick="changeEyes(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q2_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_eyes/b_eyes_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
								</div>
							</div>
						</div>
			      	</div>
			      	<!-- mimicry -->
			      	<div class="tab-pane" id="masks-tab" role="tab_edit">
			      		<h2><i class="fas fa-theater-masks"></i> <?= $l['c_10'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_mimicry/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text=$l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q3_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_mimicry_1" value="b_mimicry_'.$i.'" onclick="changeMimicry(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q3_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_mimicry/b_mimicry_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			      	<!-- ears -->
			      	<div class="tab-pane" id="deaf-tab" role="tab_edit">
			      		<h2><i class="fas fa-deaf"></i> <?= $l['c_11'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_ears/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text = $l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q4_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_ears_1" value="b_ears_'.$i.'" onclick="changeEars(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q4_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_ears/b_ears_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			      	<!-- nose -->
			      	<div class="tab-pane" id="typo-tab" role="tab_edit">
			      		<h2><i class="fab fa-typo3"></i> <?= $l['c_12'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_nose/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text = $l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q6_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_nose_1" value="b_nose_'.$i.'" onclick="changeNose(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q6_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_nose/b_nose_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			      	<!-- face -->
			      	<div class="tab-pane" id="shapes-tab" role="tab_edit">
			      		<h2><i class="fas fa-shapes"></i> <?= $l['c_13'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_face/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text = $l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q5_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_face_1" value="b_face_'.$i.'" onclick="changeFace(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q5_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_face/b_face_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			      	<!-- paws -->
			      	<div class="tab-pane" id="paw-tab" role="tab_edit">
			      		<h2><i class="fas fa-paw"></i> <?= $l['c_14'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_handle/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"))-1;} else {$quantity = 0;}
										// show
										for ($i=0; $i <= $quantity; $i++) { 
											if ($i == 0) {$checked = 'checked';$text = $l['c_18'];} else {$checked = '';$text = $l['c_17'] . ' ' . $i;}
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q7_a'.$i.'" class="option-input checkbox" type="radio" name="form_check_handle_1" value="b_handle_'.$i.'" onclick="changeHandle(this)" '.$checked.'>
													<label for="hs_cos_wrapper_q7_a'.$i.'">
														<div class="estimate-project__radio js-estimate-radio">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_handle/b_handle_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'</span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			      	<!-- additives -->
			      	<div class="tab-pane" id="gamepad-tab" role="tab_edit">
			      		<h2><i class="fas fa-gamepad"></i> <?= $l['c_15'] ?></h2>
			      		<div class="row estimate-project__question-row">
							<div class="col-md-12">
								<div class="row pinside10">
									<?php 
										// cout files
										$directory = getcwd().'/template/'.VIEW.'/lib/creator/b_creator/b_icons/b_accessories/';
										if (glob($directory  . "*.png") != false) {$quantity = count(glob($directory . "*.png"));} else {$quantity = 0;}
										// description
										if ($lang == 'pl') {
											$arrayAccessories = ['None', 'Pióra', 'Miecz stalowy', 'Blizna', 'Wąs', 'Barwy wojenne 1', 'Barwy wojenne 2', 'Jack wąs', 'Serce', 'Skrzydełka', 'Pelerynka', 'Miecz świetlny', 'Flaczki', 'Okulary', 'Rock!', 'Czarny pas', 'Dwa miecze', 'Gwiazda 1', 'Gwiazda 2', 'Gwiazda 3', 'Gwiazda 4', 'Serduszko', 'Bródka 1', 'Bródka 2', 'Bródka 3', 'Wąsik/Nos 1', 'Wąsik/Nos 2', 'Wąsik/Nos 3', 'Rumieńce', 'Miecz srebny'];
										} else {
											$arrayAccessories = ['None', 'Feathers', 'Steel sword', 'Scar', 'Moustache', 'War colours 1', 'War colours 2', 'Jack mustache', 'Heart', 'Wings', 'Cape', 'Light sword', 'Guts', 'Glasses', 'Rock!', 'Black belt', 'Two swords', 'Star 1', 'Star 2', 'Star 3', 'Star 4', 'Small heart', 'Beard 1', 'Beard 2', 'Beard 3', 'Beard/Nose 1', 'Beard/Nose 2', 'Beard/Nose 3', 'Pink cheeks', 'Silver sword'];
										}
										// show
										for ($i=1; $i <= $quantity; $i++) { 
											$text = $l['c_17'].' '.$i;
											echo '
												<div class="col-lg-4 col-md-6 col-sm-6">
													<input id="hs_cos_wrapper_q8_a'.$i.'" type="checkbox" name="form_check_accessories[]" value="b_accessories_'.$i.'" onclick="changeAccessories(this,'.$i.')">
													<label for="hs_cos_wrapper_q8_a'.$i.'">
														<div class="estimate-project__checkbox js-estimate-checkbox">
															<div class="estimate-project__checkbox__icon">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_image">
																	<img src="'.URL.'template/'.VIEW.'/lib/creator/b_creator/b_icons/b_accessories/b_accessories_'.$i.'.png" class="hs-image-widget " style="width:121px;border-width:0px;border:0px;" alt="" title="" />
																</span>
															</div>
															<div class="estimate-project__checkbox__text">
																<span class="hs_cos_wrapper hs_cos_wrapper_widget hs_cos_wrapper_type_text">'.$text.'<br /><small>('.$arrayAccessories[$i].')</small></span>
															</div>
														</div>
													</label>
												</div>
											';
										}
									?>
			      				</div>
							</div>
						</div>
			      	</div>
			    </div>
			</div>
			<div class="col-md-2 col-sm-3 bg-light nopadding pdt10">
				<ul class="nav flex-column" id="creator-nav" role="tablist2" aria-orientation="vertical">
				  	<li class="nav-item text-center active"><a class="nav-link" data-toggle="tab" href="#color-tab" role="tab_edit" aria-controls="true"><i class="fas fa-fill-drip fa-2x"></i><br /><?= $l['c_8'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#eye-tab" role="tab_edit" aria-controls="false"><i class="fas fa-eye fa-2x"></i><br /><?= $l['c_9'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#masks-tab" role="tab_edit" aria-controls="false"><i class="fas fa-theater-masks fa-2x"></i><br /><?= $l['c_10'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#deaf-tab" role="tab_edit" aria-controls="false"><i class="fas fa-deaf fa-2x"></i><br /><?= $l['c_11'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#typo-tab" role="tab_edit" aria-controls="false"><i class="fab fa-typo3 fa-2x"></i><br /><?= $l['c_12'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#shapes-tab" role="tab_edit" aria-controls="false"><i class="fas fa-shapes fa-2x"></i><br /><?= $l['c_13'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#paw-tab" role="tab_edit" aria-controls="false"><i class="fas fa-paw fa-2x"></i><br /><?= $l['c_14'] ?></a></li>
				  	<li class="nav-item text-center"><a class="nav-link" data-toggle="tab" href="#gamepad-tab" role="tab_edit" aria-controls="false"><i class="fas fa-gamepad fa-2x"></i><br /><?= $l['c_15'] ?></a></li>
				</ul>
			</div>
		</div>
		<div class="row">
			<div class="col-md-9 col-sm-12"></div>
			<div class="col-md-3 col-sm-12"><button type="submit" name="submit" class="btn btn-primary btn-sm mb20 pinside20"><i class="fas fa-cart-arrow-down"></i> <?= $l['c_16'] ?></button></div>
		</div>
	</form>
</div>