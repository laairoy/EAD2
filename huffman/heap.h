#ifndef HEAP_H
#define HEAP_H

typedef struct no {
  int chave;
  int pri;
  struct no *esq, *dir;
} HM;

HM extrair_min(HM *heap, int *tam);
void insere(HM *heap, int *tam, HM item);
void criar_heap(HM *vetor, int tam);
void melhora_pri(HM *heap, int tam, int item, int novaPri);
int troca_item(HM *heap, int ind1, int ind2);
int heapify(HM *heap, int tam, int indice);

#endif
