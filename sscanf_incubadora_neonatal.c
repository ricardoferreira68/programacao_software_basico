#include <stdio.h>
#include <string.h>
struct incub_dados {
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
    float temp;
};

// Início do Programa.
int main(void) 
{
    struct incub_dados temperatura;
    char linha_de_dados[17];
    FILE* arq = fopen("arq_incubadora_neonatal_temperatura.txt", "rt+");

    printf("RELATÓRIO DE TEMPERATURA DA INCUBADORA\n");
    printf("--------------------------------------\n");
    printf("DATA       HORA  TEMPERATURA\n");
    printf("---------- ----- ---------------------\n");
    do {
        fgets(linha_de_dados, 17, arq);
        sscanf(linha_de_dados, "%4d%2d%2d%2d%2d%f", &temperatura.ano, &temperatura.mes, &temperatura.dia, 
        &temperatura.hora, &temperatura.min, &temperatura.temp);
        printf("%02d/", temperatura.dia);
        printf("%02d/", temperatura.mes);
        printf("%04d ", temperatura.ano);
        printf("%02d:", temperatura.hora);
        printf("%02d ", temperatura.min);
        printf("%04.1f\n", temperatura.temp);
   } while(!feof(arq));
    fclose(arq);
    return 0;
}