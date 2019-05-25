#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> vi;
typedef vector<vi> vii;
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i,a[n];
        rep(i,n) cin>>a[i];
        sort(a,a+n);
        ll one=0;
        for(ll i=0;i<n;i++){if(a[i]==1) {cout<<1<<" ";one++;}}
        if(n-one==2&&a[one]==2&&a[one+1]==3) cout<<2<<" "<<3;
        else {
            for(ll i=n-1;i>=0;i--) {if(a[i]!=1) {cout<<a[i]<<" ";}}
        }
        cout<<"\n";
    }
    return 0;
}
