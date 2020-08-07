#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>


int main( ) {

	int T,dupT;
	cin>>T;

	dupT = T;
	vector<pair<int,int>>min_max;
	vector<int> max_v;

	bool isAscent[T];
	memset(isAscent, false, sizeof(isAscent));

	int ci = 0;
	int ascent_count = 0 ;

	while(T--) {
		int n;
		vector<int> temp(n);
		cin>>n ;

		int min_so_far = INT_MAX;

		int temp_min = INT_MAX;
		int temp_max = INT_MIN;

		for(int i=0;i<n;++i) {
			cin>>temp[i];

			if(temp[i]<min_so_far) {
				min_so_far = temp[i];
			}

			if(temp[i]>min_so_far) {
				isAscent[ci] = true;
			}

			if(temp[i]<temp_min) {
				temp_min = temp[i];
			}

			if(temp[i] > temp_max) {
				temp_max = temp[i];
			}
		}

		if(isAscent[ci]) {
			ascent_count++;
		} else {
			min_max.push_back(make_pair(temp_min,temp_max));
			max_v.push_back(temp_max);
		}
		
		ci++;
	}

	n_ = max_v.size();

	sort(max_v.begin(), max_v.end());
	long long int res = 0;

	for(int i=0;i<n_;++i) {

			int key = min_max[i].first;

			int l = 0;
			int r = n_-1;

			while(l<r) {
				int mid = (l+r)>>1;

				if( key < max_v[mid].first) {
					r = mid;
				} else {
					l= mid+1;
				}

			} 

			if( key < max_v[r].first) {
				res+=(n_-r);
			}
	}

	res+=(1ll*ascent_count*dupT);
	res+=(1ll*ascent_count*n_);

	cout<<res<<"\n";
	return 0;
}