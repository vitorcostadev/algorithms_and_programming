#include <iostream>
#include <cctype>
#define TMAX 50
using namespace std;

typedef struct 
{
    string nome;
    unsigned quantidade_vendida=0;
    float valor_venda=0, salario_fixo=0, comissao=0, total_a_receber=0;
} Vendedor;

// Funções 
void calcularComissao(Vendedor &v);
void calcularComissaoVet(unsigned x, Vendedor v[]);
bool validarNome(string nome);
bool validarInteiro(string numero);
bool validarFloat(string numero);
void ordernarNomes(unsigned x, Vendedor v[]);
bool vemAntes(string &a, string &b);
void entradaDeDados(Vendedor &);
void totalAReceber(Vendedor &v);
void totalAReceberVet(unsigned x, Vendedor v[]);
void relatorioFinal(unsigned x, Vendedor v[]);
void lerLimNSup(unsigned, unsigned, unsigned &);
//main
int main()
{
    Vendedor vendedores[TMAX];
    unsigned opcao=0, n = 0;

    if(n < TMAX){
        do{
            cout << "[1] : Inserir Venda"<<endl;
            cout<<"[2] : Verificar vendedores"<<endl;
            cout<<"[3] : Sair"<<endl;
            cout<<"-------------------------------------------------"<<endl;

            lerLimNSup(0,3, opcao);
            cin.ignore();

            switch(opcao){
                case 1:
                    entradaDeDados(vendedores[n]); n++; break;
                case 2:
                    relatorioFinal(n, vendedores); break;
                
            }
            system("pause"); system("cls");
        }while(opcao!=3);

    }else cout << "Limite de vendas atingido."<<endl;

    
    return 0;
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

void entradaDeDados(Vendedor &vendedor)
{
    string value = "";

    do{
        cout << "Digite o nome do vendedor(a): ";
        getline(cin, vendedor.nome);
    }while(not validarNome(vendedor.nome));

    
    do{
        cout << "Digite a quantidade de itens vendidos: ";
        cin>>value;

        if(not validarInteiro(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atoi(value.c_str()) < 0) cout << "[i] : Total de vendas nao deve ser negativo."<<endl;
            else vendedor.quantidade_vendida = atoi(value.c_str());
        }
    }while(not validarInteiro(value) or atoi(value.c_str()) < 0);

    do{
        value="";
        cout << "Digite o valor da venda: ";
        cin>>value;

        if(not validarFloat(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atof(value.c_str()) < 0) cout << "[i] : O valor de venda nao pode ser negativo."<<endl;
            else vendedor.valor_venda = atof(value.c_str());
        }
    }while(not validarFloat(value) or atof(value.c_str()) < 0);

    do{
        value="";
        cout << "Digite o salario fixo: ";
        cin>>value;

        if(not validarFloat(value)) cout << "[i] : Numero invalido."<<endl;
        else{
            if(atof(value.c_str()) < 0) cout << "[i] : O salario nao pode ser negativo."<<endl;
            else vendedor.salario_fixo = atof(value.c_str());
        }
    }while(not validarFloat(value) or atof(value.c_str()) < 0);
    
}

void totalAReceber(Vendedor &v){
    v.total_a_receber = v.salario_fixo + (v.valor_venda+v.comissao);
}

void totalAReceberVet(unsigned x, Vendedor v[])
{
    for(unsigned i = 0; i<x; i++) totalAReceber(v[i]);
}

void relatorioFinal(unsigned x, Vendedor v[]){

    if(x > 0){
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
    }else{
        cout<<"Nenhuma venda registrada."<<endl;
    }
}

void lerLimNSup(unsigned s, unsigned f, unsigned &opcao){
    do{
        cout << "Faça sua escolha (max. "<<TMAX<<"): ";
        cin>>opcao;
    }while(opcao < s or opcao > f);
}