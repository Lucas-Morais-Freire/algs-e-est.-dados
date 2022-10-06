#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASIZE 30

void printArray(int* v, int n) {
    printf("[");
    int i = 0;
    while (i < n - 1) {
        printf("%d, ", v[i]);
        i++;
    }
    printf("%d]\n", v[i]);
}

void selectionSort(int* v, int n) {
    for (int s = 0; s != n; s++) {
        int i_min = s;

        for (int i = s; i < n; i++) { //calcular o minimo entre os indices [s, n-1]
            if (v[i] < v[i_min]) {
                i_min = i;
            }
        }

        int aux = v[s];
        v[s] = v[i_min];
        v[i_min] = aux;
    }
}

int main() {
    srand(time(NULL));

    int* v = malloc(ASIZE*sizeof(int));
    for (int i = 0; i < ASIZE; i++) {
        v[i] = rand() % ASIZE;
    }

    printArray(v, ASIZE);

    selectionSort(v, ASIZE);

    printArray(v, ASIZE);

    free(v);

    return 0;
}