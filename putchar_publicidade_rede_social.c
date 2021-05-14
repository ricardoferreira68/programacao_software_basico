/* Programa para calcuar o preço das inserções publicitárias feitas nas redes sociais da startup
   Programador: Juquinha
   Data: 07/04/2021
   Hora: 08:53
*/
#include <stdio.h>
int main(void)
{ 
    FILE *ptr;
    int contador;
    char c;
    ptr = fopen("loja_uol-06_04_2021-14_02.txt", "r");
    if (ptr == NULL)
        printf("Erro na abertura do arquivo. Verifique se o nome está correto!\n");
    else
    {
        contador = 0;
        printf("------------------------------------------\n");
        printf("arquvio loja_uol-06_04_2021-14_02.txt\n");
        printf("------------------------------------------\n");
        printf("Conteúdo:\n");
        while (c = fgetc(ptr) != EOF)
        {
            contador++;
            putchar(c);
        }
        printf("------------------------------------------\n");
        printf("Qtde de Caracteres: %d\n", contador);
        printf("Preço a pagar = %5.2f\n", contador * 0.002);
        printf("------------------------------------------\n");
        fclose(ptr);
    }
    return 0;
}
