#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> set_bits, int len, int K) {
    int n = (int)set_bits.size();n--;
    for(int i=len;i<=n;++i) {
        if(set_bits[i]-set_bits[i-len]>=K) {
            return true;
        }
        
    }
    return false;
}

void findMin(vector<int> set_bits_c, int K, int n) {
    int low = 1 , high = n ;
    
    while(low<high) {
        int mid = (low+high)>>1 ;
        if(isPossible(set_bits_c, mid, K)) {
            high = mid;
        } else {
            low=mid+1;
        }
    }
    
    if(isPossible(set_bits_c, low, K)) {
        cout<<low<<endl;
    } else {
        cout<<-1<<endl;
    }
    
}

int main() {
    int n ,q , dummy;
    cin>>n>>q;
    vector<int> set_bits_c(n+1) ;
    set_bits_c[0]=0;
    for(int i=1;i<=n;++i) {
        cin>>dummy;
        set_bits_c[i] = __builtin_popcount(dummy);
    }
    
    for(int i=1;i<=n;++i) {
        set_bits_c[i]+=set_bits_c[i-1];
    }
    
    
    for(int i=0;i<q;++i) {
        cin>>dummy;
        findMin(set_bits_c, dummy, n);
    }
    return 0;
}
