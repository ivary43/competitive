#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define pb push_back
#define ll long long int
#define vi vector<int>
# define INF32 0x3f3f3f3f
# define INF64 1e18
#define forn(i, n) for (int i = 0; i < int(n); i++)

//vector<vi> adj;
//unordered_map<int, int> ump;
//int n;
//void toposort(vi incm) {
//
//    vector<bool> vis(n,false);
//    queue<int> qu;
//    for(int i=0;i<n;++i) {
//        if(incm[i] == 0) {
//            qu.push(i);
//            vis[i] = true;
//        }
//    }
//
//    int cnt = 0 ;
//    while(!qu.empty()) {
//        int u = qu.front();qu.pop();
//        ump[u] = cnt++;
//        for(int v:adj[u]) {
//            if(!vis[v]) {
//                incm[v]--;
//
//                if(incm[v] == 0) {
//                    qu.push(v);
//                    vis[v] = true;
//                }
//            }
//        }
//    }
//}

bool comp(pair<int,int> p1 , pair<int,int> p2) {
    if(abs(p1.first-p1.second) < abs(p2.first-p2.second)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    sync
    
//    int T;
//    cin>>T;
//    while(T--) {
//
//
//    }
    
    int b=0, s=0, c=0;
    int nb, ns, nc;
    int pb, ps, pc;
    ll r;
    string str;
    cin>>str ;
    
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    
    for(char ch:str) {
        if(ch == 'B') b++;
        else if(ch == 'S') s++;
        else c++;
    }
    
    ll l=0;
    ll h = 2e12;
    
    while(l<h) {
        ll mid = (l+h+1)>>1;
        
        ll req_b = b*mid; ll req_s = s*mid; ll req_c = c*mid;
        ll req_cost = max((ll)0,(req_b-nb)*pb)+max((ll)0,(req_s-ns)*ps)+max((ll)0,(req_c-nc)*pc);
        
        if(req_cost>r) {
            h = mid-1;
        } else {
            l = mid;
        }
    }
    cout<<l<<"\n";
    return 0;
}

// 0 1 -1 -1 -1
