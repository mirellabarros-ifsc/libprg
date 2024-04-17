#include "libprg/libprg.h"

typedef struct no {
    int dado;
    struct no* proximo;
} no_t;

void adicionar_encadeada(no_t** inicio, int dado) {
    no_t* novo = malloc(sizeof(no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}

no_t* buscar_encadeada(no_t* inicio, int dado) {

}

bool remover_encadeada(no_t** inicio, int dado) {
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

void destruir_encadeaca(no_t** inicio);