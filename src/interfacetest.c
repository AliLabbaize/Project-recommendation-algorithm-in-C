#include <SDL/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include "fonction_transfers.h"
#include "fonction_calcul.h"
#include "interfacetest.h"


//Initialisation des attributs de l'écran
const int SCREEN_WIDTH = 1280; // Largeur de la fenêtre
const int SCREEN_HEIGHT = 720; // Hauteur de la fenêtre
const int SCREEN_BPP = 32; // Résolution (bits/pixels) -> couleurs de 32 bits

//Initialisation des surfaces utilisées 
SDL_Surface* chargement0 = NULL;
SDL_Surface* chargement1 = NULL;
SDL_Surface* chargement2 = NULL;
SDL_Surface* chargement3 = NULL;
SDL_Surface* chargement4 = NULL;
SDL_Surface* chargement5 = NULL;
SDL_Surface* proposition1 = NULL;
SDL_Surface* proposition2 = NULL;
SDL_Surface* choix = NULL;
SDL_Surface* ecran = NULL;
SDL_Surface* film1 = NULL;
SDL_Surface* film2 = NULL;
SDL_Surface* film3 = NULL;

//Initialisation des évènements
SDL_Event event;
SDL_Event event1;
SDL_Event event2;

//Initialisation des zones de texte
TTF_Font* policet = NULL;
TTF_Font* police = NULL;
TTF_Font* policeu = NULL;
TTF_Font* policete = NULL;

//Choix des 3 films préférés;
int p[3];
int yop[3];

//Chargement de l'image: fonction nécessaire pour ajuster la résolution
SDL_Surface* load_image(char* filename){
    //Surface tampon qui nous servira pour charger l'image
    SDL_Surface* loadedImage = NULL;
    
    //Image optimisée qu'on va utiliser 
    SDL_Surface* optimizedImage = NULL;
    
    //Chargement de l'image
    loadedImage = SDL_LoadBMP(filename);   
    
    //Si chargement ok
    if (loadedImage != NULL) {
        //Création de l'image optimisée
        optimizedImage = SDL_DisplayFormat(loadedImage);
        
        //Libération de l'espace loué à l'ancienne image
        SDL_FreeSurface(loadedImage);
    } else {
        printf("coucou");
    }
    
    //Retourne l'image optimisée
    return optimizedImage;
}

//Fonction pour bliter la surface
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
    SDL_Rect offset;
    
    offset.x = x;
    offset.y = y;
    
    //Blittage de surface
    SDL_BlitSurface(source,NULL,destination, &offset );
}

//Fonction pour gérer la position du curseur dans le choix des 9 films 
int choixdesfilms(int x, int y) {
    if (x>=105 && x<=229 && y>=165 && y<330) {
        return 1;
    }
    if (x>=308 && x<=432 && y>=165 && y<330) {
        return 2;
    }
    if (x>=505 && x<=629 && y>=165 && y<330) {
        return 3;
    }
    if (x>=105 && x<=229 && y>=346 && y<511) {
        return 4;
    }
    if (x>=308 && x<=432 && y>=346 && y<511) {
        return 5;
    }
    if (x>=505 && x<=629 && y>=346 && y<511) {
        return 6;
    }
    if (x>=105 && x<=229 && y>=529 && y<694) {
        return 7;
    }
    if (x>=308 && x<=432 && y>=529 && y<694) {
        return 8;
    }
    if (x>=505 && x<=629 && y>=529 && y<694) {
        return 9;
    }
    if (x>=1010 && x<=1280 && y>=640 && y<720) {
        return 10;
    } else {
        return 0;
    }
}

//Fonction de renvoi des 3 films préférés
int* selection(){
    return p;
}

void reaffiche(int d){
    SDL_Surface* sel = NULL;
    sel = SDL_CreateRGBSurface(SDL_HWSURFACE, 125, 165, 32, 0, 0, 0, 0);
    SDL_FillRect(sel, NULL, SDL_MapRGB(sel->format, 0, 0, 0)); 
    SDL_SetAlpha(sel, SDL_SRCALPHA, 128);
    
    for (int i=0; i<3; i++){
        if (yop[i] == (d*9)+1 ) {
            apply_surface(105,165,sel,ecran);
        }
        if (yop[i] == ( (d*9 )+2 ) ){
            apply_surface(308,165,sel,ecran);
        }
        if (yop[i] == ( (d*9 )+3 ) ){
            apply_surface(505, 165, sel,ecran);
        }
        if (yop[i] == ( (d*9 )+4 ) ){
            apply_surface(105, 346, sel, ecran);
        }
        if (yop[i] == ( (d*9 )+5 ) ) {
            apply_surface(308,346, sel, ecran);
        }
        if (yop[i] == ( (d*9 )+6 ) ){
            apply_surface(505, 346, sel, ecran);
        }
        if (yop[i] == ( (d*9 )+7 ) ){
            apply_surface(105, 529, sel, ecran);
        }
        if (yop[i] == ( (d*9 )+8 ) ){
            apply_surface(308, 529, sel, ecran);
        }
        if (yop[i] == ( (d*9 )+9 ) ){
            apply_surface(505,529,sel, ecran);
        }
        SDL_Flip(ecran);
    }
}

