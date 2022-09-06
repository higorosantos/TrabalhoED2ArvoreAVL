#include "utils.h";
#include "structs.h"
#include <iostream>;
#include <regex>
#include <string.h>

using namespace std;
//

void tokenize(int* cont, string s, int linhaAtual,int indexLivro,No*& palavras,string del = " ") {
   
    int start = 0;
    string palavraString;

    
    regex re{ R"([-[\]—{}'1234567896_!()*+?/:";.,\^$|#\s])" };

    s = regex_replace(s, re, del);

    int end = s.find(del);

    palavraString = deixarGrandao(s.substr(start, end));

    if (validarPalavra(palavraString)) {

        //cout << "Linha: " << linhaAtual << " ->" << palavraString << "\n";
        
        palavras = adcionar(palavras, indexLivro, palavraString, linhaAtual);
        *cont += 1;
        //paradaGirando(palavraString, *cont);
    }
 
       // cout << palavra << "\n";

        while (end != -1) {


            start = end + del.size();
            end = s.find(del, start);
            palavraString = deixarGrandao(s.substr(start, (end - start)));

            // cout << "Start: " << start << "/ End: " << end << "\n";
            // cout << start << ". ";
            // cout << end << ".\n";

            if (validarPalavra(palavraString)) {

                //cout << "Linha: " << linhaAtual << " ->" << palavraString << "\n";
                palavras = adcionar(palavras, indexLivro, palavraString, linhaAtual);
                *cont += 1;
                //paradaGirando(palavraString, *cont);
            }

            // palavras.imprimir();
        }
    
}

bool validarPalavra(string palavra) {

    if (palavra.length() < 3) {
        return false;
    }
    else {
        return true;
    }
}

string deixarGrandao(string palavra) {

    for (int i = 0; i < palavra.length(); i++) {
        palavra[i] = toupper(palavra[i]);
    }

    return palavra;
}

void paradaGirando(string palavra, int cont) {
     int i = cont;
        if (i % 4 == 0) {
            system("cls");
            cout << "\t| Palavras sendo carregadas |";
            cout << "\n\t "  << palavra;
            Sleep(50);
        }
        if (i % 4 == 1) {
            system("cls");
            cout << "\t/ Palavras sendo carregadas /";
            cout << "\n\t  " << palavra;
            Sleep(50);
        }
        if (i % 4 == 2) {
            system("cls");
            cout << "\t- Palavras sendo carregadas -";
            cout << "\n\t " << palavra;
            Sleep(50);
        }
        if (i % 4 == 3) {
            system("cls");
            cout << "\t\\ Palavras sendo carregadas \\";
            cout << "\n\t " << palavra;
            Sleep(50);
        }
}
