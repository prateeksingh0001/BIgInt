#include "graph.h"

AdjListNode::AdjListNode(int destination){
    dest = destination;
    nextNode = NULL;
}


void AdjList::addAdjListNode(int dest){
    AdjListNode *newNode = new AdjListNode(dest);
    newNode->next(head);
    head = newNode ;
}

Graph::Graph(int numVertices){
    V = numVertices;
    array = new AdjList[V];
}

void Graph::print(){
    for(int i=0; i<V; i++){
        AdjListNode *pCrawl = array[i].head ;
        std::cout<<"Nodes adjacent to vertex "<<i<<" are: ";
        while(pCrawl){
            std::cout<<pCrawl->dest<<"  ";
            pCrawl = pCrawl->nextNode ;
        }
        std::cout<<std::endl ;
    }
}
