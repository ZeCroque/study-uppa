#!/bin/bash
echo "| Script de copie du site SiteSmileys"
echo "|   Auteur(s) : CROQUEFER"
echo ""
echo "-- Nettoyage du dossier courant"
rm -fr ./SiteSmileysScripté

echo "-- Création du répertoire SiteSmileysScripté"
mkdir ./SiteSmileysScripté

echo "-- Création de l'arborescence"
cd ./SiteSmileysScripté
mkdir ./image
mkdir ./des_images
mkdir ./des_images/encore_des_images
mkdir ./des_images/et_encore
mkdir ./une_autre_image

echo "Debug: dossier courant : "$(pwd)

#- Décommenter la ligne suivante si vous voulez afficher l'arborescence créée
tree ../SiteSmileysScripté

echo "-- Copie des fichiers dans l'arborescence"
cp /home/IntroSysEx/TP3/SiteSmileys/page1.html .
cp /home/IntroSysEx/TP3/SiteSmileys/image/smileyB.png ./image
cp /home/IntroSysEx/TP3/SiteSmileys/une_autre_image/smileyC.png ./une_autre_image
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/smileyD.png ./des_images
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/smileyE.png ./des_images
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/encore_des_images/smileyF.png ./des_images/encore_des_images
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/encore_des_images/smileyG.png ./des_images/encore_des_images
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/et_encore/smileyH.png ./des_images/et_encore
cp /home/IntroSysEx/TP3/SiteSmileys/des_images/et_encore/smileyI.png ./des_images/et_encore

#- Décommenter la ligne suivante si vous voulez afficher l'arborescence créée
tree ../SiteSmileysScripté
