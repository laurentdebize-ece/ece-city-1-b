//
// Created by gabdu on 02/11/2022.
#include "Gabriel.h"
#include "Matthieu.h"
#define CASE 40



void affichage(){

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

    //***************INITIALISATION DU DISPLAY*****************


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
    ALLEGRO_FONT *PressStart15 = al_load_ttf_font("../Fonts/PressStart2P-Regular.ttf", 15, 0);
    assert(PressStart15);
    ALLEGRO_FONT *PressStart20 = al_load_ttf_font("../Fonts/PressStart2P-Regular.ttf", 20, 0);
    assert(PressStart20);
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
    ALLEGRO_BITMAP* Flux[16]={
            {al_load_bitmap("../Route/FluxRien.PNG")},
            {al_load_bitmap("../Route/FluxHaut.PNG")},
            {al_load_bitmap("../Route/FluxBas.PNG")},
            {al_load_bitmap("../Route/FluxGauche.PNG")},
            {al_load_bitmap("../Route/FluxDroite.PNG")},
            {al_load_bitmap("../Route/FluxHautBas.PNG")},
            {al_load_bitmap("../Route/FluxHautGauche.PNG")},
            {al_load_bitmap("../Route/FluxHautDroite.PNG")},
            {al_load_bitmap("../Route/FluxBasGauche.PNG")},
            {al_load_bitmap("../Route/FluxBasDroite.PNG")},
            {al_load_bitmap("../Route/FluxGaucheDroite.PNG")},
            {al_load_bitmap("../Route/FluxHautBasGauche.PNG")},
            {al_load_bitmap("../Route/FluxHautBasDroite.PNG")},
            {al_load_bitmap("../Route/FluxHautGaucheDroite.PNG")},
            {al_load_bitmap("../Route/FluxBasGaucheDroite.PNG")},
            {al_load_bitmap("../Route/FluxHautBasGaucheDroite.PNG")},
    };

    ALLEGRO_BITMAP* Batiments[10]={
            {al_load_bitmap("../Batiments/Ruines.PNG")},
            {al_load_bitmap("../Batiments/TerrainVague.PNG")},
            {al_load_bitmap("../Batiments/Cabane.PNG")},
            {al_load_bitmap("../Batiments/Maison.PNG")},
            {al_load_bitmap("../Batiments/Immeuble.PNG")},
            {al_load_bitmap("../Batiments/GratteCiel.PNG")},
            {al_load_bitmap("../Batiments/CentralElec.PNG")},
            {al_load_bitmap("../Batiments/ChateauEau.PNG")},
            {al_load_bitmap("../Batiments/Caserne.PNG")},
            {al_load_bitmap("../Batiments/Pokedefense.PNG")},

    };
    ALLEGRO_BITMAP* Cataclysmes[16]={
            {al_load_bitmap("../Cataclysmes/Feu1.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu2.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu3.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu4.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu5.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu6.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu7.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu8.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu9.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu10.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu11.PNG")},
            {al_load_bitmap("../Cataclysmes/Feu12.PNG")},
            {al_load_bitmap("../Cataclysmes/Godzilla1.PNG")},
            {al_load_bitmap("../Cataclysmes/Godzilla2.PNG")},
            {al_load_bitmap("../Cataclysmes/Godzilla3.PNG")},
            {al_load_bitmap("../Cataclysmes/Godzilla4.PNG")},

    };

    ALLEGRO_BITMAP* BoutonMenuJeu[9]={
            {al_load_bitmap("../MenuJeu/BoutonRoute.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonRoute.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonHabitation.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonCentralElec.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonChateauEau.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonCaserne.PNG")},
            {al_load_bitmap("../MenuJeu/BoutonPokedefense.PNG")},
            {al_load_bitmap("../MenuJeu/QuitterPartie.PNG")},
            {al_load_bitmap("../MenuJeu/RevenirAchat.PNG")},

    };

    ALLEGRO_BITMAP* Bordure=al_load_bitmap("../Route/Bordure.PNG");
    ALLEGRO_BITMAP* Sapin=al_load_bitmap("../Route/Sapin.PNG");

    // Partie Menu des Images
    ALLEGRO_BITMAP* Ingo=al_load_bitmap("../ImagesMenuStart/SpriteIngo.PNG");
    ALLEGRO_BITMAP* Eclair=al_load_bitmap("../ImagesMenuStart/Eclair.PNG");
    ALLEGRO_BITMAP* BoutonCommuniste=al_load_bitmap("../ImagesMenuStart/BoutonCommuniste.PNG");
    ALLEGRO_BITMAP* BoutonCapitaliste=al_load_bitmap("../ImagesMenuStart/BoutonCapitaliste.PNG");
    ALLEGRO_BITMAP* NouvellePartie=al_load_bitmap("../ImagesMenuStart/NouvellePartie.PNG");
    ALLEGRO_BITMAP* ChargerPartie=al_load_bitmap("../ImagesMenuStart/ChargerPartie.PNG");
    ALLEGRO_BITMAP* Sauvegarde1=al_load_bitmap("../ImagesMenuStart/Sauvegarde1.PNG");
    ALLEGRO_BITMAP* Sauvegarde2=al_load_bitmap("../ImagesMenuStart/Sauvegarde2.PNG");
    ALLEGRO_BITMAP* Sauvegarde3=al_load_bitmap("../ImagesMenuStart/Sauvegarde3.PNG");
    ALLEGRO_BITMAP* Sauvegarde4=al_load_bitmap("../ImagesMenuStart/Sauvegarde4.PNG");
    ALLEGRO_BITMAP* Quitter=al_load_bitmap("../ImagesMenuStart/Quitter.PNG");
    ALLEGRO_BITMAP* Revenir=al_load_bitmap("../ImagesMenuStart/Revenir.PNG");
    ALLEGRO_BITMAP* PokeCityLogo=al_load_bitmap("../ImagesMenuStart/PokeCityLogo.PNG");
    ALLEGRO_BITMAP* FondMenu=al_load_bitmap("../ImagesMenuStart/FondMenu.PNG");



    //***************INITIALISATION DES VARIABLES ET DES STRUCUTRES*****************

    bool finpartie=false;
    bool finjeu=false;
    bool finmenu=false;

    int statsapin=53;
    bool debutforet;

    int etatjeu= PARTIE;

    int lieumenu=DEMARRAGE;
    int regimepolitique=-1;
    int sauvegardechoisie=0;
    int blabla=1;

    long long compttimer=0;
    long long chrono=1;
    int nombrebatiment=0;
    float decallagex=0;
    float decallagey=0;
    bool menujeu=false;
    bool animation=true;
    bool animinverse=false;
    float decalanim=1;

    int pokedollars=500000;
    int achat=-1;
    int nbhabitants=0;
    int niveauvue=0;
    bool attaquegodzilla=false;
    bool sensattaque=false;

    int xgodzilla=-50;
    int ygodzilla=-50;




    Avantplan Caseselec={0};
    Caseselec.x=0;
    Caseselec.y=0;
    Caseselec.numcolonne=0;
    Caseselec.numligne=0;

    Cases** casesMap=(Cases**) malloc (45 * sizeof(Cases*));;

    for (int i=0; i<45; i++){
        casesMap[i]= (Cases*) malloc (35 * sizeof(Cases));
    }

    for (int i = 0; i < 45; ++i) {
        for (int j = 0; j < 35; ++j) {
            casesMap[i][j].sapin=false;
            casesMap[i][j].niveaudebatiment=0;
            casesMap[i][j].numerobatiment=-1;
            casesMap[i][j].typedeconstruction=AUCUNE;
            casesMap[i][j].hautgauche=false;
            casesMap[i][j].nombrehabitants=0;
            casesMap[i][j].incendie=false;


        }
    }

//***************CREATION D'UNE FORET ALEATOIRE*****************
    for (int i = 0; i < 45; ++i) {
        for (int j = 1; j < 35; ++j) {
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



    //***************LANCEMENT DU JEU*****************

    al_start_timer(timer);
    while (!finjeu){
        switch (etatjeu) {
            case MENUPRINCIPAL:
                while (!finmenu){
                    ALLEGRO_EVENT event = {0};
                    al_wait_for_event(queue, &event);
                    switch (event.type){
                        case ALLEGRO_EVENT_TIMER:
                            compttimer++;
                            if (compttimer % 4 == 0){
                                al_draw_bitmap(FondMenu, larg/2-1535/2, haut/2-864/2, 0);
                                al_draw_bitmap(PokeCityLogo, larg/2-556/2, 10, 0);
                                switch (lieumenu) {
                                    case DEMARRAGE:
                                        al_draw_bitmap(NouvellePartie, larg/2-200, haut/2-140, 0);
                                        al_draw_bitmap(ChargerPartie, larg/2-200, haut/2+54, 0);
                                        al_draw_bitmap(Quitter, larg/2-100, haut/2+260, 0);
                                        break;
                                    case CHOIXREGIME:

                                        al_draw_bitmap(BoutonCommuniste, larg/2-200, haut/2-140, 0);
                                        al_draw_bitmap(BoutonCapitaliste, larg/2-200, haut/2+54, 0);
                                        al_draw_bitmap(Revenir, larg/2-100, haut/2+260, 0);
                                        break;
                                    case CHOIXSAUVEGARDE:
                                        al_draw_bitmap(Sauvegarde1, larg/2-410, haut/2-140, 0);
                                        al_draw_bitmap(Sauvegarde2, larg/2+10, haut/2-140, 0);
                                        al_draw_bitmap(Sauvegarde3, larg/2-410, haut/2+54, 0);
                                        al_draw_bitmap(Sauvegarde4, larg/2+10, haut/2+54, 0);
                                        al_draw_bitmap(Revenir, larg/2-100, haut/2+260, 0);
                                        break;

                                }
                                if(blabla>=1&&animation==false){
                                    al_draw_bitmap(Ingo, 120, haut-500,0);
                                    al_draw_filled_ellipse(larg/2, haut/2-30, 330, 170, al_map_rgb(255, 255, 255));
                                    al_draw_bitmap(Eclair, 320, haut-540,0);
                                    switch (blabla) {
                                        case 1:
                                            al_draw_text(PressStart35, al_map_rgb(0, 0, 40), larg/2-150, haut/2-120,0, "BIENVENUE");
                                            al_draw_text(PressStart35, al_map_rgb(0, 0, 40), larg/2-10, haut/2-50,0, "A");
                                            al_draw_text(PressStart35, al_map_rgb(0, 0, 40), larg/2-150, haut/2+20,0, "POKÉCITY !");
                                            break;
                                        case 2:
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-230, haut/2-100,0, "Mon nom est Ingo et je");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-220, haut/2-70,0, "suis votre conseiller ");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-250, haut/2-40,0, "municipal. Votre permis de");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-250, haut/2-10,0, "construire a  été accepté!");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-150, haut/2+20,0, "Félicitations!");

                                            break;
                                        case 3:
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-230, haut/2-100,0, "Développez votre ville");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-180, haut/2-70,0, "pour avoir le plus");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-190, haut/2-40,0, " d'habitants et de ");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-200, haut/2-10,0, "Pokédollars possible!");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-120, haut/2+20,0, "Bonne chance!");

                                            break;
                                        case 4:
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-200, haut/2-100,0, "Choisissez le régime");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-180, haut/2-70,0, "que vous souhaitez!");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-180, haut/2-40,0, " Plutôt communiste ");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-150, haut/2-10,0, "ou capitaliste?");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-160, haut/2+20,0, "Essayez les deux!");
                                            break;
                                        case 5:
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-155, haut/2-100,0, "Choisissez votre");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-95, haut/2-70,0, "sauvegarde");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-155, haut/2-40,0, " pour récupérer ");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-140, haut/2-10,0, "une partie déjà");
                                            al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-90, haut/2+20,0, "commencée!");
                                            break;
                                    }
                                }
                                if((lieumenu==DEMARRAGE||lieumenu==CHOIXREGIME )&& blabla==0&&animation==false){
                                    if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2-140 && mouse_state.y<=haut/2+26){
                                        al_draw_filled_rectangle(larg/2-200, haut/2-140,larg/2+200,  haut/2+26,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2+54 && mouse_state.y<=haut/2+220){
                                        al_draw_filled_rectangle(larg/2-200, haut/2+54,larg/2+200,  haut/2+220,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+260 && mouse_state.y<=haut/2+342){
                                        al_draw_filled_rectangle(larg/2-100, haut/2+260,larg/2+100,  haut/2+342,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }
                                }else if(lieumenu==CHOIXSAUVEGARDE&&blabla==0&&animation==false){
                                    if(mouse_state.x>=larg/2-410 && mouse_state.x<=larg/2-10 && mouse_state.y>=haut/2-140 && mouse_state.y<=haut/2+26){
                                        al_draw_filled_rectangle(larg/2-410, haut/2-140,larg/2-10,  haut/2+26,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    } else if(mouse_state.x>=larg/2+10 && mouse_state.x<=larg/2+410 && mouse_state.y>=haut/2-140 && mouse_state.y<=haut/2+26){
                                        al_draw_filled_rectangle(larg/2+10, haut/2-140,larg/2+410,  haut/2+26,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=larg/2-410 && mouse_state.x<=larg/2-10 && mouse_state.y>=haut/2+54 && mouse_state.y<=haut/2+220){
                                        al_draw_filled_rectangle(larg/2-410, haut/2+54,larg/2-10,  haut/2+220,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=larg/2+10 && mouse_state.x<=larg/2+410 && mouse_state.y>=haut/2+54 && mouse_state.y<=haut/2+220){
                                        al_draw_filled_rectangle(larg/2+10, haut/2+54,larg/2+410,  haut/2+220,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+260 && mouse_state.y<=haut/2+342){
                                        al_draw_filled_rectangle(larg/2-100, haut/2+260,larg/2+100,  haut/2+342,
                                                                 al_map_rgba(0, 0, 0, 40));
                                    }
                                }
                                if(animation){
                                    if(!animinverse){
                                        if(decalanim<=10){
                                            al_draw_bitmap(Ingo, 120, haut-500*(((1- sqrt(1-pow(2*decalanim/20, 2)))/2)-((1- sqrt(1-pow(2*(decalanim-1)/20, 2)))/2)), 0);
                                        }else{
                                            al_draw_bitmap(Ingo, 120, haut-500+500*(((sqrt(1-pow(-2*decalanim/20+2, 2))+1)/2)-((sqrt(1-pow(-2*(decalanim-1)/20+2, 2))+1)/2)), 0);
                                        }
                                        decalanim++;
                                        if(decalanim==21){
                                            animation=false;
                                            animinverse=true;
                                        }
                                    }else{
                                        if(decalanim<=10){
                                            al_draw_bitmap(Ingo, 120, haut-500*(((1- sqrt(1-pow(2*decalanim/20, 2)))/2)-((1- sqrt(1-pow(2*(decalanim-1)/20, 2)))/2)), 0);
                                        }else{
                                            al_draw_bitmap(Ingo, 120, haut-500+500*(((sqrt(1-pow(-2*decalanim/20+2, 2))+1)/2)-((sqrt(1-pow(-2*(decalanim-1)/20+2, 2))+1)/2)), 0);
                                        }
                                        decalanim--;
                                        if(decalanim==1){
                                            decalanim=1;
                                            animation=false;
                                            animinverse=false;
                                        }
                                    }
                                }
                                al_flip_display();
                            }
                            break;

                        case ALLEGRO_EVENT_KEY_DOWN:
                            switch (event.keyboard.keycode) {
                                case ALLEGRO_KEY_ESCAPE:
                                    finpartie = true;
                                    finmenu=true;
                                    finjeu=true;
                                    break;
                            }
                            break;
                        case ALLEGRO_EVENT_MOUSE_AXES:
                            al_get_mouse_state(&mouse_state);
                            break;
                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                            al_get_mouse_state(&mouse_state);
                            if(blabla>=1&&animation==false){
                                blabla++;
                                if(blabla>=4){
                                    blabla=0;
                                    animation=true;
                                }
                            }else if (animation==false){
                                switch (lieumenu) {
                                    case DEMARRAGE:
                                        if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2-140-5 && mouse_state.y <=haut/2+26-5){
                                            lieumenu=CHOIXREGIME;
                                            blabla=4;
                                            animation=true;
                                        }else if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2+54-5 && mouse_state.y <=haut/2+220-5){
                                            lieumenu=CHOIXSAUVEGARDE;
                                            blabla=5;
                                            animation=true;
                                        }
                                        else if(mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+260-5 && mouse_state.y <=haut/2+342-5){
                                            finpartie =true;
                                            finmenu=true;
                                            finjeu=true;
                                        }
                                        break;
                                    case CHOIXREGIME:
                                        if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2-140-5 && mouse_state.y <=haut/2+26-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            regimepolitique=COMMUNISTE;
                                            compttimer=0;
                                        }else if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2+54-5 && mouse_state.y <=haut/2+220-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            regimepolitique=CAPITALISTE;
                                            compttimer=0;
                                        }
                                        else if(mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+260-5 && mouse_state.y <=haut/2+342-5){
                                            lieumenu=DEMARRAGE;
                                        }
                                        break;
                                    case CHOIXSAUVEGARDE:
                                        if(mouse_state.x>=larg/2-410 && mouse_state.x<=larg/2+10 && mouse_state.y>=haut/2-140-5 && mouse_state.y <=haut/2+26-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            sauvegardechoisie=1;
                                            compttimer=0;
                                        }else if(mouse_state.x>=larg/2+10 && mouse_state.x<=larg/2+410 && mouse_state.y>=haut/2-140-5 && mouse_state.y <=haut/2+26-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            sauvegardechoisie=2;
                                            compttimer=0;
                                        }else if(mouse_state.x>=larg/2-410 && mouse_state.x<=larg/2+10 && mouse_state.y>=haut/2+54-5 && mouse_state.y <=haut/2+220-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            sauvegardechoisie=3;
                                            compttimer=0;
                                        }else if(mouse_state.x>=larg/2+10 && mouse_state.x<=larg/2+410 && mouse_state.y>=haut/2+54-5 && mouse_state.y <=haut/2+220-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            sauvegardechoisie=4;
                                            compttimer=0;
                                        }
                                        else if(mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+260-5 && mouse_state.y <=haut/2+342-5){
                                            lieumenu=DEMARRAGE;
                                        }
                                        break;
                                }
                            }
                            break;
                    }
                }

                etatjeu=PARTIE;
                break;
            case PARTIE:
                if(sauvegardechoisie!=0){
                    switch (sauvegardechoisie) {
                        case 1:
                            fonctionrecuperationSauvgarde("Sauvegarde1", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 2:
                            fonctionrecuperationSauvgarde("Sauvegarde2", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 3:
                            fonctionrecuperationSauvgarde("Sauvegarde3", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 4:
                            fonctionrecuperationSauvgarde("Sauvegarde4", casesMap, &pokedollars, &regimepolitique);
                            break;
                    }
                    for (int i = 0; i < 45; ++i) {
                        for (int j = 0; j < 35; ++j) {
                            if(casesMap[i][j].hautgauche){
                                nbhabitants+=casesMap[i][j].nombrehabitants;
                            }
                        }
                    }
                }
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
                                            if(casesMap[i][j].typedeconstruction==HABITATION){
                                                if(casesMap[i][j].niveaudebatiment<GRATTECIEL){
                                                    casesMap[i][j].niveaudebatiment++;
                                                    if(casesMap[i][j].niveaudebatiment==TERRAINVAGUE){
                                                        casesMap[i][j].niveaudebatiment++;
                                                    }
                                                    if(casesMap[i][j].hautgauche){
                                                        switch (casesMap[i][j].niveaudebatiment) {
                                                            case TERRAINVAGUE:
                                                                nbhabitants+=0;
                                                                casesMap[i][j].nombrehabitants=0;
                                                                break;
                                                            case CABANE:
                                                                nbhabitants+=10;
                                                                casesMap[i][j].nombrehabitants=10;
                                                                break;
                                                            case MAISON:
                                                                nbhabitants+=40;
                                                                casesMap[i][j].nombrehabitants=50;
                                                                break;
                                                            case IMMEUBLE:
                                                                nbhabitants+=50;
                                                                casesMap[i][j].nombrehabitants=100;
                                                                break;
                                                            case GRATTECIEL:
                                                                nbhabitants+=900;
                                                                casesMap[i][j].nombrehabitants=1000;
                                                                break;
                                                        }
                                                    }
                                                }

                                                if(casesMap[i][j].incendie){
                                                    casesMap[i][j].niveaudebatiment=RUINES;
                                                    if(casesMap[i][j].hautgauche){
                                                        nbhabitants-=casesMap[i][j].nombrehabitants;
                                                        casesMap[i][j].nombrehabitants=0;
                                                    }
                                                    casesMap[i][j].incendie=false;
                                                }
                                                if(!casesMap[i][j].incendie &&casesMap[i][j].nombrehabitants!=0 && rand()%20==0){
                                                    casesMap[i][j].incendie=true;
                                                }
                                            }
                                            if(casesMap[i][j].hautgauche){
                                                pokedollars+=casesMap[i][j].nombrehabitants*10;
                                            }
                                        }
                                    }
                                    if(rand()%1==0&&!attaquegodzilla){
                                        attaquegodzilla=true;
                                        ygodzilla=1+rand()%31;
                                        if(rand()%2==0){
                                            xgodzilla=50;
                                            sensattaque=false;
                                        }else{
                                            xgodzilla=-5;
                                            sensattaque=true;
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
                                    calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut, &menujeu);
                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Q)) {
                                    if(decallagex<160){
                                        decallagex+=40;
                                    }else if(decallagex<200){
                                        decallagex=200;
                                    }
                                    calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut, &menujeu);
                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_D)) {
                                    if(decallagex>(-(1960-larg))){
                                        decallagex-=40;
                                    }else if (decallagex>(-(2000-larg))){
                                        decallagex=-(2000-larg);
                                    }
                                    calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut, &menujeu);
                                } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Z)) {
                                    if(decallagey<160){
                                        decallagey+=40;
                                    }else if(decallagex<200){
                                        decallagey=200;
                                    }
                                    calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut, &menujeu);
                                }



                                if(attaquegodzilla && compttimer%32==0){
                                    if(sensattaque==false){
                                        xgodzilla--;
                                        if(xgodzilla<=-5){
                                            attaquegodzilla=false;
                                        }
                                        for (int i = 0; i < 3; ++i) {
                                            if(xgodzilla>=0 && xgodzilla<=44 && ygodzilla+i<=34 && ygodzilla+i>=0){

                                                casesMap[xgodzilla][ygodzilla+i].sapin=false;

                                                if(casesMap[xgodzilla][ygodzilla+i].typedeconstruction!=AUCUNE&&casesMap[xgodzilla][ygodzilla+i].typedeconstruction!=ROUTE){
                                                    nbhabitants-=casesMap[xgodzilla][ygodzilla+i].nombrehabitants;
                                                    for (int j = 0; j < 45; ++j) {
                                                        for (int k = 0; k < 35; ++k) {
                                                            if(casesMap[xgodzilla][ygodzilla+i].numerobatiment==casesMap[j][k].numerobatiment){
                                                                casesMap[j][k].typedeconstruction=AUCUNE;
                                                                casesMap[j][k].hautgauche=false;
                                                                casesMap[j][k].nombrehabitants=0;
                                                            }
                                                        }
                                                    }
                                                }else if(casesMap[xgodzilla][ygodzilla+i].typedeconstruction==ROUTE){
                                                    casesMap[xgodzilla][ygodzilla+i].typedeconstruction=AUCUNE;
                                                }
                                            }
                                        }
                                    }else{
                                        xgodzilla++;
                                        if(xgodzilla>= 50){
                                            attaquegodzilla=false;
                                        }
                                        for (int i = 0; i < 3; ++i) {
                                            if(xgodzilla+2<=44 && xgodzilla+2>=0 && ygodzilla+i >= 0 && ygodzilla+i<=34){
                                                casesMap[xgodzilla+2][ygodzilla+i].sapin=false;

                                                if(casesMap[xgodzilla+2][ygodzilla+i].typedeconstruction!=AUCUNE&&casesMap[xgodzilla+2][ygodzilla+i].typedeconstruction!=ROUTE){
                                                    nbhabitants-=casesMap[xgodzilla+2][ygodzilla+i].nombrehabitants;
                                                    for (int j = 0; j < 45; ++j) {
                                                        for (int k = 0; k < 35; ++k) {
                                                            if(casesMap[xgodzilla+2][ygodzilla+i].numerobatiment==casesMap[j][k].numerobatiment){
                                                                casesMap[j][k].typedeconstruction=AUCUNE;
                                                                casesMap[j][k].hautgauche=false;
                                                                casesMap[j][k].nombrehabitants=0;
                                                            }
                                                        }
                                                    }
                                                }else if(casesMap[xgodzilla+2][ygodzilla+i].typedeconstruction==ROUTE){
                                                    casesMap[xgodzilla+2][ygodzilla+i].typedeconstruction=AUCUNE;
                                                }
                                            }
                                        }
                                    }
                                }
                                if(attaquegodzilla && compttimer%16==0){
                                    decalanim++;
                                }




                                al_clear_to_color(al_map_rgb(0,0,0));





                                for (int i = 0; i < 45; ++i) {
                                    for (int j = 0; j<35; j++){
                                        int typederoute=0;
                                        if(casesMap[i][j].typedeconstruction!=ROUTE ){
                                            typederoute=0;
                                        }else if(casesMap[i][j].typedeconstruction==ROUTE){
                                            if((j-1>=0)&&casesMap[i][j-1].typedeconstruction==ROUTE){
                                                if((j+1<=34)&&casesMap[i][j+1].typedeconstruction==ROUTE){
                                                    if((i-1>=0)&&casesMap[i-1][j].typedeconstruction==ROUTE){
                                                        if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                            typederoute=16;
                                                           }else{
                                                            typederoute=12;
                                                          }
                                                    }else if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                        typederoute=13;
                                                    }else{
                                                        typederoute=6;
                                                    }
                                                }else if((i-1>=0)&&casesMap[i-1][j].typedeconstruction==ROUTE){
                                                    if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                        typederoute=14;
                                                    }else{
                                                        typederoute=7;
                                                    }
                                                }else if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                    typederoute=8;
                                                 }else{
                                                    typederoute=2;
                                                 }
                                            }else if((j+1<=34)&&casesMap[i][j+1].typedeconstruction==ROUTE){
                                                if((i-1>=0)&&casesMap[i-1][j].typedeconstruction==ROUTE){
                                                    if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                        typederoute=15;
                                                     }else{
                                                        typederoute=9;
                                                    }
                                                }else if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                    typederoute=10;
                                                }else{
                                                    typederoute=3;
                                                }
                                            }else if((i-1>=0)&&casesMap[i-1][j].typedeconstruction==ROUTE){
                                                if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                    typederoute=11;
                                                }else{
                                                    typederoute=4;
                                                }
                                            }else if((i+1<=44)&&casesMap[i+1][j].typedeconstruction==ROUTE){
                                                typederoute=5;
                                            }else{
                                                typederoute=1;
                                             }

                                        }
                                        if(niveauvue==0){
                                            al_draw_bitmap(Route[typederoute],CASE*(float)i+decallagex, CASE*(float)j+decallagey, 0);
                                        }else{
                                            al_draw_tinted_bitmap(Route[typederoute], al_map_rgb(200,165,235), CASE*(float)i+decallagex, CASE*(float)j+decallagey, 0);

                                            if(typederoute!=0){
                                                if(niveauvue==1){

                                                    al_draw_tinted_bitmap(Flux[typederoute-1], al_map_rgb(255,255,30), CASE*(float)i+decallagex, CASE*(float)j+decallagey, 0);
                                                }else if(niveauvue==2){

                                                    al_draw_tinted_bitmap(Flux[typederoute-1], al_map_rgb(40,40,255), CASE*(float)i+decallagex, CASE*(float)j+decallagey, 0);
                                                }
                                            }
                                        }
                                    }
                                }
                                al_draw_filled_ellipse(CASE*xgodzilla+decallagex+((sensattaque)?1:-1)*((((int)compttimer/8)%4*10)-20)+70, CASE*ygodzilla+decallagey+105, 55, 15,al_map_rgba(0, 0, 0, 80));
                                al_draw_bitmap(Cataclysmes[12+(int)decalanim%4], CASE*xgodzilla+decallagex+((sensattaque)?1:-1)*((((int)compttimer/8)%4*10)-20), CASE*ygodzilla+decallagey-20, sensattaque);

                                for (int i = 0; i < 35; ++i) {
                                    for (int j = 0; j < 45; ++j) {
                                        if(casesMap[j][i].typedeconstruction==AUCUNE){
                                            if(casesMap[j][i].sapin){
                                                if(niveauvue==0){
                                                    al_draw_bitmap(Sapin,CASE*(float)j+decallagex-2, CASE*(float)i+decallagey-10, 0);
                                                }else {
                                                    al_draw_tinted_bitmap(Sapin,al_map_rgba(120,100,180, 40),CASE*(float)j+decallagex-2, CASE*(float)i+decallagey-10, 0);
                                                }
                                            }
                                        }
                                        if(casesMap[j][i].hautgauche&&casesMap[j][i].typedeconstruction==HABITATION){
                                            if(niveauvue==0){
                                                al_draw_bitmap(Batiments[casesMap[j][i].niveaudebatiment],CASE*(float)j+decallagex, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0), 0);
                                                if(casesMap[j][i].incendie){
                                                    al_draw_bitmap(Cataclysmes[(2+compttimer/8)%6+6],CASE*(float)j+decallagex+20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+12, 1);
                                                    al_draw_bitmap(Cataclysmes[(5+compttimer/8)%6+6],CASE*(float)j+decallagex+20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+12, 0);
                                                    al_draw_bitmap(Cataclysmes[(3+compttimer/8)%6],CASE*(float)j+decallagex-10, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)-5, 0);
                                                    al_draw_bitmap(Cataclysmes[(compttimer/8)%6],CASE*(float)j+decallagex-20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+2, 0);
                                                    al_draw_bitmap(Cataclysmes[(2+compttimer/8)%6],CASE*(float)j+decallagex+50, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+15, 1);
                                                }
                                            }else{
                                                al_draw_tinted_bitmap(Batiments[casesMap[j][i].niveaudebatiment],
                                                                      al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0), 0);

                                                if(casesMap[j][i].incendie){
                                                    al_draw_tinted_bitmap(Cataclysmes[(2+compttimer/8)%6+6],al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex+20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+12, 1);
                                                    al_draw_tinted_bitmap(Cataclysmes[(5+compttimer/8)%6+6],al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex+20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+12, 0);
                                                    al_draw_tinted_bitmap(Cataclysmes[(3+compttimer/8)%6],al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex-10, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)-5, 0);
                                                    al_draw_tinted_bitmap(Cataclysmes[(compttimer/8)%6],al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex-20, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+2, 0);
                                                    al_draw_tinted_bitmap(Cataclysmes[(2+compttimer/8)%6],al_map_rgba(100,100,100, 40),CASE*(float)j+decallagex+50, CASE*(float)i+decallagey-(float)((casesMap[j][i].niveaudebatiment==GRATTECIEL)?100:(casesMap[j][i].niveaudebatiment==IMMEUBLE)?40:0)+15, 1);
                                                }
                                            }
                                        } else if(casesMap[j][i].hautgauche){
                                            if(niveauvue==0){
                                                al_draw_bitmap(Batiments[casesMap[j][i].typedeconstruction+3],CASE*(float)j+decallagex, CASE*(float)i+decallagey, 0);
                                            }else{
                                                al_draw_tinted_bitmap(Batiments[casesMap[j][i].typedeconstruction+3],
                                                                      al_map_rgba(100,100,100,40),CASE*(float)j+decallagex, CASE*(float)i+decallagey, 0);
                                            }
                                        }
                                        if(xgodzilla ==j && ygodzilla==i-3){
                                            al_draw_bitmap(Cataclysmes[12+(int)decalanim%4], CASE*xgodzilla+decallagex+((sensattaque)?1:-1)*((((int)compttimer/8)%4*10)-20), CASE*ygodzilla+decallagey-20, sensattaque);
                                        }
                                    }
                                }
                                for (int i = 0; i < 11; ++i) {
                                    if(niveauvue==0){
                                        al_draw_bitmap(Bordure,CASE*5*(float)i+decallagex-200, -200+decallagey, 0);
                                        al_draw_bitmap(Bordure,CASE*5*(float)i+decallagex-200, 1400+decallagey, 0);
                                    }else{
                                        al_draw_tinted_bitmap(Bordure,al_map_rgb(200,165,235),CASE*5*(float)i+decallagex-200, -200+decallagey, 0);
                                        al_draw_tinted_bitmap(Bordure,al_map_rgb(200,165,235),CASE*5*(float)i+decallagex-200, 1400+decallagey, 0);
                                    }

                                }
                                for (int i = 0; i < 7; ++i) {
                                    if(niveauvue==0){
                                        al_draw_bitmap(Bordure,decallagex-200, decallagey+CASE*5*(float)i, 0);
                                        al_draw_bitmap(Bordure,decallagex+1800, decallagey+CASE*5*(float)i, 0);
                                    }else{
                                        al_draw_tinted_bitmap(Bordure,al_map_rgb(200,165,235),decallagex-200, decallagey+CASE*5*(float)i, 0);
                                        al_draw_tinted_bitmap(Bordure,al_map_rgb(200,165,235),decallagex+1800, decallagey+CASE*5*(float)i, 0);
                                    }

                                }



                                //"Viseur"
                                al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x+CASE, Caseselec.y+CASE, al_map_rgba(200, 40, 180, 80));

                                // MiniMap
                                if(niveauvue==0){
                                    al_draw_filled_rectangle(larg-200, 20, larg-20, 160, al_map_rgba(00, 105, 00, 200));
                                }else{
                                    al_draw_filled_rectangle(larg-200, 20, larg-20, 160, al_map_rgba(105, 105, 105, 200));
                                }

                                al_draw_rectangle(larg-200-2, 20-2, larg-20+2, 160+2, al_map_rgba(0, 050, 00, 255),4);
                                for(int i=0; i<45; i++){
                                    for(int j =0; j<35; j++){
                                        switch (casesMap[i][j].typedeconstruction) {
                                            case ROUTE:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(10, 10, 10, 100));
                                                break;
                                            case HABITATION:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(255, 10, 10, 100));
                                                break;
                                            case CENTRALELEC:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(255, 255, 10, 100));
                                                break;
                                            case CHATEAUEAU:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(10, 10, 255, 100));
                                                break;
                                            case CASERNE:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(255, 50, 10, 100));
                                                break;
                                            case POKEDEFENSE:
                                                al_draw_filled_rectangle(larg-200+i*4, 20+j*4, larg-200+(i+1)*4, 20+(j+1)*4, al_map_rgba(10, 205, 10, 100));
                                                break;
                                        }
                                    }
                                }
                                al_draw_filled_rectangle(larg-200+Caseselec.numcolonne*4, 20+Caseselec.numligne*4, larg-200+(Caseselec.numcolonne+1)*4, 20+(Caseselec.numligne+1)*4, al_map_rgba(180, 20, 180, 100));

                                for (int i = 0; i < 3; ++i) {
                                    for (int j = 0; j < 3; ++j) {
                                        if(xgodzilla+i>=0 && xgodzilla+i<=44 && ygodzilla+j>=0 && ygodzilla+j<=44){
                                            al_draw_filled_rectangle(larg-200+(xgodzilla+i)*4, 20+(ygodzilla+j)*4, larg-200+(xgodzilla+i+1)*4, 20+(ygodzilla+j+1)*4, al_map_rgba(0, 0, 0, 100));

                                        }
                                    }
                                }



                                //Affichage et calibration du Chrono
                                int dizaine=chrono;
                                int decallageimage=0;
                                while (dizaine>=1){
                                    dizaine=dizaine/10;
                                    decallageimage++;
                                }
                                al_draw_filled_rectangle(larg/2-17.5*decallageimage+30, 15, larg/2+17.5*decallageimage+40, 60, al_map_rgb(235, 235, 235));
                                al_draw_rectangle(larg/2-17.5*decallageimage+30, 15, larg/2+17.5*decallageimage+40, 60, al_map_rgb(30, 30, 30), 4);
                                al_draw_textf(PressStart35, al_map_rgb(10, 10, 10), larg/2-17.5*decallageimage+35, 20, 0, "%d", (int)chrono);

                                al_draw_filled_rectangle(0, 60, 200, haut-60, al_map_rgb(235, 235, 235));
                                al_draw_rectangle(0, 58, 202, haut-58, al_map_rgb(30, 30, 30), 4);

                                al_draw_text(PressStart15, al_map_rgb(30 , 30, 30), 15, 85, 0, ("Pokedollars: "));
                                dizaine=pokedollars;
                                decallageimage=0;
                                while (dizaine>=1){
                                    dizaine=dizaine/10;
                                    decallageimage++;
                                }
                                al_draw_textf(PressStart20, al_map_rgb(30 , 30, 30), 100-decallageimage*10, 120, 0, ("%d"), pokedollars);

                                al_draw_text(PressStart15, al_map_rgb(30 , 30, 30), 10, 165, 0, ("Nb Habitants:"));
                                dizaine=nbhabitants;
                                decallageimage=0;
                                while (dizaine>=1){
                                    dizaine=dizaine/10;
                                    decallageimage++;
                                }
                                al_draw_textf(PressStart20, al_map_rgb(30 , 30, 30), 100-decallageimage*10, 195, 0, ("%d"), nbhabitants);


                                if(niveauvue==0){
                                    al_draw_bitmap(BoutonMenuJeu[ROUTE], 15, 240, 0);
                                    al_draw_bitmap(BoutonMenuJeu[HABITATION], 105, 240, 0);
                                    al_draw_bitmap(BoutonMenuJeu[CENTRALELEC], 15, 330, 0);
                                    al_draw_bitmap(BoutonMenuJeu[CHATEAUEAU], 105, 330, 0);
                                    al_draw_bitmap(BoutonMenuJeu[CASERNE], 15, 420, 0);
                                    al_draw_bitmap(BoutonMenuJeu[POKEDEFENSE], 105, 420, 0);

                                    al_draw_text(PressStart15, al_map_rgb(30 , 30, 30), 10, 520, 0, ("Achat actuel:"));


                                    if(achat==-1){
                                        al_draw_filled_rectangle(60, 550, 140, 630, al_map_rgb(0, 0, 0));
                                        al_draw_bitmap(BoutonMenuJeu[7], 50, 645, 0);
                                    }else{
                                        al_draw_bitmap(BoutonMenuJeu[achat], 60, 550,0);
                                        al_draw_bitmap(BoutonMenuJeu[8], 50, 645, 0);
                                    }

                                    if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=240-5 && mouse_state.y<=320-5){
                                        al_draw_filled_rectangle(15, 240, 95, 320, al_map_rgba(0, 0, 0,40));
                                    }else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=240-5 && mouse_state.y<=320-5){
                                        al_draw_filled_rectangle(105, 240, 185, 320, al_map_rgba(0, 0, 0,40));
                                    }
                                    else if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=310-5 && mouse_state.y<=410-5){
                                        al_draw_filled_rectangle(15, 330, 95, 410, al_map_rgba(0, 0, 0, 40));
                                    }
                                    else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=310-5 && mouse_state.y<=410-5){
                                        al_draw_filled_rectangle(105, 330, 185, 410, al_map_rgba(0, 0, 0, 40));
                                    }
                                    else if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=420-5 && mouse_state.y<=500-5){
                                        al_draw_filled_rectangle(15, 420, 95, 500, al_map_rgba(0, 0, 0, 40));
                                    }
                                    else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=420-5 && mouse_state.y<=500-5){
                                        al_draw_filled_rectangle(105, 420, 185, 500, al_map_rgba(0, 0, 0, 40));
                                    }else if(mouse_state.x>=50 && mouse_state.x<=150 && mouse_state.y>=645-5 && mouse_state.y<=695-5){
                                        al_draw_filled_rectangle(50, 645, 150, 695, al_map_rgba(0, 0, 0, 40));
                                    }
                                }
                                al_flip_display();
                            }
                            break;

                        case ALLEGRO_EVENT_KEY_DOWN:
                            switch (event.keyboard.keycode) {
                                case ALLEGRO_KEY_ESCAPE:
                                    finpartie = true;
                                    finjeu=true;
                                    break;
                                case ALLEGRO_KEY_E:
                                    if(niveauvue==0){
                                        niveauvue=1;
                                        achat=-1;
                                    }else{
                                        niveauvue=0;
                                    }

                                    break;
                                case ALLEGRO_KEY_A:
                                    if(niveauvue==0){
                                        niveauvue=2;
                                        achat=-1;
                                    }else{
                                        niveauvue=0;
                                    }
                                    break;
                                case ALLEGRO_KEY_F:
                                    fonctionSauvgarde("Sauvegarde1", casesMap, pokedollars, regimepolitique);
                                    break;
                                case ALLEGRO_KEY_G:
                                    fonctionSauvgarde("Sauvegarde2", casesMap, pokedollars, regimepolitique);
                                    break;
                                case ALLEGRO_KEY_H:
                                    fonctionSauvgarde("Sauvegarde3", casesMap, pokedollars, regimepolitique);
                                    break;
                                case ALLEGRO_KEY_J:
                                    fonctionSauvgarde("Sauvegarde4", casesMap, pokedollars, regimepolitique);
                                    break;

                            }
                            break;
                        case ALLEGRO_EVENT_MOUSE_AXES:
                            al_get_mouse_state(&mouse_state);
                            calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut, &menujeu);
                            break;

                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                            al_get_mouse_state(&mouse_state);

                            if(menujeu && niveauvue==0){
                                if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=240-5 && mouse_state.y<=320-5){
                                    achat=ROUTE;
                                }else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=240-5 && mouse_state.y<=320-5){
                                    achat=HABITATION;
                                }
                                else if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=310-5 && mouse_state.y<=410-5){
                                    achat=CENTRALELEC;
                                }
                                else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=310-5 && mouse_state.y<=410-5){
                                    achat=CHATEAUEAU;
                                }
                                else if(mouse_state.x>=15 && mouse_state.x<=95 && mouse_state.y>=420-5 && mouse_state.y<=500-5){
                                    achat=CASERNE;
                                }
                                else if(mouse_state.x>=105 && mouse_state.x<=185 && mouse_state.y>=420-5 && mouse_state.y<=500-5){
                                    achat=POKEDEFENSE;
                                }else if(mouse_state.x>=50 && mouse_state.x<=150 && mouse_state.y>=645-5 && mouse_state.y<=695-5){
                                    if(achat!=-1){
                                        achat=-1;
                                    }else{
                                        decalanim=1;
                                        /*finpartie = true;
                                        finmenu =false;
                                        lieumenu=DEMARRAGE;
                                        etatjeu=MENUPRINCIPAL;*/
                                    }
                                }
                            }else if (achat!=(-1)&&niveauvue==0){

                                if(achat==ROUTE) {
                                    if(Caseselec.numcolonne<45&&casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==AUCUNE &&pokedollars>=10 ) {
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction=ROUTE;
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].sapin=false;
                                        pokedollars-=10;

                                    }else if(Caseselec.numcolonne<45&&casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==ROUTE){
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction=AUCUNE;
                                    }
                                }else {

                                    if(Caseselec.numcolonne<45&& (casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==AUCUNE ||   casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==ROUTE)){
                                        bool batimentendessous = false;
                                        int imax;
                                        int jmax;
                                        switch (achat) {
                                            case HABITATION:
                                                imax=3;
                                                jmax=3;
                                                break;
                                            case CENTRALELEC:
                                            case CASERNE:
                                                imax=6;
                                                jmax=4;
                                                break;
                                            case CHATEAUEAU:
                                            case POKEDEFENSE:
                                                imax=4;
                                                jmax=6;
                                                break;
                                        }
                                        for (int i = 0; i < imax; ++i) {
                                            for (int j = 0; j < jmax; ++j) {
                                                if(Caseselec.numcolonne+i>44||Caseselec.numligne+j>34){
                                                    batimentendessous=true;
                                                }else{
                                                    if( casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].typedeconstruction!=ROUTE && casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].typedeconstruction!=AUCUNE){
                                                        batimentendessous=true;
                                                    }
                                                }
                                            }
                                        }
                                        if(!batimentendessous){
                                            switch (achat) {
                                                case HABITATION:
                                                    if(pokedollars>=1000){
                                                        pokedollars-=1000;
                                                    }else{
                                                        batimentendessous=true;
                                                    }
                                                    break;
                                                case CENTRALELEC:
                                                case CHATEAUEAU:
                                                    if(pokedollars>=100000){
                                                        pokedollars-=100000;
                                                    }else{
                                                        batimentendessous=true;
                                                    }
                                                    break;
                                                case CASERNE:
                                                case POKEDEFENSE:
                                                    if(pokedollars>=10000){
                                                        pokedollars-=10000;
                                                    }else{
                                                        batimentendessous=true;
                                                    }
                                                    break;
                                            }
                                        }
                                        if(!batimentendessous){
                                            nombrebatiment++;
                                            for (int i = 0; i < imax; ++i) {
                                                for (int j = 0; j < jmax; ++j) {
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].hautgauche=false;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].numerobatiment=nombrebatiment;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].typedeconstruction=achat;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].niveaudebatiment=TERRAINVAGUE;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].sapin=false;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].nombrehabitants=0;
                                                }
                                            }
                                            casesMap[Caseselec.numcolonne][Caseselec.numligne].hautgauche=true;


                                        }
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






