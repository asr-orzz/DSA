#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Single number problems using XOR
int n;
vector<int> a;

// every element twice except one -> XOR all
int singleOnce(){
    int res=0;
    for(int x : a) res^=x;
    return res;
}

// every element twice except two uniques p,q
pair<int,int> singleTwo(){
    int xorAll=0;
    for(int x : a) xorAll^=x;

    int diff = xorAll & (-xorAll); // a bit where p,q differ
    int p=0,q=0;
    for(int x : a){
        if(x&diff) p^=x;
        else q^=x;
    }
    return {p,q};
}

// every element thrice except one -> count bits mod 3
int singleThrice(){
    int res=0;
    for(int b=0;b<32;b++){
        int cnt=0;
        for(int x : a) cnt += (x>>b)&1;
        if(cnt%3) res |= (1<<b);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    a.resize(n);
    for(auto &x : a) cin>>x;

    // singleOnce(), singleTwo(), singleThrice()

    return 0;
}
