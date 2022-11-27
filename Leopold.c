#include "Leopold.h"
#include "Gabriel.h"


void  BFS (Cases ***cases, int flux){
    int avancementtab=0;
    for (int j = 0; j < 45; ++j) {
        for (int k = 0; k < 35; ++k) {
            if(flux==0){
                (*cases)[j][k].CentralElecAssoc=-1;
                if((*cases)[j][k].typedeconstruction==CENTRALELEC && (*cases)[j][k].hautgauche){
                    avancementtab++;
                }
            }else{
                (*cases)[j][k].ChateauEauAssoc=-1;
                if((*cases)[j][k].typedeconstruction==CHATEAUEAU && (*cases)[j][k].hautgauche){
                    avancementtab++;
                }
            }

        }
    }
    int nbCentrales=avancementtab;
    Tableau *tabGeneral = (Tableau*) malloc((nbCentrales)*sizeof (Tableau));
    for (int j = 0; j < 45; ++j) {
        for (int k = 0; k < 35; ++k) {
            if(flux==0){
                if((*cases)[j][k].typedeconstruction==CENTRALELEC && (*cases)[j][k].hautgauche){
                    avancementtab--;
                    tabGeneral[avancementtab].numx=j;
                    tabGeneral[avancementtab].numy=k;

                }
            }else{
                if((*cases)[j][k].typedeconstruction==CHATEAUEAU && (*cases)[j][k].hautgauche){
                    avancementtab--;
                    tabGeneral[avancementtab].numx=j;
                    tabGeneral[avancementtab].numy=k;

                }
            }

        }
    }

    for (int i = 0; i < nbCentrales; ++i) {
        tabGeneral[i].tabX = (int*) calloc(1575, sizeof (int));
        tabGeneral[i].tabY = (int*) calloc(1575, sizeof (int));
        tabGeneral[i].tabNoir = (int**) malloc(45*sizeof (int*));

        for (int j = 0; j < 45; ++j) {
            tabGeneral[i].tabNoir[j] = (int*) malloc(35*sizeof (int));
            for (int k = 0; k < 35; ++k) {
                tabGeneral[i].tabNoir[j][k]=0;
                if(flux==0){
                    (*cases)[j][k].niveauElec=0;
                }else{
                    (*cases)[j][k].niveauEau=0;
                }

            }

        }
        tabGeneral[i].numerobatiment=(*cases)[tabGeneral[i].numx][tabGeneral[i].numy].numerobatiment;
        tabGeneral[i].numRoute = 0;
        tabGeneral[i].capaciteCentral = 5000;
    }
    int imax=0;
    int jmax=0;
    if(flux==0){
        imax=6;
        jmax=4;
    }else{
        imax=4;
        jmax=6;
    }

    for (int j = 0; j < nbCentrales; ++j) {
        for (int i = 0; i < imax; ++i) {
            if(tabGeneral[j].numx+i<=44  && tabGeneral[j].numy-1>=0 ){
                if ((*cases)[tabGeneral[j].numx+i][tabGeneral[j].numy-1].typedeconstruction == ROUTE && tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy-1] == 0){
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy-1] = 1;
                    tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx+i;
                    tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy-1;
                    tabGeneral[j].numRoute++;
                } else{
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy-1] = 1;
                }

            }
            if(tabGeneral[j].numx+i<=44  && tabGeneral[j].numy+jmax<=34){
                if ( (*cases)[tabGeneral[j].numx+i][tabGeneral[j].numy+jmax].typedeconstruction == ROUTE && tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy+jmax] == 0){
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy+jmax] = 1;
                    tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx +i;
                    tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy+jmax;
                    tabGeneral[j].numRoute++;
                } else {
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+i][tabGeneral[j].numy+jmax] = 1;
                }
            }
        }


        for (int i = 0; i < jmax; ++i) {
            if(tabGeneral[j].numx-1>=0  && tabGeneral[j].numy+i<=34){
                if ( (*cases)[tabGeneral[j].numx-1][tabGeneral[j].numy+i].typedeconstruction == ROUTE && tabGeneral[j].tabNoir[tabGeneral[j].numx-1][tabGeneral[j].numy+i] == 0){
                    tabGeneral[j].tabNoir[tabGeneral[j].numx-1][tabGeneral[j].numy+i] = 1;
                    tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx-1;
                    tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy+i;
                    tabGeneral[j].numRoute++;
                } else{
                    tabGeneral[j].tabNoir[tabGeneral[j].numx-1][tabGeneral[j].numy+i] = 1;
                }
            }
            if(tabGeneral[j].numx+imax<=44  && tabGeneral[j].numy+i<=34){
                if ((*cases)[tabGeneral[j].numx+imax][tabGeneral[j].numy+i].typedeconstruction == ROUTE && tabGeneral[j].tabNoir[tabGeneral[j].numx+imax][tabGeneral[j].numy+i] == 0){
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+imax][tabGeneral[j].numy+i] = 1;
                    tabGeneral[j].tabX[tabGeneral[j].numRoute] = tabGeneral[j].numx+ imax;
                    tabGeneral[j].tabY[tabGeneral[j].numRoute] = tabGeneral[j].numy+i;
                    tabGeneral[j].numRoute++;
                } else {
                    tabGeneral[j].tabNoir[tabGeneral[j].numx+imax][tabGeneral[j].numy+i] = 1;
                }
            }


        }
    }



    for (int i = 0; i < nbCentrales; ++i) {

        for (int j = 0; j < tabGeneral[i].numRoute; ++j) {

            route(cases, tabGeneral[i].tabX[j], tabGeneral[i].tabY[j], &(tabGeneral[i]));

            if(tabGeneral[i].capaciteCentral>0){
                verifierHabitation(cases, tabGeneral[i].tabX[j], tabGeneral[i].tabY[j], &(tabGeneral[i]), flux);
            }else{
                j=tabGeneral[i].numRoute;
            }
        }
        if(flux==0){
            (*cases)[tabGeneral[i].numx][tabGeneral[i].numy].niveauElec=tabGeneral[i].capaciteCentral;
        }else{
            (*cases)[tabGeneral[i].numx][tabGeneral[i].numy].niveauEau=tabGeneral[i].capaciteCentral;
        }

    }

    for (int i = 0; i < nbCentrales; ++i) {
        free(tabGeneral[i].tabX);
        free(tabGeneral[i].tabY);
        for (int j = 0; j < 35; ++j) {
            free(tabGeneral[i].tabNoir[j]);
        }
        free(tabGeneral[i].tabNoir);
        free(tabGeneral);
    }
}


