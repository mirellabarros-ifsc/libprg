#include "libprg/libprg.h"

int* merge(int* vetor, int esquerda, int meio, int direita) {
	int aux[direita - esquerda + 1];
	int i = esquerda, j = meio + 1, k = 0;
	while (i <= meio && j <= direita) {
		if (vetor[i] <= vetor[j]) {
			aux[k] = vetor[i];
			i = i + 1;
		} else {
			aux[k] = vetor[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i <= meio) {
		aux[k] = vetor[i];
		i = i + 1;
		k = k + 1;
	}
	while (j <= direita) {
		aux[k] = vetor[j];
		j = j + 1;
		k = k + 1;
	}
	for (i = esquerda; i <= direita; i++) {
		vetor[i] = aux[i - esquerda];
	}
	return vetor;
}

int* merge_sort(int* vetor, int esquerda, int direita) {
	if (esquerda < direita) {
		// Divisão
		int meio = esquerda + (direita - esquerda) / 2;

		// Ordene as duas metades (conquista)
		merge_sort(vetor, esquerda, meio);
		merge_sort(vetor, meio + 1, direita);

		// Mescle as metades (combinação)
		merge(vetor, esquerda, meio, direita);
	}
	return vetor;
}

