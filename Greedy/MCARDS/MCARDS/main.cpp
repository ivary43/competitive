#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

int LIS(vector<int> arr) {
    int n = (int)arr.size();
    int maxVal = 1 ;
    vector<int> res(n,1);
    for(int i=1;i<n;++i) {
        for(int j=0;j<i;++j) {
            if(arr[i]>=arr[j]) {
                res[i]=(res[j]+1);
            }
        }
        maxVal = max(maxVal, res[i]);
    }
    return maxVal;
}


int main() {
    
    
    int c, n ;
    cin>>c>>n ;
    vector<int> res(c,INT_MAX);
    int resVal = 0 ;
    int prevC, val ;
    cin>>prevC>>val;
    vector<int> tempArr;
    tempArr.pb(val);
    int x, y;
    for(int i=1;i<n*c;++i) {
        cin>>x>>y ;
        if(x==prevC) {
            tempArr.push_back(y);
        } else {
            int val = LIS(tempArr);
            int noOfswaps = ((int)tempArr.size() - val)+(n- (int)tempArr.size());
            if(noOfswaps < res[prevC-1]) {
                res[prevC-1]= noOfswaps;
            }
            
            tempArr.clear();
            tempArr.pb(y);
            prevC=x;
        }
        
    }
    
    if(!tempArr.empty()) {
        int val = LIS(tempArr);
        int noOfswaps = ((int)tempArr.size() - val)+(n- (int)tempArr.size());
        if(noOfswaps < res[prevC-1]) {
            res[prevC-1]= noOfswaps;
        }
    }
    
    for(int i=0;i<c;++i) {
        resVal+=res[i];
    }
    
    cout<<resVal;
    
    return 0;
}
