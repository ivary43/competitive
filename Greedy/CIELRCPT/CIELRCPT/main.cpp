#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    int T ;
    cin>>T ;
    while(T--) {
        int n;
        cin>>n ;
        if(n>2048) {
            int m = n/2048 ;
            int residual = n - (m*2048);
            cout<<m+(__builtin_popcount (residual))<<endl;
        } else {
          cout<<__builtin_popcount (n) << endl;
        }
        
    }
    return 0;
}
