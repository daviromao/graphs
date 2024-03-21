#include <bits/stdc++.h>
#include "../lib/graph.h"

using namespace std;

void solve(Graph G, vertex s, vector<vertex> &parent, vector<int> &dist){
    vector<bool> visited(G->V, false);

    dist[s] = 0;
    priority_queue<VertexCost> H;
    H.push(VertexCost{s, 0});

    while(!H.empty()){

        VertexCost current = H.top();
        H.pop();

        if(visited[current.v]) continue;


        for(Edge edge : G->adj[current.v]){
            if ((dist[edge.v] > dist[current.v] + edge.weight) && !visited[edge.v]){
                dist[edge.v] = dist[current.v] + edge.weight;
                parent[edge.v] = current.v;
                H.push(VertexCost{edge.v, dist[edge.v]});
            }
        }

        visited[current.v] = true;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    Graph G = createGraph(n);
    vector<vertex> parent(n, -1);
    vector<int> dist(n, INT_MAX);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        addUndirectEdge(G, u, v, w);
    }

    solve(G, 0, parent, dist);

    for(int i = 0; i < n; i++){
        cout << i+1 <<":"<<dist[i] << " ";
    }

    cout << endl;
}