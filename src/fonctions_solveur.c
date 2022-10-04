#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "fonctions_solveur.h"

//FONCTIONS DU PROGRAMME

double entropy(linked_list_str_int* one_table,double nombremotsrestants){
    double S = 0;
    if(list_empl_is_empty(one_table)){
        return 0;
    }
    simple_cell_string_int* curseur = one_table ->first; //élément de linked_list_str_int
    while(curseur != NULL){
        int longeur= curseur->emplacement;
        double p = (double)longeur / nombremotsrestants;
        S = S + (p) *log2(1/p); 
        curseur = curseur->next;
    }
    return S;
}

char* best_mot(linked_list_str_t* dico,table_mot_hash* one_table){
    double max_entropy = 0;
    char* best_mot;
    simple_cell_string* cursor = dico->first;
    while(cursor !=NULL){
        double* pattern_en_cours = table_mot_hash_get(one_table,cursor->x);
        double entropie_curseur = (double)pattern_en_cours[0];
        if(entropie_curseur>max_entropy){
            max_entropy = entropie_curseur;
            best_mot = cursor->x;
        }
        cursor = cursor->next;
    }
    return best_mot;
}

simple_cell_string* get_pointeur(linked_list_str_t* dico,char* mot){ //ne sert plus
    int stop = 0;
    simple_cell_string *casse = (*dico).first;
    while (stop == 0){
        if (mot == (*casse).x){
            return casse;
        }
        else{
            casse = (*casse).next;
        }
    }
    return 0;
}

char* index_to_pattern(int index,int nombredelettre){  //ne sert plus
    long resultat = 0 ;
    long reste = index;
    long quotient;
    long puissance;

    //conversion base 3

    for(int i = nombredelettre-1;i>(-1);i--){
        puissance = (long) pow(3,i);
        if(puissance<=reste | reste==1){
            quotient = reste/puissance;
            resultat = resultat+quotient*pow(10,i);
            reste=reste-quotient*puissance;
        }
    }
    char result[nombredelettre+1];
    char res[nombredelettre+2];
    for(int i =0 ; i<nombredelettre;i++){
        result[i]='0';
    }
    result[nombredelettre]='\0';
    sprintf(res,"%ld\n",resultat);
    int n = strlen(res);
    for(int i=0;i<n-1;i++){
        result[nombredelettre-n+1+i]=res[i];
    }
    char* aenvoi = malloc(sizeof(char[nombredelettre+10]));
    strcpy(aenvoi,result);
    return aenvoi;
    
}
int pattern_to_index(char* mot){  // ne sert plus
    int n = strlen(mot);
    int s = 0;
    for(int i=0;i<n;i++){
        s = s + (mot[i]-48)*pow(3,n-1-i);
    }
    return s;
}

table_mot_hash* traitement(linked_list_str_t* dico, linked_list_str_t* mot_restants){
    simple_cell_string* curseur2 = dico->first; // mot du dico
    table_mot_hash* areturn = table_mot_hash_create(10);
    while(curseur2!=NULL){
        simple_cell_string* curseur1 = mot_restants->first;  //curseur1 = on parcourt les mots restants
        double* add = malloc(sizeof(double));
        linked_list_str_int* laadd = list_empl_create(); //liste qui contiendra pattern + nb mot associé
        
        while(curseur1 !=NULL){  
            char* pattern = find_pattern(curseur2->x,curseur1->x); // deux mots rend le pattern 
            if(list_empl_contains(laadd,pattern)){
                simple_cell_string_int* plus = list_empl_get_str(laadd,pattern);
                plus->emplacement = plus->emplacement+1;
                free(pattern);
            }
            else{
                list_empl_append(laadd,pattern,1);
            }
            curseur1 = curseur1->next;
        }
        add[0]=entropy(laadd,list_dico_length(mot_restants)); //on calcule entropie
        list_empl_destroy(laadd);
        table_mot_hash_add(areturn,curseur2->x,add); //on ajoute à table de hashage
        curseur2 = curseur2->next;
    }
    return areturn ;
}

