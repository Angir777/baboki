/*!
    *****************************************

    * Module: lang_switch
    * File: lang_switch.js
    * Version: 1.0.0

    *****************************************
*/
// change lang session after click to language button
function changeLang(){
	var lang = document.getElementById("langSelect").value;
	$.ajax({
		type: "POST",
		url: "https://"+location.hostname+"/template/front/lib/lang_switch/lang_switch.inc.php",
		processdata: false,
		data: "langSwitch=true&lang="+lang,
		success: function(data) {
			location.href = 'https://'+location.hostname;
		}
	});
}