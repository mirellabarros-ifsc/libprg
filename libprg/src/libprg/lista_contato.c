#include <libprg/libprg.h>
#include <string.h>

#define TAMANHO_LISTA_CONTATO 10

Contatos* criarContatos() {
    Contatos* contatos = malloc(sizeof (Contatos));
    if (contatos != NULL) {
        contatos->capacidade = TAMANHO_LISTA_CONTATO;
        contatos->pessoa = malloc(sizeof (Pessoa) * contatos->capacidade);
        contatos->tamanho = 0;

        // Verifica se há contatos em arquivo binário para carregar.
        FILE *arq = fopen("./contatosbin.bin", "rb");

        if (arq) {
            fseek(arq, 0, SEEK_END);
            long tam_arq = ftell(arq);
            rewind(arq);

            contatos->tamanho = tam_arq / sizeof(Pessoa);

            while (contatos->tamanho >= contatos->capacidade) {
                contatos->capacidade = contatos->capacidade * 2;
                contatos->pessoa = (Pessoa*) realloc(&contatos->pessoa, sizeof (Pessoa) * contatos->capacidade);
            }

            if (contatos->pessoa != NULL) {
                fread(contatos->pessoa, sizeof(Pessoa), contatos->tamanho, arq);
                fclose(arq);
            }
        }

        if (contatos->pessoa != NULL) {
            return contatos;
        }
    } else {
        free(contatos);
    }
    return NULL;
}

int getTamanhoContatos(Contatos* contatos) {
    return contatos->tamanho;
}

Pessoa* getPessoas(Contatos* contatos) {
    return contatos->pessoa;
}

bool adicionarPessoa(Contatos* contatos, char nome[100], char telefone[15], char email[50]) {
    if (contatos->tamanho >= contatos->capacidade) {
        contatos->capacidade = contatos->capacidade * 2;
        contatos->pessoa = (Pessoa*) realloc(&contatos->pessoa, sizeof (Pessoa) * contatos->capacidade);
    }
    if (contatos->pessoa != NULL) {
        // Copia os valores para a struct pessoa
        strcpy(contatos->pessoa[contatos->tamanho].nome, nome);
        strcpy(contatos->pessoa[contatos->tamanho].telefone, telefone);
        strcpy(contatos->pessoa[contatos->tamanho].email, email);
        // Compara o conteúdo das strings
        int cmp1 = strcmp(contatos->pessoa[contatos->tamanho].nome, nome);
        int cmp2 = strcmp(contatos->pessoa[contatos->tamanho].telefone, telefone);
        int cmp3 = strcmp(contatos->pessoa[contatos->tamanho].email, email);
        // Verifica se os valores são iguais
        if (cmp1 == 0 && cmp2 == 0 & cmp3 == 0) {
            contatos->tamanho = contatos->tamanho + 1;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void removerPessoa(Contatos* contatos, int id) {
    contatos->tamanho = contatos->tamanho - 1;
    contatos->pessoa[id] = contatos->pessoa[contatos->tamanho];
}

int* buscarPessoas(Contatos* contatos, char nome[100]) {
    int* resultados = malloc(5 * sizeof(int));;
    int contagem = 0;
    for (int i = 0; i < contatos->tamanho; ++i) {
        if (strcasestr(contatos->pessoa[i].nome, nome) != NULL) {
            resultados[contagem + 1] = i;
            contagem++;
        }
    }
    // Quantidade de registros encontrados.
    resultados[0] = contagem;
    return resultados;
}

Pessoa* exibirPessoas(Contatos* contatos, const int* resultados) {
    Pessoa* busca = malloc(sizeof (Pessoa) * resultados[0]);
    for (int i = 0; i < resultados[0]; ++i) {
        busca[i] = contatos->pessoa[resultados[i + 1]];
    }
    return busca;
}

Pessoa* exibirPessoa(Contatos* contatos, int id) {
    return &contatos->pessoa[id];
}

void editarPessoa(Contatos* contatos, int id, char nome[100], char telefone[14], char email[50]) {
    if (strcmp(nome, "") != 0) {
        strcpy(contatos->pessoa[id].nome, nome);
    }
    if (strcmp(telefone, "") != 0) {
        strcpy(contatos->pessoa[id].telefone, telefone);
    }
    if (strcmp(email, "") != 0) {
        strcpy(contatos->pessoa[id].email, email);
    }
}

bool salvarArquivoTxt(Contatos* contatos) {
    FILE *arq = fopen("./contatos.txt", "w");
    if (arq) {
        int tamanho = getTamanhoContatos(contatos);
        if (tamanho > 0) {
            fprintf(arq, "%d\n", tamanho);
            for (int i = 0; i < tamanho; ++i) {
                fprintf(arq, "%s\n", contatos->pessoa[i].nome);
                fprintf(arq, "%s\n", contatos->pessoa[i].telefone);
                fprintf(arq, "%s\n", contatos->pessoa[i].email);
            }
        }
        fclose(arq);
        return true;
    } else {
        return false;
    }
}

bool lerArquivoTxt(Contatos* contatos) {
    FILE *arq = fopen("./contatos.txt", "r");
    char nome[100], telefone[20], email[50];
    if (arq) {
        int tamanho;
        fscanf(arq, "%d\n", &tamanho);
        for (int i = 0; i < tamanho; ++i) {
            fgets(nome, 100, arq);
            nome[strcspn(nome, "\n\r")] = 0;
            fgets(telefone, 100, arq);
            telefone[strcspn(telefone, "\n\r")] = 0;
            fgets(email, 100, arq);
            email[strcspn(email, "\n\r")] = 0;
            adicionarPessoa(contatos, nome, telefone, email);
        }
        fclose(arq);
        return true;
    } else {
        return false;
    }
}

bool salvarArquivoBin(Contatos* contatos) {
    FILE *arq = fopen("./contatosbin.bin", "wb+");
    if (arq) {
        int t = getTamanhoContatos(contatos);
        fwrite(contatos->pessoa, sizeof(Pessoa), t, arq);
        fclose(arq);
        return true;
    } else {
        return false;
    }
}

void excluirLista(Contatos* contatos) {
    free(contatos->pessoa);
    free(contatos);
}