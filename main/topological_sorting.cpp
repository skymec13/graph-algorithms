#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
    void topSortUtil(int v, bool visited[], stack<int> &st);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topSortUtil(int v, bool visited[], stack<int> &st){
    visited[v]=true;
    for(auto x:adj[v]){
        if(!visited[x])
            topSortUtil(x, visited, st);
    }
    st.push(v);
}

void Graph::topologicalSort(){
    
    stack<int> st;
    bool* visited = new bool[V];
    
    for(int i=0; i<V; i++)
        visited[i]=false;

    for(int i=0;i<V;i++){
        if(!visited[i])
            topSortUtil(i,visited,st);
    }
    while(!st.empty()){
        cout<< st.top()<<" ";
        st.pop();
    }
}

// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}