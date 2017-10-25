#ifndef AVL_H
#define AVL_H

typedef struct avl
{
	int chave, fb;
	struct avl *dir, *esq;
}AVL;

AVL * nova_chave(int chave);

int inserir_chave(int chave, AVL **avl);

AVL * remover_chave(int chave, AVL **avl);

int altura_avl(AVL *avl);

void em_ordem_avl(AVL *avl);

void rotacao_esq(AVL **avl);

void rotacao_dir(AVL **avl);

#endif