#include "fonction_calcul.h"
#include "fonction_transfers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfacetest.h"




/**int** produitMatriciel(int A[20][20], int B[20][20]){
    int Produit[20][20];
    int ligne;
    int colonne;
    int indice;

    for (ligne=0; ligne<20; ligne++){
        for (colonne=0; colonne<20; colonne++){
            Produit[ligne][colonne]=0;
            for (indice=0; indice<20; indice++){
                Produit[ligne][colonne] += A[ligne][indice]*B[indice][colonne];
            }
        }
    }
    return Produit
}**/



Film* cst_film(int id) {
	Film * f1;
	f1 = (Film*) malloc(sizeof(Film));
	(*f1).id = id;
	strcpy((*f1).titre, title("BDCSD.txt", id));
	strcpy((*f1).realisateur, director ("BDCSD.txt",id));
	strcpy((*f1).type , type("BDCSD.txt",id));
	(*f1).annee = year ( "BDCSD.txt", id);
	(*f1).duree =  duration ("BDCSD.txt", id);
	(*f1).acteur = (char **)malloc(sizeof(char*)*3)	;
	for (int i = 0; i < 3; ++i)
	{
		(*f1).acteur[i]=actors ("BDCSD.txt",id)[i];
	}
	(*f1).tags = (char **)malloc(sizeof(char*)*6)	;
	for (int i = 0; i < 6; ++i)
	{
		(*f1).tags[i]=tags ("BDCSD.txt", id)[i];
	}
	return f1;

}

Utilisateur * cst_utilisateur(int id){
	Utilisateur * u1;
	u1 = (Utilisateur *) malloc(sizeof(Utilisateur));
	(*u1).id = id;
	for (int i = 0; i < 3; ++i)
	{
		(*u1).likedmovies[i]= *cst_film(selection()[i]);
	}
	return u1;	
}


hashmap_element* cst_hashmapelement(int key, int value) {
	 hashmap_element* e = (hashmap_element*) malloc(sizeof(hashmap_element));
	 e->key = key;
	 e->value = value;

	 return e;

}

 hashmap_map* cst_hashmap (int size) {
 	
	hashmap_map* m = (hashmap_map*) malloc(sizeof(hashmap_map));
	m->data = (hashmap_element*) malloc(sizeof(hashmap_element)*size);
	m->actual_size = (int *) malloc(sizeof(int));
	m->table_size = size;
	*(m->actual_size) = 0;
	return m;
}

void hashmap_add(hashmap_map m, hashmap_element e){
	if(*(m.actual_size) < m.table_size)
	{
		m.data[*(m.actual_size)]=e;
		*(m.actual_size) = *(m.actual_size) + 1;

	}
	else
	{
		printf("%s\n", "hashmap plein");
	}
}

/*hashmap_element* hashmap_depile (hashmap_map m, int i){

	if (i <= *(m.actual_size) )
	{
		hashmap_element * e = cst_hashmapelement(m.data[i].key,m.data[i].value);
		m.data[i].key = 0;
		m.data[i].value= 0;

		return e;
	}

	else
	{
		printf("%s\n","erreur d'indice");
	}
}*/

void hashmap_tostring(hashmap_map m) {
	for (int i = 0; i < *(m.actual_size); ++i)
	{
		printf(" id : %d || titre : %s  || type :  %s|| année : %d || durée : %d  mins || réalisateur : %s ||  NOTE : %f \n ",
		 m.data[i].key,title("BDCSD.txt",m.data[i].key),type("BDCSD.txt",m.data[i].key),
		 year("BDCSD.txt",m.data[i].key),duration("BDCSD.txt",m.data[i].key),director("BDCSD.txt",m.data[i].key),m.data[i].value);
		printf("tags :" );
		for (int j= 0; j < 6; ++j)
		{
			printf("%s ; ",tags("BDCSD.txt",m.data[i].key)[j] );
		}
		printf("|| acteurs : ");
		for (int k = 0; k < 3; ++k)
		{
			printf("%s,\n",actors("BDCSD.txt",m.data[i].key)[k] );
		}
		printf("\n");
	}

}

void trihashmapvalue (hashmap_map m) {
	int j =0;
	hashmap_element* stock = cst_hashmapelement(0,0.0);
	for (int j = 0; j < *(m.actual_size)-1; ++j)
	{
		for (int i = 0; i < *(m.actual_size)-1; ++i)
			{
					if (m.data[i].value <= m.data[i+1].value) {
						*stock=m.data[i];
						m.data[i]=m.data[i+1];
						m.data[i+1]=*stock;
					}
		}
	}
}
	




