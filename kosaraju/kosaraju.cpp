#include <bits/stdc++.h>
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

int main(int argc, char const *argv[])
{
    int opt;

    string in_name = "";
    string out_name = "";

    while ((opt = getopt(argc, (char *const *)argv, "ho:f:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            cout << "Help:\n"
                 << "-h           : mostra o help\n"
                 << "-o <arquivo> : redireciona a saida para o \"arquivo\"\n"
                 << "-f <arquivo> : indica o \"arquivo\" que contém o grafo de entrada\n";
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

    int n, m;
    file_in >> n >> m;

    vector<vertex> post(n, -1);
    vector<vertex> sc(n, -1);
    Graph G = createGraph(n);
    Graph Gr = createGraph(n);
    
    for(int i = 0; i < m; i++){
        int u, v;
        file_in >> u >> v;
        u--, v--;
        addEdge(G, u, v, 0);
        addEdge(Gr, v, u, 0); // reverse graph
    }
    
    file_in.close();

    Kosaraju(G, Gr, post);

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

    for(auto cc:components){
        for(auto v:cc){
            cout << v+1 << " "; 
        }
        cout << endl;
    }

    file_out.close();
}