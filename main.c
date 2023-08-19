// main.c
// OLIVER KIERAN GALVAO MCCORMACK ------ TIA: 42122058 -----
// PEDRO L M B VOLPE ----- TIA: 42131936 -----

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"

//----------------------------------------------------------------------------
//Função para imprimir a lista de processos
void PrintAlocListInfo(const AlocList* list)
{
 if (IsEmptyAloc(list))
 {
 printf("Lista Alocada vazia!\n");
 }
 else
 {
 // Percorrer todos os nós da lista e imprimir os valores de cada nó
 // (veja saída de exemplo no enunciado).
  tipo_MemAloc *node = list->head;
  printf("\n|||||||||||||||||||||||||||||||||||||||||||\n");
  printf("Lista Alocada com %d elementos:\n\n", list->count); 
  while (node != NULL) {
    printf(" |Numero do processo: %d  Endereço inicial: %d  Tamanho: %d|\n", node->nProcesso,node->end_i,node->tam);
    node = node->next;
  }
   printf("\n\n");
 }
}
//----------------------------------------------------------------------------
//Função para imprimir a lista de memória livre
void PrintLivreListInfo(const LivreList* list)
{
 if (IsEmptyLivre(list))
 {
 printf("Lista Livre vazia!\n");
 }
 else
 {
 // Percorrer todos os nós da lista e imprimir os valores de cada nó
 // (veja saída de exemplo no enunciado).
  tipo_MemLivre *node = list->head;
  printf("\n|||||||||||||||||||||||||||||||||||||||||||\n");
  printf("\nLista Livre com %d elementos:\n", list->count); 
  while (node != NULL) {
    printf(" |Endereço inicial: %d  Tamanho: %d|\n",node->end_i,node->tam);
    node = node->next;
  }
   printf("\n\n");
 }
}
//----------------------------------------------------------------------------
// Menu
int main(void)
{
  int entrada = 0, qtd_aloc = 0, n_proc = 0, qtd_mem = 0;

  LivreList *livrelist = LivreCreate();
  AlocList *aloclist = AlocCreate();
  
  while(entrada != 5)
  {
    printf("\n------SIMULADOR DE GERENCIAMENTO DE MEMÓRIA------\n");
    printf("\n1. Definir Memoria Livre inicial\n2. Alocar memória\n3. Finalizar processo\n4. Imprime Memorias\n5. Desligar\n");
    printf("\n------------------------------------------------");
    printf("\nInput: ");
    scanf("%d", &entrada);
    printf("------------------------------------------------");
    printf("\n\n");
    switch(entrada)
      {
        case 1:
          {
            // INICIAR MEMORIA LIVRE COM TAMANHO DEFINIDO PELO USUARIO
            printf("Digite a quantidade maxima de memória disponível: ");
            scanf("%d",&qtd_mem);
            defineMemTotal(livrelist,qtd_mem);
            break;
          }
        case 2:
          {
            //Inserir novo processo
            printf("\nInsira o número do processo a ser alocado: ");
            scanf("%d", &n_proc);
            
            printf("\nInsira a quantidade de memória a ser alocada: ");
            scanf("%d", &qtd_aloc);

            AlocaMemoria(aloclist, livrelist, n_proc, qtd_aloc);
            break;
          }
        case 3:
          {
            //Remover processo
            printf("\nInsira o número do processo a ser removido: ");
            scanf("%d", &n_proc);
            FinalizaProcesso(aloclist,livrelist,n_proc);
            OrganizaMemLivre(livrelist);
            break;
          }
        case 4:
          {
            //Imprimir listas
            PrintAlocListInfo(aloclist);
            PrintLivreListInfo(livrelist);
            break;
          }
        case 5:
          {
            //Finalizar programa (destruir listas)
            AlocDestroy(aloclist);
            LivreDestroy(livrelist);
            printf("\nPrograma desligado\n");
            break;
          }
      }
  }
  
  return 0;
}

