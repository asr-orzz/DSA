#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(1) or O(set bits)
// Common bit tricks

// count set bits — Brian Kernighan: O(number of set bits)
int countBits(int x){
    int cnt=0;
    while(x){
        x &= (x-1); // drop lowest set bit
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int x;
    cin>>x;

    // builtins (use ll versions with 'll' suffix: __builtin_popcountll etc.)
    int bits    = __builtin_popcount(x);   // set bits
    int lowbit  = x & (-x);                // isolate lowest set bit
    int dropLow = x & (x-1);               // clear lowest set bit
    int msbPos  = x ? 31-__builtin_clz(x) : -1; // index of highest set bit
    int lsbPos  = x ? __builtin_ctz(x) : -1;    // index of lowest set bit

    // swap without temp
    int a=3,b=5;
    a ^= b; b ^= a; a ^= b;

    return 0;
}