void affichage9(int x[], int i){
    SDL_Surface* film4 = NULL;
    SDL_Surface* film5 = NULL;
    SDL_Surface* film6 = NULL;
    SDL_Surface* film7 = NULL;
    SDL_Surface* film8 = NULL;
    SDL_Surface* film9 = NULL;
    SDL_Surface* film10 = NULL;
    SDL_Surface* film11 = NULL;
    SDL_Surface* film12 = NULL;
    
    //Tableau pour stocker les chaines de caractères des id des images
    char b[9][7];
    
    for(int j = i; j < i + 9; j++){
        char k[7];
        
        sprintf(k, "%d", x[j]);
        strcat(k, ".bmp");
        b[j-i][0] = k[0];
        b[j-i][1] = k[1];
        b[j-i][2] = k[2];
        b[j-i][3] = k[3];
        b[j-i][4] = k[4];
        b[j-i][5] = k[5];
        b[j-i][6] = k[6];  
                        
    }
    film4 = load_image(b[0]);
    film5 = load_image(b[1]);
    film6 = load_image(b[2]);
    film7 = load_image(b[3]);
    film8 = load_image(b[4]);
    film9 = load_image(b[5]);
    film10 = load_image(b[6]);
    film11 = load_image(b[7]);
    film12 = load_image(b[8]);
    
    film4 = rotozoomSurface(film4, 0., 0.206, 1);
    film5 = rotozoomSurface(film5, 0., 0.206, 1);;
    film6 = rotozoomSurface(film6, 0., 0.206, 1);;
    film7 = rotozoomSurface(film7, 0., 0.206, 1);;
    film8 = rotozoomSurface(film8, 0., 0.206, 1);;
    film9 = rotozoomSurface(film9, 0., 0.206, 1);;
    film10 = rotozoomSurface(film10, 0., 0.206, 1);;
    film11 = rotozoomSurface(film11, 0., 0.206, 1);;
    film12 = rotozoomSurface(film12, 0., 0.206, 1);;
    
    apply_surface(105,165, film4, ecran);
    apply_surface(308,165, film5, ecran);
    apply_surface(505,165, film6, ecran);
    apply_surface(105,346, film7, ecran);
    apply_surface(308,346, film8, ecran);
    apply_surface(505,346, film9, ecran);
    apply_surface(105,529, film10, ecran);
    apply_surface(308,529, film11, ecran);
    apply_surface(505,529, film12, ecran);    
}

int dansp(int pos, int e, int d){
    if ((e<4)){
        if (yop[0] == 0){
            return(0);
        } else if ((yop[1] == 0) && (yop[0] != (pos+d*9))){
            return(0);
        } else if ((yop[2] == 0) && (yop[0] != (pos+d*9)) && (yop[1] != (pos+d*9))){
            return(0);
        } else {
            return(1);
        }
    } else if (e>=4){
        if (yop[0] == (pos+d*9)){
            return(1);
        } else if (yop[1] == (pos+d*9)) {
            return(1);
        } else if (yop[2] == (pos+d*9)) {
            return(1);
        } else {
            return(2);
        }
    }
}

void elimine(int pos, int a){
    if (yop[0] == ((pos)+9*a) ){
        yop[0] = yop[1];
        yop[1] = yop[2];
        yop[2] = 0;
    }
    if (yop[1] == ((pos)+9*a)){
        yop[1] = yop[2];
        yop[2] = 0;
    }
    if (yop[2] == ((pos)+9*a)){
        yop[2] = 0;
    }
}


