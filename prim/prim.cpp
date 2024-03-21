#include <bits/stdc++.h>
#include "../lib/graph.h"

using namespace std;

void prim(Graph G, vertex s, vector<vertex> &parent, vector<int> &cost) {
    vector<bool> visited(G->V, false);

    cost[s] = 0;
    priority_queue<VertexCost> H;
    H.push(VertexCost{s, 0});

    while(!H.empty()){

        VertexCost current = H.top();
        H.pop();

        if(visited[current.v]) continue;

        for(Edge edge : G->adj[current.v]){
            if ((cost[edge.v] > edge.weight) && !visited[edge.v])
            {
                cost[edge.v] = edge.weight;
                parent[edge.v] = current.v;
                H.push(VertexCost{edge.v, cost[edge.v]});
            }
        }
        

        visited[current.v] = true;
    }

}

int main ()
{   
    int n, m;
    cin >> n >> m;

    Graph G = createGraph(n);
    vector<vertex> parent(n, -1);
    vector<int> cost(n, INFINITY);

    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        addUndirectEdge(G, u, v, w);
    }

    prim(G, 0, parent, cost);
    int tc = 0;
    for(int i = 0; i < n; i++){
        // cout << i+1 <<":"<<cost[i] << " ";
        tc += cost[i];
    }

    cout << tc << "\n";

    return 0;
}