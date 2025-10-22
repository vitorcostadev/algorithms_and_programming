#include <iostream>
using namespace std;

void prodEscalar(unsigned i, unsigned f, unsigned &prod, unsigned x[], unsigned y[]);
int main()
{
    unsigned n=0;
    do{
        cout<<"Digite o tamanho dos vetores x e y: ";
        cin>>n;
    }while(n==0);

    unsigned x[n], y[n];

    for(unsigned i = 0; i < n; i++){
        cout<<"Digite um valor para X["<<i<<"]: "; cin>>x[i];
        cout<<"Digite um valor para Y["<<i<<"]: "; cin>>y[i];
    }
    unsigned prod=0;
    prodEscalar(0, n, prod, x,y);
    cout << prod;
}


void prodEscalar(unsigned i, unsigned f, unsigned &prod, unsigned x[], unsigned y[])
{
    if(i==f) return;
    else{
        prod += x[i] * y[i];
        return prodEscalar(i+1, f, prod, x, y);
    }
}