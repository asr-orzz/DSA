#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Bipartite check via 2-coloring (BFS)
int n,m;
vector<vector<int>> graph;
vector<int> color;
bool bipartite=1;

void bfs(int src){
    queue<int> q;
    q.push(src);
    color[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto t : graph[node]){
            if(color[t]==-1){
                color[t]=color[node]^1;
                q.push(t);
            }
            else if(color[t]==color[node]){
                bipartite=0;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    color.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==-1) bfs(i);
        if(!bipartite) break;
    }
    
    // if(!bipartite) odd cycle exists

    return 0;
}
