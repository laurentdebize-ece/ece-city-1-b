//
// Created by gabdu on 02/11/2022.
//

#include "Matthieu.h"



void fonctionSauvgarde (char *fichier, Cases** cases, int pokedollars, bool regimepolitique){
    FILE *ifs = fopen("Sauvegarde1", "w+");
    fprintf(ifs, "%d \n", pokedollars);
    fprintf(ifs, "%d \n", regimepolitique);
    for (int i = 0; i < 45; i++ ){
        for (int j = 0; j < 35; j++){
            fprintf(ifs, "%d ", (int)cases[i][j].sapin);
            fprintf(ifs, "%d ", cases[i][j].niveaudebatiment);
            fprintf(ifs, "%d ", cases[i][j].numerobatiment);
            fprintf(ifs, "%d ", cases[i][j].typedeconstruction);
            fprintf(ifs, "%d ", (int)cases[i][j].hautgauche);
            fprintf(ifs, "%d ", cases[i][j].nombrehabitants);
            fprintf(ifs, "%d \n", (int)cases[i][j].incendie);
        }
    }
    fclose(ifs);
}

void fonctionrecuperationSauvgarde (char *fichier, Cases** cases, int* pokedollars, int* regimepolitique){
    FILE *ifs = fopen("Sauvegarde1", "r");
    fscanf(ifs, "%d \n", pokedollars);
    fscanf(ifs, "%d \n", regimepolitique);
    for (int i = 0; i < 45; i++ ){
        for (int j = 0; j < 35; j++){
            fscanf(ifs, "%d ", &(cases[i][j].sapin));
            fscanf(ifs, "%d ", &(cases[i][j].niveaudebatiment));
            fscanf(ifs, "%d ", &(cases[i][j].numerobatiment));
            fscanf(ifs, "%d ", &(cases[i][j].typedeconstruction));
            fscanf(ifs, "%d ", &(cases[i][j].hautgauche));
            fscanf(ifs, "%d ", &(cases[i][j].nombrehabitants));
            fscanf(ifs, "%d \n", &(cases[i][j].incendie));
        }
    }
    fclose(ifs);
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




