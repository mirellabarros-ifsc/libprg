#include "libprg/libprg.h"

typedef struct no {
    int dado;
    struct no* proximo;
} no_t;

typedef struct lista {
    int tamanho;
    bool ordenada;
    no_t* inicio;
} lista_t;

lista_t* criar_ec(bool ordenada) {
    lista_t* lista_ec = malloc(sizeof(lista_t));
    if (lista_ec) {
        lista_ec->tamanho = 0;
        lista_ec->ordenada = ordenada;
        lista_ec->inicio = NULL;
        return lista_ec;
    } else {
        return NULL;
    }
}

int tamanho_ec(lista_t* lista) {
    return lista->tamanho;
}

void adicionar_ec(lista_t* lista, int dado) {
    no_t* novo = malloc(sizeof(no_t));
    novo->dado = dado;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
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

int* getlista_ec(lista_t* lista) {
    int i = 0;
    int* elementos = malloc(sizeof(int) * lista->tamanho);
    if (elementos) {
        no_t* no = lista->inicio;
        while (no != NULL) {
            elementos[i] = no->dado;
            no = no->proximo;
            i++;
        }
        return elementos;
    } else {
        return NULL;
    }
}

void destruir_ec(no_t** inicio);