#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**typedef struct Matrice{
    int nbLigne;
    int nbColonne;
    int cases[nbLigne][nbColonne];
}Matrice;**/ 	

/// STRUCTURES UTILISEE DANS LES CALCULS ///
typedef struct Film{
	int id;
	char  titre[400];
	char  realisateur[100];
	char  type[50];
	int annee;
	int duree;
	char ** acteur;
	char ** tags;

}Film;

typedef struct Utilisateur{
	int id;
/*	char * pseudo;
	char * motdepasse;*/
	Film likedmovies[3];
}Utilisateur;


typedef struct _hashmap_element{
	int key;
	float value;
} hashmap_element;


typedef struct _hashmap_map{
	int table_size;
	int* actual_size;
	hashmap_element *data;
} hashmap_map;


// FONCTIONS AUXILIARES //
int max(int x, int y, int z);
int min(int x, int y, int z);
int* tagsbinaire(Film f1);
int** produitMatriciel(int A[20][20], int B[20][20]);

// CONSTRUCTEURS //
Film* cst_film(int id);
Utilisateur * cst_utilisateur(int id);
hashmap_element* cst_hashmapelement(int key, int value);
hashmap_map* cst_hashmap (int size);

// FONCTIONS DE MANIPULATIONS DES HASHMAP //
void hashmap_add(hashmap_map m, hashmap_element e);
void hashmap_tostring(hashmap_map m);
void trihashmapvalue (hashmap_map m);

// CALCUL DES FILMS A RECOMMENDE //
int * favyear (Film f1 , Film f2 , Film f3);
int * favduration (Film f1 , Film f2 , Film f3) ;
int * favtags (Film f1 , Film f2 , Film f3);
char * favrealisateur (Film f1 , Film f2 ,Film f3);
char * favacteur (Film f1, Film f2, Film f3);
float calculnoteObjet(Film f,Utilisateur u);
hashmap_map * hashmap_note_objet(Utilisateur * u);
//double calculnoteSocial(Utilisateur u1, Utilisateur u2);

