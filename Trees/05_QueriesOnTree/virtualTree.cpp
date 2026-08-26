#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(k log k) build, O(k) edges in virtual tree
// Virtual tree for k special nodes — uses LCA + monotonic stack
int n,kNodes,LOG;
vector<vector<int>> graph,up;
vector<int> depth,tin;
int timer=0;

void dfs(int node,int par){
    up[node][0]=par;
    tin[node]=++timer;
    for(int j=1;j<LOG;j++){
        if(up[node][j-1]!=-1)
            up[node][j]=up[up[node][j-1]][j-1];
    }
    for(auto t : graph[node]){
        if(t==par) continue;
        depth[t]=depth[node]+1;
        dfs(t,node);
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    int diff=depth[a]-depth[b];
    for(int j=0;j<LOG;j++){
        if(diff&(1<<j)) a=up[a][j];
    }
    if(a==b) return a;
    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}

vector<vector<int>> buildVirtualTree(vector<int> nodes){
    sort(nodes.begin(),nodes.end(),[&](int a,int b){
        return tin[a]<tin[b];
    });

    vector<int> st;
    vector<vector<int>> vtree;

    auto addNode=[&](int x){
        if((int)vtree.size()<=x) vtree.resize(x+1);
    };

    for(auto x : nodes){
        addNode(x);
        if(st.empty()){
            st.push_back(x);
            continue;
        }
        int c = lca(st.back(),x);
        addNode(c);
        if(c!=st.back()){
            while((int)st.size()>=2 && depth[st[(int)st.size()-2]]>=depth[c]){
                int a=st.back(); st.pop_back();
                int b=st.back();
                vtree[a].push_back(b);
                vtree[b].push_back(a);
            }
            if(st.back()!=c) st.push_back(c);
        }
        st.push_back(x);
    }

    while((int)st.size()>1){
        int a=st.back(); st.pop_back();
        int b=st.back();
        vtree[a].push_back(b);
        vtree[b].push_back(a);
    }

    return vtree;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    LOG=0;
    while((1<<LOG)<=n) LOG++;

    graph.resize(n+1);
    up.assign(n+1,vector<int>(LOG,-1));
    depth.assign(n+1,0);
    tin.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,-1);

    cin>>kNodes;
    vector<int> nodes(kNodes);
    for(int i=0;i<kNodes;i++) cin>>nodes[i];

    vector<vector<int>> vtree = buildVirtualTree(nodes);
    // run DP / dfs on vtree (much smaller than full tree)

    return 0;
}
