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

void travessia_preoder(nodo_t* raiz) {
	if(raiz != NULL){
		printf("%d ",raiz->valor);
		travessia_preoder(raiz->esquerda);
		travessia_preoder(raiz->direita);
	}
}

void travessia_posorder(nodo_t* raiz) {
	if(raiz != NULL){
		travessia_posorder(raiz->esquerda);
		travessia_posorder(raiz->direita);
		printf("%d ",raiz->valor);
	}
}

void largura(nodo_t* raiz,int tamanho) {
	fila_t *fila;

	if((fila = malloc(sizeof(nodo_t))) == NULL){
		exit(EXIT_FAILURE);
	}
	if((fila->array = calloc(tamanho,sizeof(nodo_t))) == NULL){
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < tamanho; i++){
		fila->array[i] == NULL;
	}

	fila->inicio = 0;
	fila->fim = 0;
	fila->total = 0;
	fila->tamanho = tamanho;

	while(raiz != NULL){
		printf("%d ",raiz->valor);
		if(raiz->esquerda != NULL){
			enfileirar(raiz->esquerda,fila);
		} if(raiz->direita != NULL){
			enfileirar(raiz->direita,fila);
		}
		raiz = desenfileirar(raiz,fila);
	}
}

void enfileirar(nodo_t* raiz, fila_t* fila) {
	if(fila->tamanho == fila->total){
		return;
	}
	fila->array[fila->fim] = raiz;
	fila->fim = (fila->fim + 1) % fila->tamanho;
	fila->total++;
}

nodo_t *desenfileirar(nodo_t *raiz, fila_t *fila) {
	if (fila->total == 0) {
		return NULL;
	}
	fila->inicio = (fila->inicio + 1) % fila->tamanho;
	fila->total--;
	return fila->array[fila->inicio];
}

void imprimir_arvore(nodo_t *raiz) {
	if (raiz != NULL) {
		if (raiz->esquerda != NULL) {
			printf("%d -- %d\n", raiz->valor, raiz->esquerda->valor);
		}
		if (raiz->direita != NULL) {
			printf("%d -- %d\n", raiz->valor, raiz->direita->valor);
		}
		imprimir_arvore(raiz->esquerda);
		imprimir_arvore(raiz->direita);
	}
}

void imprimir_texto_grafo(arvore_avl_t *raiz) {
	printf("\n");
	printf("strict graph{\n");
	printf("label=\"Árvore de busca binária\";\n");
	printf("node [shape=\"oval\", color=\"#339966\", style=\"filled\", fontcolor=\"black\"\n");
	printf("\tfixedsize=true];\n");
	imprimir_arvore(raiz);
	printf("}\n");
}

arvore_avl_t *criar_arvore_avl(int valor) {
	arvore_avl_t *raiz = malloc(sizeof(arvore_avl_t));
	raiz->valor = valor;
	raiz->esquerda = raiz->direita = NULL;
	raiz->altura = 0;
	return raiz;
}

void imprimir_arvore_avl_grafo(arvore_avl_t *raiz) {
	if (raiz != NULL) {
		if (raiz->esquerda != NULL) {
			printf("%d -- %d\n", raiz->valor, raiz->esquerda->valor);
		}
		if (raiz->direita != NULL) {
			printf("%d -- %d\n", raiz->valor, raiz->direita->valor);
		}
		imprimir_arvore_avl_grafo(raiz->esquerda);
		imprimir_arvore_avl_grafo(raiz->direita);
	}
}

int altura(arvore_avl_t *raiz) {
	if (raiz == NULL) {
		return 0;
	} else {
		return raiz->altura;
	}
}

int fator_balanceamento(arvore_avl_t *raiz) {
	if (raiz == NULL) {
		return 0;
	} else {
		return altura(raiz->esquerda) - altura(raiz->direita);
	}
}

arvore_avl_t *rotacao_esquerda(arvore_avl_t *raiz, int *contador) {
	printf("Rotação à esquerda realizada. Contador: %d\n", *contador);
	(*contador)++;
	arvore_avl_t *u = raiz->direita;
	raiz->direita = u->esquerda;
	u->esquerda = raiz;
	raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
	u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
	return u;
}

arvore_avl_t *rotacao_direita(arvore_avl_t *raiz, int *contador) {
	(*contador)++;
	printf("Rotação à direita realizada. Contador: %d\n", *contador);
	arvore_avl_t *u = raiz->esquerda;
	raiz->esquerda = u->direita;
	u->direita = raiz;
	raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
	u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
	return u;
}

arvore_avl_t *rotacao_dupla_esquerda(arvore_avl_t *raiz, int *contador) {
	raiz->direita = rotacao_direita(raiz->direita, contador);
	return rotacao_esquerda(raiz, contador);
}

arvore_avl_t *rotacao_dupla_direita(arvore_avl_t *raiz, int *contador) {
	raiz->esquerda = rotacao_esquerda(raiz->esquerda, contador);
	return rotacao_direita(raiz, contador);
}

arvore_avl_t *inserir(arvore_avl_t *raiz, int valor, int *contador) {
	if (raiz == NULL) {
		raiz = criar_arvore_avl(valor);
	} else if (valor < raiz->valor) {
		raiz->esquerda = inserir(raiz->esquerda, valor, contador);
	} else if (valor > raiz->valor) {
		raiz->direita = inserir(raiz->direita, valor, contador);
	}
	raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
	raiz = balancear(raiz, contador);
	return raiz;
}

arvore_avl_t *remover(arvore_avl_t *raiz, int valor, int *contador) {
	if (raiz == NULL) {
		return NULL;
	} else if (valor < raiz->valor) {
		raiz->esquerda = remover(raiz->esquerda, valor, contador);
	} else if (valor > raiz->valor) {
		raiz->direita = remover(raiz->direita, valor, contador);
	} else {
		// valor == v−>valor
		if (raiz->esquerda == NULL || raiz->direita == NULL) {
			arvore_avl_t *aux = raiz->esquerda = raiz->direita;
			free(raiz);
			return aux;
		} else {
			arvore_avl_t *aux = raiz->esquerda;
			while (aux->direita != NULL) {
				aux = aux->direita;
			}
			raiz->valor = aux->valor;
			raiz->esquerda = remover(raiz->esquerda, aux->valor, contador);
		}
	}
	raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
	raiz = balancear(raiz, contador);
	return raiz;
}

arvore_avl_t *balancear(arvore_avl_t *raiz, int *contador) {
	int fator = fator_balanceamento(raiz);
	if (fator > 1) {
		if (fator_balanceamento(raiz->esquerda) > 0) {
			return rotacao_direita(raiz, contador);
		} else {
			return rotacao_dupla_direita(raiz, contador);
		}
	} else if (fator < -1) {
		if (fator_balanceamento(raiz->direita) < 0) {
			return rotacao_esquerda(raiz, contador);
		} else {
			return rotacao_dupla_esquerda(raiz, contador);
		}
	}
	return raiz;
}