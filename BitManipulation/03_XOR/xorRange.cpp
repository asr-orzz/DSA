#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(1)
// XOR of 0..n has a period-4 pattern; range via prefix
ll xorTill(ll n){
    // XOR of 0,1,2,...,n
    switch(n%4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        default: return 0; // n%4==3
    }
}

ll xorRange(ll l,ll r){
    return xorTill(r) ^ xorTill(l-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll l,r;
    cin>>l>>r;
    cout<<xorRange(l,r)<<"\n";

    return 0;
}
