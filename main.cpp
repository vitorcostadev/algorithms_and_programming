#include <iostream>
#define TMAX 5
using namespace std;

int main()
{
    void inverterVetor(unsigned, unsigned, unsigned[]);
    void imprimirVetor(int, unsigned[]);
    void multVetor(int, unsigned, unsigned[]);
    void ordernarVetor(unsigned inicio, unsigned fim, unsigned vet[]);
    bool verifyIfNumExistsInVet(unsigned size, int num, unsigned vet[], unsigned &);
    void inputOnVector(int x, unsigned inc, unsigned vet[], string message="");

    unsigned vet[TMAX];
    unsigned indice;
    inputOnVector(TMAX, 0, vet);
    ordernarVetor(0, TMAX-1, vet);
    imprimirVetor(TMAX, vet);
    bool x = verifyIfNumExistsInVet(TMAX-1, 2, vet, indice);
    if(x) cout<<"Sim, esta no indice "<<indice; else cout << "Nao";
    
    return 0;
}

void inverterVetor(unsigned inicio, unsigned fim, unsigned vet[])
{
    if (inicio>=fim) return;
    else{
        swap(vet[inicio], vet[fim]);
        inverterVetor(inicio + 1, fim - 1, vet);
    }
}

void imprimirVetor(int x, unsigned vet[])
{
    if(x<=0) return;
    else{
        cout << vet[x-1]<<" ";
        imprimirVetor(x - 1, vet);
    }
}

void multVetor(int x, unsigned multiplicador, unsigned vet[])
{
    if(x<0) return;
    else{
        vet[x] *= multiplicador;
        multVetor(x - 1, multiplicador, vet);
    }
}

void ordernarVetor(unsigned inicio, unsigned fim, unsigned vet[])
{
    
    if(inicio>=fim) return;
    else{
        unsigned min_idx = inicio;
        for(unsigned i = inicio+1; i<=fim; i++){
            if(vet[i] < vet[min_idx]) min_idx = i;
        }
        swap(vet[inicio], vet[min_idx]);
        ordernarVetor(inicio+1, fim, vet);
    }
}

bool verifyIfNumExistsInVet(unsigned size, int num, unsigned vet[], unsigned &indice)
{
    if(size==0) return false;
    else{
        if(num == vet[size-1]){
            indice = size-1;
            return true;
        }else
            return verifyIfNumExistsInVet(size-1, num, vet, indice);
    }
}
void inputOnVector(int x, unsigned inc, unsigned vet[], string message="")
{
    if (message.empty())
        message = "Insira o "+to_string(inc+1)+"o valor: ";

    if (x<=0) return;
    cout<<message;
    cin>>vet[inc];
    inputOnVector(x-1, inc+1, vet);
}