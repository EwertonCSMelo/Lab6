#ifndef MATRIZ_HEADER
#define MATRIZ_HEADER
int **criarMatriz(int lin,int col);
void imprimir(int **m,int lin,int col);
void liberar(int **m, int lin);
void lerMatriz(int **m, int lin, int col);
int matrizTransposta(int **m, int lin, int col);
int adicao(int **m1,int **m2,int lin,int col);
int subtracao(int **m1,int **m2,int lin,int col);
int produtoPorEscalar(int **m,int a,int lin,int col);
int produtoEntreMatrizes(int **m1,int **m2,int lin,int col);
int matrizOposta(int **m,int lin,int col);
int determinante(int **m,int lin,int col);
#endif // MATRIZ_HEADER
