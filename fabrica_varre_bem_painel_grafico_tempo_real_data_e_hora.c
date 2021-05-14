/* Fábrica de Vassouras Varre Bem!
    Programa para exibir o gráfico dos dados do sensor 01.
    Feito por Estagiário (O bom!)
    Data: 14/04/2021, às 21h30.

layout do arquivo
=====================================================================
|Descrição                    | Campo | Tipo      | Tamanho         |
+-----------------------------+-------+-----------+-----------------+
| Código da guilhotina        | cod   | caractere | 2               |
| Sensor de comprimento em cm | s01   | real      | 00.000 a 99.999 |
| Sensor de pressão em psi    | s02   | inteiro   | 0 a 999         |
| Sensor de detecção da fibra | s03   | booleano  | 1               |
=====================================================================

Exemplo de dados:         
cod | s01  | s02 | s03
01   20.000  300    1     
01   18.090  300    1 
01   19.095  300    1 
01   19.805  300    1 
01   20.175  300    1 
01   18.001  300    1
01   21.900  300    1
01   19.510  300    1

Para compilar: gcc -lGL -lGLU -lglut -lm arquivo_fonte.c -o arquivo_objeto 

*/

#include <stdio.h>  // Funções e diretivas de I/O padrão: fopen, FILE ...
#include <GL/glut.h>  // Funções gráficas e diretivas: glutInit().
#include <time.h> // Para registrar a data e a hora da leitura dos sensores.
#include <string.h>  // Usar a função strcpy para copiar string.

// Constante para definir a quantidade de cortes a serem exibidos no gráfico.
// Um 'corte' significa um registro de dados lidos dos sensores e projetado no gráfico. 
#define CORTES 6  // O 'corte 0' é usado para marcar o ponto inicial das linhas. 
#define TEMPORIZADOR 1000  // 1 segundo (1.000 milissegundos).

// Estrutura usada na gravação dos dados no arquivo. 
typedef struct 
{
    char cod[2];  // Código da guilhotina.
    float s01;  // Medida do sensor 01 (comprimento) em centímetro.
    int s02;  // Medida do sensor 02 (pressão) em psi.
    short s03;  // Medida do sensor 03 (presença da fibra) 1-presente/2-ausente.
    struct tm dia_hora;  // Data e hora da leitura. 
} dados_guilhotina;  // Definição do nome do tipo.

// Estrutura 'dados' para manipular os dados lidos do arquivo.
dados_guilhotina dados;

// Ponteiro para manipular o arquivo de dados.
FILE *arq;

// Identificador do último registro de dados plotado.
int contador_de_registro = 0;

// Define os valores iniciais de posicionamento dos elementos do gráfico.
GLfloat x_ini = 80;  // Posição do primeiro 'Corte' plotado no eixo 'x'.
GLfloat y_ini = 300;  // Posição da primeira linha (superior) a ser plotada no eixo 'y'.

// Vetores com as coordenadas de platagem das linhas do gráfico.
GLfloat Vx[CORTES];  // As ordenadas x de cada "Corte" a ser protado no gráfico.
GLfloat My[CORTES][4];  // As ordenadas y de cada "Corte" e cada uma das 4 linhas a serem plotados no gráfico.

// Vetor com os valores (rótulos) do sensor 01 para serem plotados sobre os pontos no gráfico.
float rotulo_s01[CORTES];

// Vetor com as horas dos CORTES para serem plotadas no eixo 'x'.
struct tm hora_corte[CORTES];

// Data da leitura a ser impressa no gráfico.
char dt_leitura[10];

// Hora de uma leitura a ser impressa no gráfico.
char rotulo_hora[8];

// Controle dos cortes plotados em tempo real.
short corte = 0;

// Protótipo das funções criadas no programa.
void inicializa(void);
void desenha_grafico(void);
void denha_borda_cinza(void);
void desenha_linha(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void desenha_texto(char *, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, int);
void desenha_ponto(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, int);
void temporizacao(int);

//Função Principal.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Inicializar a biblioteca de funções gráficas.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Define o módo de exibição das imagens geradas.
    glutInitWindowSize(670, 360);  // Define o tamanho da janela gráfica inicial.
    glutInitWindowPosition(700, 0);  // Define a posição na tela de exibição da janela gráfica.
    glutCreateWindow("Monitor Sensor 01 da Guilhotina");  // Cria a janela com as configurações iniciais.

    inicializa();  // Define os valores iniciais.
    
    glutDisplayFunc(desenha_grafico);  // Desenha os gráficos na janela criada.
    glutTimerFunc(TEMPORIZADOR, temporizacao, 1);  // Força a exibição do gráfico de 5 em 5 segundos.

    glutMainLoop();  // Mantém a janela em exibição (execução).
    return 0;
}

