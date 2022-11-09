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

#ifndef ECE_CITY_1_B_ANAE_H
#define ECE_CITY_1_B_ANAE_H
typedef struct{
    int type;
    float x;
    float y;
    bool disponible;
    bool accessible;
    int numligne;
    int numcolonne;
    int casePresent;
    int sens;
    bool active;
    bool animationPv;
}Avantplan;

typedef struct{
    bool routepresente;
    bool batimentpresent;
    bool sapin;
    int niveaudebatiment;
    int numerobatiment;
    bool hautgauche;

} Cases;

void calculcaseselecAna(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey);




void testvoiture();


void amuse_toi();

#endif //ECE_CITY_1_B_ANAE_H
