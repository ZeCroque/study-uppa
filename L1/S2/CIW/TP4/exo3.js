var onglet;

function init()
{
	var bouton = document.getElementById('bouton1').addEventListener("click", function() {onglet=window.open('http://www.youtube.com');});
	var bouton1 = document.getElementById('bouton2').addEventListener("click", function() {window.close(onglet);});
}



