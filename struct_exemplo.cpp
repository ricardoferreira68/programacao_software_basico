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
    strcpy(clientes.nome, "Beth Byte");  //equivale a: clientes.nome = "Beth Byte";  
    clientes.altura = 1.67;
    clientes.idade = 23;
    clientes.sexo = 'F';
    cout << clientes.nome << endl;
    cout << clientes.altura << endl;
    cout << clientes.idade << endl;
    cout << clientes.sexo << endl;
}
