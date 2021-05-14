#include <stdio.h>
int main() 
{
    FILE *arq = fopen("arq_stream_em_disco.txt", "w");
    // Sintaxe: fputs(string, stream)
    fputs("============================\n", arq);
    fputs("*   LINGUAGEM C -  fputs   *\n", arq);
    fputs("============================\n", arq);
    fputs("\n", arq);
    fputs("Este arquivo foi gerado\n", arq);
    fputs("por um programa com a\n", arq);
    fputs("função fputs da Linguagem C.\n", arq);
    fputs("============================\n", arq);
    fputs("\nArquivo gravado no disco!\n", stdout);
    printf("\nArquivo gravado no disco!\n");
    fclose(arq);
    return 0;
}
