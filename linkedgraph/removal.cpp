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
    std:: cout << "--------------------\n";

    g.removeVertex(11);

    g.show();

    return 0;
}