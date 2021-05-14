//Fonte: http://wiki.icmc.usp.br/images/5/5b/Lab1_OpenGL.pdf
// Draw a colored square against a black background
#include <stdio.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>
void draw() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(0, 4, 0, 4, -1, 1);
    glBegin(GL_POLYGON);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2i(1, 1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2i(3, 1);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2i(3, 3);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2i(1, 3);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("whitesquare");
    glutDisplayFunc(draw);
    glutMainLoop();
}