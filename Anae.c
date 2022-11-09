//
// Created by gabdu on 02/11/2022.
//gggg

#include "Anae.h"
#define XPRIMAIRE 0
#define YPRIMAIRE 0
#define CASE 40

void testvoiture(){

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
    ALLEGRO_FONT *PressStart35 = al_load_ttf_font("../Fonts/PressStart2P-Regular.ttf", 35, 0);
    assert(PressStart35);
    ALLEGRO_FONT *Chiffre35 = al_load_ttf_font("../Fonts/Koulen-Regular.ttf", 20, 0);
    assert(Chiffre35);

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

    ALLEGRO_BITMAP* Batiments[5]={
            {al_load_bitmap("../Batiments/TerrainVague.PNG")},
            {al_load_bitmap("../Batiments/Cabane.PNG")},
            {al_load_bitmap("../Batiments/Maison.PNG")},
            {al_load_bitmap("../Batiments/Immeuble.PNG")},
            {al_load_bitmap("../Batiments/GratteCiel.PNG")},

    };

    ALLEGRO_BITMAP* Bordure=al_load_bitmap("../Route/Bordure.PNG");
    ALLEGRO_BITMAP* Sapin=al_load_bitmap("../Route/Sapin.PNG");
    ALLEGRO_BITMAP* Ingo=al_load_bitmap("../ImagesMenuStart/SpriteIngo.PNG");


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
            casesMap[i][j].hautgauche=false;
            casesMap[i][j].sapin=false;


        }
    }





    int nombrebatiment=0;




    long long chrono=0;

    int etatjeu=0;


    bool finpartie=false;
    bool finjeu=false;
    float decallagex=0;
    float decallagey=0;

    int statsapin=53;
    bool debutforet;


    for (int i = 0; i < 45; ++i) {
        for (int j = 0; j < 35; ++j) {
            if ((i - 1 >= 0 && casesMap[i - 1][j].sapin) || (i + 1 < 44 && casesMap[i + 1][j].sapin) ||
                (j - 1 >= 0 && casesMap[i][j - 1].sapin) || (j + 1 <= 34 && casesMap[i][j + 1].sapin)) {
                debutforet = true;
            }


            if (debutforet && statsapin > 51) {
                statsapin -= 51;
            }
            if(rand()%statsapin==0){
                casesMap[i][j].sapin=true;
            }


            if (debutforet) {
                debutforet = false;
                statsapin = 53;
            }





        }
    }



    long long compttimer=0;
    al_start_timer(timer);

    while (!finjeu){
        switch (etatjeu) {
            case 0:
                etatjeu=1;
                break;
            case 1:

                while (!finpartie){


                    ALLEGRO_EVENT event = {0};
                    al_wait_for_event(queue, &event);
                    switch (event.type) {

                        case ALLEGRO_EVENT_TIMER:
                            compttimer += 1;
                            if(compttimer % 100 == 0){
                                chrono++;
                                if(chrono%5==0){
                                    for (int i = 0; i < 45; ++i) {
                                        for (int j = 0; j < 35; ++j) {
                                            if(casesMap[i][j].batimentpresent&&casesMap[i][j].niveaudebatiment<4){
                                                casesMap[i][j].niveaudebatiment++;
                                            }
                                        }
                                    }
                                }
                            }

                            if (compttimer % 8 == 0) {


                                al_get_keyboard_state(&keyboard_state);
                                if (al_key_down(&keyboard_state, ALLEGRO_KEY_S)) {
                                    if(decallagey>(-(1600-haut))){
                                        decallagey-=40;
                                    }else if (decallagey>(-(1640-larg))){
                                        decallagey=-(1640-haut);
                                    }


                                    calculcaseselecAna(&mouse_state,  &Caseselec, decallagex, decallagey);

                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Q)) {
                                    if(decallagex<160){
                                        decallagex+=40;
                                    }else if(decallagex<200){
                                        decallagex=200;
                                    }

                                    calculcaseselecAna(&mouse_state,  &Caseselec, decallagex, decallagey);
                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_D)) {
                                    if(decallagex>(-(1960-larg))){
                                        decallagex-=40;
                                    }else if (decallagex>(-(2000-larg))){
                                        decallagex=-(2000-larg);
                                    }

                                    calculcaseselecAna(&mouse_state,  &Caseselec, decallagex, decallagey);
                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Z)) {
                                    if(decallagey<160){
                                        decallagey+=40;
                                    }else if(decallagex<200){
                                        decallagey=200;
                                    }
                                    calculcaseselecAna(&mouse_state,  &Caseselec, decallagex, decallagey);
                                }







                                al_clear_to_color(al_map_rgb(0,0,0));
                                for (int i = 0; i < 11; ++i) {
                                    al_draw_bitmap(Bordure,CASE*5*(float)i+XPRIMAIRE+decallagex-200, -200+YPRIMAIRE+decallagey, 0);
                                    al_draw_bitmap(Bordure,CASE*5*(float)i+XPRIMAIRE+decallagex-200, 1400+YPRIMAIRE+decallagey, 0);
                                }
                                for (int i = 0; i < 7; ++i) {
                                    al_draw_bitmap(Bordure,XPRIMAIRE+decallagex-200, YPRIMAIRE+decallagey+CASE*5*(float)i, 0);
                                    al_draw_bitmap(Bordure,XPRIMAIRE+decallagex+1800, YPRIMAIRE+decallagey+CASE*5*(float)i, 0);
                                }






                                for (int i = 0; i < 45; ++i) {
                                    for (int j = 0; j<35; j++){
                                        if(!casesMap[i][j].routepresente ){
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
                                            if(casesMap[j][i].sapin){
                                                al_draw_bitmap(Sapin,CASE*(float)j+XPRIMAIRE+decallagex-2, CASE*(float)i+YPRIMAIRE+decallagey-10, 0);

                                            }



                                        }
                                        if(casesMap[j][i].hautgauche&&casesMap[j][i].batimentpresent){
                                            al_draw_bitmap(Batiments[casesMap[j][i].niveaudebatiment],CASE*(float)j+XPRIMAIRE+decallagex, CASE*(float)i+YPRIMAIRE+decallagey-(float)((casesMap[j][i].niveaudebatiment==4)?100:(casesMap[j][i].niveaudebatiment==3)?40:0), 0);
                                        }


                                    }
                                }






                                al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x+CASE, Caseselec.y+CASE, al_map_rgba(200, 20, 20, 80));

                                al_draw_filled_rectangle(larg-200, 20, larg-20, 160, al_map_rgba(255, 255, 255, 100));
                                for(int i=0; i<45; i++){
                                    for(int j =0; j<35; j++){
                                        if(casesMap[i][j].routepresente){
                                            al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(10, 10, 10, 100));
                                        }
                                        if(casesMap[i][j].batimentpresent){
                                            al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(255, 10, 10, 100));
                                        }
                                    }
                                }
                                al_draw_filled_rectangle(larg-200+Caseselec.numcolonne*4, 20+Caseselec.numligne*4, larg-200+(Caseselec.numcolonne+1)*4, 20+(Caseselec.numligne+1)*4, al_map_rgba(120, 20, 120, 100));

                                al_draw_textf(PressStart35, al_map_rgb(10, 10, 10), larg/2, 20, 0, "%d", (int)chrono);



                                al_flip_display();


                            }
                            break;



                        case ALLEGRO_EVENT_KEY_DOWN:
                            switch (event.keyboard.keycode) {
                                case ALLEGRO_KEY_ESCAPE:
                                    finpartie = true;
                                    finjeu=true;
                                    break;
                            }
                            break;
                        case ALLEGRO_EVENT_MOUSE_AXES:
                            al_get_mouse_state(&mouse_state);
                            calculcaseselecAna(&mouse_state,  &Caseselec, decallagex, decallagey);
                            break;

                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                            al_get_mouse_state(&mouse_state);

                            if((mouse_state.buttons & 1) == 1) {
                                if(Caseselec.numcolonne<45&&!casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente && !casesMap[Caseselec.numcolonne][Caseselec.numligne].batimentpresent  ) {
                                    casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente=true;
                                    casesMap[Caseselec.numcolonne][Caseselec.numligne].sapin=false;

                                }else if(Caseselec.numcolonne<45&&casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente){
                                    casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente=false;
                                }
                            }else{
                                if(Caseselec.numcolonne<45&&!casesMap[Caseselec.numcolonne][Caseselec.numligne].routepresente && !casesMap[Caseselec.numcolonne][Caseselec.numligne].batimentpresent  ){
                                    bool batimentendessous = false;
                                    for (int i = 0; i < 3; ++i) {
                                        for (int j = 0; j < 3; ++j) {
                                            if(Caseselec.numcolonne+i>44||Caseselec.numligne+j>34){
                                                batimentendessous=true;
                                            }else{
                                                if( casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].batimentpresent==true){
                                                    batimentendessous=true;
                                                }

                                            }

                                        }
                                    }
                                    if(!batimentendessous){
                                        nombrebatiment++;
                                        for (int i = 0; i < 3; ++i) {
                                            for (int j = 0; j < 3; ++j) {
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].hautgauche=false;
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].routepresente=false;
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].numerobatiment=nombrebatiment;
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].batimentpresent=true;
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].niveaudebatiment=0;
                                                casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].sapin=false;

                                            }
                                        }
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].hautgauche=true;

                                    }



                                }
                            }


                            break;


                    }
                }



                break;

        }
    }








}