char* find_pattern(char* motatest,char* motatrouve){
    int n = strlen(motatest);
    char* result=malloc(sizeof(char)*(n+1)); //renvoie pattern de la comparasion
    result[n]='\0';
    linked_list_str_int* latentative = list_empl_create(); 
    for(int i=0;i<n;i++){
        if(motatest[i]==motatrouve[i]){
            char* ajt = malloc(sizeof(char)*2);
            ajt[0] = motatest[i];
            ajt[1] = '\0';
            list_empl_append(latentative,ajt,2);
        }
        else{
            bool verif = true;
            for(int j=0;j<n;j++){
                if(motatrouve[j]==motatest[i]){
                    char* ajt2 = malloc(sizeof(char)*2);
                    ajt2[0] = motatest[i];
                    ajt2[1] = '\0';
                    list_empl_append(latentative,ajt2,1);
                    verif = false;
                }
            }
            if(verif){
                char* ajt3 = malloc(sizeof(char)*2);
                ajt3[0] = motatest[i];
                ajt3[1] = '\0';
                list_empl_append(latentative,ajt3,0);  //contient lettre + statut
            }
        }
    }
    linked_list_str_t* occurence = list_dico_create();
    linked_list_str_t* lettres = list_dico_create();
    for(int m=0;m<n;m++){
        simple_cell_string* curseur = lettres->first;
        bool verif = false;
       
        while(curseur !=NULL){   //on compte nbre occurence des lettres
            if(curseur == NULL){
            }

            if((curseur->x)[0] == motatrouve[m]){
                verif = true;
            }
            curseur = curseur->next;
        }
        if(verif == false){
            char* ajt3 = malloc(sizeof(char)*2);
            ajt3[0] = motatrouve[m];
            ajt3[1] = '\0';
            list_dico_append(lettres,ajt3);
            int compteur = 1;
            for(int j=m+1;j<n;j++){
                if(motatrouve[j]==motatrouve[m]){
                    compteur++;
                }
            }
            char* amettre = malloc(sizeof(char)*3);
            sprintf(amettre,"%d",compteur);
            list_dico_append(occurence,amettre);
        }
    }
    for(int k=0;k<n;k++){
        if(list_empl_get(latentative,k)->emplacement == 2){
            if(list_empl_get(latentative,k)==NULL){
            }
            int indicelettre = list_dico_index_of(lettres,list_empl_get(latentative,k)->lettre);
            int nombre = atoi(list_dico_get(occurence,indicelettre));
            nombre--;
            char* amet = malloc(sizeof(char)*3);
            sprintf(amet,"%d",nombre);
            free(list_dico_get(occurence,indicelettre));
            list_dico_insert(occurence,amet,indicelettre);

    }
    }
    for(int m=0;m<n;m++){
        if(list_empl_get(latentative,m)->emplacement == 1){
             int indicelettre2 = list_dico_index_of(lettres,list_empl_get(latentative,m)->lettre);
             if(atoi(list_dico_get(occurence,indicelettre2))<1){
                 list_empl_get(latentative,m)->emplacement = 0;
             }
             else {
                 int nombre2 = atoi(list_dico_get(occurence,indicelettre2));
                nombre2--;
                char* amet2 = malloc(sizeof(char)*3);
                sprintf(amet2,"%d",nombre2);
                free(list_dico_get(occurence,indicelettre2));
                list_dico_insert(occurence,amet2,indicelettre2);
             }
        }
    }
    for(int i=0;i<n;i++){
        char* aajout = malloc(sizeof(char)*3);
        sprintf(aajout,"%d",list_empl_get(latentative,i)->emplacement);
        result[i]=aajout[0];
        free(aajout);
    }
    list_empl_destroy(latentative);
    list_dico_destroy(occurence);
    list_dico_destroy(lettres);
    return result;

}

linked_list_str_t* actu(linked_list_str_t* mot_restants,char* proposition,char* reponse){
    simple_cell_string* curseur = mot_restants->first;
    linked_list_str_t* nouvelle = list_dico_create();
    while(curseur!=NULL){
        if(possibles(proposition,reponse,curseur->x) & (strcmp(proposition,curseur->x)!= 0)){
            char* add = malloc(sizeof(char)*30);
            strcpy(add,curseur->x);
            list_dico_append(nouvelle,add);
            curseur = curseur->next;
        }
        else{
            curseur = curseur->next;
        }
    }
    list_dico_destroy(mot_restants);
    return nouvelle;
}

char* namefile(char* nb){
    char* result = malloc(sizeof(char)*30);
    result[0]='.';
    result[1]='/';
    result[2]='s';
    result[3]='t';
    result[4]='a';
    result[5]='t';
    result[6]='i';
    result[7]='c';
    result[8]='/';
    result[9]='d';
    result[10]='i';
    result[11]='c';
    result[12]='o';
    result[13]='\0';
    strcat(result,nb);
    strcat(result,".txt");
    return result;
}

bool verif_reponse(char* reponse){ //interface
    bool resultat=true;
    int n = strlen(reponse);
    for(int i=0;i<n;i++){
        char lettre = reponse[i];
        if(lettre != '0' && lettre!='1' && lettre!='2'){
            resultat = false;
        }
    }
    return resultat;
}

bool possibles(char* mot, char* pattern, char* mot_test){
    int length = strlen(mot);
    int verif[length];
    for (int l=0;l<length;l++){
        verif[l]=0;
    }
    for (int i=0;i<length;i++){
        if (pattern[i]=='2' && mot[i]==mot_test[i])  {
            verif[i]=1;
        }
        else if (pattern[i]=='2' && mot[i]!=mot_test[i]){
            return false;
        }
    }
    for (int a=0;a<length;a++){ //on parcourt le mot

        if (pattern[a]=='1'){
            if (mot[a]==mot_test[a]){
                return false;
            }

            for (int b=0;b<length;b++){  //on parcourt le mot_test
                if (mot[a]==mot_test[b]){
                    if (verif[b]==0){
                        verif[b]=1;
    }
                        break;
                    }  
                if (b==length-1){
                    return false;
                }
            }
        }
    }
    
    for (int c=0;c<length;c++){
        if (pattern[c]=='0'){
            if (mot[c]==mot_test[c]){
                return false;
            }
                
            for (int d=0;d<length;d++){ //on parcourt le mot_test
                if (verif[d]==0 && mot[c]==mot_test[d]){
                    return false;
                }
            }
        }
    }return true;
}

