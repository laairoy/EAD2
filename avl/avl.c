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
	novoNo->fb = 0;

	return novoNo;
}

// recebe de entrada uma chave
// para ser inserida em uma arvore avl
int inserir_chave(int chave, AVL **avl)
{
	assert(avl);

	if(!(*avl))
	{
		*avl = nova_chave(chave);
		return 1;
	}

	else if(chave < (*avl)->chave)
	{ 
		int cresceu = inserir_chave(chave, &((*avl)->esq));

		if(cresceu)
		{
			(*avl)->fb += -1;

			switch((*avl)->fb)
			{
				case -2:
					rotacao_dir(avl);
					return 0;
				case -1:
					return 1;
				case 0:
					return 0;
			}
		}
	}
	else 
	{
		int cresceu = inserir_chave(chave, &((*avl)->dir));

		if(cresceu)
		{
			(*avl)->fb += 1;

			switch((*avl)->fb)
			{
				case 2: 
					rotacao_esq(avl);
					return 0;
				case 1:
					return 1;
				case 0:
					return 0;
			}
		}
	} 
		
	return 0;
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
	printf("chave = %d, FB = %d\n", avl->chave, avl->fb);
	em_ordem_avl(avl->dir);
}

void rotacao_dir(AVL **avl)
{
	if((*avl)->esq->fb == 1) rotacao_esq(&((*avl)->esq));
	AVL *aux = (*avl)->esq;
	(*avl)->esq = aux->dir;
	aux->dir = *avl;
	*avl = aux;
	(*avl)->dir->fb = (*avl)->fb +1;
	(*avl)->fb += 1; 
}

void rotacao_esq(AVL **avl)
{
	if((*avl)->dir->fb == -1) rotacao_dir(&((*avl)->dir));
	AVL *aux = (*avl)->dir;
	(*avl)->dir = aux->esq;
	aux->esq = *avl;
	*avl = aux;
	(*avl)->esq->fb = (*avl)->fb -1;
	(*avl)->fb -= 1; 
}