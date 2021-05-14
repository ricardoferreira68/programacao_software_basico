/* F�brica de Vassouras Varre Bem!
 Programa para exibir o gr�fico dos dados do sensor 01.
 Feito por Estagi�rio (O bom!)
 Data: 14/04/2021, �s 21h30.
layout do arquivo
=====================================================================
|Descri��o | Campo | Tipo | Tamanho |
+-----------------------------+-------+-----------+-----------------+
| C�digo da guilhotina | cod | caractere | 2 |
| Sensor de comprimento em cm | s01 | real | 00.000 a 99.999 |
| Sensor de press�o em psi | s02 | inteiro | 0 a 999 |
| Sensor de detec��o da fibra | s03 | booleano | 1 |
=====================================================================
Exemplo de dados: 
cod | s01 | s02 | s03
01 20.000 300 1 
01 18.090 300 1 
01 19.095 300 1 
01 19.805 300 1 
01 20.175 300 1 
01 18.001 300 1
01 21.900 300 1
01 19.510 300 1
Para compilar: gcc -lGL -lGLU -lglut -lm arquivo_fonte.c -o arquivo_objeto 
*/
#include <stdio.h> // Fun��es e diretivas de I/O padr�o: fopen, FILE ...
#include <GL/glut.h> // Fun��es gr�ficas e diretivas: glutInit().
// Constante para definir a quantidade de cortes a serem exibidos no gr�fico.
// Um 'corte' significa um registro de dados lidos dos sensores e projetado nogr�fico. 
#define CORTES 6 // O 'corte 0' � usado para marcar o ponto inicial daslinhas. 
#define TEMPORIZADOR 1000 // 1 segundo (1.000 milissegundos).
// Estrutura usada na grava��o dos dados no arquivo. 
typedef struct 
{
 char cod[2]; // C�digo da guilhotina.
 float s01; // Medida do sensor 01 (comprimento) em cent�metro.
 int s02; // Medida do sensor 02 (press�o) em psi.
 int s03; // Medida do sensor 03 (presen�a da fibra) 1-presente/2-ausente.
} dados_guilhotina; // Defini��o do nome do tipo.
// Estrutura 'dados' para manipular os dados lidos do arquivo.
dados_guilhotina dados;
// Ponteiro para manipular o arquivo de dados.
FILE *arq;
// Identificador do �ltimo registro de dados plotado.
int contador_de_registro = 0;
// Define os valores iniciais de posicionamento dos elementos do gr�fico.
GLfloat x_ini = 80; // Posi��o do primeiro 'Corte' plotado no eixo 'x'.
GLfloat y_ini = 300; // Posi��o da primeira linha (superior) a ser plotada noeixo 'y'.
// Vetores com as coordenadas de platagem das linhas do gr�fico.
GLfloat Vx[CORTES]; // As ordenadas x de cada "Corte" a ser protado nogr�fico.
GLfloat My[CORTES][4]; // As ordenadas y de cada "Corte" e cada uma das 4linhas a serem plotados no gr�fico.
// Vetor com os valores (r�tulos) do sensor 01 para ser plotado sobre os pontosno gr�fico.
float rotulo_s01[CORTES];
// Controle dos cortes plotados em tempo real.
short corte = 0;
// Prot�tipo das fun��es criadas no programa.
void inicializa(void);
void desenha_grafico(void);
void denha_borda_cinza(void);
void desenha_linha(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat,
GLfloat, GLfloat);
void desenha_texto(char *, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void desenha_ponto(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, int);
void temporizacao(int);
//Fun��o Principal.
int main(int argc, char** argv)
{
 glutInit(&argc, argv); // Inicializar a biblioteca de fun��es gr�ficas.
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o m�do de exibi��odas imagens geradas.
 glutInitWindowSize(670,360); // Define o tamanho da janela gr�ficainicial.
 glutInitWindowPosition(700,10); // Define a posi��o na tela de exibi��o dajanela gr�fica.
 glutCreateWindow("Monitor Sensor 01 da Guilhotina"); // Cria a janela comas configura��es iniciais.
 inicializa(); // Define os valores iniciais.
 glutDisplayFunc(desenha_grafico); // Desenha os gr�ficos na janela criada.
 glutTimerFunc(TEMPORIZADOR, temporizacao, 1); // For�a a exibi��o dogr�fico de 5 em 5 segundos.
 glutMainLoop(); // Mant�m a janela em exibi��o (execu��o).
 return 0;
}
// Usada para fazer as configura��o dos valores iniciais de controle dogr�fico.
void inicializa(void)
{
 // Inicia o controle de contagemm de registros lidos do arquivo.
 contador_de_registro = 0; // Nenhum registro lido.
 
 // Define as posi��es das ordenadas 'x' dos cortes a serem plotados nogr�fico.
 for (int i=0; i<CORTES; i++) 
 {
 if (i==0)
 Vx[0] = x_ini; //Valor de in�cio de plotagem do gr�fico.
 else
 if (i==1)
 Vx[1] = x_ini; //Valor inicial da ordenada 'x' do primeiro
corte a ser plotado.
 else
 Vx[i] = Vx[i-1]+120; //Valor da ordenada 'x' do pr�ximo corte
a ser plotado.
 }
 // Configura��es Iniciais da janela gr�fica.
 glOrtho(0, 670, 0, 360, -1 ,1); // Define o sistema de coordenadas da �rea
gr�fica de exibi��o. glClearColor(1.0, 1.0, 1.0, 1.0); // Cor de fundo da janela (branca).
 // Define os valores das ordenadas y dos cortesXlinha a serem plotados no
gr�fico.
 My[0][0] = 300; //Ordenada y do ponto inicial e da linha 0 (valor
"M�ximo").
 My[0][1] = 200; //Ordenada y do ponto inicial e da linha 1 (valor ideal da
"Medida").
 My[0][2] = 150; //Ordenada y do ponto inicial e da linha 2 (valor
