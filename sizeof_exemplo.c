#include <stdio.h>
int main(void)
    {
        typedef struct {
        char cod[2];
        float s01;
        int s02;
        int s03;
    } sensores;
    sensores dados;
    printf("Tamanho da Estrutura dados: %d\n", sizeof(dados));
    printf("Tamanho da Estrutura cod: %d\n", sizeof(dados.cod));
    printf("Tamanho da Estrutura s01: %d\n", sizeof(dados.s01));
    printf("Tamanho da Estrutura s02: %d\n", sizeof(dados.s02));
    printf("Tamanho da Estrutura s03: %d\n", sizeof(dados.s03));
    return 0;
}
