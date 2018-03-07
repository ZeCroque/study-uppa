#!/bin/bash
echo "| Script de copie de la propriété"
echo "|   Auteur(s) : CROQUEFER"
echo ""
echo "-- Nettoyage du dossier courant"
rm -fr ./PropriétéScriptée

echo "-- Création du répertoire PropriétéScripté"
mkdir ./PropriétéScriptée

echo "-- Création de l'arborescence"
cd ./PropriétéScriptée
mkdir ./Allée
mkdir ./Jardin
mkdir ./Jardin/Salon-Séjour
mkdir ./Jardin/Salon-Séjour/Cuisine
mkdir ./Jardin/Salon-Séjour/Cuisine/Arrière-Cuisine
mkdir ./Jardin/Salon-Séjour/Dégagement
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre1
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre1/Douche
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre2
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre2/Douche
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre3
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre3/"Salle de Bain"
mkdir ./Jardin/Salon-Séjour/Dégagement/Chambre4
mkdir ./Jardin/Salon-Séjour/WC
mkdir ./Terrasse
mkdir ./Terrasse/Local_piscine
cd ./Allée
ln -s ../Jardin/Salon-Séjour/Cuisine/Arrière-Cuisine
cd Arrière-Cuisine
ln -s ../../../../Terrasse
cd ../../Dégagement/Chambre3
ln -s ../../../../Jardin
cd ../Chambre4
ln -s ../Chambre3/"Salle de Bain"

echo "-- Rappatriement des premiers éléments"
cd ../../../../
cp /home/IntroSysEx/TP2/Centre_commercial/arbres.png ./Jardin
cp /home/IntroSysEx/TP2/Centre_commercial/piscine.png ./Terrasse
cp /home/IntroSysEx/TP2/Centre_commercial/voiture.png ./Allée

echo "-- Ouverture du camion"
wget http://bjobard.perso.univ-pau.fr/Cours/ISE/Assets/TP2/Camion_d%C3%A9m%C3%A9nagement.tgz
tar xvfz Camion_déménagement.tgz
rm -rf Camion_déménagement.tgz
cp ./Camion_déménagement/litA.png ./Jardin/Salon-Séjour/Dégagement/Chambre1
cp ./Camion_déménagement/litB.png ./Jardin/Salon-Séjour/Dégagement/Chambre2
cp ./Camion_déménagement/litC.png ./Jardin/Salon-Séjour/Dégagement/Chambre3
cp ./Camion_déménagement/litD.png ./Jardin/Salon-Séjour/Dégagement/Chambre4
cp ./Camion_déménagement/table1.png ./Jardin/Salon-Séjour/Cuisine
cp ./Camion_déménagement/table2.png ./Jardin/Salon-Séjour/
cp ./Camion_déménagement/canapé.png ./Jardin/Salon-Séjour/
cp ./Camion_déménagement/"double lavabo.png" ./Jardin/Salon-Séjour/Dégagement/Chambre3/"Salle de Bain"
cp ./Camion_déménagement/fauteuils.png ./Terrasse
cp ./Camion_déménagement/WC.png ./Jardin/Salon-Séjour/WC
rm -rf Camion_déménagement

