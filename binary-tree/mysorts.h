#ifndef MYSORTS_H
#define MYSORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printArray(int* v, int n) {
    printf("[");
    int i = 0;
    while (i < n - 1) {
        printf("%d, ", v[i]);
        i++;
    }
    printf("%d]\n", v[i]);
}

void verify(int* v, int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            printf("This list is unordered.\n");
            return;
        }
    }
    printf("This list is ordered.\n");
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
        for (j = i; j > 0; j--) {
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
        int* v1 = (int*)malloc(n/2*sizeof(int));
        int* v2 = (int*)malloc((n - n/2)*sizeof(int));
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

void quickSort(int* v, int s, int f) {
    if (s >= f) {
        return;
    }
    int p = v[s]; int l = s; int r = f; int cs = 0;
    while (l != r) {
        if (v[r] < p && !cs) {
            v[l] = v[r];
            l++;
            cs = 1;
        } else if (!cs) {
            r--;
        } else if (v[l] > p) {
            v[r] = v[l];
            r--;
            cs = 0;
        } else {
            l++;
        }
    }
    v[r] = p;
    quickSort(v, s, r - 1);
    quickSort(v, r + 1, f);
}

void countingSort(int* v, int n) {
    int min = v[0]; int max = v[0]; int i;

    for (i = 0; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
        if (v[i] < min) {
            min = v[i];
        }
    }

    int* c = (int*)calloc(max - min + 1, sizeof(int));

    for (i = 0; i < n; i++) {
        c[v[i] - min]++;
    }

    i = 0; int j = 0;
    while (i < max - min + 1) {
        if (!c[i]) {
            i++;
        } else {
            v[j] = i + min;
            c[i]--; j++;
        }
    }
    free(c);
}

int partition(int* v, int s, int f) {

    int pIndex = rand() % (f - s + 1) + s;

    int temp = v[f];
    v[f] = v[pIndex];
    v[pIndex] = temp;

    pIndex = s;
    for (int i = s; i < f; i++) {
        if (v[i] <= v[f]) {
            temp = v[i];
            v[i] = v[pIndex];
            v[pIndex] = temp;

            pIndex++;
        }
    }

    temp = v[f];
    v[f] = v[pIndex];
    v[pIndex] = temp;

    return pIndex;
}

void quickSort2(int* v, int s, int f) {
    if (f > s) {
        int pIndex = partition(v, s, f);
        quickSort2(v, s, pIndex - 1);
        quickSort2(v, pIndex + 1, f);
    }
}

#endif //MYSORTS_H