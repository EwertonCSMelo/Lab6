#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
 int opcao,esc;
 int **matriz1=NULL,**matriz2=NULL,**matrizOp=NULL,linha,coluna;

  opcao=10;
  while(opcao!=0)
    {
        system("cls");
        printf("Escolha a operacao de Matriz desejada:\n\n");

        printf("(1)Calcular a matriz transposta\n");
        printf("(2)Calcular a adição entre matrizes\n");
        printf("(3)Calcular a subtração entre matrizes\n");
        printf("(4)Calcular o produto de uma matriz por um escalar\n");
        printf("(5)Calcular o produto entre matrizes\n");
        printf("(6)Calcular a matriz oposta\n");
        printf("(7)Calcular o determinante de uma matriz\n");
        printf("(0)Para sair\n\n\n");

        printf("Opcao: ");
        scanf("%d",&opcao);



    if (opcao!=0)
       {
           switch(opcao)
             {
                case 1: printf("Digite o numero de linhas e colunas:");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas: \n");
                        lerMatriz(matriz1,linha,coluna);
                        matrizOp=matrizTransposta(matriz1,linha,coluna);
                        imprimir(matrizOp,coluna,linha);
                        break;
                case 2: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1: \n");
                        lerMatriz(matriz1,linha,coluna);
                        matriz2=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 2: \n");
                        lerMatriz(matriz2,linha,coluna);
                        matrizOp=adicao(matriz1,matriz2,linha,coluna);
                        imprimir(matrizOp,linha,coluna);
                        break;
                case 3: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1: \n");
                        lerMatriz(matriz1,linha,coluna);
                        matriz2=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 2: \n");
                        lerMatriz(matriz2,linha,coluna);
                        matrizOp=subtracao(matriz1,matriz2,linha,coluna);
                        imprimir(matrizOp,linha,coluna);
                        break;
                case 4: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1:\n");
                        lerMatriz(matriz1,linha,coluna);
                        printf("Digite o escalar para produto: ");
                        scanf("%d",&esc);
                        matrizOp=produtoPorEscalar(matriz1,esc,linha,coluna);
                        imprimir(matrizOp,linha,coluna);
                        break;
                case 5: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1: \n");
                        lerMatriz(matriz1,linha,coluna);
                        matriz2=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 2:\n");
                        lerMatriz(matriz2,linha,coluna);
                        printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        if(linha==coluna)
                          {
                           matrizOp=produtoEntreMatrizes(matriz1,matriz2,linha,coluna);
                           imprimir(matrizOp,linha,coluna);
                          }
                        else
                          {
                           printf("O produto nao e possivel!!!");
                          }
                          break;
                case 6: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1: \n");
                        lerMatriz(matriz1,linha,coluna);
                        matrizOp=matrizOposta(matriz1,linha,coluna);
                        imprimir(matrizOp,linha,coluna);
                        break;
                case 7: printf("Digite o numero de linhas e colunas: ");
                        scanf("%d %d",&linha,&coluna);
                        matriz1=criarMatriz(linha,coluna);
                        printf("Digite os dados das linhas e colunas da Matriz 1: \n");
                        lerMatriz(matriz1,linha,coluna);
                        printf("O determinante e: %d\n\n",determinante(matriz1,linha,coluna));
                        system("pause");
                        break;
                        default: printf("Opcao Invalida.\n");
             }



       }
    }

    return 0;
}
