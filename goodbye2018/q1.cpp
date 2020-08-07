#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>


int main() {
	SYNC
	int T;

	while(T--) {
		int n,k1,k2;

		bool isF = false;

		int x;
		for(int i=0;i<k1;++i) {
			cin>>x ;
			if(x == n) isF = true ;
		}

		for(int i=0;i<k2;++i) {
			cin>>x ;
		}

		if(isF) {
			cout<<"YES\n";
		} else{
			cout<<"NO\n";
		}


	}

	return 0; 
}