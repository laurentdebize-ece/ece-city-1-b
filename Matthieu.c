//
// Created by gabdu on 02/11/2022.
//

#include "Matthieu.h"



void fonctionSauvegarde (char *fichier, Cases** cases, int pokedollars, bool regimepolitique){
    FILE *ifs = fopen(fichier, "w+");
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

void fonctionrecuperationSauvegarde (char *fichier, Cases** cases, int* pokedollars, int* regimepolitique){
    FILE *ifs = fopen(fichier, "r");
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

