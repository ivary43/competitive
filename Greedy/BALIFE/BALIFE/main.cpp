#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n!=-1) {
        int arr[n];

        cin>>arr[0];
        for(int i =1;i<n;++i) {
            cin>>arr[i];
            arr[i]+=(arr[i-1]);
        }
       
        if(arr[n-1]%n != 0) {
            cout<<-1<<endl;
            cin>>n;
            continue;
        } else {
            long int res = 0;
             long int mean = arr[n-1]/n;
            for(int i=0;i<n;++i) {
                res = max(res,(long int)abs((1ll*mean*(i+1))-arr[i]));
            }
            cout<<res<<endl;
            cin>>n;
            
        }
        
    }
    
    return 0;
}
