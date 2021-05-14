#include <stdio.h>
#include <string.h>
int main(void)
{
    //Estrutura com o conjunto de dados de um estado da guilhotina.
    struct guilhotina_sensores
    {
        char cod[2];
        float s01;
        int s02;
        short s03;
    } sensores; //Variável para a estrutura.

    //Ponteiro para manipular o arquivo na memória secundária.
    FILE *arq;
    char arquivo[] = "arq_guilhotina_dados.dat"; //Nome do arquivo de dados gravado em disco.

    //Abre o arquivo de dados dos sensores no modo acréscimo.
    arq = fopen(arquivo, "w+");
    //Verifica se houve erro na abertura do arquivo.
    if (arq == NULL)
        printf("Erro na abertura do arquivo.\n");
    else
    {
        //Rotina para incluir dados dos sensores da guilhotina.
        // Código 01 para todos os registros da guilhotina.
        strcpy(sensores.cod, "01");
        printf("Digite o valor do sensor s01 (comprimento em centímetro): ");
        scanf("%f", &sensores.s01);
        while (sensores.s01 != 0)
        {
            printf("Digite o valor do sensor s02 (pressão em psi): ");
            scanf("%d", &sensores.s02);
            printf("Digite o valor do sensor s02 (fibra presente: 1-sim / 0-não): ");
            scanf("%d", &sensores.s03);
            fwrite(&sensores, sizeof(sensores), 1, arq);
            printf("Digite o valor do sensor s01 (comprimento em centímetro): ");
            scanf("%f", &sensores.s01);
        }
        fclose(arq);
    }
    return 0;
}
/*
cod|s01   |s02 |s03
01  20.000 300  1 
01  20.000 299  1 
01  19.995 299  1 
01  19.905 300  1 
01  20.005 300  1 
*/
