#include<bits/stdc++.h>
using namespace std;

//Utility function to add vertices to graph nodes
void addEdge(vector<int> adj[],int u,int v){
    
    adj[u].push_back(v);
    adj[v].push_back(u);

}

//Utility function to print vertices of graph nodes
void printGraph(vector<int> adj[], int V){
    for(int i = 0; i < V; i++){
       cout<<"Adjacency vertex of "<<i<<"th node: ";
       for(auto x: adj[i])
           cout<<"->"<<x;
        cout<<endl;
    }
}

int main(){
    
    //get the number of vertices for the graph
    //cout<<"Enter the number of nodes/vertices:"<<endl;
    int V = 5;
    //cin >> V;

    //Using dynamic array (i.e. vector) to represent the adjacency list
    //We need an array of vector of size V
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
