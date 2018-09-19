"use strict";

window.onload=function()
{
	saisieINSEE();
};

function saisieINSEE()
{
		if(typeof sweetalert2==undefined)
	{
		window.alert("La librairie sweetalert n'a pas été chargée, le script ne pourra pas fonctionner");
	}
	else
	{
		swal.mixin
		({	
			input: 'number',
			confirmButtonText: 'Suivant &rarr;',
			cancelButtonText: 'Annuler',
			showCancelButton: true,
			progressSteps: ['1', '2'],
		})

		.queue
		([
			{
				title: 'INSEE',				
				text: 'Quel est votre INSEE ?',
				inputValidator: (value) => 
				{
					if(value.length!=13)
					{
						return 'Entrez un numéro correct'
					}
  				}
			},
			{
				title:'Clé',
				text: 'Quel est votre clé ?',
				inputValidator: (value) => 
				{
					if(value.length!=2)
					{
						return 'Entrez une clé correcte'
					}
  				}
			}
		])
		.then((result) => 
		{	
			if(result.value)
			{
				
				if(verifierINSEE(result.value)==true)
				{
					swal
					({
						title: 'Vérification terminée',
						type:'success',
						text: 'Vos numéros correspondent',
					  	confirmButtonText: 'Terminer'
					})
				}
				else
				{

				}
			}
			else
			{
				swal
				({
					title: 'Annulation',
					type:'info',
					text:'Vous avez annulé',
				  	confirmButtonText: 'Au revoir'
				})
			}
		})
	}
}

function verifierINSEE(input)
{
	console.log(input);
	return true;
}
	
