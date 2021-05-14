#include <GL/glut.h>
// Cabeçalho das Funções (Prótotipo das funções / Assinatura das Funções).
void Desenha(void);
void Inicializa(void);
void AlteraTamanhoJanela(GLsizei, GLsizei);

// Função Principal.
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400,350);
  glutInitWindowPosition(300,300);
  glutCreateWindow("Quadrado");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  Inicializa();
  glutMainLoop();
}

// Função de chamada para fazer o desenho
void Desenha(void) 
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
    glVertex2i(100,150);
    glVertex2i(100,100);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(150,100);
    glVertex2i(150,150);
  glEnd();
  glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void) {
  // Define a cor de fundo da janela
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
  if(h == 0) h = 1; // Evita a divisão por zero.
  glViewport(0, 0, w, h); // Dimensões da Viewport.
  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
  else
    gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}
