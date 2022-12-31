/*!
    *****************************************

    * Module: back-to-top
    * File: back-to-top.js
    * Version: 1.0.0

    *****************************************
*/
$(window).scroll(function(){
    if($(this).scrollTop() > 100){
        $('.cd-top').fadeIn();
    }else{
        $('.cd-top').fadeOut();
    }
});
$('.cd-top').click(function(){
    $('html, body').animate({scrollTop : 0},800);
    return false;
});