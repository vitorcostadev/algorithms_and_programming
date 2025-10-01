#include <iostream>
#include <cctype>
#define TMAX 2

using namespace std;

/*
3. Implemente um programa para ler os dados de vários funcionários (matrícula, nome,
cargo, departamento, data de admissão e salário) de uma empresa e gerar uma
relação daqueles que têm salários superiores à média geral de salários. O algoritmo
deve apresentar a seguinte mensagem: “Mais um funcionário: s(SIM) / n(NÃO)?”
antes de prosseguir com a entrada de dados. 
*/

typedef struct 
{
    int matricula;
    string nome,cargo,departamento,data;
    float salario;
} Funcionario;

//Chamada de funções
void salariosAcimaDaMediaGeral(
    float media, 
    unsigned x,
    unsigned &acima_size,
    Funcionario f[], 
    Funcionario acima[]
);
void calcularMediaGeral(unsigned x, Funcionario f[], float &media);
void entradaDeDados(unsigned x, Funcionario &f);
bool validarString(string nome);
bool validarInteiro(string numero);
bool validarData(string data);
bool validarFloat(string numero);
void menu(unsigned x, unsigned &acima_size, Funcionario f[], float media, Funcionario acima[]);
void relatorioFinal(unsigned x, unsigned acima_size, float media, Funcionario acima[]);

int main()
{
    Funcionario func[TMAX], acimaDaMediaGeral[TMAX];
    float media=0;
    unsigned acimaSize=0;

    menu(TMAX, acimaSize, func, media, acimaDaMediaGeral);
}

void salariosAcimaDaMediaGeral(float media, 
    unsigned x,
    unsigned &acima_size,
    Funcionario f[], 
    Funcionario acima[]
)
{
    for(unsigned i = 0; i < x; i++){
        if(f[i].salario > media){
            acima[acima_size] = f[i]; 
            acima_size++;
        }
    }
}

void calcularMediaGeral(unsigned x, Funcionario f[], float &media)
{
    for(unsigned i = 0; i<x; i++){
        media+=f[i].salario;
    }
    media /= x;
}

void entradaDeDados(unsigned x, Funcionario &f)
{
    string value="";
    do{
        cout << x+1<<": Digite a matricula: ";
        cin>>value;

        if(not validarInteiro(value)) cout << "Matricula invalida."<<endl;
        else f.matricula = atoi(value.c_str());

    }while(not validarInteiro(value));

    do{
        value="";
        cout << x+1<<": Digite o seu cargo: ";
        cin.ignore();
        getline(cin, value);

        if(not validarString(value)) cout << "Cargo escrito incorretamente."<<endl;
        else f.cargo = value;
    }while(not validarString(value));

    do{
        value="";
        cout << x+1<<": Digite o seu departamento: ";
        getline(cin, value);

        if(not validarString(value)) cout << "Departamento escrito incorretamente."<<endl;
        else f.departamento = value;
    }while(not validarString(value));

    do{
        value="";
        cout <<x+1<<": Digite o seu nome: ";
        getline(cin, value);

        if(not validarString(value)) cout << "Nome escrito incorretamente."<<endl;
        else f.nome = value;
    }while(not validarString(value));

    do{
        value="";
        cout <<x+1<<": Digite a data de admissao: ";
        cin>>value;

        if(not validarData(value)) cout << "Data escrita incorretamente."<<endl;
        else f.data = value;
    }while(not validarData(value));

    do{
        value="";
        cout <<x+1<<": Digite o seu salario: ";
        cin>>value;

        if(not validarFloat(value)) cout << "Salario escrito de maneira incorreta."<<endl;
        else f.salario = atof(value.c_str());
    }while(not validarFloat(value));

    cout << "\n";

}

bool validarString(string nome)
{
    if(nome.empty()) return false;

    for(unsigned i = 0; i < nome.size(); i++)
    {
        if(not isalpha(nome[i]) and nome[i] != ' ') return false;
    }

    return true;
}

bool validarInteiro(string numero)
{
    if(numero.empty()) return false;

    for(unsigned i = 0; i<numero.size(); i++)
    {
        if(not isdigit(numero[0]) and numero[0] != '-') return false;
        else{
            for(unsigned x = 1; x<numero.size(); x++){
                if(not isdigit(numero[x])) return false;
            }
        }
    }
    return true;
}

bool validarData(string data){
    if(data.empty()) return false;
    if(data.size() != 10) return false;
    //24/05/2024
    for(unsigned i = 0; i<data.size(); i++){
        if(not isdigit(data[i])){
            if(data[i] == '/' and i == 2 or i == 5) continue;
            else return false;
        }
    }
    return true;
}
bool validarFloat(string numero)
{
    if(numero.empty()) return false;

    short ponto = 0;
    for(unsigned i = 0; i<numero.size(); i++)
    {
        if(not isdigit(numero[0]) and numero[0] != '-') return false;
        else{
            for(unsigned x = 1; x<numero.size(); x++){
                if(not isdigit(numero[x]) and numero[x] == '.' and ponto==0) ponto++;
                else{
                    if(not isdigit(numero[x])) return false;
                }
            }
        }
    }
    return true;
}

void menu(unsigned x, unsigned &acima_size, Funcionario f[], float media, Funcionario acima[])
{
    char opcao;

    do{
        for(unsigned i = 0; i < x; i++){
            entradaDeDados(i, f[i]);
            cin.ignore();
        }
        calcularMediaGeral(x, f, media);
        salariosAcimaDaMediaGeral(media, x, acima_size, f, acima);
        relatorioFinal(x, acima_size, media, acima);

        cout << "Deseja repetir o processo? [S/N]: ";
        cin>>opcao;

    }while(tolower(opcao) == 's');
}

void relatorioFinal(unsigned x, unsigned acima_size, float media, Funcionario acima[]){

    cout<<"-- Media Geral: "<<media<<endl;
    cout<<"-- Funcionarios que ficaram acima da Media Geral: "<<endl;
    if(acima_size > 0){
        for(unsigned i = 0; i<acima_size; i++){
            cout<<"Nome: "<<acima[i].nome<<endl;
            cout<<"Cargo: "<<acima[i].cargo<<endl;
            cout<<"Departamento: "<<acima[i].departamento<<endl;
            cout<<"Matricula: "<<acima[i].matricula<<endl;
            cout<<"Data de admissao: "<<acima[i].data<<endl;
            cout<<"Salario: "<<acima[i].salario<<endl;
            cout<<"\n";
        
        }
    }else
        cout << "Nenhum."<<endl;
}