//#include<bits/stdc++.h>
#include "/Users/manishkumar/Downloads/Header/stdc++.h"
#define pb push_back
#define ll long long int
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define ALL(v) v.begin(), v.end()
int modi =  998244353;
using namespace std;

int main() {
    int n;
    cin>>n ;
    long int arr[n];
    double sum=0;
    REP(i, n) {
        cin>>arr[i];
        sum+=(log10(arr[i]));
    }
    
    long int l=1 , r=1e10;
    while(l<r) {
        long int mid = (l+r)>>1 ;
        if(n*log10(mid)>sum) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    cout<<l<<endl;
    
    return 0;
}
