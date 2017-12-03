#include "heap.h"
#include <stdio.h>

int main(){

  HM heap[3];
  heap[0].chave = 1;
  heap[0].pri = 45;
  heap[1].chave = 1;
  heap[1].pri = 4;
  //heap[2].chave = 1;
  //heap[2].pri = 5;

  heapify(heap, 2, 0);

  for (int i =0; i < 2; i++) printf("indice = %d, pri = %d\n", i, heap[i].pri);

  return 0;
}