void route (Cases ***cases, int x, int y, Tableau* tabGeneral){
    if(x>=0 && x<=44 && y-1>=0 && y-1<=34){
        if ((*cases)[x][y-1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y-1] == 0){
            tabGeneral->tabNoir[x][y-1] = 1;
            tabGeneral->tabX[tabGeneral->numRoute] = x;
            tabGeneral->tabY[tabGeneral->numRoute] = y-1;
            tabGeneral->numRoute++;
        } else tabGeneral->tabNoir[x][y-1] = 1;
    }
    if(x-1>=0 && x-1<=44 && y>=0 && y<=34 ){
        if ( (*cases)[x-1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x-1][y] == 0){
            tabGeneral->tabNoir[x-1][y] = 1;
            tabGeneral->tabX[tabGeneral->numRoute] = x-1;
            tabGeneral->tabY[tabGeneral->numRoute] = y;
            tabGeneral->numRoute++;
        }else tabGeneral->tabNoir[x-1][y] = 1;
    }
    if(x+1>=0 && x+1<=44 && y>=0 && y<=34){
        if ( (*cases)[x+1][y].typedeconstruction == ROUTE && tabGeneral->tabNoir[x+1][y] == 0){
            tabGeneral->tabNoir[x+1][y] = 1;
            tabGeneral->tabX[tabGeneral->numRoute] = x+1;
            tabGeneral->tabY[tabGeneral->numRoute] = y;
            tabGeneral->numRoute++;
        }else tabGeneral->tabNoir[x+1][y] = 1;
    }
    if(x>=0 && x<=44 && y+1>=0 && y+1<=34){
        if ( (*cases)[x][y+1].typedeconstruction == ROUTE && tabGeneral->tabNoir[x][y+1] == 0){
            tabGeneral->tabNoir[x][y+1] = 1;
            tabGeneral->tabX[tabGeneral->numRoute] = x;
            tabGeneral->tabY[tabGeneral->numRoute] = y+1;
            tabGeneral->numRoute++;
        }else tabGeneral->tabNoir[x][y+1] = 1;
    }
}


