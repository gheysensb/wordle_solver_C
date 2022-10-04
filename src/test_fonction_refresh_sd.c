#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "solveur.h"

int armand_main(void){
    /*
    linked_list_str_t *dico = list_dico_create();
    table_mot_hash* table_test = table_mot_hash_create(2);
    char* mot1 = malloc(sizeof(char[10]));
    char* mot2 = malloc(sizeof(char[10]));
    char* mot3 = malloc(sizeof(char[10]));
    char* mot4 = malloc(sizeof(char[10]));
    char* mot5 = malloc(sizeof(char[10]));
    char* mot6 = malloc(sizeof(char[10]));
    char* char_copy = "armand";
    strcpy(mot1,char_copy);
    char* char_copy2 = "bouveron";
    strcpy(mot2,char_copy2);
    char* char_copy3 = "a";
    strcpy(mot3,char_copy3);
    char* char_copy4 = "b";
    strcpy(mot4,char_copy4);
    char* char_copy5 = "c";
    strcpy(mot5,char_copy5);
    char* char_copy6 = "d";
    strcpy(mot6,char_copy6);
    list_dico_append(dico,mot1);
    list_dico_append(dico,mot2);
    list_dico_append(dico,mot3);
    list_dico_append(dico,mot4);
    list_dico_append(dico,mot5);
    list_dico_append(dico,mot6);

    //ajout des pattern armand
    table_pattern* TA = table_pattern_create(2);
    list_append(TA->table[0],get_pointeur(dico,mot3));
    list_append(TA->table[0],get_pointeur(dico,mot4));
    list_append(TA->table[1],get_pointeur(dico,mot5));
    list_append(TA->table[1],get_pointeur(dico,mot6));
    table_mot_hash_add(table_test,mot1,TA);
    
    //ajout des pattern ab
    table_pattern* TB = table_pattern_create(2);
    list_append(TB->table[0],get_pointeur(dico,mot3));
    list_append(TB->table[0],get_pointeur(dico,mot5));
    //list_append(TB->table[1],get_pointeur(dico,mot4));
    //list_append(TB->table[1],get_pointeur(dico,mot6));
    table_mot_hash_add(table_test,mot2,TB);*/

    /* table_pattern* restants = table_mot_hash_get(table_test,mot1);
    printf("restants = \n");
    list_print(restants->table[0]);
    list_print(restants->table[1]);
    table_pattern* possibles = table_mot_hash_get(table_test,mot2);
    printf("possibles = \n");
    list_print(possibles->table[0]);
    list_print(possibles->table[1]); */
    /*
    int pattern = 0;
    refresh_sd(dico, table_test, mot2, pattern);*/
    //refresh_restants(table_test, mot1, mot2, pattern);
    /* printf("11\n");
    restants = table_mot_hash_get(table_test,mot1);
    printf("12\n");
    printf("%d est le nombre de table dans restants\n", restants->taille);
    list_print(restants->table[0]);
    list_print(restants->table[1]); */
   /*  for (int i=0; i<restants->taille; i++) {
        printf("13 : %d\n", i);
        list_print(restants->table[i]);
    } */

    //destroy   
    //printf("Destroy incoming\n");
    /*
    table_mot_hash_destroy(table_test);
    list_dico_destroy(dico);*/
    //printf("SUCCESS\n");
    return EXIT_SUCCESS;
}

