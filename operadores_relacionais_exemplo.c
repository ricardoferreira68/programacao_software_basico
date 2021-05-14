#include <stdio.h>
int main(void)
{
    int A, B, Resultado;   
    A = 50;
    B = 20;
    Resultado = A == B;   //Resultado = 0 (falso)
    Resultado = A != B;    //Resultado = 1 (verdadeiro)
    Resultado = A < B;    //Resultado = 0 (falso)
    Resultado = A > B;    //Resultado = 1 (verdadeiro)
    Resultado = A <= B;   //Resultado = 0 (falso)
    Resultado = A >= B;    //Resultado = 1 (verdadeiro)

    printf("A == B =  %d \n", A == B);
    printf("A != B =  %d \n", A != B);
    printf("A < B =  %d \n", A < B);
    printf("A > B =  %d \n", A > B);
    printf("A <= B =  %d \n", A <= B);
    printf("A >= B =  %d \n", A >= B);

    if (100)   // A != B   -->  50 != 20 --> 1
        printf("Este é verdadeiro!\n");
    else
        printf("imprime este!\n");
    return(0);
}