#ifndef HUFF_H
#define HUFF_H

#include "heap.h"

typedef HM HUFF;

HUFF * criar_freq_lista(char str[], int *tam);

HUFF * gerar_arvore_huff(char str[], int *tam);

void travessia(HUFF *raiz);

#endif
