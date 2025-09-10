#include <iostream>
#include <windows.h>

using namespace std;

bool isNumberPrimo(unsigned num)
{
    if (num == 1) return false; 

    unsigned aux = 0, div=1;
    for(unsigned i = 1; i<=num; i++)
    {
        if(num % div == 0 and aux < 2)
        {
            aux++;
            div=num;
        }
    }

    if(aux==2) return true;
    return false;
    
}

int main()
{
    bool isNumberPrimo(unsigned);
    SetConsoleOutputCP(CP_UTF8);

    int n;
    do{
        cout << "Digite um número: ";
        cin>>n;

        if(isNumberPrimo(n))
        {
            cout << "O número "<<n<<" é primo!"<<endl;
        }else if(n <1)
        {
            cout << "Apenas números maior do que zero!"<<endl;
        }else cout << "O número 1 não é primo!"<<endl;
    }while(not isNumberPrimo(n));
}