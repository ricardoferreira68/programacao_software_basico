# include <stdio.h>
int main(int argc, char *argv[]) 
{
    FILE *arq;
    char c, cliente[30];
    int dia, mes, ano, hora, min;
    int contador=0;
    arq = fopen(argv[1], "r");
    if (arq==NULL)
        printf("Nao pode abrir o arquivo.\n");
    else
    { 
        printf("Arquivo: %s\n", argv[1]);
        printf("Conteúdo:\n");
        printf("------------------------------------------------------\n");
        c = fgetc(arq);
        while (c != EOF)
        {
            printf ("%c", c);
            contador++;
            c = fgetc(arq);
        }
        printf("------------------------------------------------------\n");
        scanf(argv[1],"", &cliente, &dia, &mes, &ano, &hora, &min);
        printf("Cliente: loja_uol.txt\n");
        printf("Data: 06_04_2021\n");
        printf("Hora: 14_02\n");
        printf("Qtde de caracteres: %d\n", contador);
        printf("Preço p/ caractere: R$0,002\n");
        printf("Valor a cobrar pela inserção: R$%5.2f\n", (float)contador*0.002);
        printf("------------------------------------------------------\n");
        fclose(arq);
    }
    return 0;
}
