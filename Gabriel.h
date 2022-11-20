#include <stdio.h>//
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include <math.h>

#ifndef ECE_CITY_1_B_GABRIEL_H
#define ECE_CITY_1_B_GABRIEL_H

enum {COMMUNISTE, CAPITALISTE};
enum {DEMARRAGE, CHOIXREGIME, CHOIXSAUVEGARDE};
enum {MENUPRINCIPAL, PARTIE};
enum {AUCUNE, ROUTE, HABITATION, CENTRALELEC, CHATEAUEAU, CASERNE, POKEDEFENSE};
enum {RUINES, TERRAINVAGUE, CABANE, MAISON, IMMEUBLE, GRATTECIEL};

typedef struct{

    float x;
    float y;
    int numligne;
    int numcolonne;
}Avantplan;

typedef struct{
    bool sapin;
    int niveaudebatiment;
    int numerobatiment;
    int typedeconstruction;
    bool hautgauche;
    int nombrehabitants;
    bool incendie;
} Cases;

void calculcaseselec(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey, float haut, bool* menujeu);
void affichage();


#endif //ECE_CITY_1_B_GABRIEL_H
