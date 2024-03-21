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

int main(int argc, char const *argv[])
{
    int opt;
    bool solution = false;

    string in_name = "";
    string out_name = "";

    while ((opt = getopt(argc, (char *const *)argv, "ho:f:s")) != -1)
    {
        switch (opt)
        {
        case 'h':
            cout << "Help:\n"
                 << "-h           : mostra o help\n"
                 << "-o <arquivo> : redireciona a saida para o \"arquivo\"\n"
                 << "-f <arquivo> : indica o \"arquivo\" que contém o grafo de entrada\n"
                 << "-s           : mostra a solução\n";
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
        default:
            cerr << "Use: " << argv[0] << " [-h] [-o output_file] [-f input_file] [-s show_solution]\n";
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

    int u, v, w;

    for (int i = 0; i < m; i++){
        file_in >> u >> v >> w;
        u--, v--;
        E.push_back({u, v, w});
    }

    file_in.close();

    parent = vector<vertex>(n);
    ranks = vector<int>(n);
    kruskal();

    int resp = 0;

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
        for(Edge edge : mst){
            cout << "("<<edge.u+1<< ","<<edge.v+1<< ") ";
        }
    }else{
        int resp = 0;
        for(Edge edge : mst){
            resp += resp;
        }
        cout << resp << endl;
    }

    cout << endl;

    file_out.close();
}