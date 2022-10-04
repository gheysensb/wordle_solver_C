#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solveur.h"
/*
int main(void){
    linked_list_str_t *dico = list_dico_create();
    table_mot_hash* table_test = table_mot_hash_create(2);
    list_dico_append(dico,"armand");
    list_dico_append(dico,"tibo");
    list_dico_append(dico,"baptiste");
    list_dico_append(dico,"nico");
    //ajout des pattern armand
    table_pattern* TA = table_pattern_create(2);
    list_append(TA->table[0],get_pointeur(dico,"tibo"));
    list_append(TA->table[0],get_pointeur(dico,"nico"));
    list_append(TA->table[0],get_pointeur(dico,"nico"));
    list_append(TA->table[0],get_pointeur(dico,"nico"));
    list_append(TA->table[1],get_pointeur(dico,"tibo"));
    list_append(TA->table[1],get_pointeur(dico,"nico"));
    list_append(TA->table[1],get_pointeur(dico,"nico"));
    table_mot_hash_add(table_test,"armand",TA);

    //ajout des pattern
    table_pattern* TT = table_pattern_create(2);
    list_append(TT->table[0],get_pointeur(dico,"tibo"));
    list_append(TT->table[1],get_pointeur(dico,"tibo"));
    
 
    table_mot_hash_add(table_test,"tibo",TT);

    //ajout des pattern
    table_pattern* TN = table_pattern_create(2);   
    list_append(TN->table[0],get_pointeur(dico,"tibo"));
    table_mot_hash_add(table_test,"nico",TN);

    //ajout des pattern
    table_pattern* TB = table_pattern_create(2);
    list_append(TB->table[0],get_pointeur(dico,"tibo"));
    list_append(TB->table[0],get_pointeur(dico,"nico"));
    list_append(TB->table[0],get_pointeur(dico,"tibo"));
    list_append(TB->table[1],get_pointeur(dico,"tibo"));
    table_mot_hash_add(table_test,"baptiste",TB);

    //ajout 
    char*  best = best_mot(dico,table_test);
    printf("le mot meilleur : %s\n",best);
    table_mot_hash_destroy(table_test);
    list_dico_destroy(dico);
    return EXIT_SUCCESS;
}*/

