#include "splay_tree.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
   S_TREE *raiz = NULL;
   inserir(&raiz, 5);
   printf("raiz agor é: %d\n", raiz->chave);
   inserir(&raiz, 6);
   printf("raiz agor é: %d\n", raiz->chave);
   return 0;
}
