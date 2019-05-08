#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
long int f[1002] = {0};
long int fib(int n,int m)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
    
    // If fib(n) is already computed
    if (f[n])
        return f[n];
    
    int k = (n & 1)? (n+1)/2 : n/2;
    
    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? (fib(k,m)*fib(k,m) + fib(k-1,m)*fib(k-1,m))
    : (2*fib(k-1,m) + fib(k,m))*fib(k,m);
    f[n]= f[n]%m;
    return f[n]%m;
}

int main() {
    int T ;
    
    
    cin>>T ;
    while(T--) {
        int n,m ;
        cin>>n>>m ;
        memset(f,0,1002*sizeof(f[0]));
        cout<<(fib(n,m)*2)%m<<endl;
        
    }
    
    
    return 0;
}
