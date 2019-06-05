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

bool compare(pair<int,int>a1, pair<int,int> a2) {
    return a1.second < a2.second ;
}

int main() {
    
    SYNC
    int n, k, p ;
    cin>>n>>k>>p ;
    int arr[n] ;
    rep(i, n) cin>>arr[i];
    
    vector<pair<int,int>> loc(n);
    for(int i=0;i<n;++i) {
        loc[i] = {i+1, arr[i]};
    }
    
    sort(loc.begin(), loc.end(), compare);
    cout<<"-------------------------------"<<endl;
    for(int i=0;i<n;++i) {
        cout<<loc[i].first<<" "<<loc[i].second<<endl;
    }
    cout<<"-------------------------------"<<endl;
    
    map<int,int> res ;
    int lastMax = loc[n-1].second ;
    res.insert(make_pair(loc[n-1].first, loc[n-1].second));
   
    //loc.sec --> distance
    //loc.first --> pos
    //
    for(int i=n-2;i>=0;--i) {
        if(loc[i+1].second-loc[i].second <=k) {
            res.insert(make_pair(loc[i].first, lastMax));
        } else {
            lastMax = loc[i].second;
            res.insert(make_pair(loc[i].first, loc[i].second));
        }
    }
    
    map<int,int> :: iterator it ;
    cout<<"-------------------------------"<<endl;
    for(it=res.begin();it!=res.end();++it) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"-------------------------------"<<endl;
    
    int x, y;
    for(int i=0;i<p;++i) {
        cin>>x>>y ;
        if(arr[x-1]>arr[y-1]) {
            swap(x,y);
        }
        
        int dist = res.find(x)->second;
        if(arr[y-1]<=dist) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
    
}
