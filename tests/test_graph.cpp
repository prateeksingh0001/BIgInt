#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../src/graph.h"

using namespace std;

int main(){
    ifstream infile;
    string word;

    infile.open("coursera_assignments/krager_min.txt");
    Graph G;
    
    while(getline(infile, word)){
        istringstream iss(word);
        string token;

        vector<int> edges;
        while(getline(iss, token, '\t')){
            edges.push_back(stoi(token));
        }

        //cout<<"fininshed upto here"<<endl;

        for(int i=1; i<edges.size(); i++){
            G.addEdge(edges[0], edges[i]);
        }

        //cout<<endl;
    }

    
    while(true){
        Graph P = G;
        cout<<P.kargerMinCut()<<endl;
        //if(P.kargerMinCut()== 17){
            //cout<<"Found the min cut to be 17"<<endl;
            //break;   
        //}
    }
    /*
    while(karger>>word){
        cout<<word<<endl;
    }*/
    return 0;
}

/*
int main(){
    Graph G;
    cout<<"reached here"<<endl;
    G.addEdge(0, 1);
    G.addEdge(0, 4);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    
    G.print();

    //G.removeEdge(0, 1);
    //G.removeEdge(1, 3);
    //G.removeEdge(2, 3);

    cout<<G.kargerMinCut()<<endl;
    G.print();

    //G.mergeVertices(0, 4);
    //G.print();

    return 0;
}*/

