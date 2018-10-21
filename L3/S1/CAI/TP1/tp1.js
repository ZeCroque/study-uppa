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
		swal.mixin(
		{
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

				if(97-(result.value[0]%97)==result.value[1])
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
					swal
					({
						confirmButtonText: 'Réessayer',
						cancelButtonText: 'Quitter',
						showCancelButton: true,
						title: 'Vérification terminée',
						type:'error',
						text: 'Vos numéros ne correspondent pas.\nVoulez vous réessayer ?',
					})
					.then((result) =>
					{
						if(result.value)
						{
							saisieINSEE();
						}
					})
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
		});

	}
}

