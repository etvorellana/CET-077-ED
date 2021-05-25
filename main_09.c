#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"

#define LSIZE 100

int main(void){
	double start, stop;
	tListAlunos lista;
	iniListAlunos(&lista, LSIZE);
	geraAlunos(&lista);
	
	tPilhaAlunos pilha;
    iniPilhaAlunos(&pilha, LSIZE/4);
	int index;
    int inOrOut;
    tAluno aluno;

	// Testando a pilha
	start = omp_get_wtime();
    for(index = 0; index<LSIZE; index++){
        inOrOut = random()%5;
        if(inOrOut){
            if(incPilhaAlunos(lista.lista[index], &pilha)){
                printf("In - Ok\n");
            }else{
                printf("In - Lista Cheia\n");
            }
        }else{
            if(remPilhaAlunos(&aluno, &pilha)){
                printf("Out - Ok\n");
            }else{
                printf("Out - Lista Vazia\n");
            }
        }
	}
	stop = omp_get_wtime();
	printf("t_pilha = %f\n", stop - start);
	
    tFilaAlunos fila;
    iniFilaAlunos(&fila, LSIZE/4);

    // Testando a fila
	start = omp_get_wtime();
    for(index = 0; index<LSIZE; index++){
        inOrOut = random()%5;
        if(inOrOut){
            if(incFilaAlunos(lista.lista[index], &fila)){
                printf("In - Ok\n");
            }else{
                printf("In - Lista Cheia\n");
            }
        }else{
            if(remFilaAlunos(&aluno, &fila)){
                printf("Out - Ok\n");
            }else{
                printf("Out - Lista Vazia\n");
            }
        }
	}
	stop = omp_get_wtime();
	printf("t_pilha = %f\n", stop - start);

	return 0;
}