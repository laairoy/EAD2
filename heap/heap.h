#ifndef HEAP_H
#define HEAP_H

typedef struct no {
  int chave;
  int pri;
} HM;

HM * extrair_min(HM *heap, int tam);
void insere(HM *heap, int tam, int pri, int chave);
HM * criar_heap(HM *vetor, int tam);
void melhora_pri(HM *heap, int tam, int item, int novaPri);
void troca_item(HM *heap, int ind1, int ind2)
void heapify(HM *heap, int tam, int indice);

#endif