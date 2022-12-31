<?php

    /**
    * This file is part of BABOKI.COM
    * Module: price-scroller
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

?>
<!-- price-scroller -->
<link rel="stylesheet" href="<?= URL ?>template/<?= VIEW ?>/lib/price-scroller/css/nouislider.min.css">
<script src="<?= URL ?>template/<?= VIEW ?>/lib/price-scroller/js/nouislider.min.js"></script>
<script>
  var keypressSlider = document.getElementById('nonlinear');
  noUiSlider.create(keypressSlider, {
    start: [ WGR.filterPriceRangeMin, WGR.filterPriceRangeMax ],
    connect: true,
    behaviour: 'snap',
    snap: false,
    step: 5,
    range: {
      'min': 0,
      'max': 100
    },
  });
  
  var input0 = document.getElementById('input-with-keypress-0');
  var input1 = document.getElementById('input-with-keypress-1');
  var inputs = [input0, input1];
  
  function setSliderHandle(i, value){
    var r = [null,null];
    r[i] = value;
    keypressSlider.noUiSlider.set(r);
  }
  
  inputs.forEach(function(input, handle){
    input.addEventListener('change', function(){
      setSliderHandle(handle, this.value);
    });
    input.addEventListener('keydown', function( e ) {
      var values = keypressSlider.noUiSlider.get();
      var value = Number(values[handle]);
      var steps = keypressSlider.noUiSlider.steps();
      var step = steps[handle];
      var position;
      switch( e.which ){
        case 13:
          setSliderHandle(handle, this.value);
          break;
        case 38:
          position = step[1];
          if ( position === false ) {
            position = 1;
          }
          if ( position !== null ) {
            setSliderHandle(handle, value + position);
          }
          break;
        case 40:
          position = step[0];
          if ( position === false ) {
            position = 1;
          }
          if ( position !== null ) {
            setSliderHandle(handle, value - position);
          }
          break;
      }
    });
  });
  
  var rangeValue1post = document.getElementById('input-with-keypress-0').value;
  var rangeValue2post = document.getElementById('input-with-keypress-1').value;
  
  keypressSlider.noUiSlider.on('update', function ( values, handle, unencoded, isTap, positions ) {
    rangeValue1post = parseInt(values[0]);
    rangeValue2post = parseInt(values[1]);
    inputs[handle].value = values[handle];
  });
  
  $(document).ready(function() {
    $('#subFilter').click(function() {
      box = document.getElementsByName('category');
      var box_length = box.length;
      var i = 1;
      var cat = 'all';
      
      for (i; i <= box_length; i++) {
        if (document.getElementById('cat_' + i).checked) {cat = document.getElementById('cat_' + i).value;}
      }
      
      window.location.href = '<?= URL . friendly_url($l['menu_shop']) ?>/' + cat + '/' + rangeValue1post + '/' + rangeValue2post;
    });
  });
</script>