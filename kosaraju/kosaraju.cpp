#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include "../lib/graph.h"

using namespace std;

vector<vector<int>> components;
int scc = 0;

void dfsPos(Graph G, vertex v, vector<vertex> &post, vector<bool> &visited, int &cont){
    visited[v] = true;

    for(Edge edge : G->adj[v]){
        if(visited[edge.v] == false){
            dfsPos(G, edge.v, post, visited, cont);
        }
    }

    post[cont++] = v;
}

void dfsRstrongComp(Graph G, vertex v, vector<bool> &visited){
    visited[v] = true;

    for(Edge edge : G->adj[v]){
        if(!(visited[edge.v])){
            components[scc].push_back(edge.v);
            dfsRstrongComp(G, edge.v, visited);
        }  
    }
}

void Kosaraju(Graph G, Graph Gr, vector<vertex> &post) {
    int cont = 0;
    
    vector<bool> visited(G->V, false);
    for(int i = 0; i < G->V; i++){
        if(!(visited[i])){
            dfsPos(Gr, i, post, visited, cont);
        }
    }

    fill(visited.begin(), visited.end(), false);

    for(int i = G->V-1; i >= 0; i--){
        int v = post[i];
        if(!(visited[v])){
            components.push_back({v});
            dfsRstrongComp(G, v, visited);   
            scc++;
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vertex> post(n, -1);
    vector<vertex> sc(n, -1);
    Graph G = createGraph(n);
    Graph Gr = createGraph(n);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        addEdge(G, u, v, 0);
        addEdge(Gr, v, u, 0); // reverse graph
    }
    
    Kosaraju(G, Gr, post);

    for(auto cc:components){
        for(auto v:cc){
            cout << v+1 << " "; 
        }
        cout << endl;
    }
    
}