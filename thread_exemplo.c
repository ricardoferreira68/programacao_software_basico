#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *escreve(void *numero)
{
    int *n = (int *)numero;
    printf("Programacao de Software Basico \n");
    pthread_exit(NULL);
}
void main()
{
    pthread_t threads[3];
    int s, i;
    for (i = 0; i < 3; i++)
    {
        printf("Criando o thread n. %d\n", i);
        s = pthread_create(&threads[i], NULL, escreve, (void *)&i);
        if (s)
        {
            perror("Erro ao criar o thread");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
