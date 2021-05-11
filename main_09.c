#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"

#define LSIZE 100


void  itoa ( unsigned int value, char * str);
void geraAlunos(tListAlunos* lista);

int main(void){
	double start, stop;
	tListAlunos lista;
	iniListAlunos(&lista, LSIZE);
	geraAlunos(&lista);
	//printLisAluno(lista.lista, lista.tam);

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

void geraAlunos(tListAlunos* lista){
	unsigned int matricula;
	tAluno aluno;
	while(lista->tam < lista->cap){
		matricula = (2017 + random()%5)*100000 + random()%100000;
		//printf("%d\n", matricula); 
		itoa(matricula, aluno.numMatricula);
		//strcpy(aluno.numMatricula, itoa(matricula, 10);
  	strcpy(aluno.nome, "Nome SobrenomeM SobrenomeP");
  	strcpy(aluno.email,"NSmSp@uesc.br");
		
		incNaoOrdenada(aluno, lista);
	}
}

void  itoa ( unsigned int value, char * str){
	char numArray[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (int i = 8; i >= 0; i--){
		str[i] = numArray[value % 10];
		value /=10; 
	}
	str[9] = '\0';
}