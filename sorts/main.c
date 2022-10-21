#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include <omp.h>

#define ASIZE 50000
//#define ASIZE 20

void printArray(int* v, int n) {
    printf("[");
    int i = 0;
    while (i < n - 1) {
        printf("%d, ", v[i]);
        i++;
    }
    printf("%d]\n", v[i]);
}

void copyArray(int* sender, int* receiver, int n) {
    for (int i = 0; i < n; i++) {
        receiver[i] = sender[i];
    }
}

void selectionSort(int* v, int n) {
    int aux, i_min, i;
    for (int s = 0; s != n; s++) {
        i_min = s;

        for (i = s; i < n; i++) { //calcular o minimo entre os indices [s, n-1]
            if (v[i] < v[i_min]) {
                i_min = i;
            }
        }

        aux = v[s]; //troca o elemento mínimo (aquele que está na posição i_min) pelo primeiro elemento
        v[s] = v[i_min];
        v[i_min] = aux;
    }
}

void bubbleSort(int* v, int n) {
    int aux, j;
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swapped = true;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

void insertionSort(int* v, int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (v[j] < v[j - 1]) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

void merge(int* v1, int* v2, int* v, int n1, int n2, int n) {
    int i1, i2, i;
    i = i1 = i2 = 0;
    while (i < n) {
        if (i1 == n1) {
            v[i] = v2[i2];
            i2++;
        } else if (i2 == n2) {
            v[i] = v1[i1];
            i1++;
        } else if (v1[i1] > v2[i2]) {
            v[i] = v2[i2];
            i2++;
        } else {
            v[i] = v1[i1];
            i1++;
        }
        i++;
    }
}

void mergeSort(int* v, int n) {
    if (n == 1) {
        return;
    } else {
        int* v1 = malloc(n/2*sizeof(int));
        int* v2 = malloc((n - n/2)*sizeof(int));
        for (int i = 0; i < n/2; i++) {
            v1[i] = v[i];
        }
        for (int i = n/2; i < n; i++) {
            v2[i - n/2] = v[i];
        }

        mergeSort(v1, n/2);
        mergeSort(v2, n - n/2);

        merge(v1, v2, v, n/2, n - n/2, n);
        free(v1); free(v2);
    }
}

int main() {
    srand(time(NULL));

    double start, end;

    int* v = malloc(ASIZE*sizeof(int));
    for (int i = 0; i < ASIZE; i++) {
        v[i] = rand() % ASIZE;
    }

    int* w = malloc(ASIZE*sizeof(int));
    int* u = malloc(ASIZE*sizeof(int));
    int* x = malloc(ASIZE*sizeof(int));

    copyArray(v, w, ASIZE);
    copyArray(v, u, ASIZE);
    copyArray(v, x, ASIZE);
    
    start = omp_get_wtime();
    insertionSort(v, ASIZE);
    end = omp_get_wtime();
    printf("insertionSort runtime: %.15fs\n", end - start);

    start = omp_get_wtime();
    selectionSort(w, ASIZE);
    end = omp_get_wtime();
    printf("selectionSort runtime: %.15fs\n", end - start);

    start = omp_get_wtime();
    bubbleSort(u, ASIZE);
    end = omp_get_wtime();
    printf("bubbleSort runtime: %.15fs\n", end - start);

    start = omp_get_wtime();
    mergeSort(v, ASIZE);
    end = omp_get_wtime();
    printf("mergeSort runtime: %.15fs\n", end - start);

    free(v); free(w); free(u); free(x);

    return 0;
}