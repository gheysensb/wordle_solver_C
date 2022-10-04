#include "solveur.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
linked_list_str_t* list_dico_create(){
    linked_list_str_t* p= malloc(sizeof(linked_list_str_t));
    (*p).first = NULL;
    return p;
}

bool list_dico_is_empty(linked_list_str_t* one_list){
    if((*one_list).first== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void list_dico_prepend(linked_list_str_t* one_list,char* one_value){
    simple_cell_string *newcase = malloc(sizeof(simple_cell_string));
    (*newcase).x = one_value;
    (*newcase).next = (*one_list).first;
    (*one_list).first = newcase;
}

char* list_dico_first(linked_list_str_t* one_list){
    return ((*(*one_list).first)).x;
}

void list_dico_append(linked_list_str_t* one_list,char* one_value){
    int stop = 0;
    simple_cell_string *casse = malloc(sizeof(simple_cell_string));
    (*casse).x = one_value;
    (*casse).next = NULL;
    simple_cell_string *i = (*one_list).first;
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

char* list_dico_last(linked_list_str_t* one_list){
    simple_cell_string *i =(*one_list).first; 
    while (true){
        if ((*i).next == NULL){
            return (*i).x;
        }
        else {
            i = (*i).next;
        }
    }
}

void list_dico_print(linked_list_str_t* one_list){
    if (list_dico_is_empty(one_list)==1){
        printf("[ ]\n");
    }
    else{
        printf("[ %s",(*(*one_list).first).x);
        int stop = 0;
        if ((*(*one_list).first).next == NULL){
            printf(" ]\n");
        }
        else{
          simple_cell_string * i= (*(*one_list).first).next;
        while (stop == 0){
            if((*i).next == NULL){
                printf(", %s]\n",(*i).x);
                stop = 1;
            }
            else{
                printf(", %s",(*i).x);
                i = (*i).next;
            }
        }  
        }
        
    }
}

void list_dico_insert(linked_list_str_t* one_list, char* one_value, unsigned int index){
    simple_cell_string * casse = (*one_list).first; 
    for(unsigned int i = 0 ; i<index;i++){
        casse = (*casse).next;
    }
    (*casse).x = one_value;
}

char* list_dico_get(linked_list_str_t* one_list, unsigned int index){
    simple_cell_string * casse = (*one_list).first; 
    for(unsigned int i = 0 ; i<index;i++){
        casse = (*casse).next;
    }
    return (*casse).x;
}

unsigned int list_dico_index_of(linked_list_str_t* one_list,char* one_value){
    int i = 0;
    int stop = 0;
    simple_cell_string *casse = (*one_list).first;
    while (stop == 0){
        if (strcmp(one_value,casse->x)==0){
            return i;
        }
        else{
            i++;
            casse = (*casse).next;
        }
    }
    return 0;
}

void list_dico_destroy(linked_list_str_t* one_list){
    if(list_dico_is_empty(one_list)){
        free(one_list);
    }
    else{
       simple_cell_string* celluleasup = (*one_list).first;
    int stop = 0 ;
    
    while (stop == 0){
        if ((*celluleasup).next == NULL){
            free(celluleasup->x);
            free(celluleasup);
            stop = 1;
            free(one_list);
        }
        else{
            (*one_list).first = (*celluleasup).next;
            free(celluleasup->x);
            free(celluleasup);
            celluleasup = (*one_list).first;
        }
    } 
    }
    
    
}

linked_list_str_t*  list_dico_load(char* name_file){
    FILE *f;
    linked_list_str_t* dico = list_dico_create();
    char str[50];
    f= fopen(name_file,"r");
    if(f==NULL){
        printf("problème nom de fichier ! \n");
        exit(1);
    }
    while(fgets(str,50,f) != NULL){
        str[strlen(str)-1]='\0';
        char* point = malloc(sizeof(char[50]));
        strcpy(point,str);
        list_dico_append(dico,point);
    }
    fclose(f);
    return dico;
}

int list_dico_length(linked_list_str_t *dico){
    simple_cell_string* curseur = dico->first;
    if(curseur == NULL){
        return 0;
    }
    int somme = 0;
    while(curseur != NULL){
        somme++;
        curseur = curseur->next;
    }
    return somme;
}
