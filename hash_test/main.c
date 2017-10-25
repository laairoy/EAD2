#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define TAM_MAX 1000000

void import_csv(H_hash * h_hash, char *str);

int main()
{
   H_hash *healpMd, *heaqpMd, *healpMm, *heapMy;
   int seed = 0;
   
   scanf("%d", &seed);
   srand(seed);
   
   healpMd = new_hash(TAM_MAX);
   heaqpMd = new_hash(TAM_MAX);
   healpMm = new_hash(TAM_MAX);
   heapMy = new_hash(TAM_MAX);
   
   for(int i=0; i < TAM_MAX; i++)
   {
      int chave = rand() % RAND_MAX;
      healp_md(chave, healpMd);
      heaqp_md(chave, heaqpMd);
      healp_mm(chave, healpMm);
      heap_my(chave, heapMy);
   }
   
   printf("healp md %u colisoes\n", healpMd->colisoes);
   printf("heaqp md %u colisoes\n", heaqpMd->colisoes);
   printf("healp mm %u colisoes\n", healpMm->colisoes);
   printf("heap my %u colisoes\n", heapMy->colisoes);
   
   
   import_csv(healpMd, "healpMd.csv");
   import_csv(heaqpMd, "heaqpMd.csv");
   import_csv(healpMm, "healpMm.csv");
   import_csv(healpMm, "heapMy.csv");
   
   return 0;
}

void import_csv(H_hash * h_hash, char *str)
{
   FILE *fp;
   fp = fopen(str, "w+");
   //int data[h_hash->colisoes];
   
   //for(int i=0; i<h_hash->colisoes; i++)
     // data[i]=0;
   
   for(int i=0; i < TAM_MAX; i++) fprintf(fp, "%d\n", h_hash->hash[i].colisoes);
      //data[h_hash->hash[i].colisoes]++;
   
   
   //for(int i=0; i<h_hash->colisoes; i++)
  // {
     // if(data[i]!= 0)
     // {
      //   fprintf(fp, "%d, %d\n", i, data[i]);
     // }
   //}
   fclose(fp);
}
