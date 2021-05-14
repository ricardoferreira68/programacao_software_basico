/* FACULDADE ESTÁCIO DE BELÉM
   Exemplificação Vetor de struct
   Autor: Ricardo Ferreira */
#include <iostream>
#include <string.h>
#include <iomanip>
#define TAM 3
using namespace std;
int main()
{
    struct cadastro {
        char nome[30];
        float altura;
        int idade;
        char sexo;
    };
    cadastro clientes[TAM];
    int i;
    for (i=0;i<TAM;i++) {
        cout << endl << "Digite o nome: ";
        cin >> clientes[i].nome;
        cout << "Digite a altura: ";
        cin >> clientes[i].altura;
        cout << "Digite a idade: ";
        cin >> clientes[i].idade;
        cout << "Digite o sexo: ";
        cin >> clientes[i].sexo;
    }
    cout << endl;
    cout << "==================" << endl;
    cout << "NOME     ALTURA IDADE SEXO" << endl;
    cout << "---------------------------" << endl;
    for (i=0;i<TAM;i++){
        cout << left;
        cout << setw(20) << clientes[i].nome;
        cout << setw(7) << clientes[i].altura;
        cout << setw(6) << clientes[i].idade;
        cout << setw(5) << clientes[i].sexo << endl;
    }
}
