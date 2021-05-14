#include <iostream>
using namespace std;
int main() 
{
    int num = 5; 
    int *iptr;

    iptr = &num;
    cout << *iptr << endl;

    *iptr = 10;
    cout << num << endl;
}
