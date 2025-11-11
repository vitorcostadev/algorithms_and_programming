/*
6. Admita que os dados (matrícula, nome e salário) sobre os empregados de uma determinada empresa
devam ser armazenados em uma lista encadeada. Faça um algoritmo para ler os dados dos
empregados e criar a lista. Depois de criada, a lista deverá ser desmembrada em duas, a primeira
conterá somente as informações dos empregados que recebem salários até R$ 1.000,00 e a segunda,
com as informações daqueles que têm salários superiores a R$ 1.000,00. 
*/

#include <iostream>
using namespace std; 

typedef struct Nodo{
    string matricula, nome;
    double salario;
    struct Nodo *next;
} Empregado;

void inserirNoInicio(Empregado*&emp, string mat, string nome, double salario);
void desmembrarLista(Empregado*&emp, Empregado*&maior, Empregado*&Menor);
void varrerLista(Empregado*emp);
void deletarLista(Empregado*&emp);

int main(){
    Empregado *empregado=NULL, *maior=NULL, *menor=NULL;
    int value=0;
    string nome, matricula;
    double salario=0;

    do{
        cout << "Digite o nome do empregado: " ; cin >> nome;
        cout << "Digite a matricula do mesmo: "; cin >> matricula;
        cout << "Digite o salario do empregado: "; cin >> salario;
        inserirNoInicio(empregado, matricula, nome, salario);
        value++;
    }while(value<3);
    desmembrarLista(empregado, maior, menor);
    
    cout << "\nEmpregados com salario <= 1000:" << endl;
    varrerLista(menor);
    cout << "\nEmpregados com salario > 1000:" << endl;
    varrerLista(maior);

    deletarLista(empregado);
    deletarLista(maior);
    deletarLista(menor);

    return 0;
}
void inserirNoInicio(Empregado*&emp, string mat, string nome, double salario)
{
    Empregado *newemp = new Empregado();
    newemp->matricula = mat;
    newemp->nome = nome;
    newemp->salario = salario;
    newemp->next = emp;
    emp = newemp;
}

void desmembrarLista(Empregado*&emp, Empregado*&maior, Empregado*&Menor)
{
    Empregado *paux = emp;
    
    while(paux != NULL) {
        Empregado *temp = paux->next;  
        
        if(paux->salario <= 1000) {
            paux->next = Menor;
            Menor = paux;
        } else {
            paux->next = maior;
            maior = paux;
        }
        
        paux = temp; 
    }
    
    emp = NULL; 
}

void varrerLista(Empregado*emp)
{
    Empregado *paux = emp;
    while(paux != NULL){
        cout << "Matricula: " << paux->matricula << " || Nome: " << paux->nome << " || Salario: " << paux->salario << endl;
        paux = paux->next;
    }
}

void deletarLista(Empregado*&emp)
{
    Empregado *paux;
    while(emp != NULL){
        paux = emp;
        emp = emp->next;
        delete paux;
    }
}