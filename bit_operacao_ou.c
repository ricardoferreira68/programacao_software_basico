#include <stdio.h>
int main(void)
{
    int A = 4, B = 1, C, D;
    C = A | B;
    D = A || B;
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    printf("\n");
    A = 5;
    C = A | B;
    D = A || B;
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    return 0;
}
