#include <iostream>
#include <string.h>
#include <iomanip>
#include <locale.h>
using namespace std;
int main(void)
{ 
    struct cadastro
    {
        char desc[30];
        char comp[20];
        char aplic[20];
        char clas[15];
    };
    cadastro *remedio;
	setlocale(LC_ALL, "Portuguese");
    int i = 0;
    remedio = (cadastro *) malloc(sizeof(cadastro));
    cout << "Digite o nome do remédio (Fim p/ Sair): ";
    cin >> remedio[i].desc;
    while (strcmp(remedio[i].desc, "Fim"))
    {
        cout << "Digite o Componente Ativo: ";
        cin >> remedio[i].comp;
        cout << "Digite a Aplicação: ";
        cin >> remedio[i].aplic;
        cout << "Digite a Classificação: ";
        cin >> remedio[i].clas;
        i++; //i +=1; // i = i + 1;
        remedio = (cadastro *) realloc(remedio, sizeof(cadastro) * (i+1));
        cout << "Digite o nome do remédio (Fim p/ Sair): ";
        cin >> remedio[i].desc;
    }
    cout << "===================================================================" << endl;
    cout << "Laboratório Super Med " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Descrição                      Componente Ativo     Classificação " << endl;
    cout << "------------------------------ -------------------- ---------------" << endl;
    for (int k=0;k<i;k++)
    { 
        cout << left;
        cout << setw(31) << remedio[k].desc;
        cout << setw(21) << remedio[k].comp;
        cout << setw(15) << remedio[k].clas << endl;
    }
    cout << "===================================================================" << endl;
    free(remedio);
    return 0;
}