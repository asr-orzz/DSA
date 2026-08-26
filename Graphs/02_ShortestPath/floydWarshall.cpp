#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V^3)
// All-pairs shortest paths
// Works with Negative Edges; detects Negative Cycles via dist[i][i] < 0
const ll INF = 1e18;

int n,m;
vector<vector<ll>> dist;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    dist.assign(n+1,vector<ll>(n+1,INF));

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],(ll)w); // handle multi-edges
    }

    for(int i=1;i<=n;i++) dist[i][i]=0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]==INF || dist[k][j]==INF) continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    // Negative cycle if any dist[i][i] < 0 after FW
    bool negativeCycle=0;
    for(int i=1;i<=n;i++){
        if(dist[i][i]<0) negativeCycle=1;
    }
    

    return 0;
}
