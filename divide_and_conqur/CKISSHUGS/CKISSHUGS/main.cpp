#include <iostream>
using namespace std;
#define MOD 1000000007
long long int findKiss(int n) {
    if(n<=0) return 1;
    if(n == 1) {
        return 2;
    } else {
        long long int resL = findKiss(n-1)%MOD;
        long long int resR = findKiss((n)/2)%MOD;
        return (resL+resR)%MOD;
    }
    
}


int main() {
    int T ;
    cin>>T ;
    while(T--) {
        int n ;
        cin>>n ;
        cout<<findKiss(n)<<endl;
    }
    
}
