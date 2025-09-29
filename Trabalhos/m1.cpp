/*
Revisao incompleta, apresenta pequenos erros de logica ao
cadastrar veiculos e alguma situações onde chama 'spam' de cout's.

Nota: 8.5
*/

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;


bool validarPlaca(string);
bool validarAno(string);
bool validarInt(string);
void incluirNovoVeiculo(unsigned &t, string[], string[], unsigned[], unsigned[]);
void consultarVeiculo(unsigned, string[], unsigned[], string[], unsigned[]);
void ordenarPlaca(unsigned, string[], string[], unsigned[], unsigned[]); // corrigido nome
void relatorioFrota(unsigned, string[], string[], unsigned[], unsigned[]);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string placa, ano, modelo, km;
    unsigned t = 1;
    unsigned ano_t[t], km_t[t];
    string placa_t[t], modelo_t[t];

    ordenarPlaca(t, placa_t, modelo_t, ano_t, km_t); // corrigido nome

    unsigned opcao;
    do {
        do {
            cout << "------------ LOCADORA DE VEICULOS ---------------" << endl;
            cout << "[1] : Incluir novo veiculo" << endl;
            cout << "[2] : Consultar veiculo cadastrado (pela placa)" << endl;
            cout << "[3] : Relatorio dos veiculos cadastrados" << endl;
            cout << "[4] : Sair" << endl;
            cout << "--------------------------------------------------" << endl;
            cin >> opcao;

            if (opcao < 1 or opcao > 4) cout << "Opção inválida." << endl;
            else {
                switch (opcao) {
                    case 1:
                        incluirNovoVeiculo(t, placa_t, modelo_t, ano_t, km_t);
                        break;
                    case 2:
                        consultarVeiculo(t, placa_t, km_t, modelo_t, ano_t);
                        break;
                    case 3:
                        relatorioFrota(t, placa_t, modelo_t, ano_t, km_t);
                        break;
                    case 4:
                        break;
                }
            }
        } while (opcao < 1 or opcao > 4);

    } while (opcao != 4);

    return 0;
}

bool validarPlaca(string placa) {
    if (placa.size() == 0 or placa.size() != 7) return false;

    bool valida = true;
    for (unsigned i = 0; i < placa.size(); i++) {
        if (not isalpha(placa[0]) and not isalpha(placa[1]) and not isalpha(placa[2])) {
            valida = false;
            break;
        } else {
            for (unsigned x = 0; x < placa.size(); x++) {
                if (not isdigit(placa[x]) and not isalpha(placa[x + 1])) {
                    valida = false;
                    break;
                } else {
                    if (not isdigit(placa[x])) {
                        valida = true;
                        break;
                    }
                }
            }
        }
    }
    return valida;
}

bool validarAno(string ano) {
    if (ano.size() == 0 or ano.size() != 4) return false;
    for (unsigned i = 0; i < ano.size(); i++) {
        if (not isdigit(ano[i])) {
            return false;
        }
    }
    return true;
}

bool validarInt(string inteiro) {
    if (inteiro.size() == 0) return false;

    for (int i = 0; i < inteiro.size(); i++) {
        if (not isdigit(inteiro[i])) {
            return false;
        }
    }
    return true;
}

void incluirNovoVeiculo(
    unsigned &t,  
    string placaT[], 
    string modeloT[], 
    unsigned anoT[], 
    unsigned kmT[]
) {
    string placa;
    string ano;
    string km;
    string modelo;
    unsigned n = 0;

    while (true) {
        do {
            cout << "Digite uma placa: ";
            cin.ignore();
            getline(cin, placa);

            if (not validarPlaca(placa)) cout << "A placa digitada é inválida." << endl;
        } while (not validarPlaca(placa));

        if (placaT[n] == placa) {
            cout << "Veiculo já cadastrado." << endl;
            n++;
            continue;
        } else {
            placaT[n] = placa;
            do {
                cout << "---------------- CADASTRAR VEICULO ---------------" << endl;
                cout << "Digite o modelo/marca do carro: " << endl;
                getline(cin, modelo);
                modeloT[n] = modelo;

                do {
                    cout << "Digite o ano do carro: ";
                    cin >> ano;
                    anoT[n] = atoi(ano.c_str());
                } while (not validarAno(ano) or atoi(ano.c_str()) < 0);

                do {
                    cout << "Digite a quilometragem do carro: ";
                    cin >> km;
                    kmT[n] = atoi(km.c_str());
                } while (not validarInt(km));

            } while (modelo.size() == 0);
            break;
        }
    }
    cout << "Inclusão confirmada." << endl;
    t++;
}

void consultarVeiculo(
    unsigned t, 
    string placaT[], 
    unsigned kmT[], 
    string modeloT[], 
    unsigned anoT[]
) {
    string placa;
    while (true) {
        do {
            cout << "Digite uma placa: ";
            cin.ignore();
            getline(cin, placa);

            if (not validarPlaca(placa)) cout << "A placa digitada é inválida." << endl;
        } while (not validarPlaca(placa));

        for (unsigned i = 0; i < t; i++) {
            if (placaT[i] == placa) {
                cout << "Modelo/marca do veiculo: " << modeloT[i] << endl;
                cout << "Placa do veiculo: " << placa << endl;
                cout << "Ano de fabricação: " << anoT[i] << endl;
                cout << "Quilometragem do veiculo: " << kmT[i] << endl;
                break;
            } else {
                cout << "Veiculo inexistente." << endl;
                break;
            }
        }
        break;
    }
}
// corrigido apos o envio
void ordenarPlaca(
    unsigned t, 
    string placaT[], 
    string modeloT[], 
    unsigned anoT[], 
    unsigned kmT[]
) {
    for (unsigned i = 0; i < t - 1; i++) {
        for (unsigned j = i + 1; j < t; j++) {
            if (placaT[i] > placaT[j]) {
                swap(placaT[i], placaT[j]);
                swap(modeloT[i], modeloT[j]);
                swap(anoT[i], anoT[j]);
                swap(kmT[i], kmT[j]);
            }
        }
    }
}

void relatorioFrota(
    unsigned t, 
    string placaT[], 
    string modeloT[], 
    unsigned anoT[], 
    unsigned kmT[]
) {
   if(t<=1) cout << "Nenhum veiculo cadastrado."<<endl;
   else{ // 
        for (unsigned i = 0; i < t-1; i++) {
            cout << "Modelo/marca do veiculo: " << modeloT[i] << endl;
            cout << "Placa do veiculo: " << placaT[i] << endl;
            cout << "Ano de fabricação: " << anoT[i] << endl;
            cout << "Quilometragem do veiculo: " << kmT[i] << endl;
            cout << "-------------------------------------------------" << endl;
        }
   }
}
