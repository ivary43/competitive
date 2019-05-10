#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    
    int T;
    cin>>T;
    while(T--) {
        int n ,k ;
        cin>>n>>k ;
        int arr[n];
        int no_pos = 0 ;
        int no_neg = 0 ;
        for(int i=0;i<n;++i) {
            cin>>arr[i];
            if(arr[i]<0) {
                no_neg++;
            } else {
                no_pos++;
            }
        }
        
        sort(arr, arr+n);
        
        
        
        
        
        
        
    }
    
    
    
    
    
    return 0;
}
