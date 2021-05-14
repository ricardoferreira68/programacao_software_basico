#include <stdio.h>
int main() 
{
    FILE *arq1, *arq2;
    arq1 = fopen("arq_fopen_arquivo.txt", "r");
    if (arq1 == NULL)
        printf("Erro na abertura do arquivo 'fopen_arquivo.txt'\n\n");
    else
    {
        printf("Arquivo 'fopen_arquivo.txt' aberto com sucesso!\n\n");
        fclose(arq1);
    }
    arq2 = fopen("Programacao de Software Basico.png", "rb");
    if (arq2 == NULL)
        printf("Erro na abertura do arquivo 'Programacao de Software Basico.png'\n\n");
    else
    {
        printf("Arquivo 'Programacao de Software Basico.png' aberto com sucesso!\n\n");
        fclose(arq2);
    }
    return 0;
}
