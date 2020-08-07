#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<int>> g;
vector<int> ans;
int n ;

void bfs(vector<int> start , vector<int> end) {
		vector<int> d(n,INF);

		queue<int> qu ;

		for(int temp:start) {
			d[temp] = 0;
			qu.push(temp);
		}

		while(!qu.empty()) {

			int v = qu.front();
			qu.pop();

			for(int temp:g[v]) {
				if(d[temp] == INF) {
					d[temp] = d[v] + 1;
				}
			}

		}

		for(int i=0;i<n;++i) {
			if(d[i] != INF) {
				ans[i] = d[i];
			}
		}

}


int main() {

	cin>> n;

	int arr[n];
	g = vector<vector<int>>(n);
	ans = vector<int>(n, -1);

	vector<int> even ;
	vector<int> odd ;

	for(int i=0;i<n;++i) {
		cin>>arr[i] ;

		if(arr[i]&1) {
			odd.push_back(i);
		} else {
			odd.push_back(i);
		}
	}

	for(int i=0;i<n;++i) {
		int l = i - arr[i];
		int r = i + arr[i];

		if(l>=0) g[l].push_back(i);
		if(r<n) g[r].push_back(i);

	}

	bfs(even, odd);
	bfs(odd, even);

	for(int i=0;i<n;++i) {
		cout<<ans[i]<<" ";
	}

	return 0;
}