"M�nimo").
 My[0][3] = 200; //Ordenada y da linha valor "Sensor01".
}
// Usa para concentar o desenho de todos os elementos do gr�fico.
void desenha_grafico(void)
{
 GLfloat x, y; // Auxiliar nas defini��es de posi��o dos elementos do
gr�fico.
 int legenda_tam; // espa�o usado por cada item na legenda.
 char str_valor_ponto[CORTES]; // Armazena o valor do ponto do sensor01
como string.
 // L� o pr�ximo registro de dados do arquivo controlado por
'contador_de_registro'.
 // Abre o arquivo de dados no modo leitura.
 arq = fopen("arq_guilhotina_dados.dat", "rb"); 
 // Verifica se o arquivo foi aberto corretamente.
 if (arq == NULL)
 { 
 printf("Erro na abertura do arquivo de dados da guilhotina.\n");
 exit(1); // Aborta a execu��o.
 }
 else
 {
 // Localiza o registro no arquivo.
 // Localiza um registro no arquivo a partir da posi��o SEEK_SET (in�cio
do arquivo).
 fseek(arq, contador_de_registro*sizeof(dados), SEEK_SET); 
 // Registro localizado.
 // L� o registro de dados do sensor 01 referento ao corte da
guilhotina.
 fread(&dados, sizeof(dados), 1, arq);
 // Verifica se foi lido um registro v�lido.
 if (!feof(arq))
 {
 // Incrementa o contador de registro para apontar para o pr�ximo
registro.
 contador_de_registro++;
 // Verifica se j� foram preenchidas tadas as posi��es de CORTES no
gr�fico.
 if (corte==CORTES-1)
 {
 // Faz a transfer�ncia dos valores para liberar a �ltima
posi��o para a pr�xima leitura.
 for (int i=0;i<corte;i++)
 {
 rotulo_s01[i] = rotulo_s01[i+1]; // Transfere o valor do
r�tulo.
 My[i][3] = My[i+1][3]; // Transfere os valores do 'corte'
para liberar a �ltima posi��o.
 }
 My[0][3] = My[1][3]; // Repete o conte�do da posi��o 1 na
posi��o 0. 
 }
 else
 corte++; // Incrementa o contador para o pr�ximo corte.
 // Guarda o valor da leitura do sensor 01. rotulo_s01[corte] = dados.s01;
 
 // Definie as ordenadas de cada uma das 4 linhas do gr�fico.
 My[corte][0] = 300; //Ordenada y da linha valor "M�ximo".
 My[corte][1] = 200; //Ordenada y da linha valor ideal da "Medida".
 My[corte][2] = 150; //Ordenada y da linha valor "M�nimo".
 My[corte][3] = ((dados.s01 - 20.0) * 50.0) + 200; //Ordenada y da
linha valor "Sensor01".
 }
 fclose(arq); // Fecha o arquivo de dados.
 }
 // Fun��o para desenhar a borda cinza do gr�fico.
 denha_borda_cinza(); 
 // Desenha os r�tulos do eixo y.
 x = x_ini - 60; // O r�tulo do eixo 'y' ser� plotado na posi��o inicial
