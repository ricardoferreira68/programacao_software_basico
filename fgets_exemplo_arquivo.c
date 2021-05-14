# include <stdio.h>
int main(void) {
  FILE *fp;
  char data[50];
  printf("Abrindo o arquivo teste.txt em modo leitura\n\n" );
  fp = fopen("arq_teste.txt", "r" );
  if (fp == NULL) {
    printf("Nao pode abrir arq_teste.txt\n");
    return 1;
  }
  printf("Lendo o arquivo arq_teste.txt\n\n");
  while(fgets(data, 50, fp) != NULL)
    printf( "Texto do arquivo: %s" , data ) ;
  printf("\nfechando o arquivo arq_teste.txt\n\n");
  fclose(fp) ;
  return 0;
}