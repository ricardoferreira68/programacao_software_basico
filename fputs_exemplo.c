#include <stdio.h>
int main() 
{
    char string[50] = "\nFACULDADE ESTÁCIO DE BELÉM\n\n";
    fputs(string, stdout);  // Escreve no 'Stream' stdout.
    return 0;
}