'x_ini' menos 60 pixels. 
 y = My[0][0]; // O r�tulo do eixo 'y' ser� plotado na posi��o 'My' da linha
"M�xima".
 desenha_texto("22", x, y, 0.502, 0.502, 0.502); // Desenha o texto "22"
(cor cinza).
 y = My[0][1]; // O r�tulo do eixo 'y' ser� plotado na posi��o 'My' da linha
"Medida" ideal.
 desenha_texto("20", x, y, 0.502, 0.502, 0.502); // Desenha o texto "20"
(cor cinza).
 y = My[0][2]; // O r�tulo do eixo 'y' ser� plotado na posi��o 'My' da linha
"M�nima".
 desenha_texto("19", x, y, 0.502, 0.502, 0.502); // Desenha o texto "19"
(cor cinza).
 y = My[0][2]-100; // O r�tulo do eixo 'y' ser� plotado na posi��o do eixo
base do gr�fico.
 desenha_texto("Corte", x, y, 0.502, 0.502, 0.502); // Desenha o texto
"Corte" (cor cinza).
 // Desenha a linha do eixo x.
 x = x_ini; y = 55; // Posi��o inicial da linha do exio x.
 desenha_linha(x, y, x+530, y, 0.502, 0.502, 0.502, 2); // Desenha a linha
do eixo x (cinza).
 // Plota as linhas dos 'Cortes' no gr�fico.
 for (int i=1; i<=corte; i++)
 {
 // Desenha a linha do valor M�ximo.
 desenha_linha(Vx[i-1], My[i-1][0], Vx[i], My[i][0], 1, 1, 0, 2);
 // Desenha a linha do valor ideal da "Medida".
 desenha_linha(Vx[i-1], My[i-1][1], Vx[i], My[i][1], 0, 0, 1, 2);
 // Desenha a linha do valor M�nimo.
 desenha_linha(Vx[i-1], My[i-1][2], Vx[i], My[i][2], 1, 0, 0, 2);
 // Desenha a linha do valor valor do Sensor 01.
 desenha_linha(Vx[i-1], My[i-1][3], Vx[i], My[i][3], 0, 1, 0, 4);
 // Desenha o ponto em destaque do valor M�ximo.
 desenha_ponto(Vx[i], My[i][0], 1, 1, 0, 3);
 // Desenha o ponto em destaque do valor ideal da "Medida".
 desenha_ponto(Vx[i], My[i][1], 0, 0, 1, 3);
 // Desenha o ponto em destaque do valor M�nimo.
 desenha_ponto(Vx[i], My[i][2], 1, 0, 0, 3);
 // Desenha o ponto em destaque do valor ideal da "Medida".
 desenha_ponto(Vx[i], My[i][3], 0, 1, 0, 15);
 // Plota o valor ideal da "Medida" do ponto.
 sprintf(str_valor_ponto, "%6.3f", rotulo_s01[i]);
 desenha_texto(str_valor_ponto, Vx[i]-30, My[i][3]+10, 1, 0, 0);
 }
 // Desenha a legenda.
 x = 90; y = 20; // Posi��o inicial do primeiro item da legenda. legenda_tam = 120; // Define o tamanho de cada item na legenda para 
 // permitir o afastamento adequado da plotagem do
pr�ximo item.
 desenha_linha(x, y+4, x+25, y+4, 0, 0, 1, 4); // Desenha a linha da
legenda.
 desenha_texto("Ideal", x+25, y, 0, 0, 1); // Desenha o texto "Ideal" no
gr�fico.
 x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do pr�ximo
item da legenda.
 desenha_linha(x, y+4, x+25, y+4, 1, 0, 0, 4); // Desenha a linha da
