#include<iostream>
#include<map>
#include<list>

using namespace std;

//Implementation for connected directed graph
class Graph{
public:
    map<int, bool> visited;
    map<int,list<int>> adj;

    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w){
    //Directed graph
    adj[v].push_back(w);
}

void Graph::DFS(int v){
    visited[v] = true;
    cout<< v << " ";
    for(auto x:adj[v]){
        if(!visited[x])
            DFS(x);
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

    cout<< "Following is the depth first traversal (starting from vertex 2): \n";
    g.DFS(2);
    return 0;
}
