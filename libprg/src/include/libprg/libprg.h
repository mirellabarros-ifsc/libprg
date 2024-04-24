#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct result_t;

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

// Lista Encadeada
typedef struct no no_t;
typedef struct lista lista_t;
lista_t* criar_ec(bool ordenada);
int get_tamanho_ec(lista_t* lista);
int* get_lista_ec(lista_t* lista);
void adicionar_ec(lista_t* lista, int dado);
bool remover_ec(lista_t* lista, int dado);
no_t* buscar_ec(lista_t* lista, int dado);

void destruir_ec(no_t** inicio);
void adicionar_circ_encadeada(no_t** inicio, int dado, bool ordenada);
void adicionar_circ_dp_encadeada(no_t** inicio, int dado, bool ordenada);

#endif