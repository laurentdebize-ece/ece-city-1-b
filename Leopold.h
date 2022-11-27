#ifndef ECE_CITY_1_B_LEOPOLD_H
#define ECE_CITY_1_B_LEOPOLD_H
#include "Gabriel.h"
bool batimentBFSRoute (Cases **cases, int i, int j);
typedef struct{
    int* tabX;
    int* tabY;
    int** tabNoir;
    int nbCentralEau, nbCentralElec;
    int numRoute;
    int numx;
    int numy;
    int capaciteCentral;
    int numerobatiment;
}Tableau;


void  BFS (Cases ***cases, int flux);
void  BFSCaserne (Cases ***cases);

void route (Cases ***cases, int x, int y, Tableau* tabGeneral, int protectionfeu);
void verifierHabitation (Cases ***cases, int x, int y, Tableau* tabGeneral, int flux);
void deduireCapacite(Cases ***cases, int x, int y, Tableau* tabGeneral, int flux);




#endif //ECE_CITY_1_B_LEOPOLD_H
