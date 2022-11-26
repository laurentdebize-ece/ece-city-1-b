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

/*bool route (Cases **cases, int i, int j){
    if (cases[i][j].typedeconstruction == 1 && cases[i][j-1].typedeconstruction == 1){
        }if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE){
        route(cases, i, j-1);//BFS
        }else if (cases[i][j].typedeconstruction == 1 && cases[i-1][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i-1, j);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1 && cases[i+1][j].typedeconstruction == 1){
        if (cases[i][j-1].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i][j-1].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i + 1, j);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1 && cases[i][j+1].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE){
            route(cases, i, j+1);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i, j);//BFS
        }
    }else return 0;

}
 */

/*
void  BFSEau (Cases **cases, int numCentralEau, int x, int y){
    Tableau *tabGeneral = (Tableau*) malloc(sizeof (Tableau));
    tabGeneral->tabX = (int*) calloc(0, 1575 * sizeof (int));
    tabGeneral->tabY = (int*) calloc(0, 1575 * sizeof (int));
    tabGeneral->tabNoir = (bool**) calloc(0, sizeof (Tableau*));
    tabGeneral->numRoute = 0;
    for (int i = 0; i < 6; ++i) {
        if (cases[x+i][y-1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+i][y-1] == 0){
            tabGeneral->tabNoir[x+i][y-1] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+i;
            tabGeneral->tabY[*tabGeneral->numRoute] = y-1;
            tabGeneral->numRoute++;

        } else tabGeneral->tabNoir[x+i][y-1] = 1;
    }
    for (int i = 0; i < 6; ++i) {
        if (cases[x+i][y+4].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+i][y+4] == 0){
            tabGeneral->tabNoir[x+i][y+4] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+i;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+4;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x+i][y+4] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (cases[x-1][y+i].typedeconstruction == ROUTE && tabGeneral->tabNoir[x-1][y+i] == 0){
            tabGeneral->tabNoir[x-1][y+i] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x-1;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+i;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x-1][y+i] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (cases[x+5][y+i].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+5][y+i] == 0){
            tabGeneral->tabNoir[x-1][y+i] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+5;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+i;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x+5][y+i] = 1;
    }
    for (int i = 0; i < *tabGeneral->numRoute; ++i) {
        route(cases,tabGeneral->tabX[i], tabGeneral->tabY[i], tabGeneral);

    }

}

void route (Cases **cases, int x, int y, Tableau *tabGeneral){
    if (cases[x][y-1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y-1] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x][y-1] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x;
        tabGeneral->tabY[*tabGeneral->numRoute] = y-1;
        tabGeneral->numRoute++;
    } else tabGeneral->tabNoir[x][y-1] = 1;
    if (cases[x-1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x-1][y] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x-1][y] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x-1;
        tabGeneral->tabY[*tabGeneral->numRoute] = y;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x-1][y] = 1;
    if (cases[x+1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+1][y] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x+1][y] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x+1;
        tabGeneral->tabY[*tabGeneral->numRoute] = y;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x+1][y] = 1;
    if (cases[x][y+1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y+1] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x][y+1] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x;
        tabGeneral->tabY[*tabGeneral->numRoute] = y+1;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x][y+1] = 1;
}

void verifierHabitation (Cases **cases, int x, int y, Tableau *tabGeneral){
    int distance;
    if (cases[x][y-1].typedeconstruction == HABITATION ){
        distance = tabGeneral->numRoute;
    }
    if (cases[x-1][y].typedeconstruction == HABITATION){

    }
    if (cases[x+1][y].typedeconstruction == HABITATION){

    }
    if (cases[x][y+1].typedeconstruction == HABITATION){

    }
}*/

