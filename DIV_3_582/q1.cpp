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


	int n ;

	cin>>n ;

	int arr[n];
	int odd = 0;
	int even = 0;

	for(int i=0;i<n;++i) {
		cin>>arr[i];

		if(arr[i]%2) {
			odd++;
		} else {
			even++;
		}
	}
	cout<<min(odd,even)<<"\n";
	return 0;
}