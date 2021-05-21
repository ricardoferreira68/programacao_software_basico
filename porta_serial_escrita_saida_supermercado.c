/*
    Programa de controle de entrada de um supermercado.
    A finalidade desse programa é exemplificar a escrita na porta serial e o tratamento dos dados.

    * Configurações Porta Serial
    emulador de duas portas seriais interligadas no Linux via socat:
    "sudo apt-get install socat" - Instalar o socat.
    "socat -d -d pty,raw,echo=0 pty,raw,echo=0" - Executar o emulador.
    "echo "@" > /dev/pts/2" - Escreve na porta 2.
    "cat < /dev/pts/3" - escuta a porta 3.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define LOTACAO 5
#define PORTA_LEITURA "/dev/pts/2"

void escreva_na_porta(char);

int main(int argc, char *argv[])
{
    char dado;  // Armazenar o caractere lido;
    do{
        system("clear");
        printf("========================================\n");
        printf("*****      SUPERMERCADO O BOM      *****\n");
        printf("----------------------------------------\n\n");
        printf("          Controle de Portaria\n\n");
        printf("Digite S para saída de cliente: ");
        scanf(" %c", &dado);
        if (dado == 'S')
            escreva_na_porta('S');
    }while (1);
    return 0;
}

void escreva_na_porta(char dado)
{
    int porta = open(PORTA_LEITURA, O_WRONLY);  // Abre a porta serial.
    write(porta, &dado, sizeof(dado));  // Escreve o dado na porta.
    close(porta);  // Fecha a parta serial.
}
