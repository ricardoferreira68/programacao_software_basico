#include <stdio.h>
int main(void)
{
    int A = 4, B = 5, C;
    C = A ^ B;
    printf("C = %d\n\n", C);
    A = 5, B = 1;
    C = A ^ B;
    printf("C = %d\n\n", C);
    A = 4, B = 1;
    C = A ^ B;
    printf("C = %d\n\n", C);
    return 0;
}
