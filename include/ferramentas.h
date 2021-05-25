
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
	int ini; 	//fila vazia quando ini = fim
	int fim;  //fila cheia quando fim - ini = cap
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

void  itoa ( unsigned int value, char * str);
void geraAlunos(tListAlunos* lista);

void iniListAlunos(tListAlunos* list, int cap);

int buscaNaoOrdenada(tListAlunos* list, char chave[10]);
int incNaoOrdenada(tAluno aluno, tListAlunos* list);
int remNaoOrdenada(tAluno aluno, tListAlunos* list);

int buscaOrdenada(tListAlunos* list, char chave[10], int* achou);
int incOrdenada(tAluno aluno, tListAlunos* list);
int remOrdenada(tAluno aluno, tListAlunos* list);

struct noALuno{
	char numMatricula[10];  //chave com 9 caracteres
    char nome[100];         // nome com até 99 caracteres
    char email[100];        // eMail com até 99 caracteres
	struct noALuno *prox;
};

typedef struct noALuno NOALUNO;
typedef NOALUNO *PONT;

PONT iniListaEncAluno(void);
PONT conListSeq2ListEnc(tListAlunos* listaS);

void printListaEncAluno(PONT head);
PONT buscaListaEncNaoOrdAluno(PONT head, char chave[10]);

typedef struct{
	PONT head;
	PONT tail;
}tListEncAlunos;

void ini_tListEncAlunos(tListEncAlunos* lista);
void printListaEncAluno2(tListEncAlunos lista);
PONT busca_tListEncAlunos(tListEncAlunos lista, char chave[10]);

/*
PONT conListSeq2ListEnc_R(tListAlunos* listaS);

PONT buscaNaoOrdenada_(PONT head, char chave[10]);
int incNaoOrdenada_(tAluno aluno, PONT head);
int remNaoOrdenada_(tAluno aluno, PONT head);

PONT buscaOrdenada_(PONT head, char chave[10], int* achou);
int incOrdenada_(tAluno aluno, PONT head);
int remOrdenada_(tAluno aluno, PONT head);
*/

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

/*
typedef struct{
	int lsize;			// capacidade da lista (tamanho do array)
	int next; 			// tamanho da lista (índice do priemiro elemento disponível)
	int index;			// indice de trabalho
	int* l;					// Array para armazenamento dos valores
} tListSeqInt;
*/
