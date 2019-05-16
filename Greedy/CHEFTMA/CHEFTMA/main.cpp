#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
bool compare(int a , int b) {
    return a>b;
}
int main() {
    
    int T ;
    cin>>T ;
    while(T--) {
        int n , k, m ;
        cin>>n>>k>>m ;
        int planned[n], completed[n] ;
        
        for(int i=0;i<n;++i) {
            cin>>planned[i];
        }
        
        for(int i=0;i<n;++i) {
            cin>>completed[i];
        }
        
        
        int diff[n];
        for(int i=0;i<n;++i) {
            diff[i]= planned[i] -completed[i];
        }
        int arr[k+m];
        for(int i=0;i<k+m;++i) {
            cin>>arr[i];
        }
        int m_ = k+m;
        sort(diff, diff+n, compare);
        sort(arr, arr+m_, compare);
        long int sum = 0;
        int head = 0;
        for(int i=0;i<n;++i) {
            if(head<m_ && arr[head]<=diff[i]) {
                sum+=(diff[i]-arr[head]);
                head++;
            } else if(head>=m_) {
                sum+=(diff[i]);
            } else {
                --i;
                head++;
            }
        }
        
        cout<<sum<<endl;
        
    }
    
    
    return 0;
}
