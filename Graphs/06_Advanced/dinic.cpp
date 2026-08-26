#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V^2 E) worst, usually faster
// Max Flow — Dinic
const ll INF = 1e18;

struct Edge{
    int to;
    ll cap;
    int rev;
};

int n,m,s,t;
vector<vector<Edge>> g;
vector<int> level,it;

void addEdge(int u,int v,ll c){
    Edge a={v,c,(int)g[v].size()};
    Edge b={u,0,(int)g[u].size()};
    g[u].push_back(a);
    g[v].push_back(b);
}

bool bfs(){
    fill(level.begin(),level.end(),-1);
    queue<int> q;
    level[s]=0;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &e : g[node]){
            if(e.cap>0 && level[e.to]<0){
                level[e.to]=level[node]+1;
                q.push(e.to);
            }
        }
    }
    return level[t]>=0;
}

ll dfs(int node,ll f){
    if(node==t) return f;
    for(int &i=it[node];i<(int)g[node].size();i++){
        Edge &e = g[node][i];
        if(e.cap>0 && level[e.to]==level[node]+1){
            ll pushed = dfs(e.to,min(f,e.cap));
            if(pushed>0){
                e.cap-=pushed;
                g[e.to][e.rev].cap+=pushed;
                return pushed;
            }
        }
    }
    return 0;
}

ll maxFlow(){
    ll flow=0;
    while(bfs()){
        fill(it.begin(),it.end(),0);
        while(ll pushed=dfs(s,INF)){
            flow+=pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m>>s>>t;
    g.resize(n+1);
    level.resize(n+1);
    it.resize(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        ll c;
        cin>>u>>v>>c;
        addEdge(u,v,c);
    }

    ll ans = maxFlow();
    // cout<<ans<<"\n";

    return 0;
}
