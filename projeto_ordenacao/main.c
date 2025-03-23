#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "algoritmos.h"
#include "gerar_dados.h"

int tamanhos[] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};
int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

// Função para medir o tempo de algoritmos com 2 parâmetros (int *, int)
double medir_tempo_2param(void (*algoritmo)(int *, int), int *dados, int n) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    algoritmo(dados, n);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

// Função para medir o tempo de algoritmos com 3 parâmetros (int *, int, int)
double medir_tempo_3param(void (*algoritmo)(int *, int, int), int *dados, int low, int high) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    algoritmo(dados, low, high);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

int main() {
    int *dados[num_tamanhos];
    gerar_dados(dados, tamanhos, num_tamanhos);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        printf("Testando para %d elementos...\n", n);

        // Bubble Sort
        double tempo_bubble = medir_tempo_2param(bubble_sort, dados[i], n);
        printf("Bubble Sort: %.6f segundos\n", tempo_bubble);

        // Selection Sort
        double tempo_selection = medir_tempo_2param(selection_sort, dados[i], n);
        printf("Selection Sort: %.6f segundos\n", tempo_selection);

        // Insertion Sort
        double tempo_insertion = medir_tempo_2param(insertion_sort, dados[i], n);
        printf("Insertion Sort: %.6f segundos\n", tempo_insertion);

        // Merge Sort
        double tempo_merge = medir_tempo_3param(merge_sort, dados[i], 0, n - 1);
        printf("Merge Sort: %.6f segundos\n", tempo_merge);

        // Quick Sort
        double tempo_quick = medir_tempo_3param(quick_sort, dados[i], 0, n - 1);
        printf("Quick Sort: %.6f segundos\n", tempo_quick);

        // Counting Sort
        double tempo_counting = medir_tempo_2param(counting_sort, dados[i], n);
        printf("Counting Sort: %.6f segundos\n", tempo_counting);

        printf("\n");
    }

    for (int i = 0; i < num_tamanhos; i++) {
        free(dados[i]);
    }

    return 0;
}