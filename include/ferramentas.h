
#include <string.h>
#define TRUE 1;
#define FALSE 0;

typedef struct{
    char numMatricula[10];  //chave com 9 caracteres
    char nome[100];         // nome com até 99 caracteres
    char email[100];        // eMail com até 99 caracteres
} tAluno;

typedef struct{
	tAluno* pilha;
	int cap;  //pilha vazia quando topo = 0
	int topo; //pilha cheia quando topo = cap
}tPilhaAlunos; //last in first out - lifo
// topo = 0
int iniPilhaAlunos(tPilhaAlunos* pilha, int cap); 
int incPilhaAlunos(tAluno aluno, tPilhaAlunos* pilha);
int remPilhaAlunos(tAluno* aluno, tPilhaAlunos* pilha);

typedef struct{
	tAluno* fila;
	int cap;
	int ini; 	//fila vazia quando ?
	int fim;  //fila cheia quando ?
}tFilaAlunos; //first in first out - fifo
// ini = -1   fim = 0
int iniFilaAlunos(tFilaAlunos* fila, int cap);
int incFilaAlunos(tAluno aluno, tFilaAlunos* fila);
int remFilaAlunos(tAluno* aluno, tFilaAlunos* fila);

typedef struct{
	tAluno* lista;
	int cap;
	int tam;
} tListAlunos;

void iniListAlunos(tListAlunos* list, int cap);
int buscaNaoOrdenada(tListAlunos* list, char chave[10]);
int incNaoOrdenada(tAluno aluno, tListAlunos* list);
int remNaoOrdenada(tAluno aluno, tListAlunos* list);
int buscaOrdenada(tListAlunos* list, char chave[10], int* achou);
int incOrdenada(tAluno aluno, tListAlunos* list);
int remOrdenada(tAluno aluno, tListAlunos* list);

int buscaLisAluno(tAluno lista[], int n, char chave[]);
int buscaLisAluno2(tAluno lista[], int n, char chave[]);
int buscaLisAlunoRec(tAluno lista[], int n, char chave[]);
int buscaLisAlunoRec2(tAluno lista[], int n, char chave[]);
void incLisAluno(tAluno aluno, tAluno lista[], int n);
int buscaLisAlunoOrd(tAluno lista[], int n, char chave[], int* achou);
int buscaLisAlunoOrdRec(tAluno lista[], int n, char chave[], int* achou);
int buscaLisAlunoBin(tAluno lista[], int n, char chave[], int* achou);
int buscaLisAlunoBinRec(tAluno lista[], int n, char chave[], int* achou);
int incLisAlunoOrd(tAluno aluno, tAluno lista[], int n);

void printLisAluno(tAluno lista[], int n);
void printItemLisAluno(tAluno lista[], int n);



typedef struct{
	int lsize;			// capacidade da lista (tamanho do array)
	int next; 			// tamanho da lista (índice do priemiro elemento disponível)
	int index;			// indice de trabalho
	int* l;					// Array para armazenamento dos valores
} tListSeqInt;

