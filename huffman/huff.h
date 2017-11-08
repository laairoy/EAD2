#ifndef HUFF_H
#define HUFF_H

typedef struct huff
{
	int freq;
	char letra;
	struct huff *prox, *dir, *esq;
};

HUFF * criar_freq_lista(char str[], int tamanho);

void existe_na_lista(char letra);

void add_no_lista(HUFF **huff, HUFF *node);

void gerar_arvore_huff(HUFF *huff);