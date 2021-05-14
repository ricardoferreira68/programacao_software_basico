// Ref.: https://docplayer.com.br/94248-Introducao-a-opengl-profa-alessandra-martins-coelho.html
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Desenhando uma linha");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 500, 0, 500, -1 ,1);
}

void display(void)
{
    const float distancia = 15.0f;
    float y=256, pos = -1 + distancia;
    int i;
    for (i = 1; i <= 25; i ++)
    {
        glPointSize(i);
        glBegin(GL_POINTS);
          glVertex3f(pos, y, 0);
        glEnd();
        pos += distancia;
    }
    glFlush();
}
