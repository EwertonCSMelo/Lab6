#include <stdio.h>
#include <stdlib.h>
int **criarMatriz(int lin,int col)
{
  int i,**m;
      m=(int**)malloc(lin*sizeof(int));
      for(i=0;i<lin;i++)
        {
          m[i]=(int*)calloc(col,sizeof(int));
        }
      return m;
}

void imprimir(int **m,int lin,int col)
{
    int i,j;

    for(i=0;i<lin;i++)
       {
         for(j=0;j<col;j++)
            {
               printf("%d ",m[i][j]);
            }
         printf("\n");
       }
}

void liberar(int **m, int lin)
{
    int i;
    for (i=0;i<lin;i++)
        {
           free(m[i]);
        }
        free(m);
    printf("Matriz Liberada da Memoria\n");
}

void lerMatriz(int **m, int lin, int col)
{
     int i,j;

     for (i=0;i<lin;i++)
       {
        for (j=0;j<col;j++)
          {
            scanf("%d",&m[i][j]);
          }
       }
}
int matrizTransposta(int **m, int lin, int col)
{
    int i,j,**mt;
    mt=criarMatriz(col,lin);
    for(i=0;i<lin;i++)
       {
        for(j=0;j<col;j++)
           {
            mt[j][i]=m[i][j];
           }
       }
       return mt;
}

int adicao(int **m1,int **m2,int lin,int col)
{
  int i,j,**mad;
  mad=criarMatriz(lin,col);

  for (i=0;i<lin;i++)
      {
        for (j=0;j<col;j++)
        {
            mad[i][j]=m1[i][j]+m2[i][j];
        }
      }
      return mad;
}
int subtracao(int **m1,int **m2,int lin,int col)
{
  int i,j,**msub;
  msub=criarMatriz(lin,col);

  for (i=0;i<lin;i++)
      {
        for (j=0;j<col;j++)
        {
            msub[i][j]=m1[i][j]-m2[i][j];
        }
      }
      return msub;
}
int produtoPorEscalar(int **m,int a,int lin,int col)
{
  int i,j;

  for (i=0;i<lin;i++)
      {
        for (j=0;j<col;j++)
        {
            m[i][j]=a*m[i][j];
        }
      }
      return m;
}
int produtoEntreMatrizes(int **m1,int **m2,int lin,int col)
{
  int i,j,k,**mp;
           for(k=0;k<lin;k++)
              {
               for(i=0;i<lin;i++)
                  {
                  for(j=0;j<col;j++)
                     {
                      mp[i][k]+=m1[i][j]*m2[j][i];
                     }
                  }
           }
           return mp;
}
int matrizOposta(int **m,int lin,int col)
{
  int i,j;

  for (i=0;i<lin;i++)
      {
        for (j=0;j<col;j++)
        {
            m[i][j]=(-1)*m[i][j];
        }
      }
      return m;
}
int determinante(int **m,int lin,int col)
{
  int i,j,k,jini,s1,s2,prod,det,**maux;

  if(lin==2&&col==2)
  {
      det=m[1][1]*m[2][2]-m[1][2]*m[2][1];
      return det;
  }
  else
  {
      maux=criarMatriz(lin,col+col-1);

      for (i=0;i<lin;i++) // Inicializando matriz auxiliar com matriz m
          {
           for(j=0;j<col;j++)
             {
               maux[i][j]=m[i][j];
             }
          }

      for (i=0;i<lin;i++)  // Inicializando demais colunas
          {
           for(j=col;j<2*col-1;j++)
           {   k=j-col;
               maux[i][j]=m[i][k];
           }
          }
          jini=0;
          j=jini;
          s1=0;
          s2=0;
          while(j<col)
          {
              prod=1;
              for(i=0;i<lin;i++)
              {
                  if(i<=j)
                  {
                      prod=prod*maux[i][j++];
                  }

              }
              s1=s1+prod;
              prod=1;
              jini=jini+1;
              j=jini;
          }

          jini=(2*col)-2;
          j=jini;
          while(j>=col-1)
          {
              prod=1;

              for(i=0;i<lin;i++)
              {
                  prod=prod*maux[i][j--];
              }
              s2=s2+prod;
              jini=jini-1;
              j=jini;
          }
  }
      return s1-s2;
}
