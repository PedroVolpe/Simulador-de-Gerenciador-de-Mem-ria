// OLIVER KIERAN GALVAO MCCORMACK ------ TIA: 42122058 -----
// PEDRO L M B VOLPE ----- TIA: 42131936 -----

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "linkedList.h"
//Define auxiliar para facilitar a remoção de um nó alocado dinamicamente
#define SAFE_DELETE(ptr) { if(ptr) { free(ptr); ptr = NULL; }}

//----------------------------------------------------------------------------
//Criar listas encadeadas vazias
LivreList *LivreCreate(){ 
  LivreList *newListLivre = malloc(sizeof(LivreList));
  newListLivre->count = 0;
  newListLivre->head = newListLivre->tail = NULL;
  return newListLivre;
}
AlocList *AlocCreate(){ 
  AlocList *newListAloc = malloc(sizeof(AlocList));
  newListAloc->count = 0;
  newListAloc->head = newListAloc->tail = NULL;
  return newListAloc;
}
//----------------------------------------------------------------------------
//Liberar memória alocada para a lista
LivreList *LivreDestroy(LivreList *list){
  
  tipo_MemLivre *node = list->head;
  tipo_MemLivre *next = NULL;
  while(node != NULL){
    next = node->next;
    free(node);
    node = next;
  }
  node = next = NULL;
  list->head = list->tail = NULL;
  list->count = 0;

  free(list);
  list = NULL;
  return list;
}
//----------------------------------------------------------------------------
AlocList *AlocDestroy(AlocList *list){

  tipo_MemAloc *node = list->head;
  tipo_MemAloc *next = NULL;
  while(node != NULL){
    next = node->next;
    free(node);
    node = next;
  }
  node = next = NULL;
  list->head = list->tail = NULL;
  list->count = 0;
  
  free(list);
  list = NULL;
  return list;
}
//----------------------------------------------------------------------------
void InsertAloc(AlocList *list, tipo_MemAloc *newNode)	
{
  //If linked list is empty
  if (list->head == NULL)
    {
      newNode->next = list->head;
      list->head = list->tail = newNode;
      list->count++;
      return;
    }

  //Localiza o nó antes da inserção
  tipo_MemAloc *current = list->head;
  while (current->next != NULL && current->next->end_i < newNode->end_i)
    current = current->next;
  
  //Insere o novo nó depois do no encontrado 
  if(newNode->end_i > current->end_i){
      newNode->next = current->next;
      current->next = newNode;
      if(newNode->next == NULL)
        list->tail = newNode;
  }
  //Insere o novo nó antes do no encontrado
  else{
      newNode->next = current;
      list->head = newNode;
    
      if(current->next == NULL)
        list->tail = current;
  }
  list->count++;
}
//----------------------------------------------------------------------------
void InsertLivre(LivreList *list, tipo_MemLivre *newNode)	
{
  //If linked list is empty
  if (list->head == NULL)
    {
      newNode->next = list->head;
      list->head = list->tail = newNode;
      list->count++;
      return;
    }

  //Localiza o nó antes da inserção
  tipo_MemLivre *current = list->head;
  while (current->next != NULL && current->next->end_i < newNode->end_i)
    current = current->next;
  
  //Insere o novo nó depois do no encontrado  
  if(newNode->end_i > current->end_i){
      newNode->next = current->next;
      current->next = newNode;
      if(newNode->next == NULL)
        list->tail = newNode;
  }
  //Insere o novo nó antes do no encontrado
  else{
      newNode->next = current;
      list->head = newNode;
    
      if(current->next == NULL)
        list->tail = current;
  }
  list->count++;
}
//----------------------------------------------------------------------------
//Remover o nó do início da lista
//Função para remover o head da lista alocada (primeiro nó) 
tipo_MemAloc *RemoveHeadAloc(AlocList *list){
  if (IsEmptyAloc(list)){
    return NULL;
  }
  tipo_MemAloc *toRemove = list->head;
  if (list->head == list->tail){
    list->head = list->tail = NULL;
  }
  else{
    list->head = list->head->next;
  }
  list->count--;
  toRemove->next = NULL;
  
  return toRemove;
}
//----------------------------------------------------------------------------
//Função para remover o head da lista livre (primeiro nó) 
tipo_MemLivre *RemoveHeadLivre(LivreList *list){
  if (IsEmptyLivre(list)){
    return NULL;
  }
  tipo_MemLivre *toRemove = list->head;
  if (list->head == list->tail){
    list->head = list->tail = NULL;
  }
  else{
    list->head = list->head->next;
  }
  list->count--;
  toRemove->next = NULL;
  
  return toRemove;
}
//----------------------------------------------------------------------------
//Remover o nó do final da lista
//Função para remover o tail da lista alocada (ultimo nó) 
tipo_MemAloc *RemoveTailAloc(AlocList *list){
  if (IsEmptyAloc(list)){
    return NULL;
  }
  if (list->head == list->tail){
    return RemoveHeadAloc(list);
  }
  tipo_MemAloc *toRemove = list->head;
  tipo_MemAloc *previous = NULL;
  while(toRemove != list->tail){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  previous->next = NULL;
  list->tail = previous;
  list->count--;
  toRemove->next = NULL;
  return toRemove;
}
//----------------------------------------------------------------------------
//Função para remover o tail da lista livre (ultimo nó) 
tipo_MemLivre *RemoveTailLivre(LivreList *list){
  if (IsEmptyLivre(list)){
    return NULL;
  }
  if (list->head == list->tail){
    return RemoveHeadLivre(list);
  }
  tipo_MemLivre *toRemove = list->head;
  tipo_MemLivre *previous = NULL;
  while(toRemove != list->tail){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  previous->next = NULL;
  list->tail = previous;
  list->count--;
  toRemove->next = NULL;
  return toRemove;
}
//----------------------------------------------------------------------------
//Remover nó com elemento específico da lista alocada
tipo_MemAloc *RemoveNodeAloc(AlocList *list, int nProc){
  if (IsEmptyAloc(list)){
    return NULL;
  }
  tipo_MemAloc *toRemove = list->head;
  tipo_MemAloc *previous = NULL;
  while ((toRemove != NULL) && (toRemove->nProcesso != nProc)){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  if (toRemove == NULL)
  {
    return NULL;
  }
  else if(toRemove == list->head)
  {
    return RemoveHeadAloc(list);
  }
  else if(toRemove == list->tail)
  {
    return RemoveTailAloc(list);
  }
  else{
    previous->next = toRemove->next;
    list->count--;
    toRemove->next = NULL;
    return toRemove;
  }
}
//----------------------------------------------------------------------------
//Remover nó com elemento específico da lista livre
tipo_MemLivre *RemoveNodeLivre(LivreList *list, int end){
  if (IsEmptyLivre(list)){
    return NULL;
  }
  tipo_MemLivre *toRemove = list->head;
  tipo_MemLivre *previous = NULL;
  while ((toRemove != NULL) && (toRemove->end_i != end)){
    previous = toRemove;
    toRemove = toRemove->next;
  }
  if (toRemove == NULL)
    return NULL;
  else if(toRemove == list->head)
    return RemoveHeadLivre(list);
  else if(toRemove == list->tail)
    return RemoveTailLivre(list);
  else{
    previous->next = toRemove->next;
    list->count--;
    toRemove->next = NULL;
    return toRemove;
  }
}
//----------------------------------------------------------------------------
//Verificar se a lista está vazia
bool IsEmptyAloc(const AlocList *list){
  if (list->count == 0)
    return true;
  return false;
}
bool IsEmptyLivre(const LivreList *list){
  if (list->count == 0)
    return true;
  return false;
}
//----------------------------------------------------------------------------
//Função para definir memória total disponivel (deve ser executado apenas uma vez)
void defineMemTotal(LivreList *list,int memTotal){
  tipo_MemLivre *newNodeLivre = malloc(sizeof(tipo_MemLivre));
  newNodeLivre->end_i = 0;
  newNodeLivre->tam = memTotal;
  InsertLivre(list, newNodeLivre);

  printf("Memória total disponivel definida\n");
}
//----------------------------------------------------------------------------
//Função para buscar espaço livre para inserção de um novo nó, na lista de processos.
//Se encontrar, retorna seu endereço inicial, se não retorna -1
int buscaEspaco(LivreList *list ,int tam){
  tipo_MemLivre *current = list->head;
  while(current->next != NULL && current->tam < tam){
    current = current->next;
  }
  if (current == NULL || current->tam < tam)
    return -1; // NÃO TEM ESPAÇO TRATAR DPS

  return current->end_i;
}
//----------------------------------------------------------------------------
// Cria um novo nó de processo, para ser inserido na lista
tipo_MemAloc *CriaBlocoAloc(int nProc, int end, int tamanho){
  tipo_MemAloc *newnode = malloc(sizeof(tipo_MemAloc));
  newnode->nProcesso = nProc;
  newnode->end_i = end;
  newnode->tam = tamanho;
  return newnode;
}
//----------------------------------------------------------------------------
// Cria um novo nó de memoria livre, para ser inserido na lista
tipo_MemLivre *CriaBlocoLivre(int end, int tamanho){
  tipo_MemLivre *newnode = malloc(sizeof(tipo_MemLivre));
  newnode->end_i = end;
  newnode->tam = tamanho;
  return newnode;
}
//----------------------------------------------------------------------------
//Função para inserir um novo processo, se houver espaço disponivel
void AlocaMemoria(AlocList *aloclist, LivreList *livrelist, int nProcesso, int tam){
  int end_i;
  end_i = buscaEspaco(livrelist, tam);
  if(end_i == -1){
    printf("Não há espaço disponivel para o processo\n");
    return;
  }
  tipo_MemAloc *newNodeAloc = CriaBlocoAloc(nProcesso, end_i, tam);
  
  InsertAloc(aloclist, newNodeAloc);
  // Parte da memoria livre
  tipo_MemLivre *current = livrelist->head;
  while(current != NULL && current->end_i != end_i)
    current = current->next;
  
  tipo_MemLivre *newNodeLivre = CriaBlocoLivre((end_i+tam), (current->tam - tam));

  current = RemoveNodeLivre(livrelist, end_i);
  SAFE_DELETE(current);
  InsertLivre(livrelist, newNodeLivre);

  printf("Processo %d inserido com sucesso\n",nProcesso);
}
//----------------------------------------------------------------------------
//Fução para remover um nó especifico da lista de processos, se ele existir
void FinalizaProcesso(AlocList *aloclist, LivreList *livrelist, int value){
  tipo_MemAloc *current = aloclist->head;
  //Buscar o nó a ser removido para inseri-lo na memoria livre
  while(current != NULL && current->nProcesso != value){
    current = current->next;
  }
  //Se nó for igual a NULL, não existe o processo passado na lista
  if (current == NULL){
    printf("Não existe processo com o id: %d, na memória\n",value);
    return;
  }
  // Parte da MemLivre (alocar o bloco removido da alocada na livre)
  tipo_MemLivre *newNodeLivre = CriaBlocoLivre(current->end_i, current->tam);
  InsertLivre(livrelist, newNodeLivre);
  
  // Remover o bloco da alocada passando seu id
  current = RemoveNodeAloc(aloclist, value);
  SAFE_DELETE(current);

  printf("Processo %d removido com sucesso\n",value);
}
//----------------------------------------------------------------------------
//Função que organiza a memória livre.
//Se houverem espaços continguos de memória livre, eles serão amalgamados, se não irá manter como estava
void OrganizaMemLivre(LivreList *list){
  tipo_MemLivre *current = list->head;
  tipo_MemLivre *removed;
  //Percorre toda a lista
  while (current->next != NULL){
    //Se forem continguos funde-os
    if ((current->end_i + current->tam) == current->next->end_i){
      current->tam += current->next->tam;
      
      removed = RemoveNodeLivre(list, current->next->end_i);
      SAFE_DELETE(removed);
    }
    //Se não, mantem como estava, e busca novos blocos continguos
    else
      current = current->next;
  }
  printf("Memoria livre organizada com sucesso\n");
}
//----------------------------------------------------------------------------
//Função para Liberar as listas quando acabar o programa
void LiberaListas(AlocList *aloclist, LivreList *livrelist){
  AlocDestroy(aloclist);
  LivreDestroy(livrelist);
}
//----------------------------------------------------------------------------


