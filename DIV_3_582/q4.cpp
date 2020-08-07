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

	for(int i=0;i<=arr[n-1];++i) {

		int hsb = (i == 0)?0:(int)log2(i);

		int temp_k = 0;
		int temp_min = 0;

		for(int j:arr[i]) {
			int tmp_hsb = (int)log2(j);

			int diff = tmp_hsb - hsb ;
			if(diff>=0) {
				if( ((j>>diff) xor i ) == 0) {
					temp_k++;
					temp_min+=diff;
				}

			}

			if(temp_k == k) {
				break;
			}
		}

		if(temp_min<min_val) {
			min_val = temp_min;
		}
	}

	cout<<min_val<<"\n";



	return 0;
}