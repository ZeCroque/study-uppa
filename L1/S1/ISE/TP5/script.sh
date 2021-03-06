#!/bin/bash
echo "| Script de copie du site SiteSmileys"
echo "|   Auteur(s) : CROQUEFER"
echo ""
echo "-- Nettoyage du dossier courant"
rm -fr ./Arbo

echo "-- Création du répertoire Arbo"
mkdir ./Arbo

echo "-- Création de l'arborescence"
cd ./Arbo
mkdir ./Binome
mkdir ./Connaisseurs
mkdir ./Depot
mkdir ./Public
mkdir ./Public/images
mkdir ./Public/medias
mkdir ./Secret

cd ./Binome 
>devoir.txt
cd ../Connaisseurs 
>reponse746.txt
cd ../Public 
>wikipedia.html
cd ../Secret 
>journal.doc


cd ../
chmod -R 700 Binome
setfacl -Rm u:rmastrago:rx Binome


echo "Debug: dossier courant : "$(pwd)

#- Décommenter la ligne suivante si vous voulez afficher l'arborescence créée
tree ./
