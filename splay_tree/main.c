#include "splay_tree.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
   S_TREE *raiz = NULL;
   inserir(NULL, &raiz, NULL, 5);
   printf("raiz agor é: %d\n", raiz->chave);
   raiz = inserir(NULL, &raiz, NULL, 6);
   printf("raiz agor é: %d\n", raiz->chave);
   inserir(NULL, &raiz, NULL, 3);
   printf("raiz agor é: %d\n", raiz->chave);
   return 0;
}
