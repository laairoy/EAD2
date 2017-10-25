#include "avl.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//cria um novo no avl com o campo chave
AVL * nova_chave(int chave)
{
	AVL * novoNo = (AVL *) malloc(sizeof(AVL));
	if(!novoNo) return NULL;

	novoNo->dir = novoNo->esq = NULL;
	novoNo->chave = chave;

	return novoNo;
}

// recebe de entrada uma chave
// para ser inserida em uma arvore avl
AVL * inserir_chave(int chave, AVL **avl)
{
	assert(avl);

	if(!(*avl))
	{
		*avl = nova_chave(chave);
		return *avl;
	}

	if(chave < (*avl)->chave) return inserir_chave(chave, &((*avl)->esq));
	return inserir_chave(chave, &((*avl)->dir));
}

// procura um elemento em uma arvoce avl
// caso encontre este elemento, o remove 
AVL * remover_chave(int chave, AVL **avl)
{}

// percorre uma arvore avl e devolve o tamanho dela
int altura_avl(AVL *avl)
{
	int dir, esq;
	dir = esq = 0;

	if(!avl) return -1;

	esq = 1 + altura_avl(avl->esq);
	dir = 1 + altura_avl(avl->dir);

	if(esq > dir) return esq;
	return dir;
}

// imprime os elementos de uma arvore avl
// em ordem crescente
void em_ordem_avl(AVL *avl)
{
	if(!avl) return;
	em_ordem_avl(avl->esq);
	printf("%d ", avl->chave);
	em_ordem_avl(avl->dir);
}

void rotacao_dir(AVL **avl)
{
	AVL *aux = (*avl)->esq;
	(*avl)->esq = aux->dir;
	aux->dir = *avl;
	*avl = aux;
}

void rotacao_esq(AVL **avl)
{
	AVL *aux = (*avl)->dir;
	(*avl)->dir = aux->esq;
	aux->esq = *avl;
	*avl = aux;
}