#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "algoritmos.h"
#include "gerar_dados.h"

int tamanhos[] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};
int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

double medir_tempo(void (*algoritmo)(int *, int), int *dados, int n) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    algoritmo(dados, n);
    gettimeofday(&fim, NULL);
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1e6;
}

int main() {
    int *dados[num_tamanhos];
    gerar_dados(dados, tamanhos, num_tamanhos);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        printf("Testando para %d elementos...\n", n);

        double tempo_bubble = medir_tempo(bubble_sort, dados[i], n);
        printf("Bubble Sort: %.6f segundos\n", tempo_bubble);

        double tempo_selection = medir_tempo(selection_sort, dados[i], n);
        printf("Selection Sort: %.6f segundos\n", tempo_selection);

        double tempo_insertion = medir_tempo(insertion_sort, dados[i], n);
        printf("Insertion Sort: %.6f segundos\n", tempo_insertion);

        double tempo_merge = medir_tempo((void (*)(int *, int))merge_sort, dados[i], n);
        printf("Merge Sort: %.6f segundos\n", tempo_merge);

        double tempo_quick = medir_tempo((void (*)(int *, int))quick_sort, dados[i], n);
        printf("Quick Sort: %.6f segundos\n", tempo_quick);

        double tempo_counting = medir_tempo(counting_sort, dados[i], n);
        printf("Counting Sort: %.6f segundos\n", tempo_counting);

        printf("\n");
    }

    for (int i = 0; i < num_tamanhos; i++) {
        free(dados[i]);
    }

    return 0;
}