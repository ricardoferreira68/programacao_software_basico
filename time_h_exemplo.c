#include <stdio.h>
#include <time.h>
#define LEN 150
int main ()
{
    char buf[LEN];
    time_t curtime;
    struct tm *loc_time;
    //Obtém hora corrente do sistema
    curtime = time(NULL);
    // Converte para o tempo local
    loc_time = localtime(&curtime);// Mostra hora e data no format padrão
    printf("%s", asctime(loc_time));
    strftime(buf, LEN, "Hoje eh %A, %b %d.\n", loc_time);
    fputs(buf, stdout);
    strftime(buf, LEN, "A hora eh %I:%M %p.\n", loc_time);
    fputs(buf, stdout);
    return 0;
}