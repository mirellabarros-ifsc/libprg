#include "libprg/libprg.h"

int* bubblesort(int* vetor, int tamanho, bool decrescente) {

	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < (tamanho - i - 1); j--) {
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
	return vetor;
}
