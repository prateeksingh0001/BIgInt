#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

class AdjListNode{
    int dest;
    AdjListNode *nextNode;

    public:
    AdjListNode(int destination);
    friend class Graph;

    void next(AdjListNode *node){ nextNode = node;}

};

class AdjList{
    AdjListNode *head;
    
    public:
    AdjList(){ head = NULL;}
    friend class Graph;

    void addAdjListNode(int dest);
};
class Graph{
    int V;
    AdjList *array;

    public:
    Graph(int numVertices);

    void addEdge(int src, int dest){array[src].addAdjListNode(dest);}
    void print();
};

#endif

/*
 * TODO : * Add an implementation for the destructor that destroys the AdjListNode everytime
 *          an edge is removed from the graph.
 *
 *        * Also implement the graph contraction algorithm from the coursera course.
 */
