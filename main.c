#include <stdio.h>
#include <stdlib.h>
#include "fabrica_varre_bem.h"

/* Aplicação para a Fábrica Varre Bem: Sistema Supervisório com Painel Gráfico

    Este aplicativo visa lê os dados dos sensores da guilhotina da fábrica
    e exibir um gráfico com os dados da leitura do sensor01, responsável por
    detectar o comprimento do corte.

    Feito por Estagiário (O bom!)
    Data: 14/04/2021, às 21h30.

layout do arquivo
=========================================================================
|Descrição                    | Campo    | Tipo       | Tamanho         |
+-----------------------------+----------+------------+-----------------+
| Código da guilhotina        | cod      | caractere  | 2               |
| Sensor de comprimento em cm | s01      | real       | 00.000 a 99.999 |
| Sensor de pressão em psi    | s02      | inteiro    | 0 a 999         |
| Sensor de detecção da fibra | s03      | booleano   | 1               |
|*** Novo campo para armazenar a data e a hora                          |
| Data e hora de leitura      | dia_hora | struct tm                    |
=========================================================================

Exemplo de dados:
cod | s01  | s02 | s03
01   20.000  300    1
01   18.090  300    1
01   19.095  300    1
01   19.805  300    1
01   20.175  300    1
01   18.001  300    1
01   21.900  300    1
01   19.510  300    1

Compilação via linha de comando com a biblioteca openGL:
gcc -lGL -lGLU -lglut -lm arquivo_fonte.c -o arquivo_objeto
*/

int main(int argc, char** argv)
{
    char pousa;  // Combinada com getchar(), provoca uma pausa no programa.
    char opcao_menu;  // Escolher uma opção do menu.

    do
    {
        cabecalho();
        menu_principal();
        printf("  Escolha sua opção: ");
        scanf(" %c", &opcao_menu);
        switch (opcao_menu)
        {
            case '1':
                leitura_dos_sensores();
                break;
            case '2':
                relatorio_dos_dados_dos_sensores();
                break;
            case '3':
                ativar_painel_sensor01(&argc, &argv);
                break;
            default:
                if (opcao_menu != '0')
                {
                    printf("\n\nOpção inválida!\n\nDigire 1 e Pressione <ENTER>");
                    scanf(" %c", &pousa);
                }
        };
    }while(opcao_menu != '0');
    printf("Encerrando o sistema ...\n");
    return 0;
}
