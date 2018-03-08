function hello() 
{
 console.log("oui");
}

function alerte()
{
	alert("Tu n'est pas majeur(e)");
}

function showContent()
{
	console.log(document.getElementById("submit").innerHTML);
}

function init()
{
	document.getElementById("submit").disabled=true;
}

function verifyAge()
{
	if (parseInt(document.getElementById("age").value)<18)
		alerte();
}

function verifyPseudo()
{
	if (!RegExp("/./\D").test(document.getElementById("identifiant").value))
		alert("blabla");
}


