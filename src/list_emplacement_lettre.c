#include "fonctions_solveur.h"
#include <string.h>

linked_list_str_int* list_empl_create(){
    linked_list_str_int* p= malloc(sizeof(linked_list_str_int));
    (*p).first = NULL;
    return p;
}

void list_empl_destroy(linked_list_str_int* one_list){
    simple_cell_string_int* celluleasup = (*one_list).first;
    int stop = 0 ;
    while (stop == 0){
        if ((*celluleasup).next == NULL){
            free(celluleasup->lettre);
            free(celluleasup);
            stop = 1;
            free(one_list);
        }
        else{
            (*one_list).first = (*celluleasup).next;
            free(celluleasup->lettre);
            free(celluleasup);
            celluleasup = (*one_list).first;
        }
    }
    
}

bool list_empl_is_empty(linked_list_str_int* one_list){
    if((*one_list).first== NULL){
        return true;
    }
    else{
        return false;
    }
}

void list_empl_append(linked_list_str_int* one_list,char* one_value,int empl){
    int stop = 0;
    simple_cell_string_int *casse = malloc(sizeof(simple_cell_string_int));
    (*casse).lettre = one_value;
    (*casse).next = NULL;
    casse->emplacement = empl;
    simple_cell_string_int *i = (*one_list).first;
    if (i==NULL){
        (*one_list).first = casse;
    }
    else {
        while (stop==0){
        if ((*i).next==NULL){
            stop = 1;
            (*i).next = casse;
        }
        else{
            i = (*i).next;
        }
    }
    }
    
}

simple_cell_string_int* list_empl_get(linked_list_str_int* one_list, unsigned int index){
    simple_cell_string_int * casse = (*one_list).first; 
    for(unsigned int i = 0 ; i<index;i++){
        casse = (*casse).next;
    }
    return casse;
}

simple_cell_string_int* list_empl_get_str(linked_list_str_int* laadd,char* pattern){
    simple_cell_string_int* curseur = laadd->first;
    while(curseur != NULL){
        if(strcmp(pattern,curseur->lettre)==0){
            return curseur;
        }
        else{
            curseur = curseur->next;
        }
    }
    return NULL;
}

bool list_empl_contains(linked_list_str_int* laadd,char* pattern){

    if(list_empl_is_empty(laadd)){
        return false;
    }
    else{
        simple_cell_string_int* curseur = laadd->first;
        while(curseur != NULL){
            if(strcmp(curseur->lettre,pattern )==0){
                return true;
            }
            curseur = curseur->next;
        }
        return false;
    }
}




bool list_empl_contains_index(linked_list_str_int* laadd,int pattern){

    if(list_empl_is_empty(laadd)){
        return false;
    }
    else{
        simple_cell_string_int* curseur = laadd->first;
        while(curseur != NULL){
            if(pattern_to_index(curseur->lettre)==pattern){
                return true;
            }
            curseur = curseur->next;
        }
        return false;
    }
}
