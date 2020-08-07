#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
vector<int> prnt;
vector<int> no_edges;

int findParent(int num) {
	if(prnt[num] == -1) {
		return num;
	} else {
		return findParent(prnt[num]);
	}
}

 void merge(int u,int v) {
	prnt[u] = v;
	no_edges[v] = no_edges[v]+no_edges[u]+1;
}


int main() {

	SYNC

	int n, m;

	cin>>n>>m ;

	vector<pair<int,pair<int,int>>> arr(n-1);
	vector<int> q(m);
	prnt = vector<int>(n,-1);
	no_edges = vector<int>(n,0);
	

	for(int i=0;i<n-1;++i) {
		cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
		arr[i].second.first--;
		arr[i].second.second--;
	}

	for(int i=0;i<m;++i) {
		cin>>q[i];
	}

	vector<int> dups = q;
	sort(arr.begin(), arr.end());
	sort(q.begin(), q.end());

	map<int,long long int> mp;

	int pos = 0;
    
    
	for(int i=0;i<m;++i) {

		if(mp.find(q[i])!=mp.end()) continue;
        
        if(pos>=n-1) {
            mp[q[i]]=mp[q[i-1]];
            continue;
        }
        
        map<int,int> tmp_mp2;
        
		while(pos<n-1 && arr[pos].first<=q[i]) {
	
			int pr_a = findParent(arr[pos].second.first);
			int pr_b = findParent(arr[pos].second.second);
			    
			merge(pr_a,pr_b);
			
			
			if(tmp_mp2.find(pr_a)!=tmp_mp2.end()) tmp_mp2.erase(pr_a) ;
			
			tmp_mp2[pr_b] = no_edges[pr_b];
			
			pos++;
		}
		
		
        
        long long int res = 0;
        
        for(auto it:tmp_mp2) {           
            res+=((1ll*(it.second)*(it.second+1))>>1);    
        }
        
		mp[q[i]] = (res+ mp.rbegin()->second);

	}

	for(int i=0;i<m;++i) {
		cout<<mp[dups[i]]<<" ";
	}
	cout<<"\n";


	return 0;
}