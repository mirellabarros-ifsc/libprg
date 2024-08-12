#include "libprg/libprg.h"

nodo_t *criar_arvore(int valor) {
	nodo_t *nodo = (nodo_t *) malloc(sizeof(nodo_t));
	nodo->valor = valor;
	nodo->esquerda = nodo->direita = NULL;
	return nodo;
}

void destruir_nodo(nodo_t *nodo) {
	if (nodo != NULL) {
		destruir_nodo(nodo->esquerda);
		destruir_nodo(nodo->direita);
		free(nodo);
	}
}

// todo nó é raiz de uma subárvore
nodo_t *inserir_valor(nodo_t *raiz, int valor) {
	if (raiz == NULL) {
		return criar_arvore(valor);
	} else if (valor < raiz->valor) {
		raiz->esquerda = inserir_valor(raiz->esquerda, valor);
	} else if (valor > raiz->valor) {
		raiz->direita = inserir_valor(raiz->direita, valor);
	}
	return raiz;
}

bool busca(nodo_t *raiz, int valor) {
	if (raiz == NULL) return false;
	if (valor == raiz->valor) return true;
	if (valor < raiz->valor) return busca(raiz->esquerda, valor);
	return busca(raiz->direita, valor);
}

nodo_t *remover_valor(nodo_t *raiz, int valor) {
	if (raiz == NULL) return raiz;
	if (valor < raiz->valor) {
		raiz->esquerda = remover_valor(raiz->esquerda, valor);
	} else if (valor > raiz->valor) {
		raiz->direita = remover_valor(raiz->direita, valor);
	} else {
		if (raiz->esquerda == NULL) {
			nodo_t *tmp = raiz->direita;
			free(raiz);
			return tmp;
		} else if (raiz->direita == NULL) {
			nodo_t *tmp = raiz->esquerda;
			free(raiz);
			return tmp;
		}

		nodo_t *tmp = raiz->direita;
		while (tmp->esquerda != NULL) {
			tmp = tmp->esquerda;
		}
		raiz->valor = tmp->valor;
		raiz->direita = remover_valor(raiz->direita, tmp->valor);
	}
	return raiz;
}

void travessia_inorder(nodo_t* raiz) {
	if (raiz != NULL) {
		travessia_inorder(raiz->esquerda);
		printf("%d", raiz->valor);
		travessia_inorder(raiz->direita);
	}
}