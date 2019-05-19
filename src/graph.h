#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Graph{
    std::vector<int> V;
    std::unordered_map<int, std::vector<int>> adjList;

    public:
    Graph(){srand((unsigned)time(NULL));}

    void readGraphFromFile(char *fileName);
    
    void addEdge(int src, int dest);
    void addVertex();
    void removeEdge(int src, int dest);
    void Contract(int src, int dest);
    
    int numVertices(){return adjList.size();}

    int kargerMinCut();

    void print();
};

#endif

/*
 * TODO : * Also create a way for differentiation between directed and undirected graphs.
 *
 * NOTES : * Basically I have to keep two vectors, one for nodes and the other one for their links.
 */
