#pragma once

#include <iostream>
using namespace std;

template <typename T> struct Node {

    T dado;
    Node<T>* prox;
};

template <typename T> class List {
public:
    void set(T dado);
    int getTam();
    void Lista();
    void imprimir();
    List();

private:
    Node<T>* headNode = NULL;
    Node<T>* tailNode = NULL;
    int tam = 0;
};

template <typename T> List<T>::List() { }

template <typename T> int List<T>::getTam() { return tam; }

template <typename T> void List<T>::set(T dado) {

    Node<T>* no = new Node<T>();
    no->dado = dado;
    no->prox = NULL;

    if (this->headNode == NULL) {

        this->headNode = no;
        this->tailNode = no;
    }
    else {
        this->tailNode->prox = no;
        this->tailNode = no;
    }

    this->tam++;
}

template <typename T> void List<T>::imprimir() {

    Node<T>* aux = new Node<T>;
    aux = headNode;

    while (aux != NULL) {

        cout << aux->dado;

        aux = aux->prox;
        if (aux == NULL) {
            cout << ".";
        }
        else {
            cout << ", ";
        }
    }

}
