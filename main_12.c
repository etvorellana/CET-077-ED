#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#include "include/ferramentas.h"

#define LSIZE 10
//#define LSIZE 1000
//#define LSIZE 10000
//#define LSIZE 100000

/*
    Teste doa algoritmos de busca em listas simplesmente
    encadeadas
*/

int main(void){

    double start, stop; // variaveis para medir tempo
	/*
        Criamos uma lista Linear de Alocação sequencial para
        utilizar como referência e fonte de dados para testar
        as outras listas. Como esta lista vai ser utilizada 
        apenas como fonte de dados, os alunos vão ser 
        acessados diretamente no arrey pelo seu índice. 
        Podemos utilizar uma lista não ordenada
    */
    tListAlunos lista; // declarando a variável
	iniListAlunos(&lista, LSIZE); // inicializando a lista
    //Para gerar uma lista com tamanho igual a metade da capcidade
    lista.cap = LSIZE/2; //Alterar a capacidade para metade
	geraAlunos(&lista); // Prenche a lista ate a metade
    lista.cap = LSIZE; // Retornamos o valor real da capacidade
    if (lista.cap <= 10){
        printf("Lista de referencia inicial\n");
        printLisAluno(lista.lista, lista.tam);
    }
    

    //PONT conListSeq2ListEnc(tListAlunos* listaS)
    PONT listaEncNaoOrd;
    /* 
        Geramos uma Lista simplesmente encadeada utilizando
        os elementos da lista sequencial
    */
    listaEncNaoOrd = conListSeq2ListEnc(&lista);
    if (lista.cap <= 10){
        printf("Lista encadeada\n");
        printListaEncAluno(listaEncNaoOrd);
    }
    // preencher a lista sequencial até a capacidade real
    geraAlunos(&lista);
    if (lista.cap <= 10){
        printf("Lista de referencia cheia\n");
        printLisAluno(lista.lista, lista.tam);
    }

    printf("Testando busca de elementos - Algoritmo 1\n");
    /*
        1. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */
    unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed); // definindo a semente do sequencia rand
    int index;
	int qIn, qOut; // Variáveis para testar se a busca funcionou
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	PONT aluno;  //Ponteiro para elemento achado
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
		aluno = buscaListaEncNaoOrdAluno(listaEncNaoOrd, lista.lista[index].numMatricula);
		if(aluno->prox != NULL){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    //PONT busca_tListEncAlunos(tListEncAlunos lista, char chave[10])

    printf("Testando busca de elementos - Algoritmo 2\n");
    /*
        2. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */

    tListEncAlunos listaEncNaoOrd2;
    ini_tListEncAlunos(&listaEncNaoOrd2);
    listaEncNaoOrd2.head = listaEncNaoOrd;
    PONT tail = listaEncNaoOrd;
    while(tail->prox != NULL){
        tail = tail->prox;
    }
    tail->prox = listaEncNaoOrd2.tail;

	qIn = qOut = 0; // quantos elementos estão ou não na lista
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        aluno = busca_tListEncAlunos(listaEncNaoOrd2, lista.lista[index].numMatricula);
		if(aluno->prox != listaEncNaoOrd2.tail){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);
   
    return 0;
}