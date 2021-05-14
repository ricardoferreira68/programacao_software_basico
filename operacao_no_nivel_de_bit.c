#include <stdio.h>
char ler_porta_serial(void);

int main(void)
{
    char SerialBuffer;
    short bit_recebido;

    while(1)
    {
        SerialBuffer = ler_porta_serial();
        printf("recebido: %c\n", SerialBuffer);
        // Será recebido um byte na porta serial.
        // Esse byte será sempre o mesmo: 01000000
        bit_recebido = 0100;
        printf("Bit: %d\n", bit_recebido);
    }
}

char ler_porta_serial(void)
{
    char recebido;
    scanf(" %c", &recebido);
    return recebido;
}
