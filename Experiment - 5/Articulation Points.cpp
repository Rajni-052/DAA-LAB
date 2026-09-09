#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];

int timer = 0;
int tin[100], low[100];
bool vis[100];
bool ap[100];

void dfs(int u, int par){
    vis[u] = true;

    tin[u] = low[u] = timer++;
    int child = 0;

    for(int v : adj[u]){
        if(v == par)
            continue;

        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if(par != -1 && low[v] >= tin[u]){
                ap[u] = true;
            }

            child++;
        }
    }

    if(par == -1 && child > 1){
        ap[u] = true;
    }
}

int main(){
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }

    cout << "Articulation Points are: ";

    for(int i = 0; i < n; i++){
        if(ap[i]){
            cout << i << " ";
        }
    }

    return 0;
}
