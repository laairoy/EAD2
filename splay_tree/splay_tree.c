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

S_TREE * splay_BU(S_TREE **raiz, int chave)
{
   assert(raiz);
   
   if(!(*raiz))
   {
      return *raiz;
   }
   if((*raiz)->chave == chave) return *raiz;
   
   //esq
   if(chave < (*raiz)->chave)
   {
      if((*raiz)->esq == NULL) return *raiz;
      
      if(chave < (*raiz)->esq->chave)
      {
         splay_BU(&((*raiz)->esq->esq), chave);
         rotacionar_dir(raiz);
      }
      else if(chave > (*raiz)->esq->chave)
      {
         splay_BU(&((*raiz)->esq->dir), chave);
         if((*raiz)->esq->dir != NULL) rotacionar_esq(&((*raiz)->esq));
      }
      
      if((*raiz)->esq != NULL) rotacionar_dir(raiz);
      
      return *raiz;
   }
   else
   {
      if((*raiz)->dir == NULL) return *raiz;
      
      //esq
      if(chave < (*raiz)->dir->chave)
      {
         splay_BU(&((*raiz)->dir->esq), chave);
         
         if((*raiz)->dir->esq != NULL) rotacionar_dir(&((*raiz)->dir));
      }
      else if(chave > ((*raiz)->dir->chave))
      {
         splay_BU(&((*raiz)->dir->dir), chave);
         rotacionar_esq(raiz);
      }
      
      if((*raiz)->dir != NULL) rotacionar_esq(raiz);
      
      return *raiz;
   }

}

S_TREE *splay_TD(S_TREE **raiz, int chave)
{
   assert(raiz);

   if(!(*raiz)) 
   {
      return *raiz;
   }

   if(chave < (*raiz)->chave)
   {
      if((*raiz)->esq == NULL || chave == (*raiz)->chave) 
         return *raiz;

      if(chave < (*raiz)->esq->chave)
      {

         if((*raiz)->esq->esq)
         { 
            rotacionar_dir(&((*raiz)->esq));
            rotacionar_dir(raiz);
         }
         else
         {
            rotacionar_dir(raiz);
            return *raiz;
         } 
      }
      else
      {
         if((*raiz)->esq->dir)
         {
            rotacionar_esq(&((*raiz)->esq));
            rotacionar_dir(raiz);
            
         }
         else
         {
            rotacionar_dir(raiz);
            return *raiz;
         }
      }

      splay_TD(raiz, chave);
   }
   else if(chave > (*raiz)->chave)
   {
      if((*raiz)->dir == NULL || chave == (*raiz)->dir->chave) 
         return *raiz;

      if(chave > (*raiz)->dir->chave)
      {
         if((*raiz)->dir->dir)
         {
            rotacionar_esq(&((*raiz)->dir));
            rotacionar_esq(raiz);
         }
         else
         {
            rotacionar_esq(raiz);
            return *raiz;
         }
      }
      else
      {
         if((*raiz)->dir->esq)
         {
            rotacionar_dir(&((*raiz)->dir));
            rotacionar_esq(raiz);
         }
         else
         {
            rotacionar_esq(raiz);
            return *raiz;
         }
      }
      
      splay_TD(raiz, chave);
   }
  return *raiz;
}

S_TREE * inserir(S_TREE **raiz, int chave)
{
   if(!(*raiz))
   {
      *raiz = criar_no(chave);
      return *raiz;
   } 
   
   splay_BU(raiz, chave);

   if((*raiz)->chave == chave) return *raiz;
   
   S_TREE * novoNo = criar_no(chave);
   
   if(chave < (*raiz)->chave)
   {
      novoNo->dir = *raiz;
      novoNo->esq = (*raiz)->esq;
      (*raiz)->esq = NULL;
   }
   else
   {
      novoNo->esq = *raiz;
      novoNo->dir = (*raiz)->dir;
      (*raiz)->dir = NULL;
   }
   
   *raiz = novoNo;
   
   return novoNo;
}

S_TREE * buscar_no(S_TREE **raiz, int chave)
{
   splay_BU(raiz, chave);

   if((*raiz)->chave == chave) return *raiz;

   return NULL;
}

// o procedimento verifica se a raiz e valida
// o auxiliar recebe o raiz
// o filho esquerdo se torna o novo raiz
// o filho esquerdo do auxiliar recebe o filho direito do raiz
// o auxiliar se torna o novo filho direito do raiz
S_TREE * remover_no(S_TREE **raiz, int chave)
{
   S_TREE *aux;

   if(!(*raiz)) return NULL;

   splay_BU(raiz, chave);

   //se a chave não está presente na árvore
   //então, retornamos a raiz
   if((*raiz)->chave != chave)
      return *raiz;

   //se a chave está presente na árvore
   //se o filho esquerdo da raiz é null
   //raiz->dir torna-se raiz
   if(!((*raiz)->esq))
   {
      aux = *raiz;
      *raiz = (*raiz)->dir;
   }

   //se o filho esquedo existe
   else
   {
      aux = *raiz;
      /* desde que (*raiz)->chave == chave
         então depois de realizarmos splay da chave passada
         a árvore não passará a ter filhos direitos na sub-arvore direita
         e o valor maximo na sub-arvore esquerda realizará splay
         ou seja, nova raiz*/
      splay_BU(&((*raiz)->esq), chave);
      *raiz = (*raiz)->esq;
      //torne filho direito da antiga raiz
      //como nova raiz do filho direito
      (*raiz)->dir = aux->dir;
   }

   //free na antiga raiz
   //que é o nó que continha a chave passada
   free(aux);

   //retorna nova raiz que foi feito splay
   return *raiz;
}

void rotacionar_dir(S_TREE **raiz)
{
   assert(raiz);
   
   S_TREE * auxNo = *raiz;
   *raiz = (*raiz)->esq;
   auxNo->esq = (*raiz)->dir;
   (*raiz)->dir = auxNo;
}

// o procedimento verifica se a raiz e valida
// o auxiliar recebe o raiz
// o filho direito se torna o novo raiz
// o filho direito do auxiliar recebe o filho esquerdo do raiz
// o auxiliar se torna o novo filho esquerdo do raiz
void rotacionar_esq(S_TREE **raiz)
{
   assert(raiz);
   
   S_TREE * auxNo = *raiz;
   *raiz = (*raiz)->dir;
   auxNo->dir = (*raiz)->esq;
   (*raiz)->esq = auxNo;
}

void print_emOrdem(S_TREE *raiz)
{
   if(!raiz) return;
   print_emOrdem(raiz->esq);
   printf("%d ", raiz->chave);
   print_emOrdem(raiz->dir);
}