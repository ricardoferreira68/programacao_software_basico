#include <stdio.h>
// Início do Programa.
int main(void) 
{
    FILE* arq = fopen("Programacao de Software Basico.png", "rb+");
    fclose(arq);
    return 0;
}