#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>

const int N = 200005;

int main() {

	int n, k;
	cin>>n>>k;

	pair<int,int> pr[n];
	vector<int> cnt(N);
	vector<vector<int>> ev(N);

	for(int i=0;i<n;++i) {
		cin>>pr[i].first>>pr[i].second ;
		++cnt[pr[i].first];
		--cnt[pr[i].second+1];

		ev[pr[i].first].push_back(i+1);
		ev[pr[i].second+1].push_back(-i-1);
	}

	for(int i=1;i<N;++i) {
		cnt[i]+=cnt[i-1];
	}

	set<pair<int,int>> currSegs;
	int currSub = 0;

	vector<int> sub(N);
	vector<int> ans(n) ;

	for(int i=0;i<N;++i) {
		currSub+=sub[i];

		for(auto it:ev[i]) {

			if(it>0) {
				currSegs.insert(make_pair(pr[it-1].second, it-1));
			} else {
				auto f = currSegs.find(make_pair(pr[-it-1].second,-it-1));

				if(f != currSegs.end()) {
					currSegs.erase(f);
				}
			}

		}

			while(cnt[i]- currSub > k) {
				int pos = currSegs.rbegin()->second ;
				ans[pos] = 1;
				int r = currSegs.rbegin()->first ;
				currSub++;
				--sub[r+1];
				currSegs.erase(prev(currSegs.end()));
			}
	}


	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i]) cout << i + 1 << " ";
	}
	cout << endl;

	return 0;
}