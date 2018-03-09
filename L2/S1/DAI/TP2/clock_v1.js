"use strict";

let intervalID = null; // identifiant pour window.setInterval et clearInterval

// Initialisation de l'application une fois le document chargé
window.addEventListener("load", function() {

  afficheHeure();

  majHeure();  // lance la mise à jour régulière de l'heure

  abonnements(); // abonnenement aux événements

});

function abonnements() {
	let checkboxElt = document.getElementById("checkPause");
	checkboxElt.addEventListener('change', pause);
	
}

function afficheHeure() {
	let date = new Date();
	var ss;
	var mm;
	var hh;
	if (date.getSeconds()<10)
		ss="0"+date.getSeconds();
	else
		ss=date.getSeconds();

	if (date.getMinutes()<10)
		mm="0"+date.getMinutes();
	else
		mm=date.getMinutes();

	if (date.getHours()<10)
		hh="0"+date.getHours();
	else
		hh=date.getHours();
	document.getElementById("heure").innerHTML=hh+":"+mm+":"+ss;
	let hhmmss = date.toString();
	
	console.log(hhmmss);
}

function majHeure() {
	intervalID = window.setInterval(afficheHeure,1000);
}

function pause(){
	let checkboxElt = document.getElementById("checkPause");
	if ( checkboxElt.checked){
		clearInterval(intervalID);
	}
	else
		majHeure()
		
}





