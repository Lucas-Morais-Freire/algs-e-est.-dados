#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include <omp.h>

#include "mysorts.h"

#define ASIZE 100001

int main() {
    srand(time(NULL));

    double start, end;

    int* v = malloc(ASIZE*sizeof(int));
    for (int i = 0; i < ASIZE; i++) {
        v[i] = rand() % ASIZE;
    }

    /* int* w = malloc(ASIZE*sizeof(int));
    int* u = malloc(ASIZE*sizeof(int));
    int* x = malloc(ASIZE*sizeof(int));
    int* y = malloc(ASIZE*sizeof(int));
    int* z = malloc(ASIZE*sizeof(int));
    int* r = malloc(ASIZE*sizeof(int));

    copyArray(v, w, ASIZE);
    copyArray(v, u, ASIZE);
    copyArray(v, x, ASIZE);
    copyArray(v, y, ASIZE);
    copyArray(v, z, ASIZE);
    copyArray(v, r, ASIZE);
    
    start = omp_get_wtime();
    insertionSort(v, ASIZE);
    end = omp_get_wtime();
    printf("insertionSort runtime: %.15fs\n", end - start);
    verify(v, ASIZE);

    start = omp_get_wtime();
    selectionSort(u, ASIZE);
    end = omp_get_wtime();
    printf("selectionSort runtime: %.15fs\n", end - start);
    verify(u, ASIZE);

    start = omp_get_wtime();
    bubbleSort(w, ASIZE);
    end = omp_get_wtime();
    printf("bubbleSort runtime: %.15fs\n", end - start);
    verify(w, ASIZE);

    start = omp_get_wtime();
    mergeSort(x, ASIZE);
    end = omp_get_wtime();
    printf("mergeSort runtime: %.15fs\n", end - start);
    verify(x, ASIZE);

    start = omp_get_wtime();
    quickSort(y, 0, ASIZE - 1);
    end = omp_get_wtime();
    printf("quickSort runtime: %.15fs\n", end - start);
    verify(y, ASIZE);

    start = omp_get_wtime();
    countingSort(z, ASIZE);
    end = omp_get_wtime();
    printf("countingSort runtime: %.15fs\n", end - start);
    verify(z, ASIZE); */

    start = omp_get_wtime();
    quickSort2(v, 0, ASIZE - 1);
    end = omp_get_wtime();
    printf("quickSort2 runtime: %.15fs\n", end - start);
    verify(v, ASIZE);

    free(v); //free(w); free(u); free(x); free(y); free(z); free(r);

    return 0;
}