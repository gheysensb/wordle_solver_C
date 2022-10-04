#include "solveur.h"
#include <err.h>
#include <errno.h>
#include <assert.h>

liste_mot_pattern* liste_mot_pattern_create(){
    liste_mot_pattern*  liste= malloc(sizeof(liste_mot_pattern)); //allouage de la memoir pour un pointeur vers un type linked list int
    liste->first=NULL; //on change la valeur pointé par liste donc first
    return liste;
}

bool liste_mot_pattern_is_empty(liste_mot_pattern *one_list){ //
    if (one_list->first==NULL){ // si la valeur pointer par la list est null elle est vide
        return true;
    }
    else{ // sinnon elle n'est pas vide
        return false;
    }
}
void liste_mot_pattern_destroy(liste_mot_pattern *one_list) {
    assert(one_list != NULL);

    cellule_mot_pattern *current = one_list->first;
    cellule_mot_pattern *tmp = NULL;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp->pattern);
        free(tmp);
    }
    free(one_list);
}
void liste_mot_pattern_append(liste_mot_pattern *one_list, char *one_key, double* table)
{
    assert(one_list != NULL);

    cellule_mot_pattern *new_element = calloc(1, sizeof(cellule_mot_pattern));
    if (new_element == NULL)
    {
        err(ENOMEM, "can't allocate a new element");
    }
    new_element->mot = one_key;
    new_element->pattern = table;
    new_element->next = NULL;

    cellule_mot_pattern *current = one_list->first;
    if (current == NULL)
    {
        one_list->first = new_element;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_element;
}

bool liste_mot_pattern_contains(liste_mot_pattern *one_list, char *one_key){
    if (liste_mot_pattern_is_empty(one_list)){
        return false;
    }
    else{
       cellule_mot_pattern *current = one_list->first;
    while (current!=NULL){
        if (current->mot==one_key)
        {
            return 1;
        }
        current=current->next;
    }
    return 0; 
    }
    
}

double* liste_mot_pattern_find(liste_mot_pattern *one_list, char *one_key)
{
    cellule_mot_pattern *current = one_list->first;
    while (current!=NULL){
        if (current->mot==one_key)
        {
            return current->pattern;
        }
        current=current->next;
    
    }
    return NULL;
}
