// TrabalhoED2.cpp : Este arquivo contém a função 'main'. A execução do programa
// começa e termina ali.
//
#include "lista.h"
#include "menu.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include "file.h"
#include "Arvore.h"
#include "structs.h"
#include "dirent.h"
#include "menu.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "portuguese");

	vector<string> livros;
	//ArvoreAVL palavras = ArvoreAVL();

	struct dirent* dir;
	DIR* d = opendir("Livros");

	if (d) {
		while ((dir = readdir(d)) != NULL) {

			if (strlen(dir->d_name) > 2) {
				livros.push_back(dir->d_name);
			}
		}
		closedir;
	}
	else {
		system("mkdir Livros");
	}

	

	No* palavras = NULL;

	//int teste = find(livros.begin(), livros.end(), "teste");

	for (int i = 0; i < livros.size(); i++) {

		//cout << livros[i];
		lerArquivo("./Livros/" + livros[i], i,palavras);

	}

	//procurar("GUTENBERG",palavras);

	menu(palavras);
	//imprimirECD(palavras);


	
   
}