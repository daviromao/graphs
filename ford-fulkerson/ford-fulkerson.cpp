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
    q.push({s, INT_MAX});

    while(!q.empty()){
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int neighbor : adj[current]){
            if(parent[neighbor] == -1 && residual[current][neighbor] > 0){
                parent[neighbor] = current;
                int min_cf = min(flow, residual[current][neighbor]);
                if(neighbor == t) return min_cf;
                q.push({neighbor, min_cf});
            }
        }
    }

    return 0;
}

int ford_fulkerson(vertex s, vertex t){
    int flow = 0;
    vector<int> parent(n);
    int cf = 0;

    while((cf = bfs(s, t, parent)))
    {
        flow += cf;
        // arc u -> v
        int v = t;
        while(v != s){
            int u = parent[v];
            residual[u][v] -= cf;
            residual[v][u] += cf;
            v = u;
        }
        
    }
    return flow;
}

int main(){
    cin >> n >> m;

    residual = vector<vector<int>>(n, vector<int>(n, 0));
    adj = vector<vector<vertex>>(n, vector<int>());

    int u, v, c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--; v--;
        residual[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s=1, t=n;
    s--; t--;
    
    cout << ford_fulkerson(s, t) << endl;;

}