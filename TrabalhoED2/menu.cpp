#include "menu.h"
#include "Arvore.h"
#include "file.h"
#include "utils.h"
#include <iostream>

using namespace std;


int interfaceMenu() {

    int opcao;
    cout << "\n\n               TESTE";
    cout << "\n-------------------------------------------------";
    cout << "\n\n\t1. Carregar livro.";
    cout << "\n\t2. Buscar palavra.";
    cout << "\n\t0. Sair.";
    cout << "\n\n\tEntre com a opção desejada: ";
    cin >> opcao;
    return opcao;

}

void menu(No* palavras) {
    int opcao_menu = -1;
    string palavra;
    while (opcao_menu != 0) {
        opcao_menu = interfaceMenu();
        switch (opcao_menu) {
        case 1:
            system("cls");
            cout << "\nPara adicionar livros à sua Árvore Binária Balanceada, coloque-os na pasta /Livros.";
            cout << "\nAperte ENTER para retornar ao menu anterior.";
            getchar();
            break;
        case 2:
            cout << "\n\tDigite a palavra desejada para obter mais informações: ";
            cin >> palavra;
            palavra = deixarGrandao(palavra);
            procurar(palavra, palavras);
            break;
        case 0:
            cout << "\n\n\nSaindo...\n\n";
            exit(0);
            break;
        default:
            system("cls");
            cout << "ESCOLHA INVÁLIDA TENTE NOVAMENTE.";
            break;
        }
    }
}