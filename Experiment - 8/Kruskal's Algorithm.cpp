#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent){
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(u == v) return;

    if(rank[u] < rank[v]) parent[u] = v;
    
    else if(rank[u] > rank[v]) parent[v] = u;
    
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int totalWeight = 0;
    int edgesUsed = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (auto edge : edges) {

        int u = findParent(edge.u, parent);
        int v = findParent(edge.v, parent);

        if(u != v){

            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;

            totalWeight += edge.weight;
            edgesUsed++;

            unionSet(u, v, parent, rank);

            if(edgesUsed == n - 1) break;
        }
    }

    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}
