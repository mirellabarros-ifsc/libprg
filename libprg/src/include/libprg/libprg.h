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

#endif