legenda.
 desenha_texto("Minima", x+25, y, 1, 0, 0); // Desenha o texto "M�nima"
no gr�fico.
 x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do pr�ximo
item da legenda.
 desenha_linha(x, y+4, x+25, y+4, 1, 1, 0, 4); // Desenha a linha da
legenda.
 desenha_texto("Maxima", x+25, y, 1, 1, 0); // Desenha o texto "M�xima"
no gr�fico.
 x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do pr�ximo
item da legenda.
 desenha_linha(x, y+4, x+25, y+4, 0, 1, 0, 4); // Desenha a linha da
legenda.
 desenha_texto("Sensor01", x+25, y, 0, 1, 0); // Desenha o texto "Sensor01"
no gr�fico.
 // Plotagem do n�mero do corte no eixo 'x'.
 sprintf(str_valor_ponto, "%03d", contador_de_registro); // Converte o
valor para string.
 desenha_texto(str_valor_ponto, Vx[corte], 35, 0.502, 0.502, 0.502); //
plota o n�mero do corte (cor cinza).
}
// Usada para desenha a borda cinza do gr�fico.
void denha_borda_cinza(void)
{
 glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de exibi��o com a cor de
fundo especificada.
 glLineWidth(4); //Define a espessura da linha em 4 pixels.
 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Define as cores de tr�s e e
da linha do pol�gono.
 glBegin(GL_QUADS); // Inicializa o denho de um quadro.
 glColor3f (0.502,0.502,0.502); // Define a cor da linha do quadro
(cinza).
 glVertex2f(10, 10); // Come�a no canto inferior esquerdo.
 glVertex2f(660, 10); // Desenha a linha at� o conto inferior direito.
 glVertex2f(660, 350); // Linha vertical do lado direito at� a altura
355.
 glVertex2f(10, 350); // Linha horizontal at� x=5 (fecha
automaticamente o quadro).
 glEnd(); // Finaliza o desenho do quadro.
 glFlush(); // Executa os comandos GL pendentes.
}
// Usa para plotar as diversas linhas no gr�fico.
void desenha_linha(GLfloat x_a, GLfloat y_a, GLfloat x_b, GLfloat y_b, GLfloat
r, GLfloat g, GLfloat b, GLfloat largura)
{
 glLineWidth(largura); //Define a espessura da linha em 4 pixels.
 glBegin(GL_LINES); // Inicializa o denho da linha.
 glColor3f (r, g, b); // Define a cor da linha.
 glVertex2f(x_a, y_a); // Coordenada inicial.
 glVertex2f(x_b, y_b); // Coordenada final.
 glEnd(); // Finaliza o desenho da linha.
 glFlush(); // Executa os comandos GL pendentes.}
// Usada para plotar os diversos textos no gr�fico.
void desenha_texto(char *string, GLfloat xf, GLfloat yf, GLfloat r, GLfloat g,
GLfloat b)
{
 glColor3f(r, g, b); // Define a cor do texto.
 glPushMatrix(); // Empinha a imagem na matriz de desenho da imagem.
 glRasterPos2f(xf, yf); // Posi��o no universo onde o texto ser� colocado.
 // Plota caracter a caracter
 while(*string)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++); //
Renderiza o caractere.
 glPopMatrix(); // Desempilha e torna a matriz dispon�vel para exibi��o.
 glFlush(); // Executa os comandos GL pendentes.
}
// Usada para plotar os pontos das linhas (destaque para o ponto do sensor01).
void desenha_ponto(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, int
tamanho)
{
 glColor3f(r, g, b); // Define a cor do texto.
 glPointSize(tamanho); // Define o tamanho da marca do sensor01.
 glBegin(GL_POINTS); // Inicializa o desenho da marca.
 glVertex2f(x, y); // Desenha a marca (ponto).
 glEnd(); // Finaliza o desenho do ponto.
 glFlush(); // Executa as fun��es GL.
}
// Fun��o callback chamada pela GLUT a cada intervalo de tempo.
void temporizacao(int value)
{
 // Redesenha o quadrado com as novas coordenadas 
 glutPostRedisplay();
 glutTimerFunc(TEMPORIZADOR,temporizacao, 1);
}
