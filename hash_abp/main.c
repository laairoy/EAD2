#include "hash.h"
#include <stdio.h>

#define TAM 1000

int main()
{
	HASH * hash = init_hash(TAM);

	
	inserir_hash(hash, 1001);
	inserir_hash(hash, 100001);
	inserir_hash(hash, 1);
	inserir_hash(hash, 10001);
	

	ABP * abp = buscar_hash(hash, 1);
	if(abp)
		printf("elemento %d encontrado\n", abp->chave);

	int total = totalColisoes(hash->node, hash->tamanho);

	printf("total de colisoes: %d\n", total);

	return 0;
}