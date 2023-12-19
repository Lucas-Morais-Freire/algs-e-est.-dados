#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

/************ Provided structures *************/

template <class T>
void printVector(std::vector<T> v) {
    typename std::vector<T>::iterator iter = v.begin();
    std::cout << "[" << (*iter)->getInfo();
    iter++;
    while (iter != v.end()) {
        std::cout << ", " << (*iter)->getInfo();

        iter++;
    }
    std::cout << "]\n";
}

template <class T>
class Vertex {
    T info; // contents
    std::vector<Edge<T>> adj; // list out edges
    bool visited; // auxiliary field
    bool processing; // auxiliary field

    void addEdge(Vertex<T> *dest, double w) {
        adj.push_back(Edge<T>(dest, w));
    }

    bool removeEdgeTo(Vertex<T> *d) {
        typename std::vector<Edge<T>>::iterator iter = adj.begin();
        while (iter != adj.end()) {
            if (iter->getDest() == d) {
                adj.erase(iter);
                return true;
            }

            iter++;
        }

        return false;
    }
public:
    Vertex(T in) {
        info = in;
        visited = false;
        processing = false;
    }

    T getInfo() const {
        return info;
    }

    void setInfo(T in) {
        info = in;
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited(bool v) {
        visited = v;
    }

    bool isProcessing() const {
        return processing;
    }

    void setProcessing(bool p) {
        processing = p;
    }

    const std::vector<Edge<T>>& getAdj() const {
        return adj;
    }
    
    void setAdj(const std::vector<Edge<T>>& adj) {
        this->adj = adj;
    }

    friend class Graph<T>;
};

template <class T>
class Edge {
    Vertex<T>* dest; // dest vertex
    double weight; // edge weight
public:
    Edge(Vertex<T> *d, double w) {
        dest = d;
        weight = w;
    }

    Vertex<T>* getDest() const {
        return dest;
    }

    void setDest(Vertex<T> *dest) {
        this->dest = dest;
    }