void  BFSEau (Cases **cases) {
    int avancementtab = 0;
    for (int j = 0; j < 45; ++j) {
        for (int k = 0; k < 35; ++k) {
            if (cases[j][k].typedeconstruction == CHATEAUEAU && cases[j][k].hautgauche) {
                avancementtab++;
            }
        }
    }
    int nbCentralesEau = avancementtab;
    Tableau *tabGeneral = (Tableau *) malloc((nbCentralesEau) * sizeof(Tableau));
//    Batiment *nbBatiment = (Batiment*) malloc((nbCentralesEau)*sizeof(Batiment));
    for (int j = 0; j < 45; ++j) {
        for (int k = 0; k < 35; ++k) {
            if (cases[j][k].typedeconstruction == CHATEAUEAU && cases[j][k].hautgauche) {
                avancementtab--;
                tabGeneral[avancementtab].numx = j;
                tabGeneral[avancementtab].numy = k;


            }
        }
    }
    for (int i = 0; i < nbCentralesEau; ++i) {
        tabGeneral[i].tabX = (int *) calloc(1575, sizeof(int));
        tabGeneral[i].tabY = (int *) calloc(1575, sizeof(int));
        tabGeneral[i].tabNoir = (int **) malloc(45 * sizeof(int *));
        tabGeneral[i].nbRoutes = (int **) malloc(45 * sizeof(int));
        for (int j = 0; j < 35; ++j) {
            tabGeneral[i].tabNoir[j] = (int *) malloc(35 * sizeof(int));
            tabGeneral[i].nbRoutes[j] = (int *) malloc(35 * sizeof(int));

        }
        tabGeneral[i].numRoute = 0;
        tabGeneral[i].capaciteCentral = 5000;
    }
    for (int j = 0; j < nbCentralesEau; ++j) {
        for (int i = 0; i < 4; ++i) {

            if (cases[tabGeneral[j].numx + i][tabGeneral[j].numy - 1].typedeconstruction == ROUTE &&
                tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy - 1] == 0) {
                tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy - 1] = 1;
                tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx + i;
                tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy - 1;
                tabGeneral[j].numRoute++;
                tabGeneral[j].nbRoutes[tabGeneral[j].numx + i][tabGeneral[j].numy - 1] = 1;

            } else tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy - 1] = 1;

            if (cases[tabGeneral[j].numx + i][tabGeneral[j].numy + 6].typedeconstruction == ROUTE &&
                tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy + 4] == 0) {
                tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy + 6] = 1;
                tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx + i;
                tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy + 6;
                tabGeneral[j].numRoute++;
                tabGeneral[j].nbRoutes[tabGeneral[j].numx + i][tabGeneral[j].numy + 6] = 1;

            } else tabGeneral[j].tabNoir[tabGeneral[j].numx + i][tabGeneral[j].numy + 6] = 1;
        }


        for (int i = 0; i < 6; ++i) {
            if (cases[tabGeneral[j].numx - 1][tabGeneral[j].numy + i].typedeconstruction == ROUTE &&
                tabGeneral[j].tabNoir[tabGeneral[j].numx - 1][tabGeneral[j].numy + i] == 0) {
                tabGeneral[j].tabNoir[tabGeneral[j].numx - 1][tabGeneral[j].numy + i] = 1;
                tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx - 1;
                tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy + i;
                tabGeneral[j].numRoute++;
                tabGeneral[j].nbRoutes[tabGeneral[j].numx - 1][tabGeneral[j].numy + i] = 1;

            } else tabGeneral[j].tabNoir[tabGeneral[j].numx - 1][tabGeneral[j].numy + i] = 1;


            if (cases[tabGeneral[j].numx + 4][tabGeneral[j].numy + i].typedeconstruction == ROUTE &&
                tabGeneral[j].tabNoir[tabGeneral[j].numx + 6][tabGeneral[j].numy + i] == 0) {
                tabGeneral[j].tabNoir[tabGeneral[j].numx + 4][tabGeneral[j].numy + i] = 1;
                tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx + 4;
                tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy + i;
                tabGeneral[j].numRoute++;
                tabGeneral[j].nbRoutes[tabGeneral[j].numx + 4][tabGeneral[j].numy + i] = 1;

            } else tabGeneral[j].tabNoir[tabGeneral[j].numx + 4][tabGeneral[j].numy + i] = 1;
        }
    }


    for (int i = 0; i < nbCentralesEau; ++i) {
        for (int j = 0; j < tabGeneral[j].numRoute; ++j) {
            route(cases, tabGeneral[j].tabX[i], tabGeneral[j].tabY[i], tabGeneral);
            /*if (verifierHabitation(cases, tabGeneral[j].tabX[i], tabGeneral[j].tabY[i], tabGeneral)){
                printf("  %d  ", tabGeneral[j].nbRoutes[tabGeneral[j].tabX[i]][tabGeneral[j].tabY[i]]);
            }

        }
    }*/
            for (int i = 0; i < nbCentralesEau; ++i) {
                free(tabGeneral[i].tabX);
                free(tabGeneral[i].tabY);
                free(tabGeneral[i].tabNoir);
                free(tabGeneral[i].numRoute);
                free(tabGeneral);
                free(tabGeneral[i].nbRoutes);
            }
        }
    }
}


