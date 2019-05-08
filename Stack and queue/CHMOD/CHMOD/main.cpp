#include "/Users/manishkumar/Work/stdc++.h"
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
//#include <iostream>
//#include<bits/stdc++.h>
//cout<<INT_MAX<<endl;
using namespace std;
int main() {
    SYNC
    int n ;
    cin>>n;
    vector<long int> arr(n+1);
    bool isAllzero = false;
    arr[0] = 1;
    cin>>arr[1];
    isAllzero = (arr[1] == 0)?true:false;
    
    for(int i=2;i<=n;++i) {
        cin>>arr[i];
        arr[i]*=arr[i-1];
        if(arr[i] == 0) isAllzero = true;
    }
    
    int T , l , r ,mod_val ;
    cin>>T ;
    while(T--) {
        if(isAllzero) {
            cin>>r>>l>>mod_val ;
            cout<<0<<endl;
        } else {
            cin>>l>>r>>mod_val ;
            cout<<(arr[r]/arr[l-1])%mod_val<<endl;
        }
    }
    
    return 0;
}

