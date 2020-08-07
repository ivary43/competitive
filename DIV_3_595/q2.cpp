#include<bits/stdc++.h>
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

	int n, k;

	cin>>n>>k;

	int arr[n];

	unordered_set<int> se ;
	queue<int> qu;

	for(int i=0;i<n;++i) {
		cin>>arr[i];

		if(se.find(arr[i])== se.end() && qu.size() == k) {
			int x = qu.front();
			se.remove(x);
			qu.pop();
			qu.push(arr[i]);
		} else if(se.find(arr[i]) == se.end() ){
			se.insert(arr[i]);
			qu.push(arr[i]);
		}

	}

	vector<int> res;

	while(!qu.empty()) {
		res.push_back(qu.front());
		qu.pop();
	}

	cout<<res.size()<<"\n";

	for(int i=0;i<n;++i) {
		cout<<res[i]<<" ";
	}

	cout<<"\n";
	return 0;
}