#include <stdio.h>
#include "heap.h"

HM extrair_min(HM *heap, int *tam)
{
  HM extrai = heap[0];
  heap[0] = heap[--(*tam)];

  int i = 0;
  do
  {
    i = heapify(heap, *tam, i);
  }while(i);

  return extrai;
}

void insere(HM *heap, int *tam, int pri, int chave)
{
  int i, indice;
  indice = *tam;

  heap[*tam].chave = chave;
  heap[(*tam)++].pri = pri;

  do
  {
    indice = (indice -2)/2;

    i = heapify(heap, *tam, indice);
  }while(i && indice);
}

void criar_heap(HM *vetor, int tam)
{
  for(int i=(tam/2) -1; i >= 0; i--)
    heapify(vetor, tam, i);

  for(int i=0; i <= (tam/2) -1; i++)
    heapify(vetor, tam, i);

}

void melhora_pri(HM *heap, int tam, int item, int novaPri)
{
  int i;

  heap[item].pri = novaPri;

  do
  {
    item = (item -1)/2;

    i = heapify(heap, tam, item);
  }while(i && item);
}

int troca_item(HM *heap, int ind1, int ind2)
{
  HM aux = heap[ind1];
  heap[ind1] = heap[ind2];
  heap[ind2] = aux;
  return ind2;
}

int heapify(HM *heap, int tam, int indice)
{
  int esq, dir;
  esq = (2*indice)+1;
  dir = (2*indice)+2;

  if(dir <= tam-1)
  {
    int indice_maior = (heap[esq].pri > heap[dir].pri) ? esq : dir;

    if(heap[indice].pri < heap[indice_maior].pri)
      return troca_item(heap, indice, indice_maior);

  }
  else if(esq <= tam-1)
  {
    if(heap[indice].pri < heap[esq].pri)
      return troca_item(heap, indice, esq);

  }
    return 0;
}
