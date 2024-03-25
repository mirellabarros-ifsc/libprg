#include "libprg/libprg.h"
#include <stdlib.h>

#define TAMANHO_LISTA 10

 struct Lista {
    int* elementos;
    int capacidade;
    int tamanho;
    bool ordenada;
};

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof (lista));
    lista->capacidade = TAMANHO_LISTA;
    lista->elementos = (int*) malloc(sizeof (int) * TAMANHO_LISTA);
    lista->tamanho = 0;
    lista->ordenada = false;
    return lista;
}

int inserirElemento(Lista* lista, int n) {
    lista->elementos[lista->tamanho] = n;
    lista->tamanho++;
    return lista->tamanho - 1;
}

int buscaLinear(Lista* lista, int n) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == n) {
            return i;
        }
    }
    return -1;
}
