# include <stdio.h>
int main(void) {
  FILE *fp ;
  char c ;
  printf("Abrindo o arquivo test.txt em modo leitura.\n");
  fp = fopen("test.txt", "r");
  if (fp==NULL) {
    printf("Nao pode abrir o arquivo.\n");
    return 1;
  }
  printf("lendo o arquivo test.txt\n");
  while(1) {
    c = fgetc(fp);
    if (c == EOF)
      break ;
    printf ("%c", c);
  }
  printf("\n\nfechando o arquivo test.txt\n");
  fclose(fp);
  return 0;
}
