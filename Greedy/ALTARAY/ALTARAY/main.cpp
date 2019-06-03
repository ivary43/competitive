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
bool hasAlternate(int a , int b) {
    if(a>0 && b<0) {
        return true;
    } else if(a<0 && b>0) {
        return true;
    }
        return false;
}
int main() {

    int T ;
    cin>>T;
    while(T--) {
        int n ;
        cin>>n ;
        int arr[n];
        rep(i, n) cin>>arr[i];
        bool isConti = true ;
        int res[n];
        rep(i, n) res[i] = 1;
        
        for(int i=n-2;i>=0;--i) {
            if(hasAlternate(arr[i+1], arr[i]) && isConti) {
                res[i]+=res[i+1];
            } else if(hasAlternate(arr[i], arr[i+1]) && !isConti) {
                isConti =true;
                res[i]+=res[i+1];
            } else {
                isConti= false;
            }
            
        }
        rep(i, n) cout<<res[i]<<" ";
        cout<<endl;
    }
    
 
    
    
    return 0;
}