//Fonction qui gère la toute première selection de film
void selectiondeb(int cerie){
    //Initialisation des SDL_Surfaces
    SDL_Surface* bg = NULL;
    SDL_Surface* sel = NULL;
    SDL_Surface* background = NULL;
    
    SDL_Surface* continuers = NULL;
      
    //Position du curseur
    int positionsouris = 0;
    
    //Integer pour l'affichage des pages
    int continuer10 = 1;
    int continuer11 = 1;
    int continuer12 = 1;
    int continuer13 = 1;
  
    //Autres
    int etat = 1;
    int stop1 = 0;
      
    continuers = load_image("continuerouge.bmp");
    SDL_SetColorKey(continuers, SDL_SRCCOLORKEY, SDL_MapRGB(continuers->format, 80,62,62)); 
    
    //Event pour les pages
    SDL_Event event10;
    SDL_Event event11;
    SDL_Event event12;
    SDL_Event event13; 
    
    //Image pour les films sélectionés
    sel = SDL_CreateRGBSurface(SDL_HWSURFACE, 125, 165, 32, 0, 0, 0, 0);
    SDL_FillRect(sel, NULL, SDL_MapRGB(sel->format, 0, 0, 0)); 
    SDL_SetAlpha(sel, SDL_SRCALPHA, 128);
    
    //Variables nécessaires pour la liste des films
    int j = 0;
    int k = 0; 
    int listef[57];
    int listes[42];
    
    for (int i = 0; i<99; i++) {
        if (cerie == 1){
            if (strcmp(type("BDCSD.txt", i+1), "Tv Show")==0){
                listes[k] = i+1;
                k++;
            }
        }
        if (cerie == 2){
            if (strcmp(type("BDCSD.txt",i+1), "Movie")==0){    
                listef[j] = i+1;
                j++;
            }
        }
    }
    
    background = load_image("affiche9.bmp");
    apply_surface(0,0, background, ecran);
    SDL_Flip(ecran);
    if (cerie == 1){
        affichage9(listes,0);
    } 
    if (cerie == 2){
        affichage9(listef,0);
    }
    SDL_Flip(ecran);
    while(continuer10){
        SDL_WaitEvent(&event10);
        switch(event10.type){
            case SDL_MOUSEBUTTONUP:
                positionsouris = choixdesfilms(event10.motion.x, event10.motion.y);
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 1)) {
                    if (dansp(positionsouris,etat, 0)==0){
                        apply_surface(105,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }                        
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 2)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(308,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 3)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(505,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 4)) {
                    if (dansp(positionsouris, etat, 0)==0) {
                        apply_surface(105,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 5)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(308,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 6)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(505,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 7)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(105,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 8)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(308,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 9)) {
                    if (dansp(positionsouris, etat, 0)==0){
                        apply_surface(505,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris-1];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris-1];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,0)==1) {
                        elimine(positionsouris,0);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }                        
                }
                if ((event10.button.button == SDL_BUTTON_LEFT) && (positionsouris == 10)) {
                    continuer10 = 0;  
                } 
            case SDL_MOUSEMOTION:
                positionsouris = choixdesfilms(event10.motion.x, event10.motion.y);
                if (positionsouris == 10) {
                    if (stop1 == 0) {
                        reaffiche(0);
                    }
                    stop1 = 1;
                    apply_surface(1034, 645,continuers,ecran);
                    SDL_Flip(ecran);
                } else {
                    if (stop1 == 1) {
                        apply_surface(0,0,background, ecran);
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                        stop1 = 0;
                    }
                } 
                break;    
        }
    }
    SDL_FreeSurface(ecran);
    apply_surface(0,0,background, ecran);
    if (cerie == 1){
        affichage9(listes,9);
    } 
    if (cerie == 2){
        affichage9(listef,9);
    }
    SDL_Flip(ecran);
    stop1 = 0;
    while(continuer11){
        SDL_WaitEvent(&event11);
        switch(event11.type){
            case SDL_MOUSEBUTTONUP:
                positionsouris = choixdesfilms(event11.motion.x, event11.motion.y);
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 1)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(105,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }  
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 2)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(308,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }   
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 3)) {
                   if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(505,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }                  
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 4)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(105,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }   
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 5)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(308,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 6)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(505,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }                  
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 7)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(105,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }  
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 8)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(308,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                    }
                }
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 9)) {
                    if (dansp(positionsouris,etat, 1)==0){
                        apply_surface(505,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+9;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+8];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+8];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,1)==1) {
                        elimine(positionsouris,1);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,0);
                        } 
                        if (cerie == 2){
                            affichage9(listef,0);
                        }
                        reaffiche(0);
                        SDL_Flip(ecran);
                    }  
                }
                if ((event11.button.button == SDL_BUTTON_LEFT) && (positionsouris == 10)) {
                    continuer11 = 0;  
                }
            case SDL_MOUSEMOTION:
                positionsouris = choixdesfilms(event11.motion.x, event11.motion.y);
                if (positionsouris == 10) {
                    if (stop1 == 0){
                        reaffiche(1);
                    }
                    stop1=1;
                    apply_surface(1034, 645,continuers,ecran);
                    SDL_Flip(ecran);
                } else {
                    if (stop1 == 1) {
                        apply_surface(0,0,background, ecran);
                        if (cerie == 1){
                            affichage9(listes,9);
                        } 
                        if (cerie == 2){
                            affichage9(listef,9);
                        }
                        reaffiche(1);
                        SDL_Flip(ecran);
                        stop1 = 0;
                    }
                } 
                break;    
        }
    }
    SDL_FreeSurface(ecran);
    apply_surface(0,0,background, ecran);
    if (cerie == 1){
        affichage9(listes,18);
    } 
    if (cerie == 2){
        affichage9(listef,18);
    }
    SDL_Flip(ecran);
    stop1 = 0;
    while(continuer12){
        SDL_WaitEvent(&event12);
        switch(event12.type){
            case SDL_MOUSEBUTTONUP:
                positionsouris = choixdesfilms(event12.motion.x, event12.motion.y);
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 1)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(105,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        }  
                        etat = etat + 1;
                    }  else if (dansp(positionsouris, etat,2)==1) {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 2)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(308,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 3)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(505,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 4)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(105,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 5)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(308,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 6)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(505,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 7)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(105,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 8)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(308,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 9)) {
                    if (dansp(positionsouris,etat, 2)==0){
                        apply_surface(505,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+18;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+17];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+17];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,2)==1)  {
                        elimine(positionsouris,2);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                    }
                }
                if ((event12.button.button == SDL_BUTTON_LEFT) && (positionsouris == 10)) {
                    continuer12 = 0;  
                }
            case SDL_MOUSEMOTION:
                positionsouris = choixdesfilms(event12.motion.x, event12.motion.y);
                if (positionsouris == 10) {
                    if (stop1 == 0) {
                        reaffiche(2);
                    }
                    stop1 = 1;
                    apply_surface(1034, 645,continuers,ecran);
                    SDL_Flip(ecran);
                } else {
                    if (stop1 == 1) {
                        apply_surface(0,0,background, ecran);
                        if (cerie == 1){
                            affichage9(listes,18);
                        } 
                        if (cerie == 2){
                            affichage9(listef,18);
                        }
                        reaffiche(2);
                        SDL_Flip(ecran);
                        stop1 = 0;
                    }
                } 
                break;      
        }
    }
    SDL_FreeSurface(ecran);
    apply_surface(0,0,background, ecran);
    if (cerie == 1){
        affichage9(listes,27);
    } 
    if (cerie == 2){
        affichage9(listef,27);
    }
    SDL_Flip(ecran);
    stop1 = 0;
    while(continuer13){
        SDL_WaitEvent(&event13);
        switch(event13.type){
            case SDL_MOUSEBUTTONUP:
                positionsouris = choixdesfilms(event13.motion.x, event13.motion.y);
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 1)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(105,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        } 
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1)  {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 2)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(308,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 3)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(505,165, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 4)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(105,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 5)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(308,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 6)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(505,346, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 7)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(105,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 8)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(308,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 9)) {
                    if (dansp(positionsouris,etat, 3)==0){
                        apply_surface(505,529, sel, ecran);
                        SDL_Flip(ecran);
                        yop[etat -1] = positionsouris+27;
                        if (cerie == 1){
                            p[etat-1]=listes[positionsouris+26];
                        } 
                        if (cerie == 2){
                            p[etat-1]=listef[positionsouris+26];
                        }
                        etat = etat + 1;
                    } else if (dansp(positionsouris, etat,3)==1) {
                        elimine(positionsouris,3);
                        etat = etat -1;
                        background = load_image("affiche9.bmp");
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                    }
                }
                if ((event13.button.button == SDL_BUTTON_LEFT) && (positionsouris == 10)) {
                    continuer13 = 0;  
                }
            case SDL_MOUSEMOTION:
                positionsouris = choixdesfilms(event13.motion.x, event13.motion.y);
                if (positionsouris == 10) {
                    if (stop1 == 0){
                        reaffiche(3);
                    }
                    stop1 = 1;
                    apply_surface(1034, 645,continuers,ecran);
                    SDL_Flip(ecran);
                } else {
                    if (stop1 == 1) {
                        apply_surface(0,0,background, ecran);
                        if (cerie == 1){
                            affichage9(listes,27);
                        } 
                        if (cerie == 2){
                            affichage9(listef,27);
                        }
                        reaffiche(3);
                        SDL_Flip(ecran);
                        stop1 = 0;
                    } 
                } 
                break;      
        }
    }
    printf("%d/", p[0]);
    printf("%d/", p[1]);
    printf("%d/", p[2]);
    printf("\n");
    printf("!!!! CHOIX  !!!!\n" );
    for (int i = 0; i < 3; ++i)
    {

    
        printf(" id : %d || titre : %s  || type :  %s|| année : %d || durée : %d  mins || réalisateur : %s  \n ",
        p[i],title("BDCSD.txt",p[i]),type("BDCSD.txt",p[i]),
        year("BDCSD.txt",p[i]),duration("BDCSD.txt",p[i]),director("BDCSD.txt",p[i]));
        printf("tags :" );
        for (int j= 0; j < 6; ++j)
        {
            printf("%s ; ",tags("BDCSD.txt",p[i])[j] );
        }
        printf("|| acteurs : ");
        for (int k = 0; k < 3; ++k)
        {
            printf("%s,\n",actors("BDCSD.txt",p[i])[k] );
        }
        printf("\n");

    }

    printf("!!!RESULTS!!!\n");

    SDL_FreeSurface(bg);
    SDL_FreeSurface(background);   
    SDL_FreeSurface(ecran); 
}

