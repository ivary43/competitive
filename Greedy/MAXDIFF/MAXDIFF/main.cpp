#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int T ;
    cin>>T ;
    while(T--) {
        int n, k;
        cin>>n>>k ;
        int arr[n];
        int sum =0 ;
        for(int i=0;i<n;++i) {
            cin>>arr[i] ;
            sum+=arr[i];
        }
        sort(arr, arr+n);
        int temp = 0 ;
        for(int i=0;i<k;++i) {
            temp+=(arr[i]);
        }
        
        cout<<sum - (2*temp)<<endl;
    }
    
    return 0;
}
