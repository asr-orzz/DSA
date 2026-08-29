#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N * BITS)
// Max XOR pair using a binary trie (greedy from MSB)
const int BITS = 30; // enough for values < 2^30

int n;
vector<int> a;

struct Trie {
    vector<array<int,2>> ch;
    Trie(){ ch.push_back({-1,-1}); } // root = node 0

    void insert(int x){
        int cur=0;
        for(int b=BITS;b>=0;b--){
            int bit=(x>>b)&1;
            if(ch[cur][bit]==-1){
                ch[cur][bit]=ch.size();
                ch.push_back({-1,-1});
            }
            cur=ch[cur][bit];
        }
    }

    int query(int x){
        int cur=0,res=0;
        for(int b=BITS;b>=0;b--){
            int bit=(x>>b)&1;
            int want=bit^1; // opposite bit maximizes XOR
            if(ch[cur][want]!=-1){
                res |= (1<<b);
                cur=ch[cur][want];
            }
            else cur=ch[cur][bit];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    a.resize(n);
    for(auto &x : a) cin>>x;

    Trie trie;
    int ans=0;
    trie.insert(a[0]);
    for(int i=1;i<n;i++){
        ans=max(ans,trie.query(a[i]));
        trie.insert(a[i]);
    }

    return 0;
}
