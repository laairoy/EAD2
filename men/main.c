#include "men.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * Registro de 1 KiB i.e. 1024 bytes
 */
 #define BYTES_CAMPOS 1016

typedef struct registro
{
  unsigned long chave;//Valor da Chave: 8 bytes
  unsigned char outros[BYTES_CAMPOS];//outros campos: 1016 bytes (dados)
}registro;

typedef struct TipoEnderecoExterno
{
   unsigned long int i; //indice do bloco em que um registro se encontra num arquivo
   int j; //indice do registro dentro do i-th bloco do arquivo
} TipoEnderecoExterno;

TipoEnderecoExterno buscaExterna(unsigned long chave, char nomeArq[], char modoArq[]);

TipoEnderecoExterno buscaExterna(unsigned long chave, char nomeArq[], char modoArq[])
{
  FILE *arq = fopen(nomeArq, modoArq);
  if(!arq) exit(1);


}

void main()
{
  registro a[3];

  a[0].chave = 0;
  a[1].chave = 1;
  a[2].chave = 2;

  FILE *arq = fopen("/home/laairoy/progs/EAD2/men/big.txt", "wb");
  char letra[4097];
  size_t nread;

  fwrite(a, sizeof(registro), 3, arq);
  fclose(arq);

  arq = fopen("/home/laairoy/progs/EAD2/men/big.txt", "rb");
  registro i[10];
  int total = 0;
  while(!feof(arq))
  {
    //fseek(arq, sizeof(int), 5);
    if(fread(&i, sizeof(registro), 4, arq)) total++;
    //letra[nread] = '\0';
    //printf("%d\n", nread);

  }
  float x = ((float)total*(sizeof(registro)))/4096;
  printf("%.2f\n", x);
  //for(int a =0; a<3; a++) printf("%d\n", i[a].chave);
  fclose(arq);
}
