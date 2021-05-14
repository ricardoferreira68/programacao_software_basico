/* Programa para calcuar o preço das inserções publicitárias feitas nas redes sociais da startup
   Programador: Juquinha
   Data: 07/04/2021
   Hora: 08:53
*/
#include <stdio.h>
#include <iostream>
using namespace std;
// A função main receber como parâmetro o nome do arquivo txt.
// Use assim: nome_do_executavel nome_do_arquivo_txt
int main(int argc, char *argv[])
{ 
    FILE *ptr;
    int contador;
    char c;
    ptr = fopen(argv[1], "r");
    if (ptr == NULL)
        printf("Erro na abertura do arquivo. Verifique se o nome está correto!\n");
    else
    {
        contador = 0;
        printf("------------------------------------------\n");
        printf("arquvio %s\n", argv[1]);
        printf("------------------------------------------\n");
        printf("Conteúdo:\n");
        c = fgetc(ptr);
        while (c != EOF)
        {
            contador++;
            cout << c;
            c = fgetc(ptr);
        }
        printf("------------------------------------------\n");
        printf("Qtde de Caracteres: %d\n", contador);
        printf("Preço a pagar = %5.2f\n", contador * 0.002);
        printf("------------------------------------------\n");
        fclose(ptr);
    }
    return 0;
}