void verifierHabitation(Cases ***cases, int x, int y, Tableau *tabGeneral, int flux) {
    if (x>=0 && x<=44 && y-1>=0 && y-1<=34 && (*cases)[x][y - 1].typedeconstruction == HABITATION) {
        for (int i = 0; i < 45; ++i) {
            for (int j = 0; j < 35; ++j) {
                if (((*cases)[i][j].numerobatiment == (*cases)[x][y-1].numerobatiment) && ((*cases)[i][j].hautgauche == 1)){
                    deduireCapacite(cases,i,j,tabGeneral, flux);
                }
            }
        }
    }
    if (x-1>=0 && x-1<=44 && y>=0 && y<=34 && (*cases)[x-1][y].typedeconstruction == HABITATION) {
        for (int i = 0; i < 45; ++i) {
            for (int j = 0; j < 35; ++j) {
                if (((*cases)[i][j].numerobatiment == (*cases)[x-1][y].numerobatiment) && ((*cases)[i][j].hautgauche == 1)){
                    deduireCapacite(cases,i,j,tabGeneral, flux);
                }
            }
        }
    }
    if (x+1>=0 && x+1<=44 && y>=0 && y<=34 && (*cases)[x+1][y].typedeconstruction == HABITATION) {
        for (int i = 0; i < 45; ++i) {
            for (int j = 0; j < 35; ++j) {
                if (((*cases)[i][j].numerobatiment == (*cases)[x+1][y].numerobatiment) && ((*cases)[i][j].hautgauche == 1)){
                    deduireCapacite(cases,i,j,tabGeneral, flux);
                }
            }
        }
    }
    if (x>=0 && x<=44 && y+1>=0 && y+1<=34 && (*cases)[x][y + 1].typedeconstruction == HABITATION) {
        for (int i = 0; i < 45; ++i) {
            for (int j = 0; j < 35; ++j) {
                if (((*cases)[i][j].numerobatiment == (*cases)[x][y+1].numerobatiment) && ((*cases)[i][j].hautgauche == 1)){
                    deduireCapacite(cases,i,j,tabGeneral, flux);
                }
            }
        }
    }
}



void deduireCapacite(Cases ***cases, int x, int y, Tableau *tabGeneral, int flux){
    if(flux==0){
        if ((tabGeneral->capaciteCentral>=((*cases)[x][y].nombrehabitants)-(*cases)[x][y].niveauElec) && ((*cases)[x][y].niveauElec <(*cases)[x][y].nombrehabitants)) {
            tabGeneral->capaciteCentral -=  ((*cases)[x][y].nombrehabitants)-(*cases)[x][y].niveauElec;
            (*cases)[x][y].niveauElec = (*cases)[x][y].nombrehabitants;
            (*cases)[x][y].CentralElecAssoc=tabGeneral->numerobatiment;

        }else if ((*cases)[x][y].nombrehabitants==0){
            (*cases)[x][y].CentralElecAssoc=tabGeneral->numerobatiment;
        }
    }else{

        if ((tabGeneral->capaciteCentral>((*cases)[x][y].nombrehabitants)-(*cases)[x][y].niveauEau) && ((*cases)[x][y].niveauEau <(*cases)[x][y].nombrehabitants)) {
            tabGeneral->capaciteCentral -=  ((*cases)[x][y].nombrehabitants)-(*cases)[x][y].niveauEau;
            (*cases)[x][y].niveauEau = (*cases)[x][y].nombrehabitants;
            (*cases)[x][y].ChateauEauAssoc=tabGeneral->numerobatiment;
        }else if ((*cases)[x][y].nombrehabitants==0){
            (*cases)[x][y].ChateauEauAssoc=tabGeneral->numerobatiment;
        }else{
            if(((*cases)[x][y].nombrehabitants)!=0 && ((*cases)[x][y].niveauEau !=(*cases)[x][y].nombrehabitants)){
                (*cases)[x][y].niveauEau+=tabGeneral->capaciteCentral;
                tabGeneral->capaciteCentral=0;
                (*cases)[x][y].ChateauEauAssoc=tabGeneral->numerobatiment;
            }
        }

    }

}




