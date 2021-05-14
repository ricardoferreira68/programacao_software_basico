#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define ttyS 0x3f8
// #define ttyS 0x2f8


int main(int argc, char *argv[])
{
    int escolha=0;
    char byte;
    do{
        printf ("1- Enviar Dados para porta \n");
        printf ("2- Ler dados da porta \n");
        printf ("3- Sair\n" );
        printf ("Escolha: \n");
        scanf ("%d",&escolha);
        scanf("%*[^\n]");/*limpa canal de entrada*/
        scanf("%*c");
        switch (escolha)
        {
            case 1:
                if (ioperm(ttyS, 3, 1)) 
                {
                    perror ("ioperm");
                    exit(1);
                }
                printf ("Valor: ");
                scanf ("%c",&byte);
                scanf("%*[^\n]");/*limpa canal de entrada*/
                scanf("%*c");
                printf("Valor digitado: %d\n",byte);
                outb( byte, ttyS );
                usleep(200000);
                printf ("valor lido da serial:%d \n",inb (ttyS+1));
                usleep(200000);
                break;
            case 2: 
                if (ioperm(ttyS, 2, 1)) 
                {
                    perror ("ioperm");
                    exit(1);
                }
                printf ("valor:%d \n",inb (ttyS+1));
                break;
            case 3:
                ioperm(ttyS, 3, 0);
                printf ("Portas Fechadas, saindo...\n");
        }
    }while (escolha!=3);
    // system("PAUSE");
    return 0;
}
