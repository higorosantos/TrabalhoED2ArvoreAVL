#pragma once
#include "lista.h"
#include "Arvore.h"
#include <Windows.h>

void tokenize(int* cont, std::string s, int linhaAtual, int indexLivro,No*& palavras ,std::string del);

bool validarPalavra(string palavra);

string deixarGrandao(string palavra);

void paradaGirando(string palavra, int dale);
