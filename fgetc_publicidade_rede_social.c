# include <stdio.h>
int main(void) 
{
  FILE *arq;
  char c;
  int contador=0;
  arq = fopen("loja_uol_06_04_2021_14_02.txt", "r");
  if (arq==NULL)
    printf("Nao pode abrir o arquivo.\n");
  else
  { 
    printf("Arquivo: loja_uol_06_04_2021_14_02.txt\n");
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