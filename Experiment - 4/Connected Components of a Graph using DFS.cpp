//Name -> Rajni
//Roll No. -> 25/DA/052
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int> > &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i=0; i<adj[node].size(); i++) {
        int neighbour = adj[node][i];
        if(!visited[neighbour]){
            DFS(neighbour, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int> > adj(V);

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    int components = 0;

    cout << "\nConnected Components:\n";

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            DFS(i, adj, visited);
            cout << endl;
        }
    }

    cout << "\nTotal number of connected components: "<< components << endl;
    return 0;
}
