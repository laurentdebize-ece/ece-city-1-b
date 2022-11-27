//
// Created by gabdu on 02/11/2022.
#include "Gabriel.h"
#include "Matthieu.h"
#include "Leopold.h"
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
    ALLEGRO_BITMAP* Cataclysmes[31]={
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
            {al_load_bitmap("../Cataclysmes/GodzillaLazer1.PNG")},
            {al_load_bitmap("../Cataclysmes/GodzillaLazer2.PNG")},
            {al_load_bitmap("../Cataclysmes/GodzillaLazer3.PNG")},
            {al_load_bitmap("../Cataclysmes/Missile1.PNG")},
            {al_load_bitmap("../Cataclysmes/Missile2.PNG")},
            {al_load_bitmap("../Cataclysmes/Missile3.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion1.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion2.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion3.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion4.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion5.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion6.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion7.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion8.PNG")},
            {al_load_bitmap("../Cataclysmes/Explosion9.PNG")},
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
    ALLEGRO_BITMAP* RampageLogo=al_load_bitmap("../Cataclysmes/RampageLogo.PNG");
    ALLEGRO_BITMAP *Pompiercote=al_load_bitmap("../ImagesAnae/Camionpompiercote.PNG");
    ALLEGRO_BITMAP *Pompierhaut=al_load_bitmap("../ImagesAnae/Camionpompierhaut.PNG");
    ALLEGRO_BITMAP *Pompierbas=al_load_bitmap("../ImagesAnae/Camionpompierbas.PNG");



    //***************INITIALISATION DES VARIABLES ET DES STRUCUTRES*****************

    bool finpartie=false;
    bool finjeu=false;
    bool finmenu=false;

    int statsapin=53;
    bool debutforet;

    int etatjeu= PARTIE;

    int lieumenu=DEMARRAGE;
    int regimepolitique=CAPITALISTE;
    int sauvegardechoisie=0;
    int blabla=1;



    bool menujeu=false;
    bool animation=true;
    bool animinverse=false;
    float decalanim=1;

    long long compttimer=0;
    long long chrono=1;
    int nombrebatiment=0;
    int numerohabitation=0;
    float decallagex=0;
    float decallagey=0;
    int pokedollars=500000;
    int achat=-1;
    int nbhabitants=0;
    int niveauvue=0;
    int nombreroutes=0;

    bool attaquegodzilla=false;
    bool sensattaque=false;
    int xgodzilla=-50;
    int ygodzilla=-50;
    float xmissile=0;
    float ymissile=0;
    float ymissilesave=0;
    int avancementmissile=0;
    bool missileencours=false;
    bool missilemontant=false;
    float anglecible=-3.1415/2;
    bool lazergodzilla=false;
    bool explosion=false;
    int probaattaque=5;

    bool confirmationsauvegarde=false;
    bool confirmationquitter=false;

    bool pause=false;

    int xcamion=0;
    int ycamion=0;
    int sensCamion=0;
    int orientationcamion=0;
    bool camionpresent=false;




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
            casesMap[i][j].niveauEau=0;
            casesMap[i][j].niveauElec=0;


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
                                            sauvegardechoisie=0;
                                        }else if(mouse_state.x>=larg/2-200 && mouse_state.x<=larg/2+200 && mouse_state.y>=haut/2+54-5 && mouse_state.y <=haut/2+220-5){
                                            finpartie = false;
                                            finmenu=true;
                                            etatjeu=PARTIE;
                                            regimepolitique=CAPITALISTE;
                                            compttimer=0;
                                            sauvegardechoisie=0;
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
                            fonctionrecuperationSauvegarde("Sauvegarde1", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 2:
                            fonctionrecuperationSauvegarde("Sauvegarde2", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 3:
                            fonctionrecuperationSauvegarde("Sauvegarde3", casesMap, &pokedollars, &regimepolitique);
                            break;
                        case 4:
                            fonctionrecuperationSauvegarde("Sauvegarde4", casesMap, &pokedollars, &regimepolitique);
                            break;
                    }
                    numerohabitation=0;
                    for (int i = 0; i < 45; ++i) {
                        for (int j = 0; j < 35; ++j) {
                            if(casesMap[i][j].hautgauche){
                                if(casesMap[i][j].typedeconstruction==HABITATION){
                                    numerohabitation++;
                                    casesMap[i][j].numerohabitation=numerohabitation;
                                }
                                if(casesMap[i][j].typedeconstruction==ROUTE){
                                    nombreroutes++;
                                }
                                nbhabitants+=casesMap[i][j].nombrehabitants;
                                nombrebatiment++;
                            }
                        }
                    }
                }else{
                    compttimer=0;
                    chrono=1;
                    nombrebatiment=0;
                    numerohabitation=0;
                    decallagex=0;
                    decallagey=0;
                    pokedollars=500000;
                    achat=-1;
                    nbhabitants=0;
                    niveauvue=0;
                    Caseselec.x=0;
                    Caseselec.y=0;
                    Caseselec.numcolonne=0;
                    Caseselec.numligne=0;
                    for (int i = 0; i < 45; ++i) {
                        for (int j = 0; j < 35; ++j) {
                            casesMap[i][j].sapin=false;
                            casesMap[i][j].niveaudebatiment=0;
                            casesMap[i][j].numerobatiment=-1;
                            casesMap[i][j].typedeconstruction=AUCUNE;
                            casesMap[i][j].hautgauche=false;
                            casesMap[i][j].nombrehabitants=0;
                            casesMap[i][j].incendie=false;
                            casesMap[i][j].niveauElec=0;
                            casesMap[i][j].niveauEau=0;
                        }
                    }
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
                }
                attaquegodzilla=false;
                sensattaque=false;
                xgodzilla=-50;
                ygodzilla=-50;
                xmissile=0;
                ymissile=0;
                ymissilesave=0;
                avancementmissile=0;
                missileencours=false;
                missilemontant=false;
                anglecible=-3.1415/2;
                lazergodzilla=false;
                explosion=false;
                probaattaque=5;




                while (!finpartie){
                    ALLEGRO_EVENT event = {0};
                    al_wait_for_event(queue, &event);
                    switch (event.type) {

                        case ALLEGRO_EVENT_TIMER:

                            compttimer += 1;
                            if(!confirmationsauvegarde && !pause && !confirmationquitter) {
                                if (compttimer % 100 == 0) {
                                    chrono++;
                                    if (chrono % 5 == 0){
                                        for (int i = 0; i < 45; ++i) {
                                            for (int j = 0; j < 35; ++j) {
                                                if(casesMap[i][j].hautgauche&&casesMap[i][j].incendie&&casesMap[i][j].protegedufeu){
                                                    casesMap[i][j].incendie=false;
                                                }
                                            }
                                        }
                                    }
                                    if (chrono % 15 == 0) {
                                        for (int i = 0; i < 45; ++i) {
                                            for (int j = 0; j < 35; ++j) {
                                                if (casesMap[i][j].typedeconstruction == HABITATION) {
                                                    bool evolutionpossible=true;
                                                    if(regimepolitique==COMMUNISTE){
                                                        if(casesMap[i][j].CentralElecAssoc==-1 || casesMap[i][j].ChateauEauAssoc==-1){
                                                            evolutionpossible=false;
                                                        }else{
                                                            int seuil;
                                                            switch (casesMap[i][j].typedeconstruction) {
                                                                case RUINES:
                                                                case TERRAINVAGUE:
                                                                    seuil=10;
                                                                    break;
                                                                case CABANE:
                                                                    seuil=50;
                                                                    break;
                                                                case MAISON:
                                                                    seuil=100;
                                                                    break;
                                                                case IMMEUBLE:
                                                                    seuil=1000;
                                                                    break;
                                                            }
                                                            for (int k = 0; k < 45; ++k) {
                                                                for (int l = 0; l < 35; ++l) {
                                                                    if(casesMap[k][l].hautgauche  &&casesMap[i][j].CentralElecAssoc== casesMap[k][l].numerobatiment){
                                                                        if(casesMap[k][l].niveauElec< seuil ){
                                                                            evolutionpossible=false;
                                                                        }
                                                                    }
                                                                    if(casesMap[k][l].hautgauche  &&casesMap[i][j].ChateauEauAssoc== casesMap[k][l].numerobatiment){
                                                                        if(casesMap[k][l].niveauEau< seuil ){
                                                                            evolutionpossible=false;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                    }else if(regimepolitique==CAPITALISTE){
                                                        if((casesMap[i][j].ChateauEauAssoc==-1 || casesMap[i][j].CentralElecAssoc==-1)){
                                                            evolutionpossible=false;
                                                        }else if(casesMap[i][j].hautgauche&& casesMap[i][j].nombrehabitants!=0&& ((casesMap[i][j].niveauEau<casesMap[i][j].nombrehabitants || casesMap[i][j].niveauElec<casesMap[i][j].nombrehabitants))){
                                                            evolutionpossible=false;
                                                        }

                                                    }
                                                    if(evolutionpossible){
                                                        if (casesMap[i][j].niveaudebatiment < GRATTECIEL) {
                                                            casesMap[i][j].niveaudebatiment++;
                                                            if (casesMap[i][j].niveaudebatiment == TERRAINVAGUE) {
                                                                casesMap[i][j].niveaudebatiment++;
                                                            }
                                                            if (casesMap[i][j].hautgauche) {
                                                                switch (casesMap[i][j].niveaudebatiment) {
                                                                    case TERRAINVAGUE:
                                                                        nbhabitants += 0;
                                                                        casesMap[i][j].nombrehabitants = 0;
                                                                        break;
                                                                    case CABANE:
                                                                        nbhabitants += 10;
                                                                        casesMap[i][j].nombrehabitants = 10;
                                                                        break;
                                                                    case MAISON:
                                                                        nbhabitants += 40;
                                                                        casesMap[i][j].nombrehabitants = 50;
                                                                        break;
                                                                    case IMMEUBLE:
                                                                        nbhabitants += 50;
                                                                        casesMap[i][j].nombrehabitants = 100;
                                                                        break;
                                                                    case GRATTECIEL:
                                                                        nbhabitants += 900;
                                                                        casesMap[i][j].nombrehabitants = 1000;
                                                                        break;
                                                                }
                                                            }
                                                        }
                                                    }else if (casesMap[i][j].hautgauche&& (casesMap[i][j].niveauEau<casesMap[i][j].nombrehabitants || casesMap[i][j].niveauElec<casesMap[i][j].nombrehabitants)){
                                                        int sommeeau=0;
                                                        int sommeelec=0;
                                                        for (int k = 0; k < 45; ++k) {
                                                            for (int l = 0; l < 35; ++l) {
                                                                if(casesMap[k][l].hautgauche&& casesMap[i][j].ChateauEauAssoc==casesMap[k][l].ChateauEauAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].ChateauEauAssoc){
                                                                    sommeeau+=casesMap[k][l].niveauEau;
                                                                }
                                                                if(casesMap[k][l].hautgauche&& casesMap[i][j].CentralElecAssoc==casesMap[k][l].CentralElecAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].CentralElecAssoc){
                                                                    sommeelec+=casesMap[k][l].niveauElec;
                                                                }
                                                            }
                                                        }
                                                        sommeeau=0;
                                                        sommeelec=0;
                                                        if(casesMap[i][j].niveauEau>=casesMap[i][j].nombrehabitants && casesMap[i][j].niveauElec+sommeelec>=casesMap[i][j].nombrehabitants){
                                                            for (int k = 0; k < 45; ++k) {
                                                                for (int l = 0; l < 35; ++l) {
                                                                    if(casesMap[k][l].hautgauche&& casesMap[i][j].CentralElecAssoc==casesMap[k][l].CentralElecAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].niveaudebatiment){
                                                                        sommeelec+=casesMap[k][l].niveauElec;
                                                                        nbhabitants -= casesMap[k][l].nombrehabitants;
                                                                        casesMap[k][l].nombrehabitants = 0;
                                                                        casesMap[k][l].niveaudebatiment=0;
                                                                        for (int m = 0; m < 3; ++m) {
                                                                            for (int n = 0; n < 3; ++n) {
                                                                                casesMap[k+m][l+n].niveaudebatiment=0;
                                                                            }
                                                                        }
                                                                    }
                                                                    if(casesMap[i][j].niveauElec+sommeelec>=casesMap[i][j].nombrehabitants){
                                                                        k=45;
                                                                        l=35;
                                                                    }
                                                                }
                                                            }
                                                        } else if(casesMap[i][j].niveauElec>=casesMap[i][j].nombrehabitants && casesMap[i][j].niveauEau+sommeeau>=casesMap[i][j].nombrehabitants){
                                                            for (int k = 0; k < 45; ++k) {
                                                                for (int l = 0; l < 35; ++l) {
                                                                    if(casesMap[k][l].hautgauche&& casesMap[i][j].ChateauEauAssoc==casesMap[k][l].ChateauEauAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].niveaudebatiment){
                                                                        sommeeau+=casesMap[k][l].niveauEau;
                                                                        nbhabitants -= casesMap[k][l].nombrehabitants;
                                                                        casesMap[k][l].nombrehabitants = 0;
                                                                        casesMap[k][l].niveaudebatiment=0;
                                                                        for (int m = 0; m < 3; ++m) {
                                                                            for (int n = 0; n < 3; ++n) {
                                                                                casesMap[k+m][l+n].niveaudebatiment=0;
                                                                            }
                                                                        }
                                                                    }
                                                                    if(casesMap[i][j].niveauEau+sommeeau>=casesMap[i][j].nombrehabitants){
                                                                        k=45;
                                                                        l=35;
                                                                    }
                                                                }
                                                            }
                                                        }else if(casesMap[i][j].niveauEau+sommeeau>=casesMap[i][j].nombrehabitants && casesMap[i][j].niveauElec+sommeelec>=casesMap[i][j].nombrehabitants){

                                                            for (int k = 0; k < 45; ++k) {
                                                                for (int l = 0; l < 35; ++l) {
                                                                    if(casesMap[k][l].hautgauche&& casesMap[i][j].ChateauEauAssoc==casesMap[k][l].ChateauEauAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].niveaudebatiment){
                                                                        sommeeau+=casesMap[k][l].niveauEau;
                                                                        nbhabitants -= casesMap[k][l].nombrehabitants;
                                                                        casesMap[k][l].nombrehabitants = 0;
                                                                        casesMap[k][l].niveaudebatiment=0;
                                                                        for (int m = 0; m < 3; ++m) {
                                                                            for (int n = 0; n < 3; ++n) {
                                                                                casesMap[k+m][l+n].niveaudebatiment=0;
                                                                            }
                                                                        }
                                                                    }
                                                                    if(casesMap[k][l].hautgauche&& casesMap[i][j].CentralElecAssoc==casesMap[k][l].CentralElecAssoc && casesMap[k][l].niveaudebatiment<casesMap[i][j].niveaudebatiment){
                                                                        sommeelec+=casesMap[k][l].niveauElec;
                                                                        nbhabitants -= casesMap[k][l].nombrehabitants;
                                                                        casesMap[k][l].nombrehabitants = 0;
                                                                        casesMap[k][l].niveaudebatiment=0;
                                                                        for (int m = 0; m < 3; ++m) {
                                                                            for (int n = 0; n < 3; ++n) {
                                                                                casesMap[k+m][l+n].niveaudebatiment=0;
                                                                            }
                                                                        }
                                                                    }
                                                                    if(casesMap[i][j].niveauEau+sommeeau>=casesMap[i][j].nombrehabitants && casesMap[i][j].niveauElec+sommeelec>=casesMap[i][j].nombrehabitants){
                                                                        k=45;
                                                                        l=35;
                                                                    }
                                                                }
                                                            }
                                                        }else{
                                                            switch (casesMap[i][j].niveaudebatiment) {
                                                                case CABANE:
                                                                    nbhabitants -= 10;
                                                                    casesMap[i][j].nombrehabitants = 0;
                                                                    casesMap[i][j].niveaudebatiment=0;
                                                                    break;
                                                                case MAISON:
                                                                    nbhabitants -= 40;
                                                                    casesMap[i][j].nombrehabitants = 10;
                                                                    casesMap[i][j].niveaudebatiment--;
                                                                    break;
                                                                case IMMEUBLE:
                                                                    nbhabitants -= 50;
                                                                    casesMap[i][j].nombrehabitants = 50;
                                                                    casesMap[i][j].niveaudebatiment--;
                                                                    break;
                                                                case GRATTECIEL:
                                                                    nbhabitants -= 900;
                                                                    casesMap[i][j].nombrehabitants = 100;
                                                                    casesMap[i][j].niveaudebatiment--;
                                                                    break;
                                                            }
                                                            for (int k = 0; k < 3; ++k) {
                                                                for (int l = 0; l < 3; ++l) {
                                                                    if(l!=0 && k!=0){
                                                                        if(casesMap[i+k][j+l].niveaudebatiment>=MAISON){
                                                                            casesMap[i+k][j+l].niveaudebatiment--;
                                                                        }else{
                                                                            casesMap[i+k][j].niveaudebatiment=RUINES;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (casesMap[i][j].incendie) {
                                                        casesMap[i][j].niveaudebatiment = RUINES;
                                                        if (casesMap[i][j].hautgauche) {
                                                            nbhabitants -= casesMap[i][j].nombrehabitants;
                                                            casesMap[i][j].nombrehabitants = 0;
                                                        }
                                                        casesMap[i][j].incendie = false;
                                                    }
                                                    if (!casesMap[i][j].incendie &&
                                                        casesMap[i][j].nombrehabitants != 0 && rand() % 20 == 0) {
                                                        casesMap[i][j].incendie = true;
                                                    }
                                                }
                                                if (casesMap[i][j].hautgauche) {
                                                    pokedollars += casesMap[i][j].nombrehabitants * 10;
                                                }
                                            }
                                        }
                                        if (rand() % probaattaque == 0 && !attaquegodzilla) {
                                            attaquegodzilla = true;
                                            bool positionnonvalide=true;
                                            while(positionnonvalide){
                                                positionnonvalide=false;
                                                ygodzilla = 1 + rand() % 31;
                                                for (int i = 0; i < 45; ++i) {
                                                    for (int j = 0; j < 35; ++j) {
                                                        if(casesMap[i][j].hautgauche&&casesMap[i][j].typedeconstruction==POKEDEFENSE&& j==ygodzilla){
                                                            positionnonvalide=true;
                                                        }
                                                    }
                                                }
                                            }
                                            if (rand() % 2 == 0) {
                                                xgodzilla = 45;
                                                sensattaque = false;
                                            } else {
                                                xgodzilla = -3;
                                                sensattaque = true;
                                            }
                                            for (int i = 0; i < 45; ++i) {
                                                for (int j = 0; j < 35; ++j) {
                                                    if (casesMap[i][j].hautgauche &&
                                                        casesMap[i][j].typedeconstruction == POKEDEFENSE) {
                                                        missileencours = true;
                                                        missilemontant = true;
                                                        xmissile = (i + 2) * CASE - 44;
                                                        ymissile = (j + 3) * CASE + 10;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            if (compttimer % 8 == 0) {

                                if(!confirmationsauvegarde && !pause && !confirmationquitter) {

                                    al_get_keyboard_state(&keyboard_state);
                                    if (al_key_down(&keyboard_state, ALLEGRO_KEY_S)) {
                                        if (decallagey > (-(1600 - haut))) {
                                            decallagey -= 40;
                                        } else if (decallagey > (-(1640 - larg))) {
                                            decallagey = -(1640 - haut);
                                        }
                                        calculcaseselec(&mouse_state, &Caseselec, decallagex, decallagey, haut, larg,
                                                        &menujeu);
                                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Q)) {
                                        if (decallagex < 160) {
                                            decallagex += 40;
                                        } else if (decallagex < 200) {
                                            decallagex = 200;
                                        }
                                        calculcaseselec(&mouse_state, &Caseselec, decallagex, decallagey, haut, larg,
                                                        &menujeu);
                                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_D)) {
                                        if (decallagex > (-(1960 - larg))) {
                                            decallagex -= 40;
                                        } else if (decallagex > (-(2000 - larg))) {
                                            decallagex = -(2000 - larg);
                                        }
                                        calculcaseselec(&mouse_state, &Caseselec, decallagex, decallagey, haut, larg,
                                                        &menujeu);
                                    } else if (al_key_down(&keyboard_state, ALLEGRO_KEY_Z)) {
                                        if (decallagey < 160) {
                                            decallagey += 40;
                                        } else if (decallagex < 200) {
                                            decallagey = 200;
                                        }
                                        calculcaseselec(&mouse_state, &Caseselec, decallagex, decallagey, haut, larg,
                                                        &menujeu);
                                    }


                                    if (attaquegodzilla && compttimer % 64 == 0) {
                                        if (!missileencours && !explosion) {
                                            for (int i = 0; i < 45; ++i) {
                                                for (int j = 0; j < 35; ++j) {
                                                    if (casesMap[i][j].hautgauche &&
                                                        casesMap[i][j].typedeconstruction == POKEDEFENSE) {
                                                        missileencours = true;
                                                        missilemontant = true;
                                                        xmissile = (i + 2) * CASE - 44;
                                                        ymissile = (j + 3) * CASE + 10;
                                                    }
                                                }
                                            }
                                        }
                                        lazergodzilla = false;
                                        if (sensattaque == false) {
                                            xgodzilla--;
                                            if (xgodzilla <= -5) {
                                                attaquegodzilla = false;
                                            }
                                            for (int i = 0; i < 3; ++i) {
                                                if (xgodzilla >= 0 && xgodzilla <= 44 && ygodzilla + i <= 34 &&ygodzilla + i >= 0) {
                                                    if (casesMap[xgodzilla][ygodzilla + i].sapin) {
                                                        casesMap[xgodzilla][ygodzilla + i].sapin = false;
                                                        lazergodzilla = true;
                                                    }


                                                    if (casesMap[xgodzilla][ygodzilla + i].typedeconstruction !=AUCUNE &&casesMap[xgodzilla][ygodzilla + i].typedeconstruction !=ROUTE) {

                                                        int tempnumerobatiment=casesMap[xgodzilla][ygodzilla + i].numerobatiment;
                                                        int tempnumerohabitation= casesMap[xgodzilla][ygodzilla + i].numerohabitation;

                                                        nombrebatiment--;
                                                        if(casesMap[xgodzilla][ygodzilla + i].typedeconstruction ==HABITATION){
                                                            numerohabitation--;
                                                        }
                                                        for (int j = 0; j < 45; ++j) {
                                                            for (int k = 0; k < 35; ++k) {

                                                                if (tempnumerobatiment ==casesMap[j][k].numerobatiment) {
                                                                    if (casesMap[j][k].hautgauche) {
                                                                        nbhabitants -= casesMap[j][k].nombrehabitants;
                                                                    }
                                                                    casesMap[j][k].numerobatiment=-1;
                                                                    casesMap[j][k].numerohabitation=-1;
                                                                    casesMap[j][k].typedeconstruction = AUCUNE;
                                                                    casesMap[j][k].hautgauche = false;
                                                                    casesMap[j][k].nombrehabitants = 0;
                                                                    lazergodzilla = true;
                                                                }
                                                                if(casesMap[j][k].numerobatiment>tempnumerobatiment){
                                                                    casesMap[j][k].numerobatiment--;
                                                                }
                                                                if(casesMap[j][k].typedeconstruction ==HABITATION && casesMap[j][k].numerohabitation>tempnumerohabitation){
                                                                    casesMap[j][k].numerohabitation--;
                                                                }

                                                            }
                                                        }

                                                    } else if (casesMap[xgodzilla][ygodzilla + i].typedeconstruction ==ROUTE) {
                                                        casesMap[xgodzilla][ygodzilla + i].typedeconstruction = AUCUNE;
                                                        nombreroutes--;
                                                        lazergodzilla = true;
                                                    }
                                                }
                                            }
                                        } else {
                                            xgodzilla++;
                                            if (xgodzilla >= 50) {
                                                attaquegodzilla = false;
                                            }
                                            for (int i = 0; i < 3; ++i) {
                                                if (xgodzilla + 2 <= 44 && xgodzilla + 2 >= 0 && ygodzilla + i >= 0 &&ygodzilla + i <= 34) {
                                                    if (casesMap[xgodzilla + 2][ygodzilla + i].sapin) {
                                                        casesMap[xgodzilla + 2][ygodzilla + i].sapin = false;
                                                        lazergodzilla = true;
                                                    }
                                                    if (casesMap[xgodzilla + 2][ygodzilla + i].typedeconstruction !=AUCUNE &&casesMap[xgodzilla + 2][ygodzilla + i].typedeconstruction !=ROUTE) {
                                                        int tempnumerobatiment=casesMap[xgodzilla+2][ygodzilla + i].numerobatiment;
                                                        int tempnumerohabitation= casesMap[xgodzilla+2][ygodzilla + i].numerohabitation;

                                                        nombrebatiment--;
                                                        if(casesMap[xgodzilla+2][ygodzilla + i].typedeconstruction ==HABITATION){
                                                            numerohabitation--;
                                                        }
                                                        for (int j = 0; j < 45; ++j) {
                                                            for (int k = 0; k < 35; ++k) {
                                                                if (tempnumerobatiment ==casesMap[j][k].numerobatiment) {
                                                                    if (casesMap[j][k].hautgauche) {
                                                                        nbhabitants -= casesMap[j][k].nombrehabitants;
                                                                    }
                                                                    casesMap[j][k].numerobatiment=-1;
                                                                    casesMap[j][k].numerohabitation=-1;
                                                                    casesMap[j][k].typedeconstruction = AUCUNE;
                                                                    casesMap[j][k].hautgauche = false;
                                                                    casesMap[j][k].nombrehabitants = 0;
                                                                    lazergodzilla = true;
                                                                }
                                                                if(casesMap[j][k].numerobatiment>tempnumerobatiment){
                                                                    casesMap[j][k].numerobatiment--;
                                                                }
                                                                if(casesMap[j][k].typedeconstruction ==HABITATION && casesMap[j][k].numerohabitation>tempnumerohabitation){
                                                                    casesMap[j][k].numerohabitation--;
                                                                }
                                                            }
                                                        }
                                                    } else if (casesMap[xgodzilla + 2][ygodzilla + i].typedeconstruction ==ROUTE) {
                                                        casesMap[xgodzilla + 2][ygodzilla +i].typedeconstruction = AUCUNE;
                                                        nombreroutes--;
                                                        lazergodzilla = true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (attaquegodzilla && compttimer % 16 == 0) {
                                        decalanim++;
                                    }
                                    if (missilemontant && compttimer % 8 == 0) {
                                        avancementmissile++;
                                        if (avancementmissile == 10) {
                                            ymissilesave = ymissile;
                                        }
                                        if (avancementmissile > 10) {
                                            ymissile -= 8;
                                            if (sensattaque) {
                                                //Gauche
                                                if (ygodzilla * CASE + 64 < ymissilesave) {
                                                    anglecible -= (+3.1415 / 2 -(-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) +3.1415 / 2)) / 9;
                                                } else {
                                                    anglecible += ((-3.1415 / 2 +(-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) -3.1415 / 2))) / 9;
                                                }
                                            } else {
                                                if (ygodzilla * CASE + 64 < ymissilesave) {
                                                    anglecible -= (+3.1415 / 2 -(-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) +3.1415 / 2)) / 9;
                                                } else {
                                                    anglecible -= (-3.1415 / 2 -(-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) +3.1415 / 2)) / 9;
                                                }
                                            }
                                        } else {
                                            ymissile -= 8;
                                        }
                                        if (avancementmissile == 20) {
                                            avancementmissile = 0;
                                            missilemontant = false;
                                            anglecible = -3.1415 / 2;
                                        }

                                    } else if (missileencours && compttimer % 8 == 0) {
                                        avancementmissile++;
                                        xmissile +=
                                                ((float) xgodzilla * CASE + 64 - xmissile) / (43 - avancementmissile);
                                        ymissile +=
                                                ((float) ygodzilla * CASE + 64 - ymissile) / (43 - avancementmissile);
                                        if (avancementmissile == 36) {
                                            explosion = true;
                                        }
                                        if (avancementmissile == 40) {
                                            attaquegodzilla = false;
                                            missileencours = false;

                                        }
                                    }
                                    if (avancementmissile >= 40) {
                                        avancementmissile++;
                                        if (avancementmissile >= 44) {
                                            explosion = false;
                                            avancementmissile = 0;
                                            decalanim = 0;
                                            xgodzilla = -5;

                                        }
                                    }
                                    for (int i = 0; i < 45; ++i) {
                                        for (int j = 0; j < 35; ++j) {
                                            casesMap[i][j].protegedufeu=false;
                                        }
                                    }
                                    BFSCaserne(&casesMap);
                                    BFS(&casesMap, 0);
                                    BFS(&casesMap, 1);

                                    /// Chemin du Camion
                                    if(camionpresent && compttimer%16==0){
                                        bool DroiteCamion=false, GaucheCamion=false, HautCamion=false, BasCamion=false;
                                        int sensChoisi=0;
                                        int optionFinal=-1;
                                        if (xcamion+1<=44 && casesMap[xcamion+1][ycamion].typedeconstruction==ROUTE){
                                            DroiteCamion=true;
                                            orientationcamion=0;
                                        }
                                        if (ycamion+1<=34 && casesMap[xcamion][ycamion+1].typedeconstruction==ROUTE){
                                            BasCamion=true;
                                        }
                                        if ( xcamion-1>=0 && casesMap[xcamion-1][ycamion].typedeconstruction==ROUTE){
                                            GaucheCamion=true;
                                            orientationcamion=ALLEGRO_FLIP_HORIZONTAL;
                                        }
                                        if (ycamion-1>=0 && casesMap[xcamion][ycamion-1].typedeconstruction==ROUTE){
                                            HautCamion=true;
                                        }
                                        int optionsCamion = DroiteCamion + GaucheCamion + HautCamion + BasCamion;
                                        if(optionsCamion>1){
                                            switch (sensCamion) {
                                                case 0:
                                                    BasCamion=false;
                                                    break;
                                                case 1:
                                                    HautCamion=false;
                                                    break;
                                                case 2:
                                                    DroiteCamion=false;
                                                    break;
                                                case 3:
                                                    GaucheCamion=false;
                                                    break;
                                            }
                                            optionsCamion--;
                                        }
                                        /// Pour choix de la route au hasard
                                        if(optionsCamion!=0){
                                            orientationcamion=1;
                                            sensChoisi = rand() % optionsCamion;
                                        }else{
                                            orientationcamion=0;
                                        }

                                        int taboption[4] = {HautCamion , BasCamion , GaucheCamion , DroiteCamion};
                                        int compteurCamion=0;
                                        for (int i = 0; i < 4; ++i) {
                                            if(taboption[i]==true){

                                                if (sensChoisi == compteurCamion){
                                                    optionFinal=i;
                                                }
                                                compteurCamion++;
                                            }
                                        }
                                        switch(optionFinal){
                                            case -1:
                                                break;
                                            case 0:
                                                ycamion--;
                                                break;
                                            case 1:
                                                ycamion++;
                                                break;
                                            case 2:
                                                xcamion--;
                                                break;
                                            case 3:
                                                xcamion++;
                                                break;
                                        }
                                        sensCamion=optionFinal;
                                    }


                                    al_clear_to_color(al_map_rgb(0, 0, 0));

                                    for (int i = 0; i < 11; ++i) {
                                        if (niveauvue == 0) {
                                            al_draw_bitmap(Bordure, CASE * 5 * (float) i + decallagex - 200,
                                                           -200 + decallagey, 0);
                                            al_draw_bitmap(Bordure, CASE * 5 * (float) i + decallagex - 200,
                                                           1400 + decallagey, 0);
                                        } else {
                                            al_draw_tinted_bitmap(Bordure, al_map_rgb(200, 165, 235),
                                                                  CASE * 5 * (float) i + decallagex - 200,
                                                                  -200 + decallagey, 0);
                                            al_draw_tinted_bitmap(Bordure, al_map_rgb(200, 165, 235),
                                                                  CASE * 5 * (float) i + decallagex - 200,
                                                                  1400 + decallagey, 0);
                                        }

                                    }


                                    for (int i = 0; i < 45; ++i) {
                                        for (int j = 0; j < 35; j++) {
                                            int typederoute = 0;
                                            if (casesMap[i][j].typedeconstruction != ROUTE) {
                                                typederoute = 0;
                                            } else if (casesMap[i][j].typedeconstruction != AUCUNE) {
                                                if ((j - 1 >= 0) && casesMap[i][j - 1].typedeconstruction != AUCUNE) {
                                                    if ((j + 1 <= 34) &&
                                                        casesMap[i][j + 1].typedeconstruction != AUCUNE) {
                                                        if ((i - 1 >= 0) &&
                                                            casesMap[i - 1][j].typedeconstruction != AUCUNE) {
                                                            if ((i + 1 <= 44) &&
                                                                casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                                typederoute = 16;
                                                            } else {
                                                                typederoute = 12;
                                                            }
                                                        } else if ((i + 1 <= 44) &&
                                                                   casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                            typederoute = 13;
                                                        } else {
                                                            typederoute = 6;
                                                        }
                                                    } else if ((i - 1 >= 0) &&
                                                               casesMap[i - 1][j].typedeconstruction != AUCUNE) {
                                                        if ((i + 1 <= 44) &&
                                                            casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                            typederoute = 14;
                                                        } else {
                                                            typederoute = 7;
                                                        }
                                                    } else if ((i + 1 <= 44) &&
                                                               casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                        typederoute = 8;
                                                    } else {
                                                        typederoute = 2;
                                                    }
                                                } else if ((j + 1 <= 34) &&
                                                           casesMap[i][j + 1].typedeconstruction != AUCUNE) {
                                                    if ((i - 1 >= 0) &&
                                                        casesMap[i - 1][j].typedeconstruction != AUCUNE) {
                                                        if ((i + 1 <= 44) &&
                                                            casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                            typederoute = 15;
                                                        } else {
                                                            typederoute = 9;
                                                        }
                                                    } else if ((i + 1 <= 44) &&
                                                               casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                        typederoute = 10;
                                                    } else {
                                                        typederoute = 3;
                                                    }
                                                } else if ((i - 1 >= 0) &&
                                                           casesMap[i - 1][j].typedeconstruction != AUCUNE) {
                                                    if ((i + 1 <= 44) &&
                                                        casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                        typederoute = 11;
                                                    } else {
                                                        typederoute = 4;
                                                    }
                                                } else if ((i + 1 <= 44) &&
                                                           casesMap[i + 1][j].typedeconstruction != AUCUNE) {
                                                    typederoute = 5;
                                                } else {
                                                    typederoute = 1;
                                                }

                                            }
                                            if (niveauvue == 0) {
                                                al_draw_bitmap(Route[typederoute], CASE * (float) i + decallagex,CASE * (float) j + decallagey, 0);

                                            } else {
                                                al_draw_tinted_bitmap(Route[typederoute], al_map_rgb(200, 165, 235),CASE * (float) i + decallagex,CASE * (float) j + decallagey, 0);
                                                if (typederoute != 0) {
                                                    if (niveauvue == 1) {

                                                        al_draw_tinted_bitmap(Flux[typederoute - 1],al_map_rgb(255, 255, 30),CASE * (float) i + decallagex,CASE * (float) j + decallagey, 0);
                                                    } else if (niveauvue == 2) {
                                                        al_draw_tinted_bitmap(Flux[typederoute - 1],al_map_rgb(40, 40, 255),CASE * (float) i + decallagex,CASE * (float) j + decallagey, 0);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if(camionpresent){
                                        if(orientationcamion==0){
                                            if(sensCamion==0){
                                                al_draw_bitmap(Pompierhaut,xcamion*CASE+decallagex, ycamion*CASE+decallagey,0 );
                                            }else if(sensCamion==1){
                                                al_draw_bitmap(Pompierbas,xcamion*CASE+decallagex, ycamion*CASE+decallagey,0 );
                                            }else{
                                                al_draw_bitmap(Pompiercote,xcamion*CASE+decallagex, ycamion*CASE+decallagey,((sensCamion==3) ? 0 : 1) );
                                            }
                                        }else{
                                            if(sensCamion==0){
                                                al_draw_bitmap(Pompierhaut,xcamion*CASE+decallagex, ycamion*CASE+decallagey-((((int) compttimer / 8) % 2 * 10)-20),0 );
                                            }else if(sensCamion==1){
                                                al_draw_bitmap(Pompierbas,xcamion*CASE+decallagex, ycamion*CASE+decallagey+((((int) compttimer / 8) % 2 * 10)-20),0 );
                                            }else{
                                                al_draw_bitmap(Pompiercote,xcamion*CASE+decallagex+((sensCamion==3) ? 1 : -1) *((((int) compttimer / 8) % 2 * 10)-20), ycamion*CASE+decallagey,((sensCamion==3) ? 0 : 1) );
                                            }
                                        }


                                    }

                                    if (attaquegodzilla) {
                                        if(niveauvue==0){
                                            al_draw_filled_ellipse(CASE * xgodzilla + decallagex +((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 * 10) - 30) + 65,CASE * ygodzilla + decallagey + 105, 55, 15,al_map_rgba(0, 0, 0, 80));
                                            al_draw_bitmap(Cataclysmes[12+(int)decalanim%4], CASE*xgodzilla+decallagex+((sensattaque)?1:-1)*((((int)compttimer/16)%4*10)-30), CASE*ygodzilla+decallagey-20, sensattaque);

                                        }else{
                                            al_draw_filled_ellipse(CASE * xgodzilla + decallagex +((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 * 10) - 30) + 65,CASE * ygodzilla + decallagey + 105, 55, 15,al_map_rgba(0, 0, 0, 40));
                                            al_draw_tinted_bitmap(Cataclysmes[12+(int)decalanim%4], al_map_rgba(205,205,205,40), CASE*xgodzilla+decallagex+((sensattaque)?1:-1)*((((int)compttimer/16)%4*10)-30), CASE*ygodzilla+decallagey-20, sensattaque);


                                        }

                                    }

                                    for (int i = 0; i < 35; ++i) {
                                        for (int j = 0; j < 45; ++j) {
                                            if (casesMap[j][i].typedeconstruction == AUCUNE) {
                                                if (casesMap[j][i].sapin) {
                                                    if (niveauvue == 0) {
                                                        al_draw_bitmap(Sapin, CASE * (float) j + decallagex - 2,CASE * (float) i + decallagey - 10, 0);
                                                    } else {
                                                        al_draw_tinted_bitmap(Sapin, al_map_rgba(120, 100, 180, 40),CASE * (float) j + decallagex - 2,CASE * (float) i + decallagey - 10, 0);
                                                    }
                                                }
                                            }
                                            if (casesMap[j][i].hautgauche &&casesMap[j][i].typedeconstruction == HABITATION){
                                                al_draw_rectangle(CASE * (float) j + decallagex+2,CASE * (float) i + decallagey+2, CASE * (float) (j+3) + decallagex-2,CASE * (float) (i+3) + decallagey-2,al_map_rgba(0, 0, 0, 40), 4);
                                                if (niveauvue == 0) {
                                                    al_draw_bitmap(Batiments[casesMap[j][i].niveaudebatiment],CASE * (float) j + decallagex,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0), 0);
                                                    if (casesMap[j][i].incendie) {
                                                        al_draw_bitmap(Cataclysmes[(2 + compttimer / 8) % 6 + 6],CASE * (float) j + decallagex + 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0) +12, 1);
                                                        al_draw_bitmap(Cataclysmes[(5 + compttimer / 8) % 6 + 6],CASE * (float) j + decallagex + 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0) +12, 0);
                                                        al_draw_bitmap(Cataclysmes[(3 + compttimer / 8) % 6],CASE * (float) j + decallagex - 10,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0) - 5,0);
                                                        al_draw_bitmap(Cataclysmes[(compttimer / 8) % 6],CASE * (float) j + decallagex - 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0) + 2,0);
                                                        al_draw_bitmap(Cataclysmes[(2 + compttimer / 8) % 6],CASE * (float) j + decallagex + 50,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0) +15, 1);
                                                    }
                                                } else {
                                                    al_draw_tinted_bitmap(Batiments[casesMap[j][i].niveaudebatiment],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40 : 0),0);
                                                    if (casesMap[j][i].incendie) {
                                                        al_draw_tinted_bitmap(Cataclysmes[(2 + compttimer / 8) % 6 + 6],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex + 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40: 0) +12, 1);
                                                        al_draw_tinted_bitmap(Cataclysmes[(5 + compttimer / 8) % 6 + 6],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex + 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40: 0) +12, 0);
                                                        al_draw_tinted_bitmap(Cataclysmes[(3 + compttimer / 8) % 6],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex - 10,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40: 0) -5, 0);
                                                        al_draw_tinted_bitmap(Cataclysmes[(compttimer / 8) % 6],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex - 20,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40: 0) +2, 0);
                                                        al_draw_tinted_bitmap(Cataclysmes[(2 + compttimer / 8) % 6],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex + 50,CASE * (float) i + decallagey -(float) ((casesMap[j][i].niveaudebatiment ==GRATTECIEL) ? 100: (casesMap[j][i].niveaudebatiment ==IMMEUBLE) ? 40: 0) +15, 1);
                                                    }
                                                    if(niveauvue==1){
                                                        int dizaine = casesMap[j][i].nombrehabitants;
                                                        int decallageimage = 0;
                                                        while (dizaine >= 1) {
                                                            dizaine = dizaine / 10;
                                                            decallageimage++;
                                                        }

                                                        al_draw_textf(PressStart20, al_map_rgb(255, 255, 10), CASE * (float) j + decallagex+60-10*decallageimage, CASE * (float) i + decallagey+40, 0, "%d", casesMap[j][i].niveauElec);
                                                        al_draw_textf(PressStart20, al_map_rgb(255, 255, 10), CASE * (float) j + decallagex+41-10*decallageimage, CASE * (float) i + decallagey+70, 0, "/%d", casesMap[j][i].nombrehabitants);
                                                    }else if(niveauvue==2){
                                                        int dizaine = casesMap[j][i].nombrehabitants;
                                                        int decallageimage = 0;
                                                        while (dizaine >= 1) {
                                                            dizaine = dizaine / 10;
                                                            decallageimage++;
                                                        }

                                                        al_draw_textf(PressStart20, al_map_rgb(40, 40, 255), CASE * (float) j + decallagex+60-10*decallageimage, CASE * (float) i + decallagey+40, 0, "%d", casesMap[j][i].niveauEau);
                                                        al_draw_textf(PressStart20, al_map_rgb(40, 40, 255), CASE * (float) j + decallagex+41-10*decallageimage, CASE * (float) i + decallagey+70, 0, "/%d", casesMap[j][i].nombrehabitants);
                                                    }
                                                }

                                            } else if (casesMap[j][i].hautgauche) {
                                                switch (casesMap[j][i].typedeconstruction) {
                                                    case CHATEAUEAU:
                                                    case POKEDEFENSE:
                                                        al_draw_rectangle(CASE * (float) j + decallagex+2,CASE * (float) i + decallagey+2, CASE * (float) (j+4) + decallagex-2,CASE * (float) (i+6) + decallagey-2,al_map_rgba(0, 0, 0, 40), 4);
                                                        break;
                                                    case CENTRALELEC:
                                                    case CASERNE:
                                                        al_draw_rectangle(CASE * (float) j + decallagex+2,CASE * (float) i + decallagey+2, CASE * (float) (j+6) + decallagex-2,CASE * (float) (i+4) + decallagey-2,al_map_rgba(0, 0, 0, 40), 4);
                                                        break;
                                                }
                                                if (niveauvue == 0) {
                                                    al_draw_bitmap(Batiments[casesMap[j][i].typedeconstruction + 3],CASE * (float) j + decallagex,CASE * (float) i + decallagey, 0);
                                                } else {
                                                    al_draw_tinted_bitmap(Batiments[casesMap[j][i].typedeconstruction + 3],al_map_rgba(100, 100, 100, 40),CASE * (float) j + decallagex,CASE * (float) i + decallagey, 0);
                                                    if(niveauvue==1 && casesMap[j][i].typedeconstruction==CENTRALELEC){
                                                        int dizaine = casesMap[j][i].niveauElec;
                                                        int decallageimage = 0;
                                                        while (dizaine >= 1) {
                                                            dizaine = dizaine / 10;
                                                            decallageimage++;
                                                        }
                                                        al_draw_textf(PressStart20, al_map_rgb(255, 255, 10), CASE * (float) j + decallagex+105-10*decallageimage, CASE * (float) i + decallagey+50, 0, "%d", casesMap[j][i].niveauElec);
                                                        al_draw_text(PressStart20, al_map_rgb(255, 255, 10), CASE * (float) j + decallagex+85-10*decallageimage, CASE * (float) i + decallagey+80, 0, "/5000");
                                                    }else if(niveauvue==2 && casesMap[j][i].typedeconstruction==CHATEAUEAU){
                                                        int dizaine = casesMap[j][i].niveauEau;
                                                        int decallageimage = 0;
                                                        while (dizaine >= 1) {
                                                            dizaine = dizaine / 10;
                                                            decallageimage++;
                                                        }
                                                        al_draw_textf(PressStart20, al_map_rgb(40, 40, 255), CASE * (float) j + decallagex+85-10*decallageimage, CASE * (float) i + decallagey+100, 0, "%d", casesMap[j][i].niveauEau);
                                                        al_draw_text(PressStart20, al_map_rgb(40, 40, 255), CASE * (float) j + decallagex+65-10*decallageimage, CASE * (float) i + decallagey+130, 0, "/5000");
                                                    }
                                                }
                                            }
                                            if(niveauvue==0){
                                                if (xgodzilla == j && ygodzilla == i - 3 && attaquegodzilla) {
                                                    al_draw_bitmap(Cataclysmes[12 + (int) decalanim % 4],CASE * xgodzilla + decallagex +((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 * 10) - 30),CASE * ygodzilla + decallagey - 20, sensattaque);
                                                    if (lazergodzilla) {
                                                        al_draw_bitmap(Cataclysmes[16 + (int) decalanim % 3],CASE * xgodzilla + decallagex +((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 * 10) + 36),CASE * ygodzilla + decallagey + 16, sensattaque);
                                                    }
                                                }
                                            }else{
                                                if (xgodzilla == j && ygodzilla == i - 3 && attaquegodzilla) {
                                                    if (lazergodzilla) {
                                                        al_draw_tinted_bitmap(Cataclysmes[16 + (int) decalanim % 3],al_map_rgba(255,255,255,440),CASE * xgodzilla + decallagex +((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 * 10) + 36),CASE * ygodzilla + decallagey + 16, sensattaque);
                                                    }
                                                }
                                            }

                                        }
                                    }



                                    for (int i = 0; i < 7; ++i) {
                                        if (niveauvue == 0) {
                                            al_draw_bitmap(Bordure, decallagex - 200, decallagey + CASE * 5 * (float) i,
                                                           0);
                                            al_draw_bitmap(Bordure, decallagex + 1800,
                                                           decallagey + CASE * 5 * (float) i, 0);
                                        } else {
                                            al_draw_tinted_bitmap(Bordure, al_map_rgb(200, 165, 235), decallagex - 200,
                                                                  decallagey + CASE * 5 * (float) i, 0);
                                            al_draw_tinted_bitmap(Bordure, al_map_rgb(200, 165, 235), decallagex + 1800,
                                                                  decallagey + CASE * 5 * (float) i, 0);
                                        }

                                    }
                                    if(niveauvue==0){
                                        if (missileencours && missilemontant) {
                                            al_draw_rotated_bitmap(Cataclysmes[19 + (int) decalanim % 3], 64 / 2, 45 / 2,xmissile + decallagex, ymissile + decallagey, anglecible,(avancementmissile > 10) ? ((ygodzilla * CASE + 64 >ymissilesave) ? 0 : 0) : 0);
                                        } else if (missileencours) {
                                            al_draw_rotated_bitmap(Cataclysmes[19 + (int) decalanim % 3], 64 / 2, 45 / 2,xmissile + decallagex, ymissile + decallagey,-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) +3.1415 / 2, (ygodzilla * CASE + 64 >= ymissile) ? 0 : 3);
                                        }
                                        if (explosion) {
                                            al_draw_bitmap(Cataclysmes[22 + (int) avancementmissile % 9],CASE * xgodzilla + decallagex + ((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 *10) - 30) - 16,ygodzilla * CASE + decallagey - 36, 0);
                                        }
                                    }else{
                                        if (missileencours && missilemontant) {
                                            al_draw_tinted_rotated_bitmap(Cataclysmes[19 + (int) decalanim % 3],al_map_rgba(255,255,255, 40), 64 / 2, 45 / 2,xmissile + decallagex, ymissile + decallagey, anglecible,(avancementmissile > 10) ? ((ygodzilla * CASE + 64 >ymissilesave) ? 0 : 0) : 0);
                                        } else if (missileencours) {
                                            al_draw_tinted_rotated_bitmap(Cataclysmes[19 + (int) decalanim % 3], al_map_rgba(255,255,255, 40),64 / 2, 45 / 2,xmissile + decallagex, ymissile + decallagey,-atan(((float) xgodzilla * CASE + 64 - xmissile) /((float) ygodzilla * CASE + 64 - ymissile)) +3.1415 / 2, (ygodzilla * CASE + 64 >= ymissile) ? 0 : 3);
                                        }
                                        if (explosion) {
                                            al_draw_tinted_bitmap(Cataclysmes[22 + (int) avancementmissile % 9],al_map_rgba(255,255,255, 40),CASE * xgodzilla + decallagex + ((sensattaque) ? 1 : -1) *((((int) compttimer / 16) % 4 *10) - 30) - 16,ygodzilla * CASE + decallagey - 36, 0);
                                        }
                                    }




                                    //"Viseur"
                                    switch (achat) {
                                        case -1:
                                        case ROUTE:
                                            al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x + CASE,Caseselec.y + CASE, al_map_rgba(200, 40, 180, 80));
                                            break;
                                        case CHATEAUEAU:
                                        case POKEDEFENSE :
                                            al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x + 4*CASE,Caseselec.y + 6*CASE, al_map_rgba(200, 40, 180, 80));
                                            break;
                                        case CENTRALELEC:
                                        case CASERNE:
                                            al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x + 6*CASE,Caseselec.y + 4*CASE, al_map_rgba(200, 40, 180, 80));
                                            break;
                                        case HABITATION:
                                            al_draw_filled_rectangle(Caseselec.x, Caseselec.y, Caseselec.x + 3*CASE,Caseselec.y + 3*CASE, al_map_rgba(200, 40, 180, 80));
                                            break;
                                    }


                                    // MiniMap
                                    if (niveauvue == 0) {
                                        al_draw_filled_rectangle(larg - 200, 20, larg - 20, 160,
                                                                 al_map_rgba(00, 105, 00, 200));

                                        al_draw_filled_rectangle(larg - 200, 170, larg - 20, 220,
                                                                 al_map_rgb(230, 230, 230));
                                        al_draw_rectangle(larg - 200 - 2, 170 - 2, larg - 20 + 2, 220 + 2,
                                                          al_map_rgb(10, 10, 10), 4);
                                        al_draw_text(PressStart15, al_map_rgb(0, 0, 0), larg - 185, 187, 0,
                                                     "Sauvegarde:");
                                        al_draw_filled_rectangle(larg - 200 + 2, 230, larg - 160 + 2, 270,
                                                                 al_map_rgb(230, 230, 230));
                                        al_draw_filled_rectangle(larg - 155 + 2, 230, larg - 115 + 2, 270,
                                                                 al_map_rgb(230, 230, 230));
                                        al_draw_filled_rectangle(larg - 110 + 2, 230, larg - 70 + 2, 270,
                                                                 al_map_rgb(230, 230, 230));
                                        al_draw_filled_rectangle(larg - 65 + 2, 230, larg - 25 + 2, 270,
                                                                 al_map_rgb(230, 230, 230));
                                        al_draw_rectangle(larg - 200 + 2, 230, larg - 160 + 2, 270,
                                                          al_map_rgb(10, 10, 10), 2);
                                        al_draw_rectangle(larg - 155 + 2, 230, larg - 115 + 2, 270,
                                                          al_map_rgb(10, 10, 10), 2);
                                        al_draw_rectangle(larg - 110 + 2, 230, larg - 70 + 2, 270,
                                                          al_map_rgb(10, 10, 10), 2);
                                        al_draw_rectangle(larg - 65 + 2, 230, larg - 25 + 2, 270,
                                                          al_map_rgb(10, 10, 10), 2);
                                        al_draw_text(PressStart15, al_map_rgb(0, 0, 0), larg - 185, 245, 0, "1");
                                        al_draw_text(PressStart15, al_map_rgb(0, 0, 0), larg - 140, 245, 0, "2");
                                        al_draw_text(PressStart15, al_map_rgb(0, 0, 0), larg - 95, 245, 0, "3");
                                        al_draw_text(PressStart15, al_map_rgb(0, 0, 0), larg - 50, 245, 0, "4");
                                    } else {
                                        al_draw_filled_rectangle(larg - 200, 20, larg - 20, 160,
                                                                 al_map_rgba(105, 105, 105, 200));
                                    }
                                    if(probaattaque==1){
                                        al_draw_bitmap(RampageLogo, larg-82, 280,0);
                                    }

                                    al_draw_rectangle(larg - 200 - 2, 20 - 2, larg - 20 + 2, 160 + 2,
                                                      al_map_rgba(0, 050, 00, 255), 4);
                                    for (int i = 0; i < 45; i++) {
                                        for (int j = 0; j < 35; j++) {
                                            switch (casesMap[i][j].typedeconstruction) {
                                                case ROUTE:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(10, 10, 10, 100));
                                                    break;
                                                case HABITATION:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(255, 10, 10, 100));
                                                    break;
                                                case CENTRALELEC:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(255, 255, 10, 100));
                                                    break;
                                                case CHATEAUEAU:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(10, 10, 255, 100));
                                                    break;
                                                case CASERNE:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(255, 50, 10, 100));
                                                    break;
                                                case POKEDEFENSE:
                                                    al_draw_filled_rectangle(larg - 200 + i * 4, 20 + j * 4,larg - 200 + (i + 1) * 4, 20 + (j + 1) * 4,al_map_rgba(10, 205, 10, 100));
                                                    break;
                                            }
                                        }
                                    }

                                    switch (achat) {
                                        case -1:
                                        case ROUTE:
                                            al_draw_filled_rectangle(larg - 200 + Caseselec.numcolonne * 4,20 + Caseselec.numligne * 4,larg - 200 + (Caseselec.numcolonne + 1) * 4,20 + (Caseselec.numligne + 1) * 4,al_map_rgba(180, 20, 180, 100));
                                            break;
                                        case CHATEAUEAU:
                                        case POKEDEFENSE :
                                            al_draw_filled_rectangle(larg - 200 + Caseselec.numcolonne * 4,20 + Caseselec.numligne * 4,larg - 200 + (Caseselec.numcolonne + 4) * 4,20 + (Caseselec.numligne + 6) * 4,al_map_rgba(180, 20, 180, 100));
                                            break;
                                        case CENTRALELEC:
                                        case CASERNE:
                                            al_draw_filled_rectangle(larg - 200 + Caseselec.numcolonne * 4,20 + Caseselec.numligne * 4,larg - 200 + (Caseselec.numcolonne + 6) * 4,20 + (Caseselec.numligne + 4) * 4,al_map_rgba(180, 20, 180, 100));
                                            break;
                                        case HABITATION:
                                            al_draw_filled_rectangle(larg - 200 + Caseselec.numcolonne * 4,20 + Caseselec.numligne * 4,larg - 200 + (Caseselec.numcolonne + 3) * 4,20 + (Caseselec.numligne + 3) * 4,al_map_rgba(180, 20, 180, 100));
                                            break;
                                    }

                                    for (int i = 0; i < 3; ++i) {
                                        for (int j = 0; j < 3; ++j) {
                                            if (xgodzilla + i >= 0 && xgodzilla + i <= 44 && ygodzilla + j >= 0 &&
                                                ygodzilla + j <= 44) {
                                                al_draw_filled_rectangle(larg - 200 + (xgodzilla + i) * 4,20 + (ygodzilla + j) * 4,larg - 200 + (xgodzilla + i + 1) * 4,20 + (ygodzilla + j + 1) * 4,al_map_rgba(0, 0, 0, 100));
                                            }
                                        }
                                    }


                                    //Affichage et calibration du Chrono
                                    int dizaine = chrono;
                                    int decallageimage = 0;
                                    while (dizaine >= 1) {
                                        dizaine = dizaine / 10;
                                        decallageimage++;
                                    }
                                    al_draw_filled_rectangle(larg / 2 - 17.5 * decallageimage + 30, 15,
                                                             larg / 2 + 17.5 * decallageimage + 40, 60,
                                                             al_map_rgb(235, 235, 235));
                                    al_draw_rectangle(larg / 2 - 17.5 * decallageimage + 30, 15,
                                                      larg / 2 + 17.5 * decallageimage + 40, 60, al_map_rgb(30, 30, 30),
                                                      4);
                                    al_draw_textf(PressStart35, al_map_rgb(10, 10, 10),
                                                  larg / 2 - 17.5 * decallageimage + 35, 20, 0, "%d", (int) chrono);

                                    al_draw_filled_rectangle(0, 60, 200, haut - 60, al_map_rgb(235, 235, 235));
                                    al_draw_rectangle(0, 58, 202, haut - 58, al_map_rgb(30, 30, 30), 4);

                                    al_draw_text(PressStart15, al_map_rgb(30, 30, 30), 15, 85, 0, ("Pokedollars: "));
                                    dizaine = pokedollars;
                                    decallageimage = 0;
                                    while (dizaine >= 1) {
                                        dizaine = dizaine / 10;
                                        decallageimage++;
                                    }
                                    al_draw_textf(PressStart20, al_map_rgb(30, 30, 30), 100 - decallageimage * 10, 120,
                                                  0, ("%d"), pokedollars);

                                    al_draw_text(PressStart15, al_map_rgb(30, 30, 30), 10, 165, 0, ("Nb Habitants:"));
                                    dizaine = nbhabitants;
                                    decallageimage = 0;
                                    while (dizaine >= 1) {
                                        dizaine = dizaine / 10;
                                        decallageimage++;
                                    }
                                    al_draw_textf(PressStart20, al_map_rgb(30, 30, 30), 100 - decallageimage * 10, 195,
                                                  0, ("%d"), nbhabitants);


                                    if (niveauvue == 0) {
                                        al_draw_bitmap(BoutonMenuJeu[ROUTE], 15, 240, 0);
                                        al_draw_bitmap(BoutonMenuJeu[HABITATION], 105, 240, 0);
                                        al_draw_bitmap(BoutonMenuJeu[CENTRALELEC], 15, 330, 0);
                                        al_draw_bitmap(BoutonMenuJeu[CHATEAUEAU], 105, 330, 0);
                                        al_draw_bitmap(BoutonMenuJeu[CASERNE], 15, 420, 0);
                                        al_draw_bitmap(BoutonMenuJeu[POKEDEFENSE], 105, 420, 0);
                                        al_draw_rectangle(14, 239, 96, 321, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_rectangle(104, 239, 186, 321, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_rectangle(14, 329, 96, 411, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_rectangle(104, 329, 186, 411, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_rectangle(14, 419, 96, 501, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_rectangle(104, 419, 186, 501, al_map_rgb(10, 10 ,10), 2);
                                        al_draw_text(PressStart15, al_map_rgb(30, 30, 30), 10, 520, 0,("Achat actuel:"));
                                        al_draw_rectangle(59, 549, 141, 631, al_map_rgb(10, 10 ,10), 2);

                                        if (achat == -1) {
                                            al_draw_filled_rectangle(60, 550, 140, 630, al_map_rgb(0, 0, 0));
                                            al_draw_bitmap(BoutonMenuJeu[7], 50, 645, 0);
                                        } else {
                                            al_draw_bitmap(BoutonMenuJeu[achat], 60, 550, 0);
                                            al_draw_bitmap(BoutonMenuJeu[8], 50, 645, 0);
                                        }

                                        if (mouse_state.x >= 15 && mouse_state.x <= 95 && mouse_state.y >= 240 - 5 &&
                                            mouse_state.y <= 320 - 5) {
                                            al_draw_filled_rectangle(15, 240, 95, 320, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 105 && mouse_state.x <= 185 &&
                                                   mouse_state.y >= 240 - 5 && mouse_state.y <= 320 - 5) {
                                            al_draw_filled_rectangle(105, 240, 185, 320, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 15 && mouse_state.x <= 95 &&
                                                   mouse_state.y >= 310 - 5 && mouse_state.y <= 410 - 5) {
                                            al_draw_filled_rectangle(15, 330, 95, 410, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 105 && mouse_state.x <= 185 &&
                                                   mouse_state.y >= 310 - 5 && mouse_state.y <= 410 - 5) {
                                            al_draw_filled_rectangle(105, 330, 185, 410, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 15 && mouse_state.x <= 95 &&
                                                   mouse_state.y >= 420 - 5 && mouse_state.y <= 500 - 5) {
                                            al_draw_filled_rectangle(15, 420, 95, 500, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 105 && mouse_state.x <= 185 &&
                                                   mouse_state.y >= 420 - 5 && mouse_state.y <= 500 - 5) {
                                            al_draw_filled_rectangle(105, 420, 185, 500, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= 50 && mouse_state.x <= 150 &&
                                                   mouse_state.y >= 645 - 5 && mouse_state.y <= 695 - 5) {
                                            al_draw_filled_rectangle(50, 645, 150, 695, al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= larg - 200 + 2 && mouse_state.x <= larg - 160 + 2 &&
                                                   mouse_state.y >= 230 - 5 && mouse_state.y <= 270 - 5) {
                                            al_draw_filled_rectangle(larg - 200 + 2, 230, larg - 160 + 2, 270,
                                                                     al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= larg - 155 + 2 && mouse_state.x <= larg - 115 + 2 &&
                                                   mouse_state.y >= 230 - 5 && mouse_state.y <= 270 - 5) {
                                            al_draw_filled_rectangle(larg - 155 + 2, 230, larg - 115 + 2, 270,
                                                                     al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= larg - 110 + 2 && mouse_state.x <= larg - 70 + 2 &&
                                                   mouse_state.y >= 230 - 5 && mouse_state.y <= 270 - 5) {
                                            al_draw_filled_rectangle(larg - 110 + 2, 230, larg - 70 + 2, 270,
                                                                     al_map_rgba(0, 0, 0, 40));
                                        } else if (mouse_state.x >= larg - 65 + 2 && mouse_state.x <= larg - 25 + 2 &&
                                                   mouse_state.y >= 230 - 5 && mouse_state.y <= 270 - 5) {
                                            al_draw_filled_rectangle(larg - 65 + 2, 230, larg - 25 + 2, 270,
                                                                     al_map_rgba(0, 0, 0, 40));
                                        }

                                    }
                                }
                                if(confirmationsauvegarde){
                                    al_draw_filled_rectangle(larg/2-280, haut/2-140, larg/2 +280, haut/2+120,al_map_rgb(255, 255, 255)  );
                                    al_draw_rectangle(larg/2-280, haut/2-140, larg/2 +280, haut/2+120,al_map_rgb(10, 10, 10) , 4);
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-230, haut/2-100,0, "Est-ce que vous êtes sûr");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-225, haut/2-70,0, "de vouloir sauvegarder ? ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-190, haut/2-40,0, "Cela entrainera la   ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-175, haut/2-10,0, "supression de la ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-200, haut/2+20,0, "sauvegarde précedente.");
                                }else if (confirmationquitter){
                                    al_draw_filled_rectangle(larg/2-280, haut/2-140, larg/2 +280, haut/2+120,al_map_rgb(255, 255, 255)  );
                                    al_draw_rectangle(larg/2-280, haut/2-140, larg/2 +280, haut/2+120,al_map_rgb(10, 10, 10) , 4);
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-230, haut/2-100,0, "Est-ce que vous êtes sûr");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-225, haut/2-70,0, "de vouloir quitter ? ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-190, haut/2-40,0, "Cela entrainera la   ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-175, haut/2-10,0, "supression de vos ");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-200, haut/2+20,0, "données actuelles.");
                                }
                                if(confirmationsauvegarde || confirmationquitter){
                                    al_draw_rectangle(larg/2-100, haut/2+50, larg/2-20, haut/2+105,al_map_rgb(10, 10, 10) , 2);
                                    al_draw_rectangle(larg/2+20, haut/2+50, larg/2+100, haut/2+105,al_map_rgb(10, 10, 10) , 2);
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2-90, haut/2+65,0, "Oui");
                                    al_draw_text(PressStart20, al_map_rgb(0, 0, 40), larg/2+30, haut/2+65,0, "Non");
                                    if( mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2-20 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                        al_draw_filled_rectangle(larg/2-100, haut/2+50, larg/2-20, haut/2+105,al_map_rgba(0, 0, 0,40) );
                                    }else if(mouse_state.x>=larg/2+20 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                        al_draw_filled_rectangle(larg/2+20, haut/2+50, larg/2+100, haut/2+105,al_map_rgba(0, 0, 0,40) );
                                    }
                                }
                                if(pause){
                                    al_draw_filled_rectangle(larg/2-150, haut/2-50, larg/2 +150, haut/2+50,al_map_rgb(255, 255, 255)  );
                                    al_draw_rectangle(larg/2-150, haut/2-50, larg/2 +150, haut/2+50,al_map_rgb(10, 10, 10) , 4);
                                    al_draw_text(PressStart35, al_map_rgb(0, 0, 40), larg/2-85, haut/2-20,0, "PAUSE ");
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
                                case ALLEGRO_KEY_P:
                                    if(pause){
                                        pause=false;
                                    }else if (!confirmationsauvegarde && !confirmationquitter){
                                        pause=true;
                                    }
                                    break;
                                case ALLEGRO_KEY_R:
                                    if(!pause && !confirmationsauvegarde && !confirmationquitter){
                                        if(probaattaque>1){
                                            probaattaque=1;
                                        }else{
                                            probaattaque=5;
                                        }
                                    }
                                    break;


                            }
                            break;
                        case ALLEGRO_EVENT_MOUSE_AXES:
                            al_get_mouse_state(&mouse_state);
                            calculcaseselec(&mouse_state,  &Caseselec, decallagex, decallagey, haut,larg, &menujeu);
                            break;

                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                            al_get_mouse_state(&mouse_state);

                            if(menujeu && niveauvue==0 && !pause && !confirmationsauvegarde && !confirmationquitter){
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
                                        confirmationquitter=true;
                                    }
                                }else if(mouse_state.x>=larg-200+2 && mouse_state.x<=larg-160+2 && mouse_state.y>=230-5 && mouse_state.y<=270-5){
                                    sauvegardechoisie=1;
                                    confirmationsauvegarde=true;
                                }else if(mouse_state.x>=larg-155+2 && mouse_state.x<=larg-115+2 && mouse_state.y>=230-5 && mouse_state.y<=270-5){
                                    sauvegardechoisie=2;
                                    confirmationsauvegarde=true;
                                }else if(mouse_state.x>=larg-110+2 && mouse_state.x<=larg-70+2 && mouse_state.y>=230-5 && mouse_state.y<=270-5){
                                    sauvegardechoisie=3;
                                    confirmationsauvegarde=true;
                                }else if(mouse_state.x>=larg-65+2 && mouse_state.x<=larg-25+2 && mouse_state.y>=230-5 && mouse_state.y<=270-5){
                                    sauvegardechoisie=4;
                                    confirmationsauvegarde=true;
                                }
                            }else if(confirmationsauvegarde && !pause && !confirmationquitter){
                                if( mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2-20 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                    switch (sauvegardechoisie) {
                                        case 1:
                                            fonctionSauvegarde("Sauvegarde1", casesMap, pokedollars, regimepolitique);
                                            break;
                                        case 2:
                                            fonctionSauvegarde("Sauvegarde2", casesMap, pokedollars, regimepolitique);
                                            break;
                                        case 3:
                                            fonctionSauvegarde("Sauvegarde3", casesMap, pokedollars, regimepolitique);
                                            break;
                                        case 4:
                                            fonctionSauvegarde("Sauvegarde4", casesMap, pokedollars, regimepolitique);
                                            break;
                                    }
                                    sauvegardechoisie=0;
                                    confirmationsauvegarde=false;
                                }else if(mouse_state.x>=larg/2+20 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                    confirmationsauvegarde=false;
                                }
                            }else if(confirmationquitter && !confirmationsauvegarde && !pause){
                                if( mouse_state.x>=larg/2-100 && mouse_state.x<=larg/2-20 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                    decalanim=1;
                                    finpartie = true;
                                    finmenu =false;
                                    lieumenu=DEMARRAGE;
                                    etatjeu=MENUPRINCIPAL;
                                    sauvegardechoisie=0;
                                    confirmationquitter=false;
                                    confirmationsauvegarde=false;
                                    pause=false;
                                }else if(mouse_state.x>=larg/2+20 && mouse_state.x<=larg/2+100 && mouse_state.y>=haut/2+50-5 && mouse_state.y<=haut/2+105-5){
                                    confirmationquitter=false;
                                }
                            }else if (achat!=(-1)&&niveauvue==0 && !pause && !confirmationsauvegarde){

                                if(achat==ROUTE) {
                                    if(Caseselec.numcolonne<45&&casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==AUCUNE &&pokedollars>=10 ) {
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction=ROUTE;
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].sapin=false;
                                        pokedollars-=10;
                                        if(!camionpresent){
                                            BFSCaserne(&casesMap);
                                            if(casesMap[Caseselec.numcolonne][Caseselec.numligne].protegedufeu){
                                                camionpresent=true;
                                                xcamion=Caseselec.numcolonne;
                                                ycamion=Caseselec.numligne;
                                            }
                                        }

                                        nombreroutes++;


                                    }else if(Caseselec.numcolonne<45&&casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction==ROUTE){
                                        if(camionpresent&&xcamion ==Caseselec.numcolonne && ycamion==Caseselec.numligne){
                                            camionpresent=false;
                                        }
                                        casesMap[Caseselec.numcolonne][Caseselec.numligne].typedeconstruction=AUCUNE;
                                        nombreroutes--;
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
                                                        numerohabitation++;
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
                                                    if(pokedollars>=10000){
                                                        pokedollars-=10000;
                                                    }else{
                                                        batimentendessous=true;
                                                    }
                                                    break;
                                                case POKEDEFENSE:
                                                    if(pokedollars>=50000){
                                                        pokedollars-=50000;
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
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].numerohabitation=numerohabitation;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].typedeconstruction=achat;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].niveaudebatiment=TERRAINVAGUE;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].sapin=false;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].nombrehabitants=0;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].niveauEau=0;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].niveauElec=0;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].CentralElecAssoc=-1;
                                                    casesMap[Caseselec.numcolonne+i][Caseselec.numligne+j].ChateauEauAssoc=-1;
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






void calculcaseselec(ALLEGRO_MOUSE_STATE* mouse_state, Avantplan* Caseselec, float decallagex, float decallagey, float haut, float larg, bool* menujeu){
    al_get_mouse_state(mouse_state);
    bool unfined=true;
    if(mouse_state->x>=0&&mouse_state->x<=200&&mouse_state->y>=60&&mouse_state->y<=haut-60){
        *menujeu=true;
    }else if (mouse_state->x>=larg-200&&mouse_state->x<=larg-17&&mouse_state->y>=20&&mouse_state->y<=267){
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