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
    cin>>T ;
    while(T--) {
        string s ;
        cin>>s ;
        
        int n = (int)s.size();
        int arr[6200][6200] = {0};
        
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j){
                if(s[i] == s[j]) {
                    arr[i][j] = 1+arr[i-1][j-1];
                } else {
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
        
        cout<<n-arr[n][n]<<endl;
    }
    
    return 0;
}
