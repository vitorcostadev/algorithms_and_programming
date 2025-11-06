#include <iostream>
#include <vector>

using namespace std;

double escalarProd(vector<double>, vector<double>);
void lerNVector(unsigned, string, vector<double> &);
void mostrarVector(vector<int>);

int main(){
    vector<double> a,b;
    lerNVector(5, "Leitura do Vetor A: ", a);
    lerNVector(5, "Leitura do Vetor B: ", b);

    cout << "Produto escalar: "<<escalarProd(a,b);
}

double escalarProd(
    vector<double> a,
    vector<double> b
){
    double soma;

    for(unsigned i = 0; i<a.size(); i++) soma += a[i] * b[i];

    return soma;
}

void lerNVector(unsigned n, string msg, vector<double> &a){
    unsigned k;
    for(unsigned i = 0; i<n; i++){
        cout << msg; cin >> k; a.push_back(k);
    }
}

void mostrarVector(vector<int> a){
    for(unsigned i = 0; i<a.size(); i++) cout<<"["<<a[i]<<"]"<<endl;
}