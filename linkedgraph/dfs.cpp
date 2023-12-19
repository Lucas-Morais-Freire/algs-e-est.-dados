#include "linkedgraph.hpp"
#include <iostream>

int main() {
    Graph<int> g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(0, 1);

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 4);

    g.addEdge(3, 4);
    g.addEdge(3, 6);

    g.addEdge(4, 5);

    g.addEdge(6, 0);

    g.dfs(0);

    return 0;
}