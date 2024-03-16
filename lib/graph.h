#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#define vertex int

class VertexCost{
    public:
        vertex v;
        int cost;
    bool operator<(const VertexCost &other) const{
        return cost > other.cost;
    }
};

class Edge {
    public:
        vertex u;
        vertex v;
        int weight;
    bool operator<(const Edge &other) const{
        return weight < other.weight;
    }
};

using namespace std;

struct graph
{
    int V;
    int E;
    vector<vector<Edge>> adj;
};

typedef struct graph *Graph;

Graph createGraph(int V);
void addEdge(Graph G, vertex src, vertex dest, int weight);
void addUndirectEdge(Graph G, vertex src, vertex dest, int weight);
#endif