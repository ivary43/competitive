#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>

using namespace std ;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

void build_tree(int l , int r, int cum_sum[], vector<int> &seg_tree, int i){
    
    if(l == r) {
      seg_tree[i] = cum_sum[r] - (l-1<0?0:cum_sum[l-1]);
        return ;
    }
    
    int mid = (l+r)>>1 ;
    seg_tree[i] = cum_sum[r] - (l-1<0?0:cum_sum[l-1]);
    //build left tree
    build_tree(l, mid, cum_sum, seg_tree, 2*i+1);
    //build right tree
    build_tree(mid+1, r, cum_sum, seg_tree, 2*i+2);
    
}

int query(vector<int> seg_tree, int l, int r, int l_query, int r_query, int i ){
    
    //no overlap
    if(l_query > r || r_query < l) {
        return 0 ;
    } else if ( l_query <= l && r <= r_query) {
        return seg_tree[i];
    } else {
        int mid = (l+r)>>1 ;
        int left_sum = query(seg_tree, l, mid, l_query, r_query, 2*i+1);
        int right_sum = query(seg_tree, mid+1, r, l_query, r_query, 2*i+2);
        
        return left_sum+ right_sum ;
    }
}




int main() {
    
    int n = 6 ;
    
    int arr[] = {1,3 ,5 ,7, 9, 11};
    int cum_sum[n];
    memset(cum_sum, 0, n*sizeof(cum_sum[0]));
    cum_sum[0] = arr[0];
    for(int i=1;i<n;++i) {
        cum_sum[i]+=(cum_sum[i-1]+arr[i]);
    }
    
    
    int seg_tree_size = 2*(pow(2,ceil(log2(n)))) - 1 ;
    
    vector<int> seg_tree(seg_tree_size);
    
    build_tree(0, n-1, cum_sum, seg_tree, 0);
    
    rep(i, seg_tree_size) {
        cout<<seg_tree[i]<<" ";
    }
    cout<<endl;
    
    int temp = query(seg_tree, 0, n-1, 1, 3, 0);
    
    cout<<temp<<endl;
    
    return 0;
    
}
