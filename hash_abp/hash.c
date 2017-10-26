#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


HASH * init_hash(int tam)
{
	HASH * new_hash = malloc(sizeof(HASH) + (sizeof(ABP *) *tam));
	if(!new_hash) return NULL;

	new_hash->tamanho = tam;

	for(int i = 0; i < tam; i++) new_hash->node[i] = NULL;
	return new_hash;
}

void inserir_hash(HASH *hash, int chave)
{
	//linear com divisao
	int fx = chave % hash->tamanho;
	
	//funcao da abp
	inserir_chave(chave, &(hash->node[fx]));
}

ABP * buscar_hash(HASH *hash, int chave)
{
	int fx = chave % hash->tamanho;
	ABP * abp = buscar_chave_abp(chave, hash->node[fx]);

}