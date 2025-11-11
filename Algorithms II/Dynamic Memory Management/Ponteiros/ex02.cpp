#include <iostream>
using namespace std;

/*
Faça uma função que retorne o endereço de um elemento qualquer em uma lista encadeada de
strings. Caso o elemento não esteja na lista, a função deverá retornar nulo.
*/

typedef struct Nodo{
    string value;
    struct Nodo *next;
} Str;

Str* findElement(Str* ptr, string value);

int main(){
    Str* head = new Str();
    head->value = "First";
    head->next = new Str();
    head->next->value = "Second";
    head->next->next = new Str();
    head->next->next->value = "Third";
    head->next->next->next = NULL;

    string searchValue = "Second";
    Str* result = findElement(head, searchValue);
    if(result != NULL)
        cout << "Element found: " << result->value << endl;
    else
        cout << "Element not found." << endl;

    Str* current = head;
    while(current != NULL) {
        Str* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
Str* findElement(Str* ptr, string value)
{
    Str* paux = ptr;
    while(paux != NULL and paux->value != value)
    {
        paux = paux->next;
    }
    return paux;
}

