#include <iostream> 
#include <vector> 
using namespace std;

int somaAlternada(vector<int>);
void lerNVector(unsigned, string, vector<int> &);

int main(){
    vector<int> a, b;
    lerNVector(9, "Leitura do vetor A: ", a);
    cout << somaAlternada(a);
}

int somaAlternada(
    vector<int> a
){
    int soma=0;
    for(unsigned x = 0; x<a.size(); x++){
        if(x%2==0) soma += a[x];
        else soma -= a[x];
    }

    return soma;
}

void lerNVector(unsigned n, string msg, vector<int> &a){
    unsigned k;
    for(unsigned i = 0; i<n; i++){
        cout << msg; cin >> k; a.push_back(k);
    }
}