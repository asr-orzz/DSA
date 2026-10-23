#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
// sub array Kth smallest element Query
// Q 
// l r k 
// subarray arr[l to r] find kth smallest element
// we do binary search on answer 
// number of elements <= mid should be greater than equal to k 
// by maintaining sorted vector of elements in segment tree nodes

int n,q;
vector<int> a,vals;
vector<vector<int>> tree;

int binary(vector<int>& v,int x){
    int lo=0,hi=v.size()-1;
    int ans=-1;

    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(v[mid]<=x){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }

    return ans+1;
}

void build(int id,int l,int r){
    if(l==r){
        tree[id].push_back(a[l]);
        return;
    }

    int mid=(l+r)/2;

    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    merge(
        tree[2*id].begin(),tree[2*id].end(),
        tree[2*id+1].begin(),tree[2*id+1].end(),
        back_inserter(tree[id])
    );
}

int query(int id,int l,int r,int lq,int rq,int x){
    if(r<lq or rq<l) return 0;

    if(lq<=l and r<=rq){
        return binary(tree[id],x);
    }

    int mid=(l+r)/2;

    return query(2*id,l,mid,lq,rq,x)
         + query(2*id+1,mid+1,r,lq,rq,x);
}

bool check(int l,int r,int k,int x){
    return query(1,0,n-1,l,r,x)>=k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    a.resize(n);
    tree.resize(4*n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);

    vals=a;
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;

        l--;
        r--;

        int lo=0,hi=vals.size()-1;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(check(l,r,k,vals[mid])){
                ans=vals[mid];
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}