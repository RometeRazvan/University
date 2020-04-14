use  Filme;

create table Magazin(
idMagazin int primary key,
nume varchar(20));

create table Film(
idFilm int primary key,
idMagazin int foreign key references Magazin(idMagazin),
nume varchar(20),
gen varchar(20));

create table Sarcina(
idSarcina int primary key,
nume varchar(20),
descriere varchar(100));

create table Angajat(
idAngajat int primary key,
idSarcina int foreign key references Sarcina(idSarcina),
idMagazin int foreign key references Magazin(idMagazin),
nume varchar(20),
telefon varchar(20));

create table Recenzie(
idRecenzie int primary key,
idFilm int foreign key references Film(idFilm),
descriere varchar(20),
nota int);

create table Concediu(
idConcediu int primary key,
idAngajat int foreign key references Angajat(idAngajat),
destinatie varchar(20),
pret int);

create table Client(
idClient int primary key,
nume varchar(20),
telefon varchar(20));

create table Achizitie(
idAchizitie int primary key,
idFilim int foreign key references Film(idFilm),
idCLient int foreign key references Client(idClient));


create table Social(
idSocial int primary key,
idClient int foreign key references Client(idClient),
nume varchar(20),
descriere varchar(20));

create table Reclama(
idReclama int primary key,
idClient int foreign key references Client(idClient),
descriere varchar(20));