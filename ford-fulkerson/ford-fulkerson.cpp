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

int main(int argc, char const *argv[])
{
    int opt;
    string in_name = "";
    string out_name = "";

    while ((opt = getopt(argc, (char *const *)argv, "ho:f:s:t:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            cout << "Help:\n"
                 << "Entrada recebe n e m, o número de vértices e arestas do grafo, respectivamente.\n"
                 << "Em seguida, m linhas com 3 inteiros u, v e c, indicando que há uma aresta de u para v com capacidade c.\n"
                 << "Por fim, dois inteiros s e t, indicando a fonte e o target do grafo.\n"
                 << " -h           : mostra o help\n"
                 << " -o <arquivo> : redireciona a saida para o \"arquivo\"\n"
                 << " -f <arquivo> : indica o \"arquivo\" que contém o grafo de entrada\n";
            return 0;
        case 'f':
            in_name = optarg;
            break;
        case 'o':
            out_name = optarg;
            break;
            break;
        default:
            cerr << "Use: " << argv[0] << " [-h] [-o output_file] [-f input_file]\n";
            return EXIT_FAILURE;
        }
    }

    if (in_name == "")
    {
        cerr << "Especifique o arquivo de entrada! Utilize: -f" << endl;
        return EXIT_FAILURE;
    }

    ifstream file_in(in_name);

    if (not file_in)
    {
        cerr << "Não foi possível abrir o arquivo: " << in_name << endl;
        return EXIT_FAILURE;
    }

    file_in >> n >> m;

    residual = vector<vector<int>>(n, vector<int>(n, 0));
    adj = vector<vector<vertex>>(n, vector<int>());

    int u, v, c;
    for(int i = 0; i < m; i++){
        file_in >> u >> v >> c;
        u--; v--;
        residual[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int s, t;
    file_in >> s >> t;
    s--; t--;

    file_in.close();

    ofstream file_out;
    if (out_name != "")
    {
        file_out.open(out_name);
        if (not file_out)
        {
            cerr << "Não foi possível abrir o arquivo: " << out_name << endl;
            return EXIT_FAILURE;
        }
        cout.rdbuf(file_out.rdbuf());
    }
    cout << ford_fulkerson(s, t) << endl;;

    file_out.close();
}