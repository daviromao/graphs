
#include "graph.h"

using namespace std;

Graph createGraph(int V){
    Graph G = new graph;
    G->V = V;
    G->E = 0;
    G->adj.resize(V);
    return G;
}

void addEdge(Graph G, vertex src, vertex dest, int weight){
    Edge edge;
    edge.u = src;
    edge.v = dest;
    edge.weight = weight;
    G->adj[src].push_back(edge);
    G->E++;
}

void addUndirectEdge(Graph G, vertex src, vertex dest, int weight){
    addEdge(G, src, dest, weight);
    addEdge(G, dest, src, weight);
}
