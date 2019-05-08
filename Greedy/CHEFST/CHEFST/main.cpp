#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int T ;
    cin>> T ;
    while(T--) {
        int m ;
        long int n1, n2 , res;
        cin>>m>>n1>>n2;
        res = (m*(m+1))/2 ;
        if(n1>n2) swap(n1, n2);
        
        if(n1 > res) {
            cout<<(n1-res)+(n2 -res)<<endl;
        } else {
            cout<<n2-n1<<endl;
        }
        
    }
    
    
    
    return 0;
}
