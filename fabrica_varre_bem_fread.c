/* Programa gerado para exibir os dados dos 3 sensores da guilhotina 01.
    Feito por Estagiário (O bom!)
    Data: 12/04/2021, às 09:07
   Este programa ler os dados do arquivo "guilhotina01_dados.dat" que contém a leitura 
   dos 3 sensores e exibe esses dados na tela.
   A estrutura do aquivo é: layout do arquivo

Campo   Tipo        Tamanho         Descrição
cod     caractere   2               Código da guilhotina
s01     real        00.000 a 99.999 Sensor de comprimento em cm
s02     inteiro     0 a 999         Sensor de pressão em psi
s03     booleano    1               Sensor de detecção da fibra

Exemplo de dados:         20.000 = Mx10e = 2x101 = B+B = 00100001
cod | s01  | s02 | s03
01   20.000  300    1     300 = B = 100101100
01   18.990  299    1 
01   19.095  301    1 
01   19.905  300    1 
01   20.075  300    1 
EOF
*/
#include <stdio.h>
#include <time.h>
typedef struct 
{
    char cod[2];
    float s01;
    int s02;
    short s03;
} dados_guilhotina;
dados_guilhotina dados;
// Início do programa.
int main(void)
{
    FILE *arq;
    arq = fopen("arq_guilhotina_dados.dat", "rb");
    printf("=============================================\n");
    printf(" FÁBRICA DE VASSOURAS VARRE BEM\n");
    printf("Sistema Supervisória da Fábrica\n");
    printf("Módulo de Leitura dos dados da Guilhotina 01\n");
    printf("---------------------------------------------\n"); 
    printf("Cód  Sensor01 Sensor02 Sensor03\n");

    fread(&dados, sizeof(dados), 1, arq);
  //fwrite(&dados, sizeof(dados), 1, arq);
    while (!feof(arq))
    {
        printf("%2s    ", dados.cod);
        printf("%6.3f    ", dados.s01);
        printf("%5d       ", dados.s02);
        printf("%1i\n", dados.s03);
        fread(&dados, sizeof(dados), 1, arq);
    }
    printf("=============================================\n");
    fclose(arq);
}
