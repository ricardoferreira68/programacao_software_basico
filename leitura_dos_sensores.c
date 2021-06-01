#include <stdio.h>
#include <stdlib.h>
#include "fabrica_varre_bem.h"


void leitura_dos_sensores(void)
{
    FILE *arq;  //Ponteiro para manipular o arquivo na memória secundária.
    estrutura_sensores sensores; // Estrutura para armazenar os dados dos sensores.
    char arquivo[] = NOME_ARQUIVO_EM_DISCO; //Nome do arquivo de dados gravado em disco.

    //Rotina para incluir dados dos sensores da guilhotina.
    // Código 01 para todos os registros da guilhotina.
    strcpy(sensores.cod, "01");

    cabecalho();
    printf("| Digite o valor do sensor s01 (comprimento em centímetro)....: ");
    scanf("%f", &sensores.s01);
    while (sensores.s01 != 0)
    {
        printf("| Digite o valor do sensor s02 (pressão em psi)...............: ");
        scanf("%d", &sensores.s02);
        printf("| Digite o valor do sensor s02 (fibra presente: 1-sim / 0-não): ");
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

        cabecalho();
        printf("| Digite o valor do sensor s01 (comprimento em centímetro)....: ");
        scanf("%f", &sensores.s01);
    }
    return 0;
}
