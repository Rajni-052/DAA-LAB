#include<iostream>
#include<vector>
using namespace std;

struct Edge{
    int u,v,wt;
};

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;

    vector<Edge> edges(E);
    cout<<"Enter source, destination and weight of each edge:\n";

    for(int i=0;i<E;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].wt;
    }

    int src;
    cout<<"Enter source vertex: ";
    cin>>src;

    vector<int> dist(V,1e9);
    dist[src]=0;

    for(int i=1;i<V;i++){
        bool updated=false;

        for(auto edge:edges){
            int u=edge.u;
            int v=edge.v;
            int wt=edge.wt;

            if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                updated=true;
            }
        }

        if(!updated) break;
    }

    for(auto edge:edges){
        int u=edge.u;
        int v=edge.v;
        int wt=edge.wt;

        if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
            cout<<"Negative weight cycle detected\n";
            return 0;
        }
    }

    cout<<"Shortest distances from source vertex "<<src<<":\n";
    for(int i=0;i<V;i++){
        if(dist[i]==1e9)
            cout<<src<<" to "<<i<<": Not reachable\n";
        else
            cout<<src<<" to "<<i<<": "<<dist[i]<<"\n";
    }

    return 0;
}
