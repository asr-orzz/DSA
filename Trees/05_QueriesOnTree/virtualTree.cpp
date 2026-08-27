#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(k log k) build
// Virtual Tree for k special nodes (LCA + stack)
int n,k,LOG;
vector<vector<int>> graph,up,vtree;
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

void addEdge(int a,int b){
    vtree[a].push_back(b);
    vtree[b].push_back(a);
}

void buildVT(vector<int> nodes){
    sort(nodes.begin(),nodes.end(),[](int a,int b){
        return tin[a]<tin[b];
    });

    int sz=nodes.size();
    for(int i=0;i<sz-1;i++) nodes.push_back(lca(nodes[i],nodes[i+1]));

    sort(nodes.begin(),nodes.end(),[](int a,int b){
        return tin[a]<tin[b];
    });
    nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());

    vtree.assign(n+1,vector<int>());
    vector<int> st;

    for(auto x : nodes){
        while((int)st.size()>=2){
            int c = lca(st.back(),x);
            if(depth[c]>=depth[st[(int)st.size()-2]]) break;
            addEdge(st[(int)st.size()-2],st.back());
            st.pop_back();
        }
        if(!st.empty()){
            int c = lca(st.back(),x);
            if(c!=st.back()){
                addEdge(c,st.back());
                st.pop_back();
                st.push_back(c);
            }
        }
        st.push_back(x);
    }

    while((int)st.size()>1){
        addEdge(st[(int)st.size()-2],st.back());
        st.pop_back();
    }
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

    cin>>k;
    vector<int> nodes(k);
    for(int i=0;i<k;i++) cin>>nodes[i];

    buildVT(nodes);
    // now dfs / dp on vtree

    return 0;
}
