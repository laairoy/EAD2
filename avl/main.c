#include "avl.h"
#include <stdio.h>

int main()
{
	AVL * avl = NULL;
	inserir_chave(1, &avl);
	inserir_chave(2, &avl);
	inserir_chave(3, &avl);
	inserir_chave(4, &avl);
	inserir_chave(5, &avl);
	inserir_chave(6, &avl);
	inserir_chave(7, &avl);
	em_ordem_avl(avl);
	int h = altura_avl(avl);
	printf("\n%d\n", h);
}