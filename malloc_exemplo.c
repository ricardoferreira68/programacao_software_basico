#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
  float *vetor;
  int i, tamanho;

  printf("Tamanho do vetor: ");
  scanf("%d", &tamanho);
  vetor = (float *) malloc(tamanho * sizeof(float));
  for (i = 0; i < tamanho; i++) {
    printf("Digite o valor %i de %i: ", i+1, tamanho);
    scanf("%f",&vetor[i]);
  }
  printf("\nValores digitados: \n");
  for (i = 0;i < tamanho; i++){
    printf("%.2f\n",vetor[i]);
  }
  free(vetor);
  return 0;
}