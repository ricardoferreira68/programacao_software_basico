#include <stdio.h>
int main(void)
{
    //Declara as Variáveis utilizadas no programa.
    int A, B, Resultado;
    float C, Resultado2;
    
    A = 5;
    B = 2;
    C = 2;
    Resultado  = A + B;   //Resultado = 7
    Resultado  = A - B;    //Resultado = 3
    Resultado  = A * B;    //Resultado = 10
    Resultado  = A / B;    //Resultado = 2
    Resultado  = A % B;   //Resultado = 1
    Resultado2  = A / C;    //Resultado = 2.5

    printf("A + B =  %d \n", A + B);
    printf("A - B =  %d \n", A - B);
    printf("A * B =  %d \n", A * B);
    printf("A / B =  %d \n", A / B);
    printf("A % B =  %d \n", A % B);
    printf("A / C =  %f \n", A / C);

    //Fim do programa
    return(0);
}