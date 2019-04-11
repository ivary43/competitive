#include<iostream>
#define pb push_back
#define ll long long int
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define ALL(v) v.begin(), v.end()
int modi =  998244353;
using namespace std;
  long long tot =0;
bool isDelayposs(int arr[], int d, int n,int delay) {
    long sum =0 ;
    for(int i=0;i<delay ;++i) {
        sum+=arr[i];
    }
    long long temp_tot =sum ;
    for(int i=delay;i<n;++i) {
 
        if(sum<d) {
            return false;
        }
        temp_tot+=arr[i];
        if(temp_tot == tot) {
            return true;
        }
        sum+=(arr[i]-(d));
    }
    return true;
}


int main() {
    SYNC;
    int n, d ;
    cin>>n>>d ;
    int arr[n];
  
    REP(i,n) {
        cin>>arr[i];
        tot+=arr[i];
    }
    bool ss= isDelayposs(arr, d, n, 80);
    int l=1 , r=n ;
    while(l<r) {
        int mid = (l+r)>>1 ;
        if(isDelayposs(arr,d,n,mid)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}
