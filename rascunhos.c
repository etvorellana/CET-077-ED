#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

int main(void)
{
  
	tAluno lista_stc[101];
	tAluno* lista_din;
	lista_din = (tAluno*) malloc(101*sizeof(tAluno));
	
  int index;
  int nLis =  0;
  printf("Testando Listas Lineares Sequenciais\n");
    
  // Colocar aqui a leitura de um arquivo
	// Testando Listas ordenadas
	nLis = 0;
  strcpy(aluno.numMatricula, "201913425");
  strcpy(aluno.nome, "Regrano Guedes Maia");
  strcpy(aluno.email,"regguemai@uesc.br");
	incLisAlunoOrd(aluno, lista_din, nLis);
  nLis++;
	strcpy(aluno.numMatricula, "201912345");
  strcpy(aluno.nome, "Fulano Silva Oliveira");
  strcpy(aluno.email,"fulsiloli@uesc.br");
	incLisAlunoOrd(aluno, lista_din, nLis);
  nLis++;
	strcpy(aluno.numMatricula, "201913245");
  strcpy(aluno.nome, "Mengano Martins Pereira");
  strcpy(aluno.email,"menmarper@uesc.br");
	incLisAlunoOrd(aluno, lista_din, nLis);
  nLis++;

	printLisAluno(lista_din, nLis);

	

	

	free(lista_din);
}
#include <stdio.h>
#include <stdlib.h>

/* Tipo para representar uma lista sequencial de
	número inteiros.
*/

#define LSIZE 100;  //Capacidade da Lista
#define TRUE 1;
#define FALSE 0;

typedef struct{
	int lsize;			// capacidade da lista (tamanho do array)
	int next; 			// tamanho da lista (índice do priemiro elemento disponível)
	int index;			// indice de trabalho
	int* l;					// Array para armazenamento dos valores
} tListSeqInt;

/* Funcção que retorna se a lista está vazia
	Entrada: Uma lista de tipo tListSeqInt
	Saída: TRUE se a lsita estiver vazia 				*/
int listaVazia(tListSeqInt list);

/* Funcção que retorna se a lista está cheia
	Entrada: Uma lista de tipo tListSeqInt
	Saída: TRUE se a lsita estiver cheia 				*/
int listaCheia(tListSeqInt list);

void inicializaLista(tListSeqInt* list, int lsize);

void descartaLista(tListSeqInt* list);

/* Funcção que mostra a lista na saída padrão
	Entrada: Uma lista de tipo tListSeqInt
	Saída: void													 				*/
void mostraLista(tListSeqInt list);

/* Funcção que mostra a lista, como uma 
	estrutura recursiva, na saída padrão 
	Entrada: Uma lista de tipo tListSeqInt
	Saída: void													 				*/
void mostraLista_r(tListSeqInt* list);

int adicionaALista(tListSeqInt* list, int valor);


int main(void)
{
	tListSeqInt list;

	int* arrayInt;
	double* arrayDouble; 

	arrayInt = (int*) malloc(100*sizeof(int));
	arrayDouble = (double*)malloc(100*sizeof(double));

	arrayInt[0] = 0;
	arrayDouble[0]= 1.0;

	free(arrayInt);
	free(arrayDouble);

	// Criando uma lista para armazenar até 100 int
	inicializaLista(&list, 100);

	if(listaVazia(list)){
		printf("A lista está vazia\n");
		mostraLista(list);
		mostraLista_r(&list);
	}

	for(int i = 0; i < 10; i++){
		if (!listaCheia(list)){
			//int valor = rand();
			//adicionaALista(&list, valor);
			adicionaALista(&list, i+1);
		}
	}
	mostraLista(list);
	mostraLista_r(&list);
	descartaLista(&list);
	return 0;
}

//Rev: Ok
int listaVazia(tListSeqInt list){
	if (list.next == list.index){
		return TRUE;
	}else{
		return FALSE;
	} 
}

//Rev: Ok
int listaCheia(tListSeqInt list){
	return list.next == list.lsize;
}

//Rev: Ok
void inicializaLista(tListSeqInt* list, int lsize)
{
	list->lsize = lsize;
	list->next = 0;
	list->index = 0;
	list->l = (int*) malloc(lsize*sizeof(int));
}

//Rev: Ok
void descartaLista(tListSeqInt* list)
{
	list->lsize = 0;
	list->next = 0;
	list->index = 0;
	free(list->l);
}

//Rev: ...
void mostraLista(tListSeqInt list){
	printf("[ ");
	for(int i = 0; i < list.next; i++){
		printf("%d", list.l[i]);
		if(i < list.next-1)
			printf(", ");
	}
	printf(" ]\n");		
}

//Rev: ... 
void mostraLista_r(tListSeqInt* list){
	printf("[ ");
	if(!listaVazia(*list)){
		printf("%d, ", list->l[list->index++]);
		mostraLista_r(list);
		list->index--;
	}
	printf(" ]");
	if(list->index == 0){
		printf("\n");
	}
	
}

//Rev: ...
int adicionaALista(tListSeqInt* list, int valor)
{	
	if(list->next < list->lsize){
		list->l[list->next] = valor;
		list->next++;
		return 0;
	}else{
		return 1;
	}
}

