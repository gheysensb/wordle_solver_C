#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct cellule_mot_pattern{ //nico
    char* mot;
    double* pattern;//entropie
    struct cellule_mot_pattern* next;
}cellule_mot_pattern;

//Elle contient toute les cellules qui associe les mot avec leur entropie
typedef struct liste_mot_pattern{ //nico
    cellule_mot_pattern* first;
}liste_mot_pattern;

//Elle associe le mot avec la sous liste ou il se trouve 
typedef struct table_mot_hash{ //baptiste
    int taille; //taille de la table (nombre de hash)
    liste_mot_pattern** table;
}table_mot_hash;

// dico
typedef struct simple_cell_string{
    char* x;
    struct simple_cell_string* next;
}simple_cell_string;

typedef struct linked_list_str_t{
    simple_cell_string* first;
}linked_list_str_t;

linked_list_str_t* list_dico_create();
bool list_dico_is_empty(linked_list_str_t* one_list);
void list_dico__prepend(linked_list_str_t* one_list, char* one_value);
char* list_dico_first(linked_list_str_t* one_list);
void list_dico_append(linked_list_str_t* one_list, char* one_value);
void list_dico_print(linked_list_str_t* one_list);
void list_dico_insert(linked_list_str_t* one_list, char* one_value, unsigned int index);
char* list_dico_get(linked_list_str_t* one_list, unsigned int index);
unsigned int list_dico_index_of(linked_list_str_t* one_list, char* one_value);
void list_dico_destroy(linked_list_str_t* one_list);
linked_list_str_t*  list_dico_load(char* name_file);

//LA LISTE MOT_PATTERN = liste mot+entropie

liste_mot_pattern* liste_mot_pattern_create();
bool liste_mot_pattern_is_empty(liste_mot_pattern *one_list);
void liste_mot_pattern_destroy(liste_mot_pattern *one_list);
void liste_mot_pattern_append(liste_mot_pattern *one_list, char *one_key, double* table);
bool liste_mot_pattern_contains(liste_mot_pattern *one_list, char *one_key);
double* liste_mot_pattern_find(liste_mot_pattern *one_list, char *one_key);

//LA TABLE MOT_HASH

int hash(char *some_value);
table_mot_hash* table_mot_hash_create(int size);
void table_mot_hash_destroy(table_mot_hash* one_table);
int table_mot_hash_indexof(table_mot_hash* one_table,char* one_key);
bool table_mot_hash_add(table_mot_hash* one_table,char* one_key,double* one_value);
bool table_mot_hash_contains(table_mot_hash* one_table,char* one_key);
double* table_mot_hash_get(table_mot_hash* one_table,char* one_key);

//FONCTIONS DU PROGRAMME


char* best_mot(linked_list_str_t* dico,table_mot_hash* one_table);
simple_cell_string* get_pointeur(linked_list_str_t* dico, char* mot);
char* index_to_pattern(int i,int nombredelettre);
int pattern_to_index(char* mot);

table_mot_hash* traitement(linked_list_str_t* dico, linked_list_str_t* mot_restants);

char* find_pattern(char* motatest,char* motatrouve);
linked_list_str_t* actu(linked_list_str_t* mot_restants,char* proposition,char* reponse);
char* namefile(char* nb);
int list_dico_length(linked_list_str_t *dico);
bool verif_reponse(char* reponse);
