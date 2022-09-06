#include "Arvore.h";

/*
    Função que cria um novo nó
    x -> valor a ser inserido no nó
    Retorna: o endereço do nó criado
*/
No* novoNo(int indexLivro,string palavra, int linha) {
    No* novo = new No();

    Livro livro;
    livro.indice_livro = indexLivro;
    livro.linhas.set(linha);
    livro.nOcorrencias++;

    novo->dado.palavra = palavra;
    novo->dado.ocorrencias.push_back(livro);
   
    
    
    return novo;
}

/*
    Retorna o maior dentre dois valores
    a, b -> altura de dois nós da árvore
*/
short maior(short a, short b) {
    return (a > b) ? a : b;
}


//  Retorna a altura de um nó ou -1 caso ele seja null
short alturaDoNo(No* no) {
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

//   Calcula e retorna o fator de balanceamento de um nó
short fatorDeBalanceamento(No* no) {
    if (no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}

// --------- ROTAÇÕES ---------------------------

// função para a rotação à esquerda
No* rotacaoEsquerda(No* r) {
    No* y, * f;

    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

// função para a rotação à direita
No* rotacaoDireita(No* r) {
    No* y, * f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoEsquerdaDireita(No* r) {
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No* r) {
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção
    Recebe o nó que está desbalanceado e retorna a nova raiz após o balanceamento
*/
No* balancear(No* raiz) {
    short fb = fatorDeBalanceamento(raiz);

    // Rotação à esquerda
    if (fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à esquerda
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if (fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

int comparar(string palavra1,string palavra2) {
    
    if (palavra1 == palavra2) {
        return 0;
    }

    return palavra1 < palavra2 ? -1 : 1;


}
/*
    Insere um novo nó na árvore
    raiz -> raiz da árvore
    x -> valor a ser inserido
    Retorno: endereço do novo nó ou nova raiz após o balanceamento
*/
No* adcionar(No* raiz, int indexLivro,string palavra,int linha) {
    if (raiz == NULL) // árvore vazia
        return novoNo(indexLivro,palavra, linha);
    else { // inserção será à esquerda ou à direita
        if (comparar(palavra, raiz->dado.palavra) < 0) {
            raiz->esquerdo = adcionar(raiz->esquerdo, indexLivro,palavra,linha);
        }
        else if (comparar(palavra, raiz->dado.palavra) > 0) {
            raiz->direito = adcionar(raiz->direito,indexLivro,palavra,linha);
        }
        else {
            raiz->contador++;
            int pos = indexOf(raiz->dado.ocorrencias, indexLivro);
            if (pos == -1){


                Livro newLivro;
                newLivro.indice_livro = indexLivro;
                newLivro.linhas.set(linha);
                newLivro.nOcorrencias++;

                raiz->dado.ocorrencias.push_back(newLivro);
              

            }
            else {
                raiz->dado.ocorrencias[pos].linhas.set(linha);
                raiz->dado.ocorrencias[pos].nOcorrencias++;

            }
        }
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

/*
    Função para remover um nó da Árvore binária balanceada
    Pode ser necessário rebalancear a árvore e a raiz pode ser alterada
    por isso precisamos retornar a raiz
*/
No* remover(No* raiz, string palavra) {
    if (raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else { // procura o nó a remover
        if (comparar(raiz->dado.palavra,palavra) == 0) {
            // remove nós folhas (nós sem filhos)
            if (raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                cout << "Elemento folha removido: %d !\n" << palavra;
                return NULL;
            }
            else {
                // remover nós que possuem 2 filhos
                if (raiz->esquerdo != NULL && raiz->direito != NULL) {
                    No* aux = raiz->esquerdo;
                    while (aux->direito != NULL)
                        aux = aux->direito;
                    raiz->dado = aux->dado;
                    aux->dado.palavra = palavra;
                    cout << "Elemento trocado: %d !\n" << palavra;
                    raiz->esquerdo = remover(raiz->esquerdo, palavra);
                    return raiz;
                }
                else {
                    // remover nós que possuem apenas 1 filho
                    No* aux;
                    if (raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    cout << "Elemento com 1 filho removido: %d !\n" << palavra;
                    return aux;
                }
            }
        }
        else {
            if (comparar(palavra, raiz->dado.palavra))
                raiz->esquerdo = remover(raiz->esquerdo, palavra);
            else
                raiz->direito = remover(raiz->direito, palavra);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimir(No* raiz, int nivel) {
    int i;
    
    if (raiz) {
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
            printf("\t");

        cout << raiz->dado.palavra;
        imprimir(raiz->esquerdo, nivel + 1);
    }
    else {
        printf("DEU RUIM RAIZ NULA");
    }
}


void imprimirECD(No* raiz)
{
    if (raiz->esquerdo != NULL)
        imprimirECD(raiz->esquerdo);
    std::cout << raiz->dado.palavra << "\n";
    if (raiz->direito != NULL)
        imprimirECD(raiz->direito);
}

No* _procurar(string palavra, No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    if (palavra == raiz->dado.palavra) {
        return raiz;
    }
    if (comparar(palavra, raiz->dado.palavra) < 0) {
        return _procurar(palavra, raiz->esquerdo);
    }

    return _procurar(palavra, raiz->direito);
}

void procurar(string palavra, No* raiz) {

    No* aux = _procurar(palavra, raiz);
    if (aux == NULL) {
        cout << "Palavra não encontrada!\n";
    }
    else {
        system("cls");
        cout << "\n----------------------------------------";
        cout << "\n\tPalavra: " << aux->dado.palavra << ".";
        cout << "\n----------------------------------------";
        cout << "\n\n\t-----Ocorrencias-----";
        cout << "\n\n\tOcorrências Totais: " << aux->contador << ".";
        for (int i = 0; i < aux->dado.ocorrencias.size(); i++) {

            cout << "\n\tLivro " << aux->dado.ocorrencias[i].indice_livro + 1 << ".";
            cout << "\n\tOcorrências: " << aux->dado.ocorrencias[i].nOcorrencias << ".";
            cout << "\n\tLinhas: ";
            aux->dado.ocorrencias[i].linhas.imprimir();
            cout << "\n";

        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }

}

int indexOf(vector<Livro> livros, int valor) {


    for (int i = 0; i < livros.size(); i++) {
        if(livros[i].indice_livro == valor){
            return i;
        }
    }

    return -1;

}