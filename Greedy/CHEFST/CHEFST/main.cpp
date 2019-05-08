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
        long int poss = min(res,min(n1,n2));
        cout<<n1+n2 - 2*poss<<endl;
    }
    
    
    
    return 0;
}
