#include <stdio.h>
int main(void)
{
    int Ingresso = 1;
    int Idade = 22;
    if (!Ingresso)
        printf("Você não tem ingresso!\n");
    if (Idade < 18)
        printf("Você é menor de idade!\n");
    if (!Ingresso || Idade < 18)
        printf("Você não pode entrar!\n");
    if (Ingresso && Idade >= 18)
        printf("Entrar autorizada!\n");
    return(0);
}
