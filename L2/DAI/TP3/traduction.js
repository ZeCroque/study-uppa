var traductionsLocales = null;

window.addEventListener("load", function() 
{
	abonnements();
	chargerTraductionsLocales();
});

function abonnements() 
{
	let submitElt = document.getElementById("bouton");
	submitElt.addEventListener("click", traduire);

	let texteElt = document.getElementById("expression");
	texteElt.addEventListener("keyup", rechercheDico);

	let langSrcElt = document.getElementById("langsource");
	langSrcElt.addEventListener("change", rechercheDico);

	let langDstElt = document.getElementById("langdest");
	langDstElt.addEventListener("change", rechercheDico);

	let supprimerElt = document.getElementById("supprBouton");
	supprimerElt.addEventListener("click", supprimerTraductions);
}

function chargerTraductionsLocales() 
{
	let tab = document.getElementById("tab");
	let str;
	let indice=0;

	if (localStorage.getItem('traductions') === null) 
	{
		traductionsLocales = [];
	} 
	else 
	{
		traductionsLocales = JSON.parse(localStorage.getItem('traductions'));
		for (let i = 0; i < traductionsLocales.length; i++) 
		{
			str=JSON.stringify(traductionsLocales[i]);
			indice=0;
			let row = tab.insertRow(i+1)
			let tds = new Array(5);
			tds[0]=row.insertCell(0);
			tds[0].innerHTML="<input type=\"checkbox\"></input>";
			for (let j=1; j<5; j++)
			{
				tds[j]=row.insertCell(j);	
				tds[j].innerHTML=str.substring(str.indexOf(':', indice)+2, str.indexOf('\"', str.indexOf(':', indice)+2));
				indice=str.indexOf(':', indice)+2;
			}
	
    	}

	}
}

function traduire() 
{
	let expression = document.getElementById("expression").value;
	let langSrc = document.getElementById("langsource").value;
	let langDst = document.getElementById("langdest").value;
	
	appelGoogleTraduction(expression, langSrc, langDst);
}

function appelGoogleTraduction(expression, langueSource, langueDestination) 
{

	var url = "https://translate.googleapis.com/translate_a/single?client=gtx";
	url += "&sl=" + langueSource;
	url += "&tl=" + langueDestination;
	url += "&dt=t";
	url += "&q=" + escape(expression);

	var requete = new XMLHttpRequest();

	requete.open("GET", url, true);

	requete.onerror = function() 
	{
		console.log("Échec de chargement " + url);
	};

 	requete.onload = function() 
	{
		if (requete.status === 200 || requete.status === 304) 
		{
			let responseJSON = JSON.parse(requete.responseText);
			let expressionTraduite = responseJSON[0][0][0];

			console.log(responseJSON);
			if (responseJSON[0][0][4]!=1)
			{
				afficherTraduction("Mot non connu");
			}
			else
			{
				stockerLocalement(langueSource, expression, langueDestination, expressionTraduite);
				afficherTraduction(expressionTraduite);
			}
		}
	};

	  requete.send();
}



function stockerLocalement(langSrc, expression, langDst, exprTraduite) {

  	let traduction = 
	{
		'lsrc': langSrc,
		'expr': expression,
		'ldst': langDst,
		'trad': exprTraduite
	};

	traductionsLocales.push(traduction);

	localStorage.setItem('traductions', JSON.stringify(traductionsLocales));

}

function afficherTraduction(exprTraduite) 
{

	document.getElementById("expressionTraduite").textContent = exprTraduite;
	
}

function rechercheDico()
{
	let expression = document.getElementById("expression").value;
	let langSrc = document.getElementById("langsource").value;
	let langDst = document.getElementById("langdest").value;
	
	let rows = document.getElementById("tab").rows;

	for (let i = 1; i < rows.length; i++) 
	{
		if(rows[i].cells[1].innerHTML===langSrc
			&& rows[i].cells[3].innerHTML===langDst
			&& rows[i].cells[2].innerHTML.includes(expression))
		{
			rows[i].style.display = "table-row";
		}
		else
		{
			rows[i].style.display = "none";
		}
		
	}
}

function supprimerTraductions()
{
    //TODO
	let tab = document.getElementById("tab");
	let rows = document.getElementById("tab").rows;
	traductionsLocales = JSON.parse(localStorage.getItem('traductions'));

	for (let i = 1; i < rows.length; i++) 
	{
		if(rows[i].cells[0].children[0].checked)
		{
			traductionsLocales.splice(i-1, 1);
			tab.deleteRow(i);
			i--;
		}
	}

	localStorage.setItem('traductions', JSON.stringify(traductionsLocales));
}


















