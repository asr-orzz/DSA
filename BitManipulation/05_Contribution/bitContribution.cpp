#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(32 * N)
// Bit contribution: solve each bit independently, sum contributions
// Example: sum of XOR over all pairs (i<j)
int n;
vector<int> a;

ll sumXorPairs(){
    ll total=0;
    for(int b=0;b<32;b++){
        ll ones=0;
        for(int x : a) ones += (x>>b)&1;
        ll zeros = n-ones;
        // pairs with different bit -> contribute 2^b
        total += ones*zeros*(1LL<<b);
    }
    return total;
}

ll sumAndPairs(){
    ll total=0;
    for(int b=0;b<32;b++){
        ll ones=0;
        for(int x : a) ones += (x>>b)&1;
        // both bits 1 -> AND has this bit
        total += ones*(ones-1)/2*(1LL<<b);
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    a.resize(n);
    for(auto &x : a) cin>>x;

    // sumXorPairs(), sumAndPairs()

    return 0;
}
