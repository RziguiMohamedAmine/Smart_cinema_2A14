/*
CREATE TABLE abonne
(
code number NOT NULL ,
nom varchar2(50) NOT NULL,
prenom varchar2(50) NOT NULL,
telephone number NOT NULL,
mail varchar2(50) NOT NULL);
*/



--alter table abonne add constraint fk_abonne_abonnement FOREIGN KEY (idab) references abonnement (idab);

/*

CREATE TABLE abonnement
(
idab varchar2(50) NOT NULL ,
tarif number NOT NULL,
date_debut varchar2(50) NOT NULL,
date_fin varchar2(50) NOT NULL,
type_ab varchar2(50) NOT NULL);

*/




/*
CREATE TABLE loginQt
(
username varchar2(50) NOT NULL,
password number NOT NULL);
*/



/*
insert into loginQt
values ('medamine',121998);
*/
/*
CREATE TABLE DEPARTEMENT
(
TYPE varchar2(50) NOT NULL,
NB_EMPLOYE number NOT NULL);
*/




/*
CREATE TABLE employe
(
FORMATION varchar2(50) NOT NULL,
SALAIRE number NOT NULL,
TELEPHONE number NOT NULL,
ID number NOT NULL,
AGE number NOT NULL,
NOM varchar2(50) NOT NULL,
PRENOM varchar2(50) NOT NULL);
*/
--numero number constraint fk_emp_dep references departement (numero)



/*
CREATE TABLE produits
(
code varchar2(50) NOT NULL,
nom varchar2(50) NOT NULL,
quantite number NOT NULL,
prix float NOT NULL);
*/
/*
CREATE TABLE fournisseurs
(
nom varchar2(50) NOT NULL,
prenom varchar2(50) NOT NULL,
code varchar2(50) NOT NULL,
numero number NOT NULL,
email varchar2(50) NOT NULL);
*/

/*
CREATE TABLE salle
(
NUM varchar2(20) NOT NULL,
NBRP varchar2(50) NOT NULL,
NBR number NOT NULL);
*/


/*
CREATE TABLE film
(
NOM varchar2(50) NOT NULL,
ANNEE number NOT NULL,
DIRECTOR varchar2(50) NOT NULL,
RATIO number NOT NULL);
*/
--NUM varchar2(20) constraint fk_salle_film references salle (NUM)
/*
CREATE TABLE categorie_tr
(
id varchar2(20) NOT NULL,
nom varchar2(20) NOT NULL,
type number NOT NULL);
*/



CREATE TABLE transaction
(
id varchar2(50) NOT NULL,
objet varchar2(50) NOT NULL,
somme float NOT NULL,
etat int NOT NULL);















