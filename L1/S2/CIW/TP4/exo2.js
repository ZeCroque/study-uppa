
function age()
{	

	var anneeNaissance   =   parseInt( window.prompt("Entrez votre Année de naissance") );
	var d=new Date();
	var y = d.getFullYear();
	window.alert(y-anneeNaissance);
}
