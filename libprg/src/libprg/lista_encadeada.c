#include "libprg/libprg.h"

typedef struct no {
    int dado;
    struct no* proximo;
} no_t;

void adicionar_ec(no_t** inicio, int dado) {
    no_t* novo = malloc(sizeof(no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}

no_t* buscar_ec(no_t* inicio, int dado) {
    while (inicio != NULL) {
        if (inicio->dado == dado) {
            return inicio;
        }
        inicio = inicio->proximo;
    }
    return NULL;
}

bool remover_ec(no_t** inicio, int dado) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) {
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

int* getlista_ec(no_t* inicio) {
    int tamanho = 10;
    int* lista = malloc(sizeof(int) * tamanho);
    if (lista) {

    }
}


void destruir_ec(no_t** inicio);