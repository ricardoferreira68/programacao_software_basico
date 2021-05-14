#include <stdio.h>
#include <time.h>
#define LEN 150
int main ()
{
    time_t curtime;
    struct tm *loc_time;

    //Obtém hora corrente do sistema
    curtime = time(NULL);

    // Converte para o tempo local
    loc_time = localtime(&curtime);
    
    // Mostra hora e data no format padrão
    printf("%s", asctime(loc_time));

    return 0;
}