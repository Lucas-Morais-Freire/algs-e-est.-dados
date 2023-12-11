#ifndef ARRAYLIST2_HPP
#define ARRAYLIST2_HPP

#include <iostream>

template <class T>
class Arraylist {
    private:
        T* vetor;
        int qtdade;
        int capacidade;
    public:
        int Arraylist::size() {
            return qtdade;
        }

        int Arraylist::capacity() {
            return capacidade;
        }

        Arraylist::Arraylist(int _capacidade) {
            vetor = new T[_capacidade];
            qtdade = 0;
            capacidade = _capacidade;
        }

        T& Arraylist::obterElementoEmPosicao(int posicao) {
            if (posicao >= 0 && posicao < qtdade) {
                return vetor[posicao];
            } else {
                std::cout << "indice invalido\n";
                exit(-1);
            }
            return 0;
        }

        void Arraylist::duplicarCapacidade() {
            T* aux = new T[2*capacidade];
            for (int i = 0; i < capacidade; i++) {
                aux[i] = vetor[i];
            }
            delete[] vetor;
            vetor = aux;
            capacidade *= 2;
        }

        void Arraylist::inserirElementoNoFim(T valor) {
            if (qtdade == capacidade) {
                this->duplicarCapacidade();
            }
            vetor[qtdade] = valor;
            qtdade++;
        }

        void Arraylist::inserirElementoEmPosicaoT(T valor, int posicao) {
            if (posicao < 0 || posicao > qtdade) {
                std::cout << "indice invalido.\n";
                exit(-1);
            } else if (qtdade == capacidade) {
                this->duplicarCapacidade();
            }

            for (int i = qtdade; i > posicao; i--) {
                vetor[i] = vetor[i - 1];
            }
            vetor[posicao] = valor;
            qtdade++;
        }

        void Arraylist::atualizarElemento(T valor, int posicao) {
            if(posicao < 0 || posicao > qtdade) {
                std::cout << "indice invalido.\n";
                exit(-1);
            } else {
                vetor[posicao] = valor;
            }
        }

        void Arraylist::removerElementoNoFim() {
            qtdade--;
        }

        void Arraylist::removerElementoEmPosicao(int posicao) {
            if (posicao < 0 || posicao > qtdade) {
                std::cout << "indice invalido.\n";
                exit(-1);
            } else {
                for (int i = posicao; i < qtdade - 1; i++) {
                    vetor[i] = vetor[i + 1];
                }
                qtdade--;
            }
        }

        Arraylist::~Arraylist() {
            delete[] vetor;
        }
};

#endif //ARRAYLIST2_HPP