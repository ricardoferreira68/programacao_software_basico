#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define LOTACAO 5

char le_porta(void);

int main(int argc, char *argv[])
{
    char dado;  // Armazenar o caractere lido;
    char mensagem[30];
    int quantidade = 0;  // Qtde de cliente dentro da loja.
    strcpy(mensagem, "Loja aberta!");
    do{
        system("clear");
        printf("========================================\n");
        printf("*****      SUPERMERCADO O BOM      *****\n");
        printf("----------------------------------------\n\n");
        printf("          Controle de Portaria\n\n");
        printf("Lotação Máxima Permitica: %d\n", LOTACAO);
        printf("Clientes na loja: %d\n\n", quantidade);
        printf("Mensagem: %s\n", mensagem);
        printf("----------------------------------------\n");
        if (quantidade>LOTACAO)
            strcpy(mensagem, "Entrada Proíbida!");
        else
        { 
            dado = le_porta();
            if(dado == '@')
                strcpy(mensagem, "Entrada Proíbida!");
            else
                if(dado != 0b00001010)  // Despreza o LF.
                    sprintf(mensagem, "Entrada liberada! Cliente %3d", ++quantidade);    
        }
    }while (1);
    return 0;
}

char le_porta(void)
{
    int porta;  // Usado para controle de porta aberta com open().
    char dado;  // Recebe o caractere lido da porta.
    char LF;  // Usado para ler e despresar o line feed da leitura da porta.
    porta = open("/dev/pts/3", 0);  // Abre a porta serial.
    // Lê um byte da porta serial.
    read(porta, &dado, sizeof(dado));
    // Segunda leitura para eliminar o LF do buffer.
    read(porta, &LF, sizeof(dado));
    close(porta);  // Fecha a parta serial.
    return dado;  // Retorna o caracter lido.
}
