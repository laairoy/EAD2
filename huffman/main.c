#include "huff.h"
#include <string.h>
#include <stdio.h>

int main()
{
  char str[] = "ieaoieaoiesaaaaaeeiiiiiiiiiiaaaaaaaadonieraasodierasodieaso\0";
  int tam = strlen(str);
  HUFF *list = gerar_arvore_huff(str, &tam);

  for(int i=0; i<tam; i++)
  {
    printf("%c = %d\n",list[i].chave, list[i].pri);
  }

  travessia(list);

  return 0;
}
