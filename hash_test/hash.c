#include "hash.h"
#include <stdlib.h>

#define CST 0.543

H_hash * new_hash(int tam)
{
   H_hash * h_hash = (H_hash *) malloc(sizeof(H_hash)+(sizeof(Hash) *tam));
   if(!h_hash) return NULL;
   
   h_hash->tam = tam;
   h_hash->colisoes = 0;
   
   //init hash
   for(int i = 0; i < tam; i++)
   {
     h_hash->hash[i].valor = -1;
     h_hash->hash[i].colisoes = 0; 
   } 
   
   return h_hash;
}

void healp_md(int chave, H_hash *h_hash)
{
   unsigned int i, fx, colisoes;
   colisoes = 0;
   
   for(i=0; i < h_hash->tam; i++)
   {
      fx = (unsigned int)(chave + i) % h_hash->tam;
      if(h_hash->hash[fx].valor == -1 || h_hash->hash[fx].valor == chave) 
         break;

      colisoes++;
      h_hash->colisoes += 1;
   }
   
   h_hash->hash[fx].valor = chave;
   h_hash->hash[fx].colisoes = colisoes;
   
}

void heaqp_md(int chave, H_hash *h_hash)
{
   unsigned int i, fx, colisoes;
   colisoes = 0;
   
   for(i=0; i < h_hash->tam; i++)
   {
      fx = (unsigned int)(chave + i*i) % h_hash->tam;
      if(h_hash->hash[fx].valor == -1 || h_hash->hash[fx].valor == chave) 
         break;
         
      colisoes++;
      h_hash->colisoes += 1;
   }
   
   h_hash->hash[fx].valor = chave;
   h_hash->hash[fx].colisoes = colisoes;
}

void healp_mm(int chave, H_hash *h_hash)
{
   unsigned int i, fx, colisoes;
   colisoes = 0;
    
   for(i=0; i < h_hash->tam; i++)
   {
      fx = (unsigned int)((chave *CST)+i) % h_hash->tam;
      if(h_hash->hash[fx].valor == -1 || h_hash->hash[fx].valor == chave) 
         break;
      
      colisoes++;
      h_hash->colisoes += 1;
   }
   
   h_hash->hash[fx].valor = chave;
   h_hash->hash[fx].colisoes = colisoes;
}

void heap_my(int chave, H_hash *h_hash)
{
   unsigned int i, fx, colisoes;
   colisoes = 0;
   
   for(i=0; i < h_hash->tam; i++)
   {
      fx = (unsigned int)(((chave*CST)+i) + i*i) % h_hash->tam;
      if(h_hash->hash[fx].valor == -1 || h_hash->hash[fx].valor == chave) 
         break;
         
      colisoes++;
      h_hash->colisoes += 1;
      
   }
   
   h_hash->hash[fx].valor = chave;
   h_hash->hash[fx].colisoes = colisoes;
}

