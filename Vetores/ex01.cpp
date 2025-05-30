#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double notas[20];
    string alunos[20];
    double mediaNotas = 0.0;
    int quantidadeAlunos = 0;
    char check;

    for (int i = 0; i < 20; i++) {
        cout << "[" << i + 1 << "] Digite o nome do aluno(a): ";
        cin.ignore();
        getline(cin, alunos[i]);

        cout << "[" << i + 1 << "] Digite a nota da prova: ";
        cin >> notas[i];
        mediaNotas += notas[i];
        quantidadeAlunos++;

        do {
            cout << "Deseja adicionar outro aluno? Restam " << 20 - (i + 1) << " vagas. [S/N]: ";
            cin >> check;
        } while (toupper(check) != 'S' && toupper(check) != 'N');

        if (toupper(check) == 'N') break;
    }

    if (quantidadeAlunos > 0) {
        double media = mediaNotas / quantidadeAlunos;

        cout << fixed << setprecision(2);
        cout << "\nA média das notas digitadas é de: " << media << endl;
        cout << "Relação das notas maiores ou iguais à média da turma:\n";

        int abaixoDaMedia = 0;

        for (int i = 0; i < quantidadeAlunos; i++) {
            if (notas[i] >= media) {
                cout << alunos[i] << " : " << notas[i] << endl;
            } else {
                abaixoDaMedia++;
            }
        }

        cout << "\nQuantidade de alunos com nota abaixo da média: " << abaixoDaMedia << endl;
    } else {
        cout << "Nenhum aluno foi registrado.\n";
    }

    return 0;
}
