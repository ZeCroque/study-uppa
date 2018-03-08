"use strict";



var boule = true;
var button = document.getElementById("button");

window.setInterval(afficherHeure, 1000);

button.addEventListener("click", function(){boule=!boule;});

if (boule)
{
	console.log("lol");
	window.setInterval(playExtract, 10000);
}
else
{
	document.getElementById("audio").pause();
}



function afficherHeure()
{
	var date = new Date();
	var hours;
	var seconds;
	var minutes;

	
	if (date.getSeconds()<10)
		seconds="0"+date.getSeconds();
	else
		seconds=date.getSeconds();

	if (date.getMinutes()<10)
		minutes="0"+date.getMinutes();
	else
		minutes=date.getMinutes();

	if (date.getHours()<10)
		hours="0"+date.getHours();
	else
		hours=date.getHours();
		
	document.getElementById("time").innerHTML=hours+"h "+minutes+"m "+seconds+"s ";

}

function playExtract()
{
	var audio = document.getElementById("audio");
	
	audio.load();
	audio.play();
}

