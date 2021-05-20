#include <stdio.h>
int main(void)
{
    char A = 32, B, C, D, E;
    B = A >> 1;
    C = A >> 2;
    D = A >> 3;
    E = A >> 4;
    printf("char = %d\n\n", sizeof(char));
    printf("A = %d\n\n", A);
    printf("B = %d\n\n", B);
    printf("C = %d\n\n", C);
    printf("D = %d\n\n", D);
    printf("E = %d\n\n", E);
    return 0;
}
