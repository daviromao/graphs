#include <iostream>
#include <algorithm>
#include "../lib/graph.h"

vertex find(vertex u, vertex parent[]){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u], parent);
}

void join(vertex u, vertex v, int rank[], vertex parent[]){

    if(rank[u] >= rank[v]){
        parent[v]=u;
        if(rank[u] == rank[v]){
            rank[u]++;
        }
    }else{
        parent[u] = v;
        if (rank[u] == rank[v])
        {
            rank[v]++;
        }
    }
}

void kruskal(Graph G, vector<Edge> E, vector<Edge> &mst){
    sort(E.begin(), E.end());

    vertex parent[G->V];
    int rank[G->V];

    //make-set
    for(int v = 0; v < G->V; v++){
        parent[v] = v;
        rank[v] = 1;
    }

    for(Edge e : E)
    {
        vertex u = find(e.u, parent);
        vertex v = find(e.v, parent);

        if(u != v){
            mst.push_back(e);
            join(u, v, rank, parent);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    Graph G = createGraph(n);
    vector<Edge> mst;
    vector<Edge> E;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        E.push_back({u, v, w});
        addUndirectEdge(G, u, v, w);
    }

    kruskal(G, E, mst);

    int resp = 0;
    
    for(Edge e : mst){
        resp+= e.weight;
    }

    cout << resp << endl;
}