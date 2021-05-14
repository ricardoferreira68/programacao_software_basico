#include <stdio.h>
int main() 
{
    FILE* torno = fopen("arq_dados_do_torno.txt", "w+");
    float Voltage;
    float Speed;
    float Pressure;

    printf("Digite a voltagem: ");
    scanf("%f", &Voltage);
    while (Voltage != 0)
    {
        printf("Digite a velocidade de rotação: ");
        scanf("%f", &Speed);
        printf("Digite a pressão da lâmina: ");
        scanf("%f", &Pressure);
        fprintf(torno, "%5.1f%4.1f%6.4f\n", Voltage, Speed, Pressure);
        printf("Digite a voltagem: ");
        scanf("%f", &Voltage);
    }
    fclose(torno);
    return 0;
}
