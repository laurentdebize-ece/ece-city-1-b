//
// Created by gabdu on 02/11/2022.
//

#include "Gabriel.h"
#define XPRIMAIRE -2250
#define YPRIMAIRE -1750
#define CASE 100

void affichagetest(){

    //***************DEMARRAGE ALLEGRO*****************


    assert(al_init());
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_acodec_addon();
    srand(time(NULL));

    //***************INITIALISATION DES VARIABLES*****************


    ALLEGRO_DISPLAY *display = NULL;
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(1535, 864);
    assert(display != NULL);
    al_set_window_title(display, "Jeu");
    al_set_window_position(display, 0, 0);
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();


    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    assert(queue != NULL);

    ALLEGRO_MOUSE_STATE mouse_state;
    assert(al_install_mouse());

    ALLEGRO_FONT *Chiffre50 = al_load_ttf_font("../Fonts/Koulen-Regular.ttf", 50, 0);
    assert(Chiffre50);
    ALLEGRO_FONT *Chiffre35 = al_load_ttf_font("../Fonts/Koulen-Regular.ttf", 35, 0);
    assert(Chiffre35);
    ALLEGRO_FONT *Chiffre20 = al_load_ttf_font("../Fonts/Koulen-Regular.ttf", 20, 0);
    assert(Chiffre20);

    ALLEGRO_TIMER* timer= al_create_timer(0.01);

    ALLEGRO_KEYBOARD_STATE keyboard_state;

    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    float larg = (float)al_get_display_width(display);
    float haut = (float)al_get_display_height(display);

    al_draw_text(Chiffre35, al_map_rgb(255,255,255), larg/2-50, haut/2-100, 0, "Loading...");
    al_flip_display();


    //***************CHARGEMENT DES IMAGES NECESSAIRES ET DES SONS*****

    ALLEGRO_BITMAP* Route[17]={
            {al_load_bitmap("../Route/Herbe.PNG")},
            {al_load_bitmap("../Route/RouteRien.PNG")},
            {al_load_bitmap("../Route/RouteHaut.PNG")},
            {al_load_bitmap("../Route/RouteBas.PNG")},
            {al_load_bitmap("../Route/RouteGauche.PNG")},
            {al_load_bitmap("../Route/RouteDroite.PNG")},
            {al_load_bitmap("../Route/RouteHautBas.PNG")},
            {al_load_bitmap("../Route/RouteHautGauche.PNG")},
            {al_load_bitmap("../Route/RouteHautDroite.PNG")},
            {al_load_bitmap("../Route/RouteBasGauche.PNG")},
            {al_load_bitmap("../Route/RouteBasDroite.PNG")},
            {al_load_bitmap("../Route/RouteGaucheDroite.PNG")},
            {al_load_bitmap("../Route/RouteHautBasGauche.PNG")},
            {al_load_bitmap("../Route/RouteHautBasDroite.PNG")},
            {al_load_bitmap("../Route/RouteHautGaucheDroite.PNG")},
            {al_load_bitmap("../Route/RouteBasGaucheDroite.PNG")},
            {al_load_bitmap("../Route/RouteHautBasGaucheDroite.PNG")},


    };

    ALLEGRO_BITMAP* Bordure=al_load_bitmap("../Route/Bordure.PNG");
    ALLEGRO_BITMAP* Sapin=al_load_bitmap("../Route/Sapin.PNG");
    ALLEGRO_BITMAP* Arbre=al_load_bitmap("../Route/Arbre.PNG");

    Avantplan Caseselec={0};
    Caseselec.x=0;
    Caseselec.y=0;
    Caseselec.numcolonne=0;
    Caseselec.numligne=0;


    int numeroCase=0;
    Cases** casesMap=(Cases**) malloc (45 * sizeof(Cases*));;

    for (int i=0; i<45; i++){
        casesMap[i]= (Cases*) malloc (35 * sizeof(Cases));
    }





    for (int i = 0; i < 45; ++i) {
        for (int j = 0; j < 35; ++j) {
            casesMap[i][j].routepresente=false;
            casesMap[i][j].batimentpresent=false;
            casesMap[i][j].sapin=malloc(4* sizeof(bool));
            for (int k = 0; k < 4; ++k) {
                casesMap[i][j].sapin[k]=false;
            }
            casesMap[i][j].arbre=false;

        }
    }











    bool fintest=false;
    float decallagex=0;
    float decallagey=0;

    int statsapin=43;
    bool passapin=false;
    bool debutforet;



    for (int i = 0; i < 45; ++i) {
        for (int j = 0; j < 35; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    if ((i - 1 >= 0 && casesMap[i - 1][j].sapin[l]) || (i + 1 < 44 && casesMap[i + 1][j].sapin[l]) ||(j - 1 >= 0 && casesMap[i][j - 1].sapin[l]) || (j + 1 <= 34 && casesMap[i][j + 1].sapin[l])) {
                        debutforet = true;
                    }
                }

                if (debutforet && statsapin > 10) {
                    statsapin -= 10;
                }else if (debutforet && statsapin > 5) {
                    statsapin -= 5;
                }else if (debutforet && statsapin > 4) {
                    statsapin -= 4;
                }else if (debutforet && statsapin > 3) {
                    statsapin -= 3;
                }else if (debutforet && statsapin > 2) {
                    statsapin -= 2;
                } else if (debutforet) {
                    statsapin -= 1;
                }
                if ((rand()) % statsapin == 0) {
                    casesMap[i][j].sapin[k] = true;
                    passapin=false;
                }
            }if (passapin&&statsapin<=30){
                casesMap[i][j].arbre = true;
            }else{
                passapin=true;
            }
            if (debutforet) {
                debutforet = false;
                statsapin = 43;
            }


        }
    }



    long long compttimer=0;
    al_start_timer(timer);

    while (!fintest){
        ALLEGRO_EVENT event = {0};
        al_wait_for_event(queue, &event);
        switch (event.type) {

            case ALLEGRO_EVENT_TIMER:
                compttimer += 1;

                if (compttimer % 8 == 0) {


                    al_get_keyboard_state(&keyboard_state);
                    if (al_key_down(&keyboard_state, ALLEGRO_KEY_S)) {
                        decallagey-=40;
                        calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey);

                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Q)) {
                        decallagex+=40;
                        calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey);
                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_D)) {
                        decallagex-=40;
                        calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey);
                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Z)) {
                        decallagey+=40;
                        calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey);
                    }






                    al_clear_to_color(al_map_rgb(0,0,0));
                    for (int i = 0; i < 11; ++i) {
                        al_draw_bitmap(Bordure,CASE*5*(float)i+XPRIMAIRE+decallagex-500, -500+YPRIMAIRE+decallagey, 0);
                        al_draw_bitmap(Bordure,CASE*5*(float)i+XPRIMAIRE+decallagex-500, 3500+YPRIMAIRE+decallagey, 0);
                    }
                    for (int i = 0; i < 9; ++i) {
                        al_draw_bitmap(Bordure,XPRIMAIRE+decallagex-500, YPRIMAIRE+decallagey+CASE*5*(float)i, 0);
                        al_draw_bitmap(Bordure,XPRIMAIRE+decallagex+4500, YPRIMAIRE+decallagey+CASE*5*(float)i, 0);
                    }


                    for (int i = 0; i < 45; ++i) {
                        for (int j = 0; j<35; j++){
                            if(!casesMap[i][j].routepresente && !casesMap[i][j].batimentpresent ){
                                al_draw_bitmap(Route[0],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                            }else if(casesMap[i][j].routepresente){

                                if((j-1>=0)&&casesMap[i][j-1].routepresente){

                                    if((j+1<=34)&&casesMap[i][j+1].routepresente){
                                        if((i-1>=0)&&casesMap[i-1][j].routepresente){
                                            if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                                al_draw_bitmap(Route[16],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                            }else{
                                                al_draw_bitmap(Route[12],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                            }

                                        }else if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                            al_draw_bitmap(Route[13],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }else{
                                            al_draw_bitmap(Route[6],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }
                                    }else if((i-1>=0)&&casesMap[i-1][j].routepresente){
                                        if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                            al_draw_bitmap(Route[14],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }else{
                                            al_draw_bitmap(Route[7],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }
                                    }else if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                        al_draw_bitmap(Route[8],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }else{
                                        al_draw_bitmap(Route[2],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }

                                }else if((j+1<=34)&&casesMap[i][j+1].routepresente){

                                    if((i-1>=0)&&casesMap[i-1][j].routepresente){
                                        if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                            al_draw_bitmap(Route[15],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }else{
                                            al_draw_bitmap(Route[9],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                        }

                                    }else if((i+1<=44)&&casesMap[i+1][j].routepresente){

                                        al_draw_bitmap(Route[10],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }else{
                                        al_draw_bitmap(Route[3],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }

                                }else if((i-1>=0)&&casesMap[i-1][j].routepresente){

                                    if((i+1<=44)&&casesMap[i+1][j].routepresente){
                                        al_draw_bitmap(Route[11],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }else{
                                        al_draw_bitmap(Route[4],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                    }
                                }else if((i+1<=44)&&casesMap[i+1][j].routepresente){

                                    al_draw_bitmap(Route[5],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                }else{

                                    al_draw_bitmap(Route[1],CASE*(float)i+XPRIMAIRE+decallagex, CASE*(float)j+YPRIMAIRE+decallagey, 0);
                                }

                            }

                        }
                    }

                    for (int i = 0; i < 35; ++i) {
                        for (int j = 0; j < 45; ++j) {
                            if(!casesMap[j][i].routepresente&&!casesMap[j][i].batimentpresent){
                                for (int k = 0; k < 4; ++k) {
                                    if(casesMap[j][i].sapin[k]){
                                        al_draw_bitmap(Sapin,CASE*(float)j+XPRIMAIRE+decallagex+3+(k%2)*50, CASE*(float)i+YPRIMAIRE+decallagey-13+((k>=2)?0:1)*50, 0);
                                    }
                                }
                                if(casesMap[j][i].arbre){
                                    al_draw_bitmap(Arbre,CASE*(float)j+XPRIMAIRE+decallagex+15, CASE*(float)i+YPRIMAIRE+decallagey-10, 0);

                                }
                            }


                        }
                    }





                    al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x+100, Caseselec.y+100, al_map_rgba(200, 20, 20, 80));

                    al_draw_filled_rectangle(larg-200, 20, larg-20, 160, al_map_rgba(255, 255, 255, 100));
                    al_draw_filled_rectangle(larg-200+Caseselec.numcolonne*4, 20+Caseselec.numligne*4, larg-200+(Caseselec.numcolonne+1)*4, 20+(Caseselec.numligne+1)*4, al_map_rgba(200, 20, 20, 100));

                    al_flip_display();


                }
                break;



            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        fintest = true;
                        break;
                }
                break;
            case ALLEGRO_EVENT_MOUSE_AXES:
                al_get_mouse_state(&mouse_state);
                calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey);
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                if(!casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente && !casesMap[Caseselec.numcolonne][Caseselec.numligne].batimentpresent ){
                    casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente=true;
                    for (int i = 0; i < 4; ++i) {
                        casesMap[Caseselec.numcolonne][Caseselec.numligne].sapin[i]=false;
                    }
                }else if(casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente){
                    casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente=false;
                }
                break;


        }
    }




}






void calculcaseselec(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey){
    al_get_mouse_state(mouse_state);
    for (int i =0; i<45; i++){
        if((float)mouse_state->x>=XPRIMAIRE+(float)i*CASE+decallagex&&(float)mouse_state->x<=XPRIMAIRE+(float)(i+1)*CASE+decallagex){
            for (int j=0; j<35; j++){
                if((float)mouse_state->y>=YPRIMAIRE+(float)j*CASE+decallagey&&(float)mouse_state->y<=YPRIMAIRE+(float)(j+1)*CASE+decallagey){

                    Caseselec->x = (float) i*CASE + (float) ((int) (decallagex) ) + XPRIMAIRE;
                    Caseselec->y = (float) j*CASE + (float) ((int) (decallagey) ) + YPRIMAIRE;
                    Caseselec->numcolonne=i;
                    Caseselec->numligne=j;

                }
            }
        }
    }
}