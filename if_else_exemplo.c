#include <stdio.h>
int main() 
{
    int num;
    printf("Informe o numero: ");
    scanf("%d", &num);
    if (num > 10)
        printf(" Numero maior que 10\n");
    else
        printf("O número é menor ou igual a 10\n");
    printf("Fim do programa\n");
}