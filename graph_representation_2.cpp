#include<stdio.h>
#include<vector>
#include<ostream>
#include<iostream>

using namespace std;

//Utility function to add vertices to graph nodes
void addEdge(vector<pair<int, int>> adj[],int u,int v, int wt){
    
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));

}

//Utility function to print vertices of graph nodes
void printGraph(vector<pair<int,int>> adj[], int V){
    for(int i = 0; i < V; i++){
       cout<<"Node "<<i<<" make an edge with\n";
       for(auto it=adj[i].begin();it!=adj[i].end();it++)
           cout<<"Node "<<it->first<<" with edge weight "<<it->second<<endl;
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
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    return 0;
}