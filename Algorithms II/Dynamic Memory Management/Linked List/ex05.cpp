#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    string nome, matricula; 
} Pessoa;

typedef struct Nodo{
    Pessoa funcionario;
    vector<Pessoa> dependentes; 
    struct Nodo *prox;
}Lista;

void inserirNoFinal(Lista *&lista, Pessoa people){
    Lista *listaux = new Lista();
    listaux->funcionario = people;
    listaux->prox = NULL;

    if(lista == NULL){
        lista = listaux;
        return;
    }else{
        Lista *p = lista;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = listaux;
    }
}

bool dependInList(Lista* func, string nomeDependente){
    for (auto &d : func->dependentes){
        if (d.nome == nomeDependente) return true;
    }
    return false;
}

void distribuirDepend(
    Lista *&func, 
    Lista*&depend
){
    for(Lista *x = func; x != NULL; x = x->prox){

        for(Lista *k = depend; k != NULL; k = k->prox){

            if(x->funcionario.matricula == k->funcionario.matricula){

                if(!dependInList(x, k->funcionario.nome)){
                    x->dependentes.push_back(k->funcionario);
                }
            }
        }
    }
}

void relatorio(Lista*&func){
    Lista *aux = func;
    
    while(aux != NULL){
        cout << "Nome do funcionario: " << aux->funcionario.nome << endl;
        cout << "Matricula: " << aux->funcionario.matricula << endl;
        cout << "Dependentes:" << endl;

        if(aux->dependentes.size() > 0){
            for(unsigned i = 0; i < aux->dependentes.size(); i++){
                cout << aux->dependentes[i].nome << endl;
            }
        }
        else cout << "Sem dependentes." << endl;

        cout << endl;
        aux = aux->prox;
    }
}

void deletarList(Lista *&lista){
    Lista *aux = lista;
    while(aux != NULL){
        Lista *tmp = aux;
        aux = aux->prox;
        delete tmp;
    }
    lista = NULL;
}

int main(){
    Lista *lista = NULL, *depend = NULL;
    Pessoa funcionario, dependente;

    int opcao = 0;
    do{
        cout << "[1] : Adicionar Funcionario" << endl;
        cout << "[2] : Adicionar Dependente" << endl;
        cout << "[3] : Relatorio Geral" << endl;
        cout << "[4] : Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                cout << "Nome do funcionario...: "; cin.ignore(); getline(cin, funcionario.nome); 
                cout << "Matricula: "; cin >> funcionario.matricula;

                inserirNoFinal(lista, funcionario);
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "Nome do dependente...: "; cin.ignore(); getline(cin, dependente.nome); 
                cout << "Matricula do funcionario: "; cin >> dependente.matricula;

                inserirNoFinal(depend, dependente);
                system("pause");
                break;

            case 3:
                distribuirDepend(lista, depend);
                system("cls");
                relatorio(lista);
                system("pause");
                break;

            case 4:
                opcao = -1;
                break;
        }

    } while(opcao > -1);

    deletarList(lista);
    deletarList(depend);
    return 0;
}
