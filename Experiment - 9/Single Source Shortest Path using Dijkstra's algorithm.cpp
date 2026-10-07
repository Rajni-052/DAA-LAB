//Name -> Rajni
//Roll No. -> 25/A07/052

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int source){
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[source] = 0;

    for (int i = 0; i < n; i++){
        int u = -1;

        for (int j = 0; j < n; j++){
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    cout << "\nShortest distances from source vertex " << source << ":\n";

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << source << " -> " << i << " = INF\n";
        else
            cout << source << " -> " << i << " = " << dist[i] << "\n";
    }
}

int main(){
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(n, adj, source);

    return 0;
}
