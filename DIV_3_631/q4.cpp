#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
 
struct item {
	long long int distance ;
	int L ;
	long long int base ;
 
	item(int distance, int L, int base):
		distance(distance), L(L), base(base)
		{}
};
 
 
 
int main() {
    SYNC
	set<long long int> pnts_covered ;
	queue<item> qu;
 
	int n , m ;
    int dup_m ;
	cin>>n>>m ;
	
	dup_m = m;        
	long long int res = 0;	
 
	int arr[n];
 
	for(int i=0;i<n;++i) {
		cin>>arr[i];
		pnts_covered.insert((ll)arr[i]);
	}	
 
	for(int i=0;i<n;++i) {
		if( pnts_covered.find((ll)(arr[i]-1)) == pnts_covered.end()) {
			pq.push(item((ll)1,-1,(ll)arr[i]));
			pnts_covered.insert((ll)(arr[i]-1));
		}
 
		if( pnts_covered.find((ll)(arr[i]+1)) == pnts_covered.end()) {
			pq.push(item((ll)1,1,(ll)arr[i]));
			pnts_covered.insert((ll)(arr[i]+1));
		}
	}
 
 
	vector<long long int> ans;
 
	while(dup_m>0) {
		item it = pq.front();
		pq.pop();
        
       //cout<<it.distance<<" "<<it.L<<" "<<it.base<<endl;
		long long int dist =  it.base + (it.distance*(ll)it.L);		
		//if(pnts_covered.find(dist) != pnts_covered.end()) continue ;
 
		ans.push_back(dist);
		pnts_covered.insert(dist);
		res+=it.distance;

		it.distance+=1;
		dist = it.base + (it.distance*it.L);

		if(pnts_covered.find(dist) == pnts_covered.end()) pq.push(it);
		dup_m--;
	}
 
 
	cout<<res<<"\n";
 
	for(int i=0;i<m;++i) {
		cout<<ans[i]<<" ";
	}
 
	cout<<"\n";
 
return 0;
 
}