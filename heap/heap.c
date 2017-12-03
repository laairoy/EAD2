#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HM * extrair_min(HM *heap, int tam);
void insere(HM *heap, int tam, int pri, int chave);
HM * criar_heap(HM *vetor, int tam);
void melhora_pri(HM *heap, int tam, int item, int novaPri);

void troca_item(HM *heap, int ind1, int ind2)
{
  HM aux = heap[ind1];
  heap[ind1] = heap[ind2];
  heap[ind2] = aux;
}

void heapify(HM *heap, int tam, int indice)
{
  int esq, dir;
  esq = (2*indice)+1;
  dir = (2*indice)+2;

  if(dir >= tam-1)
  {
    int indice_menor = (heap[esq].pri < heap[dir].pri) ? esq : dir;

    if(heap[indice].pri > heap[indice_menor].pri)
      troca_item(heap, indice, indice_menor);

    return;
  }
  if(esq >= tam-1)
  {
    if(heap[indice].pri > heap[esq].pri)
      troca_item(heap, indice, esq);

    return;
  }
}
