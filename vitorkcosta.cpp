#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
/*
A Fábrica Alfa trabalha com 4 representantes comerciais (identificados pelos códigos de 1 a 4), que
registram os pedidos de venda de produtos. Cada pedido possui:

• O código do representante;
• O número de itens vendidos;
• O valor total da venda.

A comissão de cada representante é calculada com base na quantidade de itens vendidos:
• Menos de 20 itens: 10%;
• De 20 a 49 itens: 15%;
• De 50 a 74 itens: 20%;
• 75 itens ou mais: 25%.

O sistema deve apresentar o seguinte menu:

==== MENU - SISTEMA DE COMISSOES ====
1 – Registrar nova venda
2 – Exibir total de vendas processadas
3 – Exibir total de comissões por representante
4 – Exibir total de comissões pagas pela empresa
5 – Vendedor com o maior valor de vendas
6 – Vendedor com a menor quantidade de itens vendidos
7 – Sair

Funcionamento esperado:
• Ao escolher opção 1, o usuário deve informar os dados de uma nova venda (representante, itens, valor
da venda). O programa deve:

o calcular a comissão da venda;
o exibir o valor da comissão daquela venda;
o voltar ao menu principal.

• As opções 2, 3 e 4 devem exibir:
o (2): o total acumulado de vendas processadas.
o (3): o total de comissões recebidas por cada representante (1 a 4).
o (4): o total geral de comissões pagas pela fábrica.
o (5): o vendedor que realizou o maior valor de vendas, juntamente com o valor de vendas.
o (6): o vendedor que realizou a menor quantidade de itens vendidos, juntamente com a quantidade de
itens.
E voltar ao menu principal após cada “relatório” gerado na tela.
• A opção 7 encerra o programa. 
*/

    int controlador = 0;
    int switchControl = 0;
    int vendasProcessadas = 0;
    int repOneVendasQty = 0, repTwoVendasQty = 0, repThreeVendasQty = 0, repFourVendasQty = 0;
    int repOneVendas = 0, repTwoVendas = 0, repThreeVendas = 0, repFourVendas = 0;
    int repMaisCapitalista = 0;
    int repMenosCapitalista = 0;
    int vendas = 0;
    int comissionPer = 0;
    int repOneComission = 0, repTwoComission = 0, repThreeComission = 0, repFourComission = 0;
    
    float vendasValor = 0;
    float vendasIndividual = 0;
    
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

            case 1:
                do{
                    cout << "Olá, aqui é a seção de registro de novas vendas.\n\n Por favor, informe os seguintes dados:\n- Código do representante (1 a 4)\n- Número de itens vendidos\n- Valor total da venda\n";
                    cout << "\n[1] : Informe o código de representante: \n";
                    cin >> switchControl;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        switchControl = 0;

                        cout << "Entrada inválida, tente novamente.";
                        continue;
                    }else{

                        vendasProcessadas++;

                        switch(switchControl){
                            case 1: repOneVendasQty++; break;
                            case 2: repTwoVendasQty++; break;
                            case 3: repThreeVendasQty++; break;
                            case 4: repFourVendasQty++; break;
                        }
                    }
                }while (switchControl < 1 || switchControl > 4);

                cout << "[2] : Quantidade de itens vendidos: ";
                cin >> vendas;
                cin.clear();
                
                if (switchControl == 1){repOneVendas += vendas;}else if(switchControl == 2){repTwoVendas += vendas;}else if(switchControl == 3){repThreeVendas+=vendas;}else{repFourVendas+= vendas;}

                cout << "[3] : Informe o valor total da venda: ";
                cin >> vendasIndividual;
                cin.clear();

                vendasValor += vendasIndividual;

                cout << "Resumo da venda\n\n";
                cout << "Código do representante: "<<to_string(switchControl)<<endl;
                cout << "Vendas totais: "<<to_string(vendas) << " itens."<<endl;

                if (vendas >= 75){
                    comissionPer = 25;
                }else if(vendas >= 50){
                    comissionPer = 20;
                }else if(vendas >=20){
                    comissionPer = 15;
                }else{
                    comissionPer = 10;
                }

                if (switchControl == 1){
                    repOneComission += comissionPer;
                }else if(switchControl == 2){
                    repTwoComission += comissionPer;
                }else if(switchControl == 3){
                    repThreeComission += comissionPer;
                }else{repFourComission+=comissionPer;}

                cout << "Comissão aplicada: "<<to_string(comissionPer)<<"%"<<endl;
                cout << "Valor total sem comissão: "<<to_string(vendasIndividual)<<endl;
                cout << "Valor total com comissão: "<<to_string(vendasIndividual+(vendasIndividual*(comissionPer/100.0f)))<<endl;
                
                if (repOneVendasQty >= repTwoVendasQty && repOneVendasQty >= repThreeVendasQty && repOneVendasQty >= repFourVendasQty) {
                    repMaisCapitalista = 1;
                }
                else if (repTwoVendasQty >= repOneVendasQty && repTwoVendasQty >= repThreeVendasQty && repTwoVendasQty >= repFourVendasQty) {
                    repMaisCapitalista = 2;
                }
                else if (repThreeVendasQty >= repOneVendasQty && repThreeVendasQty >= repTwoVendasQty && repThreeVendasQty >= repFourVendasQty) {
                    repMaisCapitalista = 3;
                }
                else {
                    repMaisCapitalista = 4;
                }

                if (repOneVendasQty <= repTwoVendasQty && repOneVendasQty <= repThreeVendasQty && repOneVendasQty <= repFourVendasQty) {
                    repMenosCapitalista = 1;
                }
                else if (repTwoVendasQty <= repOneVendasQty && repTwoVendasQty <= repThreeVendasQty && repTwoVendasQty <= repFourVendasQty) {
                    repMenosCapitalista = 2;
                }
                else if (repThreeVendasQty <= repOneVendasQty && repThreeVendasQty <= repTwoVendasQty && repThreeVendasQty <= repFourVendasQty) {
                    repMenosCapitalista = 3;
                }
                else {
                    repMenosCapitalista = 4;
                }
                break;
            
            case 2:
                cout << "A quantidade de vendas processadas foram de: "<<to_string(vendasProcessadas)<<endl;
                break;
            case 3:
                cout << "Total de comissões recebidas por cada representante: \n\n";
                cout << "- Representante 01: +"<<to_string(repOneComission)<<"%"<<" de comissão."<<endl;
                cout << "- Representante 02: +"<<to_string(repTwoComission)<<"%"<<" de comissão."<<endl;
                cout << "- Representante 03: +"<<to_string(repThreeComission)<<"%"<<" de comissão."<<endl;
                cout << "- Representante 04: +"<<to_string(repFourComission)<<"%"<<" de comissão."<<endl;
                break;
            case 4:
                cout << "A fábrica no total pagou cerca de +"<<to_string(repOneComission+repTwoComission+repThreeComission+repFourComission)<<"%"<<" de taxas em comissões."<<endl;
                break;
            case 5:
                cout << "O representante que mais vendeu foi o de número 0"<<to_string(repMaisCapitalista)<<"!"<<endl;
                if (repMaisCapitalista == 1){
                    cout<<"Ele vendeu cerca de "<<to_string(repOneVendas)<<" itens!"<<endl;
                }else if(repMaisCapitalista == 2){
                    cout<<"Ele vendeu cerca de "<<to_string(repTwoVendas)<<" itens!"<<endl;
                }else if(repMaisCapitalista == 3){
                    cout<<"Ele vendeu cerca de "<<to_string(repThreeVendas)<<" itens!"<<endl;
                }else{
                    cout<<"Ele vendeu cerca de "<<to_string(repFourVendas)<<" itens!"<<endl;
                }
                break;
            case 6:
                cout<<"O vendedor que menos vendeu foi o de número 0"<<to_string(repMenosCapitalista)<<endl;
                if (repMenosCapitalista == 1){
                    cout<<"Ele vendeu cerca de "<<to_string(repOneVendas)<<" itens!"<<endl;
                }else if(repMenosCapitalista == 2){
                    cout<<"Ele vendeu cerca de "<<to_string(repTwoVendas)<<" itens!"<<endl;
                }else if(repMenosCapitalista == 3){
                    cout<<"Ele vendeu cerca de "<<to_string(repThreeVendas)<<" itens!"<<endl;
                }else{
                    cout<<"Ele vendeu cerca de "<<to_string(repFourVendas)<<" itens!"<<endl;
                }
                break;
            case 7:
                cout<<"Encerrando o programa..."<<endl;
                exit(0);
        }
}

}