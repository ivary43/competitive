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
	int n, s ;
	cin>>n>>s ;

	int arr[n];

	for(int i=0;i<n;++i) {
			cin>>arr[i];
	}

	sort(arr, arr+n);

	long long int res =0 ;

	for(int i=0;i<n;++i) {

		if(i<n/2 && arr[i]>s) {
			res+=(arr[i]-s);
		} else if(i == n/2) {
			res+=abs(arr[i]-s);
		} else if(i>n/2 && arr[i]<s){
			res+=(s-arr[i]);
		}
	}

	cout<<res<<"\n";	
	return 0;
}