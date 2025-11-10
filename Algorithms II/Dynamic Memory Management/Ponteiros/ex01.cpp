/*
1. Considerando nome e peso de um número qualquer de pessoas, elabore funções e procedimentos
para i) armazenar em uma estrutura de lista encadeada essas informações; ii) calcular e escrever o
peso médio; iii) escrever o nome das pessoas com peso inferior a 50kg e iv) verificar se uma
determinada pessoa está representada na lista.
*/

#include <iostream>
#include <cctype>

using namespace std;

typedef struct Nodo{
    string nome;
    float peso;
    struct Nodo *next;
} Pessoa;

void inserirNoInicio(Pessoa* &p, string nome, float peso);
void deletarLista(Pessoa* &p);
float calcularPesoMedio(Pessoa* p);
void calcularPesoInf50(Pessoa* p);
bool findPeopleInList(Pessoa* p, string nome);

int main(){
    Pessoa* pessoas = NULL;
    int opcao;

    do{
        cout<<"1 - Inserir pessoa\n2 - Calcular peso medio\n3 - Listar pessoas com peso inferior a 50kg\n4 - Verificar se pessoa esta na lista\n0 - Sair\nOpcao: ";
        cin>>opcao;
        switch(opcao){
            case 1:{
                system("cls");
                string nome; float peso;
                cin.ignore();
                cout<<"Nome: "; getline(cin, nome);
                cout<<"Peso: "; cin>>peso;
                inserirNoInicio(pessoas, nome, peso);
                break;
            }
            case 2:{
                float media = calcularPesoMedio(pessoas);
                if(media != -1) cout<<"Peso medio: "<<media<<endl;
                else cout<<"Lista vazia!"<<endl;
                break;
            }
            case 3:{
                cout<<"Pessoas com peso inferior a 50kg:"<<endl;
                calcularPesoInf50(pessoas);
                break;
            }
            case 4:{
                string nome;
                cout<<"Nome da pessoa a verificar: "; cin>>nome;
                if(findPeopleInList(pessoas, nome)){
                    cout<<nome<<" encontrado na lista!"<<endl;
                } else {
                    cout<<nome<<" nao encontrada na lista!"<<endl;
                }
                break;
            }
        }
    }
    while(opcao != 0);
    deletarLista(pessoas);
    return 0;
}

void deletarLista(Pessoa* &p){
    Pessoa *paux;
    while(p != NULL){
        paux = p;
        p = p->next;
        delete paux;
    }
}

void inserirNoInicio(Pessoa* &p, string nome, float peso){
    Pessoa* paux = new Pessoa();
    paux->nome = nome;
    paux->peso = peso;
    paux->next = p;
    p = paux;
}

float calcularPesoMedio(Pessoa* p)
{
    float media=0;
    int people_qty=0;
    while(p!=NULL){
        people_qty++; media += p->peso;
        p=p->next;
    }
    if(people_qty > 0) return media/people_qty;
    return -1;
}

void calcularPesoInf50(Pessoa* p)
{
    while(p!=NULL)
    {
        if(p->peso <= 50) cout << "- Nome: " << p->nome << " || Peso: "<<p->peso<<endl;
        p=p->next;
    }
}

bool findPeopleInList(Pessoa* p, string nome){
    if(nome.size() == 0) return false;

    for(unsigned i = 0; i<nome.size(); i++){
        nome[i] = tolower(nome[i]);
    }
    for(unsigned i = 0; i<p->nome.size(); i++){
        p->nome[i] = tolower(p->nome[i]);
    }

    while(p!=NULL and p->nome != nome){
        p=p->next;
    }
    if(p != NULL){
        return true;
    }
    return false;
}