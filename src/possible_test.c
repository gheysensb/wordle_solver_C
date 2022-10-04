#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fonctions_solveur.h"

int test_main(void) {
    if(possibles("capturerons","01011110110","ondulatoire")){    
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    return EXIT_SUCCESS;
}
