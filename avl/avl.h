#ifndef AVL_H
#define AVL_H

typedef struct avl
{
	int chave;
	struct avl *dir, *esq;
}AVL;

AVL * nova_chave(int chave);

AVL * inserir_chave(int chave, AVL **avl);

AVL * remover_chave(int chave, AVL **avl);

int altura_avl(AVL *avl);

void em_ordem_avl(AVL *avl);

#endif