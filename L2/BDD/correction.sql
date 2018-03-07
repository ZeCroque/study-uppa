-- realisateurs

insert into realisateurs values('R0001','Cameron','canadien','16/08/1954',NULL);
insert into realisateurs values('R0002','Scott','anglais','30/11/1937',NULL);
insert into realisateurs values('R0003','Mendes','anglais','01/08/1965',NULL);
insert into realisateurs values('R0004','Negulesco','américain','26/02/1900','18/07/1993');
insert into realisateurs values('R0005','Canet','français','10/04/1973',NULL);
insert into realisateurs values('R0006','Berry','français','01/07/1934','12/01/2009');
insert into realisateurs values('R0007','Boyle','anglais','20/10/1956',NULL);
insert into realisateurs values('R0008','Lellouche','français','05/07/1972',NULL);

-- films

insert into films values('F001', 'Avatar', '16/12/2009', 162, 345600000, 'R0001');
insert into films values('F002', 'Aliens, le retour', '08/10/1986', 137, 123456,'R0001');
insert into films values('F003', 'Alien, le huitième passager', '12/09/1979',116, 32122,'R0002');
insert into films values('F004', 'Titanic', '07/07/1998', 194, 67889008, 'R0001');
insert into films values('F005', 'Les noces rebelles', '21/01/2009',125, 563215,'R0003');
insert into films values('F006', 'Titanic', NULL, 98, 12309,'R0004');
insert into films values('F007', 'Les petits mouchoirs', '20/10/2010', 154, 8765432, 'R0005');
insert into films values('F008', 'Ensemble c''est tout', '21/03/2007', 97, 542987, 'R0006');
insert into films values('F009', 'La plage', '16/02/2000', 119, 296306, 'R0007');
insert into films values('F010', 'Narco', '01/12/2004', 105, 328764, 'R0008');

-- acteurs

insert into acteurs values('A0001', 'Worthington', 'Sam', 'australien', 'M', '02/08/1976', NULL);
insert into acteurs values('A0002', 'Saldana', 'Zoe', 'américain', 'F', '19/06/1978', NULL);
insert into acteurs values('A0003', 'Weaver', 'Sigourney', 'américain', 'F', '08/10/1949', NULL);
insert into acteurs values('A0004', 'Lang', 'Stephen', 'américain', 'M', '11/07/1952', NULL);
insert into acteurs values('A0005', 'Biehn', 'Michael', 'américain', 'M', '31/07/1956', NULL);
insert into acteurs values('A0006', 'Henriksen', 'Lance', 'américain', 'M', '05/05/1940', NULL);
insert into acteurs values('A0007', 'Skerritt', 'Tom', 'américain', 'M', '25/08/1933', NULL);
insert into acteurs values('A0008', 'Di Caprio', 'Leonardo', 'américain', 'M', '11/11/1974', NULL);
insert into acteurs values('A0009', 'Winslet', 'Kate', 'anglais', 'F', '05/10/1975', NULL);
insert into acteurs values('A0010', 'Webb', 'Clifton', 'américain', 'M', '11/11/1889','13/10/1966');
insert into acteurs values('A0011', 'Stanwyck', 'Barbara', 'américain', 'F', '16/07/1907', '20/01/1990');
insert into acteurs values('A0012', 'Dalton', 'Audrey', 'américain', 'F', '21/01/1934', NULL);
insert into acteurs values('A0013', 'Wagner', 'Robert', 'américain', 'M', '10/02/1930', NULL);
insert into acteurs values('A0014', 'Cluzet', 'François', 'français', 'M', '21/09/1955', NULL);
insert into acteurs values('A0015', 'Cotillard', 'Marion', 'français', 'F', '30/09/1975', NULL);
insert into acteurs values('A0016', 'Dujardin', 'Jean', 'français', 'M', '19/06/1972', NULL);
insert into acteurs values('A0017', 'Lellouche', 'Gilles', 'français', 'M', '05/07/1972', NULL);
insert into acteurs values('A0018', 'Magimel', 'Benoît', 'français', 'M', '11/05/1974', NULL);
insert into acteurs values('A0019', 'Canet', 'Guillaume', 'français', 'M', '10/04/1973', NULL);
insert into acteurs values('A0020', 'Tautou', 'Audrey', 'français', 'F', '09/08/1976', NULL);
insert into acteurs values('A0021', 'Ledoyen', 'Virginie', 'français', 'F', '15/11/1975', NULL);
insert into acteurs values('A0022', 'Poelvoorde', 'Benoît', 'belge', 'M', '22/09/1964', NULL);

-- jouent

insert into jouent values('F001', 'A0001', 'Jake Sully');
insert into jouent values('F001', 'A0002', 'Neytiri');
insert into jouent values('F001', 'A0003', 'Grace Augustine');
insert into jouent values('F001', 'A0004', 'Le colonel Miles Quaritch');
insert into jouent values('F002', 'A0003', 'Lieutenant Ellen Ripley');
insert into jouent values('F002', 'A0005', 'Caporal Dwayne Hicks');
insert into jouent values('F002', 'A0006', 'Evêque');
insert into jouent values('F003', 'A0003', 'Lieutenant Ellen Ripley');
insert into jouent values('F003', 'A0007', 'Capitaine A.J. Dallas');
insert into jouent values('F004', 'A0008', 'Jack Dawson');
insert into jouent values('F004', 'A0009', 'Rose DeWitt Butaker');
insert into jouent values('F005', 'A0008', 'Franck Wheeler');
insert into jouent values('F005', 'A0009', 'April Wheeler');
insert into jouent values('F006', 'A0010', 'Richard Ward Sturges');
insert into jouent values('F006', 'A0011', 'Julia Sturges');
insert into jouent values('F006', 'A0012', 'Anette Sturges');
insert into jouent values('F006', 'A0013', 'Gifford Roger');
insert into jouent values('F007', 'A0014', 'Max Cantara');
insert into jouent values('F007', 'A0015', 'Marie');
insert into jouent values('F007', 'A0016', 'Ludo');
insert into jouent values('F007', 'A0017', 'Eric');
insert into jouent values('F007', 'A0018', 'Vincent Ribaud');
insert into jouent values('F008', 'A0019', 'Franck');
insert into jouent values('F008', 'A0020', 'Camille');
insert into jouent values('F009', 'A0008', 'Richard');
insert into jouent values('F009', 'A0019', 'Etienne');
insert into jouent values('F009', 'A0021', 'Françoise');
insert into jouent values('F010', 'A0019', 'Gustave Klopp');
insert into jouent values('F010', 'A0022', 'Lenny Bar');
insert into jouent values('F010', 'A0017', 'Le jumeau patineur');



