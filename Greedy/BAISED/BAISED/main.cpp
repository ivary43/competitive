#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main( ) {
    int T ;
    cin>>T ;
    
    while(T--) {
        
        int n ;
        cin>>n;
        long int res = 0 ;
        
        int arr[n];
        string s ;
        for(int i=0;i<n;++i) {
            cin>>s>>arr[i];
        }
        
        sort(arr, arr+n);
        for(int i=0;i<n;++i) {
            res+=abs(arr[i]-(i+1));
        }
        cout<<res<<endl;
    }
    return 0;
}
