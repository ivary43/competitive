
//#include<bits/stdc++.h>
#include "/Users/manishkumar/Work/stdc++.h"
using namespace std ;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
#include <chrono>

int arr[] = {5, 1, 1 , 1};

int solve(int i, int val) {
    
//
//    cout<<i<<" "<<val<<"\n";
//    if(val<0)  return -1;
    if(i<0 && val!=0) {
        return -1;
    } else if(val ==0 ) {
        return 0;
    } else {

        int res1 = -1;
        
        if(arr[i] <= val) {
            res1 = solve(i, val-arr[i]);
        }
            int res2 = solve(i-1, val);


            if(res1!=-1 && res2!=-1) {
                return min(1+res1, res2);
            } else if(res1== -1 && res2!=-1) {
                return res2;
            } else if(res1!=-1 && res2==-1){
                return 1+res1;
            } else {
                return -1;
            }


        
        
        return -1;
    }
    
}


int main() {
    
    auto start = std::chrono::high_resolution_clock::now();
    int val = solve(3, 27);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    
    cout<<val<<"<---res\n\n\n";
      cout << "Time taken by function: "
           << duration.count() << " microseconds" << endl;
    
    return 0;
}



