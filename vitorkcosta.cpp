#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int controlador = 0;
    int switchControl = 0;
    int vendasProcessadas = 0;

    int repOneVendas = 0, repTwoVendas = 0, repThreeVendas = 0, repFourVendas = 0;
    int repOneComission = 0, repTwoComission = 0, repThreeComission = 0, repFourComission = 0;

    float repOneVendasValor = 0, repTwoVendasValor = 0, repThreeVendasValor = 0, repFourVendasValor = 0;
    float vendasValor = 0;

    int repMaisCapitalista = 0;
    int repMenosCapitalista = 0;

    while (true){
        cout << "\n== COMISSIONS SYSTEM ==\n[1] - Registrar uma nova venda\n[2] - Exibir total de vendas processadas\n[3] - Exibir total de comissões por representante\n[4] - Exibir total de comissões pagas pela empresa\n[5] - Vendedor com o maior valor de vendas\n[6] - Vendedor com a menor quantidade de itens vendidos\n[7] - Sair";
        do{
            cout << "\nFaça sua escolha: ";
            cin >> controlador;

            if(cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                controlador = 0;

                cout << "Entrada inválida, tente novamente.";
                continue;
            }

        }while(controlador < 1 || controlador > 7);

        switch(controlador){

            case 1:{
                int vendas;
                float vendasIndividual;
                int comissionPer;

                do{
                    cout << "Olá, aqui é a seção de registro de novas vendas.\n\nPor favor, informe o código do representante (1 a 4): ";
                    cin >> switchControl;

                    if (cin.fail() || switchControl < 1 || switchControl > 4){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Entrada inválida, tente novamente." << endl;
                        switchControl = 0;
                    }
                }while (switchControl < 1 || switchControl > 4);

                cout << "Quantidade de itens vendidos: ";
                cin >> vendas;
                cin.clear();

                cout << "Informe o valor total da venda: ";
                cin >> vendasIndividual;
                cin.clear();

                vendasProcessadas++;
                vendasValor += vendasIndividual;

                if (switchControl == 1){
                    repOneVendas += vendas;
                    repOneVendasValor += vendasIndividual;
                } else if(switchControl == 2){
                    repTwoVendas += vendas;
                    repTwoVendasValor += vendasIndividual;
                } else if(switchControl == 3){
                    repThreeVendas += vendas;
                    repThreeVendasValor += vendasIndividual;
                } else {
                    repFourVendas += vendas;
                    repFourVendasValor += vendasIndividual;
                }

                if (vendas >= 75){
                    comissionPer = 25;
                } else if(vendas >= 50){
                    comissionPer = 20;
                } else if(vendas >=20){
                    comissionPer = 15;
                } else {
                    comissionPer = 10;
                }

                if (switchControl == 1){
                    repOneComission += comissionPer;
                } else if(switchControl == 2){
                    repTwoComission += comissionPer;
                } else if(switchControl == 3){
                    repThreeComission += comissionPer;
                } else {
                    repFourComission += comissionPer;
                }

                cout << "\nResumo da venda:\n";
                cout << "Código do representante: " << switchControl << endl;
                cout << "Itens vendidos: " << vendas << endl;
                cout << "Valor total da venda: R$ " << vendasIndividual << endl;
                cout << "Comissão aplicada: " << comissionPer << "%" << endl;
                cout << "Valor total com comissão: R$ " << vendasIndividual + (vendasIndividual * (comissionPer / 100.0f)) << endl;

                if (repOneVendasValor >= repTwoVendasValor && repOneVendasValor >= repThreeVendasValor && repOneVendasValor >= repFourVendasValor) {
                    repMaisCapitalista = 1;
                } else if (repTwoVendasValor >= repOneVendasValor && repTwoVendasValor >= repThreeVendasValor && repTwoVendasValor >= repFourVendasValor) {
                    repMaisCapitalista = 2;
                } else if (repThreeVendasValor >= repOneVendasValor && repThreeVendasValor >= repTwoVendasValor && repThreeVendasValor >= repFourVendasValor) {
                    repMaisCapitalista = 3;
                } else {
                    repMaisCapitalista = 4;
                }

                if (repOneVendas <= repTwoVendas && repOneVendas <= repThreeVendas && repOneVendas <= repFourVendas) {
                    repMenosCapitalista = 1;
                } else if (repTwoVendas <= repOneVendas && repTwoVendas <= repThreeVendas && repTwoVendas <= repFourVendas) {
                    repMenosCapitalista = 2;
                } else if (repThreeVendas <= repOneVendas && repThreeVendas <= repTwoVendas && repThreeVendas <= repFourVendas) {
                    repMenosCapitalista = 3;
                } else {
                    repMenosCapitalista = 4;
                }

                break;
            }

            case 2:
                cout << "Total de vendas processadas: " << vendasProcessadas << endl;
                break;

            case 3:
                cout << "Total de comissões por representante:\n";
                cout << "- Representante 1: " << repOneComission << "%\n";
                cout << "- Representante 2: " << repTwoComission << "%\n";
                cout << "- Representante 3: " << repThreeComission << "%\n";
                cout << "- Representante 4: " << repFourComission << "%\n";
                break;

            case 4:
                cout << "Total de comissões pagas pela empresa: " 
                     << (repOneComission + repTwoComission + repThreeComission + repFourComission) << "%" << endl;
                break;

            case 5:
                if(repMaisCapitalista == 0){
                    cout << "Nenhuma venda registrada ainda." << endl;
                } else {
                    cout << "O representante que mais vendeu foi o número " << repMaisCapitalista << " com valor total de vendas: R$ ";
                    if (repMaisCapitalista == 1) cout << repOneVendasValor << endl;
                    else if (repMaisCapitalista == 2) cout << repTwoVendasValor << endl;
                    else if (repMaisCapitalista == 3) cout << repThreeVendasValor << endl;
                    else cout << repFourVendasValor << endl;
                }
                break;

            case 6:
                if(repMenosCapitalista == 0){
                    cout << "Nenhuma venda registrada ainda." << endl;
                } else {
                    cout << "O representante que menos vendeu em quantidade de itens foi o número " << repMenosCapitalista << " com total de itens vendidos: ";
                    if (repMenosCapitalista == 1) cout << repOneVendas << endl;
                    else if (repMenosCapitalista == 2) cout << repTwoVendas << endl;
                    else if (repMenosCapitalista == 3) cout << repThreeVendas << endl;
                    else cout << repFourVendas << endl;
                }
                break;

            case 7:
                cout << "Encerrando o programa..." << endl;
                exit(0);
        }
    }
}
