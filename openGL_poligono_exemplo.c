/* programa teste-make.c */
/* Desenha um quadrado preto em uma janela com fundo branco */

#include <GL/glut.h>
#include <stdlib.h>

void display(void);

// Função Principal.
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (300, 300); 
  glutInitWindowPosition (0, 0); 
  glutCreateWindow (argv[0]);
  glClearColor(1.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void display(void)
{
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0.25,0.25);
  glVertex2f(0.75,0.25);
  glVertex2f(0.75,0.75);
  glVertex2f(0.25,0.75);
  glEnd();
  glFlush();
}