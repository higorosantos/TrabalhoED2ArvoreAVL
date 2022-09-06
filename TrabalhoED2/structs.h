#pragma once
#include "lista.h"
#include <vector>

struct Livro {
	int indice_livro;
	int nOcorrencias = 0;
	List<int> linhas;
};

struct info_palavra {
	string palavra;
	vector<Livro> ocorrencias;
};

