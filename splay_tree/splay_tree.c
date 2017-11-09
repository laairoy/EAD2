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
/*
S_TREE * buscar_no(S_TREE **raiz, int chave)
{ 
   //caso base: arvore vazia ou se a raiz é a chave
   if((*raiz) == NULL || (*raiz)->chave == chave)
      return (*raiz);

   //verificamos se a chave está na subarvore esquerda
   if((*raiz)->chave > chave){
      //chave não está na árvore
      if((*raiz)->esq == NULL)
         return (*raiz);

      //zig-zig - esquerda-esquerda
      if((*raiz)->esq->chave > chave){
         //primeiro trazemos a chave como raiz de esquerda-esquerda
         (*raiz)->esq->esq = buscar_no(&((*raiz)->esq->esq), chave)

         //realiza a primeira rotação, segunda rotação é feita depois
         (*raiz) = rotacionar_dir(&((*raiz)->esq->esq), *raiz)
      }
      else if((*raiz)->chave < chave){
         //primeiro, trazemos a chave para a raiz da esquerda/direita
         (*raiz)->esq->dir = buscar_no(&((*raiz)->esq->dir), chave);

         //realiza primeira rotação para raiz->esq
         if((*raiz)->esq->dir != NULL)
            (*raiz)->esq = rotacionar_esq(&((*raiz)->esq), *raiz);
      }
      //chave está na subarvore direita
      else{
         //chave não está na arvore, retorna
         if((*raiz)->dir == NULL)
            return (*raiz);

         //zag-zig - direita-esquerda
         if((*raiz)->dir->chave > chave){
            //trazemos a chave como raiz de direita-esquerda
            (*raiz)->dir->esq = buscar_no(&((*raiz)->dir->esq), chave);

            //primeira rotação para raiz->dir
            if((*raiz)->dir->esq != NULL)
               (*raiz)->dir = rotacionar_dir(&((*raiz)->dir), *raiz);
         }
         else if((*raiz)->dir->chave < chave){ //zag-zag - direita-direita
            //traz a chave como raiz de direita-direita e faz a primeira rotação
            (*raiz)->dir->dir = buscar_no(&((*raiz)->dir->dir), *raiz);
            *raiz = rotacionar_esq(&((*raiz)->dir->dir), *raiz);
         }
         //realiza segunda rotação para raiz
         return((*raiz)->dir == NULL)? (*raiz): rotacionar_esq(&((*raiz)->dir), *raiz);
      }
   }
}
*/
// primeiro realizar splay no nó x
// logo após compara-se a raíz ao nó x

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

