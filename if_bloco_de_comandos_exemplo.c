#include <stdio.h>
int main() 
{
    int num;
    printf("Informe o numero: ");
    scanf("%d", &num);
    if (num > 10)
    {
        printf("Você digitou %d\n", num);
        printf("Este número é maior que 10\n");
    }
    printf("Fim do programa\n");
}
