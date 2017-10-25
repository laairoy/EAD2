#include "abp.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//cria um novo no abp com o campo chave
ABP * nova_chave(int chave)
{
	ABP * novoNo = (ABP *) malloc(sizeof(ABP));
	if(!novoNo) return NULL;

	novoNo->dir = novoNo->esq = NULL;
	novoNo->chave = chave;

	return novoNo;
}

// recebe de entrada uma chave
// para ser inserida em uma arvore abp
ABP * inserir_chave(int chave, ABP **abp)
{
	assert(abp);

	if(!(*abp))
	{
		*abp = nova_chave(chave);
		return *abp;
	}

	if(chave < (*abp)->chave) return inserir_chave(chave, &((*abp)->esq));
	return inserir_chave(chave, &((*abp)->dir));
}

// procura um elemento em uma arvoce abp
// caso encontre este elemento, o remove 
ABP * remover_chave(int chave, ABP **abp)
{}

// percorre uma arvore abp e devolve o tamanho dela
int altura_abp(ABP *abp)
{
	int dir, esq;
	dir = esq = 0;

	if(!abp) return -1;

	esq = 1 + altura_abp(abp->esq);
	dir = 1 + altura_abp(abp->dir);

	if(esq > dir) return esq;
	return dir;
}

// imprime os elementos de uma arvore abp
// em ordem crescente
void em_ordem_abp(ABP *abp)
{
	if(!abp) return;
	em_ordem_abp(abp->esq);
	printf("%d ", abp->chave);
	em_ordem_abp(abp->dir);
}