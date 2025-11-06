#include <iostream>
using namespace std;

long int prodEscalar(unsigned n, unsigned x[], unsigned y[]);
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
    cout<<prodEscalar(n,x,y);
}


long int prodEscalar(unsigned n, unsigned x[], unsigned y[])
{
    if(n==1) return x[n-1] * y[n-1];
    else{
        return x[n-1] * y[n-1] + prodEscalar(n-1, x,y);
    }
}