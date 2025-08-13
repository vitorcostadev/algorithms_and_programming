/*
7) Leia uma matriz quadrada de ordem n (3<=n<=10, faça validação) de
elementos inteiros. Após a leitura:
a) calcule e mostre a soma dos elementos que estão na diagonal principal;
b) calcule e mostre a soma dos elementos que estão acima da diagonal
principal;
c) calcule o produto dos elementos de cada linha e armazene em um vetor,
após mostre o vetor;
d) calcule a soma dos elementos de cada coluna e armazene em um vetor,
após mostre o vetor; e
e) gere e mostre a matriz transposta desta matriz. 
*/

#include <iostream>
#include <windows.h>
#define TMAX 10 

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int matriz[TMAX][TMAX], n=0;

    do{
        cout<<"Digite a quantidade de linhas e colunas da matriz (deve ser quadrada): ";
        cin >> n;
        if(n < 3) cout << "A matriz precisa ser no minimo de ordem 3."<<endl;
    }while(n<3 || n > TMAX);

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "Digite a posição da matriz["<<i+1<<","<<j+1<<"]: ";
            cin >> matriz[i][j];
        }
    }

    int diagonalPrincipal=0;
    //Soma da diagonal principal i=j
     for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) diagonalPrincipal += matriz[i][j];
        }
    }

    // Soma dos numeros acima da diagonal principal i==j+1
    int somaNumAcimaDP=0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            somaNumAcimaDP+=matriz[i][j];
        }
    
    }

    // Produto de cada col
    int vetorProd[TMAX], aux=0;
    for(int i = 0; i<n; i++){
        vetorProd[aux] = 1;
        for(int j=0; j<n; j++){
            vetorProd[aux] *= matriz[i][j];
        }
        aux+=1;
    }

    // Soma de cada col
    int vetorSoma[TMAX], aux2=0;
    for(int i = 0; i<n; i++){
        vetorSoma[aux2] = 0;
        for(int j=0; j<n; j++){
            vetorSoma[aux2] += matriz[i][j];
        }
        aux2+=1;
    }

    //Transposta
    int matrizTransposta[TMAX][TMAX];
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            matrizTransposta[j][i] = matriz[i][j];
        }
    }

    cout<<">> Soma da diagonal principal: "<<diagonalPrincipal<<endl;
    cout<<">> Soma dos números acima da diagonal principal: "<<somaNumAcimaDP<<endl;
    cout<<">> Produto de cada linha: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<"["<<vetorProd[i]<<"] "<<endl;
    }
    cout<<">> Soma de cada linha: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<"["<<vetorSoma[i]<<"] "<<endl;
    }
    cout<<">> Matriz transposta: "<<endl;
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "transposta["<<i+1<<","<<j+1<<"]: "<<matrizTransposta[i][j]<<endl;
        }
    }
} 