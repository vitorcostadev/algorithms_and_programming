/*
Faça um programa que leia uma string no formato “DD/MM/AAAA” e copie o dia,
mês e ano para 3 variáveis inteiras. Antes disso, verifique se as barras estão no lugar
certo, e se DD, MM e AAAA são numéricos. 
*/

#include <iostream>
#include <cctype>


using namespace std;

int main()
{
    string data="";
    int dd,mm,yy;
    string d="",m="",y="";
    bool isValidDate=true;

    do{
        cout<<"Digite uma data (no formato DD/MM/YY): ";
        getline(cin, data);

    }while(data.empty());

    for(unsigned i = 0; i<data.size(); i++){
        if(
            not isdigit(data[0]) and
            not isdigit(data[1]) and
            not isdigit(data[3]) and
            not isdigit(data[4]) and
            not isdigit(data[6]) and
            not isdigit(data[7]) and
            data[0] == '-'){
            isValidDate=false;
            break;
        }else{
            // 2,5
            if(data[2] != '/' and data[5] != '/'){
                isValidDate=false;
                break;
            }
            d = {data[0],data[1]};
            m = {data[3], data[4]};
            y = {data[6], data[7]};
        }
    }

    if(isValidDate){
        dd=atoi(d.c_str());
        mm=atoi(m.c_str());
        yy=atoi(y.c_str());

        cout<<"A data eh valida!\n"<<dd<<"/"<<mm<<"/"<<yy<<endl;
    }else cout<<"A data inserida eh invalida.";

}