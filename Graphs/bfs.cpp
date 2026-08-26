#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

int n,m;
vector<vector<int>> graph;
vector<int> dist;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,1e9);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    cin>>src;
    
    queue<int> q;
    q.push(src);
    dist[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto t : graph[node]){
            if(dist[t]>dist[node]+1){ //this cares about visited thing also in BFS
                dist[t]=dist[node]+1;
                q.push(t);
            }
        }
    }

    return 0;
}