#include "libprg/libprg.h"

// ======================================
// Struct de lista simplesmente encadeada
// ======================================

typedef struct no {
    int dado;
    struct no* proximo;
} no_t;

typedef struct lista {
    int tamanho;
    bool ordenada;
    no_t* inicio;
} lista_t;

// Função para criar lista simplesmente encadeada

lista_t* lista_enc_criar(bool ordenada) {
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

int lista_enc_get_tamanho(lista_t* lista) {
    return lista->tamanho;
}

int* lista_enc_get_lista(lista_t* lista) {
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

bool lista_enc_adicionar(lista_t* lista, int dado) {
	no_t* novo = malloc(sizeof(no_t));
	if (novo) {
		novo->dado = dado;
		if (lista->ordenada) {
			novo->proximo = NULL;
			no_t* atual = lista->inicio;
			no_t* anterior = NULL;

			while (atual != NULL && atual->dado < dado) {
				anterior = atual;
				atual = atual->proximo;
			}

			if (anterior == NULL) {
				novo->proximo = lista->inicio;
				lista->inicio = novo;
			} else {
				anterior->proximo = novo;
				novo->proximo = atual;
			}
		} else {
			novo->proximo = lista->inicio;
			lista->inicio = novo;
		}
		lista->tamanho++;
		return true;
	} else {
		return false;
	}
}

bool lista_enc_remover(lista_t* lista, int dado) {
    no_t* atual = lista->inicio;
    no_t* anterior = NULL;
    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->tamanho--;
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

no_t* lista_enc_buscar(lista_t* lista, int dado) {
	no_t* no = lista->inicio;
	while (no != NULL) {
		if (no->dado == dado) {
			return lista->inicio;
		}
		no = no->proximo;
	}
	return NULL;
}

void lista_enc_excluir_lista(lista_t* lista) {
	no_t* atual = lista->inicio;
	no_t* proximo;

	while (atual != NULL) {
		proximo = atual->proximo;
		free(atual);
		atual = proximo;
	}
	free(lista);
}

// ===============================================
// Struct de lista simplesmente encadeada circular
// ===============================================

typedef struct lista_circ {
	int tamanho;
	bool ordenada;
	no_t *inicio;
	no_t *fim;
} lista_circ_t;

lista_circ_t *lista_enc_circ_criar(bool ordenada) {
	lista_circ_t *lista = malloc(sizeof(lista_circ_t));
	if (lista) {
		lista->ordenada = ordenada;
		lista->tamanho = 0;
		lista->inicio = NULL;
		lista->fim = NULL;
		return lista;
	} else {
		return NULL;
	}
}

int lista_enc_circ_get_tamanho(lista_circ_t* lista) {
	return lista->tamanho;
}

int* lista_enc_circ_get_lista(lista_circ_t* lista) {
	int i = 0;
	int* elementos = malloc(sizeof(int) * lista->tamanho);
	if (elementos) {
		no_t* no = lista->inicio;
		do {
			elementos[i] = no->dado;
			no = no->proximo;
			i++;
		} while (no != lista->inicio);
		return elementos;
	} else {
		return NULL;
	}
}

bool lista_enc_circ_adicionar(lista_circ_t* lista, int dado) {
	no_t* novo = malloc(sizeof(no_t));

	if (novo) {
		novo->dado = dado;
		novo->proximo = NULL;

		if (lista->ordenada) {
			if (lista->inicio == NULL) { // A lista está vazia
				lista->inicio = novo;
				lista->fim = novo;
				novo->proximo = lista->inicio;
			} else {
				no_t* atual = lista->inicio;
				no_t* anterior = NULL;

				while (atual != lista->fim && atual->dado < dado) {
					anterior = atual;
					atual = atual->proximo;
				}

				if (anterior == NULL) { // O elemento a ser inserido é o primeiro
					novo->proximo = lista->inicio;
					lista->inicio = novo;
					lista->fim->proximo = novo;
				} else if (atual->proximo == lista->inicio) { // O elemento a ser inserido é o último
					lista->fim->proximo = novo;
					lista->fim = novo;
					novo->proximo = lista->inicio;
				} else { // O elemento será inserido no meio
					anterior->proximo = novo;
					novo->proximo = atual;
				}
			}

		} else {
			if (lista->inicio == NULL) { // A lista está vazia
				lista->inicio = novo;
				lista->fim = novo;
				novo->proximo = lista->inicio;
			} else {
				novo->proximo = lista->inicio;
				lista->inicio = novo;
				lista->fim->proximo = novo; // Atualiza o ponteiro próximo do último nó
			}
		}
		lista->tamanho++;
		return true;
	} else {
		return false;
	}
}

bool lista_enc_circ_remover(lista_circ_t* lista, int dado);

no_t* lista_enc_circ_buscar(lista_circ_t* lista, int dado) {
	no_t* no = lista->inicio;
	do {
		if (no->dado == dado) {
			return lista->inicio;
		}
		no = no->proximo;
	} while (no != lista->inicio);
	return NULL;
}

void lista_enc_circ_excluir_lista(lista_circ_t* lista);