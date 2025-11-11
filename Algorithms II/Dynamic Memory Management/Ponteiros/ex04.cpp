/*
4. Escreva um procedimento que elimine a primeira ocorrência de um determinado valor de uma lista de
valores inteiros. 
*/

#include <iostream>
using namespace std;

typedef struct Nodo{
    int value;
    struct Nodo *next;
} Ptr;

void removerValor(Ptr *&head, int value);
void deleteList(Ptr*&head);
int main(){
    Ptr *head = NULL;
    Ptr *newptr;
    int n;

    do{
        cout << "Digite valores inteiros (-1 para parar): ";
        cin >> n;
        if(n!=-1){
            newptr = new Ptr;
            newptr->value = n;
            if(head == NULL){
                head = newptr;
                newptr->next = NULL;
            }else{
                Ptr *paux = head;
                while(paux->next != NULL){
                    paux = paux->next;
                }
                paux->next = newptr;
                newptr->next = NULL;
            }
        }
    }while(n!=-1);
    int valorRemover;
    cout << "Digite o valor a ser removido: ";
    cin >> valorRemover;
    removerValor(head, valorRemover);
    deleteList(head);
    return 0;
}

void removerValor(Ptr *&head, int value){
    Ptr *paux = head; 

    while(paux != NULL and paux->value != value){
        paux=paux->next;
    }
    if(paux != NULL){
        Ptr* paux2 = paux;
        paux = paux->next;
        delete paux2;
    }
}

void deleteList(Ptr*&head){
    Ptr* paux;
    while(head != NULL){
        paux = head;
        head = head->next;
        delete paux;
    }
}