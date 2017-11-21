#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  RBtree* arv = NULL;
  int escolha=1;
  while(escolha!=0){
      printf("Digite sua escolha: \n (1)Inserir\n (2)Deletar\n (3)Buscar\n (4)Desenhar\n (5)PreOrder\n (6)InOrder\n (7)PostOrder\n (0) Sair");
      scanf("%d", &escolha);

      switch(escolha){
        case 1:
            printf("Digite o número para inserir: ");
            int inserir;
            scanf("%d", &inserir);
            arv= Insere(arv,inserir);
            break;
        case 2:
            printf("Digite o número para deletar: ");
            int del;
            scanf("%d", &del);
            arv= Remove(arv,inserir);
            break;
        case 3:
            printf("Digite o número para buscar: ");
            int busc;
            scanf("%d", &busc);
            if(Consulta(busc,arv))
                printf("O nodo está na arvore");
            else
                printf("O nodo não está na arvore");
            break;
        case 4:
            Desenha(arv,0);
            break;
        case 5:
            preOr(arv);
            break;
        case 6:
            inOr(arv);
            break;
        case 7:
            preOr(arv);
            break;
           }



  }
  return 0;
}
