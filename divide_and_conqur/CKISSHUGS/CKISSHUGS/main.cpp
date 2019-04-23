#include "/Users/manishkumar/Work/stdc++.h"
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int pow2(int base , int exp) {
    if(exp == 0 ){
        return 1;
    } else if(exp == 1) {
        return base;
    }
    
    if(exp%2 == 0) {
        long long int ret_val = pow2(base, exp/2);
        ret_val = ret_val*ret_val;
        return (ret_val%MOD);
    } else {
        long long int ret_val = pow2(base,(exp-1)/2);
        ret_val=base*(ret_val*ret_val);
        return (ret_val%MOD);
    }
}


int main() {
    int T ;
    cin>>T ;
    while(T--) {
        int n ;
        cin>>n ;
        if(n%2 == 0) {
            long long int res = pow2(2, n/2);
            cout<<(3*res)-2<<endl;
        } else {
            long long int res = pow2(2,(n+1)/2);
            cout<<2*res -2<<endl;
        }
    }
    
    return 0;
    
}
