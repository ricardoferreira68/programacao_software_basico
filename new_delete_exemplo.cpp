#include <iostream>
using namespace std;
int main(void){
    int *ptr_a;
    ptr_a = new int;
    if (ptr_a == NULL){
        cout << "Memória insuficiente!" << endl;
        exit(1);
    }
    cout << "Endereço de ptr_a: " << ptr_a << endl;
    *ptr_a = 90;
    cout << "Conteúdo de ptr_a: " << *ptr_a << endl;
    delete ptr_a;
    return 0;
}