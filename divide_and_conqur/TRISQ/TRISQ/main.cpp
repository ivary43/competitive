#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T ;
    cin>>T ;
    
    while(T--) {
        int n ;
        cin>>n ;
        n = n/2;
        n--;
        cout<<(n*(n+1))/2 <<endl;
    }
    
    return 0;
}
