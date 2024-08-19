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

nodo_t* desenfileirar(nodo_t* raiz, fila_t *fila) {
	if(fila->total == 0){
		return NULL;
	}
	fila->inicio = (fila->inicio + 1) % fila->tamanho;
	fila->total--;
	return fila->array[fila->inicio];
}

void imprimir_arvore(nodo_t* raiz) {
	if (raiz != NULL){
		if(raiz->esquerda != NULL){
			printf("%d -- %d\n",raiz->valor, raiz->esquerda->valor);
		} if (raiz->direita != NULL){
			printf("%d -- %d\n", raiz->valor, raiz->direita->valor);
		}
		imprimir_arvore(raiz->esquerda);
		imprimir_arvore(raiz->direita);
	}
}

void imprimir_grafico(nodo_t* raiz) {
	printf("strict graph{\n"
		   "label=\"Árvore de busca binária\";\n"
		   "node [shape=\"circle\", color=\"#339966\", style=\"filled\",\n"
		   "fixedsize=true];\n");
	imprimir_arvore(raiz);
	printf("}\n");
}

int altura(arvore_avl_t* arvore_avl) {
	if (arvore_avl == NULL){
		return 0;
	} else {
		return arvore_avl->altura;
	}
}

int fator_balanceamento(arvore_avl_t* arvore_avl) {
	if(arvore_avl == NULL){
		return 0;
	} else{
		return altura(arvore_avl->esquerda) - altura(arvore_avl->direita);
	}
}

arvore_avl_t *rotacao_esquerda(arvore_avl_t* arvore_avl) {
	arvore_avl_t *novo = arvore_avl->direita;
	arvore_avl->direita = novo->esquerda;
	novo->esquerda = arvore_avl;

	arvore_avl->altura = max(altura(arvore_avl->esquerda), altura(arvore_avl->direita)) + 1;
	novo->altura = max(altura(novo->esquerda), altura(novo->direita));

	return novo;
}

arvore_avl_t *rotacao_direita(arvore_avl_t* arvore_avl) {
	arvore_avl_t* novo = arvore_avl->esquerda;
	arvore_avl->esquerda = novo->direita;
	novo->direita = arvore_avl;

	arvore_avl->altura = max(altura(arvore_avl->esquerda), altura(arvore_avl->direita)) + 1;
	novo->altura = max(altura(novo->esquerda), altura(novo->direita));

	return novo;
}

arvore_avl_t* direita_esquerda(arvore_avl_t* arvore_avl) {
	arvore_avl->direita = rotacao_direita(arvore_avl->direita);


	return rotacao_esquerda(arvore_avl);
}

arvore_avl_t* esquerda_direita(arvore_avl_t* arvore_avl) {
	arvore_avl->esquerda = rotacao_esquerda(arvore_avl->esquerda);

	return rotacao_direita(arvore_avl);
}

arvore_avl_t* balanceamento(arvore_avl_t* arvore_avl) {
	int factor = fator_balanceamento(arvore_avl);

	if(factor > 1){
		if(fator_balanceamento(arvore_avl->esquerda) > 0){
			return rotacao_esquerda(arvore_avl);
		} else{
			return esquerda_direita(arvore_avl);
		}
	} else if(factor < -1){
		if(fator_balanceamento(arvore_avl->direita) > 0){
			return rotacao_esquerda(arvore_avl);
		} else{
			return direita_esquerda(arvore_avl);
		}
	}
	return arvore_avl;
}