
function changeImageM1(url, nom) 
{
    document.body.childNodes[5].childNodes[3].childNodes[1].childNodes[3].childNodes[3].innerHTML=nom;
	document.body.childNodes[5].childNodes[3].childNodes[1].childNodes[1].firstChild.src=url;
}

function changeImageM2(id_url, id_nom, url, nom) 
{
	document.getElementById(id_nom).innerHTML=nom;
	document.getElementById(id_url).src=url;
}

function changeImageM3(url, nom)
{
	document.querySelector("article p+fieldset p").innerHTML=nom;
	document.querySelector("p img").src=url;
}

function changeBackgroundColor()
{
	var r=Math.floor((Math.random()*255));
	var g=Math.floor((Math.random()*255));
	var b=Math.floor((Math.random()*255));
	
	document.body.style.backgroundColor = 'rgb('+r+','+g+','+b+')'; 
}
