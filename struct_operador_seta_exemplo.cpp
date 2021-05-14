#include <iostream>
#include <string.h>
using namespace std;
int main(){
    struct cadastro{
        char nome[30];
        float altura;
        int idade;
        char sexo;
    };
    cadastro clientes;
    cadastro *registro;
    strcpy(clientes.nome, "Beth Byte");  //equivale a: clientes.nome = "Beth Byte";  
    clientes.altura = 1.67;
    clientes.idade = 23;
    clientes.sexo = 'F';
    registro = &clientes;
    cout << registro->nome << endl;
    cout << registro->altura << endl;
    cout << registro->idade << endl;
    cout << registro->sexo << endl;
}
