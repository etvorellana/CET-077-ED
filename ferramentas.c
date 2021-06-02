
#include <stdio.h>
#include <stdlib.h>
#include "include/ferramentas.h"

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna n;
*/
int buscaLisAluno(tAluno lista[], int n, char chave[10])
{
	int i = 0;
	while (i < n)
	{
		if (strcmp(lista[i].numMatricula, chave) == 0)
			return i;
		i++;
	}
	return n; //não achou, retorna n
}

/* 
Implementação ecursiva da função:

int buscaLisAluno(tAluno lista[], int n, char chave[10])
*/
int buscaLisAlunoRec(tAluno lista[], int n, char chave[])
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		if (!strcmp(lista[0].numMatricula, chave))
		{
			return 0;
		}
		else
		{
			return 1 + buscaLisAlunoRec(&lista[1], n - 1, chave);
		}
	}
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1. Para melhorar o algoritmo se adiciona a 
	chave procurada ao elemento da posição n, que não pertence
	à lista. Se pressupõe que a lista tem capacidade para
	armazenar informação na posição de índice n;
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna n;
*/
int buscaLisAluno2(tAluno lista[], int n, char chave[])
{
	int i = 0;
	strcpy(lista[n].numMatricula, chave); // adicionando cave no final
	while (strcmp(lista[i].numMatricula, chave) != 0)
	{
		i++;
	}
	return i;
} //O(n)

/* 
Implementação ecursiva da função:

int buscaLisAluno2(tAluno lista[], int n, char chave[10])
Para o funcionamento correto desta implementação, a inserção
da chave procurada na posição de índice n deve ser feita
antes da chamada à função;
*/
int buscaLisAlunoRec2(tAluno lista[], int n, char chave[])
{
	if (!strcmp(lista[0].numMatricula, chave))
	{
		return 0;
	}
	else
	{
		return 1 + buscaLisAlunoRec(&lista[1], n - 1, chave);
	}
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática, na qual elementos
foram inseridos de forma ordenada, em ordem crescente, de 
acordo com o campo chave numMatricula). 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1. Para melhorar o algoritmo se adiciona a 
	chave procurada ao elemento da posição n, que não pertence
	à lista. Se pressupõe que a lista tem capacidade para
	armazenar informação na posição de índice n; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
- achou: Referência para retornar um boolean que relata o 
	sucesso da busca;
saída:
- A função retorna um índice da lista e um resultado boolean
	que significa:
	* se achou for TRUE o índice retornado indica o posição da 
	lista onde se encontra o elemento que possui a chave procurada.
	* se achou for FALSE o índice retornado indica o posição da 
	lista onde um elemento com essa chave deveria ser inserido na
	lista, de acordo com a ordem crescente estabelecida;
*/
int buscaLisAlunoOrd(tAluno lista[], int n, char chave[], int *achou)
{
	int i = 0;
	*achou = FALSE;
	strcpy(lista[n].numMatricula, chave); // adicionando cave no final
	while (strcmp(lista[i].numMatricula, chave) < 0)
	{
		i++;
	}
	if ((strcmp(lista[i].numMatricula, chave) == 0) && (i < n))
		*achou = TRUE;
	return i;
} // O(n)

/* 
Implementação ecursiva da função:

int buscaLisAlunoOrd(tAluno lista[], int n, char chave[], int* achou)
Para o funcionamento correto desta implementação, a inserção
da chave procurada na posição de índice n deve ser feita
antes da chamada à função e a varável referenciada por achou deve 
ser inicializada com valor FALSE;
*/
int buscaLisAlunoOrdRec(tAluno lista[], int n, char chave[], int *achou)
{
	if ((!strcmp(lista[0].numMatricula, chave)) && (n > 0))
		*achou = TRUE;
	if (strcmp(lista[0].numMatricula, chave) < 0)
	{
		return 1 + buscaLisAlunoOrdRec(&lista[1], n - 1, chave, achou);
	}
	else
		return 0;
}

