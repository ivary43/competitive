#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
int main() {
    int T ;
    cin>>T ;
    while(T--) {
        int n ;
        cin>>n ;
        int arr[n], arr1[n];
        
        rep(i,n) cin>>arr[i];
        rep(i,n) cin>>arr1[i];
        
        sort(arr, arr+n, greater<int>());
        sort(arr1, arr1+n, greater<int>());
        long int res = 0;
        rep(i, n) res+=(arr1[i]*arr[i]);
        cout<<res<<endl;
    }    
    return 0;
}
