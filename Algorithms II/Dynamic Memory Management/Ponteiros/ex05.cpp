#include <iostream>
using namespace std;

typedef struct Nodo{
    string nome, matricula;
    struct Nodo *prox;
} Pessoa;

void inserirNoInicio(Pessoa* &p, string nome, string matricula);
void deletarLista(Pessoa* &p);
void gerarRelatorio(Pessoa* func, Pessoa* dep);

int main(){
    Pessoa* funcionarios = NULL;
    Pessoa* dependentes = NULL;

    inserirNoInicio(funcionarios, "Joao Silva", "12345");
    inserirNoInicio(funcionarios, "Maria Souza", "67890");
    inserirNoInicio(dependentes, "Ana Silva", "12345");
    inserirNoInicio(dependentes, "Carlos Souza", "67890");
    inserirNoInicio(dependentes, "Beatriz Souza", "67890");

    gerarRelatorio(funcionarios, dependentes);

    deletarLista(funcionarios);
    deletarLista(dependentes);
    return 0;
}
void inserirNoInicio(Pessoa* &p, string nome, string matricula){
    Pessoa* paux = new Pessoa();
    paux->nome = nome;
    paux->matricula = matricula;
    paux->prox = p;
    p = paux;
}

void deletarLista(Pessoa* &p){
    Pessoa* paux;
    while(p!=NULL){
        paux = p;
        p = p->prox;
        delete paux;
    }
}

void gerarRelatorio(Pessoa* func, Pessoa* dep){
    Pessoa* paux;

    while(func!=NULL){
        cout << "Nome: "<<func->nome<<" - Matricula: "<<func->matricula<<endl;
        cout << "Dependentes: "<<endl;
        paux = dep;
        while(dep!=NULL and dep->matricula != func->matricula){
            dep=dep->prox;
        }
        if(dep!=NULL){
            while(dep!=NULL and dep->matricula == func->matricula){
                cout<<"  - "<<dep->nome<<" - Matricula: "<<dep->matricula<<endl;
                dep=dep->prox;
            }
        } else {
            cout << "  Nenhum dependente cadastrado."<<endl;
        }
        func = func->prox;
        dep = paux;
    }
}