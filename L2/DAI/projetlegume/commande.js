
let panier = {
  total: 12.5,
  articles: [
    {
      article: 'Oranges',
      quantité: 3,
      prixUnitaire: 1.5,
      prix: 4.5
    }, {
      article: 'Fraises',
      quantité: 1,
      prixUnitaire: 8,
      prix: 8
    }
  ]
};

  window.addEventListener("load", function()
  {
    fabriqueInterfaceGraphique(articles, tarifs);
    let oriCheckboxTab=document.getElementsByClassName('origines')[0];
    let oriCheckboxElt;
    for(let i=1; i<oriCheckboxTab.childElementCount; i++)
    {
        oriCheckboxElt=oriCheckboxTab.children[i].children[0];
        oriCheckboxElt.addEventListener("change", oriCheckboxListener)
    }
    let catCheckboxTab=document.getElementsByClassName('categories')[0];
    let catCheckboxElt;
    for(let i=1; i<catCheckboxTab.childElementCount; i++)
    {
        catCheckboxElt=catCheckboxTab.children[i].children[0];
        catCheckboxElt.addEventListener("change", oriCheckboxListener)
    }
    oriCheckboxTab.children[1].children[0].checked=true;
    oriCheckboxTab.children[1].children[0].disabled=true;
    catCheckboxTab.children[1].children[0].checked=true;
    catCheckboxTab.children[1].children[0].disabled=true;

  });

  function ajouter(element)
  {
    let i,j;
    for(i=0, j=0; i<this.tab.length; i++)
    {
      if(this.tab[i]!=element)
      {
        j++;
      }
    }
    if(i==j)
    {
      this.tab[this.tab.length]=element;
    }
  }

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

  function set()
  {
    this.tab=[0];
    this.ajouter=ajouter;
    this.appartient =appartient;
  }

function oriCheckboxListener(event)
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

  /*********************Gestion des checkbox****************************/

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

  /*********************Gestion du filtrage****************************/

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
          articlePhoto = articles[i].photos[k-1];
        }

        newArticle = articleElt.cloneNode(true);

        let articleName = newArticle.getElementsByClassName('nom')[0];
        let priceLabel = newArticle.getElementsByClassName('prix')[0];
        let origineLabel = newArticle.getElementsByClassName('origine')[0];
        let uniteLabel = newArticle.getElementsByClassName('unité')[0];
        let articleImgStyle = newArticle.getElementsByClassName('img')[0].style;

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
        articleList.appendChild(newArticle);
        k++;

      }
    }
  }
  articleList.removeChild(articleElt);
  //--CHECKBOX--

  let oriCheckboxTab=document.getElementsByClassName('origines')[0];
  let oriCheckboxElt=oriCheckboxTab.children[1];
  let newCheckbox;
  let currentOrigines=[""];

  for (i=0; i< tarifs.length; i++)
	{
    for (j=0, k=0; j<currentOrigines.length; j++)
    {
      if(currentOrigines[j]!=tarifs[i].origine)
        k++;
    }
    if (j==k)
    {
      currentOrigines[i]=tarifs[i].origine;

  		newCheckbox = oriCheckboxElt.cloneNode(true);
  		oriCheckboxTab.appendChild(newCheckbox);

      newCheckbox.children[1].innerHTML=tarifs[i].origine;
      newCheckbox.children[0].name="ori_"+tarifs[i].origine.toLowerCase();
      newCheckbox.children[0].checked=false;
      newCheckbox.children[0].disabled=false;
    }
  }

  let catCheckboxTab=document.getElementsByClassName('categories')[0];
  let catCheckboxElt=catCheckboxTab.children[1];
  newCheckbox=catCheckboxElt;
  let currentCategory=[""];
  let str;

  for (i=1; i< articles.length; i++)
	{
    for (j=0, k=0; j<currentCategory.length; j++)
    {
      if(currentCategory[j]!=articles[i].catégorie)
        k++;
    }
    if (j==k)
    {
      currentCategory[i]=articles[i].catégorie;

  		newCheckbox = catCheckboxElt.cloneNode(true);
  		catCheckboxTab.appendChild(newCheckbox);
      str=articles[i].catégorie.substring(0,1).toUpperCase()+articles[i].catégorie.substring(1,articles[i].catégorie.length)+"s";
      newCheckbox.children[1].innerHTML=str;

      newCheckbox.children[0].name="cat_"+articles[i].catégorie.toLowerCase()+"s";
      newCheckbox.children[0].checked=false;
      newCheckbox.children[0].disabled=false;
    }
  }


}

function envoyerCommande() {
  let email = "destinataire@mail.com";
  let sujet = "commande de fruits et légumes";
  let corps = "\nCommande\n\nVoici un récapitulatif des articles commandés\npour un montant de 12.50 € :\n...\n..."
  email = encodeURIComponent(email);
  sujet = encodeURIComponent(sujet);
  corps = encodeURIComponent(corps);
  let uri = "mailto:" + email + "?subject=" + sujet + "&body=" + corps;
  window.location.href = uri;
}
