// Ref.: https://docplayer.com.br/94248-Introducao-a-opengl-profa-alessandra-martins-coelho.html
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Desenhando uma linha");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void)
{
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 0.0, 1.0);
  glBegin(GL_TRIANGLES);
    glVertex2f(10,90);
    glVertex2f(10,10);
    glVertex2f(35,75);
    glVertex2f(30,20);
    glVertex2f(90,90);
    glVertex2f(80,40);           
  glEnd();
  glFlush();
}
