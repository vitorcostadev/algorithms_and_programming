/*
Uma palavra palíndrome é uma cadeia de caracteres cuja leitura tem o mesmo sentido se feita da
direita para a esquerda ou vice-versa. Por exemplo, OSSO, OVO, RADAR, ... Ler n cadeias de
caracteres e determinar quais delas são palíndromes.
*/

#include <iostream>

using namespace std;

int main()
{
    string palavra="";
    bool isPalindrome=true;

    do{
        cout<<"Digite uma palavra: ";
        getline(cin, palavra);

    }while(palavra.empty());

    for(int i = 0; i<palavra.size()/2; i++){
        int j = palavra.size() - 1 - i;

        if(palavra[i] != palavra[j]){
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome) cout << "A palavra "<<palavra<<" eh palindrome.";
    else cout << "A palavra "<<palavra<<" nao eh palindrome.";
}