#include <iostream>
#include <cctype>

using namespace std;

int main(){
    bool validarFloat(string);
    bool validarInteiro(string);

    string n;
    do{
        cout << "Digite um numero inteiro: ";
        getline(cin, n);

        if(not validarInteiro(n)) cout << "Invalid number."<<endl;
    
    }while(not validarInteiro(n));

    cout << "String convertida para inteiro: " << atoi(n.c_str());
}

// Validar string para float
bool validarFloat(string num)
{
    if(num.size() == 0) return false;
    else if(num == "-0" or num == "-0.0") return false;

    bool result = true;
    for(unsigned i = 0; i<num.size(); i++)
    {
        if(not isdigit(num[0]) and num[0] != '-'){
            result = false; 
            break;
        }else{
            unsigned short ponto = 0;
            for(unsigned x = 1; x<num.size(); x++){
                if(not isdigit(num[x])){
                    if(num[x] == '.' and ponto == 0) ponto++;
                    else{
                        result = false;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

// Validar inteiro
bool validarInteiro(string num)
{
    if(num.size() == 0) return false;

    bool result = true;

    for(unsigned i = 0; i<num.size(); i++)
    {
        if(not isdigit(num[0]) and num[0] != '-'){
            result = false;
            break;
        }else{
            for(unsigned x = 1; x<num.size(); x++){
                if(not isdigit(num[x])){
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}