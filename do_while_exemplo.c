#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cod;
    do
    {
        printf("Código Plano        Valor\n");
        printf("-------------------------\n");
        printf(" A     Básico     R$24,90\n");
        printf(" B     Controle   R$39,90\n");
        printf(" C     Completo   R$69,90\n");
        printf(" Z     Sair do Sistema\n");
        printf("-------------------------\n");
        printf("Digite o Código do plano: ");
        scanf(" %c", &cod);
        printf("Você digitou %c\n\n\n", cod);
    } while (cod != 'Z');
}

