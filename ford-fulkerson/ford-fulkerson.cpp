#include <bits/stdc++.h>
#define vertex int

using namespace std;

int n, m;
vector<vector<int>> residual;
vector<vector<vertex>> adj;

int bfs(vertex s, vertex t, vector<vertex> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = s;

    //<vertex, minimum flow that reached it>
    queue<pair<vertex, int>> q;
    q.push({s, INFINITY});
}

int ford_fulkerson(vertex s, vertex t){
    int flow = 0;
    vector<int> parent(n);
    int cf = 0;

    while(cf = bfs(s, t, parent)){
        // arc u -> v
        int v = t;
        while(v != s){
            int u = parent[v];
            residual[u][v] -= cf;
            residual[v][u] += cf;
        }
    }

    return flow;
}

int main(){
    cout << INFINITY << endl;
    exit(0);
    cin >> n >> m;

    residual = vector<vector<int>>(n, vector<int>(n, 0));
    
    int u, v, c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        residual[u][v] = c;
    }

    int s, t;

    cin >> s >> t;

    ford_fulkerson(s, t);


}