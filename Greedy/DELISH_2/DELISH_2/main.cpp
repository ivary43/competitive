#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
int main() {
    SYNC
    int T;
    cin>>T;
    while(T--) {
        int n ;
        cin>>n ;
        int arr[n] ;
        rep(i, n) cin>>arr[i];
        long long int sum_max_left[n];
        long long int sum_min_left[n];
        sum_max_left[0] = arr[0];
        sum_min_left[0] = arr[0];
        for(int i=1;i<n;++i) {
            sum_max_left[i]=max((ll)0,sum_max_left[i-1])+arr[i];
            sum_min_left[i]=min((ll)0,sum_min_left[i-1])+arr[i];
        }
        
        long long int sum_max_right[n];
        long long int sum_min_right[n];
        
        sum_max_right[n-1]=arr[n-1];
        sum_min_right[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;--i) {
            sum_max_right[i]=max((ll)0,sum_max_right[i+1])+arr[i];
            sum_min_right[i]=min((ll)0,sum_min_right[i+1])+arr[i];
        }

        long long int res = -1;
        for(int i=1;i<n;++i) {
            res = max(res,max(abs(sum_max_left[i-1]-sum_min_right[i]),
                              abs(sum_min_left[i-1]-sum_max_right[i]) ) );
        }
        
        cout<<res<<endl;
        
    }
    
    
 
    return 0;
}
