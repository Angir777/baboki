<?php

    /**
    * This file is part of BABOKI.COM
    * Module: creator_toy
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

?>
<!-- creator -->
<script>
    function changeColor(color){
        var b_color = color.value;
        document.getElementById("b_color_front").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_color/"+b_color+"_front.png";
        document.getElementById("b_color_back").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_color/"+b_color+"_back.png";
    }
    function changeEyes(eyes){
        var b_eyes = eyes.value;
        document.getElementById("b_eyes").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_eyes/"+b_eyes+".png";
    }
    function changeMimicry(mimicry){
        var b_mimicry = mimicry.value;
        document.getElementById("b_mimicry").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_mimicry/"+b_mimicry+".png";
    }
    function changeEars(ears){
        var b_ears = ears.value;
        document.getElementById("b_ears_front").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_ears/"+b_ears+"_front.png";
        document.getElementById("b_ears_back").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_ears/"+b_ears+"_back.png";
    }
    function changeFace(face){
        var b_face = face.value;
        document.getElementById("b_face").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_face/"+b_face+".png";
    }
    function changeHandle(handle){
        var b_handle = handle.value;
        document.getElementById("b_handle_front").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_handle/"+b_handle+".png";
        document.getElementById("b_handle_back").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_handle/"+b_handle+".png";
    }
    function changeNose(nose){
        var b_nose = nose.value;
        document.getElementById("b_nose").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_nose/"+b_nose+".png";
    }
    function changeAccessories(accessories,number){
        var chceck = accessories.checked;
        if (chceck == false) {
            document.getElementById("b_accessories_"+number+"_front").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_front.png";
            document.getElementById("b_accessories_"+number+"_back").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/b_accessories_0_back.png";
        } else {
            var b_accessories = accessories.value;
            document.getElementById("b_accessories_"+number+"_front").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/"+b_accessories+"_front.png";
            document.getElementById("b_accessories_"+number+"_back").src = "<?= URL ?>template/<?= VIEW ?>/lib/creator/b_creator/b_visualisation/b_accessories/"+b_accessories+"_back.png";
            click_accessories++;
        }
    }
    function ShowHideContent(polecenie,id) {
        var PrzyciskPokaz = document.getElementById('ButtonShow_' + id);
        var PrzyciskUkryj = document.getElementById('ButtonHide_' + id);
        var TrescSkrocona = document.getElementById('ShortContent_' + id);
        var TrescPelna = document.getElementById('FullContent_' + id);
        if (polecenie == 'Show') {
            PrzyciskPokaz.style.display = 'none';
            PrzyciskUkryj.style.display = 'block';
            TrescSkrocona.style.display = 'none';
            TrescPelna.style.display = 'block';
        } else if (polecenie == 'Hide') {
            PrzyciskPokaz.style.display = 'block';
            PrzyciskUkryj.style.display = 'none';
            TrescSkrocona.style.display = 'block';
            TrescPelna.style.display = 'none';
        }
    }
</script>