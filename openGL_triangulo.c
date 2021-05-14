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
  glClearColor(0.0, 0.0, 0.0, 0.0);
  //glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex2f(-1, 0);
        glColor3f(0,1,0);
        glVertex2f(1, 0);
        glColor3f(0,0,1);
        glVertex2f(0, 1);
    glEnd();
    glFlush();
}
