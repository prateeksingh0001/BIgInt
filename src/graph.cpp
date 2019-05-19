#include "graph.h"

void Graph::addEdge(int src, int dest){
    
    if(std::find(V.begin(), V.end(), dest) == V.end())
        V.push_back(dest);
    adjList[src].push_back(dest);
    
    //if(std::find(V.begin(), V.end(), src) == V.end())
       // V.push_back(src);
    //adjList[dest].push_back(src);
}

void Graph::removeEdge(int src, int dest){
    std::vector<int>::iterator node_pos;

    if((node_pos = std::find(adjList[src].begin(), 
                adjList[src].end(), dest)) != adjList[src].end()){
        adjList[src].erase(node_pos);
    }

    if((node_pos = std::find(adjList[dest].begin(),
                adjList[dest].end(), src)) != adjList[dest].end()){
        adjList[dest].erase(node_pos);
    }
}

void Graph::Contract(int V1, int V2){
    std::unordered_map<int, std::vector<int>>::iterator node;
    std::vector<int>::iterator it = adjList[V1].begin();

    //node = std::find(adjList.begin(), adjList.end(), adjList[V2]);
    
    adjList[V1].insert(adjList[V1].end(), adjList[V2].begin(), adjList[V2].end());

    for(it = adjList[V2].begin(); it != adjList[V2].end(); it++){
        auto node_pos = std::find(adjList[*it].begin(), adjList[*it].end(), V2);
        *node_pos = V1;
    }
    //removing self_loops
    while((it = std::find(adjList[V1].begin(), 
                    adjList[V1].end(), V1)) != adjList[V1].end()){
        adjList[V1].erase(it);
    }

    adjList.erase(adjList.find(V2));
    V.erase(std::find(V.begin(), V.end(), V2));
}

int Graph::kargerMinCut(){
    int vertices = adjList.size();

    //srand((unsigned)time(NULL));
    while(adjList.size() > 2){
        //int V1 = rand()%adjList.size();
        int V1 = rand();
        //std::cout<<V1<<std::endl;
        V1 = V[V1%V.size()];
        //std::cout<<V1<<std::endl;

        //int V2 = adjList[V1][rand()%adjList[V1].size()];
        int V2 = rand();
        //std::cout<<V2<<std::endl;
        V2 = adjList[V1][V2%adjList[V1].size()];
        //std::cout<<V2<<std::endl;


        //std::cout<<"Contracting edges "<<V1<<" and "<<V2<<std::endl;
        Contract(V1, V2);
        //print();
    }
    return adjList[V[0]].size();
}

void Graph::print(){
    size_t V = adjList.size();
    std::unordered_map<int, std::vector<int>>::iterator it;

    for(it=adjList.begin(); it != adjList.end(); it++){
        std::cout<<"Nodes adjacent to vertex"<< it->first <<" are ";
        int size = it->second.size();
        for(int j=0; j<size; j++){
            std::cout<<it->second[j]<<"  ";
        }
        std::cout<<std::endl;
    }
}

