/*
Escreva um procedimento que insira um novo elemento em uma lista de valores inteiros, após a
primeira ocorrência do valor 80, caso exista este valor. 
*/

#include <iostream>
using namespace std; 

typedef struct Nodo{
    int value;
    struct Nodo *next;
} Int;

void insertAfter80(Int* &ptr, int value);
void deleteList(Int* &ptr);

int main(){
    Int* head = NULL;
    Int* second = NULL;
    Int* third = NULL;

    head = new Int();
    second = new Int();
    third = new Int();

    head->value = 10;
    head->next = second;
    second->value = 80;
    second->next = third;
    third->value = 30;
    third->next = NULL;
    insertAfter80(head, 50);
    Int* paux = head;
    while(paux != NULL){
        cout << paux->value << " ";
        paux = paux->next;
    }
    cout << endl;
    deleteList(head);
    return 0;
}
void insertAfter80(Int* &ptr, int value){
    Int* paux = ptr;

    while(paux != NULL and paux->value != 80){
        paux = paux->next;
    }
    if(paux != NULL){
        Int* newptr = new Int();
        newptr->value = value;
        newptr->next = paux->next;
        paux->next = newptr;

    }
}

void deleteList(Int* &ptr){
    Int* paux;
    while(ptr != NULL){
        paux = ptr;
        ptr = ptr->next;
        delete paux;
    }
}
