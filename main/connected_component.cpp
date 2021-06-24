#include<iostream>
#include<map>
#include<list>
using namespace std;

int count = 0;
map<int, list<int>> cc;

class Graph{
    void DFSUtil(int v, int c);
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS();
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, int c){
    if(!visited[v]){
        visited[v]=true;
        cc[c].push_back(v);
        for(auto x:adj[v])
            DFSUtil(x,c);
    }
}

void Graph::DFS(){
    for(auto x:adj){
        if(!visited[x.first]){
            DFSUtil(x.first, count);
        }
        count++;
    }
}

int main(){
    Graph g;
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();
    cout<<"the connected components are: \n"<<endl;
    for(auto x:cc){
        for(auto y:x.second)
            cout<<y<<"->";
        cout<<endl;
    }
 
    return 0;
}
