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
    int T ;
    cin>>T;
    while(T--) {
        int n , k ;
        cin>>n>>k ;
        int arr[n];
        rep(i, n) cin>>arr[i];
        
        int dp[1001][1024] = {0};

        dp[0][k]=1;
//        for(int i=0;i<1024;++i) {
//            cout<<dp[0][i]<<" ";
//        }
        cout<<endl;
        for(int i=1;i<=n;++i) {
            for(int j=0;j<1024;++j) {
                if(!dp[i][j]) {
                    dp[i][j]=(dp[i-1][j]);
                    
                    if(dp[i-1][j]) {
                        dp[i][j^arr[i-1]]=1;
                    }
                }
            }
        }
        
//        for(int i=0;i<n+1;++i) {
//            for(int j=0;j<1024;++j) {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<"--"<<endl;
//        }
        
        
        for(int i=1023;i>=0;--i) {
            if(dp[n][i] ==1) {
                cout<<i<<endl;
                break;
            }
        }
        
        
    }
    
    return 0;
}
