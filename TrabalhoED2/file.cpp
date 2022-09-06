#include "utils.h"
#include <fstream>
#include <iostream>
#include <string>
#include "file.h"
#include <windows.h>

using namespace std;

void lerArquivo(string nome, int indexLivro,No*& palavras) {

   
    string linha;
    int qtdLinhas = 0;
    int cont = 0;

    ifstream meuArquivo(nome);

    if (!meuArquivo.is_open()) {
        cout << "Erro ao abrir arquivo.\n";
    }
    else {
        while (getline(meuArquivo, linha)) {
       
            qtdLinhas++;
            if (linha.length() != 0) {
                tokenize(&cont, linha, qtdLinhas, indexLivro, palavras, " ");
                //cout << endl;
            }

        }
        cout << "Linhas: " << qtdLinhas << "\n";
        cout << "Palavras: " << cont << "\n";

        meuArquivo.close();
    }
   
}

