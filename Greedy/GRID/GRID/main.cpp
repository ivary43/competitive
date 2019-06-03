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
    cin>>T ;
    while(T--) {
        int N;
        cin>>N;
        char path[N][N];
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j) {
                cin>>path[i][j];
            }
        }
        
        int res = 0 ;
        bool canReach[1000][1000] = {0};
        bool isBlock = false;
        for(int i=N-1;i>=0;--i) {
            if(!isBlock && path[N-1][i]=='.') {
                res++;
                canReach[N-1][i]= true;
            } else if(!isBlock && path[N-1][i] == '#') {
                isBlock=true;
            } else if(path[N-1][i] == '.'){
                 canReach[N-1][i]= true;
            }
        }
        
        
        for(int i=N-2;i>=0;--i){
            isBlock = false;
            for(int j=N-1;j>=0;--j){
                if(canReach[i+1][j] && path[i][j] == '.' && !isBlock) {
                    canReach[i][j] = true;
                    res++;
                } else if(path[i][j] == '#' && !isBlock) {
                    isBlock = true;
                    canReach[i][j]=false;
                } else if(path[i][j] == '#') {
                    canReach[i][j]=false;
                } else {
                    canReach[i][j]= canReach[i+1][j];
                }
            }
        }
        
        
        cout<<res<<endl;
        
    }
    return 0;
}
