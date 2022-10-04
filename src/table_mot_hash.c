#include "solveur.h"


int hash(char *some_value)
{
    int res = 0;
    int i = 0;

    for (i = 0; some_value[i] != '\0'; i++)
    {
        res = res + some_value[i];
    }
    return res;
}

table_mot_hash* table_mot_hash_create(int size){
    table_mot_hash* creatable = malloc(sizeof(table_mot_hash));
    (*creatable).taille = size;
    liste_mot_pattern **tablelist = malloc(size*(sizeof(liste_mot_pattern*)));
    for (int i = 0;i<size;i++){
        tablelist[i] = liste_mot_pattern_create();
    }
    (*creatable).table = tablelist;
    return creatable;
}

void table_mot_hash_destroy(table_mot_hash* one_table){
    int n = one_table->taille;
    for(int i=0;i<n;i++){
        
        liste_mot_pattern_destroy((one_table->table)[i]);
    }
    
    free(one_table->table);
    free(one_table);

}

int table_mot_hash_indexof(table_mot_hash* one_table, char* one_key){
    int indice = hash(one_key);
    int i = indice;
    return i%(one_table->taille);
}

bool table_mot_hash_add(table_mot_hash* one_table,char* one_key,double* one_value){
    int indice = table_mot_hash_indexof(one_table,one_key);
    if(table_mot_hash_contains(one_table,one_key)){
        return false;
    }
    else{
        liste_mot_pattern_append(((one_table->table)[indice]),one_key,one_value);
        return true;
    }
}

bool table_mot_hash_contains(table_mot_hash* one_table,char* one_key){

    int i = table_mot_hash_indexof(one_table,one_key);
    return liste_mot_pattern_contains(((one_table->table)[i]),one_key);
}

double* table_mot_hash_get(table_mot_hash* one_table, char* one_key){
    if (table_mot_hash_contains(one_table,one_key)){
        int i = table_mot_hash_indexof(one_table,one_key);
        return liste_mot_pattern_find(((one_table->table)[i]),one_key);
    }
    else{
        return NULL;
    }
}
