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
    arq = fopen("remedios.dat", "w+");
    cout << "Digite o nome do remédio (Fim p/ Sair): ";
    cin >> remedio.desc;
    while (strcmp(remedio.desc, "Fim"))
    {
        cout << "Digite o Componente Ativo: ";
        cin >> remedio.comp;
        cout << "Digite a Quantidade: ";
        cin >> remedio.qtde;
        cout << "Digite o preço: ";
        cin >> remedio.preco;
        cout << "Digite a Classificação: ";
        cin >> remedio.clas;
        fwrite(&remedio, sizeof(remedio), 1, arq);
        cout << "Digite o nome do remédio (Fim p/ Sair): ";
        cin >> remedio.desc;
    }
    cout << "Fim do cadastro " << endl;
    fclose(arq);
    return 0;
}