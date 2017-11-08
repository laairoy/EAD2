#include "splay_tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//cria um novo no e caso seja alocado a medoria
// inicializa os valores e devolve o novo no 
S_TREE * criar_no(int chave)
{
   S_TREE *novoNo = (S_TREE *) malloc(sizeof(S_TREE));
   if(!novoNo) return NULL;
   
   novoNo->chave = chave;
   novoNo->dir = novoNo->esq = NULL;
   return novoNo;
}

S_TREE * inserir(S_TREE **raiz, int chave);

S_TREE * buscar_no(S_TREE **raiz, int chave);

S_TREE * remover_no(S_TREE **raiz, int chave);

void rotacionar_dir(S_TREE **raiz);

void rotacionar_esq(S_TREE **raiz);
