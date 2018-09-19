
function changeImageM1(url, nom) 
{
    document.body.childNodes[3].lastChild.innerHTML=nom;
    document.body.childNodes[5].firstChild.src=url;

}

function changeImageM2(id_url, id_nom, url, nom) 
{
	document.getElementById(id_nom).innerHTML=nom;
	document.getElementById(id_url).src=url;
}

function changeImageM3(url, nom)
{
	document.querySelector("p>b").innerHTML=nom;
	document.querySelector("p>img").src=url;
}
