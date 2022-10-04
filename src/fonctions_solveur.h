#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solveur.h"

// liste pour les mots restants

typedef struct linked_list_str_int{
    struct simple_cell_string_int * first;
}linked_list_str_int;

typedef struct simple_cell_string_int{
    struct simple_cell_string_int* next;
    int emplacement; //nombre de mot qui découle de ce pattern
    char* lettre; //pattern
}simple_cell_string_int;

//fonctions structure

linked_list_str_int* list_empl_create();
void list_empl_destroy(linked_list_str_int* one_list);
bool list_empl_is_empty(linked_list_str_int* one_list);
void list_empl_append(linked_list_str_int* one_list,char* one_value,int empl);
simple_cell_string_int* list_empl_get(linked_list_str_int* one_list, unsigned int index);
bool list_empl_contains(linked_list_str_int* laadd,char* pattern);
bool list_empl_contains_index(linked_list_str_int* laadd,int pattern);
simple_cell_string_int* list_empl_get_str(linked_list_str_int* laadd,char* pattern);
//fin fonctions

double entropy(linked_list_str_int* one_table,double nombremotsrestants);

bool possibles(char* mot, char* pattern, char* mot_test);
