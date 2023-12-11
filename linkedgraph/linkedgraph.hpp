#include <cstddef>
#include <vector>
#include <queue>

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

/************ Provided structures *************/

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
        std::vector<Edge<T>>::iterator iter = adj.begin();
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

    T& getInfo() const {
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
    bool dfsIsDAG(Vertex<T> *v) const;
public:
    Vertex<T>* findVertex(const T &in) const {
        std::vector<Vertex<T>*>::iterator iter = vertexSet.begin();
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
        if (!(this->findVertex(in))) {
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
    
    bool removeVertex(const T &in) {
        std::vector<Vertex<T>*>::iterator iter = vertexSet.begin();
        while (iter != vertexSet.end()) {
            if ((*iter)->getInfo() == in) {
                delete *iter;
                vertexSet.erase(iter);
                return true
            }

            iter++;
        }

        return false;
    }
    
    bool addEdge(const T &sourc, const T &dest, double w) {
        Vertex<T>* src = this->findVertex(sourc);
        Vertex<T>* dst = this->findVertex(dst);
        if (src == nullptr || dst == nullptr) {
            return false;
        }

        std::vector<Edge<T>>::iterator iter = src->adj.begin();
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
        Vertex<T>* dst = this->findVertex(dst);
        if (src == nullptr || dst == nullptr) {
            return false;
        }


        return src->removeEdgeTo(dest);
    }

    std::vector<Vertex<T>*> getVertexSet() const {
        return vertexSet;
    }

    /* Auxiliary functions for DFS and BFS */
    void dfsVisit(Vertex<T> *v, vector<T> & res) const {
        v->visited = true;
        res.push_back(v->info);
        for (auto & e : v->adj) {
            auto w = e.dest;
            if ( ! w->visited)
            dfsVisit(w, res);
        }
    }

    /*
    * Performs a DFS in a graph (this). Returns a vector with the
    * contents of the vertices by DFS order, from the source node. */
    dfs(const T & source) const {
        std::vector<T> res;
        Vertex<T>* s = findVertex(source);
        if (s == nullptr)
            return res;
        for (auto v : vertexSet)
            v->visited = false;
        dfsVisit(s, res);
    return res;
    }
    /* Performs a BFS in a graph (this), starting at (source).
    * Returns a vector with vertices’ contents by DFS order. */
    bfs(const T & source) const {
        std::vector<T> res;
        Vertex<T>* s = findVertex(source);
        if (s == NULL)
            return res;
        std::queue<Vertex<T> *> q;
        for (auto v : vertexSet)
            v->visited = false;
        q.push(s);
        s->visited = true;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            res.push_back(v->info);
            for (auto & e : v->adj) {
                auto w = e.dest;
                if ( ! w->visited ) {
                    q.push(w);
                    w->visited = true;
                }
            }
        }
        return res;
    }
};