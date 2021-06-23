#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    //Utility function to run DFS on each node
    void DFSUtil(int v);

public:

    map<int,bool> visited;
    map<int,list<int>>adj;
    //Function to add edges to graph
    void addEdge(int v, int w);
    //Function to run DFS on all nodes of the graph
    void DFS();

};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v){
    if(!visited[v]){
        visited[v]=true;
        cout<< v <<" ";
        for(auto x:adj[v])
            DFSUtil(x);
    }
    else
        return;
}

void Graph::DFS(){
    for(auto i:adj){
        if(visited[i.first]==false)
            DFSUtil(i.first);
    }
}

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();
 
    return 0;
}