/*
Implementa a busca binaria numa lista linear de alocação
sequencial do tipo tAluno. Nesta função se trabalha com uma 
lista definida como um array de forma estática, na qual elementos
foram inseridos de forma ordenada, em ordem crescente, de 
acordo com o campo chave numMatricula). 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1.
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
- achou: Referência para retornar um boolean que relata o 
	sucesso da busca;
saída:
- A função retorna um índice da lista e um resultado boolean
	que significa:
	* se achou for TRUE o índice retornado indica o posição da 
	lista onde se encontra o elemento que possui a chave procurada.
	* se achou for FALSE o índice retornado indica o posição da 
	lista onde um elemento com essa chave deveria ser inserido na
	lista, de acordo com a ordem crescente estabelecida;
*/
int buscaLisAlunoBin(tAluno lista[], int n, char chave[], int *achou)
{
	int min = 0;
	int max = n;
	int i;
	*achou = FALSE;
	while (min != max)
	{
		i = (max + min) / 2;
		int com = strcmp(lista[i].numMatricula, chave);
		if (com < 0)
		{
			min = ++i;
		}
		else
		{
			if (com > 0)
			{
				max = i;
			}
			else
			{
				if (i < n)
					*achou = TRUE;
				return i;
			}
		}
	}
	return i;
} //O(log_2(n))

/* 
Implementação ecursiva da função:

int buscaLisAlunoBin(tAluno lista[], int n, char chave[], int* achou)
*/
int buscaLisAlunoBinRec(tAluno lista[], int n, char chave[], int *achou)
{
	if (n == 0)
	{
		*achou = FALSE;
		return 0;
	}
	else
	{
		int i = n / 2;
		int com = strcmp(lista[i].numMatricula, chave);
		if (com < 0)
		{
			return i + buscaLisAlunoBinRec(&lista[i], n - (n / 2), chave, achou);
		}
		else
		{
			if (com > 0)
			{
				return buscaLisAlunoBinRec(lista, n / 2, chave, achou);
			}
			else
			{
				*achou = TRUE;
				return i;
			}
		}
	}
}

void incLisAluno(tAluno aluno, tAluno lista[], int n)
{
	if (buscaLisAluno2(lista, n, aluno.numMatricula) == n)
	{
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email, aluno.email);
	}
}

int incLisAlunoOrd(tAluno aluno, tAluno lista[], int n)
{
	int achou;
	//int i = buscaLisAlunoOrd(lista, n, aluno.numMatricula, &achou);
	//achou = FALSE;
	//strcpy(lista[n].numMatricula, aluno.numMatricula);
	//int i = buscaLisAlunoOrdRec(lista, n, aluno.numMatricula, &achou);
	int i = buscaLisAlunoBin(lista, n, aluno.numMatricula, &achou);
	if (i == n)
	{
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email, aluno.email);
		return 0;
	}
	else if (!achou)
	{
		tAluno troca;
		for (int j = i; j < n; j++)
		{
			strcpy(troca.numMatricula, lista[j].numMatricula);
			strcpy(troca.nome, lista[j].nome);
			strcpy(troca.email, lista[j].email);

			strcpy(lista[j].numMatricula, aluno.numMatricula);
			strcpy(lista[j].nome, aluno.nome);
			strcpy(lista[j].email, aluno.email);

			strcpy(aluno.numMatricula, troca.numMatricula);
			strcpy(aluno.nome, troca.nome);
			strcpy(aluno.email, troca.email);
		}
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email, aluno.email);
		return 0;
	}
	return 1; // Já tem um elemento com essa chave na lista;
}

