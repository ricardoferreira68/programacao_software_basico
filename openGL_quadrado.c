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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10,90,0);
        glVertex3f(10,10,0);
        glVertex3f(40,20,0);
        glVertex3f(35,75,0);
        glColor3f(0.0,0.7,1.0);
        glVertex3f(15,80,0);
        glVertex3f(20,10,0);
        glVertex3f(90,20,0);
        glVertex3f(90,75,0);           
    glEnd();
    glFlush();
}
