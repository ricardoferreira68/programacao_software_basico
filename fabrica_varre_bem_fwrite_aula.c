/* Programa gerado para exibir os dados dos 3 sensores da guilhotina 01.
    Feito por Estagiário (O bom!)
    Data: 12/04/2021, às 09:07
   Este programa ler os dados do arquivo "guilhotina01_dados.dat" que contém a leitura 
   dos 3 sensores e exibe esses dados na tela.
   A estrutura do aquivo é: layout do arquivo

layout do arquivo
Descrição                   Campo Tipo      Tamanho
Código da guilhotina        cod   caractere 2
Sensor de comprimento em cm s01   real      00.000 a 99.999
Sensor de pressão em psi    s02   inteiro   0 a 999
Sensor de detecção da fibra s03   booleano  1

Exemplo de dados:         
cod | s01  | s02 | s03
01   20.000  300    1     
01   18.090  300    1 
01   19.095  300    1 
01   19.805  300    1 
01   20.175  300    1 

*/
#include <stdio.h>
#include <string.h>
// Estrutura 'sensores' dos registros de dados de cada leitura dos sensores.
typedef struct {
	char cod[2];
	float s01;
	int s02;
	int s03;
} sensores;
int main(void)
{
    // Declara a variável 'dados' como sendo do timpo 'sensores'.
    sensores dados;
    // Declara o ponteiro 'pt_arq' para manipular o arquivo "em disco".
    FILE * pt_arq;
    // Abre o arquivo para gravação dos dados.
    pt_arq = fopen("guilhotina_dados.dat", "w");
    if (pt_arq == NULL)
        printf("Erro na criação do arquivo guilhotina_dados.dat\n");
    else
    {
        strcpy(dados.cod, "01");
        printf("Digite o valor do sensor s01 (0 p/ sair): ");
        scanf("%f", &dados.s01);
        while (dados.s01 != 0)
        { 
            printf("Digite o valor do sensor s02: ");
            scanf("%d", &dados.s02);
            printf("Digite o valor do sensor s03: ");
            scanf("%d", &dados.s03);
            
            // Grava os dados lidos dos sensores no arquivo.
            fwrite(&dados, sizeof(dados), 1, pt_arq);

            printf("Digite o valor do sensor s01 (0 p/ sair): ");
            scanf("%f", &dados.s01);
        }
        fclose(pt_arq);
    }
}
