/* Servidor simples TCP
 programa exemplo retirado do Plano de Aula da Disciplina Programação de Software Básico da Faculdade Estácio de Belém. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2) 
    {
        fprintf(stderr,"ERRO, nenhuma porta provida\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("ERRO abrindo socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("ERRO no binding");
        exit(1);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
    {
        printf("ERRO no aceite de conexao");
        exit(1);
    }
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) 
    {
        printf("ERRO lendo do socket");
        exit(1);
    }
    printf("Aqui sua mensagem: %s\n",buffer);
    n = write(newsockfd,"Eu recebi sua mensagem",22);
    if (n < 0) 
    {
        printf("ERRO escrevendo no socket");
        exit(1);
    }
    return 0;
}