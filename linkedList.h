// OLIVER KIERAN GALVAO MCCORMACK ------ TIA: 42122058 -----
// PEDRO L M B VOLPE ----- TIA: 42131936 -----

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

//----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

// struct dos nós

//Nó da memoria livre
typedef struct _tipo_MemLivre {
  int end_i;
  int tam;
  struct _tipo_MemLivre *next;
}tipo_MemLivre;
//Nó da memoria alocada
typedef struct _tipo_MemAloc{
  int nProcesso;
  int end_i;
  int tam;
  struct _tipo_MemAloc *next;
}tipo_MemAloc;
//----------------------------------------------------------------------------
//struct das listas

//Lista da memoria livre
typedef struct LivreList
{
int count;
tipo_MemLivre *head;
tipo_MemLivre *tail;
}LivreList;
//Lista da memoria alocada
typedef struct AlocList
{
int count;
tipo_MemAloc *head;
tipo_MemAloc *tail;

}AlocList;
//----------------------------------------------------------------------------
//Criador das listas
LivreList *LivreCreate();
AlocList *AlocCreate();

//Destrutor das listas
LivreList *LivreDestroy(LivreList *list);
AlocList *AlocDestroy(AlocList *list);

//Insert(em qualquer local da lista) das listas
void InsertAloc(AlocList *list, tipo_MemAloc *newNode);
void InsertLivre(LivreList *list, tipo_MemLivre *newNode);

//Removes auxiliares (remoção do head)
tipo_MemAloc *RemoveHeadAloc(AlocList *list);
tipo_MemLivre *RemoveHeadLivre(LivreList *list);

//Removes auxiliares (remove tail)
tipo_MemAloc *RemoveTailAloc(AlocList *list);
tipo_MemLivre *RemoveTailLivre(LivreList *list);
//Remove das listas (remove nó em qualquer lugar da lista)

tipo_MemAloc *RemoveNodeAloc(AlocList *list, int nProc);
tipo_MemLivre *RemoveNodeLivre(LivreList *list, int end);

//Verificador se a lista está vazia
bool IsEmptyAloc(const AlocList *list);
bool IsEmptyLivre(const LivreList *list);

//Funções usadas pelo gerenciador de memória
void defineMemTotal(LivreList *list,int memTotal);
int buscaEspaco(LivreList *list ,int tam);
tipo_MemAloc *CriaBlocoAloc(int nProc, int end, int tamanho);
tipo_MemLivre *CriaBlocoLivre(int end, int tamanho);
void AlocaMemoria(AlocList *aloclist, LivreList *livrelist, int nProcesso, int tam);
void FinalizaProcesso(AlocList *aloclist, LivreList *livrelist, int value);
void OrganizaMemLivre(LivreList *list);
void LiberaListas(AlocList *aloclist, LivreList *livrelist);

//----------------------------------------------------------------------------

#endif