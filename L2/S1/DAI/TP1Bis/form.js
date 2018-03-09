"use strict";

/**
* Initialisation de l'application une fois le document chargé
*/
window.addEventListener("load", function() {

  tests(); // faire des tests d'accès et de modification du DOM

  abonnements(); // abonnenement aux événements
});

/**
 * Bon endroit pour faire des tests d'accès et de modification du DOM.
 * Utile pour lors de la phase de développement.
 */
function tests() {

  let elt = document.querySelector("h1");
  console.log("Contenu du titre : " + elt.textContent);

  // Affichage de tous les champs accessible depuis un élément
  console.log("Cliquez pour obtenir les détails sur l'élément : ", elt);

  // Modification d'un attribut de l'élément :
  elt.style.color = "red";
}

/**
 * Abonnements aux événements
 */
function abonnements() {

  let identifiantElt = document.getElementById("identifiant");
  identifiantElt.addEventListener("blur", valideIdentifiant);

  let ageElt = document.getElementById("age");
  ageElt.addEventListener("blur", valideAge);

  let mdp1Elt = document.getElementById("password");
  mdp1Elt.addEventListener("blur", valideMotDePasse);
  mdp1Elt.addEventListener("blur", valideMotDePasseIdentiques);


	let mdp2Elt = document.getElementById("password_confirm");
  mdp2Elt.addEventListener("blur", valideMotDePasseIdentiques);
//TODO "subscribe"

  let submitElt = document.getElementById("submit");
  submitElt.addEventListener("click", valideSoumission);

	let checkboxElt = document.getElementById("subscribe");
	checkboxElt.addEventListener("blur", valideCGUAcceptées);
}
	

/**
 * valideIdentifiant
 * affiche un message d'erreur si un l'identifiant n'est pas conforme
 */
function valideIdentifiant() {

  let élément = document.getElementById("identifiant");

  // vérification de la conformité de l'identifiant
  let ok = vérifieIdentifant(élément);

  // Cache ou affiche le message d'erreur
  let errorLabel = document.getElementById('identifiantError');
  if (ok === true) {
    errorLabel.style.display = 'none'; // on cache le messsage d'erreur
  } else {
    errorLabel.style.display = 'block'; // on le révèle
  }
  return ok;
}

/**
 * Vérifie si l'idenfiant est composé d'au moins 12 lettres
 * minuscules ou majuscules
 * @return {boolean} vrai si l'identifiant est conforme.
 */
function vérifieIdentifant(élément) {
  let val = élément.value;
  let ok = true;

  // utilisation de la fonction test des expressions rationnelles :
  // https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Objets_globaux/RegExp/test
  ok = /^[a-zA-Z]{12,}$/.test(val);

  // retourne la valeur de ok pour faire savoir l'état de la vérification
  return ok;
}

/**
 * valideAge
 * affiche un message d'erreur si un l'age n'est pas conforme
 */
function verifierAge(age)
{
	if (!isNaN(parseInt(age)))
		if (parseInt(age)>17)
			return true;
	return false;
}

function valideAge() {

  let ok = false;
  // Cache ou affiche le message d'erreur
	ok=verifierAge(document.getElementById('age').value);
  let errorLabel = document.getElementById('ageError');
  if (ok === true) {
    errorLabel.style.display = 'none'; // on cache le messsage d'erreur
  } else {
    errorLabel.style.display = 'block'; // on le révèle
  }
  return ok;
}

/**
 * valideMotDePasse
 * @return {boolean} [description]
 */
function valideMotDePasse() {
  let mdp = document.getElementById('password').value;
  let force = 0;

	let myBar= document.getElementById('myBar');

  force += vérifieMotDePasseLongueur(mdp);
  force += vérifieMotDePasseMinuscule(mdp);
  force += vérifieMotDePasseMajuscule(mdp);
  force += vérifieMotDePasseChiffre(mdp);
  force += vérifieMotDePasseAutreCaractere(mdp);
 
	myBar.style.width = force + '%'; 

	if (force<=40)
		myBar.style.backgroundColor="#FF0000";
	else if (force>40 && force<=70)
		myBar.style.backgroundColor="#FFA500";
	else
		myBar.style.backgroundColor="#4CAF50";


  let errorLabel = document.getElementById('passError');
  if (force === 100) {
    errorLabel.style.display = 'none';
  } else {
    errorLabel.style.display = 'block';
  }

  return force === 100;
}

function vérifieMotDePasseAutreCaractere(mdp){
	var patt = new RegExp("[^A-Za-z0-9]");
    return (patt.test(mdp))?20:0;
}


function vérifieMotDePasseChiffre(mdp){
	var patt = new RegExp("[0-9]");
    return (patt.test(mdp))?20:0;
}

function vérifieMotDePasseMajuscule(mdp){
	var patt = new RegExp("[A-Z]");
    return (patt.test(mdp))?20:0;
}

function vérifieMotDePasseMinuscule(mdp){
	var patt = new RegExp("[a-z]");
    return (patt.test(mdp))?20:0;
}

function vérifieMotDePasseLongueur(mdp) {
  return (mdp.length >= 8)
    ? 20
    : 0;
}

function verifierMotDePasseIdentiques(mdp,mdpBis) {
	if (mdp===mdpBis)
		return true;
	return false;
}

function valideMotDePasseIdentiques() {

  let ok = false;

	ok=verifierMotDePasseIdentiques(document.getElementById("password").value,document.getElementById("password_confirm").value);
  let errorLabel = document.getElementById('passConfirmError');
  if (ok) {
    errorLabel.style.display = 'none'
  } else {
    errorLabel.style.display = 'block';
  }
  return ok;
}

function valideCGUAcceptées() {

  let ok = false;

	ok=verifieCGUAcceptees();
  let errorLabel = document.getElementById('CGUError');
  if (ok) {
    errorLabel.style.display = 'none'
  } else {
    errorLabel.style.display = 'block';
  }
  return ok;
}

function verifieCGUAcceptees()
{
	return document.getElementById("subscribe").checked;
}

function valideSoumission() {
  let ok = true;
  ok &= valideIdentifiant();
  ok &= valideAge();
  ok &= valideMotDePasse();
  ok &= valideMotDePasseIdentiques();
  ok &= valideCGUAcceptées();

  return ok;
}

//page récupérer l'heure et l'afficher
