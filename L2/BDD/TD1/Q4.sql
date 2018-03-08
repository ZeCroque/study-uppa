CREATE TABLE REALISATEURS(
	CODREAL CHAR(5),
	NOMREAL VARCHAR(50),
	NATIONREAL VARCHAR(50),
	DNAISSREAL DATE,
	DDECREAL DATE,
	CONSTRAINT PK_REALISATEURS PRIMARY KEY(CODREAL),
	CONSTRAINT CK_DDECREAL_REALISATEURS CHECK(DDECREAL > DNAISSREAL));

CREATE TABLE FILMS(
	CODFILM CHAR(5), 
	TITREFILM VARCHAR(100), 
	DATESORTIE DATE, 
	DUREE NUMBER(4), 
	BUDGET NUMBER(10,2), 
	CODREAL CHAR(5), 
	CONSTRAINT PK_FILMS PRIMARY KEY(CODFILM), 
	CONSTRAINT CK_DUREE_FILM CHECK(DUREE > 0),
	CONSTRAINT CK_BUDGET_FILM CHECK(DUREE > 0),
	CONSTRAINT FK_CODREAL_REALISATEUR FOREIGN KEY(CODREAL) REFERENCES REALISATEURS);

CREATE TABLE ACTEURS(
	CODACT CHAR(5),
	NOMACT VARCHAR(50),
	PRENOMACT VARCHAR(50),
	NATIONACT VARCHAR(50),
	SEXE CHAR(1),
	DNAISSACT DATE,
	DDECACT DATE,
	CONSTRAINT PK_ACTEURS PRIMARY KEY(CODACT),
	CONSTRAINT CK_SEXE_ACTEURS CHECK(SEXE='m' OR SEXE='f'),
	CONSTRAINT CK_DDECACT_ACTEURS CHECK(DDECACT > DNAISSACT));

CREATE TABLE JOUENT(
	CODFILM CHAR(5),
	NACT CHAR(5),
	NOMPERS VARCHAR(50),
	CONSTRAINT FK_CODFILM_FILMS FOREIGN KEY(CODFILM) REFERENCES FILMS,
	CONSTRAINT FK_NACT_ACTEURS FOREIGN KEY(NACT) REFERENCES ACTEURS,
	CONSTRAINT PK_JOUENT PRIMARY KEY(NACT, CODFILM));
	
