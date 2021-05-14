#include <stdio.h>
int main() 
{
    char string[20];
    printf("Nome: ");
    fgets(string, 20, stdin);
    printf("Seu nome eh %s\n", string);
    return 0;
}
