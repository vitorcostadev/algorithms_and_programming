#include <iostream>
#include <windows.h>
#define NMAX 10

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int X[NMAX];
    int n = 0;

    do {
        cout << "Quantos valores você deseja utilizar? ";
        cin >> n;
    } while (n < 1 || n > NMAX);

    for (int i = 0; i < n; i++) {
        cout << "X[" << i + 1 << "]: ";
        cin >> X[i];
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = X[i];
        X[i] = X[n - 1 - i];
        X[n - 1 - i] = temp;
    }

    cout << "[!] - VETOR COM AS POSIÇÕES TROCADAS - [!]"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "X["<<i+1<<"]: "<<X[i] << endl;
    }

    return 0;
}