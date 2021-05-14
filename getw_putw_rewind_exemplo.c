#include<stdio.h>
int main() {
    FILE *fp;
    int n;
    fp=fopen("arquivo_com_inteiros.dat", "wb+");
    printf("Entre com valores inteiros. Zero para sair\n");
    scanf("%d",&n);
    while(n!=0) {
        putw(n,fp);
        scanf("%d",&n);
    }
    rewind(fp);
    printf("Lendo dados do arquivo\n");
    while((n=getw(fp))!=EOF) {
        printf("%d\n",n);
    }
    fclose(fp);
}