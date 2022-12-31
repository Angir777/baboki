<?php

    /**
    * This file is part of BABOKI.COM
    * Module: cookies
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */
    
?>
<!-- cookies -->
<link rel="stylesheet" href="<?php echo URL; ?>template/<?= VIEW ?>/lib/cookies/css/cookieconsent.min.css">
<script async src="<?php echo URL; ?>template/<?= VIEW ?>/lib/cookies/js/cookieconsent.min.js"></script>
<script>
    window.addEventListener("load", function(){
        window.cookieconsent.initialise({
            "palette": {
                "popup": {
                    "background": "#edeff5",
                    "text": "#404040"
                },
                "button": {
                    "background": "#7373ff",
                    "text": "#ffffff"
                }
            },
            "position": "bottom-left",
            "content": {
                "message": "<?= $l['cookies_text'] ?>",
                "dismiss": "<?= $l['cookies_button_ok'] ?>",
                "link": "<?= $l['cookies_button_info'] ?>",
                "href": "<?php echo URL . friendly_url($l['menu_privacy_policy']) ?>"
            }
        })
    });
</script>