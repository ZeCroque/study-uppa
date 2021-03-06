SELECT*
  FROM FILMS
  WHERE BUDGET>1000000 ;
SELECT*
  FROM ACTEURS
  WHERE NATIONACT='Américain'
        AND SEXE='f';
SELECT NOMACT, PRENOMACT
  FROM ACTEURS
  WHERE NATIONACT='Français'
        OR NATIONACT='Belge';
SELECT TITREFILM
  FROM REALISATEURS, FILMS
  WHERE NOMREAL='Cameron'
        AND PRENOMREAL='James'
        AND REALISATEURS.CODREAL=FILMS.CODREAL;
SELECT NOMACT, PRENOMACT
  FROM ACTEURS, FILMS, JOUENT
  WHERE (NATIONACT='Français'
        OR NATIONACT='Américain')
        AND TITREFILM='La Plage'
        AND JOUENT.NACT=ACTEURS.CODACT
        AND JOUENT.CODFILM=FILMS.CODFILM;
SELECT A2.NOMACT, A2.PRENOMACT, A2.DNAISSACT
  FROM ACTEURS A1, ACTEURS A2
  WHERE A1.NOMACT='Dujardin'
        AND A1.PRENOMACT='Jean'
        AND EXTRACT(YEAR FROM A1.DNAISSACT)=EXTRACT(YEAR FROM A2.DNAISSACT);
SELECT*
  FROM FILMS, REALISATEURS
  WHERE TITREFILM='Ensemble c''est tout'
        AND FILMS.DATESORTIE>REALISATEURS.DDECREAL;
SELECT TITREFILM, NOMREAL
  FROM JOUENT, FILMS, REALISATEURS
  WHERE JOUENT.CODFILM=FILMS.CODFILM
        AND REALISATEURS.CODREAL=FILMS.CODREAL
        AND NOMPERS='Lieutenant Ellen Repley';

SELECT*
  FROM REALISATEURS
  WHERE CODREAL IN
(SELECT R1.CODREAL
  FROM REALISATEURS R1
MINUS
(SELECT CODREAL
  FROM ACTEURS, JOUENT, FILMS
  WHERE JOUENT.CODFILM=FILMS.CODFILM
  AND ACTEURS.CODACT=JOUENT.NACT
  AND NATIONACT='Américain'));
