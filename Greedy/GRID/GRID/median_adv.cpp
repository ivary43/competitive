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


int binarySeacrh(int r_, int k, int n_) {

	int l=1;
	int r=r_;

	while(l<r) {
		int mid = (l+r+1)>>1 ;

		if(mid*n_ >k) {
			r=mid-1;
		} else {
			l=mid;
		}
	}

	return l;
}



int main() {

	int n, k ;
	cin>>n>>k ;

	int arr[n];

	for(int i=0;i<n;++i) {
		cin>>arr[i];
	}

	sort(arr, arr+n);

	int max_med = arr[n/2] ;

	for(int i=(n/2)+1;i<n;++i) {
		int diff = arr[i]-max_med;
		int n_ = i - (n/2);



		if(n_ > k) {
						


		} else {
			max_med = arr[i];
			k-=diff*n_;
		}

		if(k==0) {
			break;
		}
	}

	if(k>0) {
		max_med+=(k/((n/2)+1)) ;
	}

	cout<<max_med<<"\n";

	return 0;
}