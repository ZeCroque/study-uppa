#!/bin/bash

#-----------------------------------------------------
# Projet L1 - Introduction aux Systèmes d'Exploitation
#-----------------------------------------------------

# Remplacer les noms par les vôtres
auteurs="G. Croquefer"

# Les fichiers générés par le script
fichier_rst="tux.rst"
fichier_html="tux.html"
fichier_pdf="tux.pdf"

echo "Génération de ${fichier_rst}"

# Insertion d'un bloc de texte dans fichier_rst.
# Le texte concerné est compris entre les deux mots BLOC.
cat > ${fichier_rst}  << BLOC
==============
TUX le Manchot
==============
---------------------------------------------------
Projet d\'Introduction aux Systèmes d\'Exploitation
---------------------------------------------------

:Auteurs: *${auteurs}*
:Généré par: *$(whoami)*

Ce document a été généré  à partir du fichier \`\`tux.rst\`\` au
format \`reStructuredText\`_ lui-même créé par le script
\`\`tux.sh\`\`. Ce fichier  rst a  ensuite  été  converti en
HTML  et  PDF avec  les commandes \`\`rst2html\`\` et \`\`rst2pdf\`\`.



.. _reStructuredText: https://aful.org/wikis/interop/ReStructuredText

.. sidebar:: Références

   Les directives du format RST sont disponibles \`ici\`_.

.. _ici: http://docutils.sourceforge.net/docs/ref/rst/directives.html

L\'objectif est de compléter le script \`\`tux.sh\`\` afin que les
documents générés ressemblent le plus fidèlement possible au modèle fourni.

L'histoire de TUX
=================

Quelques années après le lancement du noyau Linux en 1991, le besoin d'un logo 
se fit sentir. De nombreuses propositions furent soumises, mais **Linus Torvalds**, le créateur de Linux, suggéra de styliser un manchot !

À ceux qui rétorquèrent qu'un tel animal ne mettrait pas en valeur la puissance de ce nouveau système d'exploitation, Linus répondit qu'ils ne connaissaient visiblement pas *sa vitesse à la course* et la *dureté de son bec* ! Celui-ci s'était en effet fait courser et pincer dans un zoo. C'est **Larry Ewing** qui emporta le concours de logo.

Le nom du manchot, **TUX**, peut-être compris comme le rétro-acronyme composé à partir des mots "**T**\ orvalds" et "**U**\ ni\ **X**".

.. figure:: http://bit.ly/Logo_TUX
	:align: center

	**Figure :** TUX, la mascotte de Linux.
	

Manchot ou pingouin ?
---------------------

+-----------------------------------------------+-----------------------------------------------+
| **Noms et liens vers site web**		| **Images**					|
+===============================================+===============================================+
| Pingouin_ se dit auk en anglais		| .. image:: http://bit.ly/I_Pingouin		|
+-----------------------------------------------+-----------------------------------------------+
| Alors que manchot_ se traduit par *penguin* !	| .. image:: http://bit.ly/I_Manchot		|
+-----------------------------------------------+-----------------------------------------------+
|::												|
|												|
|                     (-_                                         _o)				|
| 	Pingouin ?    //\                   TUX                   /\\	Manchot !		|
|		      V_/_                                       _\_V				|
+-----------------------------------------------------------------------------------------------+


.. _Pingouin: http://bit.ly/W_Pingouin
.. _manchot: http://bit.ly/W_Manchot									     

Les manchots sont des geeks !
=============================

La commande \`\`screenfetch\`\` affiche le logo et des informations en temps réel sur la distribution Linux.

::

 $(screenfetch -N | boxes -d netdata)

Ici, la sortie de \`\`screenfetch\`\` est filtrée pour extraire des informations qui sont stockées dans des variables et insérées dans cette petite bande-dessinée générée par un enchaînement de commandes :

::

 $((paste -d ' ' <(screenfetch -N  | grep "OS" | awk -F"OS: " '{print "Mon ordi tourne sous\n" $2 "\n \ \n  (o<   _-)\n  //\   /\\ \n  V_/_ _\_V"}' | boxes -d stone -p r2l2; screenfetch -N  | grep "Uptime:" | awk -F"d " '{print $2}' | tr 'h' ';' | tr 'm' ';' | awk -F";" '{print "Et il est en marche depuis\n" $1 " heures," $2 " minutes !\n \ \n  \ \n   (o<   _-)\n   //\   /\\ \n   V_/_ _\_V"}' | boxes -d stone) <(screenfetch -N | grep "RAM" | awk -F"RAM: " '{print $2}' | awk -F"/" '{print "Il utilise " $1 "\nsur les" $2 " dispo.\n \ \n  (o<   _-)\n  //\   /\\ \n  V_/_ _\_V"}'  | boxes -d stone ; echo -e " Fais gaffe !\ntu deviens\nun vrai geek...\n/\n(*_   >-)\n//\   /\\ \nV_/_ _\_V" | boxes -d stone -a r)) | boxes -d mouse -p r3l3 | boxes -d peek -s 78 -a c) 


BLOC



#sed > modif chaine car


# Génération des formats HTML et PDF
echo "Génération de ${fichier_html}"
rst2html -d -t -s ${fichier_rst} ${fichier_html}
#echo "Génération de ${fichier_pdf}"
#rst2pdf           ${fichier_rst} ${fichier_pdf}