/*bool route (Cases **cases, int i, int j){
    if (cases[i][j].typedeconstruction == 1 && cases[i][j-1].typedeconstruction == 1){
        }if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE){
        route(cases, i, j-1);//BFS
        }else if (cases[i][j].typedeconstruction == 1 && cases[i-1][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i-1, j);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1 && cases[i+1][j].typedeconstruction == 1){
        if (cases[i][j-1].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i][j-1].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i + 1, j);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1 && cases[i][j+1].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }else if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE){
            route(cases, i, j+1);//BFS
        }
    }else if (cases[i][j].typedeconstruction == 1){
        if (cases[i+1][j].typedeconstruction == HABITATION || cases[i-1][j].typedeconstruction == HABITATION || cases[i][j+1].typedeconstruction == HABITATION || cases[i][j-1].typedeconstruction == HABITATION){
            return 1;
        }if (cases[i+1][j].typedeconstruction == ROUTE || cases[i-1][j].typedeconstruction == ROUTE || cases[i][j-1].typedeconstruction == ROUTE || cases[i][j+1].typedeconstruction == ROUTE) {
            route(cases, i, j);//BFS
        }
    }else return 0;

}
 */

/*
void  BFSEau (Cases **cases, int numCentralEau, int x, int y){
    Tableau *tabGeneral = (Tableau*) malloc(sizeof (Tableau));
    tabGeneral->tabX = (int*) calloc(0, 1575 * sizeof (int));
    tabGeneral->tabY = (int*) calloc(0, 1575 * sizeof (int));
    tabGeneral->tabNoir = (bool**) calloc(0, sizeof (Tableau*));
    tabGeneral->numRoute = 0;
    for (int i = 0; i < 6; ++i) {
        if (cases[x+i][y-1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+i][y-1] == 0){
            tabGeneral->tabNoir[x+i][y-1] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+i;
            tabGeneral->tabY[*tabGeneral->numRoute] = y-1;
            tabGeneral->numRoute++;

        } else tabGeneral->tabNoir[x+i][y-1] = 1;
    }
    for (int i = 0; i < 6; ++i) {
        if (cases[x+i][y+4].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+i][y+4] == 0){
            tabGeneral->tabNoir[x+i][y+4] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+i;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+4;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x+i][y+4] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (cases[x-1][y+i].typedeconstruction == ROUTE && tabGeneral->tabNoir[x-1][y+i] == 0){
            tabGeneral->tabNoir[x-1][y+i] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x-1;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+i;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x-1][y+i] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (cases[x+5][y+i].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+5][y+i] == 0){
            tabGeneral->tabNoir[x-1][y+i] = 1;
            tabGeneral->tabX[*tabGeneral->numRoute] = x+5;
            tabGeneral->tabY[*tabGeneral->numRoute] = y+i;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x+5][y+i] = 1;
    }
    for (int i = 0; i < *tabGeneral->numRoute; ++i) {
        route(cases,tabGeneral->tabX[i], tabGeneral->tabY[i], tabGeneral);

    }

}

void route (Cases **cases, int x, int y, Tableau *tabGeneral){
    if (cases[x][y-1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y-1] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x][y-1] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x;
        tabGeneral->tabY[*tabGeneral->numRoute] = y-1;
        tabGeneral->numRoute++;
    } else tabGeneral->tabNoir[x][y-1] = 1;
    if (cases[x-1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x-1][y] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x-1][y] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x-1;
        tabGeneral->tabY[*tabGeneral->numRoute] = y;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x-1][y] = 1;
    if (cases[x+1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+1][y] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x+1][y] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x+1;
        tabGeneral->tabY[*tabGeneral->numRoute] = y;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x+1][y] = 1;
    if (cases[x][y+1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y+1] == 0 && (x-1>=0) && (x+1<=45) && (y+1<=35) && (y-1>=0)){
        tabGeneral->tabNoir[x][y+1] = 1;
        tabGeneral->tabX[*tabGeneral->numRoute] = x;
        tabGeneral->tabY[*tabGeneral->numRoute] = y+1;
        tabGeneral->numRoute++;
    }else tabGeneral->tabNoir[x][y+1] = 1;
}

void verifierHabitation (Cases **cases, int x, int y, Tableau *tabGeneral){
    int distance;
    if (cases[x][y-1].typedeconstruction == HABITATION ){
        distance = tabGeneral->numRoute;
    }
    if (cases[x-1][y].typedeconstruction == HABITATION){

    }
    if (cases[x+1][y].typedeconstruction == HABITATION){

    }
    if (cases[x][y+1].typedeconstruction == HABITATION){

    }
}*/




