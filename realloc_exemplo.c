#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    /* declaração do ponteiro */
    int *vetor = NULL; 
    /* alocação de memória para o vetor */
    vetor = (int*) malloc(5 * sizeof(int));
    /* altera o valor da posição 3 para trinta e quatro */
    vetor[3] = 34;
    /* Imprime o conteúdo do vetor */
    for (int i=0;i<5;i++)
        printf("%d\n", vetor[i]);
    /* alocação de memória para o vetor */
    vetor = (int*) realloc(vetor, 3 * sizeof(int));
    /* altera o valor da posição 1 para trinta e quatro */
    vetor[1] = 26;
    /* Imprime o conteúdo do vetor */
    printf("\n\n");
    for (int i=0;i<3;i++)
        printf("%d\n", vetor[i]);
    /* liberta a área de memória alocada */
    free(vetor); 
    return 0;
}