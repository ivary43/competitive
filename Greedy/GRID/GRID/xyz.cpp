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

bool cmp(pair<int,int> a1, pair<int,int> a2) {
	return a1.second > a2.second ;
}


int main() {

	SYNC
	int n, m;
	cin>>n>>m ;

	pair<int,int> pr[m];

	int x,y ;
	for(int i=0;i<m;++i) {
		cin>>x>>y ;
		pr[i].first = x ;
		pr[i].second = y ;
	}	

	sort(pr, pr+n, cmp);

	long int res = 0 ;

	for(int i=0;i<m;++i) {

		res+= min(n,pr[i].first)*pr[i].second ;
		n-=min(n,pr[i].first);

		if(n <= 0) {
			break;
		}

	}

	cout<<res<<"\n";

	return 0;
}