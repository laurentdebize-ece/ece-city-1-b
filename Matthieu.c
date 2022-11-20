//
// Created by gabdu on 02/11/2022.
//

#include "Matthieu.h"



void creerFichier (char *fichier, Cases** cases){
    FILE *ifs = fopen("Sauvegarde1", "w+");
    for (int i = 0; i < 45; i++ ){
        for (int j = 0; j < 35; j++){


            fprintf(ifs, "%d ", (int)cases[i][j].sapin);
            fprintf(ifs, "%d ", cases[i][j].niveaudebatiment);
            fprintf(ifs, "%d ", cases[i][j].numerobatiment);
            fprintf(ifs, "%d ", cases[i][j].typedeconstruction);
            fprintf(ifs, "%d ", (int)cases[i][j].hautgauche);
            fprintf(ifs, "%d ", cases[i][j].nombrehabitants);
            fprintf(ifs, "%d \n", (int)cases[i][j].incendie);



            /*

            else if (cases[i][j].typedeconstruction == ROUTE) {
                fputc('2', fichier);
            }else if (cases[i][j].typedeconstruction == HABITATION){
                if (cases[i][j].typedeconstruction == TERRAINVAGUE) {
                    fputc('3', fichier);
                }else if (cases[i][j].niveaudebatiment == MAISON){
                    fputc('4', fichier);
                }else if (cases[i][j].niveaudebatiment == IMMEUBLE){
                    fputc('5', fichier);
                }else if (cases[i][j].niveaudebatiment == GRATTECIEL) {
                    fputc('6', fichier);
                }else if (cases[i][j].niveaudebatiment == RUINES){
                    fputc('7', fichier);
                }else if (cases[i][j].niveaudebatiment == CABANE) {
                    fputc('8', fichier);
                }else fputc('0', fichier);
            }else if (cases[i][j].typedeconstruction == CASERNE){
                fputc('9', fichier);
            }else if (cases[i][j].typedeconstruction == POKEDEFENSE){
                fputc('a', fichier);
            }else if (cases[i][j].typedeconstruction == CENTRALELEC){
                fputc('b', fichier);
            }else if (cases[i][j].typedeconstruction == CHATEAUEAU){
                fputc('c', fichier);
            }else fputc('0', fichier);*/
        }
    }
    fclose(ifs);

}
 void lireGraphe(char *fichier, Cases cases){

    FILE *file = fopen(fichier, "r+");
    char temp;
    if (!file) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    for (int i = 0; i < 35; i++ ){
        for (int j = 0; j < 45; j++){
            fscanf(file,"%c", &temp);
            if(temp == '1') {
                cases.sapin== 1;
            }else if (temp == '2'){
                cases.niveaudebatiment == ROUTE;
            }else if (temp == '3'){
                cases.niveaudebatiment == TERRAINVAGUE;
            }else if (temp == '4'){
                cases.niveaudebatiment == MAISON;
            }else if (temp == '5'){
                cases.niveaudebatiment == IMMEUBLE;
            }else if (temp == '6'){
                cases.niveaudebatiment == GRATTECIEL;
            }else if (temp == '7'){
                cases.niveaudebatiment == RUINES;
            }else if (temp == '8'){
                cases.niveaudebatiment == CABANE;
            }else if (temp == '9'){
                cases.niveaudebatiment == CASERNE;
            }else if (temp == 'a'){
                cases.niveaudebatiment == POKEDEFENSE;
            }else if (temp == 'b'){
                cases.niveaudebatiment == CENTRALELEC;
            }else if (temp == 'c'){
                cases.typedeconstruction == CHATEAUEAU;
            }else cases.typedeconstruction == AUCUNE;

        }
    }
}


void fichierEcrireGraphe(Cases **cases){
    for (int i=0; i<45; i++){
        for (int j=0;j < 35;++j) {
            if (cases[i][j].typedeconstruction != 0){

            }
        }
    }

}


bool habitationRoute (Cases **cases, int i, int j){

    if(cases[i][j].hautgauche == 1 && (cases[i-1][j].typedeconstruction == ROUTE
                                    || cases[i-1][j+1].typedeconstruction == ROUTE
                                    || cases[i-1][j+2].typedeconstruction == ROUTE

                                    || cases[i][j-1].typedeconstruction == ROUTE
                                    || cases[i+1][j-1].typedeconstruction == ROUTE
                                    || cases[i+2][j-1].typedeconstruction == ROUTE

                                    || cases[i][j+3].typedeconstruction == ROUTE
                                    || cases[i+1][j+3].typedeconstruction == ROUTE
                                    || cases[i+2][j+3].typedeconstruction == ROUTE

                                    || cases[i+3][j].typedeconstruction == ROUTE
                                    || cases[i+3][j+1].typedeconstruction == ROUTE
                                    || cases[i+3][j+2].typedeconstruction == ROUTE)){
        return 1;
    }else return 0;
}

bool batimentRoute (Cases **cases, int i, int j){
    if(cases[i][j].hautgauche == 1 && (cases[i-1][j].typedeconstruction == ROUTE
                                       || cases[i-1][j+1].typedeconstruction == ROUTE
                                       || cases[i-1][j+2].typedeconstruction == ROUTE
                                       || cases[i-1][j+3].typedeconstruction == ROUTE

                                       || cases[i+5][j].typedeconstruction == ROUTE
                                       || cases[i+5][j+1].typedeconstruction == ROUTE
                                       || cases[i+5][j+2].typedeconstruction == ROUTE
                                       || cases[i+5][j+3].typedeconstruction == ROUTE

                                       || cases[i][j-1].typedeconstruction == ROUTE
                                       || cases[i+1][j-1].typedeconstruction == ROUTE
                                       || cases[i+2][j-1].typedeconstruction == ROUTE
                                       || cases[i+3][j-1].typedeconstruction == ROUTE
                                       || cases[i+4][j-1].typedeconstruction == ROUTE
                                       || cases[i+5][j-1].typedeconstruction == ROUTE

                                       || cases[i][j+4].typedeconstruction == ROUTE
                                       || cases[i+1][j+4].typedeconstruction == ROUTE
                                       || cases[i+2][j+4].typedeconstruction == ROUTE
                                       || cases[i+3][j+4].typedeconstruction == ROUTE
                                       || cases[i+4][j+4].typedeconstruction == ROUTE
                                       || cases[i+5][j+4].typedeconstruction == ROUTE)){
        return 1;
    }else return 0;
}

bool route (Cases **cases, int i, int j){
    if (cases[i][j].typedeconstruction == 1 && cases[i][j-1].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE){
            route(cases, i, j-1);//BFS
        }else if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }
    }
    else if (cases[i][j].typedeconstruction == 1 && cases[i-1][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i-1, j);//BFS
        }else if (cases[i+1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }
    }
    else if (cases[i][j].typedeconstruction == 1 && cases[i+1][j].typedeconstruction == 1){
        if (cases[i][j-1].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE){
            route(cases, i+1, j);//BFS
        }else if (cases[i][j-1].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }
    }
    else if (cases[i][j].typedeconstruction == 1 && cases[i][j+1].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE){
            route(cases, i, j+1);//BFS
        }else if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }
    }
    else if (cases[i][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE){
            route(cases, i, j);//BFS
        }else if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }
    }else return 0;

}




