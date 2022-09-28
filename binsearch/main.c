#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../arraylist/arraylist2.h"

bool binarySearch(struct arraylist* v, int start, int end, int target) {
    int middle = (start + end)/2;

    if (target == v->vetor[middle]) {
        return true;
    } else if (start >= end) {
        return false;
    } else if (target < v->vetor[middle]) {
        return binarySearch(v, start, middle - 1, target);
    } else if (target > v->vetor[middle]) {
        return binarySearch(v, middle + 1, end, target);
    }
}

int main() {

    srand(time(NULL));

    struct arraylist* array = inicializar(10);

    int prev = 0;
    for (int i = 0; i < 10; i++) {
        inserirElementoNoFim(array, (rand() % 20 + 1) + prev);
        prev = obterElementoEmPosicao(array, array->qtdade - 1);
    }

    exibirLista(array);

    if (binarySearch(array, 0, array->qtdade - 1, 1)) {
        printf("ye\n");
    } else {
        printf("nah\n");
    }

    destruirLista(array);

    return 0;
}