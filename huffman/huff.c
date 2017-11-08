#include "huff.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

HUFF * criar_freq_lista(char str[], int tamanho);

void existe_na_lista(char letra);

void add_no_lista(HUFF **huff, HUFF *node);

void gerar_arvore_huff(HUFF *huff);