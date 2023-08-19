# Simulador-de-Gerenciador-de-Memoria

Este projeto visa simular, de forma simplificada, o sistema de gerenciamento de memória do linux.

Para tal, utilizamos uma estrutura de dados chamada LinkedList (Lista Ligada), com ela criamos duas classes de LinkedList, uma para a memória alocada e outra para a memória livre.

Funções: 

  - Definir a quantidade de memória livre total.
  
  - Aloca Mémoria (ou inserir processo)
    - Nessa função, passamos o número do processo e a quantidade de memória que ele utiliza. Em seguida verificamos se há memória disponivel, na memoria livre, para a inserção do processo. Caso exista espaço alocamos o processo na memória alocada e, automaticamente, o inicio da memória livre é atualizado.
  
  - Finalizar Processo
    - Para essa operação, primeiro buscamos o processo pelo seu número. Se encontrado, pegamos seu tamanho e alocamos um bloco de memória na lista de memória livre com o tamanho do processo, visto que temos que liberar sua memória, depois removemos o processo da memória alocada.
    - Posteriormente reorganizamos a memória livre a fim de evitar fragmentação externa, na qual mesmo que o valor de memoria disponivel seja suficiente para inserir o novo processo, o espaço não está contiguo, tornando impossivel alocar o processo.
  
  - Imprime memórias
    - Imprime todos os processos alocados na memoria alocada, caso exista algum, e mostra quanto espaço livre existe, assim como a maneira que está distribuido.

  - Desligar
    - Deleta todo o conteudo de ambas as memórias e termina o programa.
   


  By: 
  
  Pedro Volpe
  
  OLIVER KIERAN GALVAO MCCORMACK
      
