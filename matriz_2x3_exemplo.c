#include <stdio.h>
#include <stdlib.h>
void main() 
{
  int i, j, M[2][3];
  //lendo a matriz
  for (i=0; i<2; i++) 
    for (j=0; j<3; j++) 
    {
        printf("Informe o elemento[%d][%d]: ", i+1, j+1);
        scanf("%d", &M[i][j]);
    }
  for (i=0; i<2; i++) 
    for (j=0; j<3; j++)
        printf("M[%d][%d] = %d \n", i+1, j+1, M[i][j]);
}
