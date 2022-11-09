#ifndef ECE_CITY_1_B_CELLULE_H
#define ECE_CITY_1_B_CELLULE_H
typedef int typage;

struct _cellule {
    typage element;
    struct _cellule *suivant;
};

typedef struct _cellule* Cellule;
#endif //ECE_CITY_1_B_CELLULE_H
