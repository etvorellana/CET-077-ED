#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"

#define LSIZE 10

int main(void){
    tListAlunos listaS;
	iniListAlunos(&listaS, LSIZE);
	//geraAlunos(&listaS);
	printLisAluno(listaS.lista, listaS.tam);

    PONT listaE;
    listaE = conListSeq2ListEnc(&listaS);
    printLisAluno(listaS.lista, listaS.tam);
    PONT tem = listaE->prox;
    printf("[ ...\n");
    while(tem != NULL){
        printf("numMatricula: %s, ", tem->numMatricula);
        printf("nome: %s, ", tem->nome);
        printf("email: %s; \n ", tem->email);
        tem = tem->prox;
    }
    printf("...]\n");

    return 0;
}