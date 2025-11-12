/*
7. Admita que em uma lista encadeada em memória estejam armazenados sexo, idade e salário de um
conjunto de pessoas. Elabore um procedimento recursivo que copie os elementos da lista para uma
variável estática unidimensional. 
*/

#include <iostream>
using namespace std;

typedef struct Nodo{
    char sexo;
    unsigned idade;
    double salario;
    struct Nodo *next;
} Pessoa;

void incluirNoInicio(Pessoa *&people, char sexo, unsigned idade, double salario);
void deletarLista(Pessoa*&people);
int main(){
    Pessoa *people = NULL;
    incluirNoInicio(people, 'M', 30, 2500.50);
    incluirNoInicio(people, 'F', 25, 3000.75);
    incluirNoInicio(people, 'M', 40, 4000.00);

    const int tamanho = 3;
    Pessoa arrayPessoas[tamanho];

    Pessoa *paux = people;
    int index = 0;
    while(paux != NULL and index < tamanho){
        arrayPessoas[index] = *paux;
        paux = paux->next;
        index++;
    }

    cout << "Conteudo do array estatico:" << endl;
    for(int i = 0; i < index; i++){
        cout << "Pessoa " << i+1 << ": Sexo: " << arrayPessoas[i].sexo
             << ", Idade: " << arrayPessoas[i].idade
             << ", Salario: " << arrayPessoas[i].salario << endl;
    }

    deletarLista(people);
    return 0;
}
void incluirNoInicio(Pessoa *&people, char sexo, unsigned idade, double salario)
{
    Pessoa*paux = new Pessoa();
    if(paux != NULL){
        paux->sexo = sexo;
        paux->idade = idade;
        paux->salario = salario;
        paux->next = people;
        people = paux;
    }
}

void deletarLista(Pessoa*&people){
    Pessoa*paux;
    while(paux != NULL){
        paux = people;
        people = people->next;
        delete paux;

    }
}