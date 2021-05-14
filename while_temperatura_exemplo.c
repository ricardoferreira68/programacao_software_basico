#include <stdio.h>
#include <stdlib.h>
int main()
{
    float temp;
    system("clear"); // Limpar a tela
    printf("qual a temperatura? ");
    scanf("%f", &temp);
    while(temp>=36.5 && temp <=37.5)
    {
        printf("Temperatura Normal\n");
        system("sleep 01"); // pausa de 1 segundo
        printf("qual a temperatura? ");
        scanf("%f", &temp);
    }
    printf("ALERTA! Problema de temperatura\n");
}
