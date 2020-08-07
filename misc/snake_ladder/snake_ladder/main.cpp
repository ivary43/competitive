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

int res = INT_MAX ;
void dfs(vector<vector<int>> adj, int src, int dest, int dist){
    
   // cout<<src<<"\n";
    if(src == dest) {
        res = min(res, dist);
        return ;
    }
    
    for(auto it=adj[src].begin(); it!=adj[src].end();++it){
        if(*it>src){
            
            if(res!=INT_MAX && dist>=res) {
                return;
            }
            dfs(adj,*it,dest, dist+1);
        }
    }
    return ;
}


int main()
{
    SYNC
    int T;
    cin>>T ;
    vector<vector<int>> adj(30) ;
    
    //init graph
    for(int i=0;i<30;++i){
        for(int j=i+1;j<=i+6;++j){
            if(j<30){
                adj[i].push_back(j);
            }
        }
    }
    
    
    
    
    
    while(T--){
        int n;
        cin>>n ;
        int x ,y ;
        for(int i=0;i<n;++i){
            cin>>x>>y;
            --x;--y ;
            adj[x].push_back(y);
        }
        res = INT_MAX ;
        
//        for(int i=0;i<30;++i){
//            for(auto it =adj[i].begin();it!=adj[i].end();++it){
//                cout<<*it<<" ";
//            }
//            cout<<"\n";
//        }
        
        dfs(adj,0,29,0);
        cout<<res<<"\n";
    }
    //code
    return 0;
}

