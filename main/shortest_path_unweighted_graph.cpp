#include<iostream>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int>* adj;
    
public:
    Graph(int V);    
    void addEdge(int v, int w);
    vector<int> shortestPath(int src, int dest);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

vector<int> Graph::shortestPath(int src, int dest){
    bool* visited = new bool[V];
    int* prev = new int[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
        prev[i] = -1;
    }
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto x:adj[p]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                prev[x] = p; 
            }
        }
    }
    vector<int> path;
    for(int at = dest; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(),path.end());
    return path;  
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    int src = 0, dest = 7;
    vector<int> res; 
    res = g.shortestPath(src, dest);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}