void calculcaseselecAna(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey){
    al_get_mouse_state(mouse_state);
    bool unfined=true;
    for (int i =0; i<45; i++){
        if((float)mouse_state->x>=XPRIMAIRE+(float)i*CASE+decallagex&&(float)mouse_state->x<=XPRIMAIRE+(float)(i+1)*CASE+decallagex){
            for (int j=0; j<35; j++){
                if((float)mouse_state->y>=YPRIMAIRE+(float)j*CASE+decallagey&&(float)mouse_state->y<=YPRIMAIRE+(float)(j+1)*CASE+decallagey){

                    Caseselec->x = (float) i*CASE + (float) ((int) (decallagex) ) + XPRIMAIRE;
                    Caseselec->y = (float) j*CASE + (float) ((int) (decallagey) ) + YPRIMAIRE;
                    Caseselec->numcolonne=i;
                    Caseselec->numligne=j;
                    unfined=false;

                }
            }
        }
    }
    if(unfined){
        Caseselec->x = (float) 2000*CASE + (float) ((int) (decallagex) ) + XPRIMAIRE;
        Caseselec->y = (float) 2000*CASE + (float) ((int) (decallagey) ) + YPRIMAIRE;
        Caseselec->numcolonne=2000;
        Caseselec->numligne=2000;
    }
}