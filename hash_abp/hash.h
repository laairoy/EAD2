#ifndef HASH_H
#define HASH_H

#include "abp.h"

typedef struct hash
{
	int tamanho;
	ABP * node[];
} HASH;

HASH * init_hash(int tam);

void inserir_hash(HASH *hash, int chave);

ABP * buscar_hash(HASH *hash, int chave);


#endif