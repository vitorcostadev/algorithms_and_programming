/*
2. Dado uma string A e um número n, retorne uma string B que consiste na reprodução de A n
vezes. Por exemplo, se A = “tchau” e n = 2 então B = “tchau tchau”. 
*/

#include <iostream>

using namespace std; 

int main()
{
    string A = "", B = "";
    unsigned n = 0;

    do{
        cout << "Digite uma palavra: ";
        getline(cin, A);
    }while(A.empty());

    do{
        cout << "Digite um número para n: ";
        cin >> n;
    }while(n < 1);

    unsigned controlador = 0;
    while(controlador < n){
        B += A;
        B += " ";

        controlador++;
    }
    cout<<"String A: "<<A<<endl;
    cout<<"String B ("<<n<<"x A): "<<B<<endl;
}