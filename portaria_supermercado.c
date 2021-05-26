/*
    Programa para lê a o sinal enviado pelo leitor de temperatura via porta sirial.

    Motivação: Um supermercado precisa controlar o ingresso de clientes, pois não 
        pode ser autorizada a entrada de pessoas com temperatura elevada (indicativo 
        de febre), por determinação da Secretaria Municipal de Vigilância Sanitária, 
        visando controlar a propagação da doença respiratória que assola a cidade, 
        sabendo-se que a febre é um dos sintomas dessa doença. 
        A Vigilância Sanitária também determinou o controle de lotação máxima, 
        que não pode ultrapassar 50% da capacidade da loja. O supermercado adquiriu 
        leitores de temperatura manuais, com programação para sinalizar a uma 
        determinada temperatura. Entretanto, esses aparelhos e a operação se 
        revelaram inadequados, devido à lentidão e formação de filas no ingresso 
        à loja, provocando aglomeração. Contudo, os leitores possuem uma porta 
        serial RS232 que permite tanto o acionamento do leitor quanto a leitura 
        da temperatura por sistemas automatizados. Por isso, o gerente do supermercado 
        solicitou ao Setor de Engenharia que usasse os leitores para automatizar o 
        ingresso de clientes. Ele pediu um sistema que apenas autorizasse, ou não, 
        a entrada de um cliente e fizesse a contagem de ingressantes. 
        O engenheiro consultou o manual do aparelho e percebeu que a sua operação 
        é bem simples. Ele (o aparelho) aciona o leitor ao receber um sinal no pino 2, 
        da porta RS232, e envia um sinal, via pino 3, quando a temperatura configurada 
        é atingida ou ultrapassada.
        
        Três problemas a resolver:
        1. Contar a quantidade de ingressantes;
        2. Liberar entrada de clientes; e
        3. Proibir a entrada de clientes.

        // Rotina para Proibir a entrada de clientes.
        while (1)
        {
            char dado;  // 0b 01000100   0b11111111 0b01000000
            LePorta(dado)   // Dados é um byte. 0b 00 0 00000

            filtrar = dado & 0b01000000

            dado     = 'D';
                       01000100 & 
                       01000000
                       --------
            filtrar =  01000000  = '@'  40    
 
            dado     = '*';
                       00101010 &    //2A
                       01000000
                       --------
            filtrar =  00000000 = '0'  
 
            e                       -->  &
            ou                      -->  |
            não                     -->  ~    
            Deslocamento a direita  -->  >>
            Deslocamento a esquerda -->  << 
            ou exclusivo            -->  ^ 

            Se dado = '@' Então   // pino 3 é um bit do byte lido.
                Escreva("Entrada Proibida!")
            Fim Se.
        }
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define LOTACAO_MAXIMA 5

void le_porta(char *);

int main(void)
{
    int qtde = 0;
    char dado;
    while(1)
    {
        system("clear"); 
        printf("================================\n");
        printf("    SUPERMERCADO DO BAIRRO\n");
        printf("--------------------------------\n\n");
        printf("   Controle de Portaria\n\n");
        printf("     Lotação Máxima: %d\n", LOTACAO_MAXIMA);
        printf("   Clientes na loja: %d\n", qtde);
        le_porta(&dado);
        if (dado == '@')
            printf("Entrada proíbida! Febre detectada.\n");
        else
            if (qtde == LOTACAO_MAXIMA)
                printf("Entrada proíbida! Supermercado lotado.\n");
            else{
                printf("Entrada liberada!\n");
                qtde++;
            }
    }
}

void le_porta(char *dado_lido)
{
    int porta;
    ssize_t iQtdeLida;
    porta = open("/dev/pts/4", O_RDONLY);
    iQtdeLida = read(porta, dado_lido, sizeof(char));
    close(porta);
};
