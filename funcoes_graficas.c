#include <stdio.h>  // Funções e diretivas de I/O padrão: fopen, FILE ...
#include <GL/glut.h>  // Funções gráficas e diretivas: glutInit().
#include <time.h> // Para registrar a data e a hora da leitura dos sensores.
#include <string.h>  // Usar a função strcpy para copiar string.
#include "fabrica_varre_bem.h"  // Estruturas e protótios de funções usadas por todos os módulos.


// Usada para desenha a borda cinza do gráfico.
void denha_borda_cinza(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa a janela de exibição com a cor de fundo especificada.
    glLineWidth(4);  //Define a espessura da linha em 4 pixels.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Define as cores de trás e e da linha do polígono.
    glBegin(GL_QUADS);  // Inicializa o denho de um quadro.
        glColor3f (0.502,0.502,0.502);  // Define a cor da linha do quadro (cinza).
        glVertex2f(10, 10);  // Começa no canto inferior esquerdo.
        glVertex2f(660, 10);  // Desenha a linha até o conto inferior direito.
        glVertex2f(660, 350);  // Linha vertical do lado direito até a altura 355.
        glVertex2f(10, 350);  // Linha horizontal até x=5 (fecha automaticamente o quadro).
    glEnd();  // Finaliza o desenho do quadro.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usa para plotar as diversas linhas no gráfico.
void desenha_linha(GLfloat x_a, GLfloat y_a, GLfloat x_b, GLfloat y_b, GLfloat r, GLfloat g, GLfloat b, GLfloat largura)
{
    glLineWidth(largura);  //Define a espessura da linha em 4 pixels.
    glBegin(GL_LINES);  // Inicializa o denho da linha.
        glColor3f (r, g, b);  // Define a cor da linha.
        glVertex2f(x_a, y_a);  // Coordenada inicial.
        glVertex2f(x_b, y_b);  // Coordenada final.
    glEnd();  // Finaliza o desenho da linha.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usada para plotar os diversos textos no gráfico.
void desenha_texto(char *string, GLfloat xf, GLfloat yf, GLfloat r, GLfloat g, GLfloat b, int tamanho)
{

    glColor3f(r, g, b);  // Define a cor do texto.
    glPushMatrix();  // Empinha a imagem na matriz de desenho da imagem.
    glRasterPos2f(xf, yf);  // Posição no universo onde o texto será colocado.
    // Plota caracter a caracter
    if (tamanho == 10)
        while(*string)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);  // Renderiza o caractere.
    else
        if (tamanho == 12)
            while(*string)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);  // Renderiza o caractere.
        else
            while(*string)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);  // Renderiza o caractere.
    glPopMatrix();  // Desempilha e torna a matriz disponível para exibição.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usada para plotar os pontos das linhas (destaque para o ponto do sensor01).
void desenha_ponto(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, int tamanho)
{
    glColor3f(r, g, b);  // Define a cor do texto.
    glPointSize(tamanho); // Define o tamanho da marca do sensor01.
    glBegin(GL_POINTS);  // Inicializa o desenho da marca.
        glVertex2f(x, y);  // Desenha a marca (ponto).
    glEnd();  // Finaliza o desenho do ponto.
    glFlush();  // Executa as funções GL.
}

// Função callback chamada pela GLUT a cada intervalo de tempo.
void temporizacao(int value)
{
    // Redesenha o quadrado com as novas coordenadas
    glutPostRedisplay();
    glutTimerFunc(TEMPORIZADOR,temporizacao, 1);
}
