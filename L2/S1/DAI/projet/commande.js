
let panier = {
  total: 0,
  articles: []
};

window.addEventListener("load", function()
{
  fabriqueInterfaceGraphique();
  fabriquerCheckbox();
  let tab=document.getElementsByClassName("panier")[0].children[0];
  let supprBouton = tab.rows[tab.rows.length-1].cells[2].children[0];
  supprBouton.addEventListener("click", suppBoutonListener);
});

function appartient(element)
{
  let i;
  for(i=0; i<this.tab.length; i++)
  {
    if(this.tab[i]==element)
    {
      return true;
    }
  }
  return false;
}

function ajouter(element)
{
  if(!this.appartient(element))
  {
    this.tab[this.tab.length]=element;
  }
}

function set()
{
  this.tab=[0];
  this.ajouter=ajouter;
  this.appartient =appartient;
}

function buttonListener(event)
{
  let article=event.target.parentNode;
  let quantite=article.getElementsByClassName("quantite")[0].children[1].value;
  let prix=article.getElementsByClassName("prix")[0].children[0].innerHTML;
  let nom=article.getElementsByClassName("nom")[0].innerHTML;
  let panierSet=new set();
  let i=0;

  if(quantite>0)
  {
    let panierElt=
    {
      article: nom,
      quantité: quantite,
      prixUnitaire: prix,
      prix: prix*quantite
    };
    for(i=0;i<panier.articles.length;i++)
    {
      panierSet.ajouter(panier.articles[i].article+panier.articles[i].prixUnitaire);
    }
    if(!panierSet.appartient(panierElt.article+panierElt.prixUnitaire))
    {
      panier.articles[panier.articles.length]=panierElt;
    }
    else
    {
      alert("Impossible d'ajouter un article déjà présent dans le panier.");
    }

  }
  else
  {
    alert("Impossible d'ajouter une quantité nulle au panier.");
  }

  fabriquerPanier();

}

function quantiteListener(event)
{
  let value=event.target.value;
  let prixUnite=event.target.parentNode.nextElementSibling.innerHTML;
  let prixTotalElt=event.target.parentNode.nextElementSibling.nextElementSibling;
  prixTotalElt.innerHTML=value*prixUnite;
  actualiserTotal();
}

function suppBoutonListener(event)
{
  let buttonElt=event.target;
  let tab=event.target.parentNode.parentNode.parentNode.parentNode;
  let i=0;
  let j=0;

  for(i=2; i<tab.rows.length-1; i++)
  {
    if(tab.rows[i].cells[4].children[0].checked)
    {
      for(j=0; j<panier.articles.length; j++)
      {
        if(panier.articles[j].article+panier.articles[j].prixUnitaire==tab.rows[i].cells[0].innerHTML+tab.rows[i].cells[2].innerHTML)
        {
          panier.articles.splice(j,1);
          tab.rows[i].remove();
          i--;
        }
      }

    }
    if(tab.rows.length==3)
    {
      tab.rows[1].style.display="table-row";
    }
  }



  actualiserTotal();
}

