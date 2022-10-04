#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_solveur.h"
#include <string.h>
#include <unistd.h>
#include <time.h>


int main(void){
    FILE *f;
    linked_list_str_t* mot_a_trouve = list_dico_create();
    char str[50];
    f= fopen("wsolf.txt","r");
    if(f==NULL){
        printf("Erreur en lisant le fichier.\n");
        exit(1);
    }
    while(fgets(str,50,f) != NULL){
        str[strlen(str)]='\0';
        char* point = malloc(sizeof(char[50]));
        strcpy(point,str);
        list_dico_append(mot_a_trouve,point);
    }
    fclose(f);
    printf("------------------------------------\n           SOLVEUR WORDLE\n------------------------------------\n\nEquipe projet E4 :\n- Armand Bouveron\n- Thibaut Cagnon\n- Nicolas Garcia-Forest\n- Baptiste Gheysens\n\n");
    simple_cell_string* curseur = mot_a_trouve->first;
    clock_t start ,end ;
    double timediff;
    double sum = 0;
    while(curseur!=NULL ){
        start = clock();
        int n = atoi(curseur->x);
        //printf("Chargement dico\n");
        char nom[3] ;
        printf("Solveur pour les mots de %s lettres.\n",curseur->x);
        sprintf(nom,"%s",curseur->x);
        char * nomfile = namefile(nom);
        //printf("dico a charger : %s \n",nomfile);
        linked_list_str_t* dico = list_dico_load(nomfile);
        int nblettres = strlen(dico->first->x);
        linked_list_str_t* mots_restants = list_dico_load(nomfile);
        free(nomfile);
        //printf("Dico chargé\n");

        //printf("Début de partie\n");
        int stop = 0;
        char réponse[30];
        int nbessai = 1;
        end = clock();
        timediff = (double)(end - start)/CLOCKS_PER_SEC;
        sum = sum + timediff;
        //printf("chrono chargement wordle : %f\n",timediff);
        while(stop == 0){
            //printf("traitement...\n");
            start = clock();
            printf("\nChoix de la proposition en cours...\n");
            char* proposition;
            if(nbessai ==1){
                proposition = dico->first->x;
            }
            else if(list_dico_length(mots_restants)==2){
                proposition = mots_restants->first->x;
            }
            else{
                if(nblettres<9){
                    table_mot_hash* analyse = traitement(dico,mots_restants);
            if(list_dico_length(mots_restants)==1){
                proposition = mots_restants->first->x;
            }
            else{
                proposition = best_mot(dico,analyse);
            } 
            table_mot_hash_destroy(analyse);
                }
                else{
                    table_mot_hash* analyse = traitement(mots_restants,mots_restants);
            if(list_dico_length(mots_restants)==1){
                proposition = mots_restants->first->x;
            }
            else{
                proposition = best_mot(mots_restants,analyse);
            } 
            table_mot_hash_destroy(analyse);
                }
               
            }
            end = clock();
            timediff = (double)(end - start)/CLOCKS_PER_SEC;
            sum = sum + timediff;
            //printf("Temps traitement :%f\n",timediff);
            printf("Le solveur propose au WORDLE le mot suivant : %s.\n\nVeuillez indiquer en réponse :\n    - -1 si vous souhaitez arrêter le jeu,\n    - sinon le résultat de la proposition sous forme d'une séquence de 0, 1, et 2.\n\n", proposition);

            //printf("La proposition du solveur est : %s\n",proposition);
            //printf("Rentrez la réponse du wordle : \n");
            
            scanf("%s",réponse);
            int stoppage = 0;
                while(stoppage==0){
                    if((strlen(réponse)==(unsigned long)n && verif_reponse(réponse))| (strcmp(réponse,"-1")==0) ){
                        stoppage=1;
                    }
                    
                    else{
                        printf("\nVeuillez soumettre un pattern de taille adéquate : \n\n");
                        scanf("%s",réponse);
                    }
                }
            if(strcmp(réponse,"-1")==0){
                stop = 1;
                curseur = NULL;
                printf("\nMerci d'avoir utilisé le solveur WORDLE de l'équipe projet E4 !\n");
            }
            else{
                
              if(pattern_to_index(réponse)==pow(3,n)-1){
                printf("\nMot trouvé par le solveur : %s.\n\nDémarrage de la partie suivante dans 5 secondes.\n\n", proposition);
                sleep(5);
                stop = 1;
              }  
              else{
                  start= clock();
                  mots_restants = actu(mots_restants,proposition,réponse);
                  //printf("nombre de mots possibles restants :%d\n",list_dico_length(mots_restants));
                  //list_dico_print(mots_restants);
                  end = clock();
                  timediff = (double)(end - start)/CLOCKS_PER_SEC;
                  sum = sum + timediff;
                  //printf("actualisation %f\n",timediff);
              }
            
        }  
        if(list_dico_is_empty(mots_restants)){
            stop = 1 ;
            printf("\nUne erreur sur les patterns en entrée a été réalisée.\n\nRedémarrage de la partie dans 5 secondes.\n\n");
            sleep(5);
        }
        nbessai++;
        //printf("temp total : %f\n",sum);

    }
    list_dico_destroy(dico);
    list_dico_destroy(mots_restants);
            
}
    list_dico_destroy(mot_a_trouve);
    printf("Arrêt du solveur.\n\n");
    
    

}

