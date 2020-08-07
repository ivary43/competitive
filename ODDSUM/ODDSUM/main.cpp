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
int odd_val[100005] ;
//int even_val[100005] ;
int n, k ;
bool solveProb(int arr[],int start_index, int prev_odd_val ,stack<int> &res){
    
    int temp_k = (int)res.size();
    temp_k= k - temp_k;
    
    if(temp_k == 1) {
        if( (odd_val[n-1] - prev_odd_val)%2 == 1) {
            res.push(n-1);
            return true;
        } else {
            return false;
        }
    }
    
    int limit = (n - temp_k) ;
    for(int i=start_index;i<n;++i) {
        if(i>limit) {
            return false ;
        }
        
        if( (odd_val[i] - prev_odd_val)%2 == 1) {
            res.push(i);
            bool ans = solveProb(arr, i+1, odd_val[i], res);
            if(ans) {
                return true ;
            }
        }
        
    }

    return false ;
}


int main() {
    
    SYNC
    int T ;
    cin>>T ;
    
    while (T--) {

        cin>>n>>k ;
        
        int arr[n] ;
        memset(odd_val,0,n*sizeof(odd_val[0]));
        for(int i=0;i<n;++i){
            cin>>arr[i];
            if(i>0) {
                odd_val[i]=odd_val[i-1];
            }
            
            if(arr[i]%2 ==1 ) {
                odd_val[i]++;
            }
            
        }
        
        stack<int> res_Stack ;
        bool fnal_res = solveProb(arr, 0, 0, res_Stack);
        
        if(fnal_res) {
            vector<int> res_val(k);
            int i = k-1 ;
            while(!res_Stack.empty()) {
                int temp = res_Stack.top() ;
                res_Stack.pop();
                res_val[i]= temp;
                i--;
            }
            
            cout<<"YES"<<endl;
            for(int l=0;l<k;++l) {
                cout<<res_val[l]+1<<" ";
            }
            cout<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }

    return  0;
}


