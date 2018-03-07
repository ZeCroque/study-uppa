function recopyFields()
{
	var address = document.getElementById('f_livrAdresse');
	var cp = document.getElementById('f_livrCP');
	var ville = document.getElementById('f_livrVille');

	if(document.getElementById('box').checked==true)
	{		
		address.value = document.getElementById('f_factAdresse').value;
		cp.value = document.getElementById('f_factCP').value;
		ville.value = document.getElementById('f_factVille').value;

		address.readOnly=true;
		cp.readOnly=true;
		ville.readOnly=true;
	}
	else
	{		
		address.value = null;
		cp.value = null;
		ville.value = null;

		address.readOnly=false;
		cp.readOnly=false;
		ville.readOnly=false;
	}
	
}
