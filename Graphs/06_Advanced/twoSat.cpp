#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// 2-SAT via implication graph + Kosaraju SCC
// vars: 0..n-1 ; node 2*i = x_i false, 2*i+1 = x_i true
int n,m; // n vars, m clauses
vector<vector<int>> graph,rev;
vector<int> vis,order,comp;

void dfs1(int node){
    vis[node]=1;
    for(auto t : graph[node]){
        if(!vis[t]) dfs1(t);
    }
    order.push_back(node);
}

void dfs2(int node,int c){
    comp[node]=c;
    for(auto t : rev[node]){
        if(comp[t]==-1) dfs2(t,c);
    }
}

int neg(int x){ return x^1; }

void addImp(int a,int b){
    // a => b
    graph[a].push_back(b);
    rev[b].push_back(a);
}

void addOr(int a,int b){
    // a OR b  <=>  (~a => b) and (~b => a)
    addImp(neg(a),b);
    addImp(neg(b),a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    int N=2*n;
    graph.resize(N);
    rev.resize(N);
    vis.assign(N,0);
    comp.assign(N,-1);

    for(int i=0;i<m;i++){
        int x,y,sx,sy;
        // clause: (x with sign sx) OR (y with sign sy)
        // sx/sy = 1 means true literal, 0 means negated
        cin>>x>>sx>>y>>sy;
        x--; y--;
        int a = 2*x + sx;
        int b = 2*y + sy;
        addOr(a,b);
    }

    for(int i=0;i<N;i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(order.begin(),order.end());

    int sccCount=0;
    for(auto node : order){
        if(comp[node]==-1){
            dfs2(node,sccCount);
            sccCount++;
        }
    }

    vector<int> assignment(n);
    bool ok=1;
    for(int i=0;i<n;i++){
        if(comp[2*i]==comp[2*i+1]){
            ok=0; // unsatisfiable
            break;
        }
        // true if true-literal SCC is later (processed earlier in topo of condensation)
        assignment[i] = comp[2*i]<comp[2*i+1];
    }

    // if(!ok) UNSAT else assignment[] is a valid solution

    return 0;
}
