#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

// Lista Linear
typedef struct Lista Lista;
Lista* criarLista();
int* getElementos(Lista* lista);
int getTamanho(Lista* lista);
int inserirElemento(Lista* lista, int n);
void removerElemento(Lista* lista, int n);
int buscaLinear(Lista* lista, int n);
int buscaBinariaInterativa(Lista* lista, int n);
int buscaBinariaRecursiva(Lista* lista, int n, int inicio, int fim);

// Lista Contato
typedef struct Pessoa {
    char nome[100];
    char telefone[20];
    char email[50];
} Pessoa;

typedef struct Contato {
    struct Pessoa* pessoa;
    int capacidade;
    int tamanho;
} Contatos;

Contatos* criarContatos();
Pessoa* getPessoas(Contatos* contatos);
int getTamanhoContatos(Contatos* contatos);
bool adicionarPessoa(Contatos* contatos, char nome[100], char telefone[14], char email[50]);
void removerPessoa(Contatos* contatos, int id);
int* buscarPessoas(Contatos* contatos, char nome[100]);
Pessoa* exibirPessoas(Contatos* contatos, const int* resultados);
Pessoa* exibirPessoa(Contatos* contatos, int id);
void editarPessoa(Contatos* contatos, int id, char nome[100], char telefone[14], char email[50]);
bool salvarArquivoTxt(Contatos* contatos);
bool lerArquivoTxt(Contatos* contatos);
bool salvarArquivoBin(Contatos* contatos);
void excluirLista(Contatos* contatos);

// Fila
typedef struct Fila Fila;
Fila* criaFila(int capacidade); // OK
int* getFila(Fila* fila); // OK
int getSize(Fila* fila); // OK
bool isEmpty(Fila* fila); // OK
bool isFull(Fila* fila); // OK
void enqueue(Fila* fila, int n); // OK
int dequeue(Fila* fila); // OK
int head(Fila* fila); // OK
int tail(Fila* fila); // OK

// Pilha
typedef struct Pilha Pilha;
Pilha* criarPilha();
void push();

// ===============================
// ESTRUTURAS DE LISTAS ENCADEADAS
// ===============================

// Lista simplesmente encadeada

typedef struct no no_t;
typedef struct lista lista_t;
lista_t* lista_enc_criar(bool ordenada);
int lista_enc_get_tamanho(lista_t* lista);
int* lista_enc_get_lista(lista_t* lista);
bool lista_enc_adicionar(lista_t* lista, int dado);
bool lista_enc_remover(lista_t* lista, int dado);
no_t* lista_enc_buscar(lista_t* lista, int dado);
void lista_enc_excluir_lista(lista_t* lista);

// Lista simplesmente encadeada circular

typedef struct lista_circ lista_circ_t;
lista_circ_t* lista_enc_circ_criar(bool ordenada);
int lista_enc_circ_get_tamanho(lista_circ_t* lista);
int* lista_enc_circ_get_lista(lista_circ_t* lista);
bool lista_enc_circ_adicionar(lista_circ_t* lista, int dado);
bool lista_enc_circ_remover(lista_circ_t* lista, int dado);
no_t* lista_enc_circ_buscar(lista_circ_t* lista, int dado);
void lista_enc_circ_excluir_lista(lista_circ_t* lista);


// ===============================
// ALGORITMOS DE ORDENAÇÃO - TROCA
// ===============================

// Bubblesort
void bubblesort(int* vetor, int tamanho, bool decrescente);
// Insertion sort
void insertion(int* vetor, int tamanho);
// Selection sort
void selection(int* vetor, int tamanho);

// =============================================
// ÁRVORE
// =============================================

// Merge sort
int* merge_sort(int* vetor, int esquerda, int direita);
// Quick sort
int* quick_sort(int* vetor, int inicio, int fim);

// Função para calcular o tempo do algoritmo
// https://emersonmello.me/ensino/prg2/tempo/

// =============================================
// ÁRVORE
// =============================================
typedef struct nodo {
	int valor;
	struct nodo *esquerda;
	struct nodo *direita;
} nodo_t;

typedef struct arvore_avl {
	int valor;
	int altura;
	struct arvore_avl* esquerda;
	struct arvore_avl* direita;
} arvore_avl_t;

typedef struct {
	nodo_t **array;
	int fim;
	int total;
	int inicio;
	int tamanho;
} fila_t;

nodo_t *criar_arvore(int valor);
void destruir_nodo(nodo_t *nodo);
nodo_t *inserir_valor(nodo_t *raiz, int valor);
bool busca(nodo_t *raiz, int valor);
nodo_t *remover_valor(nodo_t *raiz, int valor);
void travessia_inorder(nodo_t* raiz);
void travessia_preoder(nodo_t* raiz);
void travessia_posorder(nodo_t* raiz);
void largura(nodo_t* raiz,int tamanho);
void enfileirar(nodo_t* raiz, fila_t* fila);
nodo_t* desenfileirar(nodo_t* raiz, fila_t *fila);
void imprimir_arvore(nodo_t* raiz);
// AVl
void imprimir_texto_grafo(arvore_avl_t *raiz);
arvore_avl_t *criar_arvore_avl(int valor);
void imprimir_arvore_avl_grafo(arvore_avl_t *raiz);
int altura(arvore_avl_t *raiz);
int fator_balanceamento(arvore_avl_t *raiz);
arvore_avl_t *rotacao_esquerda(arvore_avl_t *raiz, int* contador);
arvore_avl_t *rotacao_direita(arvore_avl_t *raiz, int* contador);
arvore_avl_t *rotacao_dupla_direita(arvore_avl_t *raiz, int* contador);
arvore_avl_t *rotacao_dupla_esquerda(arvore_avl_t *raiz, int* contador);
arvore_avl_t *inserir(arvore_avl_t *raiz, int valor, int *contador);
arvore_avl_t *balancear(arvore_avl_t *raiz, int *contador);
arvore_avl_t *remover(arvore_avl_t *raiz, int valor, int *contador);

#endif