//Fonction qui gère la page de présentation d'un film
void filmchoisi(SDL_Surface* film1, SDL_Surface* background, SDL_Surface* film2, SDL_Surface* film3, SDL_Surface* ecran, int id){
    SDL_Surface* film4 = NULL;
    SDL_Surface* bs = NULL;
    SDL_Surface* bs1 = NULL;
    SDL_Surface* titre = NULL;
    SDL_Surface* annee = NULL;
    SDL_Surface* annee1 = NULL;
    SDL_Surface* acteurs = NULL;
    SDL_Surface* acteurs1 = NULL;
    SDL_Surface* acteurs2 = NULL;
    SDL_Surface* acteurs3 = NULL;
    SDL_Surface* rea = NULL;
    SDL_Surface* rea1 = NULL;
    SDL_Surface* genre = NULL;
    SDL_Surface* genre1 = NULL;
    SDL_Surface* genre2 = NULL;
    SDL_Surface* genre3 = NULL;
    SDL_Surface* duree = NULL;
    SDL_Surface* duree1 = NULL;
    SDL_Surface* duree2 = NULL;
    SDL_Surface* croixb = NULL;
    SDL_Surface* croixr = NULL;
    SDL_Rect positiont; //Position titre
    SDL_Rect positiona; //Position année
    SDL_Rect positiona1;
    SDL_Rect positionr; //Position réalisateur
    SDL_Rect positionac; //Position acteurs
    SDL_Rect positionac1;
    SDL_Rect positionac2; 
    SDL_Rect positionac3;
    SDL_Rect positionr1;
    SDL_Rect positionre; //Position résumé
    SDL_Rect positiong;
    SDL_Rect positiong1;
    SDL_Rect positiong2;
    SDL_Rect positiong3;
    SDL_Rect positiond0;
    SDL_Rect positiond1;
    SDL_Rect positiond2;
    
    SDL_FreeSurface(ecran);
    char w[6];
    char z[4];
    char k[7];
    
    sprintf(k, "%d",id);
    strcat(k, ".bmp"); 
    sprintf(w, "%d", year("BDCSD.txt", id));
    sprintf(z, "%d", duration("BDCSD.txt", id)); 
    
    film4= load_image(k);
    croixb = load_image("Croix.bmp");
    croixr = load_image("Croixr.bmp");
    croixb = rotozoomSurface(croixb, 0., 0.031, 1);
    croixr = rotozoomSurface(croixr, 0., 0.031, 1);    
     
    //Changer la police
    policet = TTF_OpenFont("lottepaperfang.ttf", 28);
    SDL_Color blanc = {255, 255, 255};
    TTF_SetFontStyle(policet, TTF_STYLE_BOLD);
    
    police = TTF_OpenFont("Rounded_Elegance.ttf", 20);
    
    policeu = TTF_OpenFont("Rounded_Elegance.ttf", 20);
    TTF_SetFontStyle(policeu, TTF_STYLE_UNDERLINE);
        
    //Integer pour savoir quand revenir à la page de début
    int suite = 1;
    int stop8 = 1;
    
    //Coloration de la surface bs + Transparence
    bs = SDL_CreateRGBSurface(SDL_HWSURFACE, 1280, 720, 32, 0, 0, 0, 0);
    bs1 = SDL_CreateRGBSurface(SDL_HWSURFACE, 1280, 720, 32, 0, 0, 0, 0);
    SDL_SetAlpha(bs, SDL_SRCALPHA, 90);
    
    //Zoom de l'image + Choix du texte en fonction du film choisi
    film4 = rotozoomSurface(film4, 0., 0.9, 1);
    SDL_SetAlpha(bs, SDL_SRCALPHA, 190);
    titre = TTF_RenderText_Blended(policet, title("BDCSD.txt",id), blanc);
    annee = TTF_RenderText_Blended(policeu, "Annee :", blanc);
    annee1 = TTF_RenderText_Blended(police, w, blanc);
    rea = TTF_RenderText_Blended(policeu, "Realisateur :", blanc);
    rea1 = TTF_RenderText_Blended(police, director("BDCSD.txt",id), blanc);
    acteurs = TTF_RenderText_Blended(policeu, "Acteur(s) :", blanc);
    acteurs1 = TTF_RenderText_Blended(police, strcat(actors("BDCSD.txt", id)[0], ","), blanc);
    acteurs2 = TTF_RenderText_Blended(police, strcat(actors("BDCSD.txt", id)[1], ","), blanc);
    acteurs3 = TTF_RenderText_Blended(police, actors("BDCSD.txt", id)[2], blanc);
    genre = TTF_RenderText_Blended(policeu, "Genre :", blanc);
    genre1 = TTF_RenderText_Blended(police, strcat(tags("BDCSD.txt", id)[0], ","), blanc);
    genre2 = TTF_RenderText_Blended(police, strcat(tags("BDCSD.txt", id)[1], ","), blanc);
    genre3 = TTF_RenderText_Blended(police, tags("BDCSD.txt", id)[2], blanc);
    duree = TTF_RenderText_Blended(policeu, "Duree :", blanc);
    duree1 = TTF_RenderText_Blended(police, z, blanc);
    duree2 = TTF_RenderText_Blended(police, "mins", blanc);
    
    positiont.x = 650;
    positiona.x = 650;
    positiona1.x = positiona.x + 5 + annee->w;
    positionr.x = 650;
    positionr1.x = positionr.x + 5 + rea->w;
    positionre.x = 710;
    positionac.x = 650;
    positionac1.x = positionac.x + 5 + acteurs->w;
    positionac2.x = positionac1.x + 5 + acteurs1->w ;
    positionac3.x = positionac2.x + 5 + acteurs2->w ;
    positiong.x = 650;
    positiong1.x = positiong.x + 5 + genre->w;
    positiong2.x = positiong1.x + 5 + genre1->w;
    positiong3.x = positiong2.x + 5 + genre2->w;
    positiond0.x = 650;
    positiond1.x = positiond0.x + 5 + duree->w;
    positiond2.x = positiond1.x + 5 + duree1->w;
    positiont.y = 120;
    positiona.y = 220;
    positiona1.y = positiona.y;
    positionr.y = 260;
    positionr1.y = positionr.y;  
    positionre.y = 0;
    positionac.y = 300;
    positionac1.y = positionac.y;
    positionac2.y = positionac.y;
    positionac3.y = positionac.y;
    positiong.y = 340;
    positiong1.y = positiong.y;
    positiong2.y = positiong.y;
    positiong3.y = positiong.y;
    positiond0.y = 380;
    positiond1.y = positiond0.y;
    positiond2.y = positiond0.y;
    
    //Appliquer les éléments de la page
    apply_surface(0,0, bs1, ecran);
    apply_surface(0,0, film4, ecran);
    apply_surface(0,0, bs, ecran);
    SDL_BlitSurface(titre, NULL, ecran, &positiont);
    SDL_BlitSurface(annee, NULL, ecran, &positiona);
    SDL_BlitSurface(annee1, NULL, ecran, &positiona1);
    SDL_BlitSurface(rea, NULL, ecran, &positionr);
    SDL_BlitSurface(rea1, NULL, ecran, &positionr1);
    SDL_BlitSurface(acteurs, NULL, ecran, &positionac);
    SDL_BlitSurface(acteurs1, NULL, ecran, &positionac1);
    SDL_BlitSurface(acteurs2, NULL, ecran, &positionac2);
    SDL_BlitSurface(acteurs3, NULL, ecran, &positionac3);
    SDL_BlitSurface(genre, NULL, ecran, &positiong);
    SDL_BlitSurface(genre1, NULL, ecran, &positiong1);
    SDL_BlitSurface(genre2, NULL, ecran, &positiong2);
    SDL_BlitSurface(genre3, NULL, ecran, &positiong3);
    SDL_BlitSurface(duree, NULL, ecran, &positiond0);
    SDL_BlitSurface(duree1, NULL, ecran, &positiond1);
    SDL_BlitSurface(duree2, NULL, ecran, &positiond2);
    apply_surface(1230,2, croixb, ecran);    
    SDL_Flip(ecran);
    
    while(suite){
        SDL_WaitEvent(&event2);
        switch(event2.type){
            case SDL_MOUSEMOTION:
                if ((event2.motion.x>=1230) && (event2.motion.x<1280) && (event2.motion.y>=0) && (event2.motion.y<43) && (stop8 == 1)) {
                    apply_surface(1230, 2, croixr, ecran);
                    SDL_Flip(ecran);
                    stop8 = 0;
                } else {
                    if (stop8 == 0){
                        apply_surface(0,0, bs1, ecran);
                        apply_surface(0,0, film4, ecran);
                        apply_surface(0,0, bs, ecran);
                        SDL_BlitSurface(titre, NULL, ecran, &positiont);
                        SDL_BlitSurface(annee, NULL, ecran, &positiona);
                        SDL_BlitSurface(annee1, NULL, ecran, &positiona1);
                        SDL_BlitSurface(rea, NULL, ecran, &positionr);
                        SDL_BlitSurface(rea1, NULL, ecran, &positionr1);
                        SDL_BlitSurface(acteurs, NULL, ecran, &positionac);
                        SDL_BlitSurface(acteurs1, NULL, ecran, &positionac1);
                        SDL_BlitSurface(acteurs2, NULL, ecran, &positionac2);
                        SDL_BlitSurface(acteurs3, NULL, ecran, &positionac3);
                        SDL_BlitSurface(genre, NULL, ecran, &positiong);
                        SDL_BlitSurface(genre1, NULL, ecran, &positiong1);
                        SDL_BlitSurface(genre2, NULL, ecran, &positiong2);
                        SDL_BlitSurface(genre3, NULL, ecran, &positiong3);
                        SDL_BlitSurface(duree, NULL, ecran, &positiond0);
                        SDL_BlitSurface(duree1, NULL, ecran, &positiond1);
                        SDL_BlitSurface(duree2, NULL, ecran, &positiond2);
                        apply_surface(1230,2, croixb, ecran);    
                        SDL_Flip(ecran);
                        stop8 = 1;
                        }
                    }
            case SDL_MOUSEBUTTONUP:
                if ((event2.button.button == SDL_BUTTON_LEFT) && (event2.motion.x>=1230) && (event2.motion.x<1280) && (event2.motion.y>=0) && (event2.motion.y<43) && (stop8 = 1)) {
                    suite = 0;
                }
        }
    }
    TTF_CloseFont(policeu);
    TTF_CloseFont(police);
    TTF_CloseFont(policet);
    SDL_FreeSurface(bs1);
    SDL_FreeSurface(bs);
    apply_surface(0,0,background, ecran);
    apply_surface(106,280, film1, ecran);
    apply_surface(523,280, film2, ecran);
    apply_surface(935,280, film3, ecran);
}
    
