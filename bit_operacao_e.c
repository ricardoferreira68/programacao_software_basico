#include <stdio.h>
int main(void)
{
    // Declaracao das variáveis
    int A = 4, B = 0, C, D;
    // "E Lógico" no nível de bit.
    C = A & B;
    // "E Lógico" no nível de byte (ou no nível do dado).
    D = A && B;
    // Resultados.
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    return 0;
}
