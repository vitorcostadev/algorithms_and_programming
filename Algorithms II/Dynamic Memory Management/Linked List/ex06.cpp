/*
Admita que os dados (matrícula, nome e salário) sobre os empregados de uma determinada empresa
devam ser armazenados em uma lista encadeada. Faça um algoritmo para ler os dados dos
empregados e criar a lista. Depois de criada, a lista deverá ser desmembrada em duas, a primeira
conterá somente as informações dos empregados que recebem salários até R$ 1.000,00 e a segunda,
com as informações daqueles que têm salários superiores a R$ 1.000,00.
*/

#include <iostream>
using namespace std;

typedef struct{
    string matricula, nome;
    float salario;
} Empregado;

typedef struct Nodo{
    Empregado empregado;
    struct Nodo *prox;
} List;

void inserirNoFinal(List *&lista, Empregado people){
    List *listaux = new List();
    listaux->empregado = people;
    listaux->prox = NULL;

    if(lista == NULL){
        lista = listaux;
        return;
    }else{
        List *p = lista;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = listaux;
    }
}
void separarEmpregados(List*&empabaixo, List*&empacima, List*&lista){
    for(List *aux = lista; aux!=NULL; aux=aux->prox){
        if(aux->empregado.salario <= 1000){
            inserirNoFinal(empabaixo, aux->empregado);
        }else{
            inserirNoFinal(empacima, aux->empregado);
        }
    }
}
void deletarList(List *&lista){
    List *aux = lista;
    while(aux != NULL){
        List *tmp = aux;
        aux = aux->prox;
        delete tmp;
    }
    lista = NULL;
}
void imprimirLista(List *&lista){
    List *aux = lista;
    while(aux!=NULL){
        cout << aux->empregado.nome << endl;
        cout << aux->empregado.matricula << endl;
        cout << aux->empregado.salario << endl;
        aux = aux->prox;
    }
}
int main(){
    List *empregados=NULL, *acimade1k=NULL, *abaixode1k=NULL;
    Empregado emp;
    int x=0;
    do{
        cout << "Digite o nome do empregado(a): "; getline(cin, emp.nome);
        cout << "Digite a matricula do mesmo: ";  cin>>emp.matricula; 
        cout << "Digite o salario: "; cin>>emp.salario;
        cin.ignore();
        inserirNoFinal(empregados, emp);
        x++;
    }while(x<4);
    separarEmpregados(abaixode1k, acimade1k, empregados);
    cout << "Empregados registrados: "<<endl; imprimirLista(empregados);
    cout << "Empregados abaixo de 1000 de salario: "<<endl; imprimirLista(abaixode1k);
    cout << "Empregados acima de 1000 de salario: "<<endl; imprimirLista(acimade1k);
    deletarList(empregados);
    deletarList(abaixode1k);
    deletarList(acimade1k);
    return 0;
}
