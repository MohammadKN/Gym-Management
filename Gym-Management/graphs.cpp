#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void printGraph();

private:
    int vertices;
    std::vector<std::list<int>> adjList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // For undirected graph
}

void Graph::printGraph() {
    for (int v = 0; v < vertices; ++v) {
        std::cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adjList[v])
            std::cout << "-> " << x;
        std::cout << std::endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
