#ifndef ARRAYGRAPH_H
#define ARRAYGRAPH_H

#include <iostream>

template <class N, class W>
class ArrayGraph {
    private:
        bool** _adj;
        W** _weights;
        int _n;
        N* _nodes;
    public:
        ArrayGraph(int n) {
            if (n <= 0) {
                std::cout << "a quantidade de nos deve ser no minimo 1.\n";
                exit(-1);
            }

            _n = n;

            _adj = new bool*[n];
            _adj[0] = new bool[n*n]();
            for (int i = 1; i < n; i++) {
                _adj[i] = _adj[i - 1] + n;
            }
            
            _weights = new W*[n];
            _weights[0] = new W[n*n];
            for (int i = 1; i < n; i++) {
                _weights[i] = _weights[i - 1] + n;
            }

            _nodes = new N[n];
        }

        ~ArrayGraph() {    
            delete[] _adj[0];
            delete[] _adj;
            delete[] _weights[0];
            delete[] _weights;
            delete[] _nodes;
        }

        void showAdjacencyMatrix() {
            for (int i = 0; i < _n; i++) {
                std::cout << "[" << _adj[i][0];
                for (int j = 1; j < _n; j++) {
                    std::cout << ", " << _adj[i][j];
                }
                std:: cout << "]\n";
            }
        }

        N& operator[](int node_index) {
            if (node_index < 0 || node_index >= _n) {
                std::cout << "indice de no invalido.\n";
                exit(-1);
            }

            return _nodes[node_index];
        } 

        void placeDirEdge(int src, int dst, const W& weight) {
            if (src < 0 || src >= _n) {
                std::cout << "o no" << src << "e invalido.\n";
                exit(-1);
            }
            if (dst < 0 || dst >= _n) {
                std::cout << "o no" << dst << "e invalido.\n";
                exit(-1);
            }

            _weights[src][dst] = weight;

            _adj[src][dst] = true;
        }
        
        void placeEdge(int node1, int node2, const W& weight) {
            this->placeDirEdge(node1, node2, weight);
            this->placeDirEdge(node2, node1, weight);
        }

        void removeDirEdge(int src, int dst) {
            if (src < 0 || src >= _n) {
                std::cout << "o no" << src << "e invalido.\n";
                exit(-1);
            }
            if (dst < 0 || dst >= _n) {
                std::cout << "o no" << dst << "e invalido.\n";
                exit(-1);
            }

            _adj[src][dst] = false;
        }

        void removeEdge(int node1, int node2) {
            this->removeDirEdge(node1, node2);
            this->removeDirEdge(node2, node1);
        }

        W* getWeight(int src, int dst) {
            if (src < 0 || src >= _n) {
                std::cout << "o no" << src << "e invalido.\n";
                exit(-1);
            }
            if (dst < 0 || dst >= _n) {
                std::cout << "o no" << dst << "e invalido.\n";
                exit(-1);
            }

            if (_adj[src][dst]) {
                return &(_weights[src][dst]);
            } else {
                return nullptr;
            }
        }

        bool isLinked(int src, int dst) {
            if (src < 0 || src >= _n) {
                std::cout << "o no" << src << "e invalido.\n";
                exit(-1);
            }
            if (dst < 0 || dst >= _n) {
                std::cout << "o no" << dst << "e invalido.\n";
                exit(-1);
            }

            return _adj[src][dst];
        }
};

#endif // ARRAYGRAPH_H