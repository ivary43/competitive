#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
const int N = 150004;

int main() {

	int n;
	bool isOcc[N];

	memset(isOcc,false, sizeof(isOcc));
	cin>>n;

	int arr[n];

	for(int i=0;i<n;++i) {
		cin>>arr[i];
	}

	sort(arr, arr+n);

	isOcc[0] = true;

	for(int i=0;i<n;++i) {
		if(!isOcc[arr[i]-1]) {
			isOcc[arr[i]-1] = true;
		} else if(!isOcc[arr[i]]) {
			isOcc[arr[i]] = true;
		} else if(isOcc[arr[i]+1]) {
			isOcc[arr[i]+1] =true;
		}
	}

	int count = 0;

	for(int i=1;i<N;++i) {
			if(isOcc[i]) count++;
	}

	cout<<count<<"\n";

	return 0;
}