int* tagsbinaire(Film f1){
	int *tagsint = (int*) malloc(sizeof(int)*18);
	for (int i = 0; i < 18; ++i)
	{
		tagsint[i]=0;
	}
	for (int i = 0; i < 6; ++i)
	{

		if (strcmp(f1.tags[i], " Action " ) == 0) { 
				tagsint[0]=1;
			}
		else if (strcmp(f1.tags[i] , " Biography ") == 0 ){
				tagsint[1]=1;
			}
		else if (strcmp(f1.tags[i] , " Drama " ) == 0) {
				tagsint[2]=1;
				}
		else if (strcmp(f1.tags[i] , " Thriller " ) == 0) {
				tagsint[3]=1;
				}
		else if (strcmp(f1.tags[i] , " Comedy " ) == 0) {
				tagsint[4]=1;
				}
		else if (strcmp(f1.tags[i] , " Sci-Fi " ) == 0) {
				tagsint[5]=1;
				}
		else if (strcmp(f1.tags[i] , " Fantasy " ) == 0) {
				tagsint[6]=1;
				}
		else if (strcmp(f1.tags[i] , " Horror " ) == 0) {
				tagsint[7]=1;
				}
		else if (strcmp(f1.tags[i] , " Mystery " ) == 0) {
				tagsint[8]=1;
				}
		else if (strcmp(f1.tags[i] , " Crime " ) == 0) {
				tagsint[9]=1;
				}
		else if (strcmp(f1.tags[i] , " Adventure " ) == 0) {
				tagsint[10]=1;
				}
		else if (strcmp(f1.tags[i] , " Family " ) == 0) {
				tagsint[11]=1;
				}
		else if (strcmp(f1.tags[i] , " Drama " ) == 0) {
				tagsint[12]=1;
				}
		else if (strcmp(f1.tags[i] , " Music " ) == 0) {
				tagsint[13]=1;
				}
		else if (strcmp(f1.tags[i] , " Romance " ) == 0) {
				tagsint[14]=1;
				}
		else if (strcmp(f1.tags[i] , " History " ) == 0) {
				tagsint[15]=1;
				}
		else if (strcmp(f1.tags[i] , " Sport " ) == 0) {
				tagsint[16]=1;
				}
		else if (strcmp(f1.tags[i] , " War " ) == 0) {
				tagsint[17]=1;
				}
	}
	return tagsint;

}

int max(int x, int y, int z) {
	int max = x;
	{
      if (max< y){ max = y; }
      if (max<z){max = z;}
      return max;
    }
}

int min(int x, int y, int z) {
	int min = x;
	{
      if (min> y){ min = y; }
      if (min>z){min = z;}
      return min;
    }
}

int * favyear (Film f1 , Film f2 , Film f3) {
	int * annee = malloc(sizeof(int)*2);
	annee[0]=min(f1.annee,f2.annee,f3.annee)-4;
	annee[1]=max(f1.annee,f2.annee,f3.annee)+4;
	return annee;
}

int * favduration (Film f1 , Film f2 , Film f3) {
	int * duree = malloc(sizeof(int)*2);
	if (min(f1.duree,f2.duree,f3.duree) !=0)
	{
		duree[0]=min(f1.duree,f2.duree,f3.duree)-15;

	}
	else
	{
		duree[0]=max(f1.duree,f2.duree,f3.duree)-30;
	}
	duree[1]=max(f1.duree,f2.duree,f3.duree)+15;

	return duree;
}

int * favtags (Film f1 , Film f2 , Film f3) {
	// contient l'indice des tags préféré et compléter avec des 0
	int * favtags = malloc(sizeof(int)*18);
	int j =0 ;
	int i;
	for (int j = 0; j < 18; ++j)
	{
		favtags[j]=0;
	}
	j=0;
	for (int i = 0; i < 18; ++i)
	{
		if (((tagsbinaire(f1)[i]==tagsbinaire(f2)[i])&&(tagsbinaire(f1)[i]==1))
			||((tagsbinaire(f1)[i]==tagsbinaire(f3)[i])&&(tagsbinaire(f1)[i]==1))
			||((tagsbinaire(f2)[i]==tagsbinaire(f3)[i])&&(tagsbinaire(f2)[i]==1)))

		{
			//printf("%d , %d  %d  \n",tagsbinaire(f1)[i],tagsbinaire(f2)[i],tagsbinaire(f3)[i] );
			favtags[j]=i+1;
			j++;
		}
	}
	i=0;

	if (favtags[0]==0)
	{
		for (int i = 0; i < 18; ++i)
		{
			if (tagsbinaire(f1)[i]==1)
			{
				favtags[j]=i+1;
			}
		}
	}

	return favtags;
}

char * favrealisateur (Film f1 , Film f2 ,Film f3) {
	char * favrealisateur = (char*) malloc(sizeof(char)*100);
	if ((strcmp(f1.realisateur, f2.realisateur)==0)||(strcmp(f1.realisateur, f3.realisateur)==0))
	{
		favrealisateur = f1.realisateur;
	}
	else if (strcmp(f3.realisateur, f2.realisateur)==0)
	{
		favrealisateur = f2.realisateur;
	}

	return favrealisateur;

}


