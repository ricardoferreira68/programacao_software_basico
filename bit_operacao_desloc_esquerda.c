#include <stdio.h>
int main(void)
{
    short A = 0b0001000000000000, B, C, D, E;
    B = A << 1;
    C = A << 2;
    D = A << 3;
    E = A << 4;
    printf("short = %d\n\n", sizeof(short));
    printf("A = %d\n\n", A);   //  0001000000000000
    printf("B = %d\n\n", B);   //  0010000000000000
    printf("C = %d\n\n", C);   //  0100000000000000
    printf("D = %d\n\n", D);   //  1000000000000000
    printf("E = %d\n\n", E);   //1 0000000000000000
    return 0;
}
