#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

int main(void)
{
	tAluno aluno;
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
	//Procurando um elemento que está na lista
	printf("Testando o método de busca 4 Recursivo de um\n"); 
	printf(" elemento que esta na lista: 201913425\n");
	int achou = FALSE;
	index = buscaLisAlunoBinRec(lista_din, nLis, "201913425", &achou);
	if(achou){
    printf("Elemanto achado com índice %d\n", index);
		printItemLisAluno(lista_din, index);
  }else{
    printf("Elemento não se encontra na lista!!\n");
	}
	
	//Procurando um elemento que não está na lista
	printf("Testando o método de busca 4 Recursivo de um\n"); 
	printf(" elemento que não esta na lista: 201900000\n");
	index = buscaLisAlunoBinRec(lista_din, nLis, "201900000", &achou);
	if(achou){
    printf("Elemanto achado com índice %d\n", index);
		printItemLisAluno(lista_din, index);
  }else{
    printf("Elemento não se encontra na lista!!\n");
	}

	free(lista_din);

	return 0;
}