char * favacteur (Film f1, Film f2, Film f3) {
	char * favacteur = (char*) malloc(sizeof(char)*100); 
	int i;
	int j;
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (strcmp(f1.acteur[j],f2.acteur[i])==0)
			{
				favacteur = f1.acteur[j];
			}
		}
	}


	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (strcmp(f1.acteur[j],f3.acteur[i])==0)
			{
				favacteur = f1.acteur[j];
			}
		}
	}

	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (strcmp(f3.acteur[j],f2.acteur[i])==0)
			{
				favacteur = f3.acteur[j];
			}
		}
	}

	return favacteur;

}
float calculnoteObjet(Film f,Utilisateur u) {
	float *note;
	note = (float*) malloc(sizeof(float));
	*note = 0.0;
	int i;
	int j;

	//printf("id : %d\n", f.id);
	if ((f.annee>=favyear(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2])[0])
		&&(f.annee<=favyear(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2])[1]))
	{
		*note = *note + 1.5;
	}
	//printf(" note year : %f\n",note );

	if ((f.duree>=favduration(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2])[0])
		&&(f.duree<=favduration(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2])[1]))
	{
		*note = *note + 0.5;
	}
	//printf(" note year + duree : %f\n",note );


	if (strcmp(f.realisateur,favrealisateur(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2]))==0)
	{
		*note = *note + 1.5;
	}
	//printf(" note year + duree + rea: %f\n",note );


	for (int i = 0; i < 3; ++i)
	{
		if (strcmp(f.acteur[i],favacteur(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2]))==0)
		{
			*note = *note +2.0;
		}
	}

	//printf(" note year + duree + rea + acteur: %f\n",note );
	float noteaux = 0.0;

	for (int i = 0; i < 18; ++i)
	{
		if (tagsbinaire(f)[i]==1)
		{
			for (int j = 0;  j< 18; ++j)
			{
				if (favtags(u.likedmovies[0],u.likedmovies[1],u.likedmovies[2])[j]==i+1)
				{
					noteaux = noteaux + 3.5;	
				}
			}
		}
	}
	//printf("%d\n",f.id );
	float k1 = 0.0;
	for (int i = 0; i < 18; ++i)
	{
		if (tagsbinaire(f)[i]==1)
		{
			k1++;
		}
	}
	//printf("note aux : %f , k1 : %f\n",noteaux,k1 );

	noteaux = noteaux/k1;
	*note = *note + noteaux;


	//printf(" note year + duree + rea + acteur + tags: %f\n",*note );


	return *note;

}

hashmap_map * hashmap_note_objet(Utilisateur * u) {
	hashmap_map * m1 = cst_hashmap(99);
	for (int i = 1; i < 100; ++i)
	{
		if ((i!=(*u).likedmovies[0].id)&&(i!=(*u).likedmovies[1].id)&&(i!=(*u).likedmovies[2].id))
		{
		    Film * f4 = cst_film(i);
			hashmap_add(*m1,*cst_hashmapelement((*f4).id,calculnoteObjet(*f4,*u) ));
		}
	}
		
	trihashmapvalue(*m1);
	return m1;
}


/**int main(int argc, char const *argv[])
{
	Film * f1 = cst_film(11);
	Film * f2 = cst_film(6);
	Film * f3 = cst_film(7);
	Film tab[3];
	tab[0]=*f1;
	tab[1]=*f2;
	tab[2]=*f3;
	hashmap_map * m1 = cst_hashmap(99);


	Utilisateur * u1 =  cst_utilisateur(1,tab);
	int i = 0;
	for (int i = 1; i < 100; ++i)
	{
		if ((i!=(*u1).likedmovies[0].id)&&(i!=(*u1).likedmovies[1].id)&&(i!=(*u1).likedmovies[2].id))
		{
		Film * f4 = cst_film(i);
		hashmap_add(*m1,*cst_hashmapelement((*f4).id,calculnoteObjet(*f4,*u1) ));
		}
	}

	trihashmapvalue(*m1);
	hashmap_tostring(*m1);
	printf("%d\n", *(*m1).actual_size);

	

	free(f1);
	free(f2);
	free(f3);
	//free(f4);
	free(u1);
	free(m1);

	hashmap_map * m1 = cst_hashmap(99);
	hashmap_element * e1 = cst_hashmapelement(1,5.0);
	hashmap_element * e2 = cst_hashmapelement(2,2.0);
	hashmap_element * e3 = cst_hashmapelement(3,8.0);
	hashmap_element * e4 = cst_hashmapelement(4,6.0);
	hashmap_add(*m1, *e1);	
	hashmap_add(*m1, *e2);	
	hashmap_add(*m1, *e3);	
	hashmap_add(*m1, *e4);
	hashmap_tostring(*m1);

	trihashmapvalue(*m1);
	hashmap_tostring(*m1);



	return 0;
}*/
