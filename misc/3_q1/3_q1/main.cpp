#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define fucking_sync ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define mp make_pair
# define INF 0x3f3f3f3f
#define M_PI 3.14159265358979323846

using namespace std;
//vector<vector<int>> adj;

int n,k;
vector<int>pre;
string s;

int main() {
    fucking_sync
    
    int T,T_;
    cin>>T;
        
    T_ = T ;
    
    while(T--) {

        cin>>n>>k;
        cin>>s;
        
        pre  = vector<int>(n,0);
        
        if(s[0] == '1') {
            pre[0] = 1;
        }
        
        for(int i=1;i<n;++i) {
            pre[i]=((s[i] == '1')?pre[i-1]+1:pre[i-1]);
        }
        

        for(int i=0;i<k && i<n;++i) {
            dp[i]=pre[i];
        }
        
        for(int i=k;i<n;++i) {
            int ext = (s[i] == '1')?0:1;
            dp[]
            
            
        }
        
        
        
    }
    return 0;
}
