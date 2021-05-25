#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"


int main(void){

    PONT head;
    head = (PONT) malloc(sizeof(NOALUNO));
    strcpy(head->numMatricula, "201913425");
    strcpy(head->nome, "Regrano Guedes Maia");
    strcpy(head->email,"regguemai@uesc.br");
    head->prox = NULL;

    printf("%s, ", head->numMatricula);
	printf("%s, ", head->nome);
	printf("%s;\n", head->email);

    head->prox = (PONT) malloc(sizeof(NOALUNO));
    
    strcpy(head->prox->numMatricula, "201913245");
    strcpy(head->prox->nome, "Mengano Martins Pereira");
    strcpy(head->prox->email,"menmarper@uesc.br");
    head->prox->prox = NULL;

    printf("%s, ", head->prox->numMatricula);
	printf("%s, ", head->prox->nome);
	printf("%s;\n", head->prox->email);

    free(head->prox);
    free(head);

    return 0;
}