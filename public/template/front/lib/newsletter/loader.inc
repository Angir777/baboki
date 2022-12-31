<?php

    /**
    * This file is part of BABOKI.COM
    * Module: newsletter
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

?>
<!-- newsletter -->
<?php
	$banip = array("188.92.74.189");
	if (in_array ($_SERVER['REMOTE_ADDR'], $banip)) {} else {
		if (!isset($_COOKIE['_br'])) {setcookie("_br", "0", time()+7200, "/");}
		if ($_COOKIE['_br'] == 0) {
			if ($_SESSION['pageSite']=='newsletter') {} else {
				if (SINGLE_DIALOG == true) { 
?>
<div id="modal-content" class="modal fade" tabindex="-1" role="dialog">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header text-center">
				<button type="button" class="close" data-dismiss="modal">×</button>
				<p><?= $l['modalBox_1'] ?></p><h3><?= $l['modalBox_2'] ?></h3><p><?= $l['modalBox_3'] ?></p><br>
			</div>
			<form id="ajax-newsletter" method="post" action="<?= URL ?>template/<?= VIEW ?>/lib/newsletter/newsletter.inc.php">
				<div id="newsletter-form">
					<div class="modal-body">
						<div id="loading_banner"><img src="<?= URL ?>public/template/<?= VIEW ?>/images/loader_color.gif" alt="loader"></div>
						<div class="form-group pdb20">
							<div class="col-sm-1"></div>
							<div class="col-sm-10">
								<div id="option-group">
									<input type="hidden" name="lang" value="<?= $_SESSION['lang'] ?>">
									<input type="hidden" name="l" value="<?= $l ?>">
									<input type="hidden" name="addr" value="<?= $_SERVER['REMOTE_ADDR'] ?>">
								</div>
								<div id="email-group">
									<input type="email" name="email" class="form-style-newsletter" id="inputEmail" placeholder="<?= $l['modalBox_4'] ?>*" required>
								</div>
								<div id="re-group">
									<label for="re"><?= $l['modalBox_8'] ?>*</label>
									<div id="re" class="g-recaptcha" style="transform:scale(0.7);transform-origin:0;-webkit-transform:scale(0.7);transform:scale(0.7);-webkit-transform-origin:0 0;transform-origin:0 0;" data-sitekey="6LcsSn4UAAAAAKZ69Jlb8DmrcBPGf69N06vZDr1D"></div>
								</div>
							</div>
							<div class="col-sm-1"></div>
						</div>
					</div>
					<div class="modal-footer"><button type="submit" class="btn btn-white"><?= $l['modalBox_5'] ?></button></div>
				</div>
			</form>
			<div class="modal-footer"> 
				<div class="col-xs-6 text-left"><p><?= $l['modalBox_6'] ?></p></div>
				<div class="col-xs-6 text-right"><p><a href="" data-dismiss="modal"><?= $l['modalBox_7'] ?></a></p></div>
			</div>
		</div>
	</div>
</div>
<script>setTimeout(function(){$('#modal-content').modal({show: true});}, 2000);</script>
<?php } setcookie("_br", "1", time()+7200, "/"); }}} ?>
<div id="single-dialog" class="modal fade" tabindex="-1" role="dialog">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header text-center">
				<button type="button" class="close" data-dismiss="modal">×</button>
				<p><?= $l['modalBox_1'] ?></p><h3><?= $l['modalBox_2'] ?></h3><p><?= $l['modalBox_3'] ?></p><br>
			</div>
			<form id="ajax-newsletter" method="post" action="<?= URL ?>template/<?= VIEW ?>/lib/newsletter/newsletter.inc.php">
				<div id="newsletter-form">
					<div class="modal-body">
						<div id="loading_banner"><img src="<?= URL ?>public/template/<?= VIEW ?>/images/loader_color.gif" alt="loader"></div>
						<div class="form-group pdb20">
							<div class="col-sm-1"></div>
							<div class="col-sm-10">
								<div id="option-group">
									<input type="hidden" name="lang" value="<?= $_SESSION['lang'] ?>">
									<input type="hidden" name="addr" value="<?= $_SERVER['REMOTE_ADDR'] ?>">
								</div>
								<div id="email-group">
									<input type="email" name="email" class="form-style-newsletter" id="inputEmail" placeholder="<?= $l['modalBox_4'] ?>*" required>
								</div>
								<div id="re-group">
									<label for="re"><?= $l['modalBox_8'] ?>*</label>
									<div id="re" class="g-recaptcha" style="transform:scale(0.7);transform-origin:0;-webkit-transform:scale(0.7);transform:scale(0.7);-webkit-transform-origin:0 0;transform-origin:0 0;" data-sitekey="6LcsSn4UAAAAAKZ69Jlb8DmrcBPGf69N06vZDr1D"></div>
								</div>
							</div>
							<div class="col-sm-1"></div>
						</div>
					</div>
					<div class="modal-footer"><button type="submit" class="btn btn-white"><?= $l['modalBox_5'] ?></button></div>
				</div>
			</form>
			<div class="modal-footer"> 
				<div class="col-xs-6 text-left"><p><?= $l['modalBox_6'] ?></p></div>
				<div class="col-xs-6 text-right"><p><a href="" data-dismiss="modal"><?= $l['modalBox_7'] ?></a></p></div>
			</div>
		</div>
	</div>
</div>
<script>
	$('#single-dialog').on('shown.bs.modal', function () {$('#myInput').focus()})
	$(function(){var a=$("#ajax-newsletter"),b=$("#newsletter-form");$(a).submit(function(c){c.preventDefault();var d=$(a).serialize();document.getElementById("loading_banner").style.display="block",setTimeout(function(){$.ajax({type:"POST",url:$(a).attr("action"),data:d}).done(function(a){$(b).removeClass("error"),$(b).addClass("success"),document.getElementById("loading_banner").style.display="block",$(b).text(a),$("#name").val(""),$("#email").val(""),$("#message").val("")}).fail(function(a){$(b).removeClass("success"),$(b).addClass("error"),$(b).text(""!==a.responseText?a.responseText:"Oops! An error occured and your message could not be sent.")})},1e3)})});
    grecaptcha.ready(function(){grecaptcha.execute('6LcsSn4UAAAAAKZ69Jlb8DmrcBPGf69N06vZDr1D', {action: 'action_name'}).then(function(token) {});});
</script>