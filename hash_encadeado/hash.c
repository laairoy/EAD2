#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


HASH * init_hash(int tam)
{
	HASH * new_hash = malloc(sizeof(HASH) + (sizeof(LIST *) *tam));
	if(!new_hash) return NULL;

	new_hash->tamanho = tam;

	for(int i = 0; i < tam; i++) new_hash->node[i] = NULL;
	return new_hash;
}

void inserir_hash(HASH *hash, int chave)
{
	//linear com divisao
	int fx = chave % hash->tamanho;
	
	inserir_lista(&(hash->node[fx]), chave);
}

LIST * buscar_hash(HASH *hash, int chave);

LIST * inserir_lista(LIST **list, int chave)
{
	assert(list);

	if(!(*list))
	{
		*list = (LIST *) malloc(sizeof(LIST));
		if(!(*list)) return NULL;
		(*list)->chave = chave;
		(*list)->prox = NULL;
		return *list;
	}
	if((*list)->chave == chave) return NULL;
	return inserir_lista(&((*list)->prox), chave);
}