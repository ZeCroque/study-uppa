"use strict";

let intervalID = null; // identifiant pour window.setInterval

/**
* Initialisation de l'application une fois le document chargé
*/
window.addEventListener("load", function() 
{
	let alarm=document.getElementById("alarmes").children[0];

	alarm.children[0].checked=false;
	alarm.children[1].disabled=false;
	alarm.children[2].disabled=false;
	alarm.children[3].value="";
	afficheHeure();
	majHeure(); // lance la mise à jour régulière de l'heure
	remplirSelectsHeuresMinutes(); // ajouter la liste déroulante des heures et minutes
	abonnements(); // abonnenement aux événements
});

/**
 * Abonnements aux événements
 */
function abonnements() {

  let alarmeElts = document.getElementsByClassName("alarme");
  abonnerAlarmeElt(alarmeElts[0]);

  let ajouterElt = document.getElementsByClassName("ajouter")[0];
  ajouterElt.addEventListener("click", ajouterAlarme);
	
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

/**
 * Remplir le select des Heures et des minutes
 */
function remplirSelectsHeuresMinutes() {
  // récupérer les deux selects de alarme
  let alarmeElts = document.getElementsByClassName("alarme");
  let selectElts = alarmeElts[0].getElementsByTagName("select");

  // ajouter les heures 0 à 23 au premier select
  ajouterOptionsAuSelect(23, selectElts[0]);

  // ajouter les minutes 0 à 59 au deuxième select
  ajouterOptionsAuSelect(59, selectElts[1]);
}

/**
 * ajoute des options numériques à un champ select
 * @param  {number} borneMax    ajoute les options 0 à borneMax
 * @param  {Object} selectElt   element select concerné
 */
function ajouterOptionsAuSelect(borneMax, selectElt) {

  // création des noeuds option
  let optionElt = null;
	var i;

	for (i=0; i<=borneMax; i++)
	{
	  optionElt = document.createElement('option');
	  optionElt.value = i;
		if (i<10)
	  	{
			optionElt.textContent ="0"+i;
		}
		else
		{
			optionElt.textContent =i;
		}
	  selectElt.appendChild(optionElt);
	}
}

/**
 * abonnerAlarmeElt - Réagir aux événements sur la checkbox et
 *                    le bouton "Enlever alarme" d'une alarme
 * @param {Object} alarmElt un élément div.alarme et son contenu
 *
 */
function abonnerAlarmeElt(alarmElt) {

  let checkboxElt = alarmElt.getElementsByTagName("input")[0];
  checkboxElt.addEventListener("click", enclencherAlarme);

  let boutonElt = alarmElt.getElementsByTagName("button")[0];
  boutonElt.addEventListener("click", enleverAlarme);
}

function enclencherAlarme(evenement) {

  let checkboxElt = evenement.target;
  let checked = checkboxElt.checked;

  console.log("Alarme enclenchée ? " + checked);

  let parentNode = evenement.target.parentNode;
  let selectElts = parentNode.getElementsByTagName("select");
  let selectHeures = selectElts[0];
  let selectMinutes = selectElts[1];

  if (checked) 
	{
		let heures = selectHeures.options[selectHeures.selectedIndex].text;
		console.log("Heures : " + heures);

		let dateAlarme = new Date();
		console.log(dateAlarme.getSeconds());
		dateAlarme.setSeconds(0);
		dateAlarme.setMinutes(parentNode.children[2].value);
		dateAlarme.setHours(parentNode.children[1].value)//  parentNode.children[1].value*3600 + parentNode.children[2].value*60);
		console.log("Alarme réglée à : " + dateAlarme.toString());

		let dateCourante = new Date();
		let tempsRestant = dateAlarme - dateCourante;
		let descriptionAlarme="BOUM BADABOUM";
		
		if (parentNode.children[3].size!=0);
			 descriptionAlarme = parentNode.children[3].value;

		let timeoutId = setTimeout(function() {alert(descriptionAlarme);}, tempsRestant);

		// range le timeoutId dans la value de checkbox
		checkboxElt.value = timeoutId;
		

		// grise les champs
		selectHeures.disabled = true;
		selectMinutes.disabled = true;
  	} 
	else 
	{
	
		selectHeures.disabled = false;
		selectMinutes.disabled = false;
		clearTimeout(checkboxElt.value)
 	}
}

/**
 * enleverAlarme - Enlève le div.alarme contenant le bouton cliqué
 *                 mais seulement s'il reste plusieurs alarmes
 *
 * @param {Object} evenement l'événement qui a appelé cette fonction
 *
 */
function enleverAlarme(evenement) 
{

	let noeudDiv = evenement.target.parentNode;

	console.log("On veut supprimer ce ", noeudDiv);
	console.log("Il y a " + noeudDiv.parentNode.children.length + " alarme(s)");

  
	if (noeudDiv.parentNode.children.length!=1)
	{
		// désamorce l'éventuelle alarme
		clearTimeout(noeudDiv.children[0].value);

	  	// enleve ce div.alarme
	  	noeudDiv.remove();
	}

}

function ajouterAlarme() 
{
  console.log("Ajoute une nouvelle alarme");

  // Clone le premier fils de #alarmes
	let alarmesElt = document.getElementById("alarmes");
	let nouvelleAlarmeElt = alarmesElt.children[0].cloneNode(true);


  // dégrise les éléments éventuellement grisés
	nouvelleAlarmeElt.children[0].checked=false;
	nouvelleAlarmeElt.children[1].disabled=false;
	nouvelleAlarmeElt.children[2].disabled=false;
  	nouvelleAlarmeElt.children[3].value = "";

	alarmesElt.appendChild(nouvelleAlarmeElt);

	abonnerAlarmeElt(nouvelleAlarmeElt);
}
