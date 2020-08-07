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
		int n;
		cin>>n ;	

		int arr[n];

		for( int i=0;i<n;++i) {
			cin>>arr[i];
		}

		bool isF = false;

		for(int i=1;i<n;++i) {
			if(a[i+1] - a[i] >2) {
				cout<<"YES\n";
				cout<<i+1<<" "<<i+2<<endl;
				isF = true;
				break;
			}
		}

		if(!isF) cout<<"NO\n";


	}
	return 0;
}