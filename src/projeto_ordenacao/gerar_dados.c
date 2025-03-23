#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar conjuntos de dados aleatórios
void gerar_dados(int **dados, int *tamanhos, int num_tamanhos) {
    srand(time(NULL)); // Seed para números aleatórios
    for (int i = 0; i < num_tamanhos; i++) {
        dados[i] = (int *)malloc(tamanhos[i] * sizeof(int));
        for (int j = 0; j < tamanhos[i]; j++) {
            dados[i][j] = rand() % 100000; // Números entre 0 e 99999
        }
    }
}