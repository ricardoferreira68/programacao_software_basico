#include <stdio.h>  // Funções e diretivas de I/O padrão: fopen, FILE ...
#include <GL/glut.h>  // Funções gráficas e diretivas: glutInit().
#include <string.h>  // Usar a função strcpy para copiar string.
#include "fabrica_varre_bem.h"  // Estruturas e protótios de funções usadas por todos os módulos.

//Função Principal.
int ativar_painel_sensor01(int *argc, char** argv)
{
    glutInit(argc, argv);  // Inicializar a biblioteca de funções gráficas.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Define o módo de exibição das imagens geradas.
    glutInitWindowSize(670, 360);  // Define o tamanho da janela gráfica inicial.
    glutInitWindowPosition(700, 0);  // Define a posição na tela de exibição da janela gráfica.
    glutCreateWindow("Monitor Sensor 01 da Guilhotina");  // Cria a janela com as configurações iniciais.
    glOrtho(0, 670, 0, 360, -1 ,1);  // Define o sistema de coordenadas da área gráfica de exibição.
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Cor de fundo da janela (branca).

    glutDisplayFunc(desenha_grafico);  // Desenha os gráficos na janela criada.
    glutTimerFunc(TEMPORIZADOR, temporizacao, 1);  // Força a exibição do gráfico de 5 em 5 segundos.
    glutMainLoop();  // Mantém a janela em exibição (execução).
}

// Usa para concentar o desenho de todos os elementos do gráfico.
void desenha_grafico(void)
{
    FILE *arq;  //Ponteiro para manipular o arquivo na memória secundária.
    estrutura_sensores dados; // Estrutura para armazenar os dados dos sensores.
    char arquivo[] = NOME_ARQUIVO_EM_DISCO; //Nome do arquivo de dados gravado em disco.

    GLfloat x, y;  // Auxiliar nas definições de posição dos elementos do gráfico.
    int legenda_tam;  // espaço usado por cada item na legenda.
    // Define os valores iniciais de posicionamento dos elementos do gráfico.
    GLfloat x_ini = 80;  // Posição do primeiro 'Corte' plotado no eixo 'x'.
    GLfloat y_ini = 300;  // Posição da primeira linha (superior) a ser plotada no eixo 'y'.

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

    // Define os valores das ordenadas y dos cortesXlinha a serem plotados no gráfico.
    My[0][0] = 300;  //Ordenada y do ponto inicial e da linha 0 (valor "Máximo").
    My[0][1] = 200;  //Ordenada y do ponto inicial e da linha 1 (valor ideal da "Medida").
    My[0][2] = 150;  //Ordenada y do ponto inicial e da linha 2 (valor "Mínimo").
    My[0][3] = 200;  //Ordenada y da linha valor "Sensor01".

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
            // Incrementa o contador de registro para apontar para o próximo registro.
            contador_de_registro++;
            // Verifica se já foram preenchidas tadas as posições de CORTES no gráfico.
            if (corte==CORTES-1)
            {
                // Faz a transferência dos valores para liberar a última posição para a próxima leitura.
                for (int i=0;i<corte;i++)
                {
                    rotulo_s01[i] = rotulo_s01[i+1];  // Transfere o valor do rótulo.
                    My[i][3] = My[i+1][3];  // Transfere os valores do 'corte' para liberar a última posição.
                }
                My[0][3] = My[1][3];  // Repete o conteúdo da posição 1 na posição 0.
            }
            else
                corte++;  // Incrementa o contador para o próximo corte.

            // Guarda o valor da leitura do sensor 01.
            rotulo_s01[corte] = dados.s01;

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
}
