
#include <string.h>
#define TRUE 1;
#define FALSE 0;

typedef struct{
    char numMatricula[10];  //chave com 9 caracteres
    char nome[100];         // nome com até 99 caracteres
    char email[100];        // eMail com até 99 caracteres
} tAluno;

typedef struct{
	tAluno* lista;
	int cap;
	int tam;
} tListAlunos;


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

