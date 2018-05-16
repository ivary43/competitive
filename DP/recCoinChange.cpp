#include "/Users/manishkumar/Downloads/Header/stdc++.h"
//#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define INF 1e5
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(n) f(i,0,n)


int permutations( int coin[] ,int n ,int sum) {
   
    if(sum == 0) {
        return 1 ;
    } else if(sum < 0 ) {
        return 0;
    } else if( sum>=1 && n<=0 ) {
        return 0 ;
    } else {
        return permutations(coin, n, sum-coin[n-1])+permutations(coin, n-1, sum);
    }
    
    
}


int main() {
    
    int sum ,n;
    cin>>n>>sum;
    
    int coin[n];
    rep(n) {
        cin>>coin[i];
    }
    cout<<permutations(coin, n, sum)<<endl;
    return 0 ;
}
