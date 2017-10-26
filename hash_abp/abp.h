#ifndef ABP_H
#define ABP_H

typedef struct abp
{
	int chave;
	struct abp *dir, *esq;
}ABP;

ABP * nova_chave(int chave);

ABP * inserir_chave(int chave, ABP **abp);

ABP * remover_chave(int chave, ABP **abp);

int altura_abp(ABP *abp);

void em_ordem_abp(ABP *abp);

ABP * buscar_chave_abp(int chave, ABP *abp);

#endif