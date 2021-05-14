#include <stdio.h>
int main() 
{
    int num;
    printf("Informe o numero: ");
    scanf("%d", &num);
    if (num < 10)
        printf("O número é menor que 10\n");
    else
        if (num > 10)
            printf("O número é maior que 10\n");
        else
            printf("O número igual a 10\n");
    printf("Fim do programa\n");
}