#include "linkedgraph.hpp"
#include <iostream>

int main() {
    Graph<int> g;

    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(9);
    g.addVertex(11);
    g.addVertex(10);

    g.addEdge(4, 5);
    g.addEdge(4, 11);
    g.addEdge(4, 10);
    
    g.addEdge(5, 9);
    g.addEdge(5, 11);
    
    g.addEdge(11, 10);
    
    g.addEdge(10, 5);

    g.show();

    if (g.dfsIsDAG(*(g.getVertexSet().begin()))) {
        std::cout << "is DAG\n";
    } else {
        std::cout << "is not DAG\n";
    }

    return 0;
}