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

int main(int argc, char const *argv[])
{
    int opt;
    bool solution = false;
    int initial_vertex = 0;

    string in_name = "";
    string out_name = "";

    while ((opt = getopt(argc, (char *const *)argv, "ho:f:si:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            cout << "Help:\n"
                 << "-h           : mostra o help\n"
                 << "-o <arquivo> : redireciona a saida para o \"arquivo\"\n"
                 << "-f <arquivo> : indica o \"arquivo\" que contém o grafo de entrada\n"
                 << "-s           : mostra a solução\n"
                 << "-i           : vértice inicial\n";
            return 0;
        case 's':
            solution = true;
            break;
        case 'f':
            in_name = optarg;
            break;
        case 'o':
            out_name = optarg;
            break;
        case 'i':
            initial_vertex = stoi(optarg) - 1;
            break;
        default:
            cerr << "Use: " << argv[0] << " [-h] [-o output_file] [-f input_file] [-s show solution] [-i initial_vertex]\n";
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

    int n, m;
    file_in >> n >> m;
    Graph G = createGraph(n);
    vector<vertex> parent(n, -1);
    vector<int> cost(n, INT_MAX);

    for (int i=0; i<m; i++) {
        int u, v, w;
        file_in >> u >> v >> w;
        u--, v--;
        addUndirectEdge(G, u, v, w);
    }

    file_in.close();

    prim(G, initial_vertex, parent, cost);

    ofstream file_out;
    if (out_name != "")
    {
        file_out.open(out_name);
        if (!file_out)
        {
            cerr << "Não foi possível gravar no arquivo: " << out_name << endl;
            return EXIT_FAILURE;
        }
        cout.rdbuf(file_out.rdbuf());
    }

    if(solution){
        for(vertex v = 0; v < n; v++){
            if(v==initial_vertex) continue;
            cout << "("<<parent[v]+1<< ","<<v+1<< ") ";
        }
        cout << endl;
    }else{
        int tc = 0;
        for(int i = 0; i < n; i++){
            tc += cost[i];
        }

        cout << tc << endl;
    }

    return 0;
}