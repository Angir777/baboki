<?php

class Contact extends db {

  	public function getForm($lang, $l){

  		$numberOne = rand(1,7);
		$numberTwo = rand(2,8);
		$numberScore = $numberOne + $numberTwo;

		$result = '
			<div class="container space-medium">
				<div class="row">
			      <div class="col-md-8 col-md-offset-2">
			        <div class="well well-sm">
			        	<div class="section-title">
				          <h3>' . $l['c_5'] . '</h3>
				          <div class="divider"></div>
				        </div>
			          	<form id="ajaxContact" method="post" action="'.URL.'template/'.VIEW.'/lib/mailer/mailer.inc.php" class="form-horizontal" autocomplete="off">
							<alert></alert>
							<div id="formContact" style="display : block;">
								<!-- Lang-->
						    	<input type="hidden" name="lang"  value="'.$lang.'" />
						    	<!-- Check-->
						    	<input type="hidden" name="check" value="' . $numberScore . '" />
					          	<!-- Name -->
								<div class="form-group">
									<label class="col-md-3 control-label" for="name">' . $l['c_6'] . '*</label>
									<div id="name-group" class="col-md-9">
										<input type="text" class="form-control" name="name" placeholder="">
									</div>
								</div>
								<!-- Email -->
								<div class="form-group">
									<label class="col-md-3 control-label" for="email">' . $l['c_8'] . '*</label>
									<div id="email-group" class="col-md-9">
										<input type="text" class="form-control" name="email" placeholder="">
									</div>
								</div>
								<!-- Phone -->
								<div class="form-group">
									<label class="col-md-3 control-label" for="phone">' . $l['c_7'] . '</label>
									<div id="phone-group" class="col-md-9">
										<input type="tel" class="form-control" name="phone" placeholder="">
									</div>
								</div>
								<!-- Message -->
					            <div class="form-group">
					              	<label class="col-md-3 control-label" for="message">' . $l['c_9'] . '*</label>
					              	<div id="message-group" class="col-md-9">
					                	<textarea rows="5" class="form-control" name="message" placeholder=""></textarea>
					              	</div>
					            </div>
					            <!-- Recaptcha -->
					            <div class="form-group">
									<label class="col-md-3 control-label" for="recaptcha">' . $numberOne . '+' . $numberTwo . '=?*</label>
									<div id="recaptcha-group" class="col-md-9">
										<input type="text" class="form-control" name="recaptcha" placeholder="">
									</div>
								</div>
					            <!-- Submit button -->
								<div class="form-group">
					              <div class="col-md-12 text-right mt20">
					                <button type="submit" class="btn btn-primary btn-md">' . $l['c_5'] . '</button>
					              </div>
					            </div>
					        </div>
			          	</form>
			        </div>
			      </div>
				</div>
			</div>
		';

		return $result;
	}

}