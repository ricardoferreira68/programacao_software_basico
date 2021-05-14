#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{ 
    struct cadastro
    {
        char desc[30];
        char comp[20];
        int qtde;
        float preco;
        char clas[15];
    } remedio;
    FILE *arq;
    arq = fopen("remedios.dat", "r+");
    cout << "-------------------" << endl;
    fread(&remedio, sizeof(remedio), 1, arq);
    while (!feof(arq))
    {
        cout << "Remédio: " << remedio.desc << endl;
        cout << "Componente Ativo: " << remedio.comp << endl;
        cout << "Quantidade: " << remedio.qtde << endl;
        cout << "Preço: " << remedio.preco << endl;
        cout << "Classificação: " << remedio.clas << endl;
        cout  << endl;
        fread(&remedio, sizeof(remedio), 1, arq);
    }
    cout << "-------------------" << endl;
    cout << "Fim da listagem" << endl;
    fclose(arq);
    return 0;
}