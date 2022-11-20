#include "Leopold.h"
#include "Gabriel.h"
#include "Matthieu.h"
bool batimentBFSRoute (Cases **cases, int i, int j){
    if(cases[i][j].hautgauche == 1 && cases[i-1][j].typedeconstruction == ROUTE){
        return route(cases, i-1,j);
    }else if(cases[i][j].hautgauche == 1 && cases[i-1][j+1].typedeconstruction == ROUTE){
        return route(cases, i-1,j+1);
    }else if(cases[i][j].hautgauche == 1 && cases[i-1][j+2].typedeconstruction == ROUTE){
        return route(cases, i-1,j+2);
    }else if(cases[i][j].hautgauche == 1 && cases[i-1][j+3].typedeconstruction == ROUTE){
        return route(cases, i-1,j+3);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j].typedeconstruction == ROUTE){
        return route(cases, i+5,j);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j+1].typedeconstruction == ROUTE){
        return route(cases, i+5,j+1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j+2].typedeconstruction == ROUTE){
        return route(cases, i+5,j+2);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j+3].typedeconstruction == ROUTE){
        return route(cases, i+5,j+3);
    }else if(cases[i][j].hautgauche == 1 && cases[i][j-1].typedeconstruction == ROUTE){
        return route(cases, i,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+1][j-1].typedeconstruction == ROUTE){
        return route(cases, i+1,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+2][j-1].typedeconstruction == ROUTE){
        return route(cases, i+2,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+3][j-1].typedeconstruction == ROUTE){
        return route(cases, i+3,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+4][j-1].typedeconstruction == ROUTE){
        return route(cases, i+4,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j-1].typedeconstruction == ROUTE){
        return route(cases, i+5,j-1);
    }else if(cases[i][j].hautgauche == 1 && cases[i][j+4].typedeconstruction == ROUTE){
        return route(cases, i,j+4);
    }else if(cases[i][j].hautgauche == 1 && cases[i+1][j+4].typedeconstruction == ROUTE){
        return route(cases, i+1,j+4);
    }else if(cases[i][j].hautgauche == 1 && cases[i+2][j+4].typedeconstruction == ROUTE){
        return route(cases, i+2,j+4);
    }else if(cases[i][j].hautgauche == 1 && cases[i+3][j+4].typedeconstruction == ROUTE){
        return route(cases, i+3,j+4);
    }else if(cases[i][j].hautgauche == 1 && cases[i+4][j+4].typedeconstruction == ROUTE){
        return route(cases, i+4,j+4);
    }else if(cases[i][j].hautgauche == 1 && cases[i+5][j+4].typedeconstruction == ROUTE){
        return route(cases, i+5,j+4);
    }else return 0;
}

