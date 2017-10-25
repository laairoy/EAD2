#ifndef HASH_H
#define HASH_H

typedef struct hash
{
   int valor;
   unsigned int colisoes;
} Hash;

typedef struct head
{
   int tam;
   unsigned int colisoes;
   Hash hash[];
} H_hash;

H_hash * new_hash(int tam);

void healp_md(int chave, H_hash *h_head);

void heaqp_md(int chave, H_hash *h_hash);

void healp_mm(int chave, H_hash *h_hash);

void heap_my(int chave, H_hash *h_hash);


#endif
