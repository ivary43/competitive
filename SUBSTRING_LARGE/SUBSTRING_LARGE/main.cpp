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



int main() {
  
    string s ;
    cin>>s ;
    
    int n = (int)s.length();
    
    bool isPal[n][n] ;
    memset(isPal, false, sizeof(isPal));
    
    for(int i =0 ;i<n;++i) {
        isPal[i][i] = true ;
        
        if(i!=n-1 && s[i] == s[i+1]) {
            isPal[i][i+1] = true ;
        }
    }
    
    int max_val = INT_MIN ;
    
    for(int l= 3 ;l<=n;++l){
        
        for(int i =0 ;i<=n-l ;++i) {
            int j = i+l-1 ;
            
            if(isPal[i+1][j-1] && s[i] == s[j]) {
                isPal[i][j] = true ;
                
                max_val = max(max_val, l);
            }

        }
    }
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout<<isPal[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<max_val<<endl ;
    return 0;
}
