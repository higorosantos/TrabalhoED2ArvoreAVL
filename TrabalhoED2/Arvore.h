#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

struct No {
    info_palavra dado;
    No* esquerdo = NULL;
    No* direito = NULL;
    int contador = 1;
    short altura;
};

No* novoNo(int indexLivro, string palavra, int linha);

short maior(short a, short b);

short alturaDoNo(No* no);

short fatorDeBalanceamento(No* no);

No* rotacaoEsquerda(No* r);

No* rotacaoDireita(No* r);

No* rotacaoEsquerdaDireita(No* r);

No* rotacaoDireitaEsquerda(No* r);

No* balancear(No* raiz);

int comparar(string palavra1, string palavra2);

No* adcionar(No* raiz, int indexLivro, string palavra, int linha);

No* remover(No* raiz, string palavra);

void imprimir(No* raiz, int nivel);

void imprimirECD(No* raiz);

No* _procurar(string palavra, No* raiz);

void procurar(string palavra, No* raiz);

int indexOf(vector<Livro> livros, int valor);