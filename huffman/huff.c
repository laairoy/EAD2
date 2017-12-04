#include "huff.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

HUFF * criar_freq_lista(char str[], int *tam)
{
  int totalEle = 0;
  int hash[256];
  for(int i=0; i<256; i++) hash[i] = 0;

  for(int i =0; i<*tam; i++)
  {
    if(!hash[str[i]]) totalEle++;
    hash[str[i]]++;
  }
  *tam = totalEle;

  HUFF *listaFreq = malloc(sizeof(HUFF)*totalEle);

  int a = 0;
  for(int i=0; i<256; i++)
  {
    if(hash[i])
    {
      listaFreq[a].chave = i;
      listaFreq[a].pri = hash[i];
      listaFreq[a].dir = listaFreq[a++].esq = NULL;
    }
  }
  criar_heap(listaFreq, *tam);
  return listaFreq;
}

HUFF * criar_no(HUFF item)
{
  HUFF * novo = malloc(sizeof(HUFF));
  if(!novo) return NULL;

  novo->pri = item.pri;
  novo->chave = item.chave;
  novo->dir = item.dir;
  novo->esq = item.esq;
  return novo;
}

HUFF * gerar_arvore_huff(char str[], int *tam)
{
  HUFF *listaFreq = criar_freq_lista(str, tam);

  while(*tam > 1)
  {
    HUFF men1 = extrair_min(listaFreq, tam);
    HUFF men2 = extrair_min(listaFreq, tam);

    HUFF novoNo;
    novoNo.chave = -1;
    novoNo.pri = men1.pri + men2.pri;
    novoNo.esq = criar_no(men1);
    novoNo.dir = criar_no(men2);

    insere(listaFreq, tam, novoNo);

  }
HUFF *aux = criar_no(listaFreq[0]);
free(listaFreq);
return aux;
}

void travessia(HUFF *raiz)
{
  if(!raiz->dir && !raiz->esq)
  {
    printf("%c \n", raiz->chave);
    return;
  }
  travessia(raiz->esq);
  printf("0 \n");
  travessia(raiz->dir);
  printf("1 \n");
}
