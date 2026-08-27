#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Tree diameter via two BFS from farthest node
int n;
vector<vector<int>> graph;
vector<int> dist;

void bfs(int src){
    fill(dist.begin(),dist.end(),-1);
    queue<int> q;
    q.push(src);
    dist[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto t : graph[node]){
            if(dist[t]!=-1) continue;
            dist[t]=dist[node]+1;
            q.push(t);
        }
    }
}

int farthest(){
    int node=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[node]) node=i;
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    dist.assign(n+1,-1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    int u = farthest();
    bfs(u);
    int v = farthest();
    int diameter = dist[v]; // longest path = u ... v

    return 0;
}
