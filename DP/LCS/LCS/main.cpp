#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>

using namespace std ;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair


using namespace std;


int moveFwd(int arr[], int ptr,int l){
    int i;
    for( i=++ptr;i<l;i++){
        if(arr[i] != 0) {
            break;
        }
    }
    
    return i ;
}

int moveBwd(int arr[], int ptr,int l){
    int i ;
    for(i=--ptr;i>l;--i){
        if(arr[i] != 2) {
            break;
        }
    }
    
    return i ;
}

int main()
{
    int T;
    cin>>T;
    
    while(T--){
        int n ;
        cin>>n;
        int arr[n] ;
        
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        
        int zero_ptr = -1 ;
        int two_ptr = n ;
        
        for(int i=0;i<two_ptr;++i){
            
            if(arr[i] == 0) {
                zero_ptr = moveFwd(arr,zero_ptr,i);
                swap(arr[i], arr[zero_ptr]);
                
                if(arr[i] == 2 && i!=two_ptr) {
                    if(arr[two_ptr]==2) {
                       two_ptr = moveBwd(arr, two_ptr,i);
                    }
                    swap(arr[two_ptr], arr[i]);
                }
                
            }
            
            if(arr[i] == 2) {
                two_ptr = moveBwd(arr,two_ptr,i);
                swap(arr[i], arr[two_ptr]);
                
                if(arr[i] == 0 && i!=zero_ptr) {
                    if(arr[zero_ptr] == 0 && i!=zero_ptr) {
                        zero_ptr = moveFwd(arr,zero_ptr,i);
                    }
                    
                    swap(arr[i], arr[zero_ptr]);
                }
            }
            
        }
        
        for(int i=0;i<n;++i){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
    }
    //code
    return 0;
}
