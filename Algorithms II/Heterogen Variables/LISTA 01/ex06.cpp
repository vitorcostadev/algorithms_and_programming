#include <iostream>
#include <cctype>
#define TMAX 2
using namespace std;

/*
Uma empresa possui vários vendedores. Para cada vendedor é conhecido o nome, a
quantidade vendida, o valor da venda e o salário fixo. Os vendedores recebem
comissão de acordo com a quantidade vendida:
1. 10% do valor da venda se quantidade vendida < 15
2. 22% do valor da venda se 15 <= quantidade vendida < 30
3. 30% do valor da venda se quantidade vendida >= 30
Construa um algoritmo que escreva o nome do vendedor, a quantidade vendida, o
valor da venda, o salário fixo, a comissão e o total recebido. Os nomes dos
vendedores devem ser relacionados em ordem alfabética.
*/

typedef struct 
{
    string nome;
    unsigned quantidade_vendida;
    float valor_venda, salario_fixo, comissao, total_a_receber;
} Vendedor;

// Funções 
void calcularComissao(Vendedor &v);
void calcularComissaoVet(unsigned x, Vendedor v[]);
bool validarNome(string nome);
bool validarInteiro(string numero);
bool validarFloat(string numero);
void ordernarNomes(unsigned x, Vendedor v[]);
bool vemAntes(string &a, string &b);
void entradaDeDados(unsigned x, Vendedor v[]);
void totalAReceber(Vendedor &v);
void totalAReceberVet(unsigned x, Vendedor v[]);
void relatorioFinal(unsigned x, Vendedor v[]);
//main
int main()
{
    Vendedor vendedores[4];
    relatorioFinal(TMAX, vendedores);
}

void calcularComissao(Vendedor &v)
{
    if(v.valor_venda >= 30)
    {
        v.comissao = v.valor_venda * 0.3;
    }else if(v.valor_venda >= 15)
    {
        v.comissao = v.valor_venda * 0.22;
    }else
        v.comissao = v.valor_venda * 0.15;
}

void calcularComissaoVet(unsigned x, Vendedor v[])
{
    for(unsigned i = 0; i < x; i++)
    {
        calcularComissao(v[i]);
    }
}

bool validarNome(string nome)
{
    if(nome.empty()) return false;

    for(unsigned i = 0; i < nome.size(); i++)
    {
        if(not isalpha(nome[i]) and nome[i] != ' ') return false;
    }

    return true;
}

bool validarInteiro(string numero)
{
    if(numero.empty()) return false;

    for(unsigned i = 0; i<numero.size(); i++)
    {
        if(not isdigit(numero[0]) and numero[0] != '-') return false;
        else{
            for(unsigned x = 1; x<numero.size(); x++){
                if(not isdigit(numero[x])) return false;
            }
        }
    }
    return true;
}

bool validarFloat(string numero)
{
    if(numero.empty()) return false;

    short ponto = 0;
    for(unsigned i = 0; i<numero.size(); i++)
    {
        if(not isdigit(numero[0]) and numero[0] != '-') return false;
        else{
            for(unsigned x = 1; x<numero.size(); x++){
                if(not isdigit(numero[x]) and numero[x] == '.' and ponto==0) ponto++;
                else{
                    if(not isdigit(numero[x])) return false;
                }
            }
        }
    }
    return true;
}

void ordernarNomes(unsigned x, Vendedor v[])
{
    for (unsigned i = 0; i < x; i++) {
        for (unsigned j = i + 1; j < x; j++) {
            if (!vemAntes(v[i].nome, v[j].nome)) {
                swap(v[i], v[j]); 
            }
        }
    }

}

bool vemAntes(string &a, string &b)
{
    unsigned i = 0;
    while(i < a.size() and i < b.size())
    {
        char c1=tolower(a[i]), c2=tolower(b[i]);
        if(c1<c2) return true;
        if(c1>c2) return false;
        i++;
    }
    return a.size() < b.size();
}

void entradaDeDados(unsigned x, Vendedor v[])
{
    Vendedor vendedor;
    string value = "";

    do{
        cout << x+1<<": "<<"Digite o nome do vendedor(a): ";
        getline(cin, vendedor.nome);
    }while(not validarNome(vendedor.nome));

    
    do{
        cout << x+1<<": "<<"Digite a quantidade de itens vendidos: ";
        cin>>value;

        if(not validarInteiro(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atoi(value.c_str()) < 0) cout << "[i] : Total de vendas nao deve ser negativo."<<endl;
            else vendedor.quantidade_vendida = atoi(value.c_str());
        }
    }while(not validarInteiro(value) or atoi(value.c_str()) < 0);

    do{
        value="";
        cout << x+1<<": "<<"Digite o valor da venda: ";
        cin>>value;

        if(not validarFloat(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atof(value.c_str()) < 0) cout << "[i] : O valor de venda nao pode ser negativo."<<endl;
            else vendedor.valor_venda = atof(value.c_str());
        }
    }while(not validarFloat(value) or atof(value.c_str()) < 0);

    do{
        value="";
        cout << x+1<<": "<<"Digite o salario fixo: ";
        cin>>value;

        if(not validarFloat(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atof(value.c_str()) < 0) cout << "[i] : O salario nao pode ser negativo."<<endl;
            else vendedor.salario_fixo = atof(value.c_str());
        }
    }while(not validarFloat(value) or atof(value.c_str()) < 0);

    v[x] = vendedor;
    
}

void totalAReceber(Vendedor &v){
    v.total_a_receber = v.salario_fixo + (v.valor_venda+v.comissao);
}

void totalAReceberVet(unsigned x, Vendedor v[])
{
    for(unsigned i = 0; i<x; i++) totalAReceber(v[i]);
}

void relatorioFinal(unsigned x, Vendedor v[]){
    for(unsigned i = 0; i<x; i++){
        entradaDeDados(i, v);
        cin.ignore();
    }
    ordernarNomes(x, v);
    calcularComissaoVet(x, v);
    totalAReceberVet(x, v);

    for(unsigned i = 0; i<x; i++)
    {
        cout<<"[i] : Nome do vendedor(a): "<<v[i].nome<<endl;
        cout<<"[ii] : Qty. de itens vendidos: "<<v[i].quantidade_vendida<<endl;
        cout<<"[iii] : Valor da venda R$ "<<v[i].valor_venda<<endl;
        cout<<"[iv] : Comissao R$ "<<v[i].comissao<<endl;
        cout<<"[v] : Salario Fixo R$ "<<v[i].salario_fixo<<endl;
        cout<<"[vi] : Total a receber R$ "<<v[i].total_a_receber<<endl;
        cout<<"\n";
    }
}