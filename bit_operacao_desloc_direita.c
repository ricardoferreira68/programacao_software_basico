#include <stdio.h>
int main(void)
{
    int A = 5, B, C, D, E;
    B = 5 >> 1;
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
