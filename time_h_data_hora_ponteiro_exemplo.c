#include <stdio.h>
#include <time.h>
int main(){
    time_t data_hora; 
    time(&data_hora); //Lê o timestamp (marca temporal)
    struct tm *tempo = localtime(&data_hora);
    int dia = tempo->tm_mday;
    int mes = tempo->tm_mon + 1;
    int ano = tempo->tm_year + 1900;
    int hora = tempo->tm_hour;
    int min = tempo->tm_min;
    int seg = tempo->tm_sec;
    printf("\n%.2d-%.2d-%.4d - %d:%.2d:%.2d\n", dia, mes, ano, hora, min, seg);
    return 0;
}