void printLisAluno(tAluno lista[], int n)
{
	printf("[ \n ");
	for (int i = 0; i < n; i++)
	{
		printf("%s, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}

void printItemLisAluno(tAluno lista[], int n)
{
	printf("[ \n");
	printf("%s, ", lista[n].numMatricula);
	printf("%s, ", lista[n].nome);
	printf("%s;\n ", lista[n].email);
	printf(" ]\n");
}

void iniListAlunos(tListAlunos *list, int cap)
{
	list->cap = cap;
	list->tam = 0;
	list->lista = (tAluno *)malloc((cap + 1) * sizeof(tAluno));
}

//retorna o indice onde achou
int buscaNaoOrdenada(tListAlunos *list, char chave[10])
{
	int i = 0;
	int n = list->tam;
	strcpy(list->lista[n].numMatricula, chave); // adicionando chave no final
	while (strcmp(list->lista[i].numMatricula, chave) != 0)
	{
		i++;
	}
	return i;
}

// Retorna TRUE ou FALSE
// FALSE: Se o aluno já estiver na lista ou se a
// lista já estiver cheia
int incNaoOrdenada(tAluno aluno, tListAlunos *list)
{
	int n = list->tam; // n é o tamanho da lista
	if (n < list->cap)
	{ // se a lista não estiver cheia
		if (buscaNaoOrdenada(list, aluno.numMatricula) == n)
		{															 // se não achei na lista
			strcpy(list->lista[n].numMatricula, aluno.numMatricula); // incluo na posição n
			strcpy(list->lista[n].nome, aluno.nome);
			strcpy(list->lista[n].email, aluno.email);
			list->tam++; // e incremento o tamanho
			return TRUE; // consegui incluir
		}
		else
			return FALSE; // não inclui pq já esta
	}
	else
		return FALSE; // não inclui pq esta cheia
}

// Retorna TRUE ou FALSE
// FALSE: Se o aluno não estiver na lista ou se a
// lista já estiver vazia
int remNaoOrdenada(tAluno aluno, tListAlunos *list)
{
	int n = list->tam; // n é o tamanho da lista
	if (n > 0)
	{														// se a lista não estiver vazia
		int i = buscaNaoOrdenada(list, aluno.numMatricula); // procuro na lista
		if (i < n)
		{ // se achei na lista
			for (int j = i; j < n; j++)
			{ // removo o elemento de i
				strcpy(list->lista[j].numMatricula, list->lista[j + 1].numMatricula);
				strcpy(list->lista[j].nome, list->lista[j + 1].nome);
				strcpy(list->lista[j].email, list->lista[j + 1].email);
			}
			list->tam--; // e decrementa o tamanho
			return TRUE; // consegui remover
		}
		else
			return FALSE; // não cosnegui pq não achei
	}
	else
		return FALSE; // não consegui pq esta vazia
}

//retorna o indice onde achou
int buscaOrdenada(tListAlunos *list, char chave[], int *achou)
{
	int min = 0;
	int max = list->tam;
	int i;
	*achou = FALSE;
	while (min != max)
	{
		i = (max + min) / 2;
		int com = strcmp(list->lista[i].numMatricula, chave);
		if (com < 0)
		{
			min = ++i;
		}
		else
		{
			if (com > 0)
			{
				max = i;
			}
			else
			{
				*achou = TRUE;
				return i;
			}
		}
	}
	return i;
}

// Retorna TRUE ou FALSE
// FALSE: Se o aluno já estiver na lista ou se a
// lista já estiver cheia
int incOrdenada(tAluno aluno, tListAlunos *list)
{
	int achou;
	int n = list->tam; // n é o tamanho da lista
	if (n < list->cap)
	{															 // se a lista não estiver cheia
		int i = buscaOrdenada(list, aluno.numMatricula, &achou); // procuro na lista
		if (!achou)
		{				  // se não achei na lista
			tAluno troca; // variavel de troca
			for (int j = i; j < n; j++)
			{															 // incerir aluno em j
				strcpy(troca.numMatricula, list->lista[j].numMatricula); // copiar j para troca
				strcpy(troca.nome, list->lista[j].nome);
				strcpy(troca.email, list->lista[j].email);

				strcpy(list->lista[j].numMatricula, aluno.numMatricula); // copiar aluno para j
				strcpy(list->lista[j].nome, aluno.nome);
				strcpy(list->lista[j].email, aluno.email);

				strcpy(aluno.numMatricula, troca.numMatricula); // copiar troca para aluno
				strcpy(aluno.nome, troca.nome);
				strcpy(aluno.email, troca.email);
			}
			strcpy(list->lista[n].numMatricula, aluno.numMatricula); // copiar troca para n
			strcpy(list->lista[n].nome, aluno.nome);
			strcpy(list->lista[n].email, aluno.email);
			list->tam++; // e incremento o tamanho
			return TRUE; // consegui incluir
		}
		else
			return FALSE; // não inclui pq já esta
	}
	else
		return FALSE; // não inclui pq esta cheia
}

// Retorna TRUE ou FALSE
// FALSE: Se o aluno não estiver na lista ou se a
// lista já estiver vazia
int remOrdenada(tAluno aluno, tListAlunos *list)
{
	int achou;
	int n = list->tam; // n é o tamanho da lista
	if (n > 0)
	{															 // se a lista não estiver vazia
		int i = buscaOrdenada(list, aluno.numMatricula, &achou); // procuro na lista
		if (achou)
		{ // se achei na lista
			for (int j = i; j < n; j++)
			{ // removo o elemento de i
				strcpy(list->lista[j].numMatricula, list->lista[j + 1].numMatricula);
				strcpy(list->lista[j].nome, list->lista[j + 1].nome);
				strcpy(list->lista[j].email, list->lista[j + 1].email);
			}
			list->tam--; // e decrementa o tamanho
			return TRUE; // consegui remover
		}
		else
			return FALSE; // não cosnegui pq não achei
	}
	else
		return FALSE; // não consegui pq esta vazia
}

int iniPilhaAlunos(tPilhaAlunos* pilha, int cap){
	pilha->cap = cap;
	pilha->topo = 0;
	pilha->pilha = (tAluno*) malloc(sizeof(tAluno)*cap);
	return 0;
}
int incPilhaAlunos(tAluno aluno, tPilhaAlunos* pilha){
	if(pilha->topo < pilha->cap)
	{
		strcpy(pilha->pilha[pilha->topo].numMatricula, aluno.numMatricula);
		strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
		strcpy(pilha->pilha[pilha->topo].email, aluno.email);
		pilha->topo++;
		return 1;
	}else{
		return 0;
	}
}
int remPilhaAlunos(tAluno* aluno, tPilhaAlunos* pilha){
	if(pilha->topo > 0)
	{
		pilha->topo--;
		strcpy(aluno->numMatricula, pilha->pilha[pilha->topo].numMatricula);
		strcpy(aluno->nome, pilha->pilha[pilha->topo].nome);
		strcpy(aluno->email, pilha->pilha[pilha->topo].email);
		return 1;
	}else{
		return 0;
	}
}

int iniFilaAlunos(tFilaAlunos* fila, int cap){
	fila->cap = cap;
	fila->ini = 0;
	fila->fim = 0;
	fila->fila = (tAluno*) malloc(sizeof(tAluno)*cap);
	return 0;
}
int incFilaAlunos(tAluno aluno, tFilaAlunos* fila){
	if((fila->fim - fila->ini) < fila->cap)
	{	int pos = fila->fim % fila->cap;
		strcpy(fila->fila[pos].numMatricula, aluno.numMatricula);
		strcpy(fila->fila[pos].nome, aluno.nome);
		strcpy(fila->fila[pos].email, aluno.email);
		fila->fim++;
		return 1;
	}else{
		return 0;
	}
}
int remFilaAlunos(tAluno* aluno, tFilaAlunos* fila){
	if(fila->ini < fila->fim)
	{
		int pos = fila->ini%fila->cap;
		strcpy(aluno->numMatricula, fila->fila[pos].numMatricula);
		strcpy(aluno->nome, fila->fila[pos].nome);
		strcpy(aluno->email, fila->fila[pos].email);
		fila->ini++;
		return 1;
	}else{
		return 0;
	}
}

void geraAlunos(tListAlunos* lista){
	unsigned int matricula;
	tAluno aluno;
	while(lista->tam < lista->cap){
		matricula = (2017 + random()%5)*100000 + random()%100000; 
		itoa(matricula, aluno.numMatricula);
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

// Cria umk pontero para o head de uma lista simplesmente encadeada
PONT iniListaEncAluno(void){
	PONT head;  //head tail
    head = (PONT) malloc(sizeof(NOALUNO)); // Neste nó não guardamos informação
	head->prox = NULL; // A lista esta vazia
	return head;
}

// Criando uma lista simplesmente encadeada com base numa lista sequencial
PONT conListSeq2ListEnc(tListAlunos* listaS){
	PONT head, tail; 
	head = iniListaEncAluno(); //Criamos uma lsita encadeada vazia
	if (listaS->tam > 0){ // Se a lista seq não estiver vazia 
		tail = head;
		for(int i = 0; i < listaS->tam; i++){ // preenchemos com os elementos
			tail->prox = (PONT)malloc(sizeof(NOALUNO));
			tail = tail->prox;
			strcpy(tail->numMatricula, listaS->lista[i].numMatricula);
    		strcpy(tail->nome, listaS->lista[i].nome);
    		strcpy(tail->email,listaS->lista[i].email);
		}
		tail->prox = NULL;
	}
	return head;	
}

void printListaEncAluno(PONT head){
	PONT tail = head;
	printf("[\n");
	while(tail->prox != NULL){
		tail = tail->prox;
		printf("%s, ", tail->numMatricula);
		printf("%s, ", tail->nome);
		printf("%s\n", tail->email);
	}
	printf(" ]\n");
}

void printListaEncAluno2(tListEncAlunos lista){
	PONT tail = lista.head;
	printf("[\n");
	while(tail->prox != lista.tail){
		tail = tail->prox;
		printf("%s, ", tail->numMatricula);
		printf("%s, ", tail->nome);
		printf("%s\n", tail->email);
	}
	printf(" ]\n");
}

PONT buscaListaEncNaoOrdAluno(PONT head, char chave[10]){
	PONT tail = head;
	while(tail->prox != NULL){
		if (strcmp(tail->prox->numMatricula, chave) == 0)
			break;
		tail = tail->prox;
	}
	//return tail->prox;
	return tail; 
}

void ini_tListEncAlunos(tListEncAlunos* lista){
	lista->head = iniListaEncAluno();
	lista->tail = iniListaEncAluno();
	lista->tam = 0;
	strcpy(lista->tail->numMatricula, "999999999"); // Para listas ordenadas
	lista->head->prox = lista->tail; // Lista vazia head.prox = tail 
}

PONT busca_tListEncAlunos(tListEncAlunos lista, char chave[10]){

	PONT tail = lista.tail;
	strcpy(tail->numMatricula, chave);
	tail = lista.head; 
	while(strcmp(tail->prox->numMatricula, chave) != 0){
		tail = tail->prox;
	}
	return tail;
}

int inc_tListEncAlunos(tAluno aluno, tListEncAlunos* lista){
	PONT no = busca_tListEncAlunos(*lista, aluno.numMatricula);
	if (no->prox == lista->tail){ // o aluno não esta na lista
		PONT novo = iniListaEncAluno(); //Criando um novo no
		strcpy(novo->numMatricula, aluno.numMatricula); 
		strcpy(novo->nome, aluno.nome); // copia aluno para o novo no
		strcpy(novo->email, aluno.email);
		novo->prox = lista->tail; // o novo no aponta para o tail
		no->prox = novo; // último agora aponta para o novo
		//lista->tam++;
		return TRUE;
	}
	return FALSE; // aluno já esta na lista
}

int rem_tListEncAlunos(tAluno aluno, tListEncAlunos* lista){
	//if(lista->head->prox == lista->tail)
	//	return FALSE; //lista esta vazia
	PONT no = busca_tListEncAlunos(*lista, aluno.numMatricula);
	if (no->prox != lista->tail){ // o aluno esta na lista
		PONT exc = no->prox; // no a ser excluido
		no->prox = exc->prox; // anterior aponta para proximo
		free(exc); // livera memória
		//lista->tam--;
		return TRUE;
	}
	return FALSE; // aluno não esta na lista
}

PONT buscaOrd_tListEncAlunos(tListEncAlunos lista, char chave[10], int* achou){

	PONT tail = lista.head;
	int com = strcmp(tail->prox->numMatricula, chave);
	while(com < 0){
		tail = tail->prox;
		com = strcmp(tail->prox->numMatricula, chave);
	}
	*achou = (com == 0); 
	return tail;
}

int incOrd_tListEncAlunos(tAluno aluno, tListEncAlunos* lista){
	int achou;
	//PONT no = buscaOrd_tListEncAlunos(*lista, aluno.numMatricula, &achou);
	PONT no = buscaBin_tListEncAlunos(*lista, aluno.numMatricula, &achou);
	if(!achou){ // o aluno não esta na lista
		PONT novo = iniListaEncAluno(); //Criando um novo no
		strcpy(novo->numMatricula, aluno.numMatricula); 
		strcpy(novo->nome, aluno.nome); // copia aluno para o novo no
		strcpy(novo->email, aluno.email);
		novo->prox = no->prox; // o novo no aponta para o proximo
		no->prox = novo; // último agora aponta para o novo
		lista->tam++;
		return TRUE;
	}
	return FALSE; // aluno já esta na lista
}

int remOrd_tListEncAlunos(tAluno aluno, tListEncAlunos* lista){
	int achou;
	//if(lista->head->prox == lista->tail)
	//	return FALSE; //lista esta vazia
	//PONT no = buscaOrd_tListEncAlunos(*lista, aluno.numMatricula, &achou);
	PONT no = buscaBin_tListEncAlunos(*lista, aluno.numMatricula, &achou);
	if (achou){ // o aluno esta na lista
		PONT exc = no->prox; // no a ser excluido
		no->prox = exc->prox; // anterior aponta para proximo
		free(exc); // livera memória
		lista->tam--;
		return TRUE;
	}
	return FALSE; // aluno não esta na lista
}

PONT getAluno(int n, tListEncAlunos lista){
	PONT tail = lista.head;
	if(n >= lista.tam){
		return NULL;
	}
	for(int i = 0; i < n; i++){
		tail = tail->prox;
	}
	return tail;
}

PONT buscaBin_tListEncAlunos(tListEncAlunos lista, char chave[10], int* achou)
{	
	int min = 0;
	int max = lista.tam;
	int i;
	*achou = FALSE;
	PONT aluno = lista.head;
	while (min != max)
	{	
		i = (max + min) / 2;
		aluno = getAluno(i, lista);
		int com = strcmp(aluno->prox->numMatricula, chave);
		if (com < 0)
		{
			min = ++i;
			//lista.head = aluno;
			aluno = aluno->prox;
		}
		else
		{
			if (com > 0)
			{
				max = i;
			}
			else
			{
				*achou = TRUE;
				return aluno;
			}
		}
	}
	return aluno;
}


/*
//head->prox = (PONT)malloc(sizeof(NOALUNO));
		//tail =  head->prox;
		//strcpy(tail->numMatricula, listaS->lista[0].numMatricula);
    	//strcpy(tail->nome, listaS->lista[0].nome);
    	//strcpy(tail->email,listaS->lista[0].email);
		//tail = tail->prox;
PONT buscaNaoOrdenada_R(PONT head, char chave[10]){
	PONT lista = head;
	if (lista->prox == NULL){
		return lista;
	}else{
		int com = strcmp(lista->numMatricula, chave);
		if (com == 0)
			return lista;
		else 
			return(lista->prox, chave);
	}
}

PONT buscaNaoOrdenada_(PONT head, char chave[10], int* achou){
	PONT lista = head;
	while(lista != NULL){
		int com = strcmp(lista->numMatricula, chave);
		if (com == 0)
			return lista;
		else 
			lista = lista->prox;
	}
	return lista;
}

int incNaoOrdenada_(tAluno aluno, PONT head){
	PONT lista = head;
	lista = buscaNaoOrdenada_(lista, aluno.numMatricula);
	if(lista != NULL){

	}


}

int remNaoOrdenada_(tAluno aluno, PONT head);

int buscaOrdenada_(PONT head, char chave[10], int* achou);
int incOrdenada_(tAluno aluno, PONT head);
int remOrdenada_(tAluno aluno, PONT head);

*/