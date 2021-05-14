#include <stdio.h>
#include <time.h>
int main(void) 
{
    time_t agora;
    agora = time(NULL);
    struct tm tp = *localtime(&agora);
    printf("Data: %02d/%02d/%04d\n", tp.tm_mday, tp.tm_mon + 1, tp.tm_year + 1900);
    printf("Hora: %02d:%02d\n", tp.tm_hour, tp.tm_min);
}

