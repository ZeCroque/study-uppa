"use strict";

const CAZ=-273.15;


class Temperature
{
  	constructor(temp, unite)
	{

    	switch(unite)
		{
			case "C":
        if(temp-CAZ>=0)
        {
          this._temp=temp-CAZ;
        }
        else
        {
          this._temp=0;
          console.log("Enculé, tu peux pas");
        }


			break;
			case "F":
        if(((temp-32)/(9/5)-CAZ)>=0)
        {
          this._temp=(temp-32)/(9/5)-CAZ
        }
        else
        {
          this._temp=0;
          console.log("Enculé, tu peux pas");
        }

			break;
			case "K":
        if(temp>=0)
        {
          this._temp=temp;
        }
        else
        {
          this._temp=0;
          console.log("Enculé, tu peux pas");
        }

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
		return (9/5*(this._temp+CAZ)) + 32;
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
    if(this._temp-this._step>=0)
    {
      this._temp-=this._step;
    }
    else
    {
      this._temp=0;
      console.log("Enculé, tu peux pas");
    }

	}
}

var temp = new Temperature(40, "F");

function refreshTemp(checked)
{
  let tempLabel = document.getElementById("temperature");
  switch(checked.id)
  {
    case "checkF":
      tempLabel.textContent=temp.asFahrenheit().toFixed(2);
    break;
    case "checkC":
      tempLabel.textContent=temp.asCelsius().toFixed(2);
    break;
    case "checkK":
      tempLabel.textContent=temp.asKelvin().toFixed(2);
    break;
  }
}

function checkboxListener(event)
{
	let checkboxes=document.querySelectorAll("input[type=checkbox]");

	if(event.target.checked)
	{
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
		refreshTemp(event.target);
	}
}

function buttonListener(event)
{
  let checkboxes=document.querySelectorAll("input[type=checkbox]");

  for(let i=0; i<checkboxes.length; i++)
  {
    if(checkboxes[i].checked)
    {
      switch(checkboxes[i].id)
      {
        case "checkF":
            if(event.target.id=="btnPlus")
            {
              temp.increment(0.5);
            }
            else
            {
              temp.decrement(0.5);
            }

        break;
        case "checkC":
          if(event.target.id=="btnPlus")
          {
            temp.increment(0.2);
          }
          else
          {
            temp.decrement(0.2);
          }
        break;
        case "checkK":
          if(event.target.id=="btnPlus")
          {
            temp.increment(1);
          }
          else
          {
            temp.decrement(1);
          }
        break;
      }
      refreshTemp(checkboxes[i]);
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

  document.getElementById("btnMoins").addEventListener("click", buttonListener);
  document.getElementById("btnPlus").addEventListener("click", buttonListener);

};
