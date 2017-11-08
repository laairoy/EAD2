#include "splay_tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//cria um novo no e caso seja alocado a medoria
// inicializa os valores e devolve o novo no 
S_TREE * criar_no(int chave)
{
   S_TREE *novoNo = (S_TREE *) malloc(sizeof(S_TREE));
   if(!novoNo) return NULL;
   
   novoNo->chave = chave;
   novoNo->dir = novoNo->esq = NULL;
   return novoNo;
}

S_TREE * inserir(S_TREE *esq, S_TREE **raiz, S_TREE *dir, int chave)
{
   assert(raiz);

   if(!(*raiz)) 
   {
      *raiz = criar_no(chave);
      (*raiz)->dir = dir;
      (*raiz)->esq = esq;

      return *raiz;
   }

   if(chave < (*raiz)->chave)
   {
      S_TREE **aux = &((*raiz)->esq);
      (*raiz)->esq = NULL;

      if(dir) 
         rotacionar_dir(&dir, *raiz);
      else
         dir = *raiz;

      *raiz = inserir(esq, aux, dir, chave);

   }
   else if(chave > (*raiz)->chave)
   {

      S_TREE **aux = &((*raiz)->dir);
      (*raiz)->dir = NULL;
      
      if(esq)
         rotacionar_esq(&esq, *raiz);
      else 
         esq = *raiz;

      *raiz = inserir(esq, aux, dir, chave);
   }
  return *raiz;
}

/*S_TREE * inserir(S_TREE **raiz, int chave)
{
   assert(raiz);
   
   if(!(*raiz))
   {
      *raiz = criar_no(chave);
      return *raiz;
   }
   if((*raiz)->chave == chave) return *raiz;
   
   //esquerda
   if(chave < (*raiz)->chave)
   {
      if((*raiz)->esq == NULL)
      {
         inserir(&((*raiz)->esq), chave);
         rotacionar_dir(raiz);
      }
   } 
   else
   {
      if((*raiz)->dir == NULL)
      {
         inserir(&((*raiz)->dir), chave);
         rotacionar_esq(raiz);
      }
   }
   return *raiz;
}*/

S_TREE * buscar_no(S_TREE **raiz, int chave);

S_TREE * remover_no(S_TREE **raiz, int chave);

// o procedimento verifica se a raiz e valida
// o auxiliar recebe o raiz
// o filho esquerdo se torna o novo raiz
// o filho esquerdo do auxiliar recebe o filho direito do raiz
// o auxiliar se torna o novo filho direito do raiz
void rotacionar_dir(S_TREE **raiz, S_TREE *aux)
{
   assert(raiz);
   
   S_TREE * auxNo = *raiz;
   *raiz = aux;
   auxNo->esq = (*raiz)->dir;
   (*raiz)->dir = auxNo;
}

// o procedimento verifica se a raiz e valida
// o auxiliar recebe o raiz
// o filho direito se torna o novo raiz
// o filho direito do auxiliar recebe o filho esquerdo do raiz
// o auxiliar se torna o novo filho esquerdo do raiz
void rotacionar_esq(S_TREE **raiz, S_TREE *aux)
{
   assert(raiz);
   
   S_TREE * auxNo = *raiz;
   *raiz = aux;
   auxNo->dir = (*raiz)->esq;
   (*raiz)->esq = auxNo;
}

