#include <bits/stdc++.h>
#include "../lib/graph.h"

vector<vertex> parent;
vector<int> ranks;
vector<Edge> mst;
vector<Edge> E;
int n, m;

vertex find(vertex u)
{
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void union_sets(vertex u, vertex v)
{
    if(ranks[u] < ranks[v])
        swap(u, v);

    parent[v] = u;

    if(ranks[u] == ranks[v])
        ranks[u]++;
}

void make_set(vertex u)
{
    parent[u] = u;
    ranks[u] = 0;
}

void kruskal()
{
    sort(E.begin(), E.end());

    for(int u = 0; u < n; u++)
        make_set(u);

    for(Edge edge : E){
        vertex u = find(edge.u);
        vertex v = find(edge.v);

        if(u != v){
            mst.push_back(edge);
            union_sets(u, v);
        }
    }
}

int main()
{
    cin >> n >> m;

    int u, v, w;

    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--, v--;
        E.push_back({u, v, w});
    }

    parent = vector<vertex>(n);
    ranks = vector<int>(n);

    kruskal();

    int resp = 0;
    
    for(Edge edge : mst){
        resp+= edge.weight;
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
}