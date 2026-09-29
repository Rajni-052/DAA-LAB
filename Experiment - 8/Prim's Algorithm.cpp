#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);

    key[0] = 0;

    int totalWeight = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int count = 0; count < n; count++){
        int u = -1;

        for(int i = 0; i < n; i++){
            if(!mst[i] && (u == -1 || key[i] < key[u])){
                u = i;
            }
        }

        mst[u] = true;
        
        for(auto edge : graph[u]){
            int v = edge.first;
            int weight = edge.second;

            if(!mst[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout<< "Total weight of MST = " << totalWeight << endl;
    return 0;
}
