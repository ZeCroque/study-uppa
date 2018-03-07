==============
TUX le Manchot
==============
---------------------------------------------------
Projet d\'Introduction aux Systèmes d\'Exploitation
---------------------------------------------------

:Auteurs: *G. Croquefer*
:Généré par: *gcroquefer*

Ce document a été généré  à partir du fichier ``tux.rst`` au
format `reStructuredText`_ lui-même créé par le script
``tux.sh``. Ce fichier  rst a  ensuite  été  converti en
HTML  et  PDF avec  les commandes ``rst2html`` et ``rst2pdf``.



.. _reStructuredText: https://aful.org/wikis/interop/ReStructuredText

.. sidebar:: Références

   Les directives du format RST sont disponibles `ici`_.

.. _ici: http://docutils.sourceforge.net/docs/ref/rst/directives.html

L\'objectif est de compléter le script ``tux.sh`` afin que les
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
| 	Pingouin ?    //\                   TUX                   /\	Manchot !		|
|		      V_/_                                       _\_V				|
+-----------------------------------------------------------------------------------------------+


.. _Pingouin: http://bit.ly/W_Pingouin
.. _manchot: http://bit.ly/W_Manchot									     

Les manchots sont des geeks !
=============================

La commande ``screenfetch`` affiche le logo et des informations en temps réel sur la distribution Linux.

::

  %{----------------------------------------------------------------------------------+
  |                          ./+o+-       gcroquefer@scinfe2143.univ-pau.fr          |
  |                  yyyyy- -yyyyyy+      OS: Ubuntu 14.04 trusty                    |
  |               ://+//////-yyyyyyo      Kernel: x86_64 Linux 3.13.0-93-generic     |
  |           .++ .:/++++++/-.+sss/`      Uptime: 4m                                 |
  |         .:++o:  /++++++++/:--:/-      Packages: 2745                             |
  |        o:+o+:++.`..```.-/oo+++++/     Shell: tux.sh                              |
  |       .:+o:+o/.          `+sssoo+/    Resolution: 1920x1200                      |
  |  .++/+:+oo+o:`             /sssooo.   DE: Unity 7.2.6                            |
  | /+++//+:`oo+o               /::--:.   WM: Compiz                                 |
  | \+/+o+++`o++o               ++////.   WM Theme: Ambiance                         |
  |  .++.o+++oo+:`             /dddhhh.   GTK Theme: Ambiance [GTK2/3]               |
  |       .+.o+oo:.          `oddhhhh+    Icon Theme: ubuntu-mono-dark               |
  |        \+.++o+o``-````.:ohdhhhhh+     Font: Ubuntu 11                            |
  |         `:o+++ `ohhhhhhhhyo++os:      CPU: Intel Core2 Quad CPU Q9550 @ 2.826GHz |
  |           .o:`.syhhhhhhh/.oo++o`      GPU: Quadro FX 580                         |
  |               /osyyyyyyo++ooo+++/     RAM: 584MiB / 3886MiB                      |
  |                   ````` +oo+++o\:                                                |
  |                          `oo++.                                                  |
  +----------------------------------------------------------------------------------%}

Ici, la sortie de ``screenfetch`` est filtrée pour extraire des informations qui sont stockées dans des variables et insérées dans cette petite bande-dessinée générée par un enchaînement de commandes :

::

 /*       _\|/_
         (o o)
 +----oOO-{_}-OOo------------------------------------------------------------+
 |                              .--,       .--,                              |
 |                             ( (  \.---./  ) )                             |
 |                              '.__/o   o\__.'                              |
 |                                 {=  ^  =}                                 |
 |                                  >  -  <                                  |
 |        ______________________.""`-------`"".______________________        |
 |       /                                                           \       |
 |       \   +------------------------+ +------------------------+   /       |
 |       /   |  Mon ordi tourne sous  | | Il utilise 590MiB      |   \       |
 |       \   |  Ubuntu 14.04 trusty   | | sur les 3886MiB dispo. |   /       |
 |       /   |                        | |                        |   \       |
 |       \   |    (o<   _-)           | |   (o<   _-)            |   /       |
 |       /   |    //   /\             | |   //   /\              |   \       |
 |       \   |    V_/_ __V            | |   V_/_ __V             |   /       |
 |       /   +------------------------+ +------------------------+   \       |
 |       \   +----------------------------+ +-----------------+      /       |
 |       /   | Et il est en marche depuis | |    Fais gaffe ! |      \       |
 |       \   |  heures, minutes !         | |      tu deviens |      /       |
 |       /   |                            | | un vrai geek... |      \       |
 |       \   |                            | |               / |      /       |
 |       /   |    (o<   _-)               | |       (*_   >-) |      \       |
 |       \   |    //   /\                 | |        //\   /\ |      /       |
 |       /   |    V_/_ __V                | |       V_/_ _\_V |      \       |
 |       \   +----------------------------+ +-----------------+      /       |
 |       /                                                           \       |
 |       \___________________________________________________________/       |
 |                                ___)( )(___                                |
 |                               (((__) (__)))                               |
 +--------------------------------------------------------------------------*/ 