// Usada para fazer as configuração dos valores iniciais de controle do gráfico.
void inicializa(void)
{
    // Inicia o controle de contagemm de registros lidos do arquivo.
    contador_de_registro = 0;  // Nenhum registro lido.
    
    // Define as posições das ordenadas 'x' dos cortes a serem plotados no gráfico.
    for (int i=0; i<CORTES; i++) 
    {
        if (i==0)
            Vx[0] = x_ini;  //Valor de início de plotagem do gráfico.
        else
            if (i==1)
                Vx[1] = x_ini;  //Valor inicial da ordenada 'x' do primeiro corte a ser plotado.
            else
                Vx[i] = Vx[i-1]+120;  //Valor da ordenada 'x' do próximo corte a ser plotado.
    }

    // Configurações Iniciais da janela gráfica.
    glOrtho(0, 670, 0, 360, -1 ,1);  // Define o sistema de coordenadas da área gráfica de exibição.
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Cor de fundo da janela (branca).

    // Define os valores das ordenadas y dos cortesXlinha a serem plotados no gráfico.
    My[0][0] = 300;  //Ordenada y do ponto inicial e da linha 0 (valor "Máximo").
    My[0][1] = 200;  //Ordenada y do ponto inicial e da linha 1 (valor ideal da "Medida").
    My[0][2] = 150;  //Ordenada y do ponto inicial e da linha 2 (valor "Mínimo").
    My[0][3] = 200;  //Ordenada y da linha valor "Sensor01".
}

