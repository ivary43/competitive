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
        long int sum[n][n];
        for(int i=0;i<n;++i) {
            sum[i][i] = arr[i];
        }
        
        for(int l=1;l<n;++l) {
            for(int i=0;i<n;++i) {
                if(i+l>=n) break;
                sum[i][i+l]=sum[i][i+l-1]+sum[i+l][i+l];
            }
        }
        
//        for(int i=0;i<n;++i) {
//            for(int j=i;j<n;++j) {
//                cout<<sum[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        long int maxVal= -1;
        for(int i=0;i<n-1;++i) {
            for(int j=i;j<n-1;++j) {
                
                for(int k=j+1;k<n;++k) {
                    for(int l=k;l<n;++l) {
                        long int temp = abs(sum[i][j]-sum[k][l]);
                        maxVal = max(maxVal, temp);
                    }
                }
            }
        }
        
        cout<<maxVal<<endl;
        
    }
    
    
    
    
    return 0;
}
