#include<stdc++.h>
//#include "~/Downloads/Header/stdc++.h"
#define pb push_back
#define ll long long int
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define ALL(v) v.begin(), v.end()
int modi =  998244353;
using namespace std;
bool isDelayposs(int arr[], int d, int n,int delay) {
    long sum =0 ;
    for(int i=0;i<delay ;++i) {
        sum+=arr[i];
    }
    
    for(int i=delay;i<n;++i) {
        if(sum<d) {
            return false;
        }
        sum+=(arr[i]-(d));
    }
    return true;
}


int main() {
    SYNC;
int n, d ;
cin>>n>>d ;
int arr[n];
REP(i,n) {
cin>>arr[i];
}
int l=1 , r=n ;
    while(l<r) {
        int mid = (l+r)>>1 ;
        if(isDelayposs(arr,d,n,mid)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}