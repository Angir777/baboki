<?php

    /**
    * This file is part of BABOKI.COM
    * Module: control
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

if ($_SESSION['pageSite']!='cpanel') {
    echo '
    	<div id="control-bar">
    		<div class="container-fluid">
		        <div class="row">
		         	<div class="col-md-12">
		         		<div class="navbar-header">
					      	<span class="navbar-brand">Zalogowany: '.$_SESSION['user']['signature'].'</span>
					    </div>
			            <div class="control-bar-main"> 
				    		<ul class="nav navbar-nav navbar-right dropup">
						        <li class="dropdown">
						          	<a href="#" class="dropdown-toggle text-center" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false"><i class="fas fa-cogs"></i></a>
						          	<ul class="dropdown-menu">
						            	<li><a href="'.URL.'cpanel">cPanel</a></li>
						            	<li role="separator" class="divider"></li>
						            	<li><a href="'.URL.'cpanel/logout">Wyloguj</a></li>
						          	</ul>
						        </li>
					      	</ul>
				        </div>
			        </div>
			    </div>
			</div>
    	</div>
    ';
}
if ($_SESSION['subpageSite']=='slider') {
?>
<script type="text/javascript" src="<?php echo URL; ?>template/<?= VIEW ?>/lib/control/js/bootstrap-filestyle.min.js"></script>
<script>
	// file upload button
    $(":file").filestyle({input: false,buttonText: "Wybierz plik"});
    // actions slider
    function AddSlider() {
        var ask = confirm('Czy dodać nowy slider?');
		if (ask) {
            let xhr = new XMLHttpRequest();
    		var id = '';
    		xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/slider.inc.php?pass=1", true);
    		xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var id = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/slider/"+id+"/edytuj");
                }
            });
            xhr.send();
        }
    }
    function DeleteSlider(id_slider) {
        var ask = confirm('Czy usunąć slider?');
        if (ask) {
        	let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/slider.inc.php?pass=2&id_slider="+id_slider, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    window.location.assign("<?= URL ?>cpanel/slider");
                }
            });
            xhr.send();
        }
    }
    function DeleteSliderPhoto(id_slider, lang) {
    	var ask = confirm('Czy usunąć zdjęcie?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/slider.inc.php?pass=3&id_slider="+id_slider+"&lang="+lang, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var id = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/slider/"+id+"/edytuj");
                }
            });
            xhr.send();
        }
    }
</script>
<?php 
}
if ($_SESSION['subpageSite']=='biuletyn') {
?>
<script>
    // actions biuletyn
    function AddNewsletter() {
        var ask = confirm('Czy dodać nowy email?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/biuletyn.inc.php?pass=1", true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var id = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/biuletyn/"+id+"/edytuj");
                }
            });
            xhr.send();
        }
    }
    function DeleteNewsletter(id_newsletter) {
        var ask = confirm('Czy usunąć email?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/biuletyn.inc.php?pass=2&id_newsletter="+id_newsletter, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    window.location.assign("<?= URL ?>cpanel/biuletyn");
                }
            });
            xhr.send();
        }
    }
</script>
<?php 
}
if ($_SESSION['subpageSite']=='zamowienia') {
?>
<script>
    // actions zamowienia
    function DeleteOrder(id_order, page_name) {
        var ask = confirm('Czy usunąć to zamówienie?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var page = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/zamowienia.inc.php?pass=1&id_order="+id_order+"&page_name="+page_name, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var page = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/"+page);
                }
            });
            xhr.send();
        }
    }
</script>
<?php 
}
if ($_SESSION['subpageSite']=='magazyn') {
?>
<script type="text/javascript" src="<?php echo URL; ?>template/<?= VIEW ?>/lib/control/js/bootstrap-filestyle.min.js"></script>
<script>
    // file upload button
    $(":file").filestyle({input: false,buttonText: "Wybierz plik"});
    // actions magazyn
    function AddProduct() {
        var ask = confirm('Czy dodać nowy produkt?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/magazyn.inc.php?pass=1", true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var id = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/magazyn/"+id+"/edytuj");
                }
            });
            xhr.send();
        }
    }
    function DeleteProduct(id_product, page_name) {
        var ask = confirm('Czy usunąć ten produkt?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var page = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/magazyn.inc.php?pass=2&id_product="+id_product+"&page_name="+page_name, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var page = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/"+page);
                }
            });
            xhr.send();
        }
    }
    function DeleteProductPhoto(name) {
        var ask = confirm('Czy usunąć zdjęcie?');
        if (ask) {
            let xhr = new XMLHttpRequest();
            var id = '';
            xhr.open("GET", "<?= URL ?>template/<?= VIEW ?>/lib/control/ajax/magazyn.inc.php?pass=3&name="+name, true);
            xhr.addEventListener('readystatechange', function() {
                if (this.readyState === 4 && this.status === 200) {
                    var id = this.responseText;
                    window.location.assign("<?= URL ?>cpanel/magazyn/"+id+"/edytuj");
                }
            });
            xhr.send();
        }
    }
</script>
<?php 
}