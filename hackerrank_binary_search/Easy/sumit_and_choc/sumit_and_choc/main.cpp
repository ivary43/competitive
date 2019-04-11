#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;

void b_search(vector<pair<int,int>> arr,int ci ) {
    int n = arr.size();
    int low=0 , high = n-1 ;
    while(low<high) {
        int mid = (low+high)>>1 ;
        if(ci>=arr[mid].first && ci<=arr[mid].second) {
            cout<<mid+1<<endl;
            return;
        } else if(ci < arr[mid].first ){
            high = mid-1;
        } else {
            low = mid+1;
        }
        
    }
    
    if(ci>=arr[low].first && ci<=arr[low].second) {
        cout<<low+1<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
    int n,dummy;
    cin>>n ;
    vector<int> choc(n);
    for(int i=0;i<n;++i) {
        cin>>choc[i];
    }
    int q;
  
    
    vector<pair<int,int>> val(n);
    int prev=1;
    for(int i=0;i<n;++i) {
        val[i].first = prev;
        val[i].second = val[i].first + choc[i];
        prev = val[i].second + 1;
       // cout<< val[i].first <<" - "<<val[i].second <<endl;
    }
    
      cin>>q;
    for(int i=0;i<q;++i){
        cin>>dummy;
        b_search(val, dummy);
    }
    
  
    return 0;
}