// Usa para concentar o desenho de todos os elementos do gráfico.
void desenha_grafico(void)
{
    GLfloat x, y;  // Auxiliar nas definições de posição dos elementos do gráfico.
    int legenda_tam;  // espaço usado por cada item na legenda.
    char str_valor_ponto[CORTES];  // Armazena o valor do ponto do sensor01 como string.
    char arquivo[] = "arq_guilhotina_dados_data_e_hora.dat"; //Nome do arquivo de dados gravado em disco.

    // Lê o próximo registro de dados do arquivo controlado por 'contador_de_registro'.
    // Abre o arquivo de dados no modo leitura.
    arq = fopen(arquivo, "rb");  
    // Verifica se o arquivo foi aberto corretamente.
    if (arq == NULL)
    { 
        printf("Erro na abertura do arquivo de dados da guilhotina.\n");
        exit(1); // Aborta a execução.
    }
    else
    {
        // Localiza o registro no arquivo.
        // Localiza um registro no arquivo a partir da posição SEEK_SET (início do arquivo).
        fseek(arq, contador_de_registro*sizeof(dados), SEEK_SET); 
        // Registro localizado.
        // Lê o registro de dados do sensor 01 referento ao corte da guilhotina.
        fread(&dados, sizeof(dados), 1, arq);
        // Verifica se foi lido um registro válido.
        if  (!feof(arq))
        {
            // Guarda a data do primeiro registro lido.
            if (contador_de_registro == 0)
                sprintf(dt_leitura, "%02d/%02d/%04d", dados.dia_hora.tm_mday, dados.dia_hora.tm_mon + 1, dados.dia_hora.tm_year + 1900);

            // Incrementa o contador de registro para apontar para o próximo registro.
            contador_de_registro++;
            // Verifica se já foram preenchidas tadas as posições de CORTES no gráfico.
            if (corte==CORTES-1)
            {
                // Faz a transferência dos valores para liberar a última posição para a próxima leitura.
                for (int i=0;i<corte;i++)
                {
                    rotulo_s01[i] = rotulo_s01[i+1];  // Transfere o valor do rótulo.
                    hora_corte[i] = hora_corte[i+1];  // Transfere o valor da hora do corte.
                    My[i][3] = My[i+1][3];  // Transfere os valores do 'corte' para liberar a última posição.
                }
                My[0][3] = My[1][3];  // Repete o conteúdo da posição 1 na posição 0.    
            }
            else
                corte++;  // Incrementa o contador para o próximo corte.

            // Guarda o valor da leitura do sensor 01.
            rotulo_s01[corte] = dados.s01;

            // Guarda o valor da hora da leitura.
            hora_corte[corte] = dados.dia_hora;

            // Definie as ordenadas de cada uma das 4 linhas do gráfico.
            My[corte][0] = 300;  //Ordenada y da linha valor "Máximo".
            My[corte][1] = 200;  //Ordenada y da linha valor ideal da "Medida".
            My[corte][2] = 150;  //Ordenada y da linha valor "Mínimo".
            My[corte][3] = ((dados.s01 - 20.0) * 50.0) + 200;  //Ordenada y da linha valor "Sensor01".
            if (corte == 1)
                My[0][3] = ((dados.s01 - 20.0) * 50.0) + 200;  //Repete a posição para o primeiro corte.
        }
        fclose(arq);  // Fecha o arquivo de dados.
    }

    // Função para desenhar a borda cinza do gráfico.
    denha_borda_cinza(); 

    // Desenha a data.
    desenha_texto(dt_leitura,    80, 325, 0.502, 0.502, 0.502, 18);  // Desenha o texto da variável dt_leitura.

    // Desenha os rótulos do eixo y.
    x = x_ini - 60;  // O rótulo do eixo 'y' será plotado na posição inicial 'x_ini' menos 60 pixels. 
    y = My[0][0]; // O rótulo do eixo 'y' será plotado na posição 'My' da linha "Máxima".
    desenha_texto("22",    x, y, 0.502, 0.502, 0.502, 18);  // Desenha o texto "22" (cor cinza).
    y = My[0][1]; // O rótulo do eixo 'y' será plotado na posição 'My' da linha "Medida" ideal.
    desenha_texto("20",    x, y, 0.502, 0.502, 0.502, 18);  // Desenha o texto "20" (cor cinza).
    y = My[0][2]; // O rótulo do eixo 'y' será plotado na posição 'My' da linha "Mínima".
    desenha_texto("19",    x, y, 0.502, 0.502, 0.502, 18);  // Desenha o texto "19" (cor cinza).
    y = My[0][2]-100; // O rótulo do eixo 'y' será plotado na posição do eixo base do gráfico.
    desenha_texto("Corte", x, y, 0.502, 0.502, 0.502, 18);  // Desenha o texto "Corte" (cor cinza).

    // Desenha a linha do eixo x.
    x = x_ini; y = 55; // Posição inicial da linha do exio x.
    desenha_linha(x, y,  x+530, y, 0.502, 0.502, 0.502, 2);  // Desenha a linha do eixo x (cinza).

    // Plota as linhas dos 'Cortes' no gráfico.
    for (int i=1; i<=corte; i++)
    {
        // Desenha a linha do valor Máximo.
        desenha_linha(Vx[i-1], My[i-1][0],  Vx[i], My[i][0], 1, 1, 0, 2);
        // Desenha a linha do valor ideal da "Medida".
        desenha_linha(Vx[i-1], My[i-1][1],  Vx[i], My[i][1], 0, 0, 1, 2);
        // Desenha a linha do valor Mínimo.
        desenha_linha(Vx[i-1], My[i-1][2],  Vx[i], My[i][2], 1, 0, 0, 2);
        // Desenha a linha do valor valor do Sensor 01.
        desenha_linha(Vx[i-1], My[i-1][3],  Vx[i], My[i][3], 0, 1, 0, 4);

        // Desenha o ponto em destaque do valor Máximo.
        desenha_ponto(Vx[i], My[i][0], 1, 1, 0, 3);
        // Desenha o ponto em destaque do valor ideal da "Medida".
        desenha_ponto(Vx[i], My[i][1], 0, 0, 1, 3);
        // Desenha o ponto em destaque do valor Mínimo.
        desenha_ponto(Vx[i], My[i][2], 1, 0, 0, 3);
        // Desenha o ponto em destaque do valor ideal da "Medida".
        desenha_ponto(Vx[i], My[i][3], 0, 1, 0, 15);

        // Plota o valor ideal da "Medida" do ponto.
        sprintf(str_valor_ponto, "%6.3f", rotulo_s01[i]);
        desenha_texto(str_valor_ponto, Vx[i]-30, My[i][3]+10, 1    , 0    , 0    , 18);

        // Desenha o ponto em destaque do eixo x.
        desenha_ponto(Vx[i], y, 0.502, 0.502, 0.502, 5);

        // Hora de uma leitura a ser impressa no gráfico.
        sprintf(rotulo_hora, "%02d:%02d:%02d", hora_corte[i].tm_hour, hora_corte[i].tm_min, hora_corte[i].tm_sec);
        // Plotagem da hora do corte no eixo 'x'.
        desenha_texto(rotulo_hora, Vx[i]-15, 40, 0.502, 0.502, 0.502, 10);  // plota o número do corte (cor cinza).
    }

    // Desenha a legenda.
    x = 90; y = 20; // Posição inicial do primeiro item da legenda.
    legenda_tam = 120;  // Define o tamanho de cada item na legenda para 
                        // permitir o afastamento adequado da plotagem do próximo item.
    desenha_linha(x, y+4,  x+25, y+4, 0, 0, 1, 4);  // Desenha a linha da legenda.
    desenha_texto("Ideal",   x+25, y, 0, 0, 1, 18);  // Desenha o texto "Ideal" no gráfico.

    x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do próximo item da legenda.
    desenha_linha(x, y+4,  x+25, y+4, 1, 0, 0, 4);  // Desenha a linha da legenda.
    desenha_texto("Minima",   x+25, y, 1, 0, 0, 18);  // Desenha o texto "Mínima" no gráfico.

    x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do próximo item da legenda.
    desenha_linha(x, y+4,  x+25, y+4, 1, 1, 0, 4);  // Desenha a linha da legenda.
    desenha_texto("Maxima",   x+25, y, 1, 1, 0, 18);  // Desenha o texto "Máxima" no gráfico.

    x += legenda_tam; // Deslocamento no eixo 'x' para a plotagem do próximo item da legenda.
    desenha_linha(x, y+4,  x+25, y+4, 0, 1, 0, 4);  // Desenha a linha da legenda.
    desenha_texto("Sensor01", x+25, y, 0, 1, 0, 18);  // Desenha o texto "Sensor01" no gráfico.

    // Emite um beep a cada redesenho do tela.
    // system("paplay /usr/share/sounds/sound-icons/capital");
}

