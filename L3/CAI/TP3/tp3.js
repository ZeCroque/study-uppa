"use strict";

const CAZ=-273.15;


class Temperature
{
  	constructor(temp, unite)
	{

    	switch(unite)
		{
			case "C":
				this._temp=temp-CAZ;
			break;
			case "F":
				this._temp=(temp-32)/(9*5)-CAZ
			break;
			case "K":
				this._temp=temp;
			break;
			default:
				this._temp=0;
				console.log("L'unité n'est pas valide, initialisation à 0K.");
			break;
		}
		this._step=0.001;
	}

	asKelvin()
	{
		return this._temp;
	}

	asCelsius()
	{
		return this._temp+CAZ;
	}

	asFahrenheit()
	{
		return (9/5)*(this._temp+CAZ) + 32;
	}

	increment(pas)
	{
		if(pas!==undefined)
		{
			this._step=pas;
		}
		this._temp+=this._step; new Temperature(21, "C");
	}

	decrement(pas)
	{
		if(pas!==undefined)
		{
			this._step=pas;
		}
		this._temp-=this._step;
	}
}

var temp = new Temperature(40, "F");

function checkboxListener(event)
{
	let checkboxes=document.querySelectorAll("input[type=checkbox]");

	if(event.target.checked)
	{
		console.log(checkboxes);
		for(let i=0; i<checkboxes.length; i++)
		{
			if(checkboxes[i]!==event.target)
			{
				checkboxes[i].checked=false;
				checkboxes[i].disabled=false;
			}
			else
			{
				checkboxes[i].disabled=true;
			}
			
		}
		let tempLabel = document.getElementById("temperature");
			switch(event.target.id)
			{
				case "checkF":
					tempLabel.textContent=temp.asFahrenheit();
					console.log("test");
					
				break;
				case "checkC":
				break;
				case "checkK":
				break;
			}		
	}
}

window.onload=function()
{
	document.getElementById("checkF").checked=true;
	document.getElementById("checkF").disabled=true;
	document.getElementById("checkC").checked=false;
	document.getElementById("checkK").checked=false;

	let checkboxes=document.querySelectorAll("input[type=checkbox]");

	for(let i=0; i<checkboxes.length; i++)
	{
		checkboxes[i].addEventListener("change", checkboxListener);
	}
	
};


