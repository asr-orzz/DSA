#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Missing number in 0..n (n numbers, one missing) via XOR
int n;
vector<int> a;

int missing(){
    int res=0;
    for(int i=0;i<n;i++){
        res ^= a[i];
        res ^= i;
    }
    res ^= n; // include the full range end
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    a.resize(n);
    for(auto &x : a) cin>>x;

    cout<<missing()<<"\n";

    return 0;
}
