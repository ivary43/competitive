#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>

using namespace std ;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

void labelise(int arr[], int _l , int val, vector<int> &label ) {
    
    int n = label.size() ;
    for(int i=0;i<n;++i) {
            
        if(label[i] == -1 && arr[i] % val == 0) {
            label[i] = _l;
        }
    }
    
}

int main() {
    
    
    int n ;
    cin>>n ;
    
    int arr[n] ;
    
    for(int i=0;i<n;++i) {
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    vector<int> label(n,-1);
        
    int _l = 0;
    
    for(int i=0;i<n;++i) {
        if(label[i] == -1) {
            labelise(arr, ++_l, arr[i], label);
        }
    }
    
    cout<<_l<<endl;
    
    return 0;
}
