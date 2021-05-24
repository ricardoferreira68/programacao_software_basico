/*
    Programa de controle de entrada de um supermercado.
    A finalidade desse programa é exemplificar a leitura na porta serial e o tratamento dos dados lidos.

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
#define PORTA_LEITURA "/dev/pts/4"

char le_porta(void);

int main(int argc, char *argv[])
{
    char dado;  // Armazenar o caractere lido;
    char filtro; // Usada na Filtragem do bit da temperatura.
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
        dado = le_porta();
        if(dado & 0b01010011 == 0b01010011)
        { 
            if (quantidade>0)
                sprintf(mensagem, "Cliente saiu!", --quantidade);
        }
        else
            if (quantidade>=LOTACAO)
                strcpy(mensagem, "Entrada Proíbida! LOTADO!");
            else
                if(dado == 0b01000000)
                    strcpy(mensagem, "Entrada Proíbida! FEBRE!");
                else
                    sprintf(mensagem, "Entrada liberada! Cliente %3d", ++quantidade);
    }while (1);
    return 0;
}

char le_porta(void)
{
    int porta;  // Usado para controle de porta aberta com open().
    char dado;  // Recebe o caractere lido da porta.
    char LF;  // Usado para ler e despresar o line feed da leitura da porta.
    porta = open(PORTA_LEITURA, O_RDONLY);  // Abre a porta serial.
    // Lê um byte da porta serial.
    read(porta, &dado, sizeof(dado));
    close(porta);  // Fecha a parta serial.
    return dado;  // Retorna o caracter lido.
}