    double getWeight() const {
        return weight;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }
    
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph {
    std::vector<Vertex<T>*> vertexSet; // vertex set

    /* Auxiliary functions for DFS and BFS */
    void dfsVisit(Vertex<T>* v, std::vector<Vertex<T>*>& res) const {
        v->visited = true;
        res.push_back(v);

        typename std::vector<Edge<T>>::iterator iter = v->adj.begin();
        while (iter != v->adj.end()) {
            Vertex<T>* w = iter->getDest();
            if (!w->visited)
                dfsVisit(w, res);
            
            iter++;
        }
    }

public:
    Vertex<T>* findVertex(const T &in) const {
        typename std::vector<Vertex<T>*>::const_iterator iter = vertexSet.begin();
        while (iter != vertexSet.end()) {
            if ((*iter)->getInfo() == in) {
                return *iter;
            }

            iter++;
        }

        return nullptr;
    }

    int getNumVertex() const {
        return vertexSet.size();
    }

    bool addVertex(const T &in) {
        if (this->findVertex(in) != nullptr) {
            // lide com a falha da maneira que quiser.
            return false;
        }

        Vertex<T>* newVertex = new(std::nothrow) Vertex<T>(in);
        if (newVertex) {
            vertexSet.push_back(newVertex);
            return true;
        } else {
            // lide com a falha da maneira que quiser.
            return false;
        }
    }
    
    bool removeVertex(const T& in) {
        typename std::vector<Vertex<T>*>::iterator iter_v = vertexSet.begin();
        Vertex<T>* v = this->findVertex(in);
        bool ret = false;
        while (iter_v != vertexSet.end()) {
            if ((*iter_v) == v) {
                delete *iter_v;
                vertexSet.erase(iter_v);
                ret = true;
            } else {
                (*iter_v)->removeEdgeTo(v);
            }

            iter_v++;
        }

        return ret;
    }
    
    bool addEdge(const T &sourc, const T &dest, double w = 0) {
        Vertex<T>* src = this->findVertex(sourc);
        Vertex<T>* dst = this->findVertex(dest);
        if (src == nullptr || dst == nullptr) {
            return false;
        }

        typename std::vector<Edge<T>>::iterator iter = src->adj.begin();
        while(iter != src->adj.end()) {
            if (iter->getDest() == dst) {
                return false;
            }

            iter++;
        }

        src->addEdge(dst, w);
        return true;
    }

    bool removeEdge(const T &sourc, const T &dest) {
        Vertex<T>* src = this->findVertex(sourc);
        Vertex<T>* dst = this->findVertex(dest);
        if (src == nullptr || dst == nullptr) {
            return false;
        }

        return src->removeEdgeTo(dst);
    }

    std::vector<Vertex<T>*> getVertexSet() const {
        return vertexSet;
    }

    /*
    * Performs a DFS in a graph (this). Returns a vector with the
    * contents of the vertices by DFS order, from the source node. */
    std::vector<Vertex<T>*> dfs(const T& source) const {
        std::vector<Vertex<T>*> res;
        Vertex<T>* s = this->findVertex(source);
        if (s == nullptr)
            return res;

        typename std::vector<Vertex<T>*>::const_iterator iter = vertexSet.begin();
        while (iter != vertexSet.end()) {
            (*iter)->visited = false;
            iter++;
        }

        dfsVisit(s, res);
        printVector(res);
        return res;
    }
    /* Performs a BFS in a graph (this), starting at (source).
    * Returns a vector with vertices’ contents by DFS order. */
    std::vector<T> bfs(const T & source) const {
        std::vector<T> res;
        Vertex<T>* s = this->findVertex(source);
        if (s == nullptr)
            return res;

        std::queue<Vertex<T>*> q;
        typename std::vector<Vertex<T>*>::iterator iter = vertexSet.begin();
        while (iter != vertexSet.end()) {
            (*iter)->visited = false;

            iter++;
        }

        q.push(s);
        s->visited = true;
        typename std::vector<Edge<T>>::iterator iter2;
        while (!q.empty()) {
            Vertex<T>* v = q.front();
            q.pop();
            res.push_back(v->info);
            iter2 = v->adj.begin();
            while (iter2 != v->adj.end()) {
                Vertex<T>* w = iter2->getDest();
                if (!w->visited) {
                    q.push(w);
                    w->visited = true;
                }

                iter2++;
            }
        }
        
        return res;
    }
    
    bool dfsIsDAGVisit(Vertex<T>* v,std::vector<Vertex<T>*>& sequence) const {
        typename std::vector<Vertex<T>*>::iterator iter_v = sequence.begin();
        while (iter_v != sequence.end()) {
            if ((*iter_v) == v) {
                return false;
            }

            iter_v++;
        }

        if (v->visited) {
            return true;
        }

        v->visited = true;
        sequence.push_back(v);
        printVector(sequence);

        typename std::vector<Edge<T>>::iterator iter_e = v->adj.begin();
        while (iter_e != v->adj.end()) {
            Vertex<T>* w = iter_e->getDest();
            if(!dfsIsDAGVisit(w, sequence)) {
                return false;
            }

            iter_e++;
        }

        sequence.pop_back();
        printVector(sequence);
        return true;
    }

    bool dfsIsDAG(Vertex<T> *v) const {
        std::vector<Vertex<T>*> sequence;

        typename std::vector<Vertex<T>*>::const_iterator iter = vertexSet.begin();
        while (iter != vertexSet.end()) {
            (*iter)->visited = false;
            iter++;
        }

        return dfsIsDAGVisit(v, sequence);
    }

    void show() {
        std::vector<Vertex<int>*>::iterator iter = vertexSet.begin();

        while (iter != vertexSet.end()) {
            std::cout << "[" << (*iter)->getInfo() << "] adj: ";
            
            std::vector<Edge<int>> adj = (*iter)->getAdj();
            std::vector<Edge<int>>::iterator adj_iter = adj.begin();
            while(adj_iter != adj.end()) {
                std::cout << adj_iter->getDest()->getInfo() << "(" << adj_iter->getWeight() << "), ";
                adj_iter++;
            }

            std::cout << "\n\n";
            iter++;
        }
    }

    // void getAcyclicPaths(const Vertex<T>* src, const Vertex<T>* dst, std::vector<std::vector<T>>& paths, std::vector<T> path) const {
    //     if (src == dst) {
    //         paths.push_back(path);
    //         return;
    //     }

    //     path.push_back(src);
    //     src->visited= true;
    // }

    // std::vector<T> shortestPath(const T& sourc, const T& dest) const {
    //     typename std::vector<Vertex<T>*>::const_iterator iter = vertexSet.begin();
    //     while (iter != vertexSet.end()) {
    //         (*iter)->visited = false;
    //         iter++;
    //     }

    //     Vertex<T>* src = findVertex(sourc);
    //     Vertex<T>* dst = findVertex(dest);

    //     std::vector<std::vector<T>> paths;
    //     std::vector<T> path;
    //     path.push_back(src);
    //     getAcyclicPaths(src, dst, paths, path);
    // }
};