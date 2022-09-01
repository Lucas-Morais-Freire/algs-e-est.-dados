#include "arraylist2.h"

int main() {

    struct arraylist* lista = inicializar(10);

    for (int i = 0; i < 20; i++) {
        inserirElementoNoFim(lista, i);
    }
    exibirLista(lista);
    
    inserirElementoEmPosicao(lista, -1, 5);
    exibirLista(lista);
    
    removerElementoNoFim(lista);
    exibirLista(lista);
    
    removerElementoEmPosicao(lista, 6);
    exibirLista(lista);

    free(lista->vetor);
    free(lista);
    return 0;
}