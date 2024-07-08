#include "libprg/libprg.h"

void bubblesort(int* vetor, int tamanho, bool decrescente) {

	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < (tamanho - i - 1); j++) {
			if (decrescente) {
				if (vetor[j] > vetor[j + 1]) {
					int aux = vetor[j];
					vetor[j] = vetor[j + 1];
					vetor[j + 1] = aux;
				}
			} else {
				if (vetor[j] < vetor[j + 1]) {
					int aux = vetor[j];
					vetor[j] = vetor[j + 1];
					vetor[j + 1] = aux;
				}
			}
		}
	}
}

void insertion(int* vetor, int tamanho) {
	for (int i = 0; i < (tamanho); ++i) {
		int chave = vetor[i];
		int j = i - 1;
		while (j >= 0 && vetor[j] > chave) {
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = chave;
	}
}

void selection(int* vetor, int tamanho) {
	for (int i = 0; i < (tamanho - 1); i++) {
		int min = i;
		for (int j = i + 1; j < tamanho; j++) {
			if (vetor[j] < vetor[min]) {
				min = j;
			}
		}
		if (i != min) {
			int aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
	}
}