void calculcaseselec(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey, float haut, bool* menujeu){
    al_get_mouse_state(mouse_state);
    bool unfined=true;
    if(mouse_state->x>=0&&mouse_state->x<=200&&mouse_state->y>=60&&mouse_state->y<=haut-60){
        *menujeu=true;
    }else{
        *menujeu=false;
        for (int i =0; i<45; i++){
            if((float)mouse_state->x>=(float)i*CASE+decallagex&&(float)mouse_state->x<=(float)(i+1)*CASE+decallagex){
                for (int j=0; j<35; j++){
                    if((float)mouse_state->y>=(float)j*CASE+decallagey&&(float)mouse_state->y<=(float)(j+1)*CASE+decallagey){
                        Caseselec->x = (float) i*CASE + (float) ((int) (decallagex) ) ;
                        Caseselec->y = (float) j*CASE + (float) ((int) (decallagey) );
                        Caseselec->numcolonne=i;
                        Caseselec->numligne=j;
                        unfined=false;
                    }
                }
            }
        }
    }
    if(unfined){
        Caseselec->x = (float) 2000*CASE + (float) ((int) (decallagex) ) ;
        Caseselec->y = (float) 2000*CASE + (float) ((int) (decallagey) ) ;
        Caseselec->numcolonne=2000;
        Caseselec->numligne=2000;
    }

}