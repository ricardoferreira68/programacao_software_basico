#include <stdio.h>
int main(void)
{
    int A = 4, B = 5, C, D;
    C = ~A;
    D = A && B;
    printf("C = %d\n", C);
    printf("D = %d\n", D);
    return 0;
}
