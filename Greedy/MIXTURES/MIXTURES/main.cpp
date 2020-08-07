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
    
    int n;
    
    while(cin>>n) {
        
        
        int arr[n];
        rep(i,n) cin >> arr[i];
        
        int val[100][100] = {0};
        int res[100][100] = {0};
        
        rep(i,n) val[i][i] = arr[i];
        
        for(int L=2;L<=n;++L){
            
            for(int i=0;i<=n-L;++i){
                int j = i+L-1;
                res[i][j] = INT_MAX;
                for(int k=i;k<=j-1;++k) {
                    int temp = res[i][k] + res[k+1][j] + val[i][k]*val[k+1][j];
                    
                    if(temp< res[i][j]) {
                        res[i][j] = temp;
                        val[i][j] = (val[i][k]+val[k+1][j])%100;
                    }
                }
            }
        }
        
        cout<<res[0][n-1]<<endl;
    }
    
    return 0;
}
