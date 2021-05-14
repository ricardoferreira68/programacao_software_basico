#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Início do Programa Principal.
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
    FILE *arq;  //Ponteiro para manipular o arquivo na memória secundária.
    char arquivo[] = "arq_guilhotina_dados.dat"; //Nome do arquivo de dados gravado em disco.
    time_t agora;  // Usada para receber o timestamp da hora atual.

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

        //Abre o arquivo de dados dos sensores no modo acréscimo.
        arq = fopen(arquivo, "a+");
        //Verifica se houve erro na abertura do arquivo.
        if (arq == NULL)
        { 
            printf("Erro na abertura do arquivo.\n");
            exit(1);  // Encerra a execução. 
        }
        // Grava o registro de dados no arquivo.
        fwrite(&sensores, sizeof(sensores), 1, arq);
        // Fecha o arquivo para liberá-lo para o programa que monta o gráfico em tempo real.
        fclose(arq);

        printf("Digite o valor do sensor s01 (comprimento em centímetro): ");
        scanf("%f", &sensores.s01);
    }
    return 0;
}
