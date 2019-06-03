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
 
    
    int T;
    cin>>T;
    
    while(T--) {
        int n;
        cin>>n ;
        
        int H[n];
        int K[n]; // coin
       
        rep(i, n) cin>> H[i];
        rep(i,n )  {
            cin >> K[i];
        }
        
        int res[n][1003];
        for(int i=0;i<=1002;++i) {
            if(i%K[0] == 0) {
                res[0][i] = i/K[0];
            } else {
                res[0][i] = 0 ;
            }
        }
        
        for(int i=1;i<n;++i) {
            for(int k=0;k<=1002;++k) {
                if(k<K[i]) {
                    res[i][k]= res[i-1][k];
                } else {
                    res[i][k]= min(res[i-1][k],1+res[i][k-K[i]]);
                }
            }
        }
        
        long int sum =0;
        for(int i=0;i<n;++i) {
            sum+=(res[n-1][2*H[i]]);
        }
        cout<<sum<<endl;
        
        
    }
    
    return 0;
}
    
