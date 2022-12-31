<?php

    /**
    * This file is part of BABOKI.COM
    * Language: EN
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */
	
	$pageSite = $_SESSION['pageSite'];
	$l = [];

	// menu
	$l['menu_start'] = 'Start';
	$l['menu_about_baboki'] = 'About Baboki';
	$l['menu_own_plush_toy'] = 'Creator';
	$l['menu_shop'] = 'Shop';
	$l['menu_blog'] = 'Blog';
	$l['menu_contact'] = 'Contact';
	$l['menu_cart'] = 'Cart';
	$l['menu_returns_and_complaints'] = 'Returns and complaints';
	$l['menu_privacy_policy'] = 'Privacy policy';
	$l['menu_regulations'] = 'Regulations';
	$l['menu_delivery_methods'] = 'Delivery methods';
	$l['menu_forms_of_payment'] = 'Forms of payment';
	$l['menu_faq'] = 'FAQ';
	$l['menu_cooperation'] = 'Cooperation';
	$l['menu_status_order'] = 'Status of the order';
	$l['menu_newsletter'] = 'Newsletter';
	$l['menu_delivery_and_payment'] = 'Delivery and payment';
	$l['menu_confirmation'] = 'Confirmation';

	// banner rabat
	$l['rabat_banner_title'] = 'At all mascots 20% discounts off with a code: PANDA18';
	$l['rabat_banner_button'] = 'Buy it cheaper';
	$l['rabat_banner_day'] = 'd';
	$l['rabat_banner_hour'] = 'g';
	$l['rabat_banner_minute'] = 'm';
	$l['rabat_banner_second'] = 's';

	// footer
	$l['footer_1'] = 'Poland';
	$l['footer_2'] = 'Follow us on ';
	$l['footer_3'] = 'Instagram';
	$l['footer_4'] = 'Language of the website ';
	$l['footer_5'] = 'Information and assistance';
	$l['footer_6'] = 'Delivery methods';
	$l['footer_7'] = 'Up';
	$l['footer_8'] = 'Poczta Polska';
	$l['footer_9'] = 'Courier DPD';
	$l['footer_10'] = '<p>© 2018 - '.date("Y").' | BABOKI.COM | All rights reserved.</p><p><small><b>Cuddles, hand sewn toys for children and adults, toys, mascots.</b></small></p>';
	$l['footer_11'] = 'Keep an eye on us on ';
	$l['footer_12'] = 'Facebook';

	// meta
	$l['meta_keywords'] = 'baboki, cuddles, hand sewn toys, children\'s toys, mascots, teddy bears, soft toys, soft toys, cuddly toys, teddy bears, bowls, teddy bears, sewn together, sewn together, order a teddy bear, gift, mascot, teddy bear, doll, handicraft, children\'s room, as a gift, to the child\'s room, toys, handmade, teddy bears';
	$l['meta_description'] = 'Baboki are a handmade safe, funny teddy bear. They look fantastic on sofas, armchairs and shelves. Perfect for fun! 100% Handmade.';
	
	// modal boxes
	$l['modalBox_1'] = 'Only now can you get';
	$l['modalBox_2'] = '10% DISCOUNT CODE';
	$l['modalBox_3'] = 'for your first order, if you subscribe to our newsletter!<br><small class="mt10">(The code will be sent to the given e-mail address)</small>';
	$l['modalBox_4'] = 'Enter your e-mail address';
	$l['modalBox_5'] = 'Sign me up!';
	$l['modalBox_6'] = 'Don\'t worry, we don\'t send spam!';
	$l['modalBox_7'] = 'No, thank you. I prefer it without a discount.';
	$l['modalBox_8'] = 'Check the box';
	$l['modalBox_9'] = 'Verification failed, try again.';
	$l['modalBox_10'] = 'Please refresh this page and check the reCAPTCHA box.';
	
	$l['technicalBreak'] = 'Maintenance work is underway. Access to the store can be temporarily blocked. We invite you soon.';

	// cookies alert
	$l['cookies_text'] = 'Baboki use cookies. Your use of this website constitutes your consent to be saved or read according to your browser\'s settings.';
	$l['cookies_button_ok'] = 'I understand!';
	$l['cookies_button_info'] = 'Read more';

	// social media
	$l['social_1'] = 'Hand sewn mascots for children and adults!';
	$l['social_2'] = 'Baboki are handmade funny teddy bears. They look fantastic on sofas, armchairs and shelves. Our plush toys can also be your first best friend!';
	$l['social_3'] = 'Mascots for children and adults';

	// 404
	$l['e404_1'] = 'Ups! Page not found :(';
	$l['e404_2'] = 'You may not be able to see this page, because:';
	$l['e404_3'] = '
		<li>This page is no longer up to date,</li>
		<li>Your search engine has not yet refreshed the map of our website,</li>
		<li>The address was entered incorrectly.</li>
	';
	$l['e404_4'] = 'Go to ';
	$l['e404_5'] = 'homepage';

	// delivery
	$l['delivery_personal_name'] = 'Odbiór osobisty';
	$l['delivery_personal_cash'] = 0.00;
	$l['delivery_inpost_name'] = 'InPost Polska';
	$l['delivery_inpost_cash'] = 12.99;
	$l['delivery_dpd_name'] = 'DPD Polska';
	$l['delivery_dpd_cash'] = 13.99;
	$l['delivery_dpd_world_name'] = 'DPD Świat';
	$l['delivery_dpd_world_cash'] = 69.00;
	$l['delivery_cash'] = ' PLN';
	$l['delivery_free_cash'] = 150.00;

	// pagination
	$l['pagination_page'] = 'page';

	// shop
	$l['shop_product'] = 'product';

	switch($pageSite){
		case 'home':
			$l['page_title'] = 'Mascots, toys, cuddles for children and adults';
			$l['slider_button_create'] = 'Create';
			$l['slider_button_view'] = 'Check it out';
			$l['c_1'] = 'Hand sewn mascots for children and adults';
			$l['c_2'] = '
				Baboki is a small company of hand sewn, designed from the heart of teddy bears.<br>
				All mascots are sewn here with attention and passion by hand, so each is different and unique.<br>
				Baboki are child-friendly and haven\'t hard, plastic or metal parts. All Baboki are produced in a smoke-free environment. They are produced in Poland and only Polish materials are used for their production.
			';
			$l['c_3'] = 'Exceptional mascots';
			$l['c_4'] = 'Baboki are not only good-looking mascots on the shelf. Our teddy bears can be your child\'s first friend. They can also be a reflection of the feelings and emotional state of their owner.';
			$l['c_5'] = 'Buy a ready-made mascot or design your own teddy bear with the help of the on-line creator.';
			$l['c_6'] = 'Ready-made designs';
			$l['c_7'] = 'Find your favourite from the big Baboki family!';
			$l['c_8'] = 'Your idea';
			$l['c_9'] = 'Do you want to reproduce a character from a game or movie? Or maybe you have your own vision? Let\'s do it!';
			$l['c_10'] = 'Creator';
			$l['c_11'] = 'Follow us on Instagram';
			$l['c_12'] = 'The most popular Baboki';
			$l['c_13'] = 'Kapitan Babok is a really brave guy! He\'s carring his amazing shield :) You can take this off and help him to restore the peace at your own room!';
			$l['c_14'] = 'Wiedźminek similarly to Babok Indianin is a brave babok. His dangerous face can aware monsters hiding under your bed. His carring on his back a sword.';
			$l['c_15'] = 'We present you a real hero! Babpool is smiling a lot! His wearing two amazing swords! You can take them off and fight along with this amazing Babpool.';
			$l['c_16'] = 'See more Baboki';
			$l['c_17'] = 'Baboki are the best! Panda is the sweetiest one! Iga is thrilled to have her!';
			$l['c_18'] = 'Today came to us nice babok \"Rocuś\" I ordered and created him, thanks <b>baboki.shop</b>. He found a worth place in my car, we will be listening to music together!';
			$l['c_19'] = 'Subscribe our newsletter';
			$l['c_20'] = 'And get 10% discount ordering your first babok!';
			$l['c_21'] = 'Sign up!';
			$l['c_22'] = 'Check out';
			$l['c_23'] = 'Introducing another animal! not just any rabbit, it\'s a big-hearted Babok. He\'s very friendly.';
		break;
		case 'about':
			$l['page_title'] = 'A few words about the Baboki';
			$l['c_1'] = 'Geek\'s mascots';
			$l['c_2'] = '
				Baboki is a small company with hand crafted created with heart plushes. All mascotes are hand sewed with exact patiency that\'s why baboki are different and unique. Baboki are created and sewed in Poland, in Ostrów Wielkopolski using polish fabric. We can design and creat babok for a private client or for companys, promoting them.<br><br>
				Baboki created two people, Magda And Błażej. All what you see is made with our hands.
				Baboki is our way to make something creative :) It\'s our hobby and it makes us more and more crrative. Every comment or a photo makes us feel happier!.<br><br>
				Let\'s see our products!
			';
			$l['c_3'] = 'Why are our mascots the best?';
			$l['c_4'] = '
				<li>Baboki may be your child\'s first friend;</li>
				<li>You can express your feelings with our mascots;</li>
				<li>They are ideal for fun both at home and on the go;</li>
				<li>We use only the highest quality materials originating from Poland;</li>
				<li>Our plush toys don\'t have any hard, plastic or metal parts;</li>
				<li>We use an anti-allergic filling with a certificate of Oeko-Tex®Standard100;</li>
				<li>Mascots are produced in an environment free from cigarette smoke;</li>
				<li>Baboki are created with passion and love for toys;</li>
				<li>Each of our products is unique and unique;</li>
				<li>We care about the design and positive reception of our products;</li>
				<li>Baboki is 100% Polish handicraft.</li>
			';
			$l['c_5'] = 'Design your own mascot!';
			$l['c_6'] = 'Do you want to reproduce a character from a game or movie? No problem! Use our creator. Choose the colour, accessories and design your teddy bear as you wish :)';
			$l['c_7'] = 'Creator';
			$l['c_8'] = 'Structure schematic';
		break;
		case 'creator':
			$l['page_title'] = 'Create your mascot.';
			$l['c_1'] = 'Design your own teddy bear<br>with the help of the Baboki 2.0 creator!';
			$l['c_2'] = 'Do you want to reproduce a character from a game, a book or a movie?<br>Or do you have your own idea? Let\'s do it!';
			$l['c_3'] = 'How does it work?';
			$l['c_4'] = '
				You can design your own mascot for yourself or your friends!<br><br>
				Use ready-made elements and create your favourite character from a game, movie or book.<br><br>
				Do you have a lively imagination? Great! Create a brand new character and surprise your friends!
			';
			$l['c_5'] = '
				The design process consists of 8 stages. Starting with choosing the color of the mascot, through the style of the eyes, mink, ears and ending with the accessories.<br><br>
				After selecting the items you want your Baboki to have, add the product to your cart by clicking the „<b>Add to cart</b>” button and follow the steps in the cart.<br><br>
				Each of our mascots is unique so it may differ slightly from the one in the creator.
			';
			$l['c_6'] = 'Let\'s get started!';
			$l['c_7'] = 'Select items and create your Baboki!';
			$l['c_8'] = 'Color';
			$l['c_9'] = 'Eyes';
			$l['c_10'] = 'Mimicry';
			$l['c_11'] = 'Ears';
			$l['c_12'] = 'Nose';
			$l['c_13'] = 'Face';
			$l['c_14'] = 'Paws';
			$l['c_15'] = 'Additives';
			$l['c_16'] = 'Add to cart';
			$l['c_17'] = 'Style';
			$l['c_18'] = 'None';
			$l['c_19'] = 'Front';
			$l['c_20'] = 'Back';
		break;
		case 'shop':
			$l['page_title'] = 'Shop';
			$l['c_1']= 'Categories';
			$l['c_2']= 'No added categories.';
			$l['c_3']= 'Price';
			$l['c_4']= 'Filter';
			$l['c_5']= 'Reset all filters';
			$l['c_6']= 'No products.';
			$l['c_7']= 'Next page';
			$l['c_8']= 'Previous page';
		break;
			case 'shop-product':
				$l['page_title'] = 'Shop';
				$l['c_9'] = 'Back';
				$l['c_10'] = 'Order';
				$l['c_11'] = 'Add to cart';
				$l['c_12'] = 'Available quantity:';
				$l['c_12a'] = 'pieces';
				$l['c_13a'] = 'days';
				$l['c_13'] = 'Delivery time:';
				$l['c_14'] = 'Description';
				$l['c_15'] = 'Technical information';
				$l['c_16'] = 'Delivery';
				$l['c_17'] = '
					The purchased goods will be delivered to the address indicated by the Customer in the order form.<br><br>
					Orders are sent no later than 10 days after the payment is credited to the Company\'s account on working days.<br><br>
					For purchases over 150.00 PLN free shipping in Poland.
				';
				$l['c_18'] = '';
				$l['c_19'] = '
					Height: 23 cm +/- 2 cm;<br>
					Used materials: 40% fleece, 30% silicone ball, 12% wigofil, 10% felt, 5% thread, 3% cotton;<br>
					Filling: anti-allergic silicone ball;<br>
					Method of production: hand and machine sewing;<br>
					Country of production: Poland;
				';
				$l['c_19_small'] = '
					Height: 13 cm +/- 2 cm;<br>
					Used materials: 40% fleece, 30% silicone ball, 12% wigofil, 10% felt, 5% thread, 3% cotton;<br>
					Filling: anti-allergic silicone ball;<br>
					Method of production: hand and machine sewing;<br>
					Country of production: Poland;
				';
				$l['c_20'] = 'Each of our mascots is unique so it may differ slightly from the one in the pictures.';
				$l['c_21'] = 'Baboki are child-friendly and do not have any hard, plastic or metal parts. All Baboki are produced with an eco environment free from smoke. They are produced in Poland and only Polish materials are used for their production.';
				$l['c_22'] = 'Share on';
			break;
			case 'cart':
				$l['page_title'] = 'Your order - Shopping cart';
				$l['c_1'] = 'Your order';
				$l['c_2'] = 'Order';
				$l['c_3'] = 'Delivery and payment';
				$l['c_4'] = 'Confirmation';
				$l['c_5'] = 'Your shopping';
				$l['c_6'] = 'Product';
				$l['c_7'] = 'Name of the product';
				$l['c_8'] = 'Number';
				$l['c_9'] = 'Quantity';
				$l['c_10'] = 'Price';
				$l['c_11'] = 'You will choose the method and cost of delivery in the next step.';
				$l['c_12'] = 'Total purchases:';
				$l['c_13'] = 'Next';
				$l['c_14'] = 'Your shopping cart is empty.';
				$l['c_15'] = 'Delete';
				$l['c_16'] = 'Start shopping';
				$l['c_17'] = 'Our guarantee of satisfaction';
				$l['c_18'] = 'If you are not satisfied for any reason, please contact us and we will do our best to improve the situation.<br>We take care of our customers ;)';
				$l['c_19'] = 'We care about the security of your data';
				$l['c_20'] = 'The information on this website is encrypted using SSL.';
				$l['c_21'] = 'Highest quality';
				$l['c_22'] = 'Safety is our top priority.';
				$l['c_23'] = 'Delivery and payment';
				$l['c_24'] = 'Shop';
			break;
			case 'delivery-and-payment':
				$l['page_title'] = 'Your order - Delivery and payment';
				$l['c_1'] = 'Your order';
				$l['c_2'] = 'Order';
				$l['c_3'] = 'Delivery and payment';
				$l['c_4'] = 'Confirmation';
				$l['c_5'] = 'Secure SSL connection';
				$l['c_6'] = 'E-mail';
				$l['c_7'] = 'Phone';
				$l['c_8'] = 'Delivery method';
				$l['c_9'] = '<small>Shipping only in Poland.</small>';
				$l['c_10'] = '<small>International shipping.</small>';
				$l['c_11'] = 'Name and surname';
				$l['c_12'] = 'Country*';
				$l['c_13'] = 'Poland';
				$l['c_14'] = 'The cost of delivery will be calculated for the country: Poland';
				$l['c_15'] = 'Postcode';
				$l['c_16'] = 'Delivery address';
				$l['c_17'] = 'Comment';
				$l['c_18'] = 'Purchase';
				$l['c_19'] = 'Total purchases:';
				$l['c_20'] = 'Back';
				$l['c_21'] = 'Discount code';
				$l['c_22'] = 'Enter the discount code:';
				$l['c_23'] = 'how do I get it?';
				$l['c_24'] = 'Confirm';
				$l['c_25'] = '<small>Biniew 22, 63-410 Ostrów Wielkopolsk, Poland</small>';
				$l['c_26'] = 'Your discount code';
				$l['c_27'] = '<small>Shipping only in Poland.</small>';
				$l['c_28'] = 'I accept';
				$l['c_29'] = 'shop regulations';
				$l['c_30'] = 'I want a receipt for the company.';
				$l['c_31'] = 'Company name*';
				$l['c_32'] = 'Enter a company name';
				$l['c_33'] = 'NIP*';
				$l['c_34'] = 'Enter the NIP number';
				$l['c_35'] = 'Town';
				$l['c_36'] = 'Street';
				$l['c_37'] = 'House/apartment number';
				$l['c_38'] = 'Method of payment';
				$l['c_39'] = 'On-site payment';
				$l['c_40'] = 'Traditional transfer';
				$l['c_41'] = 'Przelewy24';
				$l['c_42'] = 'Sorry, but our value of orders<br>for the current month will be exceeded by ';
				$l['c_43'] = 'Buy less today or do your shopping next month :)<br><br><small>In case of purchase of more products, please contact us through e-mail ' . EMAIL_COMPANY . ' to determine the details of your order.</small>';
			break;
			case 'confirmation':
				$l['page_title'] = 'Order confirmation';
				$l['c_1'] = 'Your order';
				$l['c_2'] = 'Order';
				$l['c_3'] = 'Delivery and payment';
				$l['c_4'] = 'Confirmation';
				$l['c_5'] = 'Order confirmation';
				$l['c_6'] = 'Comment on the order';
				$l['c_7'] = 'Hello!';
				$l['c_8'] = 'Thank you for placing an order with the following number ';
				$l['c_9'] = 'If you want to modify your orders, please reply to this message.';
				$l['c_10'] = 'Details of your order';
				$l['c_11'] = 'Delivery method';
				$l['c_12'] = 'Method of payment';
				$l['c_13'] = 'Transfer data';
				$l['c_14'] = 'Poland';
				$l['c_15'] = 'If you have additional questions or would like to modify your order, please write to our team to answer this message.<br>
				We are at your disposal. You can check the status of your order on our website using (<a target=\'_blank\' href=\'https://baboki.com/status-of-the-order\'>this link</a>).<br><br>Greetings,<br>BABOKI.COM';
				$l['c_16'] = 'Greetings,<br>BABOKI';
				$l['c_17'] = 'Remember to enter the order number in the transfer title. This will speed up the order processing.';
				$l['c_18'] = 'Details of your order';
				$l['c_19'] = 'Ordering party\'s data';
				$l['c_20'] = 'PLN';
				$l['c_21'] = 'Total purchases';
				$l['c_22'] = 'Total products';
				$l['c_23'] = 'Shipping';
				$l['c_24'] = 'Total';
				$l['c_25'] = 'Baboki shop | ' . ADDRESS_COMPANY . ', Poland | Contact: ' . EMAIL_COMPANY . '';
				$l['c_26'] = 'Thank you for placing your order!';
				$l['c_27'] = 'It\'s gonna be a really good day!<br>Thank you for placing an order with the following number ';
				$l['c_28'] = 'Confirmation has been sent to your e-mail address';
				$l['c_29'] = '<br>We will start working as soon as we receive the transfer.<br><br>Transfer data:<br>Bank: PKO Bank Polski<br>Account number: ' . BANK_COMPANY;
				$l['c_30'] = '<br>Remember to enter the order number in the transfer title. This will speed up the order processing.';
				$l['c_31'] = '<br>Have a nice day!';
				$l['c_32'] = 'Ups! Something went wrong. Try again later ;)';
				$l['c_33'] = 'The order was placed';
				$l['c_34'] = 'Go back to the store';
				$l['c_35'] = 'Personal collection';
				$l['c_36'] = 'Remember that personal pick-up is possible only after prior arrangement of the date at the e-mail: ' . EMAIL_COMPANY . '.';
				$l['c_37'] = 'FREE!';
				$l['c_38'] = 'Personal collection';
				$l['c_39'] = 'Discount';
				$l['c_40'] = 'All rights reserved';
				$l['c_41'] = 'Courier (DPD Poland)';
				$l['c_42'] = 'Poczta Polska (Poland)';
				$l['c_43'] = 'Poczta Polska (International shipping)';
				$l['c_44'] = 'On-site payment';
				$l['c_45'] = 'Traditional transfer';
				$l['c_46'] = 'Przelewy24';
				$l['c_47'] = 'Back';
				$l['c_48'] = 'Order details';
				$l['c_49'] = 'Name and surname';
				$l['c_50'] = 'E-mail';
				$l['c_51'] = 'Phone';
				$l['c_52'] = 'Country';
				$l['c_53'] = 'Postcode';
				$l['c_54'] = 'Town';
				$l['c_55'] = 'Street';
				$l['c_56'] = 'House/apartment number';
				$l['c_57'] = 'Company name';
				$l['c_58'] = 'NIP';
				$l['c_59'] = 'Products purchased';
				$l['c_60'] = "Total purchases";
			break;
		case 'contact':
			$l['page_title'] = 'Contact us';
			$l['c_1'] = 'Contact';
			$l['c_2'] = '
				Opinions, comments, suggestions?<br>
				Or do you want to ask a question?<br>
				Write to us by e-mail: ' . EMAIL_COMPANY . '
			';
			$l['c_3'] = 'Baboki data';
			$l['c_4'] = '
				Correspondence and return address:<br>' . ADDRESS_COMPANY . ', Poland<br><br>
				Bank: PKO Bank Polski<br>Account number: ' . BANK_COMPANY . '
			';
			$l['c_5'] = 'Contact form';
			$l['c_6'] = 'Name and surname';
			$l['c_7'] = 'Phone number';
			$l['c_8'] = 'E-mail address';
			$l['c_9'] = 'How can we help you?';
			$l['c_10'] = '3+2=?';
		break;
		case 'returns-and-complaints':
			$l['page_title'] = 'Returns and complaints';
			$l['c_1'] = 'Returns and complaints';
			$l['c_2'] = 'In case of some complaint, changes or returns of a product you bought <br> please contact us per mail: ' . EMAIL_COMPANY . '';
			$l['c_3'] = 'To complain, go through the steps below';
			$l['c_4'] = '
				<li>
					<strong>1. Complain form:</strong><br>
					Fill the form attached to the package and add it to the shipping.
				</li>
				<li>
					<strong>2. Product return:</strong><br>
					Complaining the product please attach all its accesories with the coppy of invoice if it was sended.
				</li>
				<li>
					<strong>3. Shipment:</strong><br>
					Complaining product has to be sanded to this address:<br><br>
					<i>BABOKI Błażej Skrzypniak,<br>' . ADDRESS_COMPANY . ', Poland</i>
				</li>
				<li class="mt20">
					<a href="'.URL.'tmp/files/download/complain-form-en.docx" rel="nofollow" target="_blank" title="Complain form">
					<i class="fas fa-file-download"></i> Complain form</a>
				</li>
			'; 
			$l['c_5'] = 'To cancel the contact please go though the steps below';
			$l['c_6'] = '
				<li>
					<strong>1. Canceling form:</strong><br>
					According to the law you got <b>14 days</b> to return the cargo.
					To cancel the contract and return the product fill the canceling form attached to the package and add it to your shipment.
				</li>
				<li>
					<strong>2. Return the product:</strong><br>
					We hearbly as you to return the product with all its accesories and copy of your invoice, if it was sent.
					Returned product can not have any signs of using and can not be damage.
				</li>
				<li>
					<strong>3. Shipment:</strong><br>
					Product has to be sended to this address:<br><br>
					<i>BABOKI Błażej Skrzypniak,<br>' . ADDRESS_COMPANY . ', Poland</i>
				</li>
				<li class="mt20">
					<a href="'.URL.'tmp/files/download/canceling-form-en.docx" rel="nofollow" target="_blank" title="Canceling form">
					<i class="fas fa-file-download"></i> Canceling form</a>
				</li>
			';
		break;
		case 'privacy-policy':
			$l['page_title'] = 'Privacy Policy';
			$l['c_1'] = 'Privacy Policy';
			$l['c_2'] = 'Above privacy policy has informational character<br> and contains the rules of data processing and protection sended from our clients according to the shipment of our products via our online shop www.baboki.com';
			$l['c_3'] = '
				<p>Data admin, <b>BŁAŻEJ SKRZYPNIAK</b> is leader of unregistered activity who holdes the address: ' . ADDRESS_COMPANY . ', Poland; mail address: ' . EMAIL_COMPANY . '.</p>
				<p>Personal data of clients are processing according to the law about privacy policy from day 29 august 1997 (Dz.U. 1997 Nr 133, poz. 883 ze zm.) (Personally Identifiable Information Protection Act and Act on the provision of electronic service day 18 lipca 2002 r. (Dz.U. 2002 Nr 144, poz. 1204 ze zm.).</p>
				<p>In the interests of the security of data entrusted to us, the administrator of personal data makes special care to protect the interests of data subjects, and in particular ensures that the data collected by him are processed in accordance with the law; collected for specified, legitimate purposes and not subjected to further processing incompatible with those purposes; factually correct and adequate in relation to the purposes for which they are processed and stored in a form that allows identification of the persons to whom they relate, no longer than necessary to achieve the purpose of processing..</p>
				<p>Personal Data is processed on the basis of the consent expressed by the client and in cases where the law authorizes the administrator to process personal data on the basis of the law or for the purpose of implementing a contract concluded between the parties.</p>
				<p>The shop implements acquires data using the steps below:
					<ul>
						<li>by entering voluntarily informations by the form;</li>
						<li>gathering "cookies" files(look <b>File policy „cookies”</b>).</li>
					</ul>
				</p>
				<p>Shop takes all the infotmation voluntarily wroten by the user.</p>
				<p>The data provided in the form are processed for the purpose resulting from the function of a specific form, e.g. to process the information contact or to deliver the purchased goods to the indicated address.</p>
				<p>Personal data left on the site will not be sold or made available to third parties in accordance with the provisions of the Personal Data Protection Act. </p>
				<! - <p> In the case of a Customer who uses the Online Store with an electronic payment method or payment card, the Administrator provides the collected personal data of the customer to the selected entity servicing the above payments in the online store. As the administrator of the personal data received in this way, he guarantees the use of all mechanisms of personal data protection, in particular those arising from applicable regulations. </p>
				<!--<p>In the case of a Customer who uses the Online Store with the method of electronic payments or a payment card, the Administrator provides the collected personal data of the customer to the selected entity servicing the above payments in the online store. As the administrator of the personal data received in this way, he guarantees the use of all mechanisms of personal data protection, in particular those arising from applicable regulations.</p>-->
				<p>The data contained in the form may be viewed by the natural person who placed them there. This person also has the right to modify and stop processing his data at any time.
				<p>the administrator applies technical and organizational measures ensuring the protection of processed personal data appropriate to the threats and categories of data protected, and in particular protects the data against disclosure to unauthorized persons, removal by an unauthorized person, processing in violation of applicable laws and change, loss, damage or destruction</p>
				<p>The administrator provides the following technical measures to prevent the acquisition and modification of personal data sent electronically by unauthorized persons:
					<ul>
						<li>Securing the data set against unauthorized access;</li>
						<li>Certificates SSL.</li>
					</ul>
				<p>The administrator reserves the right to change the privacy policy of the website, which may be affected by the development of internet technology, possible changes in the law in the field of personal data protection and the development of our website. We will inform you about any changes in a visible and understandable way.</p>
				<p>The Store may contain links to other websites. Such websites operate independently of our store and are not supervised by the administrator of personal data of the www.baboki.com website in any way. The administrator urges that after switching to other websites, read the privacy policy set out there. These websites may have their own privacy policies and regulations, which the administrator is recommended to read.</p>
			';
			$l['c_4'] = 'File policy „cookies”';
			$l['c_5'] = 'Cookies files Pliki cookies are IT data, in particular text files, which are stored on the website user\'s end device and are intended for using the website\'s pages. Cookies usually contain the name of the website from which they originate, their storage time on the end device and a unique number.';
			$l['c_6'] = '
				<p>The entity placing cookies on the user\'s end device and accessing them is the website operator.</p>
				<p>Cookies files are used to:
					<ul>
						<li>adapting the website content to the user\'s preferences and optimizing the use of websites; in particular, these files allow to recognize the user\'s device and properly display the website tailored to his individual needs;</li>
						<li>creating statistics that help to understand how website users use websites, which allows improving their structure and content;</li>
						<li>maintaining the website user\'s session, thanks to which the added products to the basket are stored in the browser\'s memory until purchase or resignation.</li>
					</ul>
				</p>
				<p>The website uses the following types of cookies:
					<ul>
						<li>„necessary” cookies files enabling the use of services available on the website, e.g. authentication cookies used for services that require authentication on the website;</li>
						<li>cookies used to ensure security, e.g. used to detect fraud in the field of authentication on the website;</li>
						<li>„performance” cookies, enabling the collection of information on the use of website pages;</li>
						<li>„functional” cookies, enabling „remembering” user-selected settings and personalizing the user interface, eg in terms of the selected language or added products in the basket;</li>
						<!--<li>"Advertising" cookies, enabling users to provide advertising content more tailored to their interests.</li>-->
					</ul>
				</p>
				<p>In many cases, the software used for browsing websites (web browser) by default allows the storage of cookies on the user\'s end device. Website users can change cookie settings at any time. These settings can be changed in particular in such a way as to block the automatic handling of cookies in the web browser\'s settings or to inform about them every time they are placed on the user\'s device. Detailed information about the possibilities and ways of handling cookies are available in the software (web browser) settings.</p>
				<p>Cookies placed on the website user\'s end device can also be used by advertisers and partners cooperating with the website</p>
				<p>More information about cookies can be found in the „Help” section of the web browser\'s menu.</p>
			';
		break;
		case 'regulations':
			$l['page_title'] = 'Regulation';
			$l['c_1'] = 'Regulation';
			$l['c_2'] = 'Online shop www.baboki.com regulation.';
			$l['c_3'] = 'Table of contents';
			$l['c_4'] = '
			<ol type="1">
				<li>General provisions</li>
				<li>Electronic services in an online store</li>
				<li>Terms of the sales contract</li>
				<li>Methods and dates of payment for the product</li>
				<li>Cost, methods and date of delivery and receipt of the product</li>
				<li>Product complaint</li>
				<li>Out-of-court complaint consideration and redress methods and rules of access to these procedures</li>
				<li>The right to withdraw from the contract</li>
				<li>Provisions regarding entrepreneurs</li>
				<li>Personal data in the online store</li>
				<li>Final Provisions</li>
			</ol>
			';
			$l['c_5'] = '1. General provisions:';
				/* 
				<!-- <li>1.1.The Online Store available at the Internet address www.baboki.com is run by BŁAŻEJ SKRZYPNIAK conducting business activity under the name BABOKI BŁAŻEJ SKRZYPNIAK entered in the Central Register and Information on Economic Activity of the Republic of Poland maintained by the minister responsible for economy, having: address of registered business: xxx , xxx xxx, NIP, REGON, e-mail address: ' . EMAIL_COMPANY . '. </b>.</li> --> 
				<!-- <li>1.4.9.SENDER; SERVICE PROVIDER – BŁAŻEJ SKRZYPNIAK conducting business activity under the company BABOKI BŁAŻEJ SKRZYPNIAK entered in the Central Register and Information on Economic Activity of the Republic of Poland kept by the minister responsible for economy, having: delivery address: xxx, NIP xxx, REGON xxx, e-mail address: halo@.com. .</li> -->
				*/
			$l['c_6'] = '
				<li>1.1. The Online Shop available at www.baboki.com is run by BŁAŻEJ SKRZYPNIAK conducting unregistered activities, having: address for service: ' . ADDRESS_COMPANY . ', Poland; e-mail address: <b>' . EMAIL_COMPANY . '</b>.</li>
				<li>1.2. These Regulations are addressed to both consumers and entrepreneurs using the Online Store (with the exception of point 9 of the Regulations, which is addressed only to entrepreneurs).</li>
				<li>1.3. The administrator of personal data processed in connection with the implementation of the provisions of these Regulations is the Service Provider. Personal data is processed for purposes within the scope and on the basis of the principles set out in the Regulations of the Online Store. Providing personal information is voluntary. Any person whose personal data is processed by the Service Provider has the right to inspect their content and the right to update and amend it.</li>
				<li>1.4. Definitions:</li>
				<li>1.4.1. BUSINESS DAY – one day from Monday to Friday, excluding public holidays.</li>
				<li>1.4.2. ORDER FORM - Electronic Service, an interactive form available in the Online Store enabling placing an Order, in particular by adding Products to the electronic basket and determining the terms of the Sales Agreement, including the method of delivery and payment.</li>
				<li>1.4.3. CUSTOMER - a natural person with full legal capacity, and in the cases provided for by generally applicable provisions also a natural person with limited legal capacity; legal entity; or an organizational unit without legal personality, which the law confers legal capacity; - who has concluded or intends to conclude a Sales Agreement with the Seller.</li>
				<li>1.4.4. CIVIL CODE - Civil Code Act of April 23, 1964.(Dz.U. 1964 nr 16, poz. 93 ze zm.).</li>
				<li>1.4.5. NEWSLETTER - Electronic Service, an electronic distribution service provided by the Service Provider via e-mail, which enables all Service Users using it to automatically receive from the Service Provider cyclical content of subsequent editions of the newsletter containing information about Products, new products and promotions in the Online Store NEWSLETTER.</li>
				<li>1.4.6. PRODUCT - a movable item available in the Online Store that is the subject of the Sales Agreement between the Customer and the Seller.</li>
				<li>1.4.7. REGULATIONS - these Regulations of the Online Store.</li>
				<li>1.4.8. ONLINE STORE - the Service Provider\'s online store available at the Internet address www.baboki.com.</li>	
				<li>1.4.9. SENDER; SERVICE PROVIDER – BŁAŻEJ SKRZYPNIAK conducting unregistered activities, having delivery address: ' . ADDRESS_COMPANY . ', Poland; e-mail address: ' . EMAIL_COMPANY . '.</li>
				<li>1.4.10. SALE AGREEMENT - Product sales contract concluded or concluded between the Customer and the Seller via the Online Store.</li>
				<li>1.4.11. ELECTRONIC SERVICE - a service provided electronically by the Service Provider to the Service User via the Online Store.</li>
				<li>1.4.12. SERVICE RECIPIENT - (1) a natural person with full legal capacity, and in the cases provided for by generally applicable provisions also a natural person with limited legal capacity; (2) legal entity; or (3) an organizational unit without legal personality, to which the law confers legal capacity; - using or intending to use the Electronic Service.</li>
				<li>1.4.13. CONSUMER RIGHTS ACT, ACT - the Act of 30 May 2014 on consumer rights (Journal of Laws of 2014, item 827, as amended).</li>
				<li>1.4.14. ORDER - Customer\'s declaration of intent submitted via the Order Form and directly aiming at concluding the Product Sales Agreement with the Seller.</li>
				<li>1.5. By using the website, you accept these regulations.</li>
			';
			$l['c_7'] = '2. Electronic services in an online store:';
			$l['c_8'] = '
				<li>2.1. The following Electronic Services are available in the Online Store: Order Form and Newsletter.</li>
				<li>2.1.1. Order Form - the use of the Order Form begins when the Customer adds the first Product to the electronic basket in the Online Store. Placing an Order takes place after the Customer completes a total of two subsequent steps - (1) after completing the Order Form and (2) clicking on the „Purchase” field on the Online Store website after completing the Order Form - up to this moment it is possible to modify the entered data (including purpose should be guided by displayed messages and information available on the Online Store website). In the Order Form, it is necessary for the Customer to provide the following Customer data: name and surname, e-mail address, delivery address (country, zip code, city, street, house/flat number), method of delivery of the Product (s) and method of payment. For customers who are not consumers, it is necessary to click the „I want invoice” field and provide the company name and tax identification number.</li> 
				<li>2.1.1.1. The Electronic Order Form service is provided free of charge and is of a one-off nature and is terminated when the Order is placed via it or when the Customer ceases to place the Order through it.</li>
				<li>2.1.2. Newsletter - the use of the Newsletter takes place after providing in the „Newsletter” section visible on the main page of the Online Store the e-mail address to which subsequent editions of the Newsletter are to be sent and clicking the „Subscribe” field Newsletter.</li>
				<li>2.1.2.1. The Newsletter Electronic Service is provided free of charge for an indefinite period. The Service Recipient has the option, at any time and without giving a reason, to unsubscribe from the Newsletter (unsubscribe from the Newsletter) by clicking on the appropriate link located in the footer of each Newsletter („unsubscribe” link) or via email to the address ' . EMAIL_COMPANY . '.</li>
				<li>2.2. Technical requirements necessary to cooperate with the ICT system used by the Service Provider: computer, laptop or other multimedia device with Internet access; access to e-mail; web browser: Mozilla Firefox version 11.0 and higher or Internet Explorer version 7.0 and higher, Opera version 7.0 and higher, Google Chrome version 12.0.0 and higher; recommended minimum screen resolution: 1024 × 768; enabling the option of saving Cookies and JavaScript in the web browser.</li>
				<li>2.3. The service recipient is obliged to use the Online Store in a manner consistent with the law and decency, having regard to respect for personal rights as well as copyrights and intellectual property of the Service Provider and third parties. The recipient is obliged to enter data consistent with the facts. The Service Recipient is forbidden to provide illegal content.</li>
				<li>2.4. Complaint procedure:</li>
				<li>2.4.1. Complaints related to the provision of Electronic Services by the Service Provider and other complaints related to the operation of the Online Store (excluding the Product complaint procedure, which was indicated in point 6 of the Regulations) The Customer may submit, for example:</li>
				<li>2.4.2. Writing address: ' . ADDRESS_COMPANY . ', Poland.</li>
				<li>2.4.3. Electronic form via e-mail to the address: ' . EMAIL_COMPANY . '.</li>
				<li>2.4.4. It is recommended that the Service Recipient provide in the complaint description: information and circumstances regarding the subject of the complaint, in particular the type and date of irregularities; Customer\'s requests; and contact details of the person submitting the complaint - this will facilitate and accelerate the consideration of the complaint by the Service Provider. The requirements provided in the previous sentence are only recommendations and do not affect the effectiveness of complaints submitted without the recommended description of the complaint.</li>
				<li>2.4.5. The Service Provider shall respond to the complaint immediately, not later than within 14 calendar days from the date of its submission.</li>
			';
			$l['c_9'] = '3. Terms of the sales contract:';
			$l['c_10'] = '
				<li>3.1. The conclusion of the Sales Agreement between the Customer and the Seller takes place after the Customer has placed the Order using the Order Form in the Online Store in accordance with point 2.1.1 of the Regulations.</li>
				<li>3.2. The Product price shown on the Online Store website is given in Polish zlotys and includes taxes. About the total price including taxes of the Product being the subject of the Order, as well as about the delivery costs (including charges for transport, delivery and postal services) and about other costs, and when it is not possible to determine the amount of these fees - about the obligation to pay them, the Customer is informed on the Online Store website when placing the Order, including when the Customer wishes to be bound by the Sales Agreement.</li>
				<li>3.3. The procedure for concluding a Sales Agreement in the Online Store using the Order Form:</li>
				<li>3.3.1. The conclusion of the Sales Agreement between the Customer and the Seller takes place after the Customer has placed an Order in the Online Store in accordance with point 2.1.1 of the Regulations.</li>
				<li>3.3.2. After placing the Order, the Seller immediately confirms its receipt and at the same time accepts the Order for execution. Confirmation of receipt of the Order and its acceptance for implementation occurs by sending the Customer an appropriate e-mail to the Customer\'s e-mail address provided during the submission of the Order, which contains at least the Seller\'s statement about the receipt of the Order and its acceptance for implementation and confirmation of the conclusion of the Sales Agreement. As soon as the Customer receives the above e-mail, a Sales Agreement is concluded between the Customer and the Seller.</li>
				<li>3.4. The content of the Sales Agreement concluded is secured, secured and made available to the Customer by making these Regulations available on the Online Store website and by sending the Customer the e-mail message referred to in point 3.3.2. Regulations. The content of the Sales Agreement is additionally recorded and secured in the IT system of the Seller\'s Online Store.</li>
			';
			$l['c_11'] = '4. Methods and terms of payment for the product:';
			$l['c_12'] = '
				<li>4.1. The Seller provides the Customer with the following methods of payment under the Sales Agreement:</li>
				<li>4.1.1. Payment in cash on personal collection (currently no personal collection).</li>
				<li>4.1.2. Payment by bank transfer to the Seller\'s bank account:</li>
				<li>4.1.2.1. Bank: PKO Bank Polski.</li>
				<li>4.1.2.2. Account numbe: ' . BANK_COMPANY . '.</li>
				<li>4.2. Payment deadline:</li>
				<li>4.2.1. If the Customer chooses cash payment on personal pickup or bank transfer, the Customer is obliged to make the payment within 7 calendar days from the date of the Sale Agreement.</li>
			';
			$l['c_13'] = '5. Cost, methods and date of delivery and receipt of the product:';
			$l['c_14'] = '
				<li>5.1. Product delivery is available within the territory of the Republic of Poland and abroad.</li>
				<li>5.2. Delivery of the Product to the Customer is payable, unless the Sales Agreement provides otherwise. Product delivery costs (including fees for transport, delivery and postal services) are indicated to the Customer on the Online Store\'s website in the „Delivery methods” tab and when placing the Order, including when the Customer wishes to be bound by the Sales Agreement.</li>
				<li>5.3. Personal collection of the Product by the Customer is free.</li>
				<li>5.4. The Seller provides the Customer with the following methods of delivery or collection of the Product:</li>
				<li>5.4.2. Courier delivery.</li>
				<li>5.4.3. Personal pickup (currently unavailable).</li>
				<li>5.5. The deadline for delivery of the Product to the Customer is up to 10 Business Days, unless a shorter deadline is given in the description of the given Product or when placing the Order. In the case of Products with different delivery dates, the delivery date is the longest given date, which, however, cannot exceed 10 Business Days. The beginning of the delivery period of the Product to the Customer counts as follows:</li>
				<li>5.5.1. If the Customer chooses the method of payment by bank transfer - from the date of crediting the Seller\'s bank account or settlement account</li>
				<li>5.6. Product readiness for collection by the Customer - if the Customer chooses to collect the Product in person, the Product will be ready for collection by the Customer within 7 Business Days, unless a shorter period is given in the description of the Product or when placing the Order. In the case of Products with different readiness dates, the readiness date for receipt is the longest given date. The Customer will be additionally informed by the Seller about the readiness of the Product for collection by sending an appropriate e-mail to the e-mail address provided by the Customer when placing the Order. The beginning of the period of readiness for the Product to be picked up by the Customer counts as follows:</li>
				<li>5.6.1. If the Customer chooses the method of payment by bank transfer - from the date of crediting the Seller\'s bank account or settlement account.</li>
				<li>5.6.2. If the Customer chooses the method of cash on delivery - from the date of the Sale Agreement.</li>
			';
			$l['c_15'] = '6. Product complaint:';
			$l['c_16'] = '
				<li>6.1. The withdrawal and scope of liability of the Seller towards the Customer, if the Product sold has a physical or legal defect (warranty) are defined by generally applicable law, in particular in the Civil Code (in particular in Articles 556-576 of the Civil Code)</li>
				<li>6.2. The Seller is obliged to provide the Customer with a Product without defects. Detailed information regarding the Seller\'s liability for a Product defect and the Customer\'s rights are set out on the Online Store website in the „Returns and complaints” tab.</li>
				<li>6.3. Complaints may be submitted by the customer, for example:</li>
				<li>6.3.1. Writting to address: ' . ADDRESS_COMPANY . ', Poland.</li>
				<li>6.3.2. Electronic form via e-mail to the address: ' . EMAIL_COMPANY . '.</li>
				<li>6.4. It is recommended that the customer provide in the complaint description: (1) information and circumstances regarding the subject of the complaint, in particular the type and date of the defect; (2) demanding how to bring the Product into compliance with the Sales Agreement or a statement on price reduction or withdrawal from the Sales Agreement; and (3) contact details of the person submitting the complaint - this will facilitate and accelerate the consideration of the complaint by the Seller. The requirements provided in the previous sentence are only recommendations and do not affect the effectiveness of complaints submitted without the recommended description of the complaint.</li>
				<li>6.5. The Seller will respond to the Customer\'s complaint immediately, no later than within 14 calendar days from the date of its submission. The Seller\'s failure to respond within the above deadline means that the Seller considered the complaint justified.</li>
				<li>6.6. The Customer who exercises the warranty rights is obliged to provide the defective Product at the Seller\'s expense to the following address: ' . ADDRESS_COMPANY . ', Poland. If, due to the type of Product or the way it was installed, the delivery of the Product by the Customer would be excessively difficult, the Customer shall be obliged is to make the Product available to the Seller at the place where the Product is located.</li>
			';
			$l['c_17'] = '7 .Out-of-court complaint consideration and redress methods and rules of access to these procedures:';
			$l['c_18'] = '
				<li>7.1. Detailed information on the possibility for the Customer who is a consumer to use extrajudicial methods of dealing with complaints and redress as well as the rules of access to these procedures are available at the headquarters and on the websites of poviat (municipal) consumer ombudsmen, social organizations, whose statutory tasks include consumer protection, Voivodship Trade Inspection Inspectorates and the following internet addresses of the Office of Competition and Consumer Protection: http://www.uokik.gov.pl/spory_konsumenckie.php; http://www.uokik.gov.pl/sprawy_indywidualne.php oraz http://www.uokik.gov.pl/wazne_adresy.php.</li>
				<li>7.2. The customer who is a consumer has the following examples of possibilities of using out-of-court complaint consideration and redress:</li>
				<li>7.2.1. The customer is entitled to apply to a permanent amicable consumer court referred to in art. 37 of the Act of 15 December 2000 on the Trade Inspection (Journal of Laws 2001 No. 4 item 25 as amended), with a request to resolve the dispute arising from the concluded Sales Agreement. The rules of organization and operation of permanent consumer courts of arbitration are set out in the ordinance of the Minister of Justice of September 25, 2001 on the rules of organization and operation of permanent consumer courts of arbitration.</li>
				<li>7.2.2. The customer is entitled to turn to the provincial inspector of Trade Inspection, in accordance with art. 36 of the Act of 15 December 2000 on the Trade Inspection (Journal of Laws 2001 No. 4 item 25 as amended), with a request to initiate mediation proceedings regarding the amicable settlement of the dispute between the Customer and the Seller. Information on the principles and mode of mediation procedure conducted by the provincial inspector of Trade Inspection is available at the headquarters and on the websites of individual Provincial Inspectorates of Trade Inspection.</li>
				<li>7.2.3. The customer may obtain free assistance in resolving the dispute between the Customer and the Seller, also using the free assistance of the poviat (municipal) consumer ombudsman or social organization, whose statutory tasks include consumer protection (including the Consumer Federation, Association of Polish Consumers). Advice is provided by the Consumer Federation at the e-mail address 800 889 866.</li>
				<li>7.3. Address http://ec.europa.eu/consumers/odr an online platform for resolving disputes between consumers and entrepreneurs at EU level is available (ODR platform). The ODR platform is an interactive and multilingual website with a one-stop shop for consumers and entrepreneurs seeking out-of-court settlement of a dispute regarding contractual obligations under an online sales contract or service contract.</li>
			';
			$l['c_19'] = '8. The right to withdraw from the contract:';
			$l['c_20'] = '
				<li>8.1. A consumer who has entered into a distance contract may, within 14 calendar days, withdraw from it without giving a reason and without incurring costs, except for the costs specified in point 8.7 of the Regulations. To meet the deadline, it is enough to send a statement before its expiry. A declaration of withdrawal may be made, for example: 
				<li>8.1.1. Writting address: ' . ADDRESS_COMPANY . ', Poland.</li>
				<li>8.1.2. Electronic form via e-mail to the address: ' . EMAIL_COMPANY . '.</li>
				<li>8.2. The deadline to withdraw from the contract begins:</li>
				<li>8.2.1. For the contract under which the Seller issues the Product, being obliged to transfer its ownership (e.g. Sales Contract) - from taking possession of the Product by the consumer or a third party indicated by him other than the carrier, and in the case of a contract which: (1) includes many Products that are delivered separately, in batches or in parts - from taking possession of the last Product, batch or part or (2) consist in regular delivery of Products for a limited period of time - from taking possession of the first of the Products.</li>
				<li>8.2.2. For other contracts - from the date of the contract.</li>
				<li>8.3. In the event of withdrawal from a distance contract, the contract is considered void.</li>
				<li>8.4. The Seller is obliged to immediately, no later than within 14 calendar days from the date of receipt of the consumer\'s statement of withdrawal from the contract, return to the consumer all payments made by him, including the costs of delivery of the Product (except for additional costs arising from the delivery method chosen by the Customer other than the cheapest regular delivery method available in the Online Store). The seller reimburses the payment using the same method of payment as used by the consumer, unless the consumer has expressly agreed to a different method of reimbursement that does not entail any costs for him. If the Seller has not offered to collect the Product from the consumer himself, he may withhold the reimbursement of payments received from the consumer until he receives the Product back or the consumer provides proof of his return, depending on which event occurs first.</li>
				<li>8.5. The consumer is obliged to immediately, not later than within 14 calendar days from the day on which he withdrew from the contract, return the Product to the Seller or hand it over to a person authorized by the Seller to collect, unless the Seller has offered to collect the Product himself. To meet the deadline, it is sufficient to return the Product before its expiry. The consumer may return the Product to the following address: ' . ADDRESS_COMPANY . ', Poland.</li>
				<li>8.6. The consumer is responsible for reducing the value of the Product as a result of using it in a way that goes beyond what is necessary to establish the nature, characteristics and functioning of the Product.</li>
				<li>8.7. Possible costs related to the consumer\'s withdrawal from the contract, which the consumer is obliged to bear:</li>
				<li>8.7.1. If the consumer has chosen a method of delivery of the Product other than the cheapest regular delivery method available in the Online Store, the Seller is not obliged to refund the additional costs incurred by the consumer.</li>
				<li>8.7.2. The consumer bears the direct cost of returning the Product.</li>
				<li>8.7.3. In the case of a Product which is a service whose performance - at the express request of the consumer - began before the deadline to withdraw from the contract, the consumer who exercises the right to withdraw from the contract after making such a request, is required to pay for the services fulfilled until the withdrawal from the contract. The amount of the payment is calculated in proportion to the scope of the service rendered, taking into account the price or remuneration agreed in the contract. If the price or remuneration is excessive, the basis for calculating this amount is the market value of the service provided.</li>
				<li>8.8. The right to withdraw from a distance contract is not entitled to the consumer in relation to contracts:</li>
				<li>8.8.1. (1)For the provision of services, if the Seller has fully performed the service with the express consent of the consumer, who was informed before the start of the service that after the performance of the service by the Seller he will lose the right to withdraw from the contract; (2) in which the price or remuneration depends on fluctuations in the financial market over which the Seller has no control, and which may occur before the deadline to withdraw from the contract; (3) in which the subject of the service is a non-prefabricated product, manufactured according to the consumer\'s specification or serving to satisfy his individual needs; (4) in which the subject of the service is a Product that deteriorates quickly or has a short shelf life; (5) in which the subject of the service is a Product delivered in a sealed package, which after opening the package cannot be returned due to health protection or hygiene reasons, if the packaging was opened after delivery; (6) in which the subject of the service are Products that after delivery, due to their nature, are inseparably connected with other things; (7) in which the subject of the service are alcoholic beverages, the price of which was agreed at the conclusion of the Sales Agreement, and whose delivery may take place only after 30 days and whose value depends on fluctuations in the market over which the Seller has no control; in which the consumer expressly demanded that the Seller come to him for urgent repair or maintenance; if the Seller provides additional services other than those requested by the consumer, or provides Products other than spare parts necessary for the performance of repair or maintenance, the consumer has the right to withdraw from the contract in respect of additional services or Products; (9) in which the subject of the service are sound or visual recordings or computer programs delivered in a sealed package, if the package was opened after delivery; (10) for delivering newspapers, periodicals or magazines, with the exception of subscription contracts; (11) concluded through a public auction; (12) for the provision of accommodation services other than for residential purposes, the carriage of goods, car rental, catering, leisure services, entertainment, sporting or cultural events, if the contract indicates the day or period of service provision; (13) for the supply of digital content that is not saved on a tangible medium, if the performance of the service began with the express consent of the consumer before the deadline to withdraw from the contract and after informing him by the Seller about the loss of the right to withdraw from the contract.</li>
			';
			$l['c_21'] = '9. Provisions regarding entrepreneurs:';
			$l['c_22'] = '
				<li>9.1. This section of the Regulations and the provisions contained herein apply only to Customers and Service Users who are not consumers.</li>
				<li>9.2. The Seller has the right to withdraw from the Sales Agreement concluded with a Customer who is not a consumer within 14 calendar days from the date of its conclusion. Withdrawal from the Sales Agreement in this case may occur without giving a reason and does not give rise to any claims on the part of the Customer who is not a consumer against the Seller.</li>
				<li>9.3. In the case of Customers who are not consumers, the Seller has the right to limit the available methods of payment, including requiring prepayment in whole or in part, regardless of the method of payment chosen by the Customer and the conclusion of the Sales Agreement.</li>
				<li>9.4. When the Seller releases the Product to the carrier, the non-consumer Customer receives the benefits and burdens associated with the Product and the risk of accidental loss or damage to the Product. In this case, the Seller shall not be liable for any loss, defect or damage of the Product arising from its acceptance for transport until its delivery to the Customer and for delay in the shipment.</li>
				<li>9.5. If the Product is sent to the Customer via a carrier, the Customer who is not a consumer is obliged to examine the parcel in time and in the manner adopted for such shipments. If it finds that during transport there was a loss or damage to the Product, it is obliged to perform all actions necessary to determine the liability of the carrier.</li>
				<li>9.6. In accordance with art. 558 § 1 of the Civil Code, the Seller\'s liability under the warranty for the Product towards a Customer who is not a consumer is excluded</li>
				<li>9.7. In the case of Service Recipients who are not consumers, the Service Provider may terminate the contract for the provision of Electronic Services with immediate effect and without indicating the reasons by sending the Customer a relevant statement.</li>
				<li>9.8. The liability of the Service Provider/Seller in relation to the Service Recipient/Customer who is not a consumer, regardless of its legal basis, is limited - both as part of a single claim and for all claims in total - to the amount of the price paid and delivery costs under the Sales Agreement, however, not more than up to one thousand zlotys. The Service Provider/Seller is liable to the Service Recipient/Customer who is not a consumer only for typical damages foreseeable at the time of conclusion of the contract and shall not be liable for lost profits in relation to the Service Recipient/Customer who is not a consumer.</li>
				<li>9.9. All disputes arising between the Seller/Service Provider and the Customer/Service Recipient who is not a consumer shall be subject to the court having jurisdiction over the seat of the Seller/Service Provider.</li>
			';
			$l['c_23'] = '10. Personal data in the online store:';
			$l['c_24'] = '
				<li>10.1. The administrator of the personal data of the Service Recipients/Customers collected via the Online Store is the Seller.</li>
				<li>10.2. The personal data of the Service Recipients/Customers collected by the administrator via the Online Store are collected - in accordance with the will of the Service Recipient/Customer - in order to implement the Sales Agreement or the contract for the provision of Electronic Services..</li>
				<li>10.3. Possible recipients of personal data of the Online Store customers:</li>
				<li>10.3.1. In the case of a Customer who uses the Online Store with the method of delivery by post or courier, the Administrator provides the collected personal data of the Customer to the selected carrier or intermediary performing the shipment at the request of the Administrator.</li>
				<li>10.3.2. In the case of a Customer who uses the Online Store with the method of electronic payment or a payment card, the Administrator provides the Customer\'s collected personal data to the selected entity operating the above payments in the Online Store.</li>
				<li>10.4.The Service Recipient/Customer has the right to access their data and correct it. A request in this regard can be made, for example:</li>
				<li>10.4.1. Writting address: ' . ADDRESS_COMPANY . ', Poland.</li>
				<li>10.4.2. Electronic form via e-mail to the address:' . EMAIL_COMPANY . '.</li>
				<li>10.5. Providing personal data is voluntary, but failure to provide the personal data indicated in the Regulations necessary to conclude a Sales Agreement or contract for the provision of Electronic Services results in the inability to conclude this contract. The data necessary to conclude a Sales Agreement or contract for the provision of Electronic Services are also indicated each time on the Online Store website before concluding the contract.</li>
			';
			$l['c_25'] = '11. Final provisions:';
			$l['c_26'] = '
				<li>11.1. Agreements concluded through the Online Store are concluded in Polish.</li>
				<li>11.2. Change of Regulations:</li>
				<li>11.2.1. The Service Provider reserves the right to amend the Regulations for important reasons, i.e. changes to the law; changes in payment and delivery methods - to the extent that these changes affect the implementation of the provisions of these Regulations.</li>
				<li>11.2.2. In the event of conclusion of continuous contracts pursuant to these Regulations (e.g. provision of Electronic Services - Account), the amended regulations shall bind the Service Recipient, if the requirements specified in art. 384 and 384 of the Civil Code, i.e. the Customer has been properly notified of the changes and has not terminated the contract within 14 calendar days of the date of notification. In the event that a change in the Regulations results in the introduction of any new fees or an increase in existing ones, the Service Recipient who is a consumer has the right to withdraw from the contract.</li>
				<li>11.2.3. In the case of conclusion of contracts other than continuous contracts on the basis of these Regulations (e.g. Sales Agreement), changes to the Regulations will not in any way affect the acquired rights of Service Recipients/Customers who are consumers before the date of entry into force of amendments to the Regulations, in particular changes to the Regulations will not impact on already placed or submitted Orders and concluded, implemented or executed Sales Agreements.</li>
				<li>11.3. In matters not covered by these Regulations, generally applicable provisions of Polish law shall apply, in particular: the Civil Code; the Act on the provision of electronic services of July 18, 2002 (Journal of Laws 2002 No. 144, item 1204, as amended); for Sales Agreements concluded from December 25, 2014 with customers who are consumers - the provisions of the Act on Consumer Rights of May 30, 2014 (Journal of Laws of 2014, item 827, as amended); and other relevant provisions of applicable law.</li>
			';
			$l['c_27'] = 'Rules from day 01.10.2019.<br><br>';
		break;
		case 'delivery-methods':
			$l['page_title'] = 'Delivery methods';
			$l['c_1'] = 'Delivery methods';
			$l['c_2'] = 'There is no possibility of personal pick-up';
			$l['c_3'] = 'Personal collection possible only by appointment.';
			$l['c_4'] = 'The package will be sent via DPD courier. Approximate delivery time: up to 2 business days*.';
			$l['c_5'] = 'The package will be sent via the + Package. Approximate delivery time: approx. 4 business days.*.';
			$l['c_6'] = '
				Approximate delivery time.*:<br>
				- Europe: 7 business days;<br>
				- USA and Canada: 14 business days;<br>
				- the rest of the world: 20 business days.
			';
			$l['c_7'] = '*WARNING';
			$l['c_8'] = 'You need to add approx. 4 business days for completing the order to the overall delivery time. <br><br>
				„<b>Approximate delivery time</b>” is indicative because there are different random situations. For example, a sudden winter attack, fog, tornadoes, erupting volcanoes. We have no influence on the operation of the mail and we cannot take responsibility for its delays. We care about the fastest and most importantly timely delivery of your shipments. Sometimes, however, the Post Office plays tricks. And even if we performed a ritual dance and sacrificed to the great gods of logistics - we can not help it. So please be understanding ;)<br><br>';
			$l['c_9'] = 'Free delivery';
			$l['c_10'] = 'For purchases over PLN 150.00, <b>free shipping in Poland</b>.<br><br>';
		break;
		case 'forms-of-payment':
			$l['page_title'] = 'Forms of payment';
			$l['c_1'] = 'Forms of payment';
			$l['c_2'] = 'Our bank account';
			$l['c_3'] = '
				Transfer data:<br><br>
				Bank: PKO Bank Polski<br>
				Account number: ' . BANK_COMPANY . '<br><br>
			';
			$l['c_4'] = 'Transfer via Przelewy24.';
		break;
		case 'faq':
			$l['page_title'] = 'FAQ';
			$l['c_1'] = 'FAQ';
			$l['c_2'] = 'A few answears for mostly questioned informations :)';
			$l['c_3'] = 'Do I need to set up an account to shop?';
			$l['c_4'] = 'No :) You don\'t need to create an account to make purchases. Just choose, create your own babok and order it now!';
			$l['c_5'] = 'I live abroad, can I buy Babok?';
			$l['c_6'] = 'Yes. We accept orders from outside Poland. Basically it is 60.00 PLN. The delivery method should be specified in the second basket step („<b>Delivery and Payment</b>”). You can find more about shipping costs <a href="'.URL.'delivery-methoods">here</a>.';
			$l['c_7'] = 'What\'s the time of the realization?';
			$l['c_8'] = 'Time of the processing order depends on the product specifics. Most products are made to order. Such a product should be made up to 7 business days. The delivery time itself depends on the type of delivery.';
			$l['c_9'] = 'Would baboki accept the return?';
			$l['c_10'] = 'Sure. Just get to know that returning product is not unpackaged and damaged. More about complains and returings you can read <a href="'.URL.'returns-and-complains">here</a>.';
			$l['c_11'] = 'How to create your own babok?';
			$l['c_12'] = 'To order your own mascot, go to the „<b>Creator page</b>”. Then follow the wizard\'s steps. Finally, click „<b>Add to cart</b>” and complete the purchase process.';
			$l['c_13'] = 'How to get discount codes?';
			$l['c_14'] = 'You can get discount codes in various ways. Subscribe to the Babocka newsletter to receive both attractive discount codes and unique offers - prepared especially for newsletter recipients.<br>
				you can also follow babok social profiles, where competitions and promotions appear from time to time.<br><br>
				Ok, ok... But how to sign up for a newsletter? Ale jak zapisać się do newslettera? You can do it by our main page. If by accident it was closed, turn off the browser and re-enter our site - the box will appear again. You must enter your email address there. You will receive confirmation of subscribing to the newsletter and a 10% discount code on your first purchase to the email provided.<br>
				To use the rebate code, enter it in the „<b>Your discount code</b>” field and click „<b>Confirm</b>” when specifying delivery and payment.
				<br><br>
				<small>* Discount with 5% is only possible by shopping for the first time at our shop. Not using it while ordering the first babok just will disappear.</small>
			';
		break;
		case 'cooperation':
			$l['page_title'] = 'Cooperation';
			$l['c_1'] = 'Cooperation';
			$l['c_2'] = 'We are open to cooperation. We are happy to make new contacts to achieve common goals. We invite youtubers, bloggers, photographers and producers of products from the fashion and children industry to joint photo sessions or other forms of cooperation.';
			$l['c_3'] = 'It\'s not about the amount but about quality, that\'s why we don\'t search for any distributors and we don\'t offer wholesale.';
			$l['c_4'] = '' . EMAIL_COMPANY . '';
		break;
		case 'status-order':
			$l['page_title'] = 'Status of the order';
			$l['c_1'] = 'Check the status of your order';
			$l['c_2'] = 'Using our babok order search system, you can quickly and easily find your order. <br>Just enter your order number and email to find out what stage your order is being carried out.';
			$l['c_3'] = 'Enter your order number:';
			$l['c_4'] = 'Enter the e-mail address given in your order:';
			$l['c_5'] = 'Check';
			$l['c_6'] = 'Invalid address e-mail!';
		break;
		case 'newsletter':
			$l['page_title'] = 'Newsletter';
			$l['c_1'] = 'Newsletter';
			$l['c_2'] = 'We are sad because your e-mail was removed drom our base.';
			$l['c_3'] = 'Every moment you can sign up to our newsletter!';
			$l['c_4'] = 'You\'ve decided to stay at newsletter?';
			$l['c_5'] = 'Sign up again!';
			$l['c_6'] = 'Subscribe to our newsletter!';
			$l['c_7'] = 'Sign me up!';
			$l['c_8'] = 'Hi! Nice of you to be here :)';
			$l['c_9'] = 'Sign up to our newsletter and you gain 10% discount for your first shopping!';
			$l['c_10'] = 'Would you like to subscribe to our newsletter?';
			$l['c_11'] = 'Sign me up';		
		break;
		case 'cpanel':
			$l['page_title'] = 'cPanel';
			$l['c_1'] = 'cPanel';
			$l['c_2'] = 'Login';
			$l['c_3'] = 'Password';	
			$l['c_4'] = 'Log in';
			$l['c_5'] = 'Incorrect login or password.';	
			$l['c_6'] = 'You are logged in!';			
		break;
		default:
			$l['page_title'] = 'Mascots, toys, cuddles for children and adults';
			$l['slider_button_create'] = 'Create';
			$l['slider_button_view'] = 'Check it out';
			$l['c_1'] = 'Hand sewn mascots for children and adults';
			$l['c_2'] = '
				Baboki is a small company of hand sewn, designed from the heart of teddy bears.<br>
				All mascots are sewn here with attention and passion by hand, so each is different and unique.<br>
				Baboki are child-friendly and haven\'t hard, plastic or metal parts. All Baboki are produced in a smoke-free environment. They are produced in Poland and only Polish materials are used for their production.
			';
			$l['c_3'] = 'Exceptional mascots';
			$l['c_4'] = 'Baboki are not only good-looking mascots on the shelf. Our teddy bears can be your child\'s first friend. They can also be a reflection of the feelings and emotional state of their owner.';
			$l['c_5'] = 'Buy a ready-made mascot or design your own teddy bear with the help of the on-line creator.';
			$l['c_6'] = 'Ready-made designs';
			$l['c_7'] = 'Find your favourite from the big Baboki family!';
			$l['c_8'] = 'Your idea';
			$l['c_9'] = 'Do you want to reproduce a character from a game or movie? Or maybe you have your own vision? Let\'s do it!';
			$l['c_10'] = 'Creator';
			$l['c_11'] = 'Follow us on Instagram';
			$l['c_12'] = 'The most popular Baboki';
			$l['c_13'] = 'Kapitan Babok is a really brave guy! He\'s carring his amazing shield :) You can take this off and help him to restore the peace at your own room!';
			$l['c_14'] = 'Wiedźminek similarly to Babok Indianin is a brave babok. His dangerous face can aware monsters hiding under your bed. His carring on his back a sword.';
			$l['c_15'] = 'I present you a real hero! Babpool is smiling a lot! His wearing two amazing swords! You can take them off and fight along with this amazing Babpool.';
			$l['c_16'] = 'See more Baboki';
			$l['c_17'] = 'Baboki are the best! Panda is the sweetiest one! Iga is thrilled to have her!';
			$l['c_18'] = 'Today came to us nice babok \"Rocuś\" I ordered and created him, thanks <b>baboki.shop</b>. He found a worth place in my car, we will be listening to music together!';
			$l['c_19'] = 'Subscribe our newsletter';
			$l['c_20'] = 'And get 10% discount ordering your first babok!';
			$l['c_21'] = 'Sign up!';
			$l['c_22'] = 'Check out';
			$l['c_23'] = 'Introducing another animal! not just any rabbit, it\'s a big-hearted Babok. He\'s very friendly.';
		break;
	}