// Usada para desenha a borda cinza do gráfico.
void denha_borda_cinza(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa a janela de exibição com a cor de fundo especificada.
    glLineWidth(4);  //Define a espessura da linha em 4 pixels.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Define as cores de trás e e da linha do polígono.
    glBegin(GL_QUADS);  // Inicializa o denho de um quadro.
        glColor3f (0.502,0.502,0.502);  // Define a cor da linha do quadro (cinza).
        glVertex2f(10, 10);  // Começa no canto inferior esquerdo.
        glVertex2f(660, 10);  // Desenha a linha até o conto inferior direito.
        glVertex2f(660, 350);  // Linha vertical do lado direito até a altura 355.
        glVertex2f(10, 350);  // Linha horizontal até x=5 (fecha automaticamente o quadro).
    glEnd();  // Finaliza o desenho do quadro.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usa para plotar as diversas linhas no gráfico.
void desenha_linha(GLfloat x_a, GLfloat y_a, GLfloat x_b, GLfloat y_b, GLfloat r, GLfloat g, GLfloat b, GLfloat largura)
{
    glLineWidth(largura);  //Define a espessura da linha em 4 pixels.
    glBegin(GL_LINES);  // Inicializa o denho da linha.
        glColor3f (r, g, b);  // Define a cor da linha.
        glVertex2f(x_a, y_a);  // Coordenada inicial.
        glVertex2f(x_b, y_b);  // Coordenada final.
    glEnd();  // Finaliza o desenho da linha.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usada para plotar os diversos textos no gráfico.
void desenha_texto(char *string, GLfloat xf, GLfloat yf, GLfloat r, GLfloat g, GLfloat b, int tamanho)
{

    glColor3f(r, g, b);  // Define a cor do texto.
    glPushMatrix();  // Empinha a imagem na matriz de desenho da imagem.
    glRasterPos2f(xf, yf);  // Posição no universo onde o texto será colocado.
    // Plota caracter a caracter
    if (tamanho == 10)
        while(*string)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);  // Renderiza o caractere.
    else
        if (tamanho == 12)
            while(*string)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);  // Renderiza o caractere.
        else
            while(*string)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);  // Renderiza o caractere.
    glPopMatrix();  // Desempilha e torna a matriz disponível para exibição.
    glFlush();  // Executa os comandos GL pendentes.
}

// Usada para plotar os pontos das linhas (destaque para o ponto do sensor01).
void desenha_ponto(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, int tamanho)
{
    glColor3f(r, g, b);  // Define a cor do texto.
    glPointSize(tamanho); // Define o tamanho da marca do sensor01.
    glBegin(GL_POINTS);  // Inicializa o desenho da marca.
        glVertex2f(x, y);  // Desenha a marca (ponto).
    glEnd();  // Finaliza o desenho do ponto.
    glFlush();  // Executa as funções GL.
}

// Função callback chamada pela GLUT a cada intervalo de tempo.
void temporizacao(int value)
{
    // Redesenha o quadrado com as novas coordenadas 
    glutPostRedisplay();
    glutTimerFunc(TEMPORIZADOR,temporizacao, 1);
}
