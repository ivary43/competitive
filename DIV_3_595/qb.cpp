#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
 
vector<vector<int>> adj;
int d = 0 ;
map<int,int> mp;

void dfs(int target, int src) {
	if(src == target) {
		d++;
		mp[target] = d;
	} else {
		d++;
		dfs(target, adj[src][0]) ;
		mp[adj[src][0]] = d;
	}
}
 
int main() {
 
	int T ;
	cin>>T;
 
	while(T--) {
		int n ;
		cin>>n ;
 
		int arr[n];
		adj = vector<vector<int>>(n);
 
		for(int i=0;i<n;++i) {
			cin>>arr[i];
			arr[i]--;
			adj[i].push_back(arr[i]);
		}
 
		
		for(int i=0;i<n;++i) {
			if(mp.find(i) == mp.end()) {
				dfs(i,adj[i][0]);
				cout<<mp[i]<<" ";
			} else {
				cout<<mp[i]<<" ";
			}
		}
		cout<<"\n";
 
	}
 
	return 0;
}