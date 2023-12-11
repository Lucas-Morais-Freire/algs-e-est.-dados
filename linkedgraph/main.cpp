#include "arraygraph.hpp"

struct exmpl {
    int ival;
    float fval;
};

int main() {
    ArrayGraph<exmpl, int> graph(5);

    graph[0] = {1, 1};
    graph[1] = {2, 1.72};
    graph[2] = {0, 4.5};
    graph[3] = {9, -3.33};
    graph[4] = {-4, -2};

    for (int i = 0; i < 5; i++) {
        std::cout << "no " << i << ":\n   ival: " << graph[i].ival << "\n    fval: " << graph[i].fval << "\n\n";
    }

    graph.placeDirEdge(0, 2, 3);
    graph.placeDirEdge(1, 1, -5);
    graph.placeEdge(4, 3, 2);

    int* x = graph.getWeight(2, 1);
    std::cout << x << "\n";
    x = graph.getWeight(1,1);
    std::cout << x << "\n";
    std::cout << *x << "\n";

    graph.showAdjacencyMatrix();

    return 0;
}