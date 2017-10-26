#ifndef HASH_H
#define HASH_H

typedef struct l_node
{
	int chave;
	struct l_node *prox;
}LIST;

typedef struct hash
{
	int tamanho;
	LIST * node[];
} HASH;

HASH * init_hash(int tam);

void inserir_hash(HASH *hash, int chave);

LIST * buscar_hash(HASH *hash, int chave);

LIST * inserir_lista(LIST **list, int chave);

#endif