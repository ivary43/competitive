//#include<bits/stdc++.h>
#include "/Users/manishkumar/Downloads/Header/stdc++.h"
#define pb push_back
#define ll long long int
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define ALL(v) v.begin(), v.end()
int modi =  998244353;
bool isPossible(long int arr[],long long int T,int n,int days) {
    long long int sum =0 ;
    int res =1 ;
    for(int i=0;i<n;++i) {
        if(arr[i]>T) {
            return false;
        }
        if(sum+arr[i]>T) {
            sum=arr[i];
            res++;
        } else {
            sum+=arr[i];
        }
    }
    
    if(res>days) {
        return false;
    }
    return true;
}

using namespace std ;
int main() {
    SYNC
    int n,k ;
    cin>>n>>k;
    long int arr[n] ;
    long long int sum =0 ;
    REP(i, n) {
        cin>>arr[i] ;
        sum+=arr[i];
    }
    
    long long int l=1,r=sum;
    while(l<r) {
        long long int mid = (l+r)>>1 ;
        if(isPossible(arr, mid, n, k)) {
            r=mid ;
        } else {
            l=mid+1;
        }
        
    }
    cout<<r<<endl;
    
    return 0;
}
