#include <stdio.h>
#include "../../src/gestionMemoire.h"

int main(){
    int *tab = my_malloc(sizeof(int)*10);
    int i = 0;
    for(i=0; i<10; i++){
	tab[i] = i;
    }
    for(i=0; i<10; i++){
	printf("tab[%d] : %d\n", i, tab[i]);
    }
   
    return 0;
}
