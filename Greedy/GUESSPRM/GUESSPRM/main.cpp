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

bool isPrime(long long int val){
    for(int i=2;i<=sqrt(val);++i) {
        if(val%i == 0) {
            return false;
        }
    }
    return true;
    
}

int main() {

    for(long long int i =2 ;i<1e9;++i) {
        if(isPrime(i)) {
            cout<<i<<endl;
        }
        
    }
    return 0;
}
