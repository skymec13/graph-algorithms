#include<iostream>
#include<list>
#include<stack>
#include<climits>
#define INF INT_MAX

using namespace std;

class adjListNode{
    int y;
    int wt;
public:
    adjListNode(int y, int wt){
        this->y = y;
        this->wt = wt;
    }
    int getY(){ return y;}
    int getWt(){ return wt;}
};

class Graph{
    int V;
    list<adjListNode>* adj;
    void topSortUtil(int s, bool visited[], stack<int> &st);
public:
    Graph(int V);
    void addEdge(int x, int y, int wt);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<adjListNode>[V];
}

void Graph::addEdge(int x, int y, int wt){
    adjListNode node(y,wt);
    adj[x].push_back(node);
}

void Graph::topSortUtil(int s, bool visited[], stack<int> &st){
    visited[s] = true;
    list<adjListNode>::iterator i;
    for(i = adj[s].begin(); i!=adj[s].end(); i++){
        adjListNode node = *i;
        if(!visited[node.getY()])
            topSortUtil(node.getY(), visited, st);
    }
    st.push(s);
}

void Graph::shortestPath(int s){
    bool *visited = new bool[V];
    int *dist = new int[V];
    stack<int> st;

    for(int i=0; i<V; i++){
        visited[i]=false;
        dist[i] = INF;
    }
    dist[s] = 0;

    for(int i=0; i<V; i++){
        if(!visited[i])
            topSortUtil(i, visited, st);
    }
    while(!st.empty()){
        int v = st.top(); st.pop();
        list<adjListNode>::iterator it;
        if(dist[v]!=INF){
            for(it = adj[v].begin(); it!=adj[v].end(); it++){
                adjListNode node = *it;
                if(dist[node.getY()]>dist[v]+node.getWt())
                    dist[node.getY()] = dist[v]+node.getWt();
            }
        }
    }
    for(int i=0;i<V;i++)
        (dist[i]==INF)? cout<< "INF ": cout<<dist[i]<<" ";
}



// Driver Code
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
  
    int s = 1;
    cout << "Following are shortest distances from source " << s <<"\n";
    g.shortestPath(s);
  
    return 0;
}