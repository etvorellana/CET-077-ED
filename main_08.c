#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"

#define LSIZE 100000


void  itoa ( unsigned int value, char * str);
void geraAlunos(tListAlunos* lista);

int main(void){
	double start, stop;
	tListAlunos lista;
	iniListAlunos(&lista, LSIZE);
	geraAlunos(&lista);
	//printLisAluno(lista.lista, lista.tam);

	tListAlunos listaNaoOrd;
	iniListAlunos(&listaNaoOrd, LSIZE/2);
	int index;

	// Testando inc em lista não ordenada
	start = omp_get_wtime();
	while(listaNaoOrd.tam < listaNaoOrd.cap){
		index = random()%LSIZE;
		incNaoOrdenada(lista.lista[index], &listaNaoOrd);
	}
	stop = omp_get_wtime();
	printf("t_inc = %f\n", stop - start);
	//printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam); 

	// Testando busca em lista não ordenada
	int qIn, qOut;
	qIn = qOut = 0;
	int achou, n;
	start = omp_get_wtime();
	for(index = 0; index<LSIZE; index++){
		n = buscaNaoOrdenada(&listaNaoOrd, lista.lista[index].numMatricula);
		if(n < listaNaoOrd.tam){
			qOut++;
		}else{
			qIn++;
		}
	}
	stop = omp_get_wtime();
	printf("t_bus = %f\n", stop - start);
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

	// Testando rem em lista não ordenada
	start = omp_get_wtime();
	while(listaNaoOrd.tam > 0){
		 index = random()%LSIZE;
		 remNaoOrdenada(lista.lista[index], &listaNaoOrd);
	}
	stop = omp_get_wtime();
	printf("t_rem = %f\n", stop - start);
	//printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam); 

	tListAlunos listaOrd;
	iniListAlunos(&listaOrd, LSIZE/2);

	// Testando inc em lista ordenada
	start = omp_get_wtime();
	while(listaOrd.tam < listaOrd.cap){
		 index = random()%LSIZE;
		 incOrdenada(lista.lista[index], &listaOrd);
	} 
	stop = omp_get_wtime();
	printf("t_inc = %f\n", stop - start);
	//printLisAluno(listaOrd.lista, listaOrd.tam); 

	// Testando busca em lista ordenada
	qIn = qOut = 0;
	start = omp_get_wtime();
	for(index = 0; index<LSIZE; index++){
		n = buscaOrdenada(&listaOrd, lista.lista[index].numMatricula, &achou);
		if(achou){
			qIn++;
		}else{
			qOut++;
		}
	}
	stop = omp_get_wtime();
	printf("t_bus = %f\n", stop - start);
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

	// Testando rem em lista ordenada
	start = omp_get_wtime();
	while(listaOrd.tam > 0){
		 index = random()%LSIZE;
		 remOrdenada(lista.lista[index], &listaOrd);
	}
	stop = omp_get_wtime();
	printf("t_rem = %f\n", stop - start);
	//printLisAluno(listaOrd.lista, listaOrd.tam); 

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