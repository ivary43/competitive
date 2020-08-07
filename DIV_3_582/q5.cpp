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

	int n, k ;
	cin>>n>>k;

	int arr[n];

	for(int =0;i<n;++i) {
		cin>>arr[i];
	}

	int min_val = INT_MAX;
	sort(arr,arr+n);

	int _n = arr[n-1];

	pair<int,int> pr[_n+1];

	for(int j:arr) {

		int cnt = 0;
		while(j>0) {
			cnt++;
			j=(j>>1);

			if(pr[j].second<k) {
				pr[j].first+=cnt;
				pr[j].second+=1;

				if( (pr[j].second == k) && pr[j].first < min_val) {
					min_val = pr[j].second;
				}
			}
		}
	}

	cout<<min_val<<"\n";
	return 0;
}