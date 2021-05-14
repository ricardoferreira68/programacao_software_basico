#include <stdio.h>
int main(void)
{
    int A;
    A = 50;                 //Atribui o valor 50 à variável A.
    printf("A = %d\n", A);
    A +=  100;              //Atribui o valor 150 à variável A.
    printf("A = %d\n", A);
    A -=  60;              //Atribui o valor 90 à variável A.
    printf("A = %d\n", A);
    A /=  3;              //Atribui o valor 30 à variável A.
    printf("A = %d\n", A);
    A *=  4;              //Atribui o valor 120 à variável A.
    printf("A = %d\n", A);
    A %=  9;              //Atribui o valor 3 à variável A.
    printf("A = %d\n", A);
    return(0);
}
