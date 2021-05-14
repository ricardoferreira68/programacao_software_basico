#include <GL/glut.h>  // Mudar para o diretório do Windows.
#include <string.h>
#include <stdio.h>

// Variáveis Globais.
GLfloat xf, yf, r, g, b, win;
GLint view_w, view_h, primitiva;
char texto[30];

// Desenha um texto na janela GLUT
void DesenhaTexto(char *string)
{
    glPushMatrix();
    // Posição no universo onde o texto será colocado
    glRasterPos2f(-win,win-(win*0.08));
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
    glPopMatrix();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha um retângulo preenchido com a cor corrente
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(xf, 0.0f);
        glVertex2f(xf, yf);
        glVertex2f(0.0f, yf);
    glEnd();
    // Exibe a posição do mouse na janela
    glColor3f(0.0f,0.5f,0.5f);
    DesenhaTexto(texto);
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    xf=50.0f;
    yf=50.0f;
    win=250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;
    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}
// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 'R':
        case 'r':// muda a cor corrente para vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
        case 'G':
        case 'g':// muda a cor corrente para verde
        glColor3f(0.0f, 1.0f, 0.0f);
        break;
        case 'B':
        case 'b':// muda a cor corrente para azul
        glColor3f(0.0f, 0.0f, 1.0f);
        break;
    } 
    glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) 
        {
            // Troca o tamanho do retângulo, que vai do centro da
            // janela até a posição onde o usuário clicou com o mouse
            xf = ( (2 * win * x) / view_w) - win;
            yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
        }
    glutPostRedisplay();
}

// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT com um botão pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
    sprintf(texto, "Botao pressionado (%d,%d)", x, y);
    glutPostRedisplay();
}

// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT
void MoveMouse(int x, int y)
{
    sprintf(texto, "(%d,%d)", x, y);
    glutPostRedisplay();
}

// Função Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(350,300);
    glutInitWindowPosition(700,10);
    glutCreateWindow("Exemplo de Interacao");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(GerenciaTeclado);
    glutMouseFunc(GerenciaMouse);
    glutMotionFunc(MoveMouseBotaoPressionado);
    glutPassiveMotionFunc(MoveMouse);
    Inicializa();
    glutMainLoop();
}
