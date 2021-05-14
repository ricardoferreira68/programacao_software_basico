// Ref.: https://www.inf.pucrs.br/~manssour/OpenGL/PrimeiroPrograma.html
#include <stdio.h>
#include <GL/glut.h>      //No Linux: #include <GL/glut.h>
// Função de chamada para fazer o desenho
void Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL
	glFlush();
}
// Inicializa parâmetros de renderização
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualização como azul (Padrão RGB)
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
// Programa Principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
	printf("Fim do programa!\n");
}
