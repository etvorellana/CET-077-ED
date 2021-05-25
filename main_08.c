#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#include "include/ferramentas.h"

#define LSIZE 100000

/*
    Comparando uma Lista Linear de Alocação sequencial
    com uma lista linear simplesmente encadeada. 
*/

int main(void){
	double start, stop; // variaveis para medir tempo
	/*
        Criamos uma lista Linear de Alocação sequencial para
        utilizar como referência e fonte de dados para testar
        as outras listas. Como esta lista vai ser utilizada 
        apenas como fonte de dados, os alunos vão ser 
        acessados diretamente no arrey pelo seu ínioce. 
        Podemos utilizar uma lista não ordenada
    */
    tListAlunos lista; // declarando a variável
	iniListAlunos(&lista, LSIZE); // inicializando a lista
	geraAlunos(&lista); // Prenche a lista não ordenada


	/*
        Testando o desempenhyo de uma lista linear de alocação
        sequencial não ordenada
        1. Se cria uma lista de  tamanho LSIZE/2
    */
	tListAlunos listaNaoOrd;
	iniListAlunos(&listaNaoOrd, LSIZE/2);
	int index;
	printf(" Testando uma Lista Linear de Alocação\n");
    printf("Sequencial Não Ordenada.\n");
    printf("LSIZE = %d\n", LSIZE);

	printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta incluir um elemento que já esxiste na lista. 
        Para comparar esta etrutura definir uma semente que 
        garanta a mesma sequencia de números aleatórios em 
        todos os testes
    */
    unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    // equanto a lista não estiver cheia  
	while(listaNaoOrd.tam < listaNaoOrd.cap){ 
		// gera um índece aleatório nos limites da lista de referencia
        index = random()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido 
		incNaoOrdenada(lista.lista[index], &listaNaoOrd);
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (listaNaoOrd.cap <= 10)
        printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam); 

	printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */
	int qIn, qOut; // Variáveis para testar se a busca funcionou
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	int n;  //índice retornado pela busca
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
		n = buscaNaoOrdenada(&listaNaoOrd, lista.lista[index].numMatricula);
		if(n < listaNaoOrd.tam){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

	printf("Testando remoção de elementos\n");
    /*
        4. Esvaziar a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta escluit um elemento que não esxiste na lista. 
    */
	start = omp_get_wtime();// Iniciando o cronometro
    // equanto a lista não estiver vazia  
	while(listaNaoOrd.tam > 0){
        // gera um índece aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // removendo o elemento index, pode não estar na lista
		remNaoOrdenada(lista.lista[index], &listaNaoOrd);
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_rem = %f\n", stop - start);
	if (listaNaoOrd.cap <= 10)
        printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam); 

	/*
        Testando o desempenhyo de uma lista linear de alocação
        sequencial ordenada
        1. Se cria uma lista de  tamanho LSIZE/2
    */

	printf(" Testando uma Lista Linear de Alocação\n");
    printf("Sequencial Ordenada.\n");
    printf("LSIZE = %d\n", LSIZE);

	tListAlunos listaOrd;
	iniListAlunos(&listaOrd, LSIZE/2);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta incluir um elemento que já esxiste na lista. 
        Para comparar com a etrutura anterior redefinir a 
        semente
    */
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    // equanto a lista não estiver cheia  
	while(listaOrd.tam < listaOrd.cap){
        // gera um índece aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido 
		incOrdenada(lista.lista[index], &listaOrd);
	} 
	stop = omp_get_wtime();// Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (listaOrd.cap <= 10)
        printLisAluno(listaOrd.lista, listaOrd.tam);

    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */
	qIn = qOut = 0; // quantos elementos estão ou não na lista
    int achou; // flag para determinar se achou o elemento na lista bordenada
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
		n = buscaOrdenada(&listaOrd, lista.lista[index].numMatricula, &achou);
		if(achou){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime();// Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

	printf("Testando remoção de elementos\n");
    /*
        4. Esvaziar a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta escluit um elemento que não esxiste na lista. 
    */
	start = omp_get_wtime();// Iniciando o cronometro
    // equanto a lista não estiver vazia  
	while(listaOrd.tam > 0){
		 // gera um índece aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // removendo o elemento index, pode não estar na lista
		 remOrdenada(lista.lista[index], &listaOrd);
	}
	stop = omp_get_wtime();// Para o cronometro
	printf("t_rem = %f\n", stop - start);
	if (listaOrd.cap <= 10)
        printLisAluno(listaOrd.lista, listaOrd.tam); 

	return 0;
}