#include "heap.h"
#include <stdio.h>

int main(){
  int tam = 7;
  HM heap[tam];
  heap[0].pri = 9;
  heap[1].pri = 22;
  heap[2].pri = 34;
  heap[3].pri = 21;
  heap[4].pri = 74;
  heap[5].pri = 41;
  heap[6].pri = 26;

  for (int i =0; i < tam; i++) printf("%d ", heap[i].pri);
  printf("\n");

  criar_heap(heap, tam);

  for (int i =0; i < tam; i++) printf("%d ", heap[i].pri);
  printf("\n");

  extrair_min(heap, &tam);

  for (int i =0; i < tam; i++) printf("%d ", heap[i].pri);
  printf("\n");

  insere(heap, &tam, 42, 2);
  
  for (int i =0; i < tam; i++) printf("%d ", heap[i].pri);
  printf("\n");

  melhora_pri(heap, tam, 4, 28);

  for (int i =0; i < tam; i++) printf("%d ", heap[i].pri);
  printf("\n");
  return 0;
}
