#include <stdio.h>
int main(void)
{
    int A, B, C;
    A = 60;
    B = 3;
    C = ++A     +    B;
    printf("A = %d    B = %d   C = %d\n", A, B, C);

    C = A++ + B;
    printf("A = %d    B = %d   C = %d\n", A, B, C);

    return(0);
}