<?php

    /**
    * This file is part of BABOKI.COM
    * Module: mailer
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */
    
?>
<!-- mailer -->
<script>
	$(document).ready(function() {
    	var nameForm = $("#ajaxContact");
		// process the form
		$('form').submit(function(event) {
			$('.form-group').removeClass('has-error'); 	// remove the error class
			$('.help-block').remove(); 					// remove the error text
			// get the form data
			// there are many ways to get this data using jQuery (you can use the class or id also)
			var formData = {
				'name' 		: $('input[name=name]').val(),
				'email' 	: $('input[name=email]').val(),
				'phone' 	: $('input[name=phone]').val(),
				'message' 	: $('textarea[name=message]').val(),
				'recaptcha' : $('input[name=recaptcha]').val(),
				'lang' 		: $('input[name=lang]').val(),
				'check' 	: $('input[name=check]').val()
			};
			// process the form
			$.ajax({
				type 		: 'POST', 						// define the type of HTTP verb we want to use (POST for our form)
				url 		: $(nameForm).attr("action"), 	// the url where we want to POST
				data 		: formData, 					// our data object
				dataType 	: 'json', 						// what type of data do we expect back from the server
				encode 		: true
			})
			// using the done promise callback
			.done(function(data) {
				// log data to the console so we can see
				console.log(data); 
				// here we will handle errors and validation messages
				if ( ! data.success) {
					// handle errors for name ---------------
					if (data.errors.name) {
						$('#name-group').addClass('has-error'); // add the error class to show red input
						$('#name-group').append('<div class="help-block">' + data.errors.name + '</div>');
					} else 
						$('#name-group').removeClass('has-error'); // remove the error class to show red input
					// handle errors for email ---------------
					if (data.errors.email) {
						$('#email-group').addClass('has-error'); // add the error class to show red input
						$('#email-group').append('<div class="help-block">' + data.errors.email + '</div>');
					} else 
						$('#email-group').removeClass('has-error'); // remove the error class to show red input
					// handle errors for phone ---------------
					if (data.errors.phone) {
						$('#phone-group').addClass('has-error'); // add the error class to show red input
						$('#phone-group').append('<div class="help-block">' + data.errors.phone + '</div>');
					} else 
						$('#phone-group').removeClass('has-error'); // remove the error class to show red input
					// handle errors for message alias ---------------
					if (data.errors.message) {
						$('#message-group').addClass('has-error'); // add the error class to show red input
						$('#message-group').append('<div class="help-block">' + data.errors.message + '</div>');
					} else 
						$('#message-group').removeClass('has-error'); // remove the error class to show red input
					// handle errors for message alias ---------------
					if (data.errors.recaptcha) {
						$('#recaptcha-group').addClass('has-error'); // add the error class to show red input
						$('#recaptcha-group').append('<div class="help-block">' + data.errors.recaptcha + '</div>');
					} else 
						$('#recaptcha-group').removeClass('has-error'); // remove the error class to show red input
				} else {
					// ALL GOOD! just show the success message!
					$('alert').append('<div class="alert alert-success">' + data.message + '</div>');
					document.getElementById("formContact").style.display="none";
					// usually after form submission, you'll want to redirect
					// window.location = '/thank-you'; // redirect a user to another page
				}
			})
			// using the fail promise callback
			.fail(function(data) {
				// show any errors
				// best to remove for production
				console.log(data);
			});
			// stop the form from submitting the normal way and refreshing the page
			event.preventDefault();
		});
	});
    grecaptcha.ready(function(){grecaptcha.execute("6LfA95gUAAAAADpki-zUSUoEMEQ6VEqxAFImhpub", {action: "action_name"}).then(function(token) {});});
</script>