#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    int n ;
    long int D;
    cin>>n>>D;
    long int arr[n];
    
    for(int i=0;i<n;++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long int res = 0 ;
    for(int i=1;i<n;++i) {
        if(arr[i] - arr[i-1] <= D) {
            res++;
            ++i;
        }
    }
    cout<<res<<endl;
    return 0;
}
