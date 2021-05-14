/* HOSPITIAL MATERNIDADE DO POVO
   SETOR DE SUPORTE TECNOLÓGICO
   MÓDULO DE LEITURA DA INCUBADOR NEONATAL
   FINALIDADE: LER O ARQUIVO TXT GERADO PELA INCUBADORA E PRODUZIR UM RELATÓRIO COM OS DADOS DE TEMPERATURA.
   DESENVOLVEDOR: JOÃO DAS DORES
   DATA: 31/03/2021 ÀS 08:35
*/
#include <stdio.h>
int main()
{
    /* Arquivo modo texto com as informações de temperaturas registradas de 1 em 1 minuto. 
        Arquivo: incubadora_dados.txt
       Arquivo txt gerado pela Incubadora no dia 02/03/2021, a partir das 11 horas:
       2021 03 02 11 00 36.3

       20210302110036.3
       
    */
   struct incubadora
   {
       int ano;  // Campo para armazenar o ano lido do arquivo txt.
       int mes;  // Campo para armazenar o mes lido do arquivo txt.
       int dia;  // Campo para armazenar o dia lido do arquivo txt.
       int hora;  // Campo para armazenar o hora lido do arquivo txt.
       int min;  // Campo para armazenar o minuto lido do arquivo txt.
       float temp;  // Campo para armazenar o temperatura lido do arquivo txt.
   };
   struct incubadora temperatura;  // variável do tipo struct para guardar os dados lidos do arquivo.
   FILE* arquivo = fopen("arq_incubadora_neonatal_temperatura.txt", "r");  // Ponteiro para o arquivo txt.

    printf("\n\n=========================================\n");
    printf("HOSPITIAL MATERNIDADE DO POVO\n");
    printf("LEITURA DA INCUBADOR NEONATAL\n");
    printf("Relatório de Temperatura 1 em 1 minuto.\n");
    printf("-----------------------------------------\n");
    printf("DATA       HORA  TEMPERATURA\n");
    printf("---------- ----- -----------\n");

    // Lê o arquivo txto. 
    fscanf(arquivo, "%4d%2d%2d%2d%2d%f", &temperatura.ano, &temperatura.mes, &temperatura.dia, &temperatura.hora, &temperatura.min, &temperatura.temp);
    // Laço para ler o arquivo até encontrar o final do arquivo EOF=TRUE.
    while (!feof(arquivo))
    {
        printf("%02d/", temperatura.dia);
        printf("%02d/", temperatura.mes);
        printf("%4d ", temperatura.ano);
        printf("%02d:", temperatura.hora);
        printf("%02d    ", temperatura.min);
        printf("%4.1f\n", temperatura.temp);
       fscanf(arquivo, "%4d%2d%2d%2d%2d%f", &temperatura.ano, &temperatura.mes, &temperatura.dia, &temperatura.hora, &temperatura.min, &temperatura.temp);
    }
    printf("-----------------------------------------\n");
    fclose(arquivo);
   return 0;
}
