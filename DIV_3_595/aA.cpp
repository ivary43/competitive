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

int main() {

	SYNC

	int T;
	cin>>T;

	while(T--) {

		int n ;
		cin>>n;

		int arr[n];

		int ans = 1;

		cin>>arr[0];

		for(int i =1;i<n;++i) {
			if(arr[i] == arr[i-1]+1) {
				ans =2 ;
			} 
		}
		cout<<ans<<"\n";
	}


}