//Fonction pour gérer la position du curseur dans le choix des 3 films proposés
int filmselection(int x, int y) {
    if (x>=106 && x<=356 && y>=280 && y<614) {
        return 1;
    }
    if (x>=523 && x<=773 && y>=280 && y<614) {
        return 2;
    }
    if (x>=935 && x<=1185 && y>=280 && y<614) {
        return 3;
    }
    if (x>=563 && x<=761 && y>=652 && y<689){
        return 4;
    } else {
        return 0;
    }
}


int main(int argc,char* args[]){
    SDL_Surface* film4 = NULL;
    SDL_Surface* film5 = NULL;
    SDL_Surface* film6 = NULL;
    SDL_Surface* blanche = NULL;
    SDL_Surface* titre1 = NULL;
    SDL_Surface* titre2 = NULL;
    SDL_Surface* titre3 = NULL;
    SDL_Surface* aucun = NULL;
    SDL_Surface* logo = NULL;
    SDL_Surface* carre = NULL;
    
    //Position des titres
    SDL_Rect positionti1; 
    SDL_Rect positionti2; 
    SDL_Rect positionti3;
    
    //Fichier pour garder tous les informations de l'identifiant
    FILE *file;
    
    //Integer pour la position du curseur
    int curseur = 0;
    
    //Integer pour gérer la fermeture de l'app
    int continuer = 1;
    int continuer0 = 1;
    int jk=0;
    
    //Integer série ou film
    int c;
    
    //Variable pour garder le film choisi
  /*  int filmchoisis[3] = {1, 12, 32};
    Film likedmovies[3];
    likedmovies[0] = *cst_film(p[0]);
    likedmovies[1] = *cst_film(p[1]);
    likedmovies[2] = *cst_film(p[2]);*/
   
    //Autres
    int ppp[3];
    int stop = 0;
    int stop2 = 0;

    //Initialisation de tous les sous-systèmes de SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        printf("cc");
        return EXIT_FAILURE;
    }
    if(TTF_Init() == -1){
        printf("cucu");
        return EXIT_FAILURE;
    }


    //Mise en place de l'écran (Doublebuf est pour éviter le scintillement de l'écran lors de la superposition d'image)
    ecran = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    //Gestion d'une erreur dans la création de l'écran
    if (ecran == NULL) {
        return EXIT_FAILURE;
    }   
    
    //Mise de l'icone de l'application
    logo = load_image("miniLogo.bmp");
    //Rendre une couleur transparente
    SDL_SetColorKey(logo, SDL_SRCCOLORKEY, SDL_MapRGB(logo->format, 255,255,255));
    SDL_WM_SetIcon(logo,NULL);
    
    //Mise de la barre pour faire propre
    SDL_WM_SetCaption("Dasilflix", NULL);
    
    //Surface blanche
    blanche = SDL_CreateRGBSurface(SDL_HWSURFACE, 251, 334, 32, 0, 0, 0, 0);
    SDL_FillRect(blanche, NULL, SDL_MapRGB(blanche->format, 255, 255, 255)); 
    SDL_SetAlpha(blanche, SDL_SRCALPHA, 128);

    carre= load_image("Cadre.bmp");
    aucun= load_image("aucun.bmp");
    chargement0= load_image("Chargement0.bmp");
    chargement1= load_image("Chargement1.bmp");
    chargement2= load_image("Chargement2.bmp");
    chargement3= load_image("Chargement3.bmp");
    chargement4= load_image("Chargement4.bmp");
    chargement5= load_image("Chargement5.bmp");
    choix= load_image("Choix.bmp");


    //Rendre une couleur transparente
    SDL_SetColorKey(aucun, SDL_SRCCOLORKEY, SDL_MapRGB(aucun->format, 80,62,62));
    SDL_SetColorKey(carre, SDL_SRCCOLORKEY, SDL_MapRGB(carre->format, 255,255,255)); 

    //Ecran de chargement
    apply_surface(0,0, chargement0,ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
    apply_surface(0,0, chargement1, ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
    apply_surface(0,0, chargement2, ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
    apply_surface(0,0, chargement3, ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
    apply_surface(0,0, chargement4, ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
    apply_surface(0,0, chargement5, ecran);
    SDL_Flip(ecran);
    SDL_Delay(400);
    SDL_FreeSurface(ecran);
   
    apply_surface(0,0, choix, ecran);
    SDL_Flip(ecran);
    
    //Ecran du choix série/film
    while(continuer0){
        //On attend qu'on récupère un event
        SDL_WaitEvent(&event1);
        switch(event1.type){
            //Si on appuie sur la croix pour quitter
            case SDL_QUIT:
                continuer0 = 0;
                continuer = 0;
                break;  
            case SDL_MOUSEBUTTONUP:
                //Appliquer l'image sur le fond
                if ((event1.button.button == SDL_BUTTON_LEFT) && (event1.motion.x >= 336) && (event1.motion.x < 503) && (event1.motion.y >= 344) && (event1.motion.y < 575)) {
                    proposition1= load_image("Proposition1.bmp");
                    continuer0 = 0;
                    c = 2;
                }
                if ((event1.button.button == SDL_BUTTON_LEFT) && (event1.motion.x >= 783) && (event1.motion.x < 950) && (event1.motion.y >= 344) && (event1.motion.y < 575)) {
                    proposition1= load_image("Proposition2.bmp");
                    continuer0 = 0;
                    c = 1;
                }
            case SDL_MOUSEMOTION:
                if ((event1.motion.x >= 336) && (event1.motion.x < 503) && (event1.motion.y >= 344) && (event1.motion.y < 575)) {
                    if (stop2 == 0){
                        apply_surface(336, 344, carre, ecran);
                        stop2 = 1;
                        SDL_Flip(ecran);
                    }
                }
                else if ((event1.motion.x >= 783) && (event1.motion.x < 950) && (event1.motion.y >= 344) && (event1.motion.y < 575)) {
                    if (stop2 == 0){
                        apply_surface(783, 344, carre, ecran);
                        stop2 = 1;
                        SDL_Flip(ecran);
                    }
                } else {
                    if (stop2 == 1){
                        apply_surface(0,0, choix, ecran);
                        stop2 = 0;
                        SDL_Flip(ecran);
                    }
                }
            }
    }
    SDL_FreeSurface(ecran);
    
    if ((c == 1) || (c==2)){
        selectiondeb(c);
    }

    Utilisateur * u1 = cst_utilisateur(1);
    hashmap_map* filmchoisiss = cst_hashmap(99);
    for (int i = 1; i < 100; ++i)
    {
        if ((i!=(*u1).likedmovies[0].id)&&(i!=(*u1).likedmovies[1].id)&&(i!=(*u1).likedmovies[2].id))
        {
        Film * f4 = cst_film(i);
        hashmap_add(*filmchoisiss,*cst_hashmapelement((*f4).id,calculnoteObjet(*f4,*u1) ));
        }
    } 
    //tri ton hashmap
    trihashmapvalue(*filmchoisiss);
    //affiche ton hashmap
    hashmap_tostring(*filmchoisiss);

    //Changement de l'id en cha
    int ik = 0;
    while(ik <3){
        if ((c == 1) && (jk < 99)){
            if ((strcmp(type("BDCSD.txt", (*filmchoisiss).data[jk].key), "Tv Show")==0) && (p[0]!=(*filmchoisiss).data[jk].key) && (p[1]!=(*filmchoisiss).data[jk].key) && (p[2]!=(*filmchoisiss).data[jk].key)){
                ppp[ik] = (*filmchoisiss).data[jk].key;
                ik = ik + 1;
                jk = jk + 1;
            } else if (jk < 99){
                jk = jk + 1;
            }
        }
        if ((c == 2) && (jk < 99)){
            if ((strcmp(type("BDCSD.txt", (*filmchoisiss).data[jk].key), "Movie")==0) && (p[0]!=(*filmchoisiss).data[jk].key) && (p[1]!=(*filmchoisiss).data[jk].key) && (p[2]!=(*filmchoisiss).data[jk].key)){
                ppp[ik] = (*filmchoisiss).data[jk].key;
                ik = ik + 1;
                jk = jk + 1;
            } else if (jk < 99){
                jk = jk + 1;
            } 
        }
    }
    
    char b[7];
    char b1[7];
    char b2[7];
    sprintf(b, "%d", ppp[0]);
    sprintf(b1, "%d", ppp[1]);
    sprintf(b2, "%d", ppp[2]);
    strcat(b, ".bmp");
    strcat(b1, ".bmp");
    strcat(b2, ".bmp");

    //Chargement de toutes les images
    film1= load_image(b);
    film2= load_image(b1);
    film3= load_image(b2);

    //Test de l'ouverture pour savoir si c'est la première ouverture de l'app
    /*if ((file = fopen("info.txt", "r")))
    {
        fclose(file);
        file = fopen("info.txt", "w");
    } else {
        //Création du fichier
        file = fopen("info.txt", "w");
        selectiondeb(c);
    }*/
    
    //Texte pour le passage de la souris
    policete = TTF_OpenFont("Rounded_Elegance.ttf", 18);
    SDL_Color noir = {0, 0, 0};
    TTF_SetFontStyle(policete, TTF_STYLE_BOLD);
    titre1 = TTF_RenderText_Blended(policete, title("BDCSD.txt",ppp[0]), noir);
    titre2 = TTF_RenderText_Blended(policete, title("BDCSD.txt",ppp[1]), noir);
    titre3 = TTF_RenderText_Blended(policete, title("BDCSD.txt",ppp[2]), noir);
    
    //Redimensionnement de l'image
    film4 = rotozoomSurface(film1, 0., 0.4175, 1);
    film5 = rotozoomSurface(film2, 0., 0.4175, 1);
    film6 = rotozoomSurface(film3, 0., 0.4175, 1);
    
    //Positon des titres quand on passe la souris dessus
    positionti1.x = ((film4->w/2) - (titre1->w/2) + 106);
    positionti1.y = 400;
    positionti2.x = ((film5->w/2) - (titre2->w/2) + 523);
    positionti2.y = 400;
    positionti3.x = ((film6->w/2) - (titre3->w/2) + 935);
    positionti3.y = 400;
      
    //Appliquer les films
    apply_surface(0,0,proposition1, ecran);
    apply_surface(106,280, film4, ecran);
    apply_surface(523,280, film5, ecran);
    apply_surface(935,280, film6, ecran);
    
    SDL_Flip(ecran);
    
    while(continuer) {
        //On attend qu'on récupère un event
        SDL_WaitEvent(&event);
        switch(event.type){
            //Si on appuie sur la croix pour quitter
            case SDL_QUIT:
                continuer = 0;
                break;
            //Si la souris bouge 
            case SDL_MOUSEMOTION:
                //Si la souris se situe sur le premier film
                curseur = filmselection(event.motion.x, event.motion.y);
                if (curseur == 0){
                    stop = 0;
                    SDL_FreeSurface(ecran);
                    apply_surface(0,0,proposition1, ecran);
                    apply_surface(106,280, film4, ecran);
                    apply_surface(523,280, film5, ecran);
                    apply_surface(935,280, film6, ecran);
                }  
                if (curseur == 1) {
                    if (stop == 0){
                        apply_surface(106,280,blanche, ecran);
                        SDL_BlitSurface(titre1, NULL, ecran, &positionti1);
                        stop = 1;
                    }
                }
                if (curseur == 2) {
                    if (stop == 0){
                        apply_surface(523,280,blanche, ecran);
                        SDL_BlitSurface(titre2, NULL, ecran, &positionti2);
                        stop = 1;
                    }
                }
                if (curseur == 3) {
                    if (stop == 0){
                        apply_surface(935,280,blanche, ecran);
                        SDL_BlitSurface(titre3, NULL, ecran, &positionti3);
                        stop = 1;
                    }
                }
                if (curseur == 4){
                    if (stop == 0){
                        apply_surface(568,653,aucun,ecran);
                        stop = 1;
                    }
                }
                SDL_Flip(ecran);
                break;
            //Si on clique avec la souris
            case SDL_MOUSEBUTTONUP:
                //Si on clique droit avec la souris
                curseur = filmselection(event.motion.x, event.motion.y);
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 1)) {
                    filmchoisi(film4, proposition1, film5, film6, ecran, ppp[0]);
                }
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 2)) {
                    filmchoisi(film4, proposition1, film5, film6, ecran, ppp[1]);
                }
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 3)) {
                    filmchoisi(film4, proposition1, film5, film6, ecran, ppp[2]);
                }
                if ((event.button.button == SDL_BUTTON_LEFT) && (curseur == 4)) {
                    int ik = 0;
                    while(ik <3){
                        if ((c == 1) && (jk < 99)){
                            if ((strcmp(type("BDCSD.txt", (*filmchoisiss).data[jk].key), "Tv Show")==0) && (p[0]!=(*filmchoisiss).data[jk].key) && (p[1]!=(*filmchoisiss).data[jk].key) && (p[2]!=(*filmchoisiss).data[jk].key)){
                                ppp[ik] = (*filmchoisiss).data[jk].key;
                                ik = ik + 1;
                                jk = jk + 1;
                            } else if (jk < 99){
                                jk = jk + 1;
                            } else {
                                continuer = 0;
                            }
                        }
                        if ((c == 2) && (jk < 99)){
                            if ((strcmp(type("BDCSD.txt", (*filmchoisiss).data[jk].key), "Movie")==0) && (p[0]!=(*filmchoisiss).data[jk].key) && (p[1]!=(*filmchoisiss).data[jk].key) && (p[2]!=(*filmchoisiss).data[jk].key)){
                                ppp[ik] = (*filmchoisiss).data[jk].key;
                                ik = ik + 1;
                                jk = jk + 1;
                            } else if (jk < 99){
                                jk = jk + 1;
                            } else { 
                                continuer = 0;
                            }
                        }
                    }
                    char b3[7];
                    char b4[7];
                    char b5[7];
                    sprintf(b3, "%d", ppp[0]);
                    sprintf(b4, "%d", ppp[1]);
                    sprintf(b5, "%d", ppp[2]);
                    strcat(b3, ".bmp");
                    strcat(b4, ".bmp");
                    strcat(b5, ".bmp");
                
                    SDL_FreeSurface(ecran);
                    film1= load_image(b3);
                    film2= load_image(b4);
                    film3= load_image(b5);
                    film4 = rotozoomSurface(film1, 0., 0.4175, 1);
                    film5 = rotozoomSurface(film2, 0., 0.4175, 1);
                    film6 = rotozoomSurface(film3, 0., 0.4175, 1);
                    titre1 = TTF_RenderText_Blended(policete, title("BDCSD.txt", ppp[0]), noir);
                    titre2 = TTF_RenderText_Blended(policete, title("BDCSD.txt", ppp[1]), noir);
                    titre3 = TTF_RenderText_Blended(policete, title("BDCSD.txt", ppp[2]), noir);
                    
                    positionti1.x = ((film4->w/2) - (titre1->w/2) + 106);
                    positionti1.y = 400;
                    positionti2.x = ((film5->w/2) - (titre2->w/2) + 523);
                    positionti2.y = 400;
                    positionti3.x = ((film6->w/2) - (titre3->w/2) + 935);
                    positionti3.y = 400;
   
                    apply_surface(0,0,proposition1, ecran);
                    apply_surface(106,280, film4, ecran);
                    apply_surface(523,280, film5, ecran);
                    apply_surface(935,280, film6, ecran);
                    SDL_Flip(ecran);
                }
                SDL_Flip(ecran);
                break;  
        }
    }


    //Fermeture du fichier
    //fclose(file);
    
    free(filmchoisiss);
    
    //Quitter TTF (police)
    TTF_Quit();       
    
    //Libération des images
    SDL_FreeSurface(ecran);
    
    //Quitter SDL
    SDL_Quit();

}

