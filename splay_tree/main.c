#include "splay_tree.h"
#include <stdlib.h>
#include <stdio.h>

void my_print(S_TREE *raiz)
{
   printf("chave inserida é: %d\n", raiz->chave);
   if(raiz->esq) printf("Filho esquerdo é: %d\n", raiz->esq->chave);
   else printf("Filho esquerdo é: NULL\n");
   if(raiz->dir) printf("Filho direito é: %d\n\n", raiz->dir->chave);
   else printf("Filho direito é: NULL\n\n");
}
int main()
{
   S_TREE *raiz = NULL;
   inserir(&raiz, 7);
   my_print(raiz);
   
   inserir(&raiz, 8);
   my_print(raiz);
   
   inserir(&raiz, 23);
   my_print(raiz);
   
   inserir(&raiz, 21);
   my_print(raiz);
   inserir(&raiz, 10);
   my_print(raiz);
   inserir(&raiz, 24);
   my_print(raiz);

   return 0;
}
