#include "abp.h"
#include <stdio.h>

int main()
{
	ABP * abp = NULL;
	inserir_chave(5, &abp);
	inserir_chave(3, &abp);
	inserir_chave(4, &abp);
	inserir_chave(1, &abp);
	inserir_chave(7, &abp);
	em_ordem_abp(abp);
	int h = altura_abp(abp);
	printf("\n%d\n", h);
}