function checkboxListener(event)
{
  let checkboxElt=event.target;
  let category=checkboxElt.parentNode.parentNode;
  let catCheckboxElt;
  let catCheckboxTab=document.getElementsByClassName('categories')[0];
  let catSet=new set();
  let oriCheckboxTab=document.getElementsByClassName('origines')[0];
  let oriCheckboxElt;
  let oriSet=new set();
  let articleTab=document.getElementsByClassName('articles')[0];
  let i;
  let j;
  let str;

  /**********************Gestion des Checkbox*********************/

  for(i=2, j=2; i<category.childElementCount; i++)
  {
    if(category.children[i].children[0].checked)
    {
      j++
    }
  }

  if (j==i || j==2 || checkboxElt.name=="ori_toutes" || checkboxElt.name=="cat_toutes")
  {
    for(i=2; i<category.childElementCount; i++)
    {
      category.children[i].children[0].checked=false;
    }
    category.children[1].children[0].checked=true;
    category.children[1].children[0].disabled=true;
  }
  else
  {
    category.children[1].children[0].checked=false;
    category.children[1].children[0].disabled=false;
  }

  /**********************Gestion des Filtres*********************/


  for(i=0;i<articleTab.childElementCount;i++)
  {
    articleTab.children[i].style.display="none";
  }

  for(i=2; i<catCheckboxTab.childElementCount; i++)
  {
    if(catCheckboxTab.children[i].children[0].checked || catCheckboxTab.children[1].children[0].checked)
    {
      str=catCheckboxTab.children[i].children[1].innerHTML.toLowerCase();
      str=str.substring(0, str.length-1);
      catSet.ajouter(str);
    }
  }

  for(i=2; i<oriCheckboxTab.childElementCount; i++)
  {
    if(oriCheckboxTab.children[i].children[0].checked || oriCheckboxTab.children[1].children[0].checked)
    {
      oriSet.ajouter(oriCheckboxTab .children[i].children[1].innerHTML);
    }
  }

  for (i=0; i<articleTab.childElementCount;i++)
  {
    for(j=0; j<articles.length ;j++)
    {
      if(articles[j].nom==document.getElementsByClassName('nom')[i].innerHTML)
      {
        if (catSet.appartient(articles[j].catégorie) && oriSet.appartient(document.getElementsByClassName('origine')[i].children[0].innerHTML))
        {
          articleTab.children[i].style.display="inline-block";
        }
      }
    }
  }
}

function actualiserTotal()
{
  let tab=document.getElementsByClassName("panier")[0].children[0];
  let totalElt=tab.rows[tab.rows.length-1].cells[1];
  let i=0;
  let total=0;

  for(i=2; i<tab.rows.length-1; i++)
  {
    total+=parseFloat(tab.rows[i].cells[3].innerHTML);
  }
  totalElt.innerHTML=total;
}

function fabriquerPanier()
{
  let panierTab=document.getElementsByClassName("panier")[0].children[0];
  let i=0;

  for(i=2; i<panierTab.rows.length-1; i++)
  {
    panierTab.rows[i].remove();
    i--;
  }

  for(i=0; i<panier.articles.length; i++)
  {
      let row = panierTab.rows[i+1].cloneNode(true);

      row.cells[0].innerHTML=panier.articles[i].article;
      row.cells[1].children[0].value=panier.articles[i].quantité;
      row.cells[1].children[0].disabled=false;
      row.cells[1].addEventListener("change", quantiteListener);
      row.cells[2].innerHTML=panier.articles[i].prixUnitaire;
      row.cells[3].innerHTML=panier.articles[i].prix;
      row.cells[4].children[0].disabled=false;
      row.style.display="table-row";
      panierTab.insertBefore(row, panierTab.lastElementChild);
  }
  panierTab.rows[1].style.display="none";
  actualiserTotal();
}

function fabriquerCheckbox()
{
  let oriCheckboxTab=document.getElementsByClassName('origines')[0];
  let oriCheckboxElt=oriCheckboxTab.children[1];
  let newCheckbox;
  let oriSet=new set();

  oriCheckboxElt.addEventListener("change", checkboxListener);

  for (i=0; i< tarifs.length; i++)
	{
    if(!oriSet.appartient(tarifs[i].origine))
    {
      oriSet.ajouter(tarifs[i].origine);
  		newCheckbox = oriCheckboxElt.cloneNode(true);
  		oriCheckboxTab.appendChild(newCheckbox);

      newCheckbox.children[1].innerHTML=tarifs[i].origine;
      newCheckbox.children[0].name="ori_"+tarifs[i].origine.toLowerCase();
      newCheckbox.children[0].checked=false;
      newCheckbox.children[0].disabled=false;
      newCheckbox.addEventListener("change", checkboxListener);
    }
  }

  let catCheckboxTab=document.getElementsByClassName('categories')[0];
  let catCheckboxElt=catCheckboxTab.children[1];
  newCheckbox=catCheckboxElt;
  let catSet = new set();
  let str;

  catCheckboxElt.addEventListener("change", checkboxListener);

  for (i=1; i< articles.length; i++)
	{
    if (!catSet.appartient(articles[i].catégorie))
    {
      catSet.ajouter(articles[i].catégorie);

  		newCheckbox = catCheckboxElt.cloneNode(true);
  		catCheckboxTab.appendChild(newCheckbox);
      str=articles[i].catégorie.substring(0,1).toUpperCase()+articles[i].catégorie.substring(1,articles[i].catégorie.length)+"s";
      newCheckbox.children[1].innerHTML=str;

      newCheckbox.children[0].name="cat_"+articles[i].catégorie.toLowerCase()+"s";
      newCheckbox.children[0].checked=false;
      newCheckbox.children[0].disabled=false;
      newCheckbox.addEventListener("change", checkboxListener);
    }
  }

  oriCheckboxElt.children[0].checked=true;
  oriCheckboxElt.children[0].disabled=true;
  catCheckboxElt.children[0].checked=true;
  catCheckboxElt.children[0].disabled=true;

}

