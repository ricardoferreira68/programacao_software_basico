#include <stdio.h>
void grava_dados(FILE *arq, char *dados)
{
    fputs(dados, arq);
}
int main() 
{
    FILE *arq = fopen("arq_fputs_arquivo_funcao_exemplo.txt", "w");
    grava_dados(arq, "============================\n");
    grava_dados(arq, "*   LINGUAGEM C -  fputs   *\n");
    grava_dados(arq, "============================\n");
    grava_dados(arq, "\n");
    grava_dados(arq, "Este arquivo foi gerado\n");
    grava_dados(arq, "por um programa com a\n");
    grava_dados(arq, "função fputs da Linguagem C.\n");
    grava_dados(arq, "============================\n");
    printf("\nArquivo gravado no disco!\n");
    fclose(arq);
    return 0;
}
