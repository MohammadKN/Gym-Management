#pragma once

#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void displayGraph();

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
    adjList[w].push_back(v); 
}

void Graph::displayGraph() {
    for (int v = 0; v < vertices; ++v) {
        std::cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adjList[v])
            std::cout << "-> " << x;
        std::cout << std::endl;
    }
}