function fabriqueInterfaceGraphique()
{
	let dirImages = "./images/";
  let articleList = document.getElementsByClassName('articles')[0];
	let articleElt = articleList.getElementsByClassName('article')[0];
  let newArticle=articleElt.cloneNode(true);
  let articlePhoto;
  let articleName
  let priceLabel;
  let origineLabel;
  let uniteLabel;
  let articleImgStyle;
  let refTmp=[""];
  let i=0;
  let j=0;
  let k=0;

  for (i=0; i<articles.length; i++)
  {
    for(j=0, k=0; j<tarifs.length; j++)
    {
      if(tarifs[j].ref==articles[i].ref)
      {
        if (k<articles[i].photos.length)
        {
          articlePhoto = articles[i].photos[k];
        }
        else
        {
          articlePhoto = articles[i].photos[0];
        }

        newArticle = articleElt.cloneNode(true);

        let articleName = newArticle.getElementsByClassName('nom')[0];
        let priceLabel = newArticle.getElementsByClassName('prix')[0];
        let origineLabel = newArticle.getElementsByClassName('origine')[0];
        let uniteLabel = newArticle.getElementsByClassName('unité')[0];
        let articleImgStyle = newArticle.getElementsByClassName('img')[0].style;
        let articleButton = newArticle.getElementsByTagName('button')[0];

        articleImgStyle.backgroundImage = "url('" + dirImages + articlePhoto.url + "')";
        articleImgStyle.backgroundPositionX = -articlePhoto.x + "px";
        articleImgStyle.backgroundPositionY= -articlePhoto.y + "px";
        articleImgStyle.width = articlePhoto.w + "px";
        articleImgStyle.height = articlePhoto.h + "px";
        articleName.innerHTML=articles[i].nom;
        priceLabel.children[0].innerHTML=tarifs[j].prix;
        priceLabel.children[1].innerHTML=tarifs[j].unité;
        origineLabel.children[0].innerHTML=tarifs[j].origine;
        uniteLabel.innerHTML=tarifs[j].unité;
        articleButton.addEventListener("click", buttonListener);
        articleList.appendChild(newArticle);
        k++;
      }
    }
  }
  articleList.removeChild(articleElt);
}

function envoyerCommande() {
  let email = "destinataire@mail.com";
  let sujet = "commande de fruits et légumes";
  let tab=document.getElementsByClassName("panier")[0].children[0];
  let total=tab.rows[tab.rows.length-1].cells[1].innerHTML;
  let corps = "\nCommande\n\nVoici un récapitulatif des articles commandés pour un montant de "+total+"€.\n";
  let i=0;
  let j=0;

  for(i=0; i<tab.rows.length-1; i++)
  {
    if(i!=1)
    {
      for (j=0; j<4; j++)
      {
        if(j!=1 || i==0)
        {
          corps+=" "+tab.rows[i].cells[j].innerHTML;
        }
        else if(j==1)
        {
          corps+=" "+tab.rows[i].cells[j].children[0].value;
        }
      }
      corps+="\n";
    }
  }
  email = encodeURIComponent(email);
  sujet = encodeURIComponent(sujet);
  corps = encodeURIComponent(corps);
  let uri = "mailto:" + email + "?subject=" + sujet + "&body=" + corps;
  window.